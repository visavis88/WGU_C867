//
//  roster.cpp
//  WGU_C867 Student Roster
//
//  Created by mykhaylo roslyak on 9/21/23.
//

#include "roster.h"
#include <iostream>


// Constructor
Roster::Roster() {
    
    this->numStudents = 0;
    for(int i = 0; i < MAX_STUDENTS; i++) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    for(int i = 0; i < numStudents; i++) {
        delete classRosterArray[i]; // Deallocate memory for each Student object
        classRosterArray[i] = nullptr; // Set the pointer to nullptr after deallocation
    }
}


int Roster::getSize() {
    return numStudents;
}

Student** Roster::getClassRosterArray() {
    return classRosterArray;  // Return the address of the array of pointers
}



void Roster::parse(string row) {
    size_t start = 0;
        size_t end = row.find(",");
        
        string studentID = row.substr(start, end - start);
        start = end + 1;
        end = row.find(",", start);
        
        string firstName = row.substr(start, end - start);
        start = end + 1;
        end = row.find(",", start);
        
        string lastName = row.substr(start, end - start);
        start = end + 1;
        end = row.find(",", start);
        
        string emailAddress = row.substr(start, end - start);
        start = end + 1;
        end = row.find(",", start);
        
        int age = stoi(row.substr(start, end - start));
        start = end + 1;
        end = row.find(",", start);
        
        int daysInCourse1 = stoi(row.substr(start, end - start));
        start = end + 1;
        end = row.find(",", start);
        
        int daysInCourse2 = stoi(row.substr(start, end - start));
        start = end + 1;
        end = row.find(",", start);
        
        int daysInCourse3 = stoi(row.substr(start, end - start));
        start = end + 1;
        end = row.find(",", start);
        
        DegreeProgram degreeProgram;
        string degreeStr = row.substr(start, end - start);
        if(degreeStr == "SECURITY") degreeProgram = SECURITY;
        else if(degreeStr == "NETWORK") degreeProgram = NETWORK;
        else degreeProgram = SOFTWARE;
        
        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
   
}

// Add Student to Roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    if(numStudents < MAX_STUDENTS) {
        int daysToCompleteCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        classRosterArray[numStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse, degreeProgram);
        numStudents++;
    } else {
        cout << "Cannot add more students, roster is full!" << endl;
    }
}


// Remove Student from Roster
void Roster::remove(string studentID) {
    
    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            
            // Delete the student object to avoid memory leaks
            delete classRosterArray[i];
            
            // Move the remaining elements up
            for (int j = i; j < numStudents - 1; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            
            numStudents--;
            break;
        }
    }
    
    if (!found) {
        cout << "Error: Student with ID " << studentID << " not found.\n";
    } else {
        cout << "Student with ID " << studentID << " has been removed from the roster.\n";
    }
}



void Roster::printAll() {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr) classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysToCompleteCourse();
            float average = (days[0] + days[1] + days[2]) / 3.0;
            cout << "The average number of days in the three courses for student ID " << studentID << " is: " << average << endl;
            return;
        }
    }
    cout << "Student with ID: " << studentID << " not found." << endl;
}

void Roster::printInvalidEmails()  {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getEmailAddress();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
                cout <<  email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)  {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram)
            classRosterArray[i]->print();
    }
}


