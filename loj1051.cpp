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

bool check(char c)
{
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
        return false;
}

string str;
int dp[52][52][2][2], l;

bool bad(int idx, int no, bool cons, bool vowel) {
    if(cons&&no>=5) return true;
    else if(vowel&&no>=3) return true;

    if(idx>=l) {
        if(cons&&no>=5) return true;
        else if(vowel&&no>=3) return true;
        return false;
    }

    if(dp[idx][no][cons][vowel]!=-1) return dp[idx][no][cons][vowel];
    if(str[idx]=='?') {
        bool ans;
        if(cons) ans = bad(idx+1, no+1, true, false);
        else ans = bad(idx+1, no+1, false, true);
        if(cons) ans = ans || bad(idx+1, 1, false, true);
        else ans = ans || bad(idx+1, 1, true, false);
        return dp[idx][no][cons][vowel] = ans;
    }
    else if(check(str[idx])) {
        if(vowel) return dp[idx][no][cons][vowel] = bad(idx+1, no+1, false, true);
        else return dp[idx][no][cons][vowel] = bad(idx+1, 1, false, true);
    }
    else {
        if(vowel) return dp[idx][no][cons][vowel] = bad(idx+1, 1, true, false);
        else return dp[idx][no][cons][vowel] = bad(idx+1, no+1, true, false);
    }
}

bool good(int idx, int no, bool cons, bool vowel) {
    if(cons&&no>=5) return false;
    else if(vowel&&no>=3) return false;

    if(idx>=l) {
        if(cons&&no>=5) return false;
        else if(vowel&&no>=3) return false;
        return true;
    }

    if(dp[idx][no][cons][vowel]!=-1) return dp[idx][no][cons][vowel];
    if(str[idx]=='?') {
        if(vowel) return dp[idx][no][cons][vowel] = good(idx+1, 1, true, false)||good(idx+1, no+1, false, true);
        else return dp[idx][no][cons][vowel] = good(idx+1, 1, false, true)||good(idx+1, no+1, true, false);
    }
    else if(check(str[idx])) {
        if(vowel) return dp[idx][no][cons][vowel] = good(idx+1, no+1, false, true);
        else return dp[idx][no][cons][vowel] = good(idx+1, 1, false, true);
    }
    else {
        if(vowel) return dp[idx][no][cons][vowel] = good(idx+1, 1, true, false);
        else return dp[idx][no][cons][vowel] = good(idx+1, no+1, true, false);
    }
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int t, Case = 1;
    scanf("%d",&t);
    while(t--) {
        cin>>str;
        l = str.size();

        memset(dp,-1,sizeof(dp));
        bool flag1 = bad(0, 0, false, false);
        memset(dp,-1,sizeof(dp));
        bool flag2 = good(0, 0, false, false);

        if(flag1&&flag2) printf("Case %d: MIXED\n",Case++);
        else if(flag1) printf("Case %d: BAD\n",Case++);
        else printf("Case %d: GOOD\n",Case++);
    }
    return 0;
}
