#include <iostream> // for std::cout, std::cin
#include <iomanip> // for std::setprecision
#include <cmath> // for std::ceil

using namespace std;

int main() {
    const double SPEED = 120.0;     // nautical miles per hour
    const double FUEL_RATE = 8.4;   // gallons per hour
    const double SAFETY_TIME = 0.5; // extra 30 minutes (0.5 hours) for safety
    
    char continueChoice = 'y';
    
    cout << "Aircraft Fuel Calculator" << endl << endl;
    
    while (continueChoice == 'y' || continueChoice == 'Y') {
        double distance;
        double flightTime, flightTimeWithSafety;
        int hours, minutes;
        double requiredFuel;
        
        cout << "Distance in nautical miles: ";
        cin >> distance;
        
        // calculate flight time in hours
        flightTime = distance / SPEED;
        
        // convert flight time to hours and minutes for display
        hours = static_cast<int>(flightTime);
        minutes = static_cast<int>((flightTime - hours) * 60);
        
        // add safety time for fuel calculation
        flightTimeWithSafety = flightTime + SAFETY_TIME;
        
        // calculate required fuel and round up to 1 decimal place
        requiredFuel = flightTimeWithSafety * FUEL_RATE;
        requiredFuel = ceil(requiredFuel * 10) / 10;  // round up to 1 decimal place
        
        cout << "Flight time: " << hours << " hour(s) and " << minutes << " minute(s)" << endl;
        cout << "Required fuel: " << fixed << setprecision(1) << requiredFuel << " gallons" << endl << endl;
        
        cout << "Continue? (y/n): ";
        cin >> continueChoice;
        cout << endl;
    }
    
    cout << "Bye!" << endl;
    
    return 0;
}