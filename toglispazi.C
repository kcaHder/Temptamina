#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream iff("matriceinversa.txt");
	ofstream off("matricesenzaspazi.txt");
	char c;
	while(!iff.eof())	
	{
		if((c = iff.get()) != ' ' && c != '\n') off << c;
		if(c == '1' || c == '0') off << '\n';
	}
}
