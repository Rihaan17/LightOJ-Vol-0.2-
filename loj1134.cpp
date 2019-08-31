//tempp//{ Template
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

int arr[100000+10],dp[100000+10],countt[100000+10];

long long int solve(int n){
        if(n<=1) return 0;
        return n-1+solve(n-1);
}

int main () {
	int t, cs,n,m,i,j;
	long long cnt;
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++) {
                scanf("%d %d",&n,&m);
                for(i=0;i<=m;i++) countt[i]=0;

                cnt=0;
                for(i=0;i<n;i++) {
                        scanf("%d",&arr[i]);
                        if(i==0) dp[i]=arr[i]%m;
                        else dp[i] = (dp[i-1]%m+arr[i]%m)%m;
                        countt[dp[i]]++;
                }

                for(i=0;i<m;i++) cnt+=solve(countt[i]);
                cnt+=countt[0];
                printf("Case %d: %lld\n",cs,cnt);
	}
	return 0;
}
