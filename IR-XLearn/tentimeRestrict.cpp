#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	in.open("pred.txt");
	ofstream out;
	out.open("predRestrict.txt");
	
	double temp;
	for(int i = 0; i < 172483; i++)
	{
		in >> temp;
		temp = min(1.0, temp);
		temp = max(0.0, temp);
		out << temp * 100 << "\n";
	}
	in.close();
	out.close();
	return 0;
}
