#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Project name: Attendance Management System.

/*
    - The Attendance Management system takes the attendance of each member/admin in the organization.
    - Each user/admin will have an organized table of where their records will be displayed.
    - If the User/Admin is new it creates an account for them.
    - After creating their account it will update their attendance count to 1. 
    - If the User is an existing memeber it calls the necessary function and updates the attendance count of the user.
    - If the Admin is an existing memeber it calls the necessary function, and gives privilege to do/perform certain tasks.
    - The code in total has 2 structs, 1 enum and 11 functions(including main).
*/

//Structure for regular Employees.
struct Employee
{
    string name;
    int Id;
    char StayingHours;
    float attendance;
};

//Structure for Admins.
struct admins
{
    string Name;
    int ID;
    string password;
    string HidePassword;
    char Stayinghours;
    float attendances;
};

enum ChoiceType
{
    a = 1, b,c
};

//Displays welcome message and informs the users to follow instructions as displayed in the console.
void Welcome()
{
    cout << "Welcome to the Attendance Management System" << endl;

    cout << "Please follow the instructions" << endl;
}

//Creating a membership.
Employee* CreateMember(int counter)
{
    Employee* membership = new Employee[300];
    float attendance = 0; 
    
    for(int i = 0; i < counter; i++)
    {
        cout << "Enter name: ";
        cin >> membership[i].name;

        cout << "Enter 3-digit Id: ";
        cin >> membership[i].Id;

        cout << "Full-day[F] or Half-day[H]: ";
        cin >> membership[i].StayingHours;

        if(membership[i].StayingHours == 'F' || membership[i].StayingHours == 'f')
        {
            membership[i].attendance = attendance + 1;
           
        }else if(membership[i].StayingHours == 'H' || membership[i].StayingHours == 'h')
        {
            membership[i].attendance = attendance + 0.5;
        }
    }                
    return membership;
}

//Saves new Member account created and Automtically increase Attendance count by 1 || for existing users it updates based on the users input.
void SaveMembership(Employee* membership, int counter)
{
    ofstream A("membershipname.txt", ios::app);
    ofstream B("membershipid.txt", ios::app);
    ofstream C("membershipattendance.txt", ios::app);

    if(A.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
            A << membership[i].name << endl;
        }
    }
    else
    cout << "Unable to open file." << endl;

    if(B.is_open())
    { 
        for(int i = 0; i < counter; i++)
        {
        B << membership[i].Id << endl;
        }
    }
    else
        cout << "Unable to open file." << endl;

    if(C.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
            C << membership[i].attendance << endl;
        }
    }
    else
    cout << "Unable to open file." << endl;

    A.close();//After writting into the file 'a' it closes it.
    B.close();//After writting into the file 'b' it closes it.
    C.close();//After writting into the file 'c' it closes it.
}

//Displays the text file of Membership if the User is an existing one.
void DisplayMembership(int &MemberCount)
{
    ifstream A("membershipname.txt", ios::in); //Opens the file 'a' for reading.
    ifstream B("membershipid.txt", ios::in);//Opens the file 'b' for reading.
    ifstream C("membershipattendance.txt", ios::in); //Opens the file 'c' for reading.
    string line1, line2, line3; //Line by line displaying to the console.
    
    MemberCount = 0;

    cout << "   Name     " << "  Id     " << "  Attendance Count" << endl;

    while (getline(A, line1) && getline(B,line2) && getline(C,line3))
     { 
      //Member Count will increase everytime New member is added.
        MemberCount++;

       cout << MemberCount << ". " << line1 << "     "  << line2 << "   \t    " << line3 << endl;  
     }

    A.close(); //Closes the file after displaying the name.
    B.close(); //Closes the file after displaying the Id.
    C.close(); //Closes the file after displaying the attendance.

}

admins* CreateAdmin(int counter)
{
    admins* Adminship = new admins[300];
    float attendances = 0;

    for(int i = 0; i < counter; i++)
    {
        cout << "Enter name: ";
        cin >> Adminship[i].Name;

        cout << "Enter 4-digit Id: ";
        cin >> Adminship[i].ID;

        cout << "Enter password: ";
        cin >> Adminship[i].password;

        Adminship[i].HidePassword = (Adminship[i].password, "***");

        cout << "Full-day[F] or Half-day[H]: ";
        cin >> Adminship[i].Stayinghours;

        if(Adminship[i].Stayinghours == 'F' || Adminship[i].Stayinghours == 'f')
        {
            Adminship[i].attendances = attendances + 1;
           
        }else if(Adminship[i].Stayinghours == 'H' || Adminship[i].Stayinghours == 'h')
        {
            Adminship[i].attendances = attendances + 0.5;
        }
    }
    return Adminship;
}

//Saves new Admin account created.
void SaveAdminship(admins* Adminship, int counter)
{
    ofstream A("adminshipname.txt", ios::app); //Saves the name of the admin.
    ofstream B("adminshipid.txt", ios::app);//Saves the id of the admin.
    ofstream C("adminshipattendance.txt", ios::app);//Saves the attendance of the admin.
    ofstream D("adminshiphidePassword.txt", ios::app); 
    ofstream E("adminshipPassword.txt", ios::app); //Save the admin's password. 

    if(A.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
        A << Adminship[i].Name << endl;
        }
    }
    else
         cout << "Unable to open file." << endl;

    if(B.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
            B << Adminship[i].ID << endl;
        }
    }
    else
        cout << "Unable to open file." << endl;

    if(C.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
            C << Adminship[i].attendances << endl;
        }
    }
    else 
        cout << "Unable to open file." << endl;
    
    if(D.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
            D << Adminship[i].HidePassword << endl;
        }
    }
    else
        cout << "Unable to open file." << endl;
    
    if(E.is_open())
    {
        for(int i = 0; i < counter; i++)
        {
            E << Adminship[i].password << endl;
        }
    }
    else
        cout << "Unable to open file." << endl;

    A.close(); //Closes the file after writting the admins name.
    B.close(); //Closes the file after writting admins id.
    C.close(); //Closes the file after writting admins attendance.
    D.close(); //Closes the file after hiding admins password with '***' into the file.
    E.close(); //Closes the file after writting admins password.
}

//Displays the text file of Membership if the Admin is an existing one.
void DisplayAdminship(int &Admincount)
{
    ifstream A("adminshipname.txt", ios::in); //Opens the adminship name text file for reading.
    ifstream B("adminshipid.txt", ios::in); //Opens the the adminship id text file for reading.
    ifstream C("adminshiphidePassword.txt", ios::in); //Opens the adminship hide password text file for reading.
    ifstream D("adminshipattendance.txt", ios::in); //Opens the adminship attendance text file for reading.
    string line1,line2,line3,line4; //Displays every line on the console.

    cout << "  Name     " << " Id  " << "  Password  " << "  Attendance  " << endl;

    while(getline(A,line1) && getline(B,line2) && getline(C,line3) && getline(D,line4))
    {
        cout << Admincount << "." << line1  << "    "  << line2 << "     " << line3 << "  \t   " << line4 << endl;

        //Increments the value of Admin count after displaying one line.
        Admincount++;
    }

    A.close(); //After reading the adminship name text file it closes it.
    B.close(); //After reading the adminship id text file it closes it.
    C.close(); //After reading the adminship passwordtext file it closes it.
    D.close(); //After reading the adminship attendance text file it closes it.
}

//Checks the username of the member and then provides ceratin tasks.
void EmployeeChecker(string user_name, int Id)
{
    ifstream file("membershipname.txt", ios::in); //Open file for reading names.
    ifstream files("membershipattendance.txt", ios::in); //Open file for reading attendance.
    ifstream filei("membershipid.txt", ios::in); //Open file for reading Id.
    
    string filesString;
    string names[300]; //Array to store names.
    int ID[300]; //Array to store Id.
    float attendance[300]; //Array to store attendance counts.

    int num = 0;
    bool nameFound = false;
    bool IdCorrect = false;

    //Read existing names and attendance counts from file into arrays.
    while (file >> filesString)
    {
        names[num] = filesString; 
        files >> filesString;
        attendance[num] = stof(filesString); //Converts string to float and store in array.
        filei >> filesString;
        ID[num] = stoi(filesString);

        num++;
    }

    //Search for user name and update attendance count based on user input for 'Full-day' or 'Half-day'.
    for (int i = 0; i < num; i++)
    {
        if (user_name == names[i])
        {
            cout << "Name found." << endl;
          if(Id == ID[i])
          {
            cout << "Id correct." << endl;

            char userChoice;

            cout << "Full-day[F] || Half-day[H]: ";
            cin >> userChoice;

            if (userChoice == 'F' || userChoice == 'f')
            {
                attendance[i] += 1; 
            }
            else if (userChoice == 'H' || userChoice == 'h')
            {
                attendance[i] += 0.5; 
            }
            else
                cout << "Error input." << endl;
            
            nameFound = true;
            IdCorrect = true;
            break;
          }
        }
    }

    //If user name is not found it displays the following message.
    if (!nameFound || !IdCorrect)
    {
        cout << "Error user name or Id." << endl;
    }
    else
    {
        //Writes attendance count back to the original file.
        ofstream attendances("membershipattendance.txt", ios::out);
        for (int i = 0; i < num; i++)
        {
            attendances << attendance[i] << endl; 
        }
        attendances.close();
    }

    file.close(); //Close the file after getting the name to check if the user exists or not.
    files.close(); //Close the file after getting the attendance count of the user if he/she exists.
}

//Checks the admin name and password to check for the account and does necessary tasks.
void AdminChecker(string admin_name, string password)
{
    ifstream file("adminshipname.txt", ios::in); //Open file for reading names.
    ifstream Password("adminshipPassword.txt", ios::app); //Save the admin's password. 
    ifstream files("adminshipattendance.txt", ios::in); //Open file for reading attendance.

    string filesString;//Variable used for the name of the admin.
    string fileString;//Variable used for the password of the admin.
  
    string names[300]; //Array to store names.
    string passwords[300]; //Array to store passwords.
    float attendance[300]; //Array to store attendance counts.

    int num = 0;
    bool nameFound = false;
    bool passwordCorrect = false;

    //Read existing names and attendance counts from file into arrays.
    while (file >> filesString && Password >> fileString)
    {
        names[num] = filesString;
        passwords[num] = fileString;

        files >> filesString;
        attendance[num] = stof(filesString); //Converts string to float and store in array.

        num++;
    }

    //Search for user name and update attendance count.
    for (int i = 0; i < num; i++)
    {
        if (admin_name == names[i])
        {
            cout << "Name found." << endl;

           if(password == passwords[i])
            {
            cout << "Password correct." << endl;

             char user_choice;

                cout << "Full-day[F] || Half-day[H]: ";
                cin >> user_choice;

            if (user_choice == 'F' || user_choice == 'f')
            {
                attendance[i] += 1; 
            }
            else if (user_choice == 'H' || user_choice == 'h')
            {
                attendance[i] += 0.5; 
            }
            else
                cout << "Error input." << endl;
            
            nameFound = true;
            passwordCorrect = true;
            break;
            }
        }
    }

    //If user name is not found it || password is not correct it displays the following message.
    if (!nameFound || !passwordCorrect)
    {
        cout << "Error user name or password." << endl;
    }
    else
    {
        //Write attendance count back to the original file.
        ofstream attendances("adminshipattendance.txt", ios::out);
        for (int i = 0; i < num; i++)
        {
            attendances << attendance[i] << endl;
        }
        attendances.close();
    }

    file.close();//Closes the file after checking whether the admin's name exists or not.
    Password.close();//Closes the file after checking the password of the admin.
    files.close();//Closes the file after updating the attendance count of the admin.
}

void DeleteUserAcc(int &Membercount)
{
    fstream filen("membershipname.txt", ios::in | ios::out);
    fstream filei("membershipid.txt", ios::in | ios::out);
    fstream filea("membershipattendance.txt", ios::in | ios::out);

    string name;

    cout << "Enter name of user account you want to delete: ";
    cin >> name;

    string Name[300];
    string Id[300];
    string attendance[300];

    string filenString, fileiString, fileaString;
    int num = 0;
    bool nameFound = false;

    while(filen >> filenString && filei >> fileiString && filea >> fileaString)
    {
        Name[num] = filenString;
        Id[num] = fileiString;
        attendance[num] = fileaString;

        num++;
    }

    //Erase user's records.
    for(int i = 0; i < num; i++)
    {
        if(name == Name[i])
        {
            nameFound = true;
            Membercount--;//Decrease the total number of records.

            for(int j = i; j < num-1; j++)
            {
                Name[j] = Name[j+1];
                Id[j] = Id[j+1];
                attendance[j] = attendance[j+1];
            }
            num--;
        }
    }

    filen.close();
    filei.close();
    filea.close();

    //Write back the updated records
    filen.open("membershipname.txt", ios::out | ios::trunc);
    filei.open("membershipid.txt", ios::out | ios::trunc);
    filea.open("membershipattendance.txt", ios::out | ios::trunc);

    for(int i = 0; i < num; i++)
    {
        filen << Name[i] << endl;
        filei << Id[i] << endl;
        filea << attendance[i] << endl;
    }

    filen.close();
    filei.close();
    filea.close();

    if(!nameFound)
    {
        cout << "Name not found." << endl;
    }
}

int main()
{   
    Welcome();

    //Variable for Employee
    Employee* membership;

    //Variable for admins
    admins* Adminship;

    //Counter initialized to 1 so that a user can create one account at a time.
     int counter = 1;

    //Counts the total number of members.
     int Membercount = 1;

    //Counts the total number of admins.
     int Admincount = 1;

    char Continue;
    int choice;

      for(int i = 0; i < 100; i++)
      {
        cout << "Would you like to carry on[Y/N]: ";
        cin >> Continue;

        if(Continue == 'Y' ||Continue == 'y')
        {
         cout << "1.Continue" << endl;
         cout << "2.Exit" << endl; 

         cout << "Enter choice: ";
         cin >> choice;

        }else if(Continue == 'N' || Continue == 'n')
        {
         return 0;
        }else 
            cout << "Error input." << endl;

    int Answer;//A variable that stores the user's choice after displaying the choices for it.

    if(choice == 1)
    {   
        cout << "\t\t" << "1.User Account" << endl;
        cout << "\t\t" << "2.Admin Account" << endl;
        cout << "\t\t" << "3.Exit" << endl;

        cout << "Enter your choice: ";
        cin >> Answer;

        switch ((ChoiceType)Answer)
        {
        case a:
            char user_choice;
            
            cout << "N for new account || E for Existing account" << endl;

            cout << "Are you New or Existing member: ";
            cin >> user_choice;

            if(user_choice == 'N' || user_choice == 'n')
            {
            membership = CreateMember(counter);
            SaveMembership(membership,counter);
            }else if(user_choice == 'E' || user_choice == 'e')
            {
                string user_name;

                cout << "Enter your user name: ";
                cin >> user_name;

                int Id;

                cout << "Enter your Id: ";
                cin >> Id; 

            ifstream file("membershipname.txt", ios::in);
            
            if(file.is_open())
            {
                EmployeeChecker(user_name, Id);
            }
            else
                cout << "Unable to open file." << endl;

            }else if(user_choice != 'N' || user_choice != 'n' || user_choice != 'E' || user_choice != 'e')
                {
                    cout << "N for new account || E for Existing account" << endl;

                    cout << "Are you New or Existing member: ";
                    cin >> user_choice;
                }
            break;
        case b:
            int adminstrator;
            char admin_choice;
            
            cout << "1.Sign in/up to admin account." << endl;
            cout << "2.Manage user account." << endl;
            cout << "3.Exit." << endl;

            cout << "Enter choice: ";
            cin >> adminstrator;

            if(adminstrator == 1)
            {
            cout << "N for new account || E for Existing account" << endl;

            cout << "Are you New or Existing admin: ";
            cin >> admin_choice;

            if(admin_choice == 'N' || admin_choice == 'n')
            {
                Adminship = CreateAdmin(counter);
                SaveAdminship(Adminship, counter);
            }else if(admin_choice == 'E' || admin_choice == 'e')
            {
                string admin_name;

                cout << "Enter your admin name: ";
                cin >> admin_name;

               string password;

               cout << "Enter your password: ";
               cin >> password;

            ifstream File("adminshipname.txt", ios::in);
            
                if(File.is_open())
                {
                  DisplayAdminship(Admincount);
                  AdminChecker(admin_name,password);
                }
                else
                     cout << "Unable to open file." << endl;

            }else if(admin_choice != 'N' || admin_choice != 'n' || admin_choice != 'E' || admin_choice != 'e')
                {
                    cout << "N for new account || E for Existing account" << endl;

                    cout << "Are you New or Existing admin: ";
                    cin >> admin_choice;
                }
            }else if(adminstrator == 2)
            {
                int user_acc;

                cout << "\t" << "1.Create user account" << endl;
                cout << "\t" << "2.Delete user account" << endl;
                cout << "\t" << "3.Display all user records" << endl;
                cout << "\t" << "4.Exit" << endl;

                cout << "Enter choice: ";
                cin >> user_acc;

                if(user_acc == 1)
                {
                    int counter;

                    cout << "How many accounts do you want to create: ";
                    cin >> counter;

                    membership = CreateMember(counter);
                    SaveMembership(membership,counter);
                }else if(user_acc == 2)
                {
                    DeleteUserAcc(Membercount);
                }else if(user_acc == 3)
                {
                    DisplayMembership(Membercount);
                }else if(user_acc == 4)
                {
                    return 0;
                }
                else
                    cout << "Error input" << endl;
            }else if(adminstrator == 4)
            {
                return 0;
            }
            else
                cout << "Error input." << endl;
            break;
        case c:
                return 0;
        }
    }else if(choice == 2)
    {
        return 0;
    }else
        cout << "Error input." << endl;
    }

    return 0;  
}