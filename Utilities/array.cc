/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <exception>
#include <iostream>


// Random Partition
int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition(int data[], int length, int start, int end)
{
    if(data == nullptr || length <= 0 || start < 0 || end >= length) {
        printf("Invalid Parameters\n");
        return -1;
    }

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for(index = start; index < end; ++ index)
    {
        if(data[index] < data[end])
        {
            ++ small;
            if(small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++ small;
    Swap(&data[small], &data[end]);

    return small;
}


vector<int> Array2Vector(const int *arr, int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = arr[i];
    }
    return vec;
}

vector<vector<int> > Array2Matrix(const int *arr, int rows, int cols) {
    vector<vector<int> > matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = arr[i * cols + j];
        }
    }
    return matrix;
}

void PrintVector(vector<int> &vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void PrintMatrix(vector<vector<int> > &matrix) {
    for (vector<int> vec : matrix) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}
