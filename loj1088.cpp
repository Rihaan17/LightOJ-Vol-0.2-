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

int fst[100000+10],sec[100000+10],ans[100000+10];
vector<ll>num;


int main () {

        int t,Case=1,i,n,q;
        ll x;
        scanf("%d",&t);

        while(t--)
        {
                num.clear();
                scanf("%d %d",&n,&q);

                for(i=0;i<n;i++)
                {
                        scanf("%lld",&x);
                        num.push_back(x);
                }

                vector<ll>::iterator low,high;
                for(i=0;i<q;i++)
                {
                        scanf("%d %d",&fst[i],&sec[i]);
                        low = lower_bound(num.begin(),num.end(),fst[i]);
                        high = upper_bound(num.begin(),num.end(),sec[i]);
                        ans[i] = (int)((high-num.begin())-(low-num.begin()));
                }

                printf("Case %d:\n",Case++);

                for(i=0;i<q;i++)
                        printf("%d\n",ans[i]);

        }
        return 0;
}
