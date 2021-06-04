#include <iostream>
using namespace std;


bool check(float **arr,int row,int column){
        int counter = 1;
        int Booling = 0;
        for(int i =0; i < row; i++){
            for (int j = 0; i < row && j < column; )
            {
                if (arr[i][j] != 0)
                        {
                            if (arr[i][j] == 1){
                            		Booling = 1;
							}
							if(arr[i][j]!= 1
							){
								Booling = 0;
							}
							counter++;
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

