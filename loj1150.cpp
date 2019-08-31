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
#define INF 0x3f3f3f3f
#define ll long long
#define CountOne(mask) __builtin_popcountll(mask)
#define sz 57

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

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*................Code Starts Here................*/

struct info{
    int x, y;
};

vector<int>graph[sz];
int cnt1, cnt2, n, dist[sz][sz], d[sz][sz], cx[sz], cy[sz], mp[sz][sz];
char grid[sz][sz];
bool vis[sz];

bool dfs(int u) {
    for(int i=0;i<graph[u].size();i++) {
        int v=graph[u][i];
        if(!vis[v]) {
            vis[v] = true;
            if(cy[v]==-1||dfs(cy[v])) {
                cy[v]=u;
                cx[u]=v;
                return true;
            }
        }
    }
    return false;
}
int BPM() {
    int ans=0;
    for(int i=0;i<sz;i++) cx[i] = cy[i] = -1;

    for(int i=0;i<cnt1;i++) {
        if(cx[i]==-1) {
            memset(vis, false, sizeof(vis));
            if(dfs(i))
                ans++;
        }
    }
    return ans;
}

bool check(int x, int y) {
    if(x >= 0 && x < n && y >= 0 && y<n && d[x][y] == -1 && grid[x][y] != '#') return true;
    return false;
}

void bfs(int x, int y) {
    info crnt;
    crnt.x = x;
    crnt.y = y;
    queue<info>q;
    q.push(crnt);
    for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) d[i][j] = -1;
    d[x][y] = 0;

    while(!q.empty()) {
        info temp = q.front();
        q.pop();

        if(grid[temp.x][temp.y] == 'G') dist[mp[x][y]][mp[temp.x][temp.y]] = d[temp.x][temp.y];

        for(int i=0;i<4;i++) {
            int rx = temp.x + dir[i][0];
            int ry = temp.y + dir[i][1];

            if(check(rx, ry)) {
                d[rx][ry] = d[temp.x][temp.y]+1;
                crnt.x = rx;
                crnt.y = ry;
                q.push(crnt);
            }
        }
    }
}

void make_graph(int key) {
    for(int i=0;i<cnt1;i++) {
        graph[i].clear();
        for(int j=0;j<cnt2;j++) {
            if(dist[i][j]<=key) graph[i].push_back(j);
        }
    }
}


int main() {
    freopen("input.txt","r",stdin);
    int t, Case = 1, i, j;
    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%s",grid[i]);

        cnt1 = cnt2 = 0;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j] == 'H') mp[i][j] = cnt1++;
                if(grid[i][j] == 'G') mp[i][j] = cnt2++;
            }
        }

        for(i=0;i<sz;i++) {
            for(j=0;j<sz;j++) dist[i][j] = INF;
        }

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j] == 'H') bfs(i, j);
            }
        }

        int ans = -1, low = 0, ri = INF/2;
        while(low<=ri) {
            int mid = (low+ri)/2;
            make_graph(mid);

            if(BPM()==cnt1) {
                ans = mid;
                ri = mid-1;
            } else low = mid+1;
        }

        if(ans == -1) printf("Case %d: Vuter Dol Kupokat\n",Case++);
        else printf("Case %d: %d\n",Case++,(ans*2+2));
    }
    return 0;
}
