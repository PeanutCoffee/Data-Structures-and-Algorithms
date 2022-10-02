#include<bits/stdc++.h>
using namespace std;

int priority(char c)
    {
        if(c == '^')
        {
            return 3;
        }
        else if(c == '*' or c == '/')
        {
            return 2;
        }
        else if(c == '+' or c == '-')
        {
            return 1;
        }
        else if(c == '(')
        {
            return -1;
        }
        else if(c == ')')
        {
            return 100;
        }
        else
        {
            return 0;
        }
    }

int main()
    {
        stack<char> s;

        string infix;
        cout << "Give Infix: ";
        cin >> infix;

        infix = "(" + infix + ")";

        cout << infix << endl;

        string postFix = "";

        for(char ch : infix)
        {
            cout << postFix << endl;

            if(priority(ch) == -1)
            {
                s.push(ch);
                //s.display();
                continue;
            }

            if(priority(ch) == 0)
            {
                postFix = postFix + ch;
                continue;
            }

            char chk = s.top();

            if(ch == ')')
            {
                while(chk != '(' and chk != 'a')
                {
                    postFix = postFix + chk;
                    s.pop();
                    chk = s.top();
                    //s.display();
                }

                if(chk != 'a')
                    s.pop();

                continue;
            }

            while(priority(chk) >= priority(ch))
            {
                postFix = postFix + chk;

                s.pop();
                chk = s.top();

                if(chk == 'a')
                {
                    break;
                }

                if(chk == '(')
                {
                    s.pop();
                    break;
                }
                //s.display();
            }

            s.push(ch);
        }

        cout << "\nPostFix: " << postFix << endl;

        stack<int> s1;

        for(char ch : postFix)
        {
            if(ch >= '0' and ch <= '9')
            {
                s1.push(int(ch - '0'));
            }

            else
            {
                int top1 = s1.top();
                s1.pop();
                int top2 = s1.top();
                s1.pop();

                if(ch == '+')
                {
                    s1.push(top1 + top2);
                }
                else if(ch == '-')
                {
                    s1.push(top2 - top1);
                }
                else if(ch == '*')
                {
                    s1.push(top1*top2);
                }
                else if(ch == '/')
                {
                    s1.push(top2/top1);
                }
            }
        }

        cout << "\n\nEvaluated Ans: " << s1.top();

        return 0;
    }