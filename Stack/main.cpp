#include <iostream>

#include "Stack.h"

int main()
{
    Stack stack;

    stack.push(30);
    stack.push(50);
    stack.push(70);

    cout<<"The top element is: "<<stack.top()<<endl;

    stack.pop();
    cout<<"The element after pop is: "<<stack.top()<<endl;

    return 0;
}
