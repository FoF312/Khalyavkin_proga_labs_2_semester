#include <iostream>
#include "../inc/VectorBool/VectorBool.h"
#include "../inc/Tests/TestRunner.h"
#include "../inc/Tests/Logical/VectorBoolLogicalTests.h"
#include "../inc/Tests/Functional/VectorBoolFunctionalTests.h"

TestRunner testrunner;

void printTask() 
{
    std::cout << "\n=== TASK DESCRIPTION ===\n";
    std::cout << "Implement a template specialization for bool vector (VectorBool).\n";
    std::cout << "Each bool value should use only 1 bit of memory.\n\n";
    std::cout << "Required functionality:\n";
    std::cout << "- Method for adding elements to the end (push_back)\n";
    std::cout << "- Method and operator for getting/setting values by index\n";
    std::cout << "- Method for getting size (size)\n";
    std::cout << "- Methods for inserting and erasing elements\n";
    std::cout << "========================\n\n";
}

void DemoVectorBoolOperations() 
{
    std::cout << "\n=== VECTOR BOOL DEMONSTRATION ===\n";
    
    // Создание и вывод вектора
    MyVector<bool> vec1;
    vec1.push_back(true);
    vec1.push_back(false);
    vec1.push_back(true);
    std::cout << "Vector 1: " << vec1 << " (size: " << vec1.size() << ")\n";

    // Изменение элемента через оператор []
    vec1[1] = true;
    std::cout << "After modification: " << vec1 << "\n";

    // Вставка элемента
    vec1.insert(1, false);
    std::cout << "After insert at pos 1: " << vec1 << " (size: " << vec1.size() << ")\n";

    // Удаление элемента
    vec1.erase(2);
    std::cout << "After erase at pos 2: " << vec1 << " (size: " << vec1.size() << ")\n";

    // Проверка на выход за границы
    try {
        std::cout << "Trying to access element at index 10: ";
        bool val = vec1[10];
        std::cout << val << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    // Демонстрация эффективности памяти
    MyVector<bool> largeVec;
    for (int i = 0; i < 100; ++i) {
        largeVec.push_back(i % 3 == 0);
    }
    std::cout << "\nLarge vector (100 elements) created.\n";
    std::cout << "Size: " << largeVec.size() << "\n";
    std::cout << "Memory efficient: each bool uses 1 bit (not 1 byte)\n";
}

void ManualVectorBoolInput() 
{
    std::cout << "\n=== MANUAL VECTOR BOOL INPUT ===\n";
    MyVector<bool> vec;
    int size;
    bool value;

    std::cout << "Enter vector size: ";
    std::cin >> size;

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value (0 or 1) for position " << i << ": ";
        std::cin >> value;
        vec.push_back(value);
    }

    std::cout << "Your vector: " << vec << " (size: " << vec.size() << ")\n";

    // Демонстрация операций
    int index;
    std::cout << "\nEnter index to modify: ";
    std::cin >> index;
    if (index >= 0 && index < vec.size()) {
        std::cout << "Current value: " << vec[index] << "\n";
        std::cout << "Enter new value (0 or 1): ";
        std::cin >> value;
        vec[index] = value;
        std::cout << "Modified vector: " << vec << "\n";
    } else {
        std::cout << "Invalid index!\n";
    }
}

void DoingProgramm()
{
    int mode;
    std::cout << "\nSelect demonstration mode:\n";
    std::cout << "1. Automatic demonstration\n";
    std::cout << "2. Manual input\n";
    std::cout << "Your choice: ";
    std::cin >> mode;

    if (mode == 1) {
        DemoVectorBoolOperations();
    } 
    else if (mode == 2) {
        ManualVectorBoolInput();
    }
    else {
        std::cout << "Invalid choice!\n";
    }
}

bool CurrentInput(int choice)
{
    if (choice == 1 || choice == 2) {
        return true;
    }
    std::cout << "\nINPUT ERROR\n";
    std::cout << "\nSelect an operating mode:\n";
    std::cout << "1. Run tests\n";
    std::cout << "2. Run Program\n";
    std::cout << "Your choice: ";
    return false;
}

bool CurrentInputTests(int type)
{
    return (type >= 0 && type <= 3);
}

void TestMenu() 
{
    int type;
    do {
        std::cout << "\nSelect the type of tests:\n";
        std::cout << "1. All tests\n";
        std::cout << "2. Logic tests\n";
        std::cout << "3. Functional tests\n";
        std::cout << "0. Back\n";
        std::cout << "Your choice: ";
        std::cin >> type;

        if (!CurrentInputTests(type)) {
            std::cout << "\nERROR INPUT\n";
            continue;
        }

        switch (type) {
            case 1: VectorBoolLogicalTests::runAll(); break;
            case 2: VectorBoolLogicalTests::runAll(); break;
            case 3: VectorBoolFunctionalTests::runAll(); break;
        }
    } while (type != 0);
}

void Menu() 
{
    int choice;
    do {
        std::cout << "\nSelect an operating mode:\n";
        std::cout << "1. Run tests\n";
        std::cout << "2. Run Program\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
    } while (!CurrentInput(choice));

    if (choice == 1) {
        TestMenu();
    } else {
        DoingProgramm();
    }
}

int main()
{
    printTask();
    Menu();
    return 0;
}