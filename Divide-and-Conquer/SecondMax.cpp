//
//  SecondMax.cpp
//  Divide-and-Conquer
//
//  Created by PRO on 2018-02-27.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;
int Find_SM(int array[],int length,int max,int sm);

int main(int argc, const char * argv[]) {
    
    int array[10] = {1,14,56,11,5,90,28,100,200,300};
    int length = sizeof(array)/sizeof(array[0]);
    int secondMax = Find_SM(array,length,0,0);
    cout << secondMax<<endl;
    
    return 0;
}

int Find_SM(int array[],int length,int max,int sm){
    
    if(length == 1){
        int temp = array[length - 1];
        if(temp <= sm)
            return sm;
        else if (temp > sm && temp < max)
            return temp;
        else
            return max;
    }
    
    else {
        int temp = array[length - 1];
        if(temp <= sm)
        {
            return Find_SM(array, length -1,max,sm);
        }
        else if(temp > sm && temp < max){
            return Find_SM(array,length - 1, max, temp);
        }
        else {
            return Find_SM(array,length - 1, temp, max);
        }
    }
    
    return 0;
}
