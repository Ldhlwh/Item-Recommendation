#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

int data[11977000][3];
int vdata[110000][3];
int tdata[200000][3];
int temp;


int main()
{
	ifstream in;
	in.open("t.sf");
	for(int i = 0; i < 11976538; i++)
	{
		in >> data[i][0] >> data[i][1] >> data[i][2] >> temp >> temp;
	}
	in.close();
	in.open("v.sf");
	for(int i = 0; i < 106717; i++)
	{
		in >> vdata[i][0] >> vdata[i][1] >> vdata[i][2] >> temp >> temp;
	}
	in.close();
	in.open("test.sf");
	for(int i = 0; i < 172483; i++)
	{
		in >> tdata[i][0] >> tdata[i][1] >> temp >> temp;
	}
	in.close();
		
	ofstream out;
	out.open("fbv-i.svd");
	int vst = 0;
	vdata[106717][0] = -100;
	for(int ved = 0; ved < 106718; ved++)
	{
		if(vdata[ved][0] == vdata[vst][0])
			continue;
		if(true)
		{
			int tst = 0, ted = 0;
			for(int j = 0; j < 172483; j++)
			{
				if(tdata[j][0] == vdata[vst][0])
				{
					tst = j;
					int k = j;
					while(tdata[k][0] == vdata[vst][0] && k < 172483)
					{
						k++;
					}
					ted = k;
					break;
				}
			}
			int st = 0, ed = 0;
			for(int j = 0; j < 11976583; j++)
			{
				if(data[j][0] == vdata[vst][0])
				{
					st = j;
					int k = j;
					while(data[k][0] == vdata[vst][0] && k < 11976583)
					{
						k++;
					}
					ed = k;
					break;
				}
			}
			double sru = sqrt(ted - tst + ed - st + ved - vst);
			out << ved - vst << " " << ted - tst + ed - st + ved - vst;
			for(int j = tst; j < ted; j++)
			{	
				double output;
				double temp = 1 / sru;
				if(fabs(temp) < 1e-8)
					output = 0.0;
				else
					output = temp;
				out << " " << tdata[j][1] << ":" << output;
			}
			for(int j = st; j < ed; j++)
			{
				double output;
				double temp = 1 / sru;
				if(fabs(temp) < 1e-8)
					output = 0.0;
				else
					output = temp;
				out << " " << data[j][1] << ":" << output;
			}
			for(int j = vst; j < ved; j++)
			{
				double output;
				double temp = 1 / sru;
				if(fabs(temp) < 1e-8)
					output = 0.0;
				else
					output = temp;
				out << " " << vdata[j][1] << ":" << output;
			}
		}
		out << "\n";
		vst = ved;
	}
	return 0;
}
