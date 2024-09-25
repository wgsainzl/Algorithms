#include <iostream>
#include <vector>
    
using namespace std;

int linearSearch(vector<int> vec, int target){
    for(int i = 0; i<vec.size(); i++){
        if(vec[i]>target){
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {5,2,9,7,4,6};
    int target=5;

    int index = linearSearch(vec, target);

    if(index != -1){
        cout<<"Elemento: "<<vec[index];
    }
    else{
        cout<<"Elemento no encontrado";
    }
    
    return 0;
}
