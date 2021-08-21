//
// Created by petrm on 31.07.2021.
//
#pragma once
#ifndef FIRST_MYTABLE_H
#define FIRST_MYTABLE_H

#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <algorithm>

namespace mynamespace{
    class MyTable {
    public:           // Access specifier
//        MyTable() {}
        MyTable (std::vector<std::vector<std::string>>* vec,unsigned int x_size,unsigned int y_size);
        void prinpointer();

        bool check_number(std::string str);
        bool compare_me( std::vector<std::string>& first, std::vector<std::string>& second, int nmb_col, bool equal);
        void swap(int first, int second);
        void CallSwap();
        int Partition(int low, int high, int nmb_col);
        void QuickSort(unsigned int low, unsigned int high, int nmb_col);
        MyTable BubbleSort(int nmb_col);
        MyTable ShakerSort(int nmb_col);
        void print_table();
        friend bool MyTable::compare_me( std::vector<std::string>& first, std::vector<std::string>& second, int nmb_col, bool equal);

    private:
        std::vector<std::vector<std::string>>* p_vec;
        unsigned int x_size;
        unsigned int y_size;
    };

}

#endif //FIRST_MYTABLE_H