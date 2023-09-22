//
//  student.h
//  WGU_C867 Student Roster
//
//  Created by mykhaylo roslyak on 9/22/23.
//

#ifndef student_h
#define student_h

#include <stdio.h>
#include "degree.h"
#include <string>


using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToCompleteCourse[3]; 
    DegreeProgram degreeProgram;
    
public:
    
    
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram); // Constructor
    ~Student(); // Destructor
    
    
    
    // Accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToCompleteCourse();
    DegreeProgram getDegreeProgram();
    
    // Mutators
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourse(int daysToCompleteCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    // convert DegreeProgram enum to string
    string degreeProgramToString(DegreeProgram degreeProgram);
    
    // print Student's info
    void print();
    
    
};

#endif /* student_h */
