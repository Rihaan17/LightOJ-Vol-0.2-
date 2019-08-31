using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

typedef long long int ll_d;

ll_d dp[205][12][25];
int n,m,d,arr[210];
bool visited[205][12][25];

ll_d solve(int pos, int no,int sum)
{
        if(no==m)
        {
                if(sum%d==0) return 1;
                else return 0;
        }
        if(pos>=n)
                return 0;

        if(visited[pos][no][sum])
                return dp[pos][no][sum];

        ll_d r1,r2;

        r1=solve(pos+1,no+1,(sum%d+arr[pos]%d+d)%d);
        r2=solve(pos+1,no,sum);
        visited[pos][no][sum]=true;
        return dp[pos][no][sum]=r1+r2;
}

int main()
{
        int t,q,i,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&q);
                for(i=0;i<n;i++)
                        scanf("%d",&arr[i]);

                printf("Case %d:\n",Case++);

                while(q--)
                {
                        memset(visited,false,sizeof(visited));
                        scanf("%d%d",&d,&m);

                        printf("%lld\n",solve(0,0,0));
                }
        }

        return 0;
}
