#include<iostream>
#include<stdio.h>
#include<string.h>
#define LL long long

using namespace std;

int n,k,m;
LL dp[55][55][55];
bool vis[55][55][55];

LL solve(int no, int cnt)
{
        if(no==0&&cnt==0) return 1;
        if(no<0||cnt<0) return 0;

        if(vis[no][cnt][m]) return dp[no][cnt][m];

        LL ans=0;

       for(int i=1;i<=m;i++)
        ans+=solve(no-i,cnt-1);

        vis[no][cnt][m] = true;
        return dp[no][cnt][m] = ans;

}
int main()
{
            int t,Case=1,i,j,l;
            scanf("%d",&t);
            memset(vis,false,sizeof(vis));

            while(t--)
            {
                        scanf("%d %d %d",&n,&k,&m);
                        printf("Case %d: %lld\n",Case++,solve(n,k));
            }

            return 0;
}











/*#include<iostream>
#include<stdio.h>
#include<string.h>
#define LL long long

using namespace std;

int n,k,m;
LL dp[55][55][55];
bool flag;

LL solve(int no, int cnt, int num)
{
        if(no==0&&num==0) return 1;
        if(no<0||num<0) return 0;

        if(dp[no][cnt][num]!=-1) return dp[no][cnt][num];

        LL r1=0,r2=0;
        if(flag)
        {
                 if(cnt-1>=0) r1=solve(no-1,cnt-1,num);
                 r2 = solve(no-1,m-1,num-1);
        }
        else
        {
                flag=true;
                r1=solve(no-1,cnt-1,num-1);
                //cout<<"enter"<<endl;
        }


        return dp[no][cnt][num] = r1+r2;

}
int main()
{
            int t,Case=1,i,j,l;
            scanf("%d",&t);

            memset(dp,-1,sizeof(dp));

            while(t--)
            {
                        flag=false;
                        scanf("%d %d %d",&n,&k,&m);
                        printf("Case %d: %lld\n",Case++,solve(n,m,k));
            }

            return 0;
}*/

