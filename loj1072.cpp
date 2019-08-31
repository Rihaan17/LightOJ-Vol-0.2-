#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    unsigned int T,n,Case=1;
    double pi=2*acos(0.0);
    double R,r;
    cin>>T;
    while(T--)
    {
        cin>>R>>n;
        cout.precision(10);
        if((R>0&&R<1000)&&(n>=2&&n<=100))
        {
            r=(R*sin(pi/n))/(1+sin(pi/n));
            cout<<"Case "<<Case++<<": "<<r<<endl;
        }
    }
    return 0;
}
