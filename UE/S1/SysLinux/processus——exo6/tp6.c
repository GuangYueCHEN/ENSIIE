# include <stdio.h> //printf
# include <string.h> //strcmp
# include <unistd.h> //dup2
# include <stdlib.h> //wait
# include <sys/types.h> //wait
# include <sys/wait.h> //wait
# include <fcntl.h> //open

# define CMD_ERROR (2)
# define CMD_SUCCESS (1)
# define CMD_EXIT (0)
# define CMD_UNKNOWN (-1)

# define STDIN_FD (0)
# define STDOUT_FD (1)
# define STDERR_FD (2)

/* 命令struct */
typedef struct	s_cmd {
	const char 	* s;		//命令名
	int 		(*f)(void);	//方程指针
}		t_cmd;

/* 推出命令 */
static int f_exit(void) {
	return (CMD_EXIT);
}

/** pid command */
static int f_pid(void) {
	printf("shell pid: %d\n", getpid());
	return (CMD_SUCCESS); 
}

/**上一个命令的状态  需要设置成静态的 */
static int last_status = 0;
static int f_last_status(void) {
	if (f_last_status>=0)
	printf("last command status: SUCCESS\n");
else 
	printf("last command status: Error\n"); 
	return (CMD_SUCCESS);
}

/* 设置全局变量 可用命令*/
static t_cmd cmds[] = {
	{"exit", f_exit},
	{"$$", f_pid},
	{"$?", f_last_status}
};

/* 算命令数*/
static size_t MAX_CMDS = sizeof(cmds) / sizeof(t_cmd);


char * nextIn = NULL;
char * nextOut = NULL;

/**EXO3  当出现了 <> 时候怎么办  声明两个字符指针   */
static int shell(char * cmd) {
	if (cmd[0] == '<') {
		nextIn = strdup(cmd + 1);
		return (CMD_SUCCESS);
	} else if (cmd[0] == '>') {
		nextOut = strdup(cmd + 1);
		return (CMD_SUCCESS);
	}

	unsigned int i;
	for (i = 0 ; i < MAX_CMDS ; i++) {
		/** 寻找可执行的命令 */
		if (strcmp(cmds[i].s, cmd) == 0) {
			/**建立一个子进程用来执行 */
			pid_t pid = fork();
			if (pid == -1) {
				return (CMD_ERROR);
			}
			if (pid == 0) {
				/** 如果出现重定向流符号 重定向流*/
				if (nextIn != NULL) {
					int fd = open(nextIn, O_RDONLY);
					if (fd == -1 || dup2(fd, STDIN_FD) == -1) {
						printf("couldn't redirect stdout.\n");
						exit(EXIT_FAILURE);
					}
					free(nextIn);
					nextIn = NULL;
				}

				if (nextOut != NULL) {
					int fd = open(nextOut, O_WRONLY | O_CREAT, 0644);
					if (fd == -1 || dup2(fd, STDOUT_FD) == -1) {
						printf("couldn't redirect stdout.\n");
						exit(EXIT_FAILURE);
					}
					free(nextOut);
					nextOut = NULL;
				}
				
				/**执行这个命令*/
				cmds[i].f();
				exit(EXIT_SUCCESS);
			}
			wait(&last_status);
			return (i == 0 ? CMD_EXIT : CMD_SUCCESS);
		}
	}
	return (CMD_UNKNOWN);
}
//第一题读入命令 若命令无法理解 输出该命令无法理解 若命令是 exit  退出
int main(void) {
	char cmd[1000], line[1000];
	while (!feof(stdin)) {
		printf("shell > ");
		if (fgets(line, 100, stdin) == 0 || sscanf(line, "%s", cmd) != 1) {
			continue ;
		}
		int r = shell(cmd);
		if (r == CMD_UNKNOWN) {   
			printf("unknown command: %s\n", cmd);
			printf("%lu available commands:\n", MAX_CMDS);
			size_t i;
			for (i = 0 ; i < MAX_CMDS ; i++) {
				printf("\t%s\n", cmds[i].s);
			}
		} else if (r == CMD_ERROR) {
			printf("an error occured\n");
		} else if (r == CMD_EXIT) {
			break ;
		}
	}
	printf("\n");
	return (0);
}