#include "roster.h"

void Roster::parse(string studentdata)
{
	
	//finds studentID
	long long int rhs = studentdata.find(",");//will find the comma
	string sID = studentdata.substr(0, rhs);

	//finds First Name
	long long int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string fn = studentdata.substr(lhs, rhs - lhs);

	//finds Last Name
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string ln = studentdata.substr(lhs, rhs - lhs);

	//finds Email Address
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string eaddress = studentdata.substr(lhs, rhs - lhs);

	//finds Student Age
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs));//converted string to int

	//Average Days in First Course
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int adic1 = stoi(studentdata.substr(lhs, rhs - lhs));

	//Average Days in Second Course
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int adic2 = stoi(studentdata.substr(lhs, rhs - lhs));
	
	//Average Days in Third Course
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int adic3 = stoi(studentdata.substr(lhs, rhs - lhs));

	//Degree Program
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string degree = studentdata.substr(lhs, rhs - lhs);

	DegreeProgram dp = SECURITY;
	if (degree == "NETWORK") {

		dp = NETWORK;

	}

	if (degree == "SOFTWARE") {
	
		dp = SOFTWARE;
	
	}


	add(sID, fn, ln, eaddress, age, adic1, adic2, adic3, dp);
}

void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sCompDays1, int sCompDays2, int sCompDays3, DegreeProgram dp)

{

	int CompsDaysArray[3] = { sCompDays1, sCompDays2, sCompDays3 };

	classRosterArray[++lastIndex] = new Student(sID, sFirstName, sLastName, sEmail, sAge, CompsDaysArray, dp);// Full Constructor

}

void Roster::removeID(string sID)

{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == sID)
		{
			any = true;

			if (i < numberofStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numberofStudents - 1];
				classRosterArray[numberofStudents - 1] = temp;
			}

			Roster::lastIndex--;
		}
	}
	if (any)
	{
		cout << sID << " has been removed from roster." << std::endl;
	}
	else cout << sID << "could not be found." << std::endl;

}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getID(); cout << '\t';
		if (classRosterArray[i]->getFirstName().size() > 6)
		{
			cout << classRosterArray[i]->getFirstName(); cout << '\t';
		}
		else
		{
			cout << classRosterArray[i]->getFirstName(); cout << '\t' << '\t';
			
		}
		if (classRosterArray[i]->getLastName().size() > 6)
		{
			cout << classRosterArray[i]->getLastName(); cout << '\t';
		}
		else
		{
			cout << classRosterArray[i]->getLastName(); cout << '\t' << '\t';

		}
		if (classRosterArray[i]->getEmailAddress().size() > 16)
		{
			cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		}
		else
		{
			cout << classRosterArray[i]->getEmailAddress(); cout << '\t' << '\t';

		}
		cout << classRosterArray[i]->getAgeofStudent(); cout << '\t';
		cout << classRosterArray[i]->getDaystoComp()[0]; cout <<',';
		cout << classRosterArray[i]->getDaystoComp()[1]; cout << ',';
		cout << classRosterArray[i]->getDaystoComp()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;

	}

}

void Roster::printAverageDaysInCourse(string sID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)

	
		if (classRosterArray[i]->getID() == sID) {

			cout << classRosterArray[i]->getID() << ": ";
			cout << classRosterArray[i]->getDaystoComp()[0]
				+ classRosterArray[i]->getDaystoComp()[1]
				+ classRosterArray[i]->getDaystoComp()[2]/3.0 << std::endl;
		}

		cout << std::endl;

	}

void Roster::printInvalidEmail()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sEmail = classRosterArray[i]->getEmailAddress();

		if ((sEmail.find("@") != string::npos) && (sEmail.find('.') != string::npos)) {

			if (sEmail.find(' ') != string::npos) {

				cout << sEmail;
				cout << std::endl;

			}
		}
		else {

			cout << sEmail;
			cout << std::endl;
		}
	}
}
	void Roster::printByDegreeProgram(DegreeProgram dp)
	{

		Student::printHeader();
		for (int i = 0; i <= Roster::lastIndex; i++)
		{

		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
		}

		cout << std::endl;

	}

	Roster::~Roster()
	{
		cout << "DESTRUCTOR" << std::endl << std::endl;
		for (int i = 0; i < numberofStudents; i++)
		{
			cout << "destroying student #" << i + 1 << std::endl;
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;

		}
	}





















/*
const string studentData[] =

{
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
"A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"


*/








/*
E. Create a Roster class (roster.cpp) by doing the following:
1. Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
2. Create a student object for each student in the data table and populate classRosterArray.
a. Parse each set of data identified in the “studentData Table.”
b. Add each student object to classRosterArray.
3. Define the following functions:
a. public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
b. public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
d. public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
e. public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
f. public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
white_check_mark
eyes
raised_hands
*/