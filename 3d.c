#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc,char*argv[])
{
    FILE *fp;

    fp= fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("unable to open\n");

        exit(1);
    }
    int n,i,j,x,k;

    printf("Enter the number of matrix= ");
    fscanf(fp,"%d",&n);
    printf("%d\n",n);
    int r[n],c[n],a[n][14][14],mul[n][14][14];

    for(k=0; k<n; k++)
    {
        printf("Enter the number of row and column for number %d Matrix = ",k+1);
        fscanf(fp,"%d%d",&r[k],&c[k]);
        printf("%d %d\n",r[k],c[k]);
        printf("enter the number %d matrix element:\n",k+1);
        for(i=0; i<r[k]; i++)
        {
            for(j=0; j<c[k]; j++)
            {
                fscanf(fp,"%d",&a[k][i][j]);
                printf("%d\t",a[k][i][j]);

            }
            printf("\n");
        }
    }

    if(c[0]!=r[1])
    {
        printf("I can not multiply ,please give again rows and column\n");
    }
    else
    {
        printf("Multiplication of the first 2  matrix is=\n");
        for(k=0; k<1; k++)
        {

            for(i=0; i<r[k]; i++)
            {
                for(j=0; j<c[k+1]; j++)
                {
                    mul[k][i][j]=0;
                    for(x=0; x<c[k]; x++)
                    {
                        mul[k][i][j]=mul[k][i][j]+a[k][i][x]*a[k+1][x][j];

                    }
                    printf("%d\t",mul[k][i][j]);
                }
                printf("\n");
            }
        }
        if(n>2)
        {
            printf("Multiplication of the First 3 matrix  is = \n");
            for(k=1; k<n-1; k++)
            {
                if(c[k]==r[k+1])
                {
                    for(i=0; i<r[0]; i++)
                    {
                        for(j=0; j<c[k+1]; j++)
                        {
                            mul[k][i][j]=0;
                            for(x=0; x<r[k+1]; x++)

                            {
                                mul[k][i][j]=mul[k][i][j]+mul[k-1][i][x]*a[k+1][x][j];
                            }
                            printf("%d\t",mul[k][i][j]);
                        }
                        printf("\n");


                    }
                    if(k<n-2)
                    printf("Multiplication of First %d matrix is:\n",k+3);
                }
            else
            {
                  printf("I can not multiply ,please give again rows and column\n");
            }
        }
        }
    }
    //For multiply A*A matrix
    if(r[0]==c[0])
    {
    printf("Multiply of A*A the matrix:\n");
    for(i=0;i<r[0];i++)
    {
    for(j=0;j<c[0];j++)
    {
    mul[0][i][j]=0;
    for(x=0;x<c[0];x++)
        {
    mul[0][i][j]=mul[0][i][j]+a[0][i][x]*a[0][x][j];
    }
     printf("%d\t",mul[0][i][j]);
    }
    printf("\n");
    }
    }
    else
    printf("I can not Multiply A*A! Please give again A(First) matrix row and column\n");



    fclose(fp);
    return 0;
}
