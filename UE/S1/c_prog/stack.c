#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct stack
{
	int value[20];
	int count;
}stack;

stack new(){
	stack p;
	p.count=0;
	return p;
}

int is_empty(stack *p){
	return p->count;
}


int push(stack *p,int n){
	if(p->count>=20) return 0;
      p->value[p->count]=n;
      p->count++;
      return 1 ;

}
int pop(stack *p){
	p->count--;
	return p->value[p->count];
}

void printstack(stack p){
	printf("print stack--------------------------\n");
	while(is_empty(&p)){
		printf("%d\n",pop(&p));
	}
	printf("end print----------------------------\n");
}








double * MAX(double a,double b){
	if(a>=b) return &a;
	else return &b;
}

double * different(double a[],double b[],int taille){
	int i=0;static double d[20];
	for(;i<taille;i++){

		if(a[i]>=b[i]) d[i]=a[i]-b[i];
		else           d[i]=b[i]-a[i];
	}
	return d;
}
double *  sort(double a[],int taille){
	static double s[20];
	static int i,j;
	
	double x;
	for (int i = 0; i < taille; i++)
	{
		for (int j = i; j < taille; j++)
		{    
			if (a[i]<a[j])
			{
				 x=a[i];
             a[i]=a[j];
             a[j]=x;
			}
			s[i]=a[i];
		}	
	}
	return s;
}


double * common( double a[], double b[],int ta,int tb){
	
	int i=0;
    int j=0,k=0;
    static double com[20];

    while(j<ta&&k<tb){
    	printf("%.1lf   %.1lf      ->>\n", a[j], b[k]);
           if( a[j] == b[k] ) {
           	com[i]=a[j];
           	j++;
     
           	k++;
           	i++;
           }
           else if( a[j] > b[k] ) j++;
           else k++;
    } 

    return com;
}

int main(int argc, char const *argv[])
{
	int i;
	stack p;
	p=new();
	
	
	push(&p,1);push(&p,2);push(&p,3);push(&p,4);push(&p,5);
    printstack(p);
    

  printf("------------------找最大-------------------\n");
    double a=2.0;
    double b=3.0;
    double *n;
    n=MAX(a,b);
    printf("%lf\n",*n);



    printf("---------------返回差数组-------------------\n");
     double c[10]={1,2,3,4,5,6,7,8,9,10};
     double d[10]={10,99,8,77,6,55,4,33,2,11};
    double *e=different(c,d,10);

for(i=0;i<10;i++){
      printf("%.1lf\n", *(e+i));
   
  }
   


  printf("——————————————排序——————————————\n");
        double *s;
         s=sort(e,10);
  for(i=0;i<10;i++){
      printf("%.1lf\n", *(s+i));
   
  }




   printf("-----------------找相同-------------\n");
         double *cc;
         double *aa;
         
     
     aa=sort(c,10);
	for(i=0;i<10;i++){
		c[i]=*(aa+i);
    
  }
    
    aa=sort(d,10);
    for(i=0;i<10;i++){
		d[i]=*(aa+i);
  }
 
  cc=common(c,d,10,10);
   printf("end print----------------------------\n");
  

  for(i=0;*(cc+i)!=0;i++){
      printf("%.1lf\n", *(cc+i));
   
  }
	return 0;

}