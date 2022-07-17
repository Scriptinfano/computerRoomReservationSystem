//该头文件及其绑定cpp文件将提供整个项目所需要的全局函数，这些全局函数将在整个项目的任何位置提供服务，只要包含此头文件
#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int fileIsEmpty(ifstream &fileIn);

void reservationInformationToMap(string &reservationUnit,map<string,string>&singleReservationInformation);