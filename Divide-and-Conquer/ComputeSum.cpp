//
//  ComputeSum.cpp
//  Divide-and-Conquer
//
//  Created by PRO on 2018-02-27.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;

int Compute_sum(int array[],int p,int r);

int main(int argc, const char * argv[]) {
    
    int array[6] = {10,20,15,40,60,25};
    int length = sizeof(array)/sizeof(array[0]);
    int sum = Compute_sum(array,0,length - 1);
    cout << sum<<endl;
    
    return 0;
}

int Compute_sum(int array[],int p,int r){
    
    int length = r - p + 1;
    
    if(length == 1){
        return array[p];
    }
    
    else if(length == 2){
        return array[p] + array[r];
    }
    
    else{
        int middle = (p + r)/2;
        int left = Compute_sum(array,p,middle);
        int right = Compute_sum(array,middle + 1, r);
        return left + right;
    }
}


