#include <string.h>
#include <iostream>

using namespace std;

class Game {
public:
    virtual string result() = 0;
};

class FakeFootballGame : public Game
{
public:
    string result() {return "3:4";}
};


int main() {
    FakeFootballGame footballGame;
    try {
        string score = footballGame.result();
        if (score != "2:4") {
            throw exception("Wrong score");
        }
        cout << score << '\n';
    }
    catch (const exception& exc) {
        cout << exc.what() << endl;
        return(1);
    }

    return(0);
}