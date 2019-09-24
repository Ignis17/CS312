#include <iostream>
using namespace std;

int main(){

    int arr[8] = {1,3,8,4,2,5,7,6};

    cout << "Unsorted array: ";
    for(int a=0; a < sizeof(arr-1);a++){
        cout << arr[a] << " " ;
    }
    cout << endl;

    for(int j=1; j < sizeof(arr-1);j++){
        int key = arr[j];
        int i = j -1;
        while(i > 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i = i-1;
            arr[i+1] = key;
        }
    }

    cout << "Sorted array: ";
    for(int a=0; a < sizeof(arr-1);a++){
         cout << arr[a] << " ";
    }
    cout << endl;
    
    return 0;
}

