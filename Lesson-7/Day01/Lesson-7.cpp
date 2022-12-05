#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Elf {
    int calories;
public:
    Elf(int calories) {
        this->calories=calories;
    };
    int getValue(){
        return calories;
    }
};


int main()
{
    vector<Elf> vect;

    fstream newFile;
    newFile.open("../Day01.txt", ios::in);
    if (newFile.is_open()) {
        string line;
        int cal = 0, i = 0, max = 0, max_i = 0;
        while (getline(newFile, line)) {
            if (line == "") {
                vect.push_back(cal);
                if (max < vect[i].getValue()) {
                    max = vect[i].getValue();
                    max_i = i;
                }
                cal = 0;
                i++;

            }
            else {
                cal += stoi(line);
            }
        }
        vect.push_back(cal);
        if (max < vect[i].getValue()) {
            max = vect[i].getValue();
            max_i = i;
        }


        for (Elf x : vect) {
            cout << x.getValue()<<"\n";
        }

        cout << "Elf #" << i << " is carrying the most Calories: " << max;
    }
    else exit(1);

    return 0;
}
