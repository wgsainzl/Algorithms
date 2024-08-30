#include <iostream>
#include <vector>
    
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void bubbleSort(vector<int> & vec){
    int n = vec.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1-i;j++){
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> vec = {85,70,95,60,90};

    bubbleSort(vec);

    for(int num:vec){
        cout<<num<<" ";
    }
    
    return 0;
}