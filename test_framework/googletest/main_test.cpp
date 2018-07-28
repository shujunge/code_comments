
#include <iostram>
#include "gtest/gtest.h"

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


TEST_F(Test_Sort,read_file)
{

    one_Tuple m_coordinate;
    one_Tuple angle;
    //正确路径输入测试
    string filename="test_data/simtarget_data";
    bool result=read_file(filename,m_coordinate,angle);
    ASSERT_TRUE(result);
    //错误路径输入测试
    filename="1";
    result=read_file(filename,m_coordinate,angle);
    ASSERT_FALSE(result);

    //输入错误的路径测试
    filename="test_data/angle0.dot";
    result=read_file(filename,m_coordinate,angle);
    ASSERT_FALSE(result);

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
