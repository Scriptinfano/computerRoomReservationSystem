//��ͷ�ļ������cpp�ļ����ṩ������Ŀ����Ҫ��ȫ�ֺ�������Щȫ�ֺ�������������Ŀ���κ�λ���ṩ����ֻҪ������ͷ�ļ�
#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int fileIsEmpty(ifstream &fileIn);

void reservationInformationToMap(string &reservationUnit,map<string,string>&singleReservationInformation);