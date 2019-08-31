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
#define ll long long int
#define db double
#define pii pair<int ,int >
#define NL puts("")
#define G getchar()
#define MOD 1000000007
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

#define N 50000
bool prime[N];
vector<ll>primes;
ll x,y;

void sieve()
{
        ll i,j,sqr = sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<sqr;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(j=i*i;j<N;j+=2*i)
                                prime[j]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false)
                        primes.push_back(i);
                i+=2;
        }
}

void cal_x(ll b, ll B)  // extended euclid algorithm :)
{
        ll temp;
        if(B==0)
        {
                x = 1;
                y = 0;
                return;
        }

        cal_x(B,b%B);
        temp = x;
        x = y;
        y = temp-(b/B)*y;
}


ll solve(ll num, ll p)
{
        ll sz = primes.size(),j,sq = sqrt(num);
        ll ans=1,cnt;
        for(j=0;j<sz&&primes[j]<=sq;j++)
        {
                if(num%primes[j]==0)
                {
                        cnt=0;
                        while(num%primes[j]==0) {
                                num/=primes[j];
                                cnt++;
                        }

                        ll a = (BigMod(primes[j],cnt*p+1,MOD)-1)%MOD;
                        if(a<0) a+=MOD;
                        cal_x(primes[j]-1, MOD);

                        x%=MOD;

                        if(x<0) x+=MOD;

                        ans = (ans*(a%MOD*x%MOD)%MOD)%MOD;
                }
        }

        if(num>1)
        {
                ll a = (BigMod(num,p+1,MOD)-1)%MOD;
                if(a<0) a+=MOD;
                cal_x(num-1,MOD);

                x%=MOD;
                if(x<0) x+=MOD;

                ans = (ans*(a%MOD*x%MOD)%MOD)%MOD;
        }

        return ans;
}


int main () {

        sieve();
        ll t,Case=1;
        ll b,p;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld %lld",&b,&p);

                printf("Case %lld: %lld\n",Case++,solve(b,p));
        }

        return 0;
}
