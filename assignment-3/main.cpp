#include <iostream> // for std::cout, std::cin
#include <fstream> // for file operations
#include <string> // for std::string
#include <iomanip> // for std::setw, std::setprecision
#include <vector> // for std::vector

using namespace std;

// structure to hold product data
struct Product {
    string code;
    double price;
    double discountPercent;
    double discountAmount;
    double finalPrice;
};

int main() {
    cout << "Product List" << endl << endl;
    
    // open input file
    ifstream inFile("products.txt");
    if (!inFile) {
        cout << "Error opening products.txt file." << endl;
        return 1;
    }
    
    cout << "Reading product data from products.txt file." << endl;
    
    // read and discard header line
    string header;
    getline(inFile, header);
    
    // read product data into vector
    vector<Product> products;
    string code;
    double price, discountPct;
    
    while (inFile >> code >> price >> discountPct) {
        Product product;
        product.code = code;
        product.price = price;
        product.discountPercent = discountPct * 100; // convert to percentage
        product.discountAmount = price * discountPct;
        product.finalPrice = price - product.discountAmount;
        
        products.push_back(product);
    }
    
    inFile.close();
    
    // open output file
    ofstream outFile("product_list.txt");
    if (!outFile) {
        cout << "Error creating product_list.txt file." << endl;
        return 1;
    }
    
    cout << "Writing product data to product_list.txt file." << endl;
    
    // write header to output file
    outFile << "CURRENT PRODUCT LIST" << endl;
    outFile << "=======================================================================" << endl;
    outFile << setw(16) << left << "code" 
            << setw(16) << left << "price" 
            << setw(16) << left << "discount" 
            << setw(16) << left << "discount" 
            << setw(16) << left << "your" << endl;
    outFile << setw(16) << left << "" 
            << setw(16) << left << "" 
            << setw(16) << left << "percent" 
            << setw(16) << left << "amount" 
            << setw(16) << left << "price" << endl;
    outFile << "=======================================================================" << endl;
    
    // write product data
    for (const Product& product : products) {
        outFile << setw(16) << left << product.code
                << fixed << setprecision(2) << setw(16) << left << product.price
                << setprecision(0) << setw(16) << left << product.discountPercent
                << setprecision(2) << setw(16) << left << product.discountAmount
                << setw(16) << left << product.finalPrice << endl;
    }
    
    outFile.close();

    cout << endl;
    cout << "Bye!" << endl;
    
    return 0;
}