//
//  main.cpp
//  NextPermutation
//
//  Created by Richard Michael on 9/18/19.
//  Copyright © 2019 Richard Michael. All rights reserved.
//

#include <iostream>
#include <vector>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void reverse(std::vector<int>& arr, unsigned long start){
   unsigned long end = arr.size()-1;
    
    while(start<end){
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }
    
}

std::vector<int> nextPermutation(std::vector<int> vec){
    unsigned long i = vec.size()-2;
    while(i>=0 && vec[i] >= vec[i+1]){
        i--;
    }
    unsigned long j = vec.size()-1;
    if(i>=0){
    while(j>=0 && vec[i]>=vec[j]){
        j--;
    }
    swap(&vec[i], &vec[j]);
    }
    reverse(vec, i+1);
    
    return vec;
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {1,1};
    std::vector<int> next = nextPermutation(arr);
    
    for(int i = 0;i<arr.size();i++){
        std::cout << arr[i] << std::endl;
    }
    
    return 0;
}
