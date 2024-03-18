//
// Created by 25369 on 16/3/2024.
//
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "fstream"
#include "random"
#include <cinttypes>
const std::string file=R"(D:\\YURI\\PHD_NTU\\linear_equation\\Z-tech\\GENERAL_AUTO\\New_C\\3R.dat)";
void LoadDat(const std::string&  file,int size)
{
    uint8_t b[size];
    std::ifstream inF;
    inF.open(file, std::ifstream::binary);
    inF.read(reinterpret_cast<char*>(b), sizeof(uint8_t )*size);
    inF.close();

    for (int i = 0; i < size; i++)
    {

        if(i%20==0)
        {
            std::cout<<std::endl;
        }
        std::cout << int(b[i]) <<" ,";
    }
}

int main()
{
    LoadDat(file,2048);
    return 0;

}