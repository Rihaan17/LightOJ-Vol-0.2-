using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>

#define ct cout<<"endl"<<endl

map<string,int>mp;
char sentence[100000+10];

int main()
{
        int t,n,m,ans;
        string str;
        scanf("%d",&t);

        int Case=1;

        while(t--)
        {
                printf("Case %d:\n",Case++);
                mp.clear();
                scanf("%d",&n);

                while(n--)
                {
                       cin>>str;
                       if(str.size()>=3)
                                sort(str.begin()+1,str.end()-1);
                        mp[str]++;
                }

                scanf("%d ",&m);
                while(m--)
                {
                        string word;
                        ans=1;
                        gets(sentence);
                        stringstream ss;
                        ss<<sentence;

                        while(ss>>word)
                        {
                                if(word.size()>=3)
                                        sort(word.begin()+1,word.end()-1);
                                ans*=mp[word];
                        }

                        printf("%d\n",ans);
                }
        }

        return 0;
}

/*struct node{
        int cnt[53];
        node *next[53];
        node(){
        for(int i=0;i<53;i++){
                next[i]=NULL;
                cnt[i]=0;
        }
        }
};

node *root;
map<char,int>mch;

void insert(char *str)
{
        node *curr=root;
        int i;

        for(i=0;str[i];i++)
        {
                if(curr->next[mch[str[i]]]==NULL)
                {
                        curr->next[mch[str[i]]]=new node();
                }
                //curr->cnt[mch[str[i]]]++;
                curr=curr->next[mch[str[i]]];
        }
        curr->cnt[mch[str[i-1]]]++;
}

void del(node *p)
{
        for(int i=0;i<53;i++)
        {
                if(p->next[i]!=NULL)
                {
                        del(p->next[i]);
                        delete p->next[i];
                }
        }
}

int check(char *str)
{
        node *curr=root;
        int i;

        for(i=0;str[i];i++)
        {
                if(curr->next[mch[str[i]]]==NULL)
                        return 0;
                curr=curr->next[mch[str[i]]];
        }
        return curr->cnt[mch[str[i-1]]];
}
char sentence[100000+10];

int main()
{
        for(char c = 'a';c<='z';c++)
                mch[c] = c-96;
        for(char c = 'A';c<='Z';c++)
                mch[c] = c-64+26;

        int t,n,m;
        long long ans;
        char str[110];//,word[100];
        scanf("%lld",&t);
        getchar();

        int Case=1;

        while(t--)
        {
                root=new node();
                scanf("%d",&n);

                while(n--)
                {
                       scanf("%s",str);
                       if(strlen(str)>3)
                                sort(str+1,str+strlen(str)-1);
                        //cout<<str<<endl;
                        insert(str);
                        //cout<<"aise"<<endl;
                }

                scanf("%d",&m);
                printf("Case %d:\n",Case++);
                getchar();
                while(m--)
                {
                        ans=1;
                        char delime[] = " ";
                        gets(sentence);
                        char *word = NULL;
                        word = strtok(sentence,delime);
                        while(word!=NULL)
                        {
                                //cout<<strlen(word)<<endl;
                                if(strlen(word)>3)
                                        sort(word+1,word+strlen(word)-1);
                                ans*=check(word);
                                word = strtok(NULL,delime);
                        }
                        printf("%lld\n",ans);
                }
                del(root);
        }

        return 0;
}
*/
