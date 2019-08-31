using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

int main()
{
    int T,Case=1;
    double r1,r2,h,p,pi=2*acos(0.0);

    scanf("%d",&T);

    while(T--)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);

        r1 = (p*((r1-r2)/h))+r2;

        printf("Case %d: %.9lf\n",Case++,(p*pi*(r1*r1+r1*r2+r2*r2))/3.0);
    }

    return 0;
}
