//
//  roster.h
//  WGU_C867 Student Roster
//
//  Created by mykhaylo roslyak on 9/22/23.
//

#ifndef roster_h
#define roster_h

#include "student.h"


const int MAX_STUDENTS = 5;

class Roster {
private:
    Student* classRosterArray[MAX_STUDENTS]; // Array of pointers to Student objects
    int numStudents = 0; // Current number of students added to the array
    
public:
    
    Roster(); // Constructor
    ~Roster(); // Destructor
    
    int getSize();
    Student** getClassRosterArray();
    
    
    void parse(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    
};

#endif /* roster_h */

