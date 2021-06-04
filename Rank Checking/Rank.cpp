#include <iostream>
#include "reduced.h"
using namespace std;



int function(float **array,int row,int column){
	int Rank_Ab =0;

	for(int i =0; i<row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			if (array[i][j] != 0)
			{
				Rank_Ab = Rank_Ab + 1;
				break;
			}
		}
	}

	cout << "Rank of Ab is " << Rank_Ab << endl;


	if (Rank_Ab != row)
	{
		cout << "The system is Non-trival and it is linearly Dependent" << endl;
	}
	if (Rank_Ab == row)
	{
		cout << "The system is Trival and it is linearly Independent" << endl;
	}
}


int main ()
{
	float **array = new float *[3];
    for (int i = 0; i < 3; ++i)
    {
        array[i] = new float [3];
    }

    cout << "Enter the value " << endl;


    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> array[i][j];
        }
    }

    cout << "Here is required Martix " << endl;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout <<  array[i][j] << "  ";
        }
        cout << endl;
    }

    reduceEchelonForm(array, 3, 3);

    cout << "After reducing the required Martixs " << endl;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout <<  array[i][j] << "  ";
        }
        cout << endl;
    }

	function(array,3,3);

}