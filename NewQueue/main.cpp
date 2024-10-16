#include <iostream>
#include <Queue.h>

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<"Front element: "<<q.frontElement()<<endl;
    return 0;
}
