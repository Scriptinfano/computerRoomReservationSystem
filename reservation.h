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

    void updateReservation();//����ԤԼ״̬

    void getSizeOfReservation();//ȡ��ԤԼ������

    void setReservationSize(int reservationSize);//�����趨ԤԼ������ֻ�����������ʹ��

    void autoSetReservationSize();//���������д����Ԫ�������Զ��趨ԤԼ����

private:
    map<int, map<string, string>> m_reservationData;
    /*���������Ƕ��map���������map������int����ڼ���ԤԼ��¼
     * ���ڲ�map�����ĵ�һ��string����ԤԼ�е����ڼ������Ϣ���ͣ�
     * �ڶ���string����ÿ����Ϣ�����µľ�����Ϣ����*/
    int m_reservationSize;//ԤԼ��¼������
};