#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int loadArrays(ifstream& fin, string[], double[][5], double[]);
void printReport(ofstream& fout, string[], double[][5], double[]);


int main()
{
	int length;
	string diverName[25];
	double diverScore[3][5];
	double diveDifficulty[3];
	ifstream fin("divers.txt");
	if (!fin.is_open())
	{
		cout << "File did not open correctly";
		system("pause");
		exit(666);
	}

	ofstream fout("results.rpt");
	if (!fout.is_open())
	{
		cout << "File did not open correctly.";
		system("pause");
		exit(666);
	}

	// call loadArrays function here
	length = loadArrays(fin, diverName, diverScore, diveDifficulty);

	//call printReport function here
	printReport(fout, diverName, diverScore, diveDifficulty);

	system("type results.rpt");
	system("pause");

}

int loadArrays(ifstream& fin, string diverName[], double diverScore[][5], double diveDifficulty[])
{
	int length = 0;	

	for (int ctr = 0; ctr < 3; ctr++)
	{

		getline(fin, diverName[ctr]);
		//fin.ignore(80, '\n');

		if (fin.eof())
			break;

		for (int index = 0; index < 5; index++)
		{
			fin >> diverScore[ctr][index];
		}
	
		fin >> diveDifficulty[ctr];
		fin.ignore(80, '\n');

		length++;
		
	}
	return length;
}

void printReport(ofstream& fout, string diverName[], double diverScore[][5], double diveDifficulty[])
{
	int length = 0;
	fout << setprecision(1) << fixed;
	for (int ctr = 0; ctr < 3; ctr++)
	{
		fout << setw(15) << left << diverName[ctr];

		for (int index = 0; index < 5; index++)
		{
			fout << setw(8) << right << diverScore[ctr][index] << " ";

		}
		fout << setw(8) << diveDifficulty[ctr] << " " << endl;
		length++;
	}
	fout << "Number of Divers: " << length << endl;
}
