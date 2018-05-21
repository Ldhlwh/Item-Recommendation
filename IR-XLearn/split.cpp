#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	ofstream o1, o2;
	
	in.open("tv.shuffle");
	o1.open("tn.shuffle");
	o2.open("vn.shuffle");
	
	int a[5];
	
	for(int i = 0; i < 12083255; i++)
	{
		for(int j = 0; j < 5; j++)
			in >> a[j];
		
		if(i < 980311 || i >= 990311)
		{
			for(int j = 0; j < 4; j++)
				o1 << a[j] << "\t";
			o1 << a[4] << "\n";
		}
		else
		{
			for(int j = 0; j < 4; j++)
				o2 << a[j] << "\t";
			o2 << a[4] << "\n";
		}
	}
	return 0;
}
