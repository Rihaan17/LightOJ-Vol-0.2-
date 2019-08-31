using namespace std;

#include<cstdio>

int solve(int n, int k)
{
        if(n==1)
                return 1;

        return ((solve(n-1, k)+k-1)%n)+1;
}

int main()
{
        int t, Case=1,N,K;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&N,&K);

                printf("Case %d: %d\n",Case++,solve(N,K));
        }

        return 0;
}
