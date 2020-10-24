#include<stdio.h>

int main()
{ int i,j,size=0;
  int sparsematrix[4][5]={
  {0,0,3,0,4},
  {0,0,5,7,0},
  {0,0,0,0,0},
  {0,2,6,0,0}
  };
  for(i=0;i<4;i++)
  {  for(j=0;j<5;j++)
        {
          if(sparsematrix[i][j]!=0)
             size++;
        }
     }

  int resultmatrix[3][size];
  int k=0;
  for(i=0;i<4;i++)
  {  for(j=0;j<5;j++)
        {
         if(sparsematrix[i][j]!=0)
         {
         resultmatrix[0][k]=i;
         resultmatrix[1][k]=j;
         resultmatrix[2][k]=sparsematrix[i][j];
         k++;
         }
        }
     }

  for(i=0;i<3;i++)
  {
      for(j=0;j<size;j++)
      {printf(" %d",resultmatrix[i][j]);}
      printf("\n");
  }
  return 0;
}

