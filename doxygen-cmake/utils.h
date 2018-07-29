//
// Created by fred on 5/22/18.
//

#ifndef MULTILOC_UTILS_H
#define MULTILOC_UTILS_H

#include <multiloc.h>

/**
 * \brief 输出1维vector<double>的数据到命令行
 *
 * \param list为vector<double>类型
 *
 * \return 无
 *
 */
void print(one_Tuple& list);

/**
 * \brief 输出2维vector<vector<double>>的数据到命令行
 *
 * \param list为vector<vector<double>>类型
 *
 * \return 无
 *
 */
void print(two_Tuple& list);

/**
 * \brief 输出3维vector<vector<vector<double>>>的数据到命令行
 *
 * \param list为vector<vector<vector<double>>>类型
 *
 * \return 无
 *
 */
void print(three_Tuple& list);

/**
 * \brief 输出2维MatrixXd前total个的数据到命令行
 *
 * \param list为MatrixXd类型
 * \param total为int类型
 *
 * \return 无
 *
 */
void print(MatrixXd& list,int &total);

/**
 * \brief: 从文件中读取数据内容，将输出的结果保存在一维的vector<double>中．
 * filename为需要读取数据的文件名路径，tuples保存读取的数据．读取数据成功，返回true．否则，返回false．
 *
 * \param: filename为char字符串类型
 * \param: tuples为vector<double>类型
 *
 * \return: bool类型
 *
 */
bool read_data(const char *filename,one_Tuple& tuples);

/**
 * \brief 从文件中读取用于多目标定位的靶点和测向线信息，其中filename为需要读取数据的文件路径，
 * 将读取的靶点坐标保存在m_data中，将读取的测向线信息保存在angle中．
 *
 * \param Docement为string类型
 * \param m_data为vector<double>类型
 * \param angle为vector<vector<double>>类型
 *
 * \return bool类型，读取数据成功，返回true．否则，返回false．
 *
 */
bool read_file(string& Docement,one_Tuple& m_data,two_Tuple& angle);

/**
 * \brief 从文件中读取用于单目标定位的靶点和测向线信息，其中filename为需要读取数据的文件路径，
 * 将读取的靶点坐标保存在m_data中，将读取的测向线信息保存在angle中．
 *
  * \param Docement为string类型
 * \param m_data 为vector<double>类型
 * \param angle 为vector<double>类型
 *
 * \return bool类型，读取数据成功，返回true；否则，返回 false。
 *
 */
bool  read_file(string& Docement,one_Tuple& m_data,one_Tuple& angle);


#endif //MULTILOC_UTILS_H
