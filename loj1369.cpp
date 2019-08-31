using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long int ll_d;

ll_d arr[100000+5],sum[100000+5],n;


int main()
{
        ll_d t,i,q,m,ans,x,Case=1,temp,k;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld%lld",&n,&q);

                for(i=0;i<n;i++)
                {
                        scanf("%lld",&arr[i]);
                }

                //sort(arr,arr+n);

                temp=sum[0]=arr[0];
                for(i=1;i<n;i++)
                {
                        sum[i]=temp-arr[i];
                        temp=sum[i];

                       // cout<<sum[i]<<" ";
                }

                ans=0;
                for(i=0;i<n;i++)
                {
                        temp=(n-(i+1))*arr[i];
                        ans+=((sum[n-1]-sum[i])+temp);
                }

                printf("Case %lld:\n",Case++);

                while(q--)
                {
                        scanf("%lld",&x);

                        if(x==0)
                        {
                                scanf("%lld%lld",&m,&k);
                                /*ans=ans-((n-m)*arr[m]);
                                arr[m]=k;
                                ans+=(n-m)*k;*/
                                ans=ans-((n-1-m)*arr[m]+m*arr[m]);
                                arr[m]=k;
                                ans=ans+((n-1-m)*arr[m]-m*arr[m]);

                        }
                        else
                        {
                                //ans=solve();
                                printf("%lld\n",ans);
                              /*  for(i=0;i<n;i++)
                                        cout<<arr[i]<<" x ";
                                cout<<endl;*/
                        }
                }
        }

        return 0;
}

    /* int flag;
                                if(ans<0)
                                        flag=-1;
                                else
                                        flag=1;

                                ans=subtraction(absolute(ans),absolute((n-1)*arr[m]));
                                if(flag==-1)
                                        ans=-ans;

                                if(ans<0)
                                        flag=-1;
                                else
                                        flag=1;

                                ans=(absolute(ans)+absolute((n-1)*k));
                                if(flag==-1)
                                        ans=-ans;*/
