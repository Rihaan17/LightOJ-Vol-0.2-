using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        int t,n,a,b,c,mini,maxi,min_idx,max_idx,i,vol[100+10],Case=1;
        char name[100+10][25];
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                        scanf("%s %d %d %d",name[i],&a,&b,&c);
                        vol[i] = a*b*c;
                }

                maxi = mini = vol[0];
                max_idx = min_idx = 0;

                for(i=1;i<n;i++)
                {
                        if(vol[i]>maxi)
                        {
                                maxi = vol[i];
                                max_idx = i;
                        }
                        if(vol[i]<mini)
                        {
                                mini = vol[i];
                                min_idx = i;
                        }
                }

                if(maxi==vol[0]&&mini==vol[0])
                {
                        printf("Case %d: no thief\n",Case++);
                }
                else
                {
                        printf("Case %d: %s took chocolate from %s\n",Case++,name[max_idx],name[min_idx]);
                }
        }

        return 0;
}
