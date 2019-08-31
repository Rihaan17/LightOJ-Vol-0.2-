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

#define INF (1<<28)
#define ll long long

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

struct info
{
        int u, v, w;
        bool operator < (const info &p) const
        {
                return w<p.w;
        }
};

int pre[5007], n;
vector<info>path, ans;

int find(int x)
{
        return (pre[x]==x?x:find(pre[x]));
}

int mst()
{
        int i, cnt = 0, sz = path.size(), cost = 0;
        for(i=0;i<n;i++) pre[i] = i;
        sort(path.begin(), path.end());

        for(i=0;cnt<n-1&&i<sz;i++)
        {
                int u = find(path[i].u);
                int v = find(path[i].v);

                if(u!=v)
                {
                        ans.push_back(path[i]);
                        pre[u] = v;
                        cnt++;
                        cost+=path[i].w;
                        if(cnt==n-1) return cost;
                }
        }
        return INF;
}

int mst2(info edge)
{
        int i, cnt = 0, sz = path.size(), cost = 0;
        for(i=0;i<n;i++) pre[i] = i;

        for(i=0;i<sz;i++)
        {
                if(path[i].u==edge.u&&path[i].v==edge.v&&path[i].w==edge.w) continue;
                int u = find(path[i].u);
                int v = find(path[i].v);

                if(u!=v)
                {
                        pre[u] = v;
                        cnt++;
                        cost+=path[i].w;
                        if(cnt==n-1) return cost;
                }
        }

        return INF;
}


int main ()
{
        int t, m, u, v, i, w, Case = 1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d %d", &n, &m);

                for(i=0;i<m;i++)
                {
                        scanf("%d %d %d", &u, &v, &w);
                        u--; v--;
                        info edge;
                        edge.u = u;
                        edge.v = v;
                        edge.w = w;

                        path.push_back(edge);
                }

                int mst1 = mst();
                int sz = ans.size(), _2ndbest = INF;
                for(i=0;i<sz;i++)
                {
                        _2ndbest = min(_2ndbest, mst2(ans[i]));
                }
                printf("Case %d: %d\n",Case++,_2ndbest);

                path.clear(); ans.clear();
        }
        return 0;
}

