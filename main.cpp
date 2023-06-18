#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int userId;
    int password;
    string name;
    string emailId;
    float phoneNo;
    int fees;
    int roomNo;
};

class HostelManagementSystem
{
private:
    Student students[100];
    int numStudents;
    int loggedInUserId;

public:
    HostelManagementSystem()
    {
        numStudents = 5;
        loggedInUserId = -1;

        for (int i = 0; i < numStudents; i++)
        {
            students[i].userId = i + 1;
            students[i].password = 1 + i;
            students[i].name = "Student " + to_string(i + 1);
            students[i].emailId = "student" + to_string(i + 1) + "@gsfc.com";
            students[i].phoneNo = 92;
            students[i].fees = 5500 + (i * 120);
            students[i].roomNo = 101 + i;
        }
    }

    void start()
    {
        int choice;
        do
        {
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t***Welcome to Hostel Management System*** ";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\t\t MAIN MENU";
            cout << "\n\n";
            cout << "\n \t\t\t\t 1>> ABOUT US";
            cout << "\n \t\t\t\t 2>> Login into existing Account";
            cout << "\n \t\t\t\t 3>> View all students";
            cout << "\n \t\t\t\t 4>> Apply For Admission";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n \t\t\t\t Enter a login option(0 to exit program): ";
            cin >> choice;
            cout << "\n\n";

            switch (choice)
            {
            case 1:
                aboutUs();
                break;
            case 2:
                loginAcc();
                break;
            case 3:
                viewStud();
                break;
            case 4:
                newStud();
                break;
            default:
                cout << "\n\t\t\t\t __________________________________________________\n";
                cout << "\n\t\t\t\t***Thank You For Using Hostel Management System.***";
                cout << "\n\t\t\t\t __________________________________________________\n\n";
                break;
            }
        } while (choice != 0);
    }

private:
    void aboutUs()
    {
        int choice;
        cout << "\n________________________________________________________________________________________________________________________________________________________________________________";
        cout << "\n\nXYZ University offers comfortable and convenient residence for all students. The residential complex provides accommodation on sharing basis and ensures safety and well-being for all students. The complex is designed to give the residents a sense of home and living in a big family. There are ample spaces in the complex for students to relax, interact and study.";
        cout << "\n________________________________________________________________________________________________________________________________________________________________________________";
        cout << "\n\nHostel Facilities\n";
        cout << "\n-->Each room has attached washrooms, Study table, chair and bed for each student";
        cout << "\n-->Secure Wi-Fi internet connectivity";
        cout << "\n-->The hostel rooms are spacious with natural light and ventilation. ";
        cout << "\n-->Common Rooms for student interaction and group discussions";
        cout << "\n-->24/7 Library facility";
        cout << "\n-->Security / Warden";
        cout << "\n-->Gymnasium";
        cout << "\n-->Guest Room for Parents";
        cout << "\n-->Laundry and Housekeeping";
        cout << "\n-->Cafeteria";
        cout << "\n-->Indoor Sports Facilities";
        cout << "\n-->Medical Facility";
        cout << "\n-->Emergency Helpline";
        cout << "\n-->Solar Water Heating Facility";
        cout << "\n________________________________________________________________________________________________________________________________________________________________________________";
        cout << "\n\n Press 1 to go back to Home Page:";
        cin >> choice;
        if (choice == 1)
        {
            return;
        }
        else
        {
            return;
        }
    }

    void loginAcc()
    {
        int id, pass;
        cout << "\n\n\t\t\t\t_________________________________________";
        cout << "\n\n\t\t\t\t\t***Welcome to Login Page*** ";
        cout << "\n\t\t\t\t_________________________________________";
        cout << "\n\n\t\t\t\t\tEnter User ID: ";
        cin >> id;
        cout << "\n\t\t\t\t\tEnter Password: ";
        cin >> pass;

        int i;
        for (i = 0; i < numStudents; i++)
        {
            if (students[i].userId == id && students[i].password == pass)
            {
                loggedInUserId = i;
                loggedInAcc();
                break;
            }
        }

        if (i == numStudents)
        {
            cout << "\n\t\t\t\t\tInvalid User ID or Password!";
        }
    }

    void loggedInAcc()
    {
        int choice;
        do
        {
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\t***Welcome to Student Dashboard*** ";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\t\t MENU";
            cout << "\n\n";
            cout << "\n \t\t\t\t 1>> Pay Fees";
            cout << "\n \t\t\t\t 2>> View Profile";
            cout << "\n \t\t\t\t 3>> Room Change";
            cout << "\n \t\t\t\t 4>> Room Cancellation";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n \t\t\t\t Enter an option(0 to Logout): ";
            cin >> choice;
            cout << "\n\n";

            switch (choice)
            {
            case 1:
                payFees();
                break;
            case 2:
                viewProfile();
                break;
            case 3:
                roomChange();
                break;
            case 4:
                roomCancel();
                break;
            default:
                cout << "\n\t\t\t\t __________________________________________________\n";
                cout << "\n\t\t\t\t***Logged Out Successfully.***";
                cout << "\n\t\t\t\t __________________________________________________\n\n";
                return;
            }
        } while (choice != 10);

        loggedInUserId = -1; // Reset the logged-in user ID
    }

    void payFees()
    {
        if (loggedInUserId != -1)
        {
            int i = loggedInUserId;
            cout << "\n\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t***Pay Fees*** ";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\tName: " << students[i].name;
            cout << "\n\n\t\t\t\t\tYour Fees is: " << students[i].fees;
            cout << "\n\n\t\t\t\t\tEnter Amount to Pay: ";
            int amount;
            cin >> amount;

            if (amount >= students[i].fees)
            {
                cout << "\n\n\t\t\t\t\tPayment Successful!";
                students[i].fees = 0;
            }
            else
            {
                cout << "\n\n\t\t\t\t\tInsufficient Amount!";
            }
        }
        cout << "\n\n Press 1 to go back to Student Dashboard:";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            loggedInAcc();
        }
        else
        {
            return;
        }
    }

    void viewProfile()
    {
        if (loggedInUserId != -1)
        {
            int i = loggedInUserId;
            cout << "\n\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t***View Profile*** ";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\tName: " << students[i].name;
            cout << "\n\n\t\t\t\t\tUser ID: " << students[i].userId;
            cout << "\n\n\t\t\t\t\tEmail ID: " << students[i].emailId;
            cout << "\n\n\t\t\t\t\tPhone No: " << students[i].phoneNo;
            cout << "\n\n\t\t\t\t\tRoom No: " << students[i].roomNo;
            cout << "\n\n\t\t\t\t\tFees: " << students[i].fees;
        }
        cout << "\n\n Press 1 to go back to Student Dashboard:";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            loggedInAcc();
        }
        else
        {
            return;
        }
    }

    void roomChange()
    {
        if (loggedInUserId != -1)
        {
            int i = loggedInUserId;
            cout << "\n\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t***Room Change*** ";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\tName: " << students[i].name;
            cout << "\n\n\t\t\t\t\tCurrent Room No: " << students[i].roomNo;
            cout << "\n\n\t\t\t\t\tEnter New Room No: ";
            int newRoom;
            cin >> newRoom;

            if (newRoom != students[i].roomNo)
            {
                students[i].roomNo = newRoom;
                cout << "\n\n\t\t\t\t\tRoom Changed Successfully!";
            }
            else
            {
                cout << "\n\n\t\t\t\t\tYou are already in this room!";
            }
        }
        cout << "\n\n Press 1 to go back to Student Dashboard:";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            loggedInAcc();
        }
        else
        {
            return;
        }
    }

    void roomCancel()
    {
        if (loggedInUserId != -1)
        {
            int i = loggedInUserId;
            cout << "\n\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t***Room Cancellation*** ";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\tName: " << students[i].name;
            cout << "\n\n\t\t\t\t\tRoom No: " << students[i].roomNo;
            cout << "\n\n\t\t\t\t\tAre you sure you want to cancel your room? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice == 'Y' || choice == 'y')
            {
                students[i].roomNo = 0;
                cout << "\n\n\t\t\t\t\tRoom Cancelled Successfully!";
            }
        }
        cout << "\n\n Press 1 to go back to Student Dashboard:";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            loggedInAcc();
        }
        else
        {
            return;
        }
    }

    void viewStud()
    {
        cout << "\n\n\t\t\t\t_________________________________________";
        cout << "\n\n\t\t\t\t***List of All Students*** ";
        cout << "\n\t\t\t\t_________________________________________";
        cout << "\n\n\t\t\t\t\tTotal Number of Students: " << numStudents << "\n";

        for (int i = 0; i < numStudents; i++)
        {
            cout << "\n\n\t\t\t\t\tStudent ID: " << students[i].userId;
            cout << "\n\t\t\t\t\tName: " << students[i].name;
            cout << "\n\t\t\t\t\tEmail ID: " << students[i].emailId;
            cout << "\n\t\t\t\t\tPhone No: " << students[i].phoneNo;
            cout << "\n\t\t\t\t\tRoom No: " << students[i].roomNo;
            cout << "\n\t\t\t\t\tFees: " << students[i].fees << "\n";
        }
        cout << "\n\n Press 1 to go back to Home Page:";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            return;
        }
        else
        {
            return;
        }
    }

    void newStud()
    {
        if (numStudents < 100)
        {
            Student newStudent;

            cout << "\n\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t***New Student Admission*** ";
            cout << "\n\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\tEnter User ID: ";
            cin >> newStudent.userId;

            // Check if the user ID already exists
            for (int i = 0; i < numStudents; i++)
            {
                if (students[i].userId == newStudent.userId)
                {
                    cout << "\n\n\t\t\t\t\tUser ID already exists!";
                    return;
                }
            }

            cout << "\n\n\t\t\t\t\tEnter Password: ";
            cin >> newStudent.password;
            cout << "\n\n\t\t\t\t\tEnter Name: ";
            cin.ignore();
            getline(cin, newStudent.name);
            cout << "\n\n\t\t\t\t\tEnter Email ID: ";
            cin.ignore();
            getline(cin, newStudent.emailId);
            cout << "\n\n\t\t\t\t\tEnter Phone No: ";
            cin >> newStudent.phoneNo;
            cout << "\n\n\t\t\t\t\tEnter Room No: ";
            cin >> newStudent.roomNo;
            cout << "\n\n\t\t\t\t\tEnter Fees: ";
            cin >> newStudent.fees;

            students[numStudents] = newStudent;
            numStudents++;

            cout << "\n\n\t\t\t\t\tAdmission Successful!";
        }
        else
        {
            cout << "\n\n\t\t\t\t\tMaximum limit of students reached!";
        }
        cout << "\n\n Press 1 to go back to Home Page:";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            return;
        }
        else
        {
            return;
        }
    }
};

int main()
{
    HostelManagementSystem hms;
    hms.start();

    return 0;
}
