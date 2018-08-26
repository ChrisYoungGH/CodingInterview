/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

#pragma once

#include <vector>

using namespace std;


int Partition(int data[], int length, int start, int end);

vector<vector<int> > Array2Matrix(const int *arr, int rows, int cols);
vector<int> Array2Vector(const int *arr, int n);
void PrintVector(vector<int> &vec);
void PrintMatrix(vector<vector<int> > &matrix);