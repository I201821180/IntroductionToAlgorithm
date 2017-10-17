#ifndef _VECTOROPERATION_H_
#define _VECTOROPERATION_H_

#include <iostream>
#include <vector>
#include <random>
#include <functional>

#include <ctime>
#include <cstdint>

using namespace std;

template<typename T>
void getRandomVector(vector<T>& v, int32_t size, int32_t from, int32_t to);

template void getRandomVector<int32_t>(vector<int32_t>& v, int32_t size, int32_t from, int32_t to);

template<typename T> 
void printVector(vector<T>& v);

// ģ����ʾʵ����������ģ���������ʵ�ֲ��ֿܷ�

template void printVector<int>(vector<int>& v);

#endif
