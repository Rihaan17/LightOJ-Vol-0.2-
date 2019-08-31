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
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
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

bool cmp(int a, int b)
{
        return a>b;
}

int main () {
	int t, cs,n,a[55],b[55],i,ans,j,Case=1;
	bool visa[55],visb[55];
	scanf("%d",&t);
	For (cs, t) {
		scanf("%d",&n);

		for(i=0;i<n;i++) scanf("%d",&a[i]);
                for(i=0;i<n;i++) {
                        scanf("%d",&b[i]);
                        visa[i] = visb[i] = false;
                }

                sort(a,a+n);
                sort(b,b+n,cmp);

                ans=0;
                for(i=0;i<n;i++)
                {
                        j=0;
                        while(j<n&&(a[i]<=b[j]||visb[j]))
                                j++;
                        if(j<n)
                        {
                                visb[j]=visa[i]=true;
                                ans+=2;
                        }
                }

                for(i=0;i<n;i++)
                {
                        if(visa[i]==false)
                        {
                                for(j=0;j<n;j++)
                                {
                                        if(visb[j]==false&&a[i]==b[j])
                                        {
                                                visa[i]=visb[j]=true;
                                                ans+=1;
                                                break;
                                        }
                                }
                        }
                }

                printf("Case %d: %d\n",Case++,ans);
	}
	return 0;
}
