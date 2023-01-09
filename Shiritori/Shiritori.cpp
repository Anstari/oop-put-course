#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Shiritori {
public:
    vector<string> word;
public:
    void play(string new_word) {
        int breakPoint = 0;
        word.push_back(new_word);
        if (word.size() > 1) {
            int vectorSize = word.size();
            int wordSize = word[vectorSize-2].length();
            if ((word[vectorSize - 1].at(0)) != (word[vectorSize - 2].at(wordSize-1))) {
                cout << "game over: "+word[vectorSize -1] + " doesn't start with " + word[vectorSize -2].at(wordSize-1) + "\n";
                breakPoint = 1;
                word.pop_back();
            }
            if (breakPoint == 0) {
                for (int i = 0; i < vectorSize - 1; i++) {
                    if (word[i] == word[vectorSize - 1]) {
                        cout << "game over: word \"" + word[i] + "\" was alredy used\n";             
                        word.pop_back();
                        break;
                    }
                }
            }
        }
    }
    void printWords() {
        
        for (int i = 0; i < word.size(); i++) {
            cout << word[i]+" ";
        }
        cout << '\n';
    }

    void restart() {
        word.clear();
        cout << "Game restarted\n";
    }

};


int main()
{
    Shiritori my_shiritori;
    my_shiritori.play("apple");
    my_shiritori.play("ear");
    my_shiritori.play("rhino");
    my_shiritori.play("corn");
    my_shiritori.printWords();
    my_shiritori.restart();
    my_shiritori.printWords();
    my_shiritori.play("hostess");
    my_shiritori.play("stash");
    my_shiritori.play("hostess");
    my_shiritori.printWords();
}

