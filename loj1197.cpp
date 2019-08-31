/*
Author: Golam Rahman Tushar
........Aust Cse 27th batch.........
*/

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

#define INF 1<<29
#define ll long long
#define N 50000

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}


bool prime[N];
vector<int>primes;

void sieve()
{
        ll i,j,sq=sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);

        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<=sq;i+=2)
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

bool com[100000+7];

int main ()
{
    sieve();
    ll t, a, b, i, sz = primes.size(), Case = 1;

    scanf("%lld",&t);

    while(t--) {
        scanf("%lld %lld",&a, &b);
        ll sq = sqrt(b), temp;

        for(i=0;i<=b-a;i++) com[i] = 1;

        for(i=0;i<sz&&primes[i]<=sq;i++) {
            temp = (a/primes[i])*primes[i];

            while(temp<=b) {
                if((temp>primes[i])&&temp>=a) com[temp-a] = 0;
                temp+=primes[i];
//                if(primes[i]==2) temp+=primes[i];
//                else temp+=(2*primes[i]);
            }
        }

        ll cnt = 0;
        for(i=0;i<=b-a;i++) {
            if(com[i]) cnt++;
        }

        if(a==1) cnt--;

        printf("Case %lld: %lld\n",Case++,cnt);
    }
    return 0;
}
