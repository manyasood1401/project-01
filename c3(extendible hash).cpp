#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ExtendibleHash {
    vector<vector<int>> dir{2}; // Starts with 2 empty buckets

public:
    void insert(int key) {
        int i = key % dir.size();

        if (dir[i].size() == 2) {
            cout << "Bucket full! Resizing table...\n";
            vector<int> old = dir[i];
            old.push_back(key);

            dir[i].clear();
            dir.resize(dir.size() * 2);

            for (int x : old)
                dir[x % dir.size()].push_back(x);
        } else {
            dir[i].push_back(key);
        }
        cout << "Key inserted successfully.\n";
    }

    void search(int key) {
        auto& b = dir[key % dir.size()];
        if (find(b.begin(), b.end(), key) != b.end())
            cout << "Key found.\n";
        else
            cout << "Key not found.\n";
    }

    void deleteKey(int key) {
        auto& b = dir[key % dir.size()];
        auto it = find(b.begin(), b.end(), key);
        if (it != b.end()) {
            b.erase(it);
            cout << "Key deleted.\n";
        } else {
            cout << "Key not found.\n";
        }
    }

    void display() {
        for (int i = 0; i < dir.size(); i++) {
            cout << "Bucket " << i << ": ";
            for (int x : dir[i]) cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    ExtendibleHash h;
    int ch, key;

    while (true) {
        cout << "\n1.Insert  2.Search  3.Delete  4.Display  5.Exit\n";
        cin >> ch;
        if (ch == 5) break;

        if (ch >= 1 && ch <= 3) {
            cout << "Enter key: ";
            cin >> key;
        }

        if (ch == 1) h.insert(key);
        else if (ch == 2) h.search(key);
        else if (ch == 3) h.deleteKey(key);
        else if (ch == 4) h.display();
    }
}