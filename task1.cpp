/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>

using namespace std;


class komputer{
    public:
        char marka[30];
        int cena;
        int moc;
        int czyjestwsklepie;
};

class gra{
    public:
        string nazwa;
        int cena;
        string opis;
        int moc;
};

class ksiazka{
    public:
        char nazwa[30];
        char rodzaj[30];
        int cena;
        string opis;
};

int main()
{
    komputer k1;
    cout<<"Prosze podac marke komputera 1: ";
    cin>>k1.marka;
    cout<<"Prosze podac cene komputera 1: ";
    cin>>k1.cena;
    cout<<"Prosze podac moc komputera 1 (1, 2 lub 3): ";
    cin>>k1.moc;
    cout<<"Czy komputer 1 jest w sklepie? (1-tak, 0-nie): ";
    cin>>k1.czyjestwsklepie;
    cout<<"Komputer 1: \nMarka: "<<k1.marka<<"\nCena:"<<k1.cena<<'\n';
    if (k1.czyjestwsklepie == 0){
        cout<<"Nie ma w sklepie\n";
    }
    else{
        cout<<"Jest w sklepie\n";
    }
    
    gra g1;
    g1.nazwa = "Witcher";
    g1.cena = 2;
    g1.moc = 3;
    
    if (k1.moc>=g1.moc){
        cout<<g1.nazwa<<" zadziala na komputerze "<<k1.marka;
    }
    else{
        cout<<g1.nazwa<<" nie zadziala na komputerze "<<k1.marka;
    }
    
    
    
    return 0;
    
    
    
}
