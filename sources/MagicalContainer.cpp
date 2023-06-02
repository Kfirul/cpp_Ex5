#include <iostream>
#include <algorithm>

#include "MagicalContainer.hpp"

void MagicalContainer :: addElement(int element){
    bool contains = (std::find(mysticalElements.begin(), mysticalElements.end(), element) != mysticalElements.end());
    if(!contains){
        this ->mysticalElements.push_back(element);
    }
}

void MagicalContainer :: removeElement(int element){
    this -> mysticalElements.erase(std::remove(mysticalElements.begin(), mysticalElements.end(), element), mysticalElements.end());
}

int MagicalContainer :: size()const{
    return this -> mysticalElements.size();
}

std::vector<int>  MagicalContainer :: getElements()const{
    return this ->mysticalElements;
}