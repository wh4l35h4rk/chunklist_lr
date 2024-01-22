#include <iostream>
#include "chunklist.hpp"
using namespace fefu_laboratory_two;

int main() {
    ChunkList<int> test (3);
    for (int i = 0; i < 9; i++) test.insert(i);
    test.output();
    std::cout << std::endl;

    test.erase(3);
    test.erase(4);
    test.erase(3);
    test.output();
    std::cout << std::endl;

    test.pop_back();
    test.pop_head();
    test.output();
    std::cout << std::endl;

    test.insert(10);
    test.output();
    return 0;
}