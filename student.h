#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student
{


public:
    const static int daystoComplete = 3;

private:
	
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int ageofStudent;
	int daystoComp[daystoComplete];
	DegreeProgram degreeProgram;

public:

	Student();//Default Constructor
		Student (string studentID, string firstName, string lastName, string emailAddress, int ageofStudent, int daystoComp[], DegreeProgram degreeProgram);//Full Constructor
		~Student();/*Destructor*/

        //accessor aka getters
        string getID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAgeofStudent();
        int* getDaystoComp();
        DegreeProgram getDegreeProgram();

        //mutators aka setters
        void setID(string ID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAgeofStudent(int ageofStudent);
        void setDaystoComp(int daystoComp[]);
        void setDegreeProgram(DegreeProgram dp);
        
        static void printHeader();

        void print(); //will display student's data

};

/*
A. Modify the “studentData Table” to include your personal information as the last item.
B. Create a C++ project in your integrated development environment (IDE) with the following files:
• degree.h
• student.h and student.cpp
• roster.h and roster.cpp
• main.cpp
Note: There must be a total of six source code files.
C. Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.
Note: This information should be included in the degree.h file.
D. For the Student class, do the following:
1. Create the class Student in the files student.h and student.cpp, which includes each of the following variables:
• student ID
• first name
• last name
• email address
• age
• array of number of days to complete each course
• degree program
2. Create each of the following functions in the Student class:
a. an accessor (i.e., getter) for each instance variable from part D1
b. a mutator (i.e., setter) for each instance variable from part D1
c. All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d. constructor using all of the input parameters provided in the table
e. print() to print specific student data
white_check_mark
eyes
raised_hands

*/
