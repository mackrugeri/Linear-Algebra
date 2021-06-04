#include<iostream>
using namespace std;

int  reducing( float **matrix,int column,int row)
{

    for (int F_index = 0; F_index < row; )
    {
        float For_div =0.0;
        float  For_mul = 0.0;
        float swaping = 0.0;
        int counter = 0;
        float array[row];

        for (int i =0; i<row; i++)
        {
            if(matrix[F_index][F_index] != 0)
                {
                    For_div = matrix[F_index][F_index];
                    For_mul = ((matrix[i][F_index]) / (matrix[F_index][F_index]));
                    
                }
            if(matrix[F_index][F_index] == 0)
                {
                    For_div = 1;
                    For_mul = 1;
                    
                }
            for(int j =0; j<column; j++)
                {
                    if( i == F_index)
                        {
                            if( matrix[i][j] != 0)
                            {
                                matrix[i][j] = ((matrix[i][j]) / (For_div));
                            }
                            if(matrix[i][j] == 0)
                                {
                                    matrix[i][j] = 0;
                                }
                                
                        }
                    if (i != F_index)
                        {
                            matrix[i][j] = matrix[i][j] - (matrix[F_index][j] * For_mul);
                        }
                }
            } 
        F_index = F_index +1;
        for (int i = 0 ; i < row ; i++)
        {
            for (int j = 0 ; j < column ; j++)
            {
                if (matrix[i][j] == 0)
                {
                    counter = counter + 1;
                }
                if (j == column - 1)
                {
                    if (counter == column)
                    {
                        array[i] = 1;
                        counter = 0;
                    }
                    if (counter != column)
                    {
                        array[i] = 0;
                        counter = 0;
                    }
                }
            }
        }
        for (int i = 0 ; i < row - 1 ; i++)
        {
            if(i > 0){
                if (array[i] > array[i+1])
                {
                    for(int i = 0 ; i < column ; i++)
                    {
                        swaping = array[i];
                        array[i] = array[i+1];
                        array[i+1] = array[i];
                    }
                }
            }
        }
    }
}

