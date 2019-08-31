using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>

#define max(a,b) ((a>b)?(a):(b))

int mx;

struct node{
        int cnt[5];
        node *next[5];
        node(){
                for(int i=0;i<5;i++){
                        next[i]=NULL;
                        cnt[i]=0;
                }
        }
};

node *root;
map<char,int>mch;

void insert(char *str)
{
        int temp;
        node *curr=root;

        for(int i=0;str[i];i++)
        {
                if(curr->next[mch[str[i]]]==NULL)
                {
                        curr->next[mch[str[i]]]=new node();
                }
                curr->cnt[mch[str[i]]]++;
                temp=curr->cnt[mch[str[i]]]*(i+1);
                curr=curr->next[mch[str[i]]];
                mx=max(mx,temp);
        }
}

void del(node *p)
{
        for(int i=0;i<5;i++)
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
        int n,t,i,Case=1;
        char str[55];
        scanf("%d",&t);
        mch['A']=0; mch['C']=1; mch['G']=2; mch['T']=3;

        while(t--)
        {
                root=new node();
                scanf("%d",&n);
                mx=0;

                while(n--)
                {
                        scanf("%s",str);
                        insert(str);
                }

                printf("Case %d: %d\n",Case++,mx);
                del(root);
        }

        return 0;
}
