//queue using stl
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    cout<<q.empty()<<endl;
    q.push(2);
    cout<<q.front()<<endl;
    q.push(3);
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q.size();
    return 0;
}
