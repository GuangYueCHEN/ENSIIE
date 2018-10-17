#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// attention: c'est pas un header système
#include "waitverbose.h"

int pid_pos,pid_neg;
int pos[2];
int neg[2];

void fils(char* nickname, int in)
{
	int x;
	int len=sizeof x;
	while (1) {
		/*修改处 读入失败时推出循环*/
		int r = read(in,&x,len);
		if (r <= 0) {
			break ;
		} else if (r != len) {
			continue ;
		}
		printf("%s:%d: %d\n",nickname,getpid(),x);
		if (x==0) break;
	}
	exit(0);
}

static void sig_callback(int signum) {
	int r = kill(pid_pos, SIGKILL);
	kill(pid_neg, SIGKILL);
	pid_t firstKilled = (r == 0) ? pid_pos : pid_neg;
	pid_t secondKilled = (r == 0) ? pid_neg : pid_pos;
	pid_t pid_pere = getpid();
	fprintf(stderr, "pere:%d: fin inattendue du fils %d\n", pid_pere, firstKilled);
	fprintf(stderr, "pere:%d: tue fils %d\n", pid_pere, secondKilled);
	fprintf(stderr, "pere:%d: mes fils sont morts (fin)\n", pid_pere);
	exit(EXIT_FAILURE);
}

void pere(char* nickname, int pos[2], int neg[2])
{
	/* 修改处2  SIGPIPE 写入无读响应信号时进入方程  */
	signal(SIGPIPE, sig_callback);
	int x;
	int len=sizeof x;
	dup2(2,1);
	while (1) {
		printf("entrez un entier: ");
		/* 修改处3  pour EXO4.2       当父进程被关闭时 关闭两个子进程*/
		int r = scanf("%d",&x);
		if (r == EOF) {
			close(pos[1]);
			close(neg[1]);
			break ;
		} else if ( r!=1 ) {
			fprintf(stderr,"%s:%d: probleme lecture stdin.\n",
					nickname,getpid());
			while ( getchar()!='\n' );
			continue;
		}
		if ( x>=0 ) write(pos[1],&x,len);
		if ( x<=0 ) write(neg[1],&x,len);
		if ( x==0 ) break;
	}
	waitendverbose(0);
	waitendverbose(0);
	exit(0);
}

int main(int argc, char*argv[])
{
	if ( pipe(pos)<0 || pipe(neg) ) {
		fprintf(stderr,"%s: probleme creation pipe\n",argv[0]);
		exit (1);
	}
	/* 修改处三   在打开新的子进程前关掉 原来的子进程*/
	if ( (pid_pos=fork())==0 ) { 
		close(neg[0]);
		close(pos[1]);
		close(neg[1]);
		fils("filsP",pos[0]);
	}
	else if ( (pid_neg=fork())==0 ) {
		close(pos[0]);
		close(pos[1]);
		close(neg[1]);
		fils("filsN",neg[0]);
	} else {
		close(pos[0]);
		close(neg[0]);
		pere("pere",pos,neg);
	}
	fprintf(stderr,"Argh!!!\n");
	return 255;
}