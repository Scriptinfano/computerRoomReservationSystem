#pragma once

#include<iostream>
#include<string>
#include "computerRoom.h"
#include"identity.h"

using namespace std;

class studentClass : public identityClass {
public:
    //Ĭ���޲ι��캯��
    studentClass()=default;

    //�вι��캯��
    studentClass(int id, string name, string passord);

    //�Ӳ˵�����
    virtual void showSubMenu();

    //�����Ӳ˵�
    virtual void operateSubMenu();


    //����ԤԼ
    void applyAppointment();

    //�鿴�ҵ�ԤԼ
    void showMyAppointment();

    //�鿴����ԤԼ
    void showAllAppointment();

    //ȡ��ԤԼ
    void cancelAppointment();

    //ע����¼�Ĺ��ܼ̳и��������ٴζ���


    //ѧ�����еĳ�Ա����
    int m_studentId;

    //��������
    vector<computerRoomClass>v_computerRooms;
};
