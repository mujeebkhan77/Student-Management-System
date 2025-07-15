#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> // its used for sorting
#include "Student.h"

using namespace std;

// Functions
void showMenu();
void addStudent(vector<Student>& students);
void displayAll(const vector<Student>& students);
void searchById(const vector<Student>& students);
void searchByName(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void showTopStudents(vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to remove new line char i.e (/)

        switch (choice) {
        case 1: addStudent(students); break;
        case 2: displayAll(students); break;
        case 3: searchById(students); break;
        case 4: searchByName(students); break;
        case 5: updateStudent(students); break;
        case 6: deleteStudent(students); break;
        case 7: showTopStudents(students); break;
        case 8: cout << " Exiting...........!\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }

        cout << "  ***----------------------------------------*** \n";

    } while (choice != 8);

    return 0;
}

void showMenu() {
    cout << "\n========== Student Management System ==========\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by ID\n";
    cout << "4. Search Student by Name\n";
    cout << "5. Update Student Info\n";
    cout << "6. Delete Student\n";
    cout << "7. Show Top 3 Students (by GPA)\n";
    cout << "8. Exit\n";
    cout << "===============================================\n";
}

void addStudent(vector<Student>& students) {
    string name, dept, phone, email;
    double gpa;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter department: ";
    getline(cin, dept);
    cout << "Enter GPA: ";
    cin >> gpa;
    cin.ignore();
    cout << "Enter phone: ";
    getline(cin, phone);
    cout << "Enter email: ";
    getline(cin, email);

    students.emplace_back(name, dept, gpa, phone, email);
    cout << " Student added successfully \n";
}

void displayAll(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }

    cout << left << setw(6) << "ID" << setw(20) << "Name"
        << setw(20) << "Department" << setw(6) << "GPA"
        << setw(15) << "Phone" << setw(25) << "Email\n";
    cout << string(90, '-') << '\n';

    for (const auto& s : students) // auto ki jaga Students b likh sakhtay but its efficient.
        s.display();
}

void searchById(const vector<Student>& students) {
    int id;
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    for (const auto& s : students) {
        if (s.getId() == id) {
            cout << " Student found:\n";
            s.display();
            return;
        }
    }

    cout << " Student not found.\n";
}

void searchByName(const vector<Student>& students) {
    string name;
    cout << "Enter name: ";
    getline(cin, name);

    bool found = false;
    for (const auto& s : students) {
        if (s.getName() == name) {
            cout << " Student found:\n";
            s.display();
            found = true;
        }
    }

    if (!found) cout << " No student found with this name.\n";
}

void updateStudent(vector<Student>& students) {

    if (students.empty()) {
        cout << " There is no students to update.\n";
        return;
    }

    int id;
    cout << "Enter student ID to update: ";
    cin >> id;
    cin.ignore();

    for (auto& s : students) {
        if (s.getId() == id) {
            int option;
            cout << "1. Update GPA\n2. Update Department\n3. Update Phone\n4. Update Email\n";
            cout << "Choose field to update: ";
            cin >> option;
            cin.ignore();

            if (option == 1) {
                double newGPA;
                cout << "Enter new GPA: ";
                cin >> newGPA;
                s.updateGPA(newGPA);
            }
            else if (option == 2) {
                string newDept;
                cout << "Enter new department: ";
                getline(cin, newDept);
                s.updateDepartment(newDept);
            }
            else if (option == 3) {
                string newPhone;
                cout << "Enter new phone: ";
                getline(cin, newPhone);
                s.updatePhone(newPhone);
            }
            else if (option == 4) {
                string newEmail;
                cout << "Enter new email: ";
                getline(cin, newEmail);
                s.updateEmail(newEmail);
            }
            else {
                cout << "Invalid option.\n";
            }

            cout << " Student updated successfully!\n";
            return;
        }
    }

    cout << " Student not found.\n";
}

void deleteStudent(vector<Student>& students) {

    if (students.empty()) {
        cout << "There is no students to delete.\n";
        return;
    }

    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    cin.ignore();

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) { // it is an iterator go through each student id
            students.erase(it);
            cout << " Student deleted.\n";
            return;
        }
    }

    cout << " Student not found.\n";
}

void showTopStudents(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in system.\n";
        return;
    }

    sort(students.begin(), students.end()); //  < operator
    int count = min(3, (int)students.size());

    cout << "\nTop " << count << " Students (by GPA):\n";
    for (int i = 0; i < count; ++i)
        students[i].display();
}
