//
// Created by USER on 13/07/2022.
//

#include "student.h"


//���ι��캯��
studentClass::studentClass(int id, string name, string passord) {
    this->m_studentId = id;
    this->m_name = name;
    this->m_password = passord;
}

//��ʾ�Ӳ˵�
void studentClass::showSubMenu() {
    cout << "��ӭѧ������--" << this->m_name << "��¼!" << endl;
    cout << "=======================����������ѡ��=====================" << endl;
    cout << "|                       1 ����ԤԼ                      | " << endl;
    cout << "|                       2 �鿴�ҵ�ԤԼ                   |" << endl;
    cout << "|                       3 �鿴����ԤԼ                   |" << endl;
    cout << "|                       4 ȡ��ԤԼ                      |" << endl;
    cout << "|                       5 �˳���¼                      |" << endl;
    cout << "========================================================" << endl;
    cout << "����������ѡ��";

}

//����ԤԼ
void studentClass::applyAppointment() {

}

//��ʾ�Լ���ԤԼ
void studentClass::showMyAppointment() {

}

//��ʾ�����˵�ԤԼ
void studentClass::showAllAppointment() {

}

//ȡ��ԤԼ
void studentClass::cancelAppointment() {

}

void studentClass::operateSubMenu() {
    string select;
    studentClass *student = (studentClass *) this;
    while (true) {
        this->showSubMenu();
        getline(cin, select);
        if (select == "1") {
            //����ԤԼ
            student->applyAppointment();
        } else if (select == "2") {
            //�鿴�ҵ�ԤԼ
            student->showMyAppointment();

        } else if (select == "3") {
            //�鿴����ԤԼ
            student->showAllAppointment();

        } else if (select == "4") {
            //ȡ��ԤԼ
            student->cancelAppointment();
        } else if(select=="5"){
            //�˳���¼
            student->logout();
            return;
        }
        else
        {
            cout<<"�����ѡ�������������ȷ��ѡ��"<<endl;
            system("pause");
            system("cls");
        }
    }

}
