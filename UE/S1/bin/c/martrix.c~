#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct martrise{
  double **arr;
  int size;
};
typedef struct martrise martrix;


martrix new(int n){
  int i;
  martrix newMartrix;
  newMartrix.arr=(double**) malloc(n*sizeof(double*));
  for(i=0;i<n;i++)
    
  newMartrix.arr[i]=(double*)malloc(n*sizeof(double));

  newMartrix.size=n;

  return newMartrix;
}

void set(martrix *m){
  int i,j;
  printf("----------%d * %d -------\n",m->size,m->size);
  for (i=0;i<m->size;i++){
    for(j=0;j<m->size;j++)
      scanf("%lf",&(m->arr[i][j]));

  }
}

#define random(x)(rand()%x)
void randSet(martrix *m){
  int max;
  int i,j;
   printf("----------RAND MAX IS ? -------\n");
   scanf("%d",&max);
   srand((int)time(0));
   
   for (i=0;i<m->size;i++){
     
    for(j=0;j<m->size;j++)
      m->arr[i][j]=random(max);

   }

}


void printMartrix(martrix *m){
  int i, j;
  printf("----------MARTRIX  PRINT -------\n");
  for(i=0;i<m->size;i++){

    for(j=0;j<m->size;j++){

      printf("%-4.0lf ",m->arr[i][j]);

    }

    printf("\n");

  }

  printf("The SIze is %d \n",m->size);

}

void showAdress(martrix m){
   int i ,j;
    printf("----------MARTRIX ADRESS PRINT -------\n");
   for(i=0;i<m.size;i++){

    for(j=0;j<m.size;j++){

      printf("%d ",&(m.arr[i][j]));

    }
     printf("\n");

  }

}

//addddddddddddddddddddddddddddddddddddddddddddddd

martrix add(martrix m1,martrix m2){
  //if size m1 != size m2   error
  
    printf("----------MARTRIX ADDITION -------\n");
  int size=m1.size;
  martrix result=new(size);
  int i,j;
    for(i=0;i<size;i++){

    for(j=0;j<size;j++){

     result.arr[i][j]=m1.arr[i][j]+m2.arr[i][j];

    }


  }

    return result;
}
  

//foissssssssssssssssssssssssssssssssssssssssssssssssss

martrix fois(martrix m1,martrix m2){
  //if size m1 != size m2   error
  
    printf("----------MARTRIX FOIS -------\n");
  int size=m1.size;
  martrix result=new(size);
  int i,j,k;
  double sum;
    for(i=0;i<size;i++){

    for(j=0;j<size;j++){
      sum=0;
      for(k=0;k<size;k++)
     sum+=m1.arr[i][k]*m2.arr[k][j];
      result.arr[i][j]=sum;
     }


  }

    return result;
}


double trace(martrix m){
   int i ;
   double sum=0;
    printf("----------MARTRIX TRACE -------\n");

    for(i=0;i<m.size;i++)
     sum+= m.arr[i][i];

    return sum;

}

martrix T(martrix m){
   int size=m.size;
  martrix result=new(size);
  int i,j;
    for(i=0;i<size;i++){

    for(j=0;j<size;j++){

     result.arr[i][j]=m.arr[j][i];

    }


  }

    return result;
}

martrix Pascal(int n){
  martrix m=new(n);
  int i,j;
  for (i=0;i<n;i++){
    for(j=0;j<n;j++)
      m.arr[i][j]=0;
    }
   m.arr[0][0]=1;
   for (i=1;i<n;i++){
     m.arr[i][0]=1;
    for(j=1;j<=i;j++)
      m.arr[i][j]=m.arr[i-1][j-1]+m.arr[i-1][j];
    }



   return m;





}



int main(){
  // printf("----------MARTRIX  size is ? -------\n");
  int size;
  // scanf("%d",&size);
  //martrix tp1=new(size);

  // randSet(&tp1);

  // printMartrix(&tp1);
  // showAdress(tp1);

  //martrix tp2=new(size);

  // randSet(&tp2);

  // printMartrix(&tp2);

  //martrix tp3=add(tp1,tp2);
  
  //printMartrix(&tp3);

  //martrix tp3=fois(tp1,tp2);
  
  //printMartrix(&tp3);
  //double res=trace(tp1);
  //printf("%.0lf\n",res);


  // martrix tp3=T(tp1);
  
  //printMartrix(&tp3);
   printf("----------Pascal  size is ? -------\n");
    scanf("%d",&size);
martrix tp4=Pascal(size);
  printMartrix(&tp4);
  return 0;


}
  
      

  


  
