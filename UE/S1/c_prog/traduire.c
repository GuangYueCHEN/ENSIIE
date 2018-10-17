#include<stdio.h>
#include<math.h>

double puiss(double x,long int p);


int main (){
	
	
	
	/*   
	// sphere
	 int x=1000;
	double y=0.000011;

	printf("%f\n",y);
	y=4*atan(1.0/5.0)-atan(1.0/239.0);
	printf("%f\n",y);
	y=4.0*y;
	printf("%f\n",y);

float t;
scanf("%f",&t);
double O=4.0/3.0*y*pow(t,3.0);
printf("%f",O);

*/


	/*
int a;
char s[10]={
	'w','o','s','h'  
};
char d[10]={

'a','s','d','s','a','d'};
printf("888888\n");
printf("%20s%s\n",s,d);
*/

/*
int i,j;
printf("     I");
  for(i=1;i<11;i++){
	  printf("%5d",i);
  }

printf("\n");
  for(i=0;i<66;i++)
printf("-");

printf("\n");

  for(i=1;i<11;i++){
     if(i!=10)printf(" %d",i);
     else printf("%d",i);
      printf("    I");

      for(j=1;j<11;j++){
		  printf("%5d",j*i);
	  }
    
printf("\n");

  }



*/
/*
int i,j=0,a,b,c;
for(i=0;i<5;i++){
j=0;

scanf("%d , %d",&a,&b);
for(;a%b!=0;){
    c=a%b;
	a=b,b=c;
j++;

}
j++;
printf("%d\n",b);
printf("%d\n",j);

}
*/

int i,j=0;
double a;
long int b;
long double c;
for(i=0;i<5;i++){
scanf("%lf  %ld",&a,&b);
c=puiss(a,b);


printf("%.0Lf\n",c);








}


	return 0;

}
double puiss(double x,long int p){
long double c=0.1;
if(p==0) return 1;
	else if(p%2==0){

	c=	puiss(x,p/2);
        return c*c;

	}
else {

c=puiss(x,(p-1)/2);

return  x*c*c;

}
}
