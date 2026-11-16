#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    float marks;
    Node* next;
} *head = NULL;

Node* find(int r) {
    for (Node* t = head; t; t = t->next)
        if (t->roll == r) return t;
    return NULL;
}

void add() {
    Node* n = new Node;
    cout << "Enter roll number: "; cin >> n->roll;
    cout << "Enter name: "; cin >> n->name;
    cout << "Enter marks: "; cin >> n->marks;
    n->next = head; head = n;
    cout << "Student added successfully!\n";
}

void display() {
    if (!head) cout << "No records found!\n";
    for (Node* t = head; t; t = t->next)
        cout << "\nRoll Number: " << t->roll << "\nName: " << t->name << "\nMarks: " << t->marks << "\n";
}

void search() {
    int r; cout << "Enter roll number to search: "; cin >> r;
    Node* t = find(r);
    if (t) cout << "Student found!\nName: " << t->name << "\nMarks: " << t->marks << "\n";
    else cout << "Student not found!\n";
}

void update() {
    int r; cout << "Enter roll number to update: "; cin >> r;
    Node* t = find(r);
    if (t) {
        cout << "Enter new name: "; cin >> t->name;
        cout << "Enter new marks: "; cin >> t->marks;
        cout << "Record updated successfully!\n";
    } else cout << "Student not found!\n";
}

void del() {
    int r; cout << "Enter roll number to delete: "; cin >> r;
    Node *t = head, *p = NULL;
    while (t && t->roll != r) { p = t; t = t->next; }
    if (!t) { cout << "Student not found!\n"; return; }
    if (!p) head = t->next; else p->next = t->next;
    delete t;
    cout << "Student deleted successfully!\n";
}

int main() {
    int ch;
    while (true) {
        cout << "\n===== STUDENT RECORD MANAGEMENT =====\n1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\nEnter your choice: ";
        if (!(cin >> ch)) { cout << "\nInvalid input! Please restart the program.\n"; return 1; }
        if (ch == 1) add();
        else if (ch == 2) display();
        else if (ch == 3) search();
        else if (ch == 4) update();
        else if (ch == 5) del();
        else if (ch == 6) { cout << "Program exited successfully!\n"; break; }
        else cout << "Invalid choice! Try again.\n";
    }
}