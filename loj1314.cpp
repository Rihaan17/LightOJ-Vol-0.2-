using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

char str[10000+10];
int lcp[10000+10],sa[10000+10];

bool cmp(int a, int b)
{
        return strcmp(str+a,str+b)<0;
}

int main()
{
        int t,n,x,y,cnt,temp,Case=1,a,b,i;
        long long int ans;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s",str);
                scanf("%d %d",&a,&b);
                n=strlen(str);

              /*  if(a==b&&a==n)
                        printf("Case %d: %d\n",Case++,1);
                else
                {*/
                        for(i=0;i<n;i++) sa[i] = i;
                        sort(sa,sa+n,cmp);

                        lcp[0]=0;
                        for(i=1;i<n;i++)
                        {
                                cnt=0;
                                for(x=sa[i],y=sa[i-1];str[x]==str[y];x++,y++) cnt++;
                                lcp[i]=cnt;
                                //cout<<cnt<<endl;
                        }

                        a--;

                       x=a;
                       if(x>=n-sa[0]) ans=0;
                       else{
                               y=max(0,(n-sa[0]-b));
                               ans=n-sa[0]-lcp[0]-x-y;
                       }

                        for(i=1;i<n;i++)
                        {
                                if(a>=n-sa[i]) continue;
                                x=max(lcp[i],a);
                                y=max(0,(n-sa[i]-b));

                                if(x+y>n-sa[i]) y=(n-sa[i])-x;

                                temp=n-sa[i]-x-y;
                                ans+=temp;
                                //cout<<i<<" : "<<ans<<endl;
                        }

                        printf("Case %d: %lld\n",Case++,ans);
               // }
        }

        return 0;
}
