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
int x,y;
void cal_x(ll b, ll B)  // extended euclid algorithm :)
{
        int temp;
        if(b==0)
        {
                x = 0;
                y = 1;
                return;
        }

        cal_x(B%b,b);
        temp = y;
        y = x;
        x = temp-B/b*x;
}


int main () {

        int t,Case=1;
        ll i,n,b[15],c[15],ans,pro;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%lld",&n);
                pro = 1;
                for(i=0;i<n;i++)
                {
                        scanf("%lld %lld",&b[i],&c[i]);
                        pro *= b[i];
                }

                ans=0;
                for(i=0;i<n;i++)
                {
                        cal_x(b[i],pro/b[i]);
                        ans = (ans%pro + (c[i]*(pro/b[i])*y)%pro)%pro;
                }



                ans = (ans+pro)%pro;


                printf("Case %d: %lld\n",Case++,ans);
        }

        return 0;
}

/*
bool flag = true;
        B%=b;
        ll rem = 1;
        while(rem%B)
        {
                if(flag)
                {
                        rem+=b;
                        flag=false;
                }
                else
                {
                        B-=b;
                        flag=true;
                }
        }

        return rem/B;
*/

 /*if(ans<=0){
                        while(ans<=0)
                        {
                                ans+=pro;
                        }
                }
                else
                {
                        while(ans-pro>0)
                        {
                                ans-=pro;
                        }
                }*/
