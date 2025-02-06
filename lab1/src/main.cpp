#include <iostream>
#include "../inc/Containers/CircularDoublyLinkedList.h"
//#include "../inc/Tests/Logical/Test1.h"
//#include "../inc/Tests/Functional/Test2.h"
//#include "../inc/Tests/Functional/TestAddNode.h"
//Я как пользователь должен быть максимально проинформирован.
// Т.е выводим в консоль условия заданий. Описываем что от меня требуется ввести.
// Если ввел что-то не так описываем что не так и просим ввести заново.


// 1. выводим в консоль условия всех пунктов.
// 2. Ждем от пользователя интересующий его пункт.
// 3. Предлагаем пользователю режим. 1) Прогнать тесты. 2) Выполнить работу.
// Если выбраны тесты то спрашиваем какие запустить все/логические/функциональные
// Если выполнить работу то описываем то что пользователь должен ввести и ожидаем от него ввода.
// Если программа продразумевает работу с файлом. То мы ожидаем путь до файла или ничего(enter).
// Если нажат enter то файл берется по умалчанию из base.
// Файл ВАЛИДИРУЕМ!!!


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
CircularDoublyLinkedList list;
    int n, number;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter a sequence of natural numbers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> number;
        list.append(number);
    }

    std::cout << "Original list: ";
    list.display();

    if (list.countEndingWith2Or4() >= 3) {
        std::cout << "There are at least 3 numbers ending with 2 or 4. Sorting by the first digit in descending order." << std::endl;
        list.sortByFirstDigitDescending();
    }
    else {
        std::cout << "There are fewer than 3 numbers ending with 2 or 4. Removing primes and duplicating multiples of 10." << std::endl;
        list.removePrimesAndDuplicateMultiplesOf10();
    }

    std::cout << "Modified list: ";
    list.display();
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
        std::cout << "0. Back\n";
        std::cout << "Your choice: ";
        std::cin >> type;  
    }
    if (CurrentInputTests(type))
    {
        if (type == 1)
        {
           
        }
        if (type == 2)
        {
            
        }   
        if (type == 3)
        {
            
        }  
        if (type == 0)
        {
            
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
