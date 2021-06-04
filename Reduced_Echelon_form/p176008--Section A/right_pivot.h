#include <iostream>
using namespace std;

bool right_pvoit(float **arr, int row, int column){
		int vara;
        int counter = 0;
        int Booling = 0;
        for(int i =0; i < row; i++){
            for (int j = 0; i < row && j < column; )
            {
                if (arr[i][j] != 0)
                        {
                            if (counter > 0){
                            	if(vara < j){
                            		Booling = 1;
								}
								else{
									Booling = 0;
								}
							}
							else{

								Booling = 1;
								vara = j;
							}   
                            j =0;
                            i++;
                            counter++;
                        }
                else{
                    j++;
                }        
            }
        }
        return Booling;

}

