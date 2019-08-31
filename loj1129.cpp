/*using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

bool cmp(string a,string b)
{
        return a.size()>b.size();
}

struct node{
        node *next[12];

        node(){
                for(int i=0;i<12;i++)
                        next[i]=NULL;
        }
};

node *root=new node();
bool flag;

void insert(string str)
{
        int cnt=0;
        node *curr=root;
        for(int i=0;str[i];i++)
        {
                if(curr->next[str[i]-'0']==NULL)
                {
                        curr->next[str[i]-'0']=new node();
                        //flag=true;
                }
                else cnt++;
                curr=curr->next[str[i]-'0'];
        }
        if(cnt==str.length())
                flag=true;
}

void del(node *p)
{
        for(int i=0;i<12;i++)
        {
                if(p->next[i]!=NULL)
                {
                        del(p->next[i]);
                        delete p->next[i];
                }
        }
}

int main()
{
        int t,n,i,Case=1;
        scanf("%d",&t);
        vector<string>strr;
        string str;

        while(t--)
        {
                root=new node();
                scanf("%d",&n);
                for(i=0;i<n;i++){
                        cin>>str;
                        strr.push_back(str);
                }
               // cout<<"doneee"<<endl;
                sort(strr.begin(),strr.end(),cmp);
               / for(i=0;i<strr.size();i++)
                        cout<<strr[i]<<endl;/
                //cout<<"done"<<endl;

                flag=false;

                for(i=0;i<n;i++)
                {
                        insert(strr[i]);
                        if(flag)
                                break;
                }

                if(flag) printf("Case %d: NO\n",Case++);
                else printf("Case %d: YES\n",Case++);
                del(root);
                strr.clear();
        }

        return 0;
}

*/


using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define mini(a,b) ((a<b)?(a):(b))

bool check(string a,string b)
{
        int l = mini(a.size(),b.size());

        for(int i=0;i<l;i++)
        {
                if(a[i]!=b[i])
                        return false;
        }

        return true;
}

int main()
{
        int t,n,i,Case=1;
        vector<string>v;
        scanf("%d",&t);

        while(t--)
        {
                v.clear();
                scanf("%d",&n);

                string s;

                for(i=0;i<n;i++)
                {
                        cin>>s;
                        v.push_back(s);
                }

                sort(v.begin(),v.end());

                bool flag=true;

                for(i=0;i<n-1;i++)
                {
                        if(check(v[i],v[i+1]))
                        {
                                flag=false;
                                break;
                        }
                }

                if(flag)
                       printf("Case %d: YES\n",Case++);
                else
                        printf("Case %d: NO\n",Case++);
        }

        return 0;
}
