using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>

struct info{
        char str[100];
        int cnt;
}tushar[400];

int main()
{
        int t,n,i;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                for(i=1;i<n;i++)
                {
                        scanf("%s",str);
                        if(m[str1]==0){
                                m[str1]=cnt++;

                        }
                        if(m[str2]==0) m[str2]=cnt++;


                }
        }
}

/*map<string,int>m1;
map<int,string>m2;

int arr1[800],arr2[800];

void call(int x)
{
        if(arr1[x]==0){
                cout<<m2[x]<<endl;
                return;
        }
        call(arr1[x]);
        cout<<m2[x]<<endl;
}

int main()
{
        int t,n,i,cnt,temp,Case=1;
        string str1,str2;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);
                for(i=0;i<=2*n;i++) {arr1[i]=0; arr2[i]=0;}

                cnt=1;
                for(i=0;i<n-1;i++)
                {
                        cin>>str1>>str2;
                        if(m1[str1]==0) m1[str1]=cnt++;
                        if(m1[str2]==0) m1[str2]=cnt++;

                        m2[m1[str1]]=str1;
                        m2[m1[str2]]=str2;
                        arr2[m1[str1]]=m1[str2];
                        arr1[m1[str2]]=m1[str1];
                }
                temp=m1[str1];
                printf("Case %d:\n",Case++);
                call(temp);

                while(arr2[temp])
                {
                        temp=arr2[temp];
                        cout<<m2[temp]<<endl;
                }
                m1.clear(); m2.clear();
                 cout<<endl;
        }

        return 0;
}*/

/*map<string,string>mp1,mp2;
map<string,int>mp1f,mp2f;

void call(string str)
{
        if(!mp2f[str]){
                cout<<str<<endl;
                return;
        }
        call(mp2[str]);
        cout<<str<<endl;
}

int main()
{
        int t,i,Case=1,n;
        string str1,str2;
        scanf("%d",&t);
        //getchar();

        while(t--)
        {
                scanf("%d",&n);
               // getchar();

                for(i=0;i<n-1;i++)
                {
                        cin>>str1>>str2;
                       mp1[str1]=str2;
                       mp2[str2]=str1;
                       mp1f[str1]=1; mp2f[str2]=1;
                }

                printf("Case %d:\n",Case++);
                call(str1);
                while(mp1f[str1])
                {
                        cout<<mp1[str1]<<endl;
                        str1=mp1[str1];
                }
                mp1.clear(); mp2.clear(); mp1f.clear(); mp2f.clear();
        }
        return 0;
}
*/
