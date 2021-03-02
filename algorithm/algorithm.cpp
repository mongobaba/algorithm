// algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <gtest/gtest.h>

#pragma comment(lib, "gtestd.lib")
#pragma comment(lib, "gmockd.lib")

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
