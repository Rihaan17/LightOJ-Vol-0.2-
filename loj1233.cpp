using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

struct info
{
        int coin,freq;
}value[105];

/*bool cmp(info a, info b)
{
        return a.coin*a.freq<b.coin*b.freq;
}*/

int main()
{
        int t,Case=1,n,i,m,j,k,temp;
        bool ans[100000+10];

        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&m);
                for(i=0;i<n;i++) scanf("%d",&value[i].coin);
                for(i=0;i<n;i++) scanf("%d",&value[i].freq);

               // sort(value,value+n,cmp);

             /*   for(i=0;i<n;i++)
                        cout<<value[i].coin<<"    "<<value[i].freq<<endl;*/

                int taken[100000+10];
                for(i=0;i<=m;i++){
                        taken[i]=0;
                        ans[i]=0;
                }
                ans[0]=1;
                int cnt=0;

                for(i=0;i<n;i++)
                {
                        for(j=m;j>=0;j--)
                        {
                                if(ans[j]==1&&taken[j]!=i+1)
                                {
                                        for(k=1;j+(k*value[i].coin)<=m&&taken[j+(k*value[i].coin)]!=i+1&&k<=value[i].freq;k++)
                                        {
                                                temp=j+(k*value[i].coin);
                                                ans[temp]=1;
                                                taken[temp]=i+1;
                                        }
                                        taken[j]=i;
                                }
                        }
                }

                for(i=1;i<=m;i++)
                {
                        if(ans[i])
                                cnt++;
                }

                printf("Case %d: %d\n",Case++,cnt);
        }

        return 0;
}

















/*using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define size 100000+10
#define inf 999999



int main()
{
        int t,i,Case=1,cnt,k,temp,coin[105],freq[105],n,m,coin_no[size];
        bool check[size];
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&m);

                for(i=0;i<n;i++)  scanf("%d",&coin[i]);
                for(i=0;i<n;i++)  scanf("%d",&freq[i]);

                // for(i=0;i<=m;i++) check[i]=false;
                memset(check,false,sizeof(check));
                check[0]=true;
                cnt=0;

                for(i=0;i<n;i++)
                {
                        for(k=0;k<=m;k++)
                        {
                                if(check[k]==false)
                                        coin_no[k]=0;
                                else
                                        coin_no[k]=inf;
                        }

                        for( k=0;k<=m;k++ )
                        {
                                temp = k + coin[ i ];
                                if( check[temp] == false && coin_no[temp] <coin_no[k] + 1 && coin_no[k] <= freq[i] )
                                {
                                    coin_no[temp] = coin_no[k] + 1;
                                    check[temp] = true;
                                        cnt++;
                                }
                        }
                }
              /*  int tin=0;
                for(i=1;i<=m;i++)
                        if(check[i])
                        tin++;/


                printf("Case %d: %d\n",Case++,cnt);
        }

        return 0;
}
/




using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define size 100000+10

int dp[105][size];
int coin[105],freq[105],n,m,cnt;
bool ans[size];

int solve(int i, int taka)
{
        if(i>=n||taka>m)
                return 0;

        if(dp[i][taka]!=-1)
                return dp[i][taka];

            int r1=0,r2=0;


            for(int k=0;k<=freq[i];k++)
            {
                if((taka+coin[i]*k)<=m)
                {
                        if(ans[taka+coin[i]*k]==false)
                        {
                                 ans[taka+coin[i]*k]=true;
                                 //cnt++;
                                r1=r1+1+solve(i+1,taka+coin[i]*k);
                        }
                        else
                        {
                                r1+=solve(i+1,taka+coin[i]*k);
                        }
                }
                else
                   break;
            }

            return dp[i][taka]=r1;//+r2;
}

int main()
{
        int t,i,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&m);

                for(i=0;i<n;i++)
                {
                        scanf("%d",&coin[i]);
                }
                for(i=0;i<n;i++)
                        scanf("%d",&freq[i]);

                memset(dp,-1,sizeof(dp));
               for(i=0;i<=m;i++)
                        ans[i]=false;
                ans[0]=true;
               // cnt=0;
                int temp=solve(0,0);

               /* for(i=1;i<=m;i++)
                        if(ans[i])
                        cnt++;/

                printf("Case %d: %d\n",Case++,temp);
        }

        return 0;
}

/*
2
3 10
1 2 4 2 1 1
2 5
1 4 2 1
*/
