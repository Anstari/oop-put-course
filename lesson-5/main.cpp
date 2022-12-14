#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>

class FakeCantor {
private:
    std::map<std::string, float> rates{ {"USD", 1.0366f},
                                       {"GBP", 0.87063f},
                                       {"CHF", 0.9881f},
                                       {"JPY", 145.12f} };
public:
    FakeCantor() = default;
    float EuroToRate(const std::string& currency) {
        return rates[currency];
    };
};

class Currency {
public:
    virtual void AddedCurrency(float value, std::string currency) = 0;
    virtual void SubtractedCurrency(float value, std::string currency) = 0;
    virtual std::string Abbreviation() = 0;
    virtual std::string Symbol() = 0;
    virtual std::string Balance() = 0;
    virtual float DollarExchangeRate() = 0;
};

class Euro : public Currency, FakeCantor {
private:
    float balance;
public:
    void AddedCurrency(float value, std::string currency) {
        balance += value * EuroToRate(currency);
        std::cout<<value<<' ' << currency << " added or "<< value * EuroToRate(currency) <<" EUR\n";
    }
    void SubtractedCurrency(float value, std::string currency) {
        balance -= value * EuroToRate(currency);
        std::cout << value << ' ' << currency << " subtracted or " << value * EuroToRate(currency) << " EUR\n";
    }
    std::string Abbreviation(){
        return "EUR\n";
    }   
    std::string Symbol() {
        return "€\n";
    }
    std::string Balance() {
        return std::to_string(balance) + " EUR\n";
    }
    float DollarExchangeRate() {
        return EuroToRate("USD");
    }


    Euro() { balance = 0; }
};

int main() {
    // TODO: showcase usage
    FakeCantor fakeCantor;
    Euro euro;
    std::cout << euro.Balance();
    std::cout<<euro.Abbreviation();
    std::cout << euro.DollarExchangeRate();
    std::cout << euro.Symbol();
    euro.AddedCurrency(100.0f, "USD");
    std::cout << euro.Balance();
    euro.SubtractedCurrency(100.0f, "GBP");
    std::cout << euro.Balance();
    return 0;
}
