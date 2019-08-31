using namespace std;

#include<iostream>
#include<cstring>
#include<stack>
#include<cstdio>

const string BACK    = "BACK";
const string FORWARD = "FORWARD";
const string VISIT   = "VISIT";
const string QUIT    = "QUIT";

int main()
{

    int T,Case=1;
    cin>>T;

    while(T--)
    {
        stack<string>forward,backward;
        string str,newstr,str2;
        printf("Case %d:\n",Case++);
        newstr="http://www.lightoj.com/";
        while(cin>>str&&str!=QUIT)
        {
            if(str==VISIT)
            {
                cin>>str2;
                backward.push(newstr);

                newstr=str2;


                while(!forward.empty())
                {
                    forward.pop();
                }
                cout<<str2<<endl;
            }

            else if(str==BACK)
            {
                if(backward.empty())
                    cout<<"Ignored"<<endl;
                else
                {
                    forward.push(newstr);
                    newstr=backward.top();
                    backward.pop();
                    cout<<newstr<<endl;
                }

            }
            else if(str==FORWARD)
            {
                if(forward.empty())
                    cout<<"Ignored"<<endl;
                else
                {
                    backward.push(newstr);
                    newstr=forward.top();
                    forward.pop();
                    cout<<newstr<<endl;
                }

            }
        }

    }

    return 0;
}

