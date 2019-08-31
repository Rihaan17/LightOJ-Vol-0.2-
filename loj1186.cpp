#include<stdio.h>

int absolute(int x)
{
        if(x<0) return -x;
        return x;
}

int main()
{
        int XOR,t,w[105],b[105],Case=1,i,n;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                for(i=0;i<n;i++)
                        scanf("%d",&w[i]);

                for(i=0;i<n;i++)
                        scanf("%d",&b[i]);

                XOR=0;

                for(i=0;i<n;i++)
                {
                        XOR=XOR^(absolute(w[i]-b[i])-1);
                }

                if(XOR==0) printf("Case %d: black wins\n",Case++);
                else printf("Case %d: white wins\n",Case++);
        }

        return 0;
}
