#pragma once

#include<iostream>
#include<string>
#include<vector>
#include "computerRoom.h"
#include "globalFile.h"
#include<fstream>

using namespace std;

//��ݳ�����
class identityClass {
public://�������������麯����ÿ����ݵ�ִ�д��벻��ͬ
    virtual void showSubMenu() = 0;//��Ϊÿ����ݵ��Ӳ˵��ǲ�һ���ģ�����Ҫ��Ϊ���麯����ʵ�ֶ�̬

    virtual void operateSubMenu() = 0;//���ӿں����ļ���д��ú����Ķ�����

    virtual void initComputerRoom();

    virtual void logout() {
        delete this;
        cout << "�˳���¼�ɹ�" << endl;
        system("pause");
        system("cls");
    }

    virtual string getName() { return m_name; }

    virtual string getPassword() { return m_password; }

    virtual void setNamePassword(string name, string password) {
        m_password = name;
        m_password = password;
    }

    virtual void showAllReservation();

protected:
    //��ʼ��������Ϣ����Ϊ������Ϣֻ��Ҫ��ʼ��һ�Σ���ͬ��initVector()��Ҫ��ε���


    string m_name;//�û���
    string m_password;//����
    vector<computerRoomClass> v_computerRooms;//����������ݷ��ʻ�����Ϣ����˽�����������Ϊprotected
};
