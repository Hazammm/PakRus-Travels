#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;
void menu();
class ManageMenu
{
protected:
    string userName; // Stores the admin's username.
    int pass;        // Stores the admin's password.
public:
    // Constructor that initializes the management menu and verifies the admin.
    ManageMenu()
    {
        // system("color 0A"); // Changes the terminal color to green text on black background.
        cout << "Enter Admin Name: ";
        cin >> userName; // Takes the admin's username as input.
        cout << "Enter Admin Password: ";
        cin >> pass; // Takes the admin's password as input.
        // Verifies the admin's credentials. If correct, clears the screen and calls `menu()`.
        if ((userName == "hazam" || userName == "shahbaz" || userName == "waleed" || userName == "husnain"  ) && (pass == 1234))
        {
            system("cls"); // Clears the terminal screen.
            menu();        // Calls the main menu function.
        }
        else
        {
            cout << "Admin Not Verified" << endl;
            // Displays an error message if credentials are incorrect.
            return; // Returns from the constructor without calling `menu()`.
        }
    }
    ~ManageMenu() {} // Destructor (currently does nothing but can be used for cleanup).
};
class Customer
{
public:
    string name, gender, address; // Variables to store customer's details.
    int age, menuBack;            // Variables to store customer's age and a menu navigation option.
    float mobileNo;               // Variable to store customer's mobile number.
    static int cusID;             // Static variable to store the customer ID, shared across all instances. By default the value of static variables is 0. Static members are alive till the termination of the program.
    char all[999];                // Character array used to read and display customer details from file.
    // Function to get and save customer details.
    void getDetails()
    {
        cout << "\nEnter Customer ID: ";
        cin >> cusID; // Takes the customer ID as input.
        cout << "Enter Name: ";
        cin >> name; // Takes the customer's name as input.
        cout << "Enter Age: ";
        cin >> age; // Takes the customer's age as input.
        cout << "Enter Mobile Number: ";
        cin >> mobileNo; // Takes the customer's mobile number as input.
        cout << "Address: ";
        cin >> address; // Takes the customer's address as input.
        cout << "Gender: ";
        cin >> gender; // Takes the customer's gender as input.
        // creating object of name "out" and utilizing it to
        //  Opens a file in append mode to store customer details.
        ofstream out("old-customers.txt", ios::app);
        // save the customer details to the file.
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age
            << "\nMobile Number: " << mobileNo << "\nAddress: " << address
            << "\nGender: " << gender << endl;
        out << "--------------------------------------------------------" << endl;
        out.close(); // Closes the file.
        cout << "Saved" << endl
             << "We save your details record for future purposes." << endl
             << endl;
    }
    // Function to display customer details by reading from the file.
    void showDetails()
    {
        ifstream in("old-customers.txt"); // Opens the file in read mode.
        {
            if (!in)
            { // Checks if the file could not be opened.
                cout << "File Error!" << endl;
            }
            // Reads and displays each line from the file until the end of the file is reached.
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close(); // Closes the file.
        }
    }
};
int Customer::cusID; //
class Cabs
{
public:
    int cabChoice;            // Variable to store the user's choice of cab.
    int kilometers;           // Variable to store the distance to be traveled.
    float cabCost;            // Variable to store the calculated cost of the cab ride.
    static float lastCabCost; // Static variable to store the cost of the last hired cab.

    // Function to display cab details and calculate cost based on user's choice.
    void cabDetails()
    {
        cout << "We collaborated with fastest, safest, and smartest cab service around the country" << endl;
        cout << "-----------Rus Cabs-----------\n"
             << endl;
        cout << "1. Rent a Standard Cab - Rs.25 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.35 per 1KM" << endl;

        cout << "\nEnter another key to back or," << endl;
        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice; // Takes the user's choice of cab.
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers; // Takes the distance to be traveled as input.

        int hireCab; // Variable to store the user's decision to hire the cab.

        // Calculates the cost based on the user's cab choice and distance traveled.
        if (cabChoice == 1)
        {
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab; // Takes the user's input to either hire or select another cab.
            system("CLS");  // Clears the screen.

            if (hireCab == 1)
            {
                lastCabCost = cabCost; // Stores the cost of the hired cab.
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails(); // Recalls the cab details function to allow the user to select another cab.
            }
            else
            {
                // Displays an error message and recalls the function after a delay if input is invalid.
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);   // Pauses execution for 1.1 seconds.
                system("CLS"); // Clears the screen.
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometers * 35;
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab; // Takes the user's input to either hire or select another cab.
            system("CLS");  // Clears the screen.

            if (hireCab == 1)
            {
                lastCabCost = cabCost; // Stores the cost of the hired cab.
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails(); // Recalls the cab details function to allow the user to select another cab.
            }
            else
            {
                // Displays an error message and recalls the function after a delay if input is invalid.
                cout << "Invalid Input! Redirecting to Previous Menu.Please Wait!" << endl;
                Sleep(1100);   // Pauses execution for 1.1 seconds.
                system("CLS"); // Clears the screen.
                cabDetails();
            }
        }
        else
        {
            // Handles invalid cab choice and redirects to the menu.
            cout << "Invalid Input! Redirecting to Previous Menu .Please Wait!" << endl;
            Sleep(1100);   // Pauses execution for 1.1 seconds.
            system("CLS"); // Clears the screen.
            menu();        // Redirects to the main menu.
        }
        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab; // Takes input for returning to the main menu.
        system("CLS");  // Clears the screen.
        if (hireCab == 1)
        {
            menu(); // Redirects to the main menu.
        }
        else
        {
            menu(); // Redirects to the main menu.
        }
    }
};
float Cabs::lastCabCost;
class Booking
{
public:
    int choiceHotel;        // Variable to store the user's hotel choice.
    int packChoice1;        // Variable to store the user's package choice within a hotel.
    int gotoMenu;           // Variable to store the user's decision to return to the menu.
    static float hotelCost; // Static variable to store the cost of the booked hotel.
    // Function to display hotel options and book a package based on user's choice.
    void hotels()
    {
        string hotelNo[] = {"Rosche", "Yayu", "Eleven"}; // Array of hotel names.
        for (int a = 0; a < 3; a++)
        {
            // Displays available hotels with their corresponding numbers.
            cout << (a + 1) << ". Hotel " << hotelNo[a] << endl;
        }
        cout << "\nCurrently we collaborated with above hotels!" << endl;

        cout << "Press any key to back or\nEnter the number of the hotel you want to book: ";
        cin >> choiceHotel; // Takes the user's hotel choice as input.
        system("CLS");      // Clears the screen.

        if (choiceHotel == 1)
        {
            cout << "-------WELCOME TO HOTEL ROSCHE-------\n"
                 << endl;
            cout << "The Garden, food, and beverage. Enjoy all you can drink, stay cool, and get chilled in the summer sun." << endl;
            cout << "Packages offered by Rosche:\n"
                 << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Rosche: Rs.15000.00" << endl;
            cout << "\nPress another key to back or\nEnter package number you want to book: ";
            cin >> packChoice1; // Takes the user's package choice as input.

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00; // Sets the cost for the Standard Pack.
                cout << "\nYou have successfully booked Standard Pack at Rosche" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00; // Sets the cost for the Premium Pack.
                cout << "\nYou have successfully booked Premium Pack at Rosche" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 15000.00; // Sets the cost for the Luxury Pack.
                cout << "\nYou have successfully booked Luxury Pack at Rosche" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                // Displays an error message and recalls the function after a delay if input is invalid.
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);   // Pauses execution for 1.1 seconds.
                system("CLS"); // Clears the screen.
                hotels();      // Recalls the hotels function.
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu; // Takes input for returning to the main menu.
            system("CLS");   // Clears the screen.
            if (gotoMenu == 1)
            {
                menu(); // Redirects to the main menu.
            }
            else
            {
                menu(); // Redirects to the main menu.
            }
        }
        else if (choiceHotel == 2)
        {
            cout << "-------WELCOME TO HOTEL YAYU-------\n"
                 << endl;
            cout << "The Garden, food, and beverage. Enjoy all you can drink, stay cool, and get chilled in the summer sun." << endl;
            cout << "Packages offered by Yayu:\n"
                 << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.6000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.11000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Yayu: Rs.16000.00" << endl;

            cout << "\nPress another key to back or\nEnter package number you want to book: ";
            cin >> packChoice1; // Takes the user's package choice as input.

            if (packChoice1 == 1)
            {
                hotelCost = 6000.00; // Sets the cost for the Standard Pack.
                cout << "\nYou have successfully booked Standard Pack at Yayu" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 11000.00; // Sets the cost for the Premium Pack.
                cout << "\nYou have successfully booked Premium Pack at Yayu" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 16000.00; // Sets the cost for the Luxury Pack.
                cout << "\nYou have successfully booked Luxury Pack at Yayu" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                // Displays an error message and recalls the function after a delay if input is invalid.
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);   // Pauses execution for 1.1 seconds.
                system("CLS"); // Clears the screen.
                hotels();      // Recalls the hotels function.
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu; // Takes input for returning to the main menu.
            system("CLS");   // Clears the screen.
            if (gotoMenu == 1)
            {
                menu(); // Redirects to the main menu.
            }
            else
            {
                menu(); // Redirects to the main menu.
            }
        }
        else if (choiceHotel == 3)
        {
            cout << "-------WELCOME TO HOTEL ELEVEN-------\n"
                 << endl;
            cout << "The Garden, food, and beverage. Enjoy all you can drink, stay cool, and get chilled in the summer sun." << endl;
            cout << "Packages offered by Eleven:\n"
                 << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.7000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.12000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Eleven: Rs.17000.00" << endl;

            cout << "\nPress another key to back or\nEnter package number you want to book: ";
            cin >> packChoice1; // Takes the user's package choice as input.

            if (packChoice1 == 1)
            {
                hotelCost = 7000.00; // Sets the cost for the Standard Pack.
                cout << "\nYou have successfully booked Standard Pack at Eleven" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 12000.00; // Sets the cost for the Premium Pack.
                cout << "\nYou have successfully booked Premium Pack at Eleven" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 17000.00; // Sets the cost for the Luxury Pack.
                cout << "\nYou have successfully booked Luxury Pack at Eleven" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                // Displays an error message and recalls the function after a delay if input is invalid.
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);   // Pauses execution for 1.1 seconds.
                system("CLS"); // Clears the screen.
                hotels();      // Recalls the hotels function.
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu; // Takes input for returning to the main menu.
            system("CLS");   // Clears the screen.
            if (gotoMenu == 1)
            {
                menu(); // Redirects to the main menu.
            }
            else
            {
                menu(); // Redirects to the main menu.
            }
        }
        else
        {
            // Handles invalid hotel choice and redirects to the menu.
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);   // Pauses execution for 1.1 seconds.
            system("CLS"); // Clears the screen.
            menu();        // Redirects to the main menu.
        }
    }
};

float Booking::hotelCost;
class Chargers : public Booking, Cabs, Customer
{
public:
    void printBill()
    {
        // Function to print the bill/receipt.
        ofstream outf("receipt.txt"); // Opens a file to save the receipt details.
        {
            outf << "--------PakRus Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;
            outf << "Customer ID: " << Customer::cusID << endl;
            outf << "\nDescription\t Total" << endl;
            outf << "Hotel cost:\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << endl;
            outf << "_________________________________" << endl;
            outf << "------------Thank You------------" << endl;
        }
        outf.close(); // Closes the file after writing the receipt.
        cout << "Your receipt has been printed. You can get it from the file saved as 'receipt.txt'." << endl;
    }
    void showBill()
    {                                // Function to display the bill.
        ifstream inf("receipt.txt"); // Opens the file containing the receipt details.
        if (!inf)
        {
            cout << "File opening error!" << endl; // Displays an error message if the file couldn't be opened.
        }
        while (!(inf.eof()))
        {                          // Reads until the end of the file.
            inf.getline(all, 999); // Reads a line from the file into the `all` array.
            cout << all << endl;   // Displays the line read from the file.
        }
        inf.close(); // Closes the file after reading the receipt details.
    }
};
void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * PakRus Travels *\n"
         << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;

    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2;
    Cabs a3;
    Booking a4;
    Chargers a5;

    if (mainChoice == 1)
    {
        cout << "------Customers------\n"
             << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1)
        {
            a2.getDetails();
        }
        else if (inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();
    }
    else if (mainChoice == 3)
    {
        cout << "--> Book a Luxury Hotel using the System <--\n"
             << endl;
        a4.hotels();
    }
    else if (mainChoice == 4)
    {
        cout << "-->Get your receipt<--\n"
             << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n"
             << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5)
    {
        cout << endl
             << "--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to Previous Menu. Please Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}
int main()
{
    ManageMenu startObj;
    return 0;
}
