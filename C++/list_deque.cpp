#include <bits/stdc++.h>
using namespace std;

void explainLIST()
{
    // What is a List?
    // List is similar to vector, but it allows us to do more up front operations

    list<int> li;       // {}
    li.push_back(2);    // {2}
    li.emplace_back(5); // {2,5}

    li.push_front(20);    //{20,2,5}
    li.emplace_front(13); //(13,20,2,5)

    for (auto it : li)
    {
        cout << it << " ";
    }
    cout << endl;

    // Rest functions same as a vector
    // begin, end, rbegin, rend, swap, clear, insert, size
}

void explainDEQUE()
{
    // What is a Deque?
    // Same as a vector or a list
    deque<int> dq;      // {}
    dq.push_back(2);    // {2}
    dq.emplace_back(5); // {2,5}

    dq.push_front(20);    //{20,2,5}
    dq.emplace_front(13); //(13,20,2,5)
    for (auto it : dq)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    explainLIST();
    explainDEQUE();
    return 0;
}