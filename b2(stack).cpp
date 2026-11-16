#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int ch, x, done;

    do {
        cout << "\n1.Add  2.Process  3.Display  4.Cancel  5.Exit\n";
        cin >> ch;

        if (ch == 1) {
            cout << "Event ID: ";
            cin >> x;
            q.push(x);
        }

        else if (ch == 2) {
            if (q.empty())
                cout << "No Event\n";
            else {
                cout << "Event " << q.front() << " happened? (1=Yes, 0=No): ";
                cin >> done;

                if (done == 1) {
                    cout << "Event Processed\n";
                    q.pop();
                }
                else
                    cout << "Event not happened, remains in queue\n";
            }
        }

        else if (ch == 3) {
            queue<int> temp = q;

            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
        }

        else if (ch == 4) {
            cout << "Enter ID to cancel: ";
            cin >> x;

            queue<int> temp;

            while (!q.empty()) {
                if (q.front() != x)
                    temp.push(q.front());
                q.pop();
            }

            q = temp;
        }

    } while (ch != 5);

    return 0;
}