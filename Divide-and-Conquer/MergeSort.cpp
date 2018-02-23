//
//  main.cpp
//  Divide-and-Conquer
//
//  Created by PRO on 2018-02-22.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;


void MergeSort(int array[],int p,int r);


void Merge(int array[],int p,int q,int r);

int main(int argc, const char * argv[]) {
    
    int array[10] = {9,8,7,6,4,3,2,5,1,15};
    int p = 0;
    int r = 9;
    int length = sizeof(array)/sizeof(array[0]);
    
    MergeSort(array, p, r);
    
    for(int i = 0 ; i < length;i ++){
        cout << array[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

void MergeSort(int array[],int p,int r){
    if(p < r){
        int q = (p + r)/2;
        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);
        Merge(array,p,q,r);
    }
}

void Merge(int array[],int p,int q,int r){
    int left = q - p + 1;
    int right = r - q;
    
    int array1[left + 2];
    int array2[right + 2];
    for(int i = 1;i <= left; i ++){
        array1[i] = array[p + i - 1];
    }
    for(int i = 1;i <= right; i ++){
        array2[i] = array[q + i];
    }
    array1[left + 1] = 10000;
    array2[right + 1] = 10000;
    int k1 = 1;
    int k2 = 1;
    for(int i = p; i <= r; i ++){
        if(array1[k1] <= array2[k2]){
            array[i] = array1[k1];
            k1 ++;
        }
        else{
            array[i] = array2[k2];
            k2 ++;
        }
    }
}
