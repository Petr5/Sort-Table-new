//
// Created by petrm on 31.07.2021.
//

#include "MyTable.h"


//typeid(var).name()  - get type of variable var

namespace mynamespace {
//    MyTable() {
//        std::cout << "Hello World!";
//    }

    MyTable::MyTable(std::vector<std::vector<std::string>>* vec,unsigned int x_size,unsigned int y_size) {

        this->p_vec = vec;
        this->x_size = x_size;
        this->y_size = y_size;
        // std::cout << (*p_vec)[2][4] << std::endl; print element by index
    };

    void MyTable::prinpointer() {
        std::cout << this->p_vec << std::endl;
    }
    void MyTable::swap(int first, int second){
        if (first!=second){
            std::vector<std::string> temp;
            temp.reserve(this->x_size);
            for (int g = 0; g < this->x_size; g++) {
                temp.push_back((*this->p_vec)[first][g]);
            }
            (*this->p_vec)[first].clear();
            for (int g = 0; g < this->x_size; g++) {
                (*this->p_vec)[first].push_back((*this->p_vec)[second][g]);
            }
            (*this->p_vec)[second].clear();
            for (int g = 0; g < this->x_size; g++) {
                (*this->p_vec)[second].push_back(temp[g]);
            }
            temp.clear(); // clear memory
            temp.shrink_to_fit();
        }
    }
    void MyTable::CallSwap(){
        swap(0, 1);
    }
    int MyTable::Partition(int low, int high, int nmb_col){
//        std::vector<std::string> pivot = this->p_vec[high];
        int i = (low - 1);
        for (int j = low; j <= high- 1; j++){
            if (compare_me((*this->p_vec)[j], (*this->p_vec)[high], nmb_col, true)){
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return (i + 1);
    }
    void MyTable::QuickSort(unsigned int low, unsigned int high, int nmb_col){
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = Partition(low, high, nmb_col);

            // Separately sort elements before
            // partition and after partition
            QuickSort( low, pi - 1, nmb_col);
            QuickSort( pi + 1, high, nmb_col);
        }
    }
    MyTable MyTable::BubbleSort(int nmb_col) {

        for (int counter = 0; counter < this->y_size - 1; counter++) {
            for (int i = 1; i < this->y_size - 2; i++) {//sort all rows

                if (compare_me((*this->p_vec)[i], (*this->p_vec)[i + 1], nmb_col, false)) {
                    swap(i, i + 1);

                }
            }

        }
        std::cout << "my sorted matrix" << std::endl;

        return *this;
    }
    MyTable MyTable::ShakerSort(int nmb_col){

        for (int i = 1; i < (*this->p_vec).size()/2; i++) {
            bool swapped = false;
            for (int j = i; j < (*this->p_vec).size() - i - 1; j++) {
                if (!compare_me((*this->p_vec)[j], (*this->p_vec)[j+1], nmb_col,  false)) {
                    swap(j, j+1);
                    swapped = true;
                }
            }
            for (int j = (*this->p_vec).size() - 2 - i; j > i; j--) {
                if (compare_me((*this->p_vec)[j], (*this->p_vec)[j-1], nmb_col, false))   {
                    swap(j, j-1);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }
        return *this;
    }
    void MyTable::print_table() {
        for (int i = 0; i < this->y_size - 1; i++) {
            for (int j = 0; j < this->x_size; j++)
                std::cout << (*this->p_vec)[i][j] << "  ";
            std::cout << std::endl << std::endl;
        }
    }
    bool MyTable::check_number(std::string str) {
        for (int i = 0; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;
    }
    bool MyTable::compare_me( std::vector<std::string> &first, std::vector<std::string> &second, int nmb_col, bool equal) {
        std::string type = "";
        if (check_number((*this->p_vec)[1000][nmb_col])){
            type = "integer";
        }
        else{
            type = "string";
        }
        if (type == "integer") {
            if (equal){
                return (std::stoi(first[nmb_col]) >= std::stoi(second[nmb_col]));
            }
            return (std::stoi(first[nmb_col]) > std::stoi(second[nmb_col]));
        }
        else if (type == "string"){

            for (int i =0; i < std::min(first[nmb_col].size(),second[nmb_col].size()); i ++){
                if (first[nmb_col][i] < second[nmb_col][i]){
//                std::cout<< [nmb_col][i] << " lower than "<< second[nmb_col][i] << std::endl;
                    return true;
                }
                else if (first[nmb_col][i] > second[nmb_col][i]){
                    return false;
                }
            }
            return false;

        }


    }

};