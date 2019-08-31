//{ Template
using namespace std;
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
//}
//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 1<<29
#define ll long long
#define db double
#define NL puts("")
#define G getchar()
//}

int n,x;
ll dp[28][155];

ll gcd(ll a, ll b)
{
        if(b==0) return a;
        return gcd(b,a%b);
}

ll solve(int pos, int sum)
{
        if(pos==n)
        {
                if(sum>=x) return 1;
                return 0;
        }

        if(dp[pos][sum]!=-1) return dp[pos][sum];

        ll res = 0;
        for(int i=1;i<=6;i++)
                res+=solve(pos+1,sum+i);

        return dp[pos][sum] = res;
}


int main () {

        int t,i,Case=1;
        ll p,q,gd;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d %d",&n,&x);

                q=1;
                for(i=1;i<=n;i++) q*=6;
                memset(dp,-1,sizeof(dp));
                p = solve(0,0);
                //cout<<p<<"    "<<q<<endl;
                gd = gcd(p,q);
                if(q/gd==1) printf("Case %d: %lld\n",Case++,p/gd);
                else printf("Case %d: %lld/%lld\n",Case++,p/gd,q/gd);
        }

        return 0;
}
