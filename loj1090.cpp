//{ Template

//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define ll long long
#define db double
#define pii pair<int ,int >
#define NL puts("")
#define G getchar()
//}

//compute b^p
ll Pow(ll  b,ll  p){
    ll  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}

//compute b^p%m
ll BigMod(ll  b,ll  p ,ll  m ){
     ll  ret = 1 ;
     while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
     }
    return ret ;
}

//compute gcd of (a,b)
ll GCD(ll a , ll b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
ll LCM(ll a , ll b) {
     return (a / GCD(a,b)*b);
}

#define N 1000000+10

int fac5_zero[N], fac2_zero[N];
void pre_cal()
{
        int temp, i, cnt;
        fac5_zero[0] = 0;
        for(i=5;i<=1000000;i+=5)
        {
                cnt = 0;
                temp = i;
                while(temp%5==0)
                {
                        temp/=5;
                        cnt++;
                }

                fac5_zero[i] = fac5_zero[i-5]+cnt;
        }

        fac2_zero[0] = 0;
        for(i=2;i<=1000000;i+=2)
        {
                cnt = 0;
                temp = i;
                while(temp%2==0)
                {
                        temp/=2;
                        cnt++;
                }

                fac2_zero[i] = fac2_zero[i-2]+cnt;
        }
}


int main ()
{
        pre_cal();
        int t, n, r, p, q, cnt1, cnt2, temp, Case = 1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d %d %d %d",&n,&r,&p,&q);

                cnt1 = cnt2 = 0;
                while(p%5==0)  // calculating no of 5
                {
                        p/=5;
                        cnt1+=q;
                }

                while(p%2==0)  // calculating no of 2
                {
                        p/=2;
                        cnt2+=q;
                }

               // ans = min(cnt1,cnt2)*q;
                //cnt1 = cnt1 - (ans/q);  // stored unused no of 5 in cnt1


                // calculating no of 5 in nCr
                temp = n;
                while(temp%5) temp--;
                cnt1+=fac5_zero[temp];

                temp = r;
                while(temp%5) temp--;
                cnt1-=fac5_zero[temp];

                temp = n-r;
                while(temp%5) temp--;
                cnt1-=fac5_zero[temp];

               /* if(temp1>temp2)
                {
                        no_of_5 = temp1-temp2;
                        ans+=no_of_5;
                }*/

                // calculating no of 2 in nCr

                temp = n;
                while(temp%2) temp--;
                cnt2+=fac2_zero[temp];

                temp = r;
                while(temp%2) temp--;
                cnt2-=fac2_zero[temp];

                temp = n-r;
                while(temp%2) temp--;
                cnt2-=fac2_zero[temp];

                /*if(temp1>temp2)
                {
                        no_of_2 = temp1-temp2;
                        no_of_2 -= no_of_5;   // stored unused no of 2 in no_of_2

                        ans += min(no_of_2, cnt1*q);
                }*/

                printf("Case %d: %d\n",Case++,min(cnt1,cnt2));
        }
        return 0;
}
