
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <vector>
using namespace std;



namespace ariel
{

    string mat(int col_num, int row_num, char a, char b)
    {
        const int asciInf = 33;
        const int asciiSUP = 126;

        if (col_num%2 == 0 || row_num%2 ==0){
            __throw_invalid_argument("only odd");
        }

        if (asciInf > a || a > asciiSUP || asciInf > b || b > asciiSUP){
            __throw_invalid_argument("right ascii range please");
        }

        if (col_num <= 0 || row_num <= 0){
            __throw_invalid_argument("only positive");
        }

        if (a == '\n' || b == '\n' || a == '\t' || b == '\t'
            || a == '\r' || b == '\r' || a == ' ' || b == ' '){
            __throw_invalid_argument("those chars are not legal");
        }

        vector<vector<char>> arr(row_num, vector<char> (col_num, a));
        bool flag = true;
        if(row_num == 1 || col_num == 1){
            flag = false;
        }

  
        int inner = 1;
        int counter =  0;
      
        while(flag)
        {
            for (int i = inner; i<col_num-inner ; i++)
            {
                arr[inner+0][i] = b; // ceiling
                arr[row_num-inner-1][i] = b; // bottom

            }


            for (int i = inner; i<row_num-inner; i++){
                arr[i][inner+0] = b; // left side
                arr[i][col_num-inner-1] = b; // right side
            }
            counter ++ ;
            int j  =((min(row_num, col_num)+1)/2)/2;
            if ( counter== j){
                flag = false;
            }
            inner+=2;

        }

        string ans = string("");
        for(int i = 0 ; i<row_num;i++ ){
            for(int j = 0 ; j < col_num ; j ++ ){
                ans+= arr[i][j];
            }
            ans += "\n";
        }

        return ans;
    }
}