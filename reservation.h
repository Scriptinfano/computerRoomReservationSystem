#pragma once

#include<iostream>
#include<map>
#include<fstream>
#include "globalFile.h"
#include"globalFunction.h"
using namespace std;



//ԤԼ�����࣬ÿ����������������ԤԼ��¼
class reservationClass {
public:
    reservationClass();

    void updateReservation();//����ԤԼ״̬���������е�ԤԼ��Ϣд���ļ�

    int getReservationSize();

    string getReservationData(int index,string key);//�õ�ԤԼ�����о���ĳһ��������ĳ�����͵�valueֵ
    //index��������ԤԼ��¼������ֵ��key����ĳ��ԤԼ��¼��ĳ�������Ϣ��keyֵ

    //date interval roomId studentId studentName status
private:
    map<int, map<string, string>> m_reservationData;
    /*���������Ƕ��map���������map������int����ԤԼ��¼�����map�����е��±꣬���һ��ԤԼ��¼���±����0
     * �ڲ�map�����ĵ�һ��string����ԤԼ�е����ڼ������Ϣ���ͣ�
     * �ڶ���string����ÿ����Ϣ�����µľ�����Ϣ����*/
};