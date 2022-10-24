#include <iostream>

using namespace std;

class Cell_phone {
public:
    int c_id_cell;
    string c_brand;
    double c_price;



    Cell_phone(double price) {
        c_id_cell = -1;
        c_brand = "-1";
        c_price = price;
    };
    Cell_phone(string brand) {
        c_id_cell = -1;
        c_brand = brand;
        c_price = -1;
    };
    Cell_phone(int id_cell = 0, string brand = "Sumsung", double price = 100) {
        c_id_cell = id_cell;
        c_brand = brand;
        c_price = price;
    };

    void print() {
        cout << "id: " << c_id_cell << ", brand = " << c_brand << ", price: " << c_price << ";\n";
    }
};


class Twister {

};

int main()
{
    Cell_phone cel0;
    cel0.print();

    Cell_phone cel1(10.00);
    cel1.print();

    Cell_phone cel2("Nokia");
    cel2.print();

    Cell_phone cel3(3, "Xiaomi", 350.99);
    cel3.print();
}

