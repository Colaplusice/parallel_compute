#include <iostream>
#include <deque>
using namespace std;

deque<int> de;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int t;
        cin>>t;
        int i;
        bool flag = true;
        for(i = 0; i < de.size(); ++i)
        {
            if(100 - de[i] >= t)
            {
                de[i] += t;
                flag = false;
                cout<<t<<" "<<i+1<<endl;
                break;
            }
        }
        if(flag)
        {
            de.push_back(t);
            cout<<t<<" "<<de.size()<<endl;
        }
    }
    cout<<de.size()<<endl;

    return 0;
}
