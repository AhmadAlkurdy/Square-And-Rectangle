// Name: Ahmad Alkurdy
// class: Algorithm
//My algorithm (not coded)
//              1- the program will generate the data and output the result to matrix.txt
//              2- it will read the data into a dynamic multi dim array
//              3- identify the location of the zero's and store the location as x for row and y for column
//              4- calculate the distance between every two zeros in every row and store the 
//                 the distance with the two array of structs
//              5- loop through the colomns and compare the distance of every two location from every rows  
//              6- output the matching with the location to a file
//                          
// Due the short time I have I just coded the simplest way and lease effiecent which uses four for loops
//           1- find the first zero in the first loop
//           2- find another zero in the same row
//           3- loop to looks for zero in the same locations in different rows
//           the only problem with this algorithm that when i request the max numbers of the matrix
//           it takes about 5 second to be processed



//declaring labriries 
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>


using namespace std;
//functions I am using 
void generate(int rows, int columns);
void promptUser();
void identifier(int rows,int columns);

int main()
{
	//prompt the user to get the size of the generated matrix
	promptUser();
}

void promptUser()
{
    int columns = 0;
	int rows = 0;
	char answer = 0;
	//prompting the user
	cout << "Enter the size of the matrix, the matrix can be 10 to 50 rows, and" <<
		" 10 to 80 column" << endl;
	cout << "Enter Rows:" << endl;
	
	//error handling
	cin >> rows;
	if(rows < 10 || rows > 50)
	{
		cout << "Invalid input" << endl;
		system("pause");
	}
	cout << "Enter columns: " << endl;
	cin >> columns;
	if(columns < 10 || columns > 80)
	{
		cout << "Invalid input" << endl;
		system("pause");
	}

	//call the genrating function
	generate(rows,columns);
	//prompting the user to ask if wanting to process the file generated
	cout << "The file with the genreate binary numbers is created and closed." << endl;
	cout << "Do you want to process the data to identify each location where the 0's form the four" << 
		" corners of a square or rectangle? y/n" << endl;
	cin >> answer;
	if (answer == 'y')
	{
		//if the user choose y which is yes it will call the identifier function to process the data
		identifier(rows,columns);
	}
	else if(answer == 'n')
	{
		return;
	}
	else
	{
		//error handling
		cout << "invalid input" << endl;
		system("pause");
	}
	
}
//this function will generate random binary numbers and output them to matrix.txt
void generate( int rows, int columns)
{
	ofstream output;
	output.open("matrix.txt");
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			output << rand() % 2 << " "; //randomly generating 
		}
		output << endl;
	}
	output.close();
}
//this function will do the identifiction 
void identifier(int rows,int columns)
{
	//allocate matrix with the max numbers required for the rows and columns
	int matrix[50][80];
	ifstream input; //declare input file
	ofstream output;//declare output file
	input.open("matrix.txt");
	if (!input.is_open())
	{
		cout << "Unable to open file" << endl; 
		system("pause");

	}

	else 
	{
		//read the binary numbers from the file into the matrix
		for(int i = 0; i< rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				input >> matrix[i][j];

			}
		}
		//algorithm for the search
		output.open("corners.txt");
		 for (int i = 0; i < rows; i++) //for the first row
        {
                
                for (int j= 0; j < columns; j++) //for the first columns
                {
                        if (matrix[i][j] == 0) //if there is a zero 
                        {
							//it will look for a second one
                                for (int k = j + 1; k < columns; k++)
                                {
                                        if (matrix[i][k] == 0)
                                        {
                                                for (int x = i + 1; x < rows; x++)
                                                {
                                                        
                                                        if (matrix[x][j] == 0 && matrix[x][k] == 0)
                                                        {
															//if they match then the locations will be output to corners.txt file
                                                                output << "(" << i << "," << j << ")," <<
																	"(" << i << "," << k << ")," << 
																	"(" << x << "," << j << ")," <<
																	"(" << x << "," << k << ")" << endl;
                                                        }
                                                }

                                        }
                                }

                        }
                }
        }       


	}
	//closing the files
	output.close();
	input.close();
	
}