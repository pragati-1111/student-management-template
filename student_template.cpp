#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class MemoryCalculate {
public:
    T id;
    string name;

    MemoryCalculate(T i, string n) {
        id = i;
        name = n;
    }

    void showDetails() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate<int>> students;
    int ch;

    do {
        cout << "1. add Student" << endl;
        cout << "2. display all students" << endl;
        cout << "3. remove student by ID" << endl;
        cout << "4 search student by ID" << endl;
        cout << "0. exit" << endl;
        cout << "enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int id;
                string name;
                cout << "enter student ID: ";
                cin >> id;
                cout << "enter student Name: ";
                cin >> name;

                MemoryCalculate<int> s(id, name);
                students.push_back(s);

                cout << "student added successfully" << endl;
                break;
            }

            case 2: {
                for (int i = 0; i < students.size(); i++) {
                    students[i].showDetails();
                }
                break;
            }

            case 3: {
                int id;
                cout << "enter ID to remove: ";
                cin >> id;

                int i;
                for (i = 0; i < students.size(); i++) {
                    if (students[i].id == id) {
                        students.erase(students.begin() + i);
                        cout << "student removed" << endl;
                        break;
                    }
                }
                if (i == students.size()) {
                    cout << "ID not founde" << endl;
                }

                break;
            }

            case 4: {
                int id;
                cout << "enter id to search: ";
                cin >> id;

                for (int i = 0; i < students.size(); i++) {
                    if (students[i].id == id) {
                        students[i].showDetails();
                        break;
                    }
                    if (i == students.size() - 1) {
                        cout << "student not found" << endl;
                    }
                }
                break;
            }

            case 0:
                cout << "Exit...." << endl;
                break;

            default:
                cout << "invalid choice. please try again." << endl;
        }

    } while (ch != 0);

    return 0;
}
