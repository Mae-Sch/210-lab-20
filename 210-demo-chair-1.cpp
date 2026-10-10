// Mae Schweller
// 210 lab 20
// 10/9/26
#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;
double NULL_LIST[SIZE]; //used to give constructor a default value

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2) + 3; //randon number 3-4
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % 90000) / 100; // random rpice from 100.00 to 999.99
    }
    Chair(int l, double* p = NULL_LIST) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    double pricesFirst[SIZE] = {441.41, 552.52, 663.63};
    collection[0] = Chair(4, pricesFirst);
    double pricesSecond[SIZE] = {484.84, 959.59, 868.68};
    collection[1] = Chair(4, pricesSecond);
    double pricesThird[SIZE] = {626.26, 515.15, 757.57};
    collection[2] = Chair(4, pricesThird);
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    cout << "\nPrinting randomly constructed chairs:\n\n";
    for (int i = 0; i < 5; ++i) {
        Chair randChair;
        randChair.print();
    }

    return 0;
}