using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

double finding_area(double a,double b,double c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double finding_angle(double a,double b,double c)
{
    return acos(((b*b)+(c*c)-(a*a))/(2.0*b*c));
}

double finding_area_of_arc(double r,double angle)
{
    return 0.5*(r*r)*angle;
}

int main()
{
    double r1,r2,r3,A,B,C,angle_of_A,angle_of_B,angle_of_C,sum_of_arcs,triangle_area;
    int T,Case=1;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&r1,&r2,&r3);

        A = r1+r3;
        B = r2+r3;
        C = r2+r1;

        triangle_area = finding_area(A,B,C);

        angle_of_A = finding_angle(B,A,C);
        angle_of_B = finding_angle(A,B,C);
        angle_of_C = finding_angle(C,B,A);

        sum_of_arcs = finding_area_of_arc(r1,angle_of_A)+finding_area_of_arc(r2,angle_of_B)+finding_area_of_arc(r3,angle_of_C);

        printf("Case %d: %.10lf\n",Case++,(triangle_area-sum_of_arcs));
    }

    return 0;
}
