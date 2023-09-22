//
//  student.cpp
//  WGU_C867 Student Roster
//
//  Created by mykhaylo roslyak on 9/21/23.
//

#include "student.h"
#include <iostream>

// Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    
    for (int i = 0; i < 3; i++)
        this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
    
    this->degreeProgram = degreeProgram;
}

// Destructor
Student::~Student() {
    // nothing to release, because we didn't dynamically allocate any memory
}


// Accessors
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysToCompleteCourse() { return daysToCompleteCourse; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

// Mutators
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToCompleteCourse(int daysToCompleteCourse[]) {
    for(int i = 0; i < 3; i++) {
        this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


// convert DegreeProgram enum to string
string Student::degreeProgramToString(DegreeProgram degreeProgram) {
    switch(degreeProgram) {
        case DegreeProgram::SOFTWARE: return "SOFTWARE";
        case DegreeProgram::NETWORK: return "NETWORK";
        case DegreeProgram::SECURITY: return "SECURITY";
        default: return "UNKNOWN";
    }
}

// print Student's info
void Student::print() {
    cout << getStudentID() << "\t";
    cout << "First Name: " << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "Days in course: {" << getDaysToCompleteCourse()[0] << ", " << getDaysToCompleteCourse()[1] << ", " << getDaysToCompleteCourse()[2] << "}\t";
    cout << "Degree Program: " << degreeProgramToString(getDegreeProgram()) << endl;
    
}





