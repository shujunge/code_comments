//
// Created by zf on 18-3-23.
//

///doxygen对c++代码注释参考:https://blog.csdn.net/czyt1988/article/details/8901191
///
///
///
///

#ifndef CPLUSPLUS_LOCATION_H
#define CPLUSPLUS_LOCATION_H

#include "Eigen/Dense"/* 使用c++的eigen矩阵库*/
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sys/time.h>/* 用于算法程序运行时间的统计*/

extern int numberruncount;

using namespace std;
using namespace Eigen;

typedef vector<double> one_Tuple;/**< 使用one_Tuple代替vector<double>*/
typedef vector<one_Tuple> two_Tuple;/**< 使用two_Tuple代替vector<vector<double>>*/
typedef vector<two_Tuple> three_Tuple;/**< 使用three_Tuple代替vector<vector<vector<double>>>*/


/// \brief 对一个二维的vector<vector<double>>的list进行按照每一个vector<double>的第２个元素进行升序
/// \param list是vector<vector<double>>类型
/// \param temp为int类型
/// \return 无返回
void sortarry(two_Tuple&list,int temp);



/// \brief 判断value元素是否属于2维vector中的第一个元素,如果value属于list中返回true,否则返回false.
/// \param value为double类型
/// \param list是vector<vector<double>>类型
/// \return bool类型
bool finditems(double value,two_Tuple& list);

/**
 * \brief 判断value元素是否属于1维vector的list,如果value属于list中返回true,否则返回false.
 *
 * \param  list是vector<double>类型
 * \param value为double类型
 *
 * \return bool类型
 *
 */
bool finditems(double value,one_Tuple& list);

/**
 * \brief 坐标点聚类算法,即判断一维的vector<double>类型是否属于交点坐标聚类集合list中的一类,如果属于其中的一类,
 * 则将该1维的vector归入到该类中,否则单独归为list中新的一类.
 *
 * \param list_one是vector<double>类型
 * \param list为vector<vector<vector<double>>>类型
 *
 * \return int类型
 *
 */
int classification(const one_Tuple& list_one,three_Tuple& list);

/**
 * \brief 判断两个二维vector即list和list1是否相等,如果两个相等,返回true.否则返回false.
 *
 * \param list为vector<vector<double>>类型
 * \param list1为vector<vector<double>>类型
 *
 * \return bool类型
 *
 */
bool isequal(const two_Tuple& list,const two_Tuple& list1);

/**
 * \brief 测向线交点坐标聚类算法，即第一步读取靶点和测向线的数据信息，将两两测向线进行相交的到交点坐标．
 * 第2步即将交点坐标送入坐标聚类算法中，进行坐标点的聚类．其中m_data为靶点的坐标．angle为每个靶点对应的测向
 * 线的角度信息．list_three为输出的坐标点聚类集合．numberruncount为测向线数量用于剔除独立的测向线聚类集合．
 *
 * \param  m_data为vector<double>类型
 * \param angle为vector<vector<double>>类型
 * \param list_three为vector<vector<double>>类型
 * \param numberruncount为int类型
 * \return 无
 *
 */
void productiondot(one_Tuple& m_data,two_Tuple& angle,three_Tuple & list_three,int& numberruncount);

/**
 * \brief 将坐标点聚类集合转化为测向线聚类集合．其中means_result为输入的坐标点聚类集合．
 * f_result为输出的测向线聚类集合．numberruncount为测向线数量用于剔除独立的测向线聚类集合．
 *
 * \param  means_result为vector<vector<double>>类型
 * \param f_result为vector<vector<double>>类型
 * \param numberruncount为int类型
 * \return 无.
 *
 */
void clearreplace(three_Tuple& means_result,three_Tuple& f_result,int& numberruncount);
/**
 * \brief 将测向线聚类集合送入目标定位算法中，进行目标点定位．其中f_result为输入的测向线聚类集合．
 * list_two为所有目标点的坐标．str为目标点的坐标信息以文件形式输出的文件路径．
 *
 * \param  f_result为vector<vector<double>>类型
 * \param list_two为vector<vector<double>>类型
 * \param str为string类型
 *
 * \return 无.
 *
 */
void Demo4Mult_Targetlocalization(three_Tuple& f_result,two_Tuple& list_two,string& str);
/**
 * \brief 单目标定位算法根据输入的测向线角度和靶点坐标求解目标点的具体位置信息．
 * data为所有靶点的坐标．angle为每个靶点对应测向线的角度信息．定位出来的目标点坐标将保存在result．
 *
 * \param angle为vector<double>类型
 * \param data为vector<double>类型
 * \param result为MatrixXd类型
 *
 * \return 无.
 *
 */
void  Demo1Single_Target(one_Tuple& angle,one_Tuple& data,MatrixXd& result);

/**
 * \brief 对靶点数据和测向线数据通过聚类算法得到测向线聚类坐标集合．其中m_data为所有靶点的坐标．
 * angle为每个靶点对应测向线的角度信息．交点坐标聚类集合为list_three，测向线组聚类集合为list_threetwo．
 *
 * \param angle为vector<double>类型
 * \param data为vector<double>类型
 * \param result为MatrixXd类型
 *
 * \return 无
 *
 */

void Demo2(one_Tuple& m_data,two_Tuple& angle,three_Tuple& list_three,three_Tuple& list_three2);

/**
 * \brief 判断测向线组中任意两类是否具有重复的测向线信息．将第一类中非重复的部分归入第2类中．
 * A为一类的测向线聚类组．B为另一类的测向线聚类组．
 *
 * \param A为vector<vector<double>>类型
 * \param B为vector<vector<double>>类型
 *
 * \return 无
 *
 */
void Demo3count(two_Tuple& A,two_Tuple& B);

/**
 * \brief 判断测向线组中任意两类是否具有重复的测向线信息．将重复的多余的部分进行删除． A为一类的测向线聚类组．
 * B为另一类的测向线聚类组．numberruncount为测向线数量用于剔除独立的测向线聚类集合．
 *
 * \param A为vector<vector<double>>类型
 * \param B为vector<vector<double>>类型
 * \param numberruncount为int类型
 * \return 无
 *
 */
void Demo3intersect(two_Tuple& A,two_Tuple& B, ofstream& out_stream,int numberruncount);

/**
 * \brief 判断一类测向线聚类组与整个测向线聚类集合中每一类是否具有重复的测向线信息．将重复多余的测向线信息进行删除，同时更新测向线聚类集合．
 * A为一类的测向线聚类组．B为所有测向线聚类集合．numberruncount为测向线数量用于剔除独立的测向线聚类集合．
 *
 * \param A为vector<vector<double>>类型
 * \param B为vector<vector<vector<double>>>类型
 * \param numberruncount为int类型
 *
 * \return　无
 *
 */
void Demo3(three_Tuple& f_result,three_Tuple& list_three,string & str,int &numberruncount);

/**
 * \brief 将测向线聚类集合进行测向线野值检测. 将重复多余的测向线信息进行删除,同时更新测向线聚类集合.将删除的测向线信息保存到文件中.
 * f_result为一类的测向线聚类组.list_three为所有测向线聚类集合.str为删除的测向线信息以文件形式输出的路径.numberruncount为测向线
 * 数量用于剔除独立的测向线聚类集合．
 *
 * \param Ａ为vector<vector<double>>类型
 * \param Ｂ为vector<vector<vector<double>>>类型
 * \param str为string类型
 * \param numberruncount为int类型
 *
 * \return 无
 *
 */
void Demo3remove(two_Tuple& A,three_Tuple& B, ofstream& out_stream, int&  numberruncount);

/**
 * \brief 测试数据数据通过命令行进行在线输入,对输入的靶点数据坐标和测向线角度信息进行保存,剔除重复输入的信息.
 * 输入的测向线角度信息保存在angles,输入的靶点坐标信息保存在m_coordinate.当输入出现数据格式出现错误时,返回false.正确返回true.
 *
 * \param angles为vector<vector<double>>类型
 * \param m_coordinate为<vector<double>类型
 *
 * \return bool类型
 *
 */
bool Demo5inputdata(two_Tuple& angles,one_Tuple& m_coordinate);

#endif //CPLUSPLUS_LOCATION_H
