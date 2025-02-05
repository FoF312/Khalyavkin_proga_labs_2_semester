//
// Created by Антон Гломадов on 18.01.2025.
//

#include "../../../inc/Tests/Functional/TestAddNode.h"
#include "../../../inc/Containers/List.h"

bool TestAddNode::exec() {
    std::cout<<std::endl<<"Run "<< getTestName() <<"...";
    List list;
    list.addNode(10);
    if (list.getSize() == 1){
        return true;
    }
    return false;
}
