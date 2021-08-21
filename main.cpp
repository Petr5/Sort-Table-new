#include "MyTable.h"

#include <chrono>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;
using namespace std::chrono;

vector<string> split (const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

//bool compare_string(std::string& first, std::string& second){
//    for (int i =0; i < min(first.size(),second.size()); i ++){
//        if (first[i] < second[i]){
//            std::cout<< first[i] << " lower than "<< second[i] << std::endl;
//            return true;
//        }
//    }
//    return false;
//}

int main(){
    setlocale(LC_ALL, "Russian");

    std::ofstream out;
    out.open(R"(C:\Users\petrm\Documents\SortTemplate\res_to_graph\res.txt)");
//    out << "\t" << "QuickSort, seconds " << std::endl;
//    out << "100000" << "\t"<< "150000" << "\t" << "200000" << "\t" << "250000" << "\t" << "300000" << "\t" << "350000" << "\t"<< "400000" << "\t" << "450000" << "\t" << "500000" << "\t"<<std::endl;
    out << std::endl;
    int count = 0;
    int index = 100000;
    while (count < 9){
        //reading file

        std::fstream fin;
        std::cout << "i begin reading file" << std::endl;

        std::string path = "C:\\Users\\petrm\\Documents\\SortTemplate\\csv files\\student " + std::to_string(index) + ".csv";
        std::cout << path << std::endl;
        //some changes, which i want to see in my repository

        fin.open(path, std::ios::in);
        std::vector<std::vector<string>> table;
        std::string str;
        while (!fin.eof()) {
            str = "";
            getline(fin, str);
            std::string delimiter = ",";
            if (str != ",,," & str != ",,,," & str != ",,,,," & str != ",," & str != ","){
                std::vector<std::string> conv_string_to_vec = split(str, delimiter);
                conv_string_to_vec.back() = split(conv_string_to_vec.back(), "\r" )[0];
                table.push_back(conv_string_to_vec);
            }
        }

//    table.pop_back();


        //end of reading file




        int nmb_col = 2;

        mynamespace::MyTable table1(&table, table[0].size(), table.size());


        auto start = high_resolution_clock::now();
        table1.QuickSort(1, table.size() - 2, nmb_col);
//        table1.ShakerSort(nmb_col);
//        table1.BubbleSort(nmb_col);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
//        table1.print_table();
        std::cout << "BubbleSort function was ended by " << duration.count() << " microseconds or " << (duration.count()) / 1e6 << " seconds" << std::endl;

        std::cout << std::endl;

        std::ofstream fout;
        fout.open("C:\\Users\\petrm\\Documents\\SortTemplate\\sorted student " + std::to_string(index) + ".csv");

        if (fout.is_open())
        {
            for (int i = 0; i < table.size() - 1;i++){
                for(int j =0; j < table[0].size(); j++){
                    fout << table[i][j] << "\t";
                }
                fout << std::endl;
            }

            fout.close();
        }


    out << (duration.count()) / 1e6 /*<< " seconds"*/ << "\t";
    count ++;
    index = index + 50000;

    }

    out.close();
    return 0;

}