#include<stdio.h>
#include<math.h>
#include<float.h>


int main()
{
    int T,Case=1;
    int i,s,n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);
        double ans = 0.5+sqrt(.25-(2.0*n*log(0.5)));

        printf("Case %d: %.0lf\n",Case++,ans-1);//round(ans));
    }

    return 0;
}
