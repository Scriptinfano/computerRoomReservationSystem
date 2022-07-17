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
public:
    virtual void showSubMenu() = 0;//��Ϊÿ����ݵ��Ӳ˵��ǲ�һ���ģ�����Ҫ��Ϊ���麯����ʵ�ֶ�̬

    void logout() {
        //������ݵ��˳���¼�Ĵ�����ͬ��������ݶ����ֱ�ӵ��ü̳��Ը���Ľӿں���ʵ���˳���¼����
        delete this;
        cout << "�˳���¼�ɹ�" << endl;
        system("pause");
        system("cls");
    }

    virtual void operateSubMenu() = 0;//���ӿں����ļ���д��ú����Ķ�����

    virtual string getName(){return m_name;}
    virtual string getPassword(){return m_password;}

    virtual void setNamePassword(string name,string password){m_password=name;m_password=password;}
    virtual void setName(string name){m_name=name;}
    virtual void setPassword(string password){m_password=password;}

    //��ʼ��������Ϣ����Ϊ������Ϣֻ��Ҫ��ʼ��һ�Σ���ͬ��initVector()��Ҫ��ε���

protected:

   virtual void initComputerRoom();
protected:
    string m_name;//�û���
    string m_password;//����
    vector<computerRoomClass>v_computerRooms;//����������ݷ��ʻ�����Ϣ����˽�����������Ϊprotected
};
