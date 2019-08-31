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
#define INF (1<<29)
#define ll long long
#define CountOne(mask) __builtin_popcountll(mask)

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
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
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a; a = b; b = tmp; }

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

struct edge {
    int u,v,w;

    bool operator < ( const edge& p ) const {
        return w < p.w;
    }
};

vector<edge>graph, graph2;
int n,parent[207], lastC;

int parent_find(int u) {
    return (u == parent[u])? u : parent_find(parent[u]);
}

void mst() {
    int i, sz = graph.size(), cnt = 0;

    sort(graph.begin(), graph.end());

    for(i=0; i<=n; i++) parent[i]=i;

    int cost = 0;
    for(i=0; i<sz; i++) {
        int u=parent_find(graph[i].u);
        int v=parent_find(graph[i].v);

        if(u != v) {
            parent[u]=v;
            cnt++;

            cost += graph[i].w;

            edge e;
            e.u = u;
            e.v = v;
            e.w = graph[i].w;

            graph2.push_back(e);


        }

        if(cnt == n-1) break;
    }

    if(cnt == n-1) {
        printf("%d\n",cost);
        lastC = cost;
        graph.clear();
        graph = graph2;
        graph2.clear();
    }
    else {
        printf("%d\n",lastC);
    }
}

int main() {
    freopen("input.txt","r",stdin);
    int t, Case = 1, week, u, v, w, i, arr[207][207], j, temp;
    scanf("%d",&t);

    while(t--) {
        scanf("%d %d",&n,&week);

        for(i=0; i<=n; i++) for(j=0; j<=n; j++) arr[i][j] = 0;

        printf("Case %d:\n", Case++);
        lastC = -1;
        for(i=0; i<week; i++) {
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;

            if(arr[u][v] > 0 || arr[v][u] > 0) {
                if(arr[u][v] > 0 && arr[v][u] > 0) temp = min(arr[u][v], arr[v][u]);
                else temp = max(arr[u][v], arr[v][u]);

                if(temp > w) {
                    arr[u][v] = arr[v][u] = w;

                    edge e;
                    e.u = u;
                    e.v = v;
                    e.w = w;

                    graph.push_back(e);
                    mst();

                } else {
                    printf("%d\n", lastC);
                }
            } else {
                    arr[u][v] = arr[v][u] = w;
                    edge e;
                    e.u = u;
                    e.v = v;
                    e.w = w;

                    graph.push_back(e);

                    mst();
            }
        }

        graph.clear();
        graph2.clear();
    }
    return 0;
}

