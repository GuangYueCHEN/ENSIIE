#include<stdio.h>
#include<stdlib.h>

void communicating_classes_algorithm(int n, float** a, int* comclasses){
int def=1;
int i,j,k;


int *b;
b=(int*)malloc(n*sizeof(int));

for(i=0;i<n;i++){
	comclasses[i]=i+1;
	b[i]=comclasses[i];
}

//asdasdasdsadas
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		printf("%f ",a[i][j] );
	
}
printf("\n");

}
printf("----------------\n");

	for(i=0;i<n;i++){
	
		printf("%d ",comclasses[i] );

}
printf("\n+++++++++++\n");
	for(i=0;i<n;i++){
	
		printf("%d ",b[i] );

}
printf("\n+++++++++++\n");



while(def!=0){





	def=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){

			if(a[i][j]>0){
					
				
				for(k=0;k<n;k++){
					a[i][k]=a[i][k]*a[j][k]+0.01;
				
				}
			}
		}

	}



	for(i=0;i<n;i++){
		for(j=0;j<n;j++){

			if(a[i][j]>0&&a[j][i]>0){
				comclasses[j]=comclasses[i];
			}

	}

	}



for(i=0;i<n;i++){

	if((b[i]-comclasses[i])>0){
	def+=b[i]-comclasses[i];
	}
	else{
		def+= comclasses[i]-b[i];
	}

	


}

//asdasdasdsadas
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		printf("%f ",a[i][j] );
	
}
printf("\n");

}
printf("----------------\n");

	for(i=0;i<n;i++){
	
		printf("%d ",comclasses[i] );

}
printf("\n+++++++++++\n");
	for(i=0;i<n;i++){
	
		printf("%d ",b[i] );

}
printf("\n+++++++++++\n");

for(i=0;i<n;i++){
b[i]=comclasses[i];
}



}



free(b);

}

float transitions[9][9] = {{0.0, 0.0, 0.0, 0.0, 0.75, 0.0, 0.12, 0.0, 0.13},
							{0.2, 0.42, 0.0, 0.38, 0.0, 0.0, 0.0, 0.0, 0.0},
							{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0},
							{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0},
							{0.0, 0.23, 0.0, 0.0, 0.0, 0.0, 0.65, 0.06, 0.06},
						{0.0, 0.0, 0.0, 0.69, 0.0, 0.0, 0.31, 0.0, 0.0},
					{0.0, 0.89, 0.0, 0.0, 0.0, 0.0, 0.11, 0.0, 0.0},
				{0.0, 0.56, 0.0, 0.0, 0.39, 0.0, 0.0, 0.0, 0.05},
			{0.0, 0.0, 0.0, 0.14, 0.0, 0.78, 0.06, 0.02, 0.0}};
int comclasses[9]= {-1,-1,-1,-1,-1,-1,-1,-1,-1};

int main(){
int n=9;
int i,j;
 float ** a;  
    a=(float**)malloc(n*sizeof(float*));  
  
    for(int i=0;i<n;i++){  
        a[i]=(float*)malloc(n*sizeof(float));  
    } 

for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		a[i][j]=transitions[i][j];
	
}

}


communicating_classes_algorithm(n,a,comclasses);

for(i=0;i<5;i++){
free(a[i]);
}


free(a);
return 0;
}