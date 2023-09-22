//
//  main.cpp
//  WGU_C867 Student Roster
//
//  Created by mykhaylo roslyak on 9/21/23.
//
#include <iostream>
#include <string>
#include "roster.h"


using namespace std;



int main(int argc, const char * argv[]) {
    
    cout << "Course Title: Scripting and Programming - Applications C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011326947" << endl;
    cout << "Student Name: Mykhaylo Roslyak" << endl;
    cout << std::endl;
    
    
    
    
    
    const string studentData[] = {
      "A1,John,Smith,John1989@gm il.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Mykhaylo,Roslyak,mrosly1@wgu.edu,35,8,10,7,SOFTWARE"
    };
    
   
    
        
    Roster classRoster;
    
    cout << "All Students:"<< endl;
    for (int i = 0; i < MAX_STUDENTS; i++) classRoster.parse(studentData[i]);
    classRoster.printAll();
    cout << std::endl;
    
    cout << "Invalid Emails:"<< std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    

    
    
    
    cout << "Average days in course:"<< endl;
    for(int i = 0; i < classRoster.getSize(); ++i) {
        string studentID = classRoster.getClassRosterArray()[i]->getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << std::endl;
    
    
    cout << "Degree Program:"<< endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << std::endl;
    
    cout << "Remove:"<< endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    
    cout << "Remaining Students:"<< endl;
    classRoster.printAll();
    cout << std::endl;
    
    
    cout << "Remove again:"<< endl;
    classRoster.remove("A3");  // Expected to print an error message as "A3" should have been removed in the previous step.
    cout << std::endl;
    
    
    
    return 0;
}

