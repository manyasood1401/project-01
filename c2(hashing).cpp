#include <iostream>
using namespace std;

int t[10];

int find(int k) {
    for (int i = 0, idx; i < 10; i++) {
        idx = (k + i) % 10;
        if (t[idx] == k) return idx;
        if (t[idx] == -1) return -1;
    }
    return -1;
}

int main() {
    fill_n(t, 10, -1);
    int ch, k, p;

    while (true) {
        cout << "\n===== HASH TABLE =====\n1. Insert Key\n2. Search Key\n3. Delete Key\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> ch;

        if (ch == 5) { cout << "Exiting...\n"; break; }
        if (ch < 1 || ch > 5) { cout << "Invalid choice!\n"; continue; }

        if (ch == 4) {
            cout << "\nHash Table:\n";
            for (int i = 0; i < 10; i++)
                cout << i << " : " << (t[i] == -1 ? "Empty" : to_string(t[i])) << endl;
            continue;
        }

        cout << "Enter key: ";
        cin >> k;
        p = find(k);

        if (ch == 1) {
            if (p != -1) { cout << "Key already exists.\n"; continue; }
            for (int i = 0; i < 10; i++) {
                if (t[(k + i) % 10] == -1) { t[(k + i) % 10] = k; p = 1; break; }
            }
            cout << (p == 1 ? "Key inserted successfully.\n" : "Hash table is full.\n");
        } 
        else if (ch == 2)
            cout << (p != -1 ? "Key found at index " + to_string(p) + ".\n" : "Key not found.\n");
        else if (ch == 3) {
            if (p != -1) t[p] = -1;
            cout << (p != -1 ? "Key deleted successfully.\n" : "Key not found.\n");
        }
    }
}