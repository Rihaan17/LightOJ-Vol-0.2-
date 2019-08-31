using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define max(a,b) ((a>b)?(a):(b))

int dp[55][55][55],L1,L2,L3;
char str1[55],str2[55],str3[55];

int solve(int l1,int l2,int l3)
{
        if(l1>=L1||l2>=L2||l3>=L3)
                return 0;

        if(dp[l1][l2][l3]!=-1)
                return dp[l1][l2][l3];

        if(str1[l1]==str2[l2]&&str2[l2]==str3[l3])
                return dp[l1][l2][l3]=1+solve(l1+1,l2+1,l3+1);
        else
        {
                int r1=max(solve(l1+1,l2,l3),max(solve(l1,l2+1,l3),solve(l1,l2,l3+1)));
                //int r2=max(solve(l1+1,l2+1,l3),max(solve(l1+1,l2,l3+1),solve(l1,l2+1,l3+1)));
               // int r3=solve(l1+1,l2+1,l3+1);

                return dp[l1][l2][l3]=r1;//max(r1,max(r2,r3));
        }
}

int main()
{
        int t,i,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s%s%s",str1,str2,str3);
                L1=strlen(str1);
                L2=strlen(str2);
                L3=strlen(str3);

                memset(dp,-1,sizeof(dp));

                printf("Case %d: %d\n",Case++,solve(0,0,0));
        }

        return 0;
}
