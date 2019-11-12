/*
Joel Turbi & Luis Casado
Dr. Zavala
CS312 - Analysis of Algorithms Paradigms 
Sum of two - Team Project
10/22/2019
*/

#include <bits/stdc++.h>
#include <algorithm>
#include <cassert>
using namespace std;
// Used to create Set of Pairs of integers. 
typedef pair<int,int> pairs;

// Checks if array given is sorted.
bool isSorted(int A[], size_t N){
    for(int i=0; i < N-1;i++){
        if (A[i] > A[i + 1])return false;
    }
    return true;
}

/*Constant reference for speed const to avoid changing values */
void display(const set<pairs>& s, int x){
    bool found = false;

    cout << "The order pairs that sum up to, " << x << " are: \n";
    for (auto const &x : s){
        found = true;
        cout <<  "(" << x.first << ", " << x.second << ")" << " \n"; 
    }
    // If no order pairs are found it displays the following message.
    if(not found)
        cout << "No valid pair\n";
}


void sum2(int A1[], int A2[], int n1, int n2, int x){
    set<pairs> sum;
    int v1, v2;
    
    for(int i = 0; i < n1;i++){
        v1 = A1[i];
        v2 = x - v1;
        // Searches for the current value of v2 in A2 in a linear manner/search. 
        for(int j = 0; j < n2;j++){
            if(A2[j] == v2){
                pairs x = make_pair(v1,v2);
                sum.insert(x);
            }
        }
    }
    display(sum,x);
    sum.clear();
}

int main(){

    // Test #1
    /*int A1[] = {4,5,2,7,8,10};
    int A2[] = {1,9,-4,12,-7,-6};
    int x = 3;
    */
    // Test #2
    /*int A1[] = {4,5,2,7,8,10};
    int A2[]  = {1,9,-4,12,-7,-6};
    int x = 0;
    */
    // Test #3
    /*int A1[] = {4,5,2,7,8,10};
    int A2[] = {1,9,-4,12,-7,-6};
    int x = 7;
    */
    // Test #4
    int A1[] = {5,2,7,-8,10,-20,13,64,0,-36,-10,-4,-44};
    int A2[]  = {1,2,3,5,6,7,8,10,12,13,14,15,16,17,19,20,
                21,22,23,25,26,27,28,30,31,33,34,35,36,37,
                41,41,43,44,47,48,49,50,51,52,53,54,56,57,
                58,63,64,65,67,68,69,70,75,80};
    // Targeted # 
    int x = 14;

    // Gets the size of both arrays A1 & A2
    int n1 = sizeof(A1) / sizeof(A1[0]);
    int n2 = sizeof(A2) / sizeof(A2[0]);
   
    // Sorts arrays in increasing order:
    sort(A1, A1+n1);
    sort(A2, A2+n2);
    // Throws an error if the array is not sorted.
    assert(isSorted(A1,n1));  
    assert(isSorted(A2,n2));
    // Function call.
    sum2(A1,A2,n1,n2,x);
    return 0;
}