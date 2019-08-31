using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int T,x1,y1,x2,y2,x0,y0,Case=1,n;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        scanf("%d",&n);
        printf("Case %d:\n",Case++);
        while(n--)
        {
            scanf("%d%d",&x0,&y0);
            if((x0>=x1&&x0<=x2)&&(y0>=y1&&y0<=y2))
                printf("Yes");
            else
                printf("No");

            printf("\n");
        }

    }
    return 0;
}
