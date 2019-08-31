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

ll dp[11][11][500], sz, n, m;

ll solve(int pos, int no, ll num)
{
    if(pos>=sz) return 0;
    if(dp[pos][no][num]!=-1) return dp[pos][no][num];


    ll r1 = 0, r2 = 0, r3 = 0, r4 = 0, i;
    for(i=0;i<=9;i++) {

        ll temp = (num*10)+i;
        //cout<<temp<<"   "<<no<<endl;
        if(temp>=m&&temp<=n) {
            cout<<" 1 :::"<<endl;
            //cout<<temp<<"   vitore"<<endl;
            if(i==0) { cout<<"dukse"<<endl; r1 += no+1+solve(pos+1, no+1, temp); }
            else r2 += no+solve(pos+1, no, temp);
        }
        else if(temp<m) {
            cout<<" 2 :::"<<endl;
            if(i==0) r3+=solve(pos+1,no+1,temp);
            else r4+=solve(pos+1,no,temp);
        }

        else {
            cout<<" 3 :::"<<endl;
            break;
        }
    }

    return dp[pos][no][num] = r1+r2+r3+r4;
}
int main ()
{
    ll t, Case = 1, i;
    scanf("%lld",&t);

    while(t--) {
        scanf("%lld %lld",&m,&n);
        memset(dp,-1,sizeof(dp));
        ll temp = n;

        sz = 0;
        while(temp) {
            temp/=10;
            sz++;
        }

        //cout<<sz<<endl;

//        int f = 0;
//        temp = m;
        /*while(temp&&(temp%10)==0) {
            temp/=10;
            f++;
        }*/
        ll ans = 0;
        for(i=1;i<=9;i++) {
            ans+=solve(1,0,i); cout<<ans<<endl;
        }

        printf("Case %lld: %lld\n",Case++,ans);
    }
    return 0;
}
