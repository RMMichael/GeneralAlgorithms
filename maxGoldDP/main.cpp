//
//  main.cpp
//  maxGoldDP
//
//  Created by Richard Michael on 9/9/19.
//  Copyright © 2019 Richard Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    
    int n,x;
    std::cin >> n >>x;
    std::vector<int> W(x);
    for(int i = 0;i<x;i++){
        int temp;
        std::cin >> temp;
        W[i]=temp;
    }
    std::vector<std::vector<int> > matrix(n+1,std::vector<int>(x+1));
    std::vector<int> val(n+1);
    for(int i = 0;i<=n;i++){
        for(int j = 0; j<=x;j++){
            if(i==0 ||j==0){
                matrix[i][j] = 0;
            }else if(W[j-1]<=i){
                matrix[i][j] = std::max(matrix[i-W[j-1]][j-1]+W[j-1],matrix[i][j-1]);
            }else{
                matrix[i][j] = matrix[i][j-1];
            }
        }
    }
    int k = 0;
    std::cout << matrix[n][x];
    
    
    return 0;
}
