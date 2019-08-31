using namespace std;

#include<cstdio>
#include<map>

int main()
{
        int t,n,i,ans,Case=1;
        long x;
        scanf("%d",&t);

        while(t--)
        {
                ans=0;
                scanf("%d",&n);

                map<long,int>m;

                for(i=0;i<n;i++)
                {
                        scanf("%ld",&x);

                        if(m[x]==0)
                        {
                                ans+=(x+1);
                                m[x]++;
                        }
                        else
                        {
                                if(m[x]>=x+1)
                                {
                                        ans+=(x+1);
                                        m[x]=1;
                                }
                                else
                                        m[x]++;
                        }
                }

                printf("Case %d: %d\n",Case++,ans);
        }

        return 0;
}
