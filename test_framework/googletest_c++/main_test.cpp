
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
using testing::Test;

///
/// \brief googletest的测试单元，用于算法函数的测试．
///
/// \param 无
///
/// \return 无
///
///
class Test_Sort : public Test
{
    void SetUp()
    {

    }

    void TearDown()
    {

    }
};

int add(int x,int y)
{
    return x+y;
}


TEST_F(Test_Sort,add)
{
    ASSERT_EQ(add(3,7),10);
    ASSERT_EQ(add(3,1.0),4.0);
    ASSERT_TRUE(add(1.0,1.0));
    ASSERT_TRUE(add(1.0,1));
}

///
/// \brief 测试主算法对项目的各个函数进行单元测试
///
///
GTEST_API_ int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
