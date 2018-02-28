//
//  SecondMax-half.cpp
//  Divide-and-Conquer
//
//  Created by PRO on 2018-02-27.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;
int Find_SM(int array[],int length,int p,int r);
int Find_Max(int array[],int p, int r);

int main(int argc, const char * argv[]) {
    
    int array[14] = {201,301,201,200,1,14,56,11,5,90,28,100,200,300};
    int length = sizeof(array)/sizeof(array[0]);
    int secondMax = Find_SM(array,length,0,length - 1);
    cout << secondMax<<endl;
    
    return 0;
}

int Find_SM(int array[],int length,int p,int r){
    if(length >= 2){
        int middle = (p + r)/2;
        int max_left = Find_Max(array,p,middle);
        int max_right = Find_Max(array,middle + 1, r);
        if(max_left > max_right)
            return max_right;
        else
            return max_left;
    }
    else
        return -1;
    
}

int Find_Max(int array[],int p, int r){
    
    int length = r - p + 1;
    if(length == 1)
        return  array[p];
    else if(length == 2){
        if(array[p] > array[r])
            return array[p];
        else
            return array[r];
    }
    else{
        int middle = (p + r)/2;
        int max_left = Find_Max(array,p,middle);
        int max_right = Find_Max(array,middle + 1, r);
        if(max_left > max_right)
            return max_left;
        else
            return max_right;
    }
}
