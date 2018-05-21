#include <fstream>
#include <iostream>

using namespace std;

int feat[497700][7];
int userID[13976600];
int itemID[13976600];
int score[13976600];
int day[13976600];
int time[13976600];


int main()
{
	ifstream inF;
	
	inF.open("feature.txt");
	int temp;
	for(int i = 0; i < 497657; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(j == 0)
			{
				inF >> temp;
				continue;
			}
			inF >> feat[i][j - 1];
		}
	}
	cout << "------Finish Reading Feature------\n";
	
	
	inF.close();
	inF.open("test.tsv");
	
	const int dn = 172483;
	
	for(int i = 0; i < dn; i++)
	{
		inF >> userID[i] >> itemID[i] >> day[i] >> time[i];
		//cout << userID[i] << " " << itemID[i] << " " << score[i] << " " << day[i] << " " << time[i] << endl;
		//system("pause");
	}
	cout << "------Finish Reading------\n";
	
	ofstream outF;
	outF.open("testj.libfm");
	
	for(int i = 0; i < dn; i++)
	{
		outF << "0 " << userID[i] << ":1 " << itemID[i] + 60928 << ":1 " << time[i] / 100 + 630755 << ":1 " << (day[i] - 2870) / 100 + 630807 << ":1";		
		if(feat[itemID[i]][0] != -1)
			outF << " " << feat[itemID[i]][0] + 558585 << ":1";
		if(feat[itemID[i]][1] != -1)
			outF << " " << feat[itemID[i]][1] + 610350 << ":1";
		if(feat[itemID[i]][2] != -1)
			outF << " " << feat[itemID[i]][2] + 629935 << ":1";
		if(feat[itemID[i]][3] != -1)
			outF << " " << feat[itemID[i]][3] + 630140 << ":1";
		if(feat[itemID[i]][4] != -1)
			outF << " " << feat[itemID[i]][4] + 630345 << ":1";
		if(feat[itemID[i]][5] != -1)
			outF << " " << feat[itemID[i]][5] + 630550 << ":1";
		outF << "\n";
	}
	cout << "------Finish Making------\n";
	outF.close();
	
	return 0;
}
