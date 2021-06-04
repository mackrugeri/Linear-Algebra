#include <iostream>
using namespace std;
bool zero_pvoit(float  **arr, int row, int column){
        int sum =0;
        int arra[row];
        for(int i =0; i < row; i++){
            for (int j = 0; j < column; j++)
            {
                sum = sum + arr[i][j];
            }
            arra[i] = sum;
            
            sum =0 ;
        }
        
        for(int i =0; i < row;i++){
			if(i == row-1){
				return 1;
			}
			if(arra[i]==0 && i != 0){
				if(arra[i-1] > 0 && arra [i+1] >0){
						return 0;
				}
			}
			
			if(i == 0 && arra[i] == 0){
				if(arra[i+1] > 0 || arra[i+1] == 0){
					return 0;
				}
			}
	}

}

