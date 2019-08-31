using namespace std;

#include<iostream>
#include<cmath>
#include<ctype.h>
#include<cstdio>

double at(double a,double b,double c)
{
    double s=(a+b+c);
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    int T,Case=1;
    double a,b,c,r;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&r);

        double t1 = at(a,b,c);
        double tr = (t1/(r+1));
        double t2 = tr*r;

        double ans = (sqrt(t2)/sqrt(t1))*a;

        printf("Case %d: %.10lf\n",Case++,ans);
    }

    return 0;
}
