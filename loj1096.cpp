using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define MAX_N 4
#define M 10007

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
            Matrix X=matPow(BASE,p/2);
            X=matMul(X,X);
            if(p&1)X=matMul(X,BASE);
            return X;
}

int main()
{
        int t,a,b,n,Case=1,c;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d%d%d",&n,&a,&b,&c);

                if(n<=2)
                        printf("Case %d: 0\n",Case++);
                else{

                        Matrix base;

                        base.mat[0][0]=a;
                        base.mat[0][1]=0;
                        base.mat[0][2]=b;
                        base.mat[0][3]=1;

                        base.mat[1][0]=1;
                        base.mat[1][1]=0;
                        base.mat[1][2]=0;
                        base.mat[1][3]=0;

                        base.mat[2][0]=0;
                        base.mat[2][1]=1;
                        base.mat[2][2]=0;
                        base.mat[2][3]=0;

                        base.mat[3][0]=0;
                        base.mat[3][1]=0;
                        base.mat[3][2]=0;
                        base.mat[3][3]=1;

                        Matrix ans = matPow(base,n-2);
                        int output = ((ans.mat[0][3]%M)*(c%M))%M;

                        printf("Case %d: %d\n",Case++,output);
                }
        }

        return 0;
}
