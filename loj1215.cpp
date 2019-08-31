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

ll power(ll n,ll m)
{
    ll ans=1,p=n;
    while(m)
    {
        if(m&1) ans*=p;
        p*=p;
        m=m>>1;
    }
    return ans;
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
bool prime[N];
vector<ll>primes;

void sieve()
{
        int i,j,sqr = sqrt(N);
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

int fact_cnt[N];

ll solve(ll a, ll b, ll L)
{
        memset(fact_cnt, 0, sizeof(fact_cnt));
        ll i, ans, sz = primes.size(), tempA = a, tempB = b, cnt;

        for(i=0;i<sz&&primes[i]<=sqrt(a);i++)
        {
                fact_cnt[primes[i]] = 0;
                while(a%primes[i]==0)
                {
                        a/=primes[i];
                        fact_cnt[primes[i]]++;
                }

                if(a==1) break;
        }

        if(a>1) fact_cnt[a]=1;

        for(i=0;i<sz&&primes[i]<=sqrt(b);i++)
        {
                if(b%primes[i]==0)
                {
                        cnt = 0;
                        while(b%primes[i]==0)
                        {
                                b/=primes[i];
                                cnt++;
                        }

                        fact_cnt[primes[i]] = max(cnt, fact_cnt[primes[i]]);
                       // cout<<fact_cnt[primes[i]]<<"  #2#   "<<cnt<<endl;
                }


                if(b==1) break;
        }

        ans = 1;
        /*if(a>1&&L%a) ans*=a;
        if(b>1&&L%b) ans*=b;*/
        if(b>1) fact_cnt[b] = 1;

        for(i=0;i<sz&&primes[i]<=sqrt(L);i++)
        {
                if(L%primes[i]==0)
                {
                        cnt = 0;
                        while(L%primes[i]==0)
                        {
                                L/=primes[i];
                                cnt++;
                        }

                        if(cnt>fact_cnt[primes[i]]) ans*=(power(primes[i],cnt));
                       // cout<<fact_cnt[primes[i]]<<"   #3#   "<<cnt<<endl;

                }


                if(L==1) break;
        }

        if(L>1)
        {
                if(tempA%L&&tempB%L) ans*=L;
        }

        return ans;
}

int main ()
{
        sieve();
        int t, Case=1;
        ll a, b, L;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%lld %lld %lld",&a, &b, &L);

                if(LCM(a, b)==L)
                {
                        printf("Case %d: 1\n",Case++);
                        continue;
                }

                if(L%a||L%b)
                {
                        printf("Case %d: impossible\n",Case++);
                        continue;
                }

                printf("Case %d: %lld\n", Case++, solve(a, b, L));
        }
        return 0;
}
