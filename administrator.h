//ѧУ����Ա

#pragma once

#include<iostream>
#include"identity.h"
#include"teacher.h"
#include"student.h"
#include "computerRoom.h"

using namespace std;

class administratorClass : public identityClass {
public:
    //Ĭ�Ϲ���
    administratorClass()=default;

    //�вι���
    administratorClass(string name, string password);

    //�˵�����
    virtual void showSubMenu();

    //�����Ӳ˵�
    virtual void operateSubMenu();

    //����˺�
    void addAccount();

    //�鿴�˺�
    void showAccount();

    //�鿴������Ϣ
    void showComputerRoom();

    //���ԤԼ��¼
    void clearReservation();

    //ע����¼�Ĺ��ܼ̳и��������ٴζ���

    //��ʼ���ڲ�vector���������ļ��е����ݶ�ȡ��vector������
    void initVector();

    //��ʼ��������Ϣ����Ϊ������Ϣֻ��Ҫ��ʼ��һ�Σ���ͬ��initVector()��Ҫ��ε���
    void initComputerRoom();
    //������˺�ʱ����Ƿ�������ظ���id
    bool checkRepeatId(int id,string identity);

private:
    vector<teacherClass>v_teachers;
    vector<studentClass>v_students;
    vector<computerRoomClass>v_computerRooms;
};