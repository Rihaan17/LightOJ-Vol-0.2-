/*
Author: Md Golam Rahman Tushar
*/

//{ Template

#include <bits/stdc++.h>

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

//bool isVowel(char ch){ch=tolower(ch);if(ch=='a'  ch=='e'  ch=='i' | ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

void init() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #else
    // online submission
    #endif
}
int dp[1007][1007], ans[1007];
void solve() {
    dp[1][1] = 1;
    for(int i = 2; i <=1000; i++) {
        dp[i][i] = ((dp[i-1][i-1] % 10056) * i) % 10056;
        dp[1][i] = 1;
    }

    for(int i = 2; i <= 1000; i++) {
        for(int j = i + 1; j <= 1000; j++) {
            dp[i][j] = (dp[i][j-1] * i) % 10056;
            dp[i][j] = (dp[i][j] + ((dp[i-1][j-1] * i) % 10056)) % 10056;
        }
    }

    for(int i = 1; i <= 1000; i++) {
        ans[i] = 0;
        for(int j = 1; j <= i; j++) ans[i] = (ans[i] + dp[j][i]) % 10056;
    }
}

int main() {
    init();
    solve();
    int n, no, Case = 1;
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &no);
        printf("Case %d: %d\n", Case++, ans[no]);
    }

    return 0;
}

