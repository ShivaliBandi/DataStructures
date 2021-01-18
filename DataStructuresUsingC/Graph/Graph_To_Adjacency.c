#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N=0,M=0;
    printf("Enter number of vertices\n");
    scanf("%d",&N);
    int **arr=(int **)malloc(sizeof(int*) *N);
    for(int icnt=0;icnt<N;icnt++)
        arr[icnt]=(int *)malloc(sizeof(int)*N);
    for(int irow=0;irow<N;irow++)
        for(int icol=0;icol<N;icol++)
            arr[irow][icol]=0;

            
    printf("Enter number of edges\n");
    scanf("%d",&M);
    int j=0;
    int **brr=(int **)malloc(sizeof(int*) *M);
    for(int icnt=0;icnt<M;icnt++)
        brr[icnt]=(int *)malloc(sizeof(int)*2);
    for(int irow=0;irow<M;irow++)
        for(int icol=0;icol<2;icol++)
            {
                scanf("%d",&j);
                label:if(j<N && j>=0)
                    brr[irow][icol]=j;
                else
                {   
                    printf("Edge out of range\ntotal vertieces are %d so enter edge between 0 to %d",N,N);
                    scanf("%d",&j);
                    goto label;
                }
                
            }

       

    return 0;
}