#include "../../../inc/Tests/Functional/Test2.h"
#include <iostream>
/**
 * Описание того что проверяем.
 * @return
 */
bool Test2::exec() {
    std::cout<<std::endl<<"Run "<< getTestName() <<"...";
    return false;
}
