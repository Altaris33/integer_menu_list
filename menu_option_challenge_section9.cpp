#include <iostream>
#include <vector>

using namespace std;

/*
* This program is about using a List of integers and displaying them to the user

The program will display a menu to allow the user to select options from it to perform operations from the list : 
- P - print numbers
- A - add numbers  
- M - print the mean of the numbers
- S - print the smallest number from the list
- L - print the largest number from the list  
- Q - quit the menu and app  

Enter your choice :  

The program should only accept valid choices from the user. Both uppercase and lowercase 
characters should be allowed.  

If an illegal option is used, the program should display the following error message :  
"Unknonwn option, please try again". and the menu option should be displayed again.  

If the user choose P or p, we should display all elements from the list.  
If the list is empty, we should display : "[] : The list is empty".  

If the user enters A or a, we prompt the user for an new integer to add to the list.
We should then display the newly added number : for example : "5 added".  
Duplicate list entries are OK

If the user choose M or m, we calculate the mean of the list and display it. If the list
is empty, we print "Unable to calculate mean, no data in the list".  

If the user enters S or s, we find and print the smallest element and display it.  
If the list is empty print : "Unable to determine smallest number, no data".  

If the user enters L or l, we find and print the largest number and display it.  
If the list is empty print : "Unable to determine largest number, no data".  

If the user enters Q or q, we quit and print "Goodbye.".  
*
*/

int main() {

    cout << "Welcome to the number list program " << endl;

    char option {};
    
    cout << "Menu" << endl;
    cout << "\t- P - print numbers" << endl;
    cout << "\t- A - add numbers" << endl;
    cout << "\t- M - print the mean of the numbers" << endl;
    cout << "\t- S - print the smallest number from the list" << endl;
    cout << "\t- L - print the largest number from the list"  << endl; 
    cout << "\t- Q - quit the menu and app" << endl;
    cout << "Enter your choice : " << endl; 

    // TODO : improve this part by dynamically creating the vector, using only user input
    //  write unit tests to test each algorithm individually  
    vector<int> numbers = {5, 8, 3, 2, 5, 9};

    bool menu_condition = true;

    while (menu_condition)
    {
        cout << "Menu" << endl;
        cout << "\t- P - print numbers" << endl;
        cout << "\t- A - add numbers" << endl;
        cout << "\t- M - print the mean of the numbers" << endl;
        cout << "\t- S - print the smallest number from the list" << endl;
        cout << "\t- L - print the largest number from the list"  << endl; 
        cout << "\t- Q - quit the menu and app" << endl;
        cout << "Enter your choice : " << endl; 
        cin >> option;

        switch (option)
        {
        case 'P':
        case 'p':
            // print out numbers  
            if (numbers.empty()) 
            {
                cout << "[] list is empty. No data to display." << endl;
            }
            else {
                for (int i = 0; i < numbers.size(); i++)
                {
                    cout << numbers[i] << " ";
                }
            }
            cout << endl;
            break;
        case 'A':
        case 'a': 
        {
            // ask user a number to add to the list
            string number_to_add {};
            cout << "Enter the number to add : ";
            cin >> number_to_add;

            // check if a number is passed 
            for (int i = 0; i < number_to_add.length(); i++)
            {
                // don't work for inputs such as 4a5, 44t, etc... but good enough for the exercise 
                if (isdigit(number_to_add[i]))
                {
                    int convertedNumberInInt = stoi(number_to_add);
                    numbers.push_back(convertedNumberInInt);
                    cout << convertedNumberInInt << " added" << endl;
                    break;
                }
                cout << "Number is not an integer. Aborting." << endl;
                break;
            }
            break;
        }
        case 'M':
        case 'm':
        {
            if (numbers.empty()) 
            {
                 cout << "Unable to calculate mean, no data in the list" << endl;
                 break;
            }

            // calculate average/mean 
            int sumOfAllNumbers {};
            float mean {};
            for (int i = 0; i < numbers.size(); i++)
            {
                sumOfAllNumbers = sumOfAllNumbers + numbers[i];
            }
            
            mean = (float) sumOfAllNumbers / numbers.size();
            
            cout << "Mean is : " << mean << endl;
            break;
        }
        case 'S':
        case 's':
        {
            // get smallest value from the vector
            int proxyNumber {};
            for (int i = 0; i < numbers.size() - 1; i++)
            {
                if (numbers[i] <= numbers[i + 1])
                {
                    proxyNumber = numbers[i];  
                    numbers[i] = numbers[i+1];
                    numbers[i+1] = proxyNumber;
                } 
                else 
                {
                    proxyNumber = numbers[i+1];
                }
            }
            cout << "Smallest number :" << proxyNumber << endl;
            break;
        }
        case 'L':
        case 'l':
        {
            // get highest value from the vector
            int proxyNumber {};
            int smallestNumber {};
            for (int i = 0; i < numbers.size() - 1; i++)
            {
                if (numbers[i] > numbers[i + 1])
                {
                    proxyNumber = numbers[i];  
                    numbers[i] = numbers[i+1];
                    numbers[i+1] = proxyNumber;
                } 
                else 
                {
                    proxyNumber = numbers[i+1];
                }
            }
            cout << "Highest number :" << proxyNumber << endl;
            break;
        }
        case 'Q':
        case 'q':
            cout << "goodbye" << endl;
            menu_condition = false;
            break;    
        default:
            cout << "Default option selected, exitting program." << endl; 
            menu_condition = false;
            break;
        }
    }
   
    return 0;
}