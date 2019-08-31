using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
	int T,i=1,a,b,ans;
	scanf("%d",&T);

    while(T--)
	{
       scanf("%d %d",&a,&b);
       if(a>b)
       {
           ans=19+(a+(a-b))*4;
       }
       else
       {
           ans=19+b*4;
       }


	   printf("Case %d: %d\n",i++,ans);
	}

	return 0;
}
