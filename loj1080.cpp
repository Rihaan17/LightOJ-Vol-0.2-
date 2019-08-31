//{
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
//{
using namespace std;

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

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define INF 1<<29

#define pf printf
#define sc scanf


typedef long long int ll_d;
char arr[100000+10];
int M[600000],times;

void built_segment_tree(int node, int u, int v)
{
        if(u==v)
                M[node]=0;
        else
        {
                built_segment_tree(2*node,u,(u+v)/2);
                built_segment_tree(2*node+1,(u+v)/2+1,v);
                M[node] = 0;
        }
}

void update(int node,int left, int right, int u, int v)
{
        if(left>v||right<u)
                return;

        if(left>=u&&right<=v)
        {
                M[node]+=1;
                M[node]%=2;
                return;
                //update(node<<1,left,mid,u,v);
                //update(1+node<<1,mid+1,right,u,v);
        }
        else
        {
                int mid = (left+right)/2;

                if(u<=mid)
                        update(node*2,left,mid,u,v);
                if(v>mid)
                        update(1+node*2,mid+1,right,u,v);
        }

        //arr[node]=!arr[node];
}

void Query(int node, int left, int right, int u)
{
        if(left>u||right<u)
                return;

        /*if(u==7)
                cout<<"now : "<<node<<"  "<<M[node]<<" "<<left<<"  "<<right<<endl;*/

        if(left==u&&right==u){
                times=times+M[node];
                /*if(node==25)
                        cout<<"enter      "<<left<<"  "<<right<<"  "<<times<<"   "<<M[node]<<endl;*/
                return;
        }

        if(left<=u&&u<=right){
                times+=M[node];
                int mid = (left+right)/2;
                Query(2*node,left,mid,u);
                Query(2*node+1,mid+1,right,u);

                return;
        }

       /* int mid = (left+right)/2;



                Query(2*node,left,mid,u);

                Query(2*node+1,mid+1,right,u);*/
}

int main()
{
        int t,Case=1,u,v,n,q;
        char type[2];
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s",arr);
                scanf("%d",&q);
                n = strlen(arr);
                built_segment_tree(1,0,n-1);

                printf("Case %d:\n",Case++);

                while(q--)
                {
                        scanf("%s",type);times = 0;
                        if(type[0]=='I')
                        {
                                scanf("%d%d",&u,&v);
                                u--; v--;
                                update(1,0,n-1,u,v);
                                //cout<<M[4]<<" " <<M[5]<<" "<<M[6]<<" "<<M[9]<<" "<<M[13]<<" "<<M[17]<<" "<<M[20]<<" "<<M[25]<<endl;
                        }
                        else
                        {
                                //cout<<"M[25] "<<M[25]<<endl;
                                /*if(t==1)
                                {
                                     cout<<M[4]<<" "<<M[6]<<" "<<M[9]<<" "<<M[13]<<" "<<M[20];
                                }
                                cout<<endl;*/
                                scanf("%d",&u);
                                u--;

                                Query(1,0,n-1,u);
                                //cout<<"times: "<<times<<endl;
                                char ans;
                                if(times%2) ans=(arr[u]=='0'?'1':'0');
                                else ans = arr[u];
                                printf("%c\n",ans);
                        }
                }

        }
        return 0;
}


