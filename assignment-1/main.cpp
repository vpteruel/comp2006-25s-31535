#include <iostream> // for std::cout, std::cin
#include <iomanip> // for std::setprecision

using namespace std;

int main() {
    double mealCost, tipPercent, tipAmount, totalAmount;
    
    cout << "Tip Calculator" << endl << endl;
    
    cout << "Cost of meal: ";
    cin >> mealCost;
    
    cout << "Tip percent: ";
    cin >> tipPercent;
    
    // calculate tip amount using the formula: tip = cost of meal * (tip percent / 100)
    tipAmount = mealCost * (tipPercent / 100.0);
    
    // calculate the total amount (meal cost + tip)
    totalAmount = mealCost + tipAmount;
    
    cout << endl;
    cout << "Tip amount: " << fixed << setprecision(2) << tipAmount << endl;
    cout << "Total amount: " << totalAmount << endl;
    
    return 0;
}