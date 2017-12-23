/************************************************************************/
#include<iostream>
#include<string>
#include <stack>
using namespace  std;
int fh_uxj(char c)
{
    switch(c)
    {
    case '+':return 0;
    case '-':return 0;
    case '*':return 1;
    case '/':return 1;
    default: break;
    }
}
float szys(float a,float b,char c)
{
    switch (c)
    {
    case '+':return a+b;
    case '-':return a-b;
    case '*':return a*b;
    case '/':return a/b;
    }

}

int  main()
{
    stack <char> stack1;
    stack <float> stack2;
    string s_input,s_last,s_comput;
    cout<<"please input your data...."<<'\n';
    getline(cin,s_input);
    int j=0,last=-1;
    for (int i=0;i<s_input.size();i++)
    {
        char temp=s_input.at(i);
        if (s_input.at(i)>='0'&&s_input.at(i)<='9')
        {
            if (i-last!=1)
            {
                s_last.push_back(' ');
            }
            s_last.push_back(s_input.at(i));
            last=i;
        }
        else
        {
            if(stack1.empty())
            {
                stack1.push(s_input.at(i));
            }
            else
            {
                if (s_input.at(i)==')')
                {
                    while (stack1.top()!='(')
                    {
                        s_last.push_back(stack1.top());
                        stack1.pop();
                    }
                    stack1.pop();
                }
                else if (s_input.at(i)=='(')
                {
                    stack1.push(s_input.at(i));
                }
                else
                {
                    char flag=1;
                    while (stack1.top()!='(')
                    {
                        if (fh_uxj(stack1.top())<fh_uxj(s_input.at(i)))
                        {
                            flag=0;
                            stack1.push(s_input.at(i));
                            break;
                        }
                        else
                        {
                            s_last.push_back(stack1.top());
                            stack1.pop();
                            if (stack1.empty())
                                break;
                        }
                    }
                    if (flag) stack1.push(s_input.at(i));
                }
            }
        }
    }
    while (!stack1.empty())
    {
        s_last.push_back(stack1.top());
        stack1.pop();
    }
    for (int i=0;i<s_last.size();i++)
    {
        if (s_last.at(i)>='0'&&s_last.at(i)<='9')
        {
            float f_temp=0;
            while(s_last.at(i)>='0'&&s_last.at(i)<='9')
            {
                f_temp=f_temp*10;
                f_temp=f_temp+(float)(s_last.at(i)-48);
                i++;
            }
            stack2.push(f_temp);
            i--;
        }
        else if (s_last.at(i)==' ')
            continue;
        else
        {
            float a=(float)stack2.top();
            stack2.pop();
            float b=(float)stack2.top();
            stack2.pop();
            float c=szys(b,a,s_last.at(i));
            stack2.push(c);
        }
    }
    cout<<stack2.top();




    return 0;
}










