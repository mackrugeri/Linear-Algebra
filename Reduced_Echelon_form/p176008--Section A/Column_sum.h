#include <iostream>
using namespace std;

bool Column_pviot(float  **arr, int row, int column){
		int sum = 0;
        int Booling = 0;
        for(int i =0; i < row; i++){
            for (int j = 0; i < row && j < column; )
            {
                if (arr[i][j] != 0)
                        {	
                        	int chck = 0;
                            for(int k =0; k <row;k++){
                            		sum = sum + arr[k][j];
                            		
							}
							if (sum == arr[i][j]){
								Booling = 1;
	
							}
							else{
								Booling = 0;	
							}
							sum = 0;
							cout << endl;
                            j =0;
                            i++;
                        }
                else{
                    j++;
                }        
            }
        }
        return Booling;

}

