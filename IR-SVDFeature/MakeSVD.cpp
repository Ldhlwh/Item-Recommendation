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
	inF.open("tv.sf");
	
	for(int i = 0; i < 12083255; i++)
	{
		inF >> userID[i] >> itemID[i] >> score[i] >> day[i] >> time[i];
		//system("pause");
	}
	
	cout << "------Finish Reading------\n";
	
	ofstream outF;
	outF.open("tv.feature");
	
	for(int i = 0; i < 12083255; i++)
	{
		int global = 0;
		for(int j = 0; j < 6; j++)
		{
			if(feat[itemID[i]][j] != -1)
				global++;
		}
		outF << score[i] / 100.0 << " 2 1 " << global + 1 << " " << day[i] + 2309 << ":1 " << time[i] << ":1 " << userID[i] << ":1 " << itemID[i] << ":1";
		if(feat[itemID[i]][0] != -1)
			outF << " " << feat[itemID[i]][0] + 497657 << ":1";
		if(feat[itemID[i]][1] != -1)
			outF << " " << feat[itemID[i]][1] + 549422 << ":1";
		if(feat[itemID[i]][2] != -1)
			outF << " " << feat[itemID[i]][2] + 569007 << ":1";
		if(feat[itemID[i]][3] != -1)
			outF << " " << feat[itemID[i]][3] + 569212 << ":1";
		if(feat[itemID[i]][4] != -1)
			outF << " " << feat[itemID[i]][4] + 569417 << ":1";
		if(feat[itemID[i]][5] != -1)
			outF << " " << feat[itemID[i]][5] + 569622 << ":1";
		outF << "\n";
	}
	cout << "------Finish Making------\n";
	outF.close();
	
	return 0;
}
