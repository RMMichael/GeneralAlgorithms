//
//  main.cpp
//  minDistanceStrings
//
//  Created by Richard Michael on 9/7/19.
//  Copyright © 2019 Richard Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::string s1,s2;
    std::cin >> s1;
    std::cin >> s2;
    
    std::size_t l1 = s1.size();
    std::size_t l2 = s2.size();
    
    int i =0,j=0;
    
    std::vector<std::vector<int>> matrix(l1+1,std::vector<int>(l2+1));
    
    for(i=0;i<=l1;i++){
        matrix[i][0] = i;
    }
    for(j=0;j<=l2;j++){
        matrix[0][j] = j;
    }
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            
            if(s1[i-1]==s2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else{
                int del = 1+matrix[i-1][j];
                int ins = 1+matrix[i][j-1];
                int rep = 1+matrix[i-1][j-1];
                matrix[i][j] = std::min(del, std::min(ins,rep));
            }
        
            
        }
    }
    std::cout << matrix[l1][l2];
    
    return 0;
}
