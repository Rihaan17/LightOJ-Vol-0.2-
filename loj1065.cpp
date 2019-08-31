using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>

#define MAX_N 2

int M;

struct Matrix{
    int mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a,Matrix b)
{
            Matrix ans;
            int i,j,k;
            for(i=0;i<MAX_N;i++)
                for(j=0;j<MAX_N;j++)
                {
                    for(ans.mat[i][j]=k=0;k<MAX_N;k++)
                    {
                        ans.mat[i][j]=((ans.mat[i][j]%M)+(((a.mat[i][k]%M)*(b.mat[k][j]%M))%M))%M;
                    }

                }
            return ans;
}

Matrix matPow(Matrix BASE,int p)
{
            if(p==1) return BASE;
            Matrix X=matPow(BASE,p>>1);
            X=matMul(X,X);
            if(p&1)X=matMul(X,BASE);
            return X;
}

int main()
{
        int n,a,b,t,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d%d%d",&a,&b,&n,&M);

                if(M==1) M=10; else if(M==2) M=100; else if(M==3) M=1000; else M=10000;

                Matrix base;

                base.mat[0][0]=1;
                base.mat[0][1]=1;
                base.mat[1][0]=1;
                base.mat[1][1]=0;

                Matrix ans = matPow(base,n-1);

                printf("Case %d: %d\n",Case++,((ans.mat[0][0]*b)%M+(ans.mat[0][1]*a)%M)%M);
        }

        return 0;
}
