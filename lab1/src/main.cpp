#include <iostream>
#include "../inc/scripts/DoublyLinkedList.h"
#include "TestRunner.h"

TestRunner testrunner;

void printTask() 
{
    std::cout << "\n=== TASK DESCRIPTION ===\n";
    std::cout << "It is required to process a sequence of natural numbers.\n\n";
    std::cout << "Data structure:\n";
    std::cout << "- Doubly linked cyclic list\n";
    std::cout << "- With a dummy element\n\n";
    std::cout << "Processing rules:\n";
    std::cout << "1. If there are at least 3 numbers in the sequence\n";
    std::cout << "   ending with the digit 2 or 4:\n";
    std::cout << "    Sort the sequence in descending order of the first digit\n\n";
    std::cout << "2. Otherwise:\n";
    std::cout << "    Remove prime numbers from the sequence\n";
    std::cout << "    Duplicate numbers that are multiples of 10\n";
    std::cout << "========================\n\n";
}
void DoingProgramm()
{
DoublyLinkedList list;
    int n, number;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter a sequence of natural numbers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> number;
        list.insert(number);
    }

    std::cout << "Original list: ";
    list.print();

    list.processSequence();

    std::cout << "Modified list: ";
    list.print();
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
