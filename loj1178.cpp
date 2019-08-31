using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctype.h>

double finding_area(double a,double b,double c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double finding_angle(double a,double b,double c)
{
    return acos(((b*b)+(c*c)-(a*a))/(2.0*b*c));
}

double finding_Parellelogram_area(double angle,double b,double c)
{
    return b*c*sin(angle);
}

int main()
{
    double a,b,c,d;
    int T,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

        if(c>a)
        {
            double temp=a;
            a=c;
            c=temp;
        }

        double triangle_area = finding_area(a-c,b,d);
        double angle = finding_angle(d,a-c,b);
        double Parellelogram_area = finding_Parellelogram_area(angle,b,c);

        printf("Case %d: %.10lf\n",Case++,triangle_area+Parellelogram_area);
    }

    return 0;
}
