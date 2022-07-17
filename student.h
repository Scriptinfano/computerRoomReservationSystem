#pragma once

#include<iostream>
#include<string>
#include "computerRoom.h"
#include"identity.h"

using namespace std;

class studentClass : public identityClass {
public:
    //Ĭ���޲ι��캯��
    studentClass() = default;

    //�вι��캯��
    studentClass(int id, string name, string password);

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

    void setStudentId(int studentId) { m_studentId = studentId; }

    int getStudentId() { return m_studentId; }


private:
    //���������̳��Ը���

    int m_studentId;//ѧ�����еĳ�Ա����

};
