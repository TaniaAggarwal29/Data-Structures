#include <iostream>
#include <cstdio>
using namespace std;

/*
Recursive call is made at the top.
all the other instructions are executed return time.
*/
void headRecursion(int n)
{
    if (n>0)
    {
        headRecursion(n-1);
        printf("%d ", n);
    }
}

//driver code
int main()
{
    headRecursion(5);	// prints : 1 2 3 4 5
    return 0;
}
