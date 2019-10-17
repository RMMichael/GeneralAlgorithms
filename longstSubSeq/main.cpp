//
//  main.cpp
//  longstSubSeq
//
//  Created by Richard Michael on 9/7/19.
//  Copyright © 2019 Richard Michael. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    int l1,l2,l3;
    std::cin >> l1;
    std::vector<int> s1(l1);
    for(int i = 0;i<l1;i++){
        int temp;
        std::cin >> temp;
        s1[i] = temp;
    }
    std::cin >> l2;
    std::vector<int> s2(l2);
    for(int i = 0;i<l2;i++){
        int temp;
        std::cin >> temp;
        s2[i] = temp;
    }
    std::cin >> l3;
    std::vector<int> s3(l3);
    for(int i = 0;i<l3;i++){
        int temp;
        std::cin >> temp;
        s3[i] = temp;
    }
    std::vector<std::vector<std::vector<int> > > matrix(l1+1,std::vector<std::vector<int> >(l2+1,std::vector<int>(l3+1)));
    for(int i = 0;i<=l1;i++){
        for(int j = 0;j<=l2;j++){
            for(int k = 0;k<=l3;k++){
                if(i==0 || j==0 || k==0){
                    matrix[i][j][k] = 0;
                }
                else if(s1[i-1]==s2[j-1] && s3[k-1]==s2[j-1]){
                    matrix[i][j][k] = matrix[i-1][j-1][k-1]+1;
                }
                else{
                    matrix[i][j][k] = std::max(matrix[i-1][j][k],std::max(matrix[i][j][k-1],matrix[i][j-1][k]));
                }
            }
        }
    }
    std::cout << matrix[l1][l2][l3];
    return 0;
}
