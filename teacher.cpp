//
// Created by USER on 14/07/2022.
//

#include "teacher.h"

teacherClass::teacherClass(int employeeId, string name, string password) {
    this->setEmployeeId(employeeId);
    this->setNamePassword(name, password);
    this->initComputerRoom();
}

void teacherClass::showSubMenu() {
    cout << "��ӭ��ʦ--" << this->getName() << "��¼!" << endl;
    cout << "=======================����������ѡ��=====================" << endl;
    cout << "|                       1 �鿴����ԤԼ                      | " << endl;
    cout << "|                       2 ���ԤԼ                      |" << endl;
    cout << "|                       3 �˳���¼                      |" << endl;
    cout << "========================================================" << endl;
    cout << "����������ѡ��";

}

void teacherClass::showAllReservation() {

}

void teacherClass::verifyReservation() {

}

void teacherClass::operateSubMenu() {
    string select = "";
    teacherClass *teacher = (teacherClass *) this;
    while (true) {
        this->showSubMenu();
        getline(cin, select);
        if (select == "1") {
            //�鿴����ԤԼ
            teacher->showAllReservation();

        } else if (select == "2") {
            //���ԤԼ
            teacher->verifyReservation();

        } else if (select == "3") {
            //�˳���¼
            teacher->logout();
            return;
        } else {
            cout << "�����ѡ�������������ȷ��ѡ��" << endl;
            system("pause");
            system("cls");
        }
    }
}
