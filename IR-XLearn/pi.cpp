#include <fstream>
#include <iostream>
using namespace std;


int main()
{
	ifstream in;
	in.open("p.txt");
	ofstream out;
	out.open("pred.txt");
	double temp, y;
	double sum = 0;
	for(int i = 0; i < 172483; i++)
	{
		in >> y;
		out << y - 8.04 << "\n";
		sum += y - 8.04;
	}
	cout << sum / 172483.0;
	return 0;
}
