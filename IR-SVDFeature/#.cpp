#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	in.open("test.sf");
	ofstream out;
	out.open("paste.txt");
	
	int a, b, temp;
	
	for(int i = 0; i < 172483; i++)
	{
		in >> a >> b >> temp >> temp;
		out << a << "#" << b << "\n";
	}
	return 0;
}
