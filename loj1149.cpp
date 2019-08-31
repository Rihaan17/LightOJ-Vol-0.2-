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

#define N 207

/*................Code Starts Here................*/

int Left[N], Right[N], n, m;
bool seen[N];
vector<int>graph[N];

bool kuhn(int u) {
    for(int i = 0;i<graph[u].size();i++) {
        int v = graph[u][i];
        if(seen[v]) continue;
        seen[v] = 1;
        if(Right[v] == -1 || kuhn(Right[v])) {
            Right[v] = u;
            Left[u] = v;
            return true;
        }
    }

    return false;
}

int BM() {
    int i, cnt = 0;
    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));
    for(i=0;i<n;i++) {
        if(Left[i]==-1) {
            memset(seen, 0, sizeof(seen));
            if(kuhn(i)) cnt++;
        }
    }

    return cnt;
}

int main() {
    //freopen("input.txt","r",stdin);
    int t, x, arr[N], i, Case = 1, j;
    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&arr[i]);

        scanf("%d",&m);
        for(i=0;i<m;i++) {
            scanf("%d",&x);
            for(j=0;j<n;j++) {
                if(x%arr[j]==0) graph[j].push_back(i);
            }
        }

        printf("Case %d: %d\n",Case++, BM());
        for(i=0;i<=n;i++) graph[i].clear();
    }
    return 0;
}

