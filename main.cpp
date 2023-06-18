#include <iostream>

#include <gtest/gtest.h>


#include "multiplier_tests.h"



auto main(int argc, char** argv) -> int {

    
    std::cout << "Welcome to the ldvector test application!\n";

    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();



    return 0;

}