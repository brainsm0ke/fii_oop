//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
using namespace std;
template<class T>
void swapper(T& a, T& b)
{
    //schimbare valori
    T aux = b;
    a = b;
    b = aux;
}
template <class T>
void sorting_algorithm(T* arr, int n) {
    //sortare crescatoare
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n ; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
