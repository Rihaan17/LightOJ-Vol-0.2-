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
//#define abs(x) (((x) < 0) ? - (x) : (x))
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

#define N 66000
bool prime[N];
vector<ll>primes;

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


int main ()
{
        sieve();
        ll t, x1, y1, x2, y2, mx, ans, i, Case=1, div, sz = primes.size();
        ll  x, y;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);

                //cout<<x1<<" "<<x2<<endl;

                if(x1==x2)
                {
                        printf("Case %lld: %lld\n",Case++,abs(y1-y2)+1);
                        continue;
                }

                if(y1==y2)
                {
                        printf("Case %lld: %lld\n",Case++,abs(x1-x2)+1);
                        continue;
                }

                x = abs(x1-x2);
                y = abs(y1-y2);
                //cout<<x<<"   "<<y<<endl;

                if(x==y)
                {
                        printf("Case %lld: %lld\n",Case++,x+1);
                        continue;
                }

                ans=2;

                div = 1;
                mx = max(x, y);
                for(i = 0; i<sz&& primes[i]<=sqrt(mx);i++)
                {
                        if(x%primes[i]==0&&y%primes[i]==0)
                        {
                                ans += (div*(primes[i]-1));
                                x/=primes[i];
                                y/=primes[i];
                                div*=primes[i];
                               // cout<<div<<"   "<<ans<<endl;

                                while(x%primes[i]==0&&y%primes[i]==0)
                                {
                                        x/=primes[i]; y/=primes[i];
                                        ans += (div*(primes[i]-1));
                                        div*=primes[i];
                                }
                                mx = max(x, y);
                        }

                        if(x%primes[i]==0) while(x%primes[i]==0) x/=primes[i];
                        if(y%primes[i]==0) while(y%primes[i]==0) y/=primes[i];

                        if(x==1||y==1) break;

                }

                if(x>1&&x==y)
                {
                        ans += (x-1);
                }

                printf("Case %lld: %lld\n",Case++,ans);

        }

        return 0;
}


/*
mx = max(x,y)/2;

                int sz = primes.size();
                ll mx_prime = 0, mx_cnt=0, cnt;
                for(i=0;i<sz&&primes[i]<=mx;i++)
                {

                        if(x%primes[i]==0&&y%primes[i]==0)
                        {
                                cnt = 0;
                                while(x%primes[i]==0&&y%primes[i]==0)
                                {
                                        x/=primes[i], y/=primes[i];
                                        cnt++;
                                }

                                if(cnt>mx_cnt)
                                {
                                        mx_cnt = cnt;
                                        mx_prime = primes[i];
                                }
                                /*ans+=(primes[i]-1); x/=primes[i]; y/=primes[i];



                                while(x%primes[i]==0&&y%primes[i]==0)
                                {
                                        ans += primes[i];
                                        x/=primes[i]; y/=primes[i];

                                        if(x==1||y==1) break;
                                }

                                break;/
                        }
                        if(x==1||y==1) break;
                }

                cout<<mx_prime<<endl;

                if(mx_prime>1){
                        ans+=(mx_prime-1);
                        mx_cnt--;
                        ans+=mx_cnt*(mx_prime);
                }

                if(x>1&&x==y)
                {
                        ans += x-1;
                }

                /if(i>=sz&&(x>1&&y>1))
                {
                        for(i=0;i<sz&&primes[i]<=sqrt(x);i++)
                        {
                                while(x%primes[i]==0) x/=primes[i];
                                if(x==1) break;
                        }

                        if(x>1)
                        {
                                for(i=0;i<sz&&primes[i]<=sqrt(y);i++)
                                {
                                        while(y%primes[i]==0) y/=primes[i];
                                        if(y==1) break;
                                }
                        }


                }/
*/
