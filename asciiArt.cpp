#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int decToHex(int n);

int main(int argc, char* argv[])
{
	if (argc < 3)	//need 3 arguments (key, inFile, outFile), argc is already 1
	{
		cerr << "Arguments missing" << endl;
		cerr << "Usage: euclid infile outfile" << endl;
		return 1; //program failed, not enough inputs
	}
	ifstream aInFile;
	ofstream aOutFile;
	aInFile.open(argv[1], ios::in);
	if (!aInFile.good())	//checks input file can be opened
	{
		aInFile.close();
		cerr << "Input file could not be opened" << endl;
		return 2;
	}
	else
	{
		cout << "Input file successfully opened" << endl;
		aOutFile.open(argv[2], ios::binary);	//open output file
		cout << "Output file " << argv[2] << " created" << endl;
	}
	int data;
	char value;
	while (aInFile.good())
	{
		aInFile >> data;
		for(int i = 0; i < 4; i++)
		{
			//printf("%d", data);
			value = data % 256;
			if(value == 0x0A)
			{
				aOutFile << endl;
			}
			else
			{
				aOutFile << value;
			}
			data = data / 256;
		}
	}
	aOutFile << endl << "Prepared by Joshua7922";
	aInFile.close();
	aOutFile.close();
	cout << endl << "Files successfully closed" << endl;
	return 0;
}
