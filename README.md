# Hostel_Management_System


This code implements a Hostel Management System using C++. The system manages student information, their hostel rooms, and their fees.

The code begins by including the necessary header files for input/output operations and string manipulation. The using namespace std statement allows the use of standard library functions without explicitly qualifying them with std::.

The code defines two classes: Student and HostelManagementSystem. The Student class represents a student and contains various attributes such as userId, password, name, emailId, phoneNo, fees, and roomNo.

The HostelManagementSystem class is the main class that represents the hostel management system. It contains private member variables: an array of Student objects called students, the total number of students numStudents, and the ID of the currently logged-in user loggedInUserId.

The HostelManagementSystem class also includes several member functions:

HostelManagementSystem(): The constructor initializes the numStudents and loggedInUserId variables and populates the students array with some sample data.

start(): This function is the main entry point of the program. It displays a menu of options and allows the user to perform various operations such as viewing information, logging in, adding new students, etc. It uses a switch statement to execute different functions based on the user's choice.

aboutUs(): This function displays information about the hostel facilities and services. It also provides an option to go back to the main menu.

loginAcc(): This function prompts the user to enter a user ID and password for login. It checks if the entered credentials match any existing student's credentials and logs in the user if successful.

loggedInAcc(): This function is called after a successful login. It displays a menu of options for the logged-in student, allowing them to perform operations such as paying fees, viewing their profile, changing rooms, canceling rooms, etc.

payFees(): This function allows the logged-in student to pay their fees. It displays the student's name and fees and prompts for the amount to be paid. It updates the fees and displays a success message if the payment is sufficient.

viewProfile(): This function displays the profile information of the logged-in student, including their name, user ID, email ID, phone number, room number, and fees.

roomChange(): This function allows the logged-in student to request a room change. It displays the student's current room number and prompts for a new room number. If the new room number is different from the current one, it updates the room number and displays a success message.

roomCancel(): This function allows the logged-in student to cancel their room. It prompts for confirmation and sets the room number to 0 if confirmed.

viewStud(): This function displays a list of all students and their information, including user ID, name, email ID, phone number, room number, and fees.

newStud(): This function allows the addition of a new student to the system. It prompts for the student's details such as user ID, password, name, email ID, phone number, room number, and fees. It performs basic validation and adds the student to the students array if there is space available.

The main() function creates an instance of the HostelManagementSystem class and calls its start() function to begin the execution of the program.
