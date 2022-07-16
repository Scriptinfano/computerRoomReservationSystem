//
// Created by USER on 14/07/2022.
//
#include<iostream>
#include<fstream>
#include<string>

#include "systemManager.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "administrator.h"

using namespace std;

systemManager::systemManager() {

}

systemManager::~systemManager() {

}

void systemManager::login(string fileName, identityNameUnion identityName) {
    identityClass *person = nullptr;//����һ������ָ�����ʵ�ֶ�̬

    ifstream fileIn(fileName, ios::in);
    if (!fileIn.is_open()) {
        cout << "�ļ�������" << endl;
        fileIn.close();
        return;
    }

    //׼��һЩ���������û�������
    int id = 0;//���Ż�ѧ��
    string name;//�û���
    string password;//����

    //�û�����ѧ�ţ����ţ��û���������
    if (identityName == student) {
        cout << "�������ѧ�ţ�";
        (cin >> id).get();
    } else if (identityName == teacher) {
        cout << "���������Ĺ��ţ�";
        (cin >> id).get();
    } else {}
    cout << "�������û�����";
    getline(cin, name);
    cout << "���������룺";
    getline(cin, password);

    int idFromFile;//�洢���ļ��ж�ȡ��ѧ�Ż򹤺�
    string nameFromFile;//�洢���ļ��ж�ȡ���û���
    string passwordFromFile;//�洢���ļ��ж�ȡ������

    //������ݵ���֤
    if (identityName == student) {
        //ѧ�������֤

        //ÿ��ѭ���ж�ʱ��ȡһ�����ݣ��ֱ��Կո�Ϊ��������ݷֱ���뵽���������У������������ֱ���û���������Ա�
        while (fileIn >> idFromFile && fileIn >> nameFromFile && fileIn >> passwordFromFile) {
            if (id == idFromFile && name == nameFromFile && password == passwordFromFile) {
                cout << "ѧ����֤��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                person = new studentClass(id, name, password);//����ָ��ָ�����������ʵ�ֶ�̬

                //����ѧ����ִ�еĲ����Ӳ˵�
                person->operateSubMenu();
                //������ĺ����˳���¼��person��delete���ˣ���person��Ϊ��ָ��
                person = nullptr;
                return;
            }
        }
    } else if (identityName == teacher) {
        //��ʦ�����֤
        while (fileIn >> idFromFile && fileIn >> nameFromFile && fileIn >> passwordFromFile) {
            if (id == idFromFile && name == nameFromFile && password == passwordFromFile) {
                cout << "��ʦ��֤��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                person = new teacherClass(id, name, password);//����ָ��ָ�����������ʵ�ֶ�̬

                //������ʦ��ִ�в˵�
                person->operateSubMenu();
                person = nullptr;

                return;
            }
        }
    } else {
        //����Ա�����֤
        while (fileIn >> nameFromFile && fileIn >> passwordFromFile) {
            if (name == nameFromFile && password == passwordFromFile) {
                cout << "����Ա��֤��¼�ɹ�" << endl;
                system("pause");
                system("cls");

                person = new administratorClass(name, password);

                //�������Ա��ִ�еĲ˵�
                person->operateSubMenu();
                person = nullptr;

                return;
            }
        }
    }
    cout << "��֤��¼ʧ��!" << endl;
    system("pause");
    system("cls");
}

void systemManager::showMenu() {
    cout << "====================��ӭ��������ԤԼϵͳ===================" << endl;
    cout << "=======================�������������=====================" << endl;
    cout << "|                       1 ѧ������                      | " << endl;
    cout << "|                       2 ��ʦ                          |" << endl;
    cout << "|                       3 ����Ա                        |" << endl;
    cout << "|                       0 �˳�                          |" << endl;
    cout << "========================================================" << endl;
    cout << "����������ѡ��";

}

void systemManager::exitSystem() {
    cout << "��ӭ��һ��ʹ��" << endl;
    system("pause");
    exit(0);
}
