#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int choice;

    do {
        // ===== MENU =====
        cout << "===== Lost & Found Manager =====\n";
        cout << "1. Report Lost Item\n";
        cout << "2. Report Found Item\n";
        cout << "3. View All Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            // ===== CASE 1: REPORT LOST ITEM =====
            case 1: {
                string item, location, date;
                cin.ignore(); // clear input buffer
                cout << "Enter item name: ";
                getline(cin, item);
                cout << "Enter location: ";
                getline(cin, location);
                cout << "Enter date (DD-MM-YYYY): ";
                getline(cin, date);

                ofstream file("records.txt", ios::app); // append mode
                file << "LOST | " << item << " | " << location << " | " << date << "\n";
                file.close();

                cout << "Lost item recorded successfully!\n";
                break;
            }

            // ===== CASE 2: REPORT FOUND ITEM =====
            case 2: {
                string item, location, contact;
                cin.ignore(); // clear input buffer
                cout << "Enter item name: ";
                getline(cin, item);
                cout << "Enter location: ";
                getline(cin, location);
                cout << "Enter contact info: ";
                getline(cin, contact);

                ofstream file("records.txt", ios::app);
                file << "FOUND | " << item << " | " << location << " | " << contact << "\n";
                file.close();

                cout << "Found item recorded successfully!\n";
                break;
            }

            // ===== CASE 3: VIEW ALL RECORDS =====
            case 3: {
                ifstream file("records.txt");
                string line;
                if(file.is_open()) {
                    cout << "\n--- All Records ---\n";
                    while(getline(file, line)) {
                        cout << line << "\n";
                    }
                    file.close();
                } else {
                    cout << "No records found!\n";
                }
                break;
            }

            // ===== CASE 4: EXIT =====
            case 4:
                cout << "Exiting program. Thank you!\n";
                break;

            // ===== INVALID CHOICE =====
            default:
                cout << "Invalid choice. Try again!\n";
        }

        cout << "\n"; // add blank line
    } while(choice != 4); // loop until user chooses 4

    return 0;
}
