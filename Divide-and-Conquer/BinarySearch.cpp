//
//  BinarySearch.cpp
//  Divide-and-Conquer
//
//  Created by PRO on 2018-02-23.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;

int BinarySearch(int array[],int begin,int end,int x);

int main(int argc, const char * argv[]) {
    
    int array[10] = {11,22,33,44,55,66,77,88,99,100};
    cout<<BinarySearch(array,0,9,101)<<endl;
}

int BinarySearch(int array[],int begin,int end,int x){
    
    int middle = (begin + end)/2;
    if(begin == end){
        if(array[begin] == x)
            return begin;
        else
            return -1;
    }
    
    else if(array[middle] == x)
        return middle;
    else if(array[middle] > x)
        return BinarySearch(array,begin,middle,x);
    else
        return BinarySearch(array,middle + 1,end,x);
}
