#include "Student.h"
#include <iostream>
#include <iomanip> 

int Student::nextId = 1000;  // starts student IDs from 1000

// Default constructor(delegation)
Student::Student() : Student("Unknown", "Undeclared", 0.0, "N/A", "N/A") {}

// parametarize constructor
Student::Student(const std::string& name, const std::string& department,
    double gpa, const std::string& phone, const std::string& email)
    : id(nextId++), name(name), department(department), gpa(gpa), phone(phone), email(email) {
}

// All getters
int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getDepartment() const {
    return department;
}

double Student::getGPA() const {
    return gpa;
}

std::string Student::getPhone() const {
    return phone;
}

std::string Student::getEmail() const {
    return email;
}

// Setters of All functions, returns nothing
void Student::updateGPA(double newGPA) {
    gpa = newGPA;
}

void Student::updateDepartment(const std::string& newDept) {
    department = newDept;
}

void Student::updatePhone(const std::string& newPhone) {
    phone = newPhone;
}

void Student::updateEmail(const std::string& newEmail) {
    email = newEmail;
}

// displaying these methods
void Student::display() const {
    std::cout << std::left << std::setw(6) << id
        << std::setw(20) << name
        << std::setw(20) << department
        << std::setw(6) << std::fixed << std::setprecision(2) << gpa
        << std::setw(15) << phone
        << std::setw(25) << email << '\n';
}

//  sorting students (by GPA descending)
bool Student::operator<(const Student& s) const {
    return this->gpa > s.gpa;  
}
