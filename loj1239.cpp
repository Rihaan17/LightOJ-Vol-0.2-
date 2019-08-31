using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
        int t;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                for(i=0;i<n;i++)
                {
                        scanf("%s %d %d %d",&name[i],&a,&b,&c);
                        vol[i] = a*b*c;
                }

                for(i=0;i<n;i++)
                {
                        if(vol[i]<mini)
                        {
                                mini = vol[i];
                                min_idx = i;
                        }
                        if(vol[i]>maxi)
                        {
                                maxi = vol[i];
                                max_idx  = i;
                        }
                }
        }
}
