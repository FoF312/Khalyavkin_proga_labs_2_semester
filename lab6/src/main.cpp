#include <iostream>
#include "Matrix/Matrix.h"
#include "Tests/TestRunner.h"

TestRunner testrunner;

void printTask() 
{
    std::cout << "\n=== TASK DESCRIPTION ===\n";
    std::cout << "Implement a template class for matrices (including vectors).\n";
    std::cout << "Template parameters: element type, dimensions N and M (N, M <= 3).\n\n";
    std::cout << "Required functionality:\n";
    std::cout << "- Basic constructors and copy assignment\n";
    std::cout << "- Element access via operator()\n";
    std::cout << "- Arithmetic operations (+, *, +=, *=)\n";
    std::cout << "- Increment operator (++)\n";
    std::cout << "- Determinant calculation\n";
    std::cout << "- Input/output operations\n";
    std::cout << "========================\n\n";
}

void DemoMatrixOperations() 
{
    std::cout << "\n=== MATRIX DEMONSTRATION ===\n";
    
    // Создание и вывод матрицы
    Matrix<int, 2, 2> mat1 = {{{1, 2}, {3, 4}}};
    std::cout << "Matrix 1:\n" << mat1 << std::endl;

    Matrix<int, 2, 2> mat2 = {{{5, 6}, {7, 8}}};
    std::cout << "Matrix 2:\n" << mat2 << std::endl;

    // Сложение матриц
    auto sum = mat1 + mat2;
    std::cout << "Sum (Matrix1 + Matrix2):\n" << sum << std::endl;

    // Умножение матриц
    auto product = mat1 * mat2;
    std::cout << "Product (Matrix1 * Matrix2):\n" << product << std::endl;

    // Инкремент
    std::cout << "After prefix increment:\n" << ++mat1 << std::endl;
    std::cout << "After postfix increment:\n" << mat1++ << std::endl;
    std::cout << "Final state:\n" << mat1 << std::endl;

    // Определитель
    std::cout << "Determinant of Matrix1: " << mat1.determinant() << std::endl;
}

void ManualMatrixInput() 
{
    std::cout << "\n=== MANUAL MATRIX INPUT ===\n";
    Matrix<int, 2, 2> mat;
    std::cout << "Enter 2x2 matrix elements (row by row):\n";
    std::cin >> mat;
    std::cout << "You entered:\n" << mat << std::endl;
    std::cout << "Determinant: " << mat.determinant() << std::endl;
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
        DemoMatrixOperations();
    } 
    else if (mode == 2) {
        ManualMatrixInput();
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
            case 1: testrunner.runAllTests(); break;
            case 2: testrunner.runLogicalTests(); break;
            case 3: testrunner.runFunctionalTests(); break;
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