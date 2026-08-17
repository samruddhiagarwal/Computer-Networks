#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n========== Hamming Code Menu ==========\n";
        cout << "1. Generate Hamming Code\n";
        cout << "2. Detect and Correct Hamming Code\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int d7, d6, d5, d3;

            cout << "\nEnter 4 data bits (d7 d6 d5 d3): ";
            cin >> d7 >> d6 >> d5 >> d3;

            // Calculate parity bits
            int p1 = d7 ^ d5 ^ d3;
            int p2 = d7 ^ d6 ^ d3;
            int p4 = d7 ^ d6 ^ d5;

            int h[8]; // Index 1 to 7
            h[7] = d7;
            h[6] = d6;
            h[5] = d5;
            h[4] = p4;
            h[3] = d3;
            h[2] = p2;
            h[1] = p1;

            cout << "\nGenerated Hamming Code: ";
            for (int i = 7; i >= 1; i--)
                cout << h[i];
            cout << endl;

            break;
        }

        case 2: {
            int r[8];

            cout << "\nEnter received 7-bit Hamming code (d7 d6 d5 p4 d3 p2 p1):\n";
            cin >> r[7] >> r[6] >> r[5] >> r[4] >> r[3] >> r[2] >> r[1];

            // Calculate syndrome bits
            int s1 = r[1] ^ r[3] ^ r[5] ^ r[7];
            int s2 = r[2] ^ r[3] ^ r[6] ^ r[7];
            int s4 = r[4] ^ r[5] ^ r[6] ^ r[7];

            int errorPos = s4 * 4 + s2 * 2 + s1;

            if (errorPos == 0) {
                cout << "\nNo error detected.\n";
            } else {
                cout << "\nError detected at bit position: " << errorPos << endl;

                // Correct the error
                r[errorPos] ^= 1;

                cout << "Corrected Hamming Code: ";
                for (int i = 7; i >= 1; i--)
                    cout << r[i];
                cout << endl;
            }

            // Extract original data bits
            cout << "Recovered Data Bits: ";
            cout << r[7] << " " << r[6] << " " << r[5] << " " << r[3] << endl;

            break;
        }

        case 3:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice! Please enter 1, 2, or 3.\n";
        }

    } while (choice != 3);

    return 0;
}
