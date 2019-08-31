using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

int absolute(int x)
{
    if(x<0)
        return -x;
    return x;
}

bool cheaque(int x1,int y1,int x2,int y2)
{
    if((x1>x2&&y2>y1)||(x2>x1&&y1>y2))
    {

            /*if(x1>y1)
            {
                if(x2>y2)
                {
                    if((x1+y1)==(x2+y2))
                        return true;
                    return false;
                }
                return false;
            }
            else if(y1>x1)
            {
                if(y2>x2)
                {
                    if((y1+x1)==(y2+x2))
                        return true;
                    return false;
                }
                return false;
            }

            if((x1+y1)==(x2+y2))
                return true;
                return false;*/
        if((x1+y1)==(x2+y2))
            return true;

        return false;
    }
    else if((x1>x2&&y1>y2)||(x2>x1&&y2>y1))
    {
        //if(x1>x2&&y1>y2)
     //   {
            if(x1>y1)
            {
                if(x2>y2)
                {
                    if((x1-y1)==(x2-y2))
                        return true;
                    return false;
                }
                return false;
            }
            else if(y1>x1)
            {
                if(y2>x2)
                {
                    if((y1-x1)==(y2-x2))
                        return true;
                    return false;
                }
                return false;
            }

            if((x1-y1)==(x2-y2))
                return true;
                return false;
       // }

        /*if(absolute(x1-y1)==absolute(x2-y2))
            return true;

        return false;*/
    }
    return false;
}

int main()
{
    int x1,y1,x2,y2,T,Case=1;

    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        if((x1+y1)%2!=(x2+y2)%2)
            printf("Case %d: impossible\n",Case++);
        else if(cheaque(x1,y1,x2,y2))
            printf("Case %d: 1\n",Case++);
        else
            printf("Case %d: 2\n",Case++);
    }

    return 0;
}
