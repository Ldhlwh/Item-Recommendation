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
	out.open("fb-i.svd");
	int st = 0;
	data[11976538][0] = -100;
	for(int ed = 0; ed < 11976539; ed++)
	{
		if(data[ed][0] == data[st][0])
			continue;
		if(true)
		{
			int tst = 0, ted = 0;
			for(int j = 0; j < 172483; j++)
			{
				if(tdata[j][0] == data[st][0])
				{
					tst = j;
					int k = j;
					while(tdata[k][0] == data[st][0] && k < 172483)
					{
						k++;
					}
					ted = k;
					break;
				}
			}
			int vst = 0, ved = 0;
			for(int j = 0; j < 106717; j++)
			{
				if(vdata[j][0] == data[st][0])
				{
					vst = j;
					int k = j;
					while(vdata[k][0] == data[st][0] && k < 106717)
					{
						k++;
					}
					ved = k;
					break;
				}
			}
			double sru = sqrt(ted - tst + ed - st + ved - vst);
			out << ed - st << " " << ted - tst + ed - st + ved - vst;
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
		st = ed;
	}
	return 0;
}
