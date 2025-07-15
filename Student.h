#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
private:
    static int nextId;           // static is used here for auto generating ids
    int id;
    std::string name;
    std::string department;
    double gpa;
    std::string phone;
    std::string email;

public:
    
    Student();

    Student(const std::string& name, const std::string& department,
        double gpa, const std::string& phone, const std::string& email);

    // getters (it only getting data)
    int getId() const;
    std::string getName() const;
    std::string getDepartment() const;
    double getGPA() const;
    std::string getPhone() const;
    std::string getEmail() const;

    // Setter (or updating data)
    void updateGPA(double newGPA);
    void updateDepartment(const std::string& newDept);
    void updatePhone(const std::string& newPhone);
    void updateEmail(const std::string& newEmail);

    void display() const;

    // for comparing like top students of cgpa
    bool operator<(const Student& s) const;
};
#endif 
