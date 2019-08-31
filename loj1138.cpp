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


ll binary(ll x)
{
        ll low=1,high=80000003,mid,cnt,temp,i;

        while(low<=high)
        {
                mid = (low+high)/2;

                temp = mid*5;
                cnt = 0;
                for(i=1;pow(5,i)<=temp;i++)
                {
                        cnt+=floor(temp/pow(5,i));
                }

                //cout<<mid<<" : "<<cnt<<endl;

                if(cnt==x)  return mid*5;
                else if(cnt>x)   high = mid-1;
                else if(cnt<x)    low = mid+1;

        }

        return -1;
}
int main () {

        /*ll temp=400000005,cnt=0;;
        for(ll j=1;pow(5,j)<=temp;j++)
        {
                cnt+=floor(temp/pow(5,j));
        }

        cout<<cnt<<endl;*/

        int t,Case=1; scanf("%d",&t);
        ll q;

        while(t--)
        {
                scanf("%lld",&q);
                ll ans = binary(q);
                if(ans==-1)
                {
                        printf("Case %d: impossible\n",Case++);
                }
                else
                {
                       printf("Case %d: %lld\n",Case++,ans);
                }
        }
        return 0;
}


        /*ll cnt,t,Case=1,q,i,temp,j;
        vector<ll>ans;
        ans.push_back(0);
        for(i=5;i<=100000000;i+=5)
        {
                temp = i;
                cnt=0;
                while(temp%5==0)
                {
                        cnt++;
                        temp/=5;
                }

                ans.push_back(ans[i/5-1]+cnt);
        }
        //cout<<5*ans[100000000/5]<<endl;

       / for(i=0;i<=25;i++)
                cout<<i<<" : "<<ans[i]<<endl;/
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld",&q);

                vector<ll>::iterator low = lower_bound(ans.begin(),ans.end(),q);
                if(ans[low-ans.begin()]==q)
                {
                        ll lp = (ll)(low-ans.begin());
                        printf("Case %lld: %lld\n",Case++,5*lp);
                }
                else
                {
                        printf("Case %lld: impossible\n",Case++);
                }
        }*/
