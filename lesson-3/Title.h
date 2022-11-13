#include <iostream>
#ifndef CPP_TITLE_H
#define CPP_TITLE_H


using namespace std;

class Title {
private:
	string fullTitle;
	string shortTitle;
public:
	string value(string form) {
		return form == "full" ? this->fullTitle : this->shortTitle;
	}
	Title(string fullTitle, string shortTitle) {
		this->fullTitle = fullTitle;
		this->shortTitle = shortTitle;
	}
	Title(){}
};
#endif //CPP_TITLE_H