using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        long long int t,n,i,arr[205],XOR,Case=1;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld",&n);

                for(i=0;i<2*n;i++)
                {
                        scanf("%lld",&arr[i]);
                }

                XOR=0;
                for(i=1;i<2*n;i+=2)
                {
                        XOR^=(arr[i]-arr[i-1]-1);
                }

                if(XOR==0) printf("Case %d: Bob\n",Case++);
                else printf("Case %d: Alice\n",Case++);
        }

        return 0;
}
