#include<iostream>
#include<fstream>
using namespace std;
float reduceEchelonForm( float **matrix, int row, int col)
{
	  int point = 0; 
	int cut = 0; 
	for( int i = 0; i < row; i++)
	{
		if( matrix[i][0] == 1 )
		{
			point = i;
		}
		else if( matrix[i][0] > 1)
		{
			cut = matrix[i][0];
			for( int j = 0; j < col; j++)
			{
				matrix[i][j] -= matrix[point][j] * cut;
			}
		}
	}
    int lead = 0;
    while ( lead < row )
    {
        float div, mul;
        for (int i =0; i<row; i++)
        {
             
			 if(matrix[lead][lead] != 0)
            {
                div = matrix[lead][lead];
                mul = matrix[i][lead] / matrix[lead][lead];
                
            }
            else
            {
                div = 1;
                mul = 1;
                
            }
            for(int j =0; j<col; j++)
            {
                if( i == lead)
                {
                    if( matrix[i][j] != 0)
                    {
                        matrix[i][j] /= div;
                    }
                    else
                    {
                        matrix[i][j] = 0;
                    }
                    
                }
                else
                {
                    matrix[i][j] -= matrix[lead][j] * mul;
                }
            }
        }
        lead++; 
        int count = 0;
        int arr[row];
        int temp[row];
        for (int i = 0 ; i < row ; i++)
        {
            for (int j = 0 ; j < col ; j++)
            {
                if (matrix[i][j] == 0)
                {
                    count++;
                }
                if (j == col - 1)
                {
                    if (count == col)
                    {
                        arr[i] = 1;
                        count = 0;
                    }
                    else
                    {
                        arr[i] = 0;
                        count = 0;
                    }
                }
            }
        }
        int row1, row2;
        for (int i = 0 ; i < row - 1 ; i++)
        {
            if (arr[i] > arr[i+1] && i > 0)
            {
                row1 = i;
                row2 = i+1;
                for(int i = 0 ; i < col ; i++)
                {
                    swap(matrix[row1][i], matrix[row2][i]);
                }
            }
        }
      
        
    }
    return **matrix;
}