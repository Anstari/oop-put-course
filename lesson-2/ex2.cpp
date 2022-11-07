#include <iostream>

using namespace std;

class Twister {
public:
	string t_color;
	string t_body_part;
	bool t_left_or_right;

	void print() {
		cout << "Color: " << t_color << ", body part: " << t_left_or_right <<" " << t_body_part;
	}
	void gen_color() {
		int i = rand() % 4;
		if (i == 0) t_color = "Red";
		else if (i == 1) t_color = "Green";
		else if (i == 2) t_color = "Blue";
		else t_color = "Yellow";
	};
};

int main()
{
	Twister t1;
	t1.gen_color();
	t1.print();
}

