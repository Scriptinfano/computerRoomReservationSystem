#pragma once

#include<iostream>
#include<string>
#include<vector>
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

    string m_name;//�û���
    string m_password;//����
};

