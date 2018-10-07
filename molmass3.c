#include <iostream>
#include <cctype>
#include <stack>

using namespace std;
//calculates the character code
int charencode(char ch)
{
    if (ch == 'C')
        return 12;
    else if(ch == 'O')
        return 16;
    else if(ch =='H')
        return 1;
     else
        return -1;
}

int main() {

    int total=0;
    stack<int> s;
    string str;
    cin >> str;
    int i=0;
    while (str[i])
    {
        if ( str[i]!= ')')
        {
            if (isdigit(str[i]))
            {
                int t = s.top() * (int)(str[i] - '0');
                s.pop();
                s.push(t);
            }
            else
                s.push(charencode(str[i]));

        }
        else
        {
            int sum=0;int t=s.top();
            while( (!s.empty()) && (t!=-1))
            {
                sum+= s.top();
                s.pop();
                t = s.top();
            }

            s.pop();
            s.push(sum);

        }

        i++;
    }
    //summing up the final stack
    while (!s.empty())
    {
        total+= s.top();
        s.pop();
    }
    cout << total <<"\n";

    return 0;
}
