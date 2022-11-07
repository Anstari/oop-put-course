class Game {
private:
    string tittle;
    string devStudioName;
    double price;
    int yearOfRelease;
public:

    Game(string tittle, string devStudioName, double price, int yearOfRelease) {
        this->tittle = tittle;
        this->devStudioName = devStudioName;
        this->price = price;
        this->yearOfRelease = yearOfRelease;
    }

    void ShowGameInfo() {
        cout << "Tittle: " << tittle << '\n';
        cout << "Created by: " << devStudioName << '\n';
        cout << "Release year: " << yearOfRelease << '\n';
        cout << "Current price: " << price << '\n';
    }

};