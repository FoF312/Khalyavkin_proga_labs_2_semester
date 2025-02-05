#include "../../../inc/Tests/Logical/Test1.h"
#include <iostream>
/**
 * Описание того что проверяем.
 * @return
 */
bool Test1::exec() {
    std::cout<<std::endl<<"Run "<< getTestName() <<"...";
    return false;
}
