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

int main ()
{
    //freopen("input.txt","r",stdin);
    string dp[107][107];char a[107], b[107];
    int t, Case = 1;
    scanf("%d",&t);

    while(t--) {
        scanf("%s %s",a,b);
        int l1 = strlen(a), l2 = strlen(b);

        for(int i=0;i<=l1;i++)
            for(int j=0;j<=l2;j++)
                if(i==0||j==0) dp[i][j] = "";
                else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + a[i-1];
                else if(dp[i-1][j].size()>dp[i][j-1].size()) dp[i][j] = dp[i-1][j];
                else if(dp[i-1][j].size()<dp[i][j-1].size()) dp[i][j] = dp[i][j-1];
                else if(dp[i-1][j]<dp[i][j-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j-1];

        if(dp[l1][l2].size()==0) printf("Case %d: :(\n",Case++);
        else cout<<"Case "<<Case++<<": "<<dp[l1][l2]<<endl;

    }
    return 0;
}
