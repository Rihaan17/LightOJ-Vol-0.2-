using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        int t,row,col,i,j,Case=1,XOR;
        unsigned long long arr[55],x;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&row,&col);

                for(i=0;i<row;i++)
                {
                        arr[i]=0;
                        for(j=0;j<col;j++)
                        {
                                scanf("%llu",&x);
                                arr[i]+=x;
                        }
                }

                XOR=0;

                for(i=0;i<row;i++)
                        XOR^=arr[i];

                if(XOR) printf("Case %d: Alice\n",Case++);
                else printf("Case %d: Bob\n",Case++);
        }

        return 0;
}
