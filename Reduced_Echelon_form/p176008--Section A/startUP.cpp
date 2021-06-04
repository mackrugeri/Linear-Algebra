#include<iostream>
#include<fstream>
#include "pviot1.h"
#include "Column_sum.h"
#include "right_pivot.h"
#include "zero.h"
#include  "checking.h"
using namespace std;

int Start_in_reduction(float **martix, int row, int column){
    int vara=0;
    int check =0;
    float*swap;
    int M_row[column];

    for(int i =0; i<row; i++){
        vara = martix[i][0];
        for(int j =0; j<column;j++){
            M_row[j] = martix[i][j];
        }
        for(int k =0; k<column;k++){

            if(M_row[k]%vara == 0 && M_row[k] != 0){
                check = 1;
            }
            else{
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            for(int k =0;k<column;k++){
                        martix[i][k] = M_row[k]/vara;
                }
        }
    }
    // Reducing by table
    check =0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            M_row[j] = martix[i][j];
        }

        for(int t=2; t<20; t++){
            for(int k=0; k<column; k++){
                if(M_row[k]%t == 0 && M_row[k] != 0){
                    check = 1;
                }
                else{
                    check = 0;
                    break;
                }
            }
            for(int k =0;k<column;k++){
                if(check == 1){
                    martix[i][k] = M_row[k]/t;
                }
            }
        }
    }
    check =0;
    // If one is not on first Index 
    for(int i=0;i<row;i++){
        if(martix[0][0] == 1 ){
            check =0;
            break;
        }
        else{
            if(martix[i][0] == 1 ){
                vara = i;
                check = 1;
                break;
            }
            else{
                check =0;
            }
        }
    }
    if(check == 1){
            swap = martix[vara];

            martix[vara] = martix[0];

            martix[0] = swap;    

    }

     cout << "Here is requried Matrix" << endl;
    for(int i =0; i<row;i++){
        for(int j=0; j<column;j++){
            cout << martix[i][j] << " ";
        }
        cout << endl;
    }
    

    reducing( martix,column,row);

    for(int i =0 ;i<row; i++)
    {
        for(int j =0; j<column; j++)
        {
            cout<< martix[i][j] <<"\t";
        }
        cout<<endl;
    }
}

bool is_reducedEche_form(float **matrix, int row, int col) {
	int Booling =0;
	int a;
	int b;
	int c;
	int d;
	int array[4];
	int counter = 0;
	a = check(matrix, row, col);
	array[counter] = a;
	counter++;
	cout << "The value of a "<< a << endl;
	
	b = Column_pviot(matrix, row, col);
	array[counter] = b;
	counter++;

	cout << "The value of b" << b << endl;
	
	c = right_pvoit(matrix, row, col);
	array[counter] = c;
	counter++;
	
	cout << "The value of c" << c << endl;

	d = zero_pvoit(matrix,row,col);
	array[counter] = d;
	counter++;

	cout << "The value of d" << d << endl;
	
	for (int i=0; i<4; i++){
		if(array[i] == 0){
			Booling = 0;
			break;
		}
		else{
			
			Booling = 1;
		}
	}
	cout << Booling << endl;
	return Booling;
}

//Don't touch this function
void alloca_memory(float **matrix, int row, int col) {
	for (int i = 0; i < row; i++)
		matrix[i] = new float[col];
}

//Don't touch this function
void free_memory(float **matrix, int row) {
	for (int i = 0; i > row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

int  main() {

	int row = 0, col = 0, tmatrix = 0; int counter = 0;
	int vara;
	float **matrix = 0;
	ifstream in("in.txt");
	ofstream out("out.txt"); // will automatically created if not present

	if (!in.is_open()) {
		cout << "Error in opening file" << endl;
		return 0;
	}

	in >> tmatrix;
	out << tmatrix << endl;
	for (int i = 0; i < tmatrix; i++) {
		in >> row;
		in >> col;
		out << row << endl;
		out << col << endl;

		matrix = new float*[row];
		alloca_memory(matrix, row, col);

		for (int k = 0; k < row; k++) 
		{
			for (int j = 0; j < col; j++)
				{
					in >> matrix[k][j];
				 	cout << matrix[k][j] << " ";
				 } 
			cout << endl;
		}

		if (is_reducedEche_form(matrix, row, col)){ // your desired function to which you passes 2d array(matrix)
			for(int i=0; i<row; i++){
				for(int j=0; j<col;j++){
					out << matrix[i][j] << " ";
				}
				out << endl;
			}	
		}
		else{
			Start_in_reduction(matrix,row,col);			//Start_in_reduction(matrix,row,col);
			for(int i=0; i<row; i++){
				for(int j=0; j<col;j++){
					out << matrix[i][j] << " ";
				}
				out << endl;
			}	
		} 

		free_memory(matrix, row); // to free the memory allocated

	}


}
