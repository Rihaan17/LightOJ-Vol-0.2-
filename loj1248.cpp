using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

int main()
{
    int T,Case=1,i;
    double n;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%lf",&n);

        double ans=0.0;
        for(i=1;i<=n;i++)
        {
            ans=ans+(double)(n/i);
        }

        printf("Case %d: %.10lf\n",Case++,ans);
    }

    return 0;
}
