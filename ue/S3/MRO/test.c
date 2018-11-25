#include<stdio.h>
#include<stdlib.h>

void johnson_ordering_algorithm(int n, int* t1, int* t2, int* ordering){
int a,b;
a=0,b=0;
int i,j,buf;
int *Sa;
int *Sb;
int *indexA;
int *indexB;

for(i=0;i<n;i++){
	if(t1[i]<=t2[i]) a++;
	else b++;
}

Sa=malloc(a*sizeof(int));
indexA=malloc(a*sizeof(int));
Sb=malloc(b*sizeof(int));
indexB=malloc(b*sizeof(int));
a=0;
b=0;
for(i=0;i<n;i++){
	if(t1[i]<=t2[i]){
		Sa[a]=t1[i];
		indexA[a]=i+1;
		a++;
	}
	else {
		Sb[b]=t2[i];
		indexB[b]=i+1;
		b++;
	}
}




for(i=0;i<a;i++){
	for(j=i+1;j<a;j++){
		if(Sa[i]>Sa[j]){
			buf=Sa[i];
			Sa[i]=Sa[j];
			Sa[j]=buf;
			buf=indexA[i];
			indexA[i]=indexA[j];
			indexA[j]=buf;
		}
	}

}
for(i=0;i<b;i++){
	for(j=i+1;j<b;j++){
		if(Sb[i]<Sb[j]){
			buf=Sb[i];
			Sb[i]=Sb[j];
			Sb[j]=buf;
			buf=indexB[i];
			indexB[i]=indexB[j];
			indexB[j]=buf;
		}
	}

}


for(i=0;i<n;i++){
	if(i<a){
		ordering[i]=indexA[i];
	}else{
		ordering[i]=indexB[i-a];
	}
}

}
int t1[] = {10,30,20,60,40,40,50,30 };
int t2[] = {15,50,100,30,10,90,20,40 };
int ordering[]= {1,2,3,4,5,6,7,8 };
int main(){
	int n =8;
	int i;
	johnson_ordering_algorithm( n, t1, t2,  ordering);
	for(i=0;i<n;i++){
		printf("\n%d",ordering[i]);
	}
return 0;
}
