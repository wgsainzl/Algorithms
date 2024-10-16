#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree t;

    t.root = t.insert(t.root,50);
    t.root = t.insert(t.root,30);
    t.root = t.insert(t.root,70);

    int valueToSearch = 30;
    Node* result=t.search(t.root, valueToSearch);
    cout<<result->data;

    return 0;
}
