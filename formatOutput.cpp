#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

string materialArray[500];
int quantityArray[500];
double costArray[500];

string format(string material, int quantity, double costPerUnit) {
    ostringstream formattedString;
    formattedString << left << setw(20) << material 
                    << left << setw(15) << to_string(quantity) + " Units"
                    << left << fixed << setprecision(2) << "$" << setw(19) << costPerUnit
                    << left << fixed << setprecision(2) << "$" << setw(15) << costPerUnit * quantity
                    << endl;
    return formattedString.str();
}

void print(int currentIndex) {
    string tempString;
    if (currentIndex != 0) {
        for (int i = 0; i < currentIndex; i++) {
            tempString = format(materialArray[i], quantityArray[i], costArray[i]);
            cout << tempString;
        }
    } else {
        cout << endl;
        cout << left << "No Materials Currently Listed!" << endl << endl << endl;
    }
}

int main() {
    string formattedString = "";
    string material;
    int quantity;
    double costPerUnit;
    int choice = 0;
    int currentIndex = 0;
    string tempString = "";
    ofstream outFile("outputFile.txt");

    while(choice != 4) {
        cout << endl;
        cout << "Select a Menu Option: " << endl;
        cout << "1: Add New Material" << endl;
        cout << "2: View Current Materials List" << endl;
        cout << "3: Output Materials List to File" << endl;
        cout << "4: Exit"<< endl << endl;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl;
            cout << "Invalid choice. Please Try Again" << endl << endl;
            continue;
        }
        
        switch (choice) {
            case 1: //Option 1: Add New Material
                cout << "Enter Material: ";
                cin.ignore(); //Ignores any leftover newline from previous inputs
                getline(cin, material); //Allows multi-word inputs
                cout << "Enter Quantity of " << material << ": ";
                cin >> quantity;
                cout << "Enter the Cost Per Unit of " << material << ": ";
                cin >> costPerUnit;
                
                materialArray[currentIndex] = material;
                quantityArray[currentIndex] = quantity;
                costArray[currentIndex] = costPerUnit;

                currentIndex++;

                cout << "------------------" << endl;
                cout << "Information Saved!" << endl;
                cout << "------------------" << endl << endl << endl;
                break;
            case 2: //Option 2: View Current Materials List
                cout << left << setw(20) << "Material" << left << setw(15) << "Quantity" << left << setw(20) << "Cost Per Unit" << left << setw(15) << "Materials Cost" << endl;
                cout << "=========================================================================" << endl;
                print(currentIndex);
                break;
            case 3: //Option 3: Output Materials List to File
                if(outFile.is_open()) {
                    //Title Section
                    outFile << setw(53) << "   Part Pricer Estimated Expense Report" << endl;
                    outFile << setw(53) << "   ====================================" << endl << endl; 

                    //Cost Breakdown Section
                    outFile << left << setw(20) << "Material" << left << setw(15) << "Quantity" << left << setw(20) << "Cost Per Unit" << left << setw(15) << "Materials Cost" << endl;
                    outFile << "=========================================================================" << endl;
                    for (int i = 0; i < currentIndex; i++) {
                        tempString = format(materialArray[i], quantityArray[i], costArray[i]);
                        outFile << tempString;
                    }

                    //Calculate Totals
                    int NumOfMaterialsTypes = currentIndex;
                    int totalMaterialsUnits = 0;
                    double totalCost = 0.0;

                    for (int i = 0; i < currentIndex; i++) {
                        totalMaterialsUnits += quantityArray[i];
                        totalCost += costArray[i] * quantityArray[i];
                    }
                    
                    //Total Cost Section                                   
                    outFile << endl << endl << endl << left << setw(55) << "Total Material Types..................................." << NumOfMaterialsTypes << " Material Types" << endl;
                    outFile << left << setw(55) << "Total Number of Units.................................." << totalMaterialsUnits << " Total Units" << endl;
                    outFile << left << setw(55) << fixed << setprecision(2) << "Estimated Total Cost..................................." << "$" << totalCost;

                    //Footer Section
                    outFile << endl << endl << right << setw(50) << "Thank you for using Part Pricer" << endl;
                    outFile << setw(50) << "  ===============================" << endl << endl;
                    outFile.close();
                    cout << endl;
                    cout << "File Saved!" << endl << endl;
                } else {
                    cout << endl;
                    cout << "Failed to open file for writing!" << endl << endl;
                }
                break;
            case 4://Option 4: Exit
                cout << endl;
                cout << "--------" << endl;
                cout << "Goodbye!" << endl;
                cout << "--------" << endl << endl;
                break;
            default:
                cout << endl;
                cout << "Invalid choice. Please Try Again" << endl << endl;
                break;
        }
    }    
        







    









    return 0;
}