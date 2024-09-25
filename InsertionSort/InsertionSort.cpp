#include <iostream>
#include <vector>
    
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(vector <int>& vec){
    int n=vec.size();
    for(int i=1; i<n; i++){
        int key=vec[i];
        int j=i-1;
        while(j>=0 && vec[j]>key){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=key;
    }
}

int main()
{
    vector <int> vec = {3,2,15,1,7};   
    insertionSort(vec);
    for(int num:vec){
        cout<<num<<" ";
    }
    
    return 0;
}
