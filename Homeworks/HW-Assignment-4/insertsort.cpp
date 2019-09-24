/*
    Joel Turbi
    Dr. Zavala 
    CS312 – Analysis of Algorithms
    Homework Assignment 4 – INSERTION-SORT Implementation
    9/22/19
*/

#include <iostream>
#include <cassert>

using namespace std;

void insert(int A[], int i, int key) {
    while (i >= 0 && A[i] > key){
        A[i + 1] = A[i];
        i = i - 1;
    }
    A[i + 1] = key;
}

void insertionSort(int A[], size_t N) {
    
    for (int j = 1; j < N; j++)
    {
        int key = A[j];
        int i = j - 1;
        insert(A,i,key);
    }
}

bool isSorted(int A[], size_t N){
    for(int i=0; i < N-1;i++){
        if(!(A[i] <= A[i+1])){
            return false;
        }
    }
    return true;
}

void printArray(int A[], size_t N){
    cout << "{";
    for(int i=0; i < N; i++){
        cout << " " << A[i] << " ";
  }
  cout << "}\n";
}

int main () {
  int A[] = {22, 11, 99, 88, 9, 7, 42};
  int arrayTurbi [] = {17,10,12,19,21,7,16,60,40,27};
  // Calls printArray() function to display all elements in the array.
  printArray(A, 7);
  
  insertionSort(A,7);

  // Uncommented first line of code.
  assert(isSorted(A, 7));

  //Calls to insert function go here (to sort the array manually).
  insert(A, 0, 10);
  insert(A, 1, 80);
  insert(A, 2, 78);
  insert(A, 3, 12);
  insert(A, 4, 9);
  insert(A, 5, 50);
  // SECOND BLOCK OF COMMENTS 
  assert(isSorted(A, 7));
  cout << "Array after sorting:  " << endl;
  printArray(A, 7);

  // THIRD BLOCK OF COMMENTS
  int B[] = {222, 111, 999, 888, 99, 77, 422};
  insertionSort(B, 7);
  assert(isSorted(B, 7));
  cout << "Array after sorting:  " << endl;
  printArray(B, 7);

  // My array implementation.
  insertionSort(arrayTurbi,10);
  assert(isSorted(arrayTurbi, 10));
  cout << "My array after sorting:  " << endl;
  printArray(arrayTurbi, 10);
  
  return 0;
}
