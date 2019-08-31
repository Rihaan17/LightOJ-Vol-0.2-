using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

#define pi (2*acos(0.0))

int main()
{
         int t,Case=1;
         double x1,x2,y1,y2,r1,r2,area1,area2,sector1,sector2,ab,angle1,angle2,rad1,rad2;
         scanf("%d",&t);

         while(t--)
         {
                 scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);

                 if(r1<r2)
                 {
                         int temp=r1; r1=r2; r2=temp;
                 }

                 ab = sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));

                 //cout<<ab<<endl;

                 if(ceil(ab)>(r1+r2))
                 {
                         printf("Case %d: %.10lf\n",Case++,0.0);
                 }
                 else if(r1-r2>=ab)
                 {
                        printf("Case %d: %.10lf\n",Case++,pi*(r2*r2));
                 }
                 else
                 {
                         angle1 = acos(((r1*r1)+(ab*ab)-(r2*r2))/(2.0*r1*ab))*(180.0/pi);
                         angle1*=2.0;
                         rad1 = angle1*(pi/180.0);
                         angle2 = acos(((r2*r2)+(ab*ab)-(r1*r1))/(2.0*r2*ab))*(180.0/pi);
                         angle2*=2.0;
                         rad2 = angle2*(pi/180.0);

                         //cout<<angle1<<"  "<<angle2<<endl;

                         sector1 = 0.5*(r1*r1)*rad1;
                         sector2 = 0.5*(r2*r2)*rad2;

                         area1 = sector1-(0.5*(r1*r1)*sin(angle1*pi/180.0));
                         area2 = sector2-(0.5*(r2*r2)*sin(angle2*pi/180.0));

                         printf("Case %d: %.10lf\n",Case++,area1+area2);
                 }

         }

         return 0;
}
