#include<iostream>
#include<stack>
using namespace std;

stack<string> undostack, redostack;
string document = "";

void makechange() {
	undostack.push(document);
	cout<<"Enter new data"<<endl;
	cin.ignore();
	getline(cin, document);
	while (!redostack.empty()) redostack.pop();
}

void undo() {
	if (undostack.empty()) {
	cout<<"Nothing to undo";
	return; 
	}
	redostack.push(document);
	document=undostack.top();
	undostack.pop();
}

void redo() {
	if (redostack.empty()) {
	cout<<"Nothing to redo";
	return;
	}
	undostack.push(document);
	document=redostack.top();
	redostack.pop();
}

int main() {
int choice;
do{
	cout<<"1. Make Change, 2. Undo, 3. Redo, 4.Display, 5.Exit"<<endl;
	cout<<"Enter your Choice"<<endl;
	cin >> choice;

	switch(choice) {
		case 1: makechange(); break;
		case 2: undo(); break;
		case 3: redo(); break;
		case 4: cout<< "Document:" <<document<<endl; break;
		case 5: break;
		default: cout<< "Invalid Choice"<<endl;
	}
} while (choice != 5);

return 0;
}