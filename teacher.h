#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;
#include "identity.h"

class teacherClass :public identityClass
{
public:

    //Ĭ�Ϲ���
    teacherClass()=default;
    //�вι���
    teacherClass(int employeeId,string name,string password);
    //�˵�����
    virtual void showSubMenu();

    //�����Ӳ˵�
    virtual void operateSubMenu();

    //�鿴����ԤԼ
    void showAllReservation();
    //���ԤԼ
    void verifyReservation();

    int m_employeeId;

    //ע����¼�Ĺ��ܼ̳и��������ٴζ���

};