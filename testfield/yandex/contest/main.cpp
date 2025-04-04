#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inFile("input.txt");
	std::ofstream outFile("output.txt");
	
	int a, b;
	inFile >> a >> b;
	outFile << a + b;
	
	return 0;
}