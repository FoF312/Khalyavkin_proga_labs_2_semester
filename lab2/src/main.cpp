#include "tests/TestRunner.h"
#include <iostream>
TestRunner testrunner;

void printTask() 
{
    std::cout << "=== Assignment ===" << std::endl;
    std::cout << "1. Given a string consisting of English letters, no more than 100 characters, calculate its length using recursion. Do not use the length() method or the strlen() function." << std::endl;
    std::cout << "2. Implement QuickSort. Study how it works. Compare its speed with Bubble Sort." << std::endl;
    std::cout << "3. You are given a field of size NxM (2 <= N, M <= 100). Each cell of the field contains characters:" << std::endl;
    std::cout << "   '.' - passable;" << std::endl;
    std::cout << "   '#' - impassable;" << std::endl;
    std::cout << "   'S' - starting cell;" << std::endl;
    std::cout << "   'E' - ending cell;" << std::endl;
    std::cout << "   Write an algorithm to determine the minimum number of steps to move from the starting cell to the ending cell. If it is impossible, output -1. You can move to all neighboring cells marked with '.' (including diagonally)." << std::endl;
    std::cout << "==================" << std::endl;
}
void DoingProgramm()
{

}
bool CurrentInput(int choice)
{
   if (choice == 1)
   {
    return true;
   }
   if (choice == 2)
   {
    return true;
   }
   if (choice != 1 || choice != 2)
   {
        std::cout << "\n INPUT ERROR\n";
        std::cout << "\n Select an operating mode:\n";
        std::cout << "1. Run tests\n";
        std::cout << "2. Run Program\n";
        std::cout << "Your choice: ";
        return false;
   }
   return false;
}
bool CurrentInputTests(int type)
{
    if (type == 1 || type == 2 || type == 3 || type == 0)
    {
        return true;
    }   
    else
    {
        return false;
    }     
    return false;
}
void TestMenu() 
{
    std::cout << "\n Select the type of tests:\n";
    std::cout << "1. All tests\n";
    std::cout << "2. Logic tests\n";
    std::cout << "3. Functional tests\n";
    std::cout << "0. Back\n";
    std::cout << "Your choice: ";
    int type;
    std::cin >> type;
    while (CurrentInputTests(type) == false)
    {
        std::cout << "\nERROR INPUT\n";
        std::cout << "\n Select the type of tests:\n";
        std::cout << "1. All tests\n";
        std::cout << "2. Logic tests\n";
        std::cout << "3. Functional tests\n";
        std::cout << "Your choice: ";
        std::cin >> type;  
    }
    if (CurrentInputTests(type))
    {
        if (type == 1)
        {
            testrunner.runAllTests();
        }
        if (type == 2)
        {
              testrunner.runLogicalTests(); 
        }   
        if (type == 3)
        {
            testrunner.runFunctionalTests();
        }           
    }             
}
void Menu() 
{
    std::cout << "\n Select an operating mode:\n";
    std::cout << "1. Run tests\n";
    std::cout << "2. Run Program\n";
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice; 
    while (CurrentInput(choice) == false)
    {
      std::cin >> choice;  
    }
    if (CurrentInput(choice))
    {
        if (choice == 1)
        {
            TestMenu();
        }
        if (choice == 2)
        {
            DoingProgramm();
        }              
    }                
}
int main()
{
    printTask();
    Menu();
    return 0;
}
