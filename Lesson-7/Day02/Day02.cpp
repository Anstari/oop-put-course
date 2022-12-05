#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream infile("./Day02.txt");
	
	char a, b;
	int score = 0;
	while (infile >> a >> b)
	{
		if (b == 'X') score += 1;
		if (b == 'Y') score += 2;
		if (b == 'Z') score += 3;

		if (((a == 'A') && (b == 'X')) || ((a == 'B') && (b == 'Y')) || ((a == 'C') && (b == 'Z'))) score += 3; //draw
		if (((a == 'A') && (b == 'Y')) || ((a == 'B') && (b == 'Z')) || ((a == 'C') && (b == 'X'))) score += 6; //win

	}
		
	cout << score;

	return 0;
}
