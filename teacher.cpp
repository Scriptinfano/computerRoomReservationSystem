//
// Created by USER on 14/07/2022.
//

#include "teacher.h"
#include "reservation.h"

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


void teacherClass::verifyReservation() {
    reservationClass reservation;
    int reservationSize = reservation.getReservationSize();
    if (reservationSize == 0) {
        cout << "û��ԤԼ��¼" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "����˵�ԤԼ��¼����" << endl;
    this->showAllReservation();
    cout << "������Ҫ��˵�ԤԼ��¼��0������" << endl;

    string select;
    string verifyResult;
    while (true) {
        getline(cin, select);
        int int_select = stoi(select);
        if (int_select >= 0 && int_select <= v_reservationToBeVerify.size()) {
            if (int_select == 0)return;
            else {

                //���ͨ�����ǲ�ͨ���ľ������
                cout << "��������˽��" << endl;
                cout << "1��ͨ��" << endl;
                cout << "2����ͨ��" << endl;
                getline(cin, verifyResult);

                //�����״̬�У�1��������У�0�������ȡ����2�������ͨ����-1������˲�ͨ��
                if (verifyResult == "1") {
                    reservation.setStatus(v_reservationToBeVerify.at(stoi(select) - 1), "2");
                } else if (verifyResult == "2") {
                    reservation.setStatus(v_reservationToBeVerify.at(stoi(select) - 1), "-1");

                } else {
                    cout << "�����ѡ����������������" << endl;
                    break;
                }


                cout << "�����ԤԼ" << endl;
                break;

            }
        } else {
            cout << "�����������������룺";
            continue;
        }
    }
    system("pause");
    system("cls");

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

void teacherClass::showAllReservation() {
    reservationClass reservation;
    int reservationSize = reservation.getReservationSize();
    if (reservationSize == 0) {
        cout << "û��ԤԼ��¼" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "����˵�ԤԼ��¼���£�" << endl;
    int index = 0;
    for (int i = 0; i < reservationSize; i++) {

        if (reservation.getReservationData(i, "status") == "1")//���ԤԼ�еļ�¼
        {
            v_reservationToBeVerify.push_back(i);

            //�������˵�ԤԼ��¼
            cout << ++index << "��";
            string dateHint = "ԤԼ���ڣ���", reservationDate = reservation.getReservationData(i, "date");
            if (reservationDate == "1")dateHint += "һ";
            else if (reservationDate == "2")dateHint += "��";
            else if (reservationDate == "3")dateHint += "��";
            else if (reservationDate == "4")dateHint += "��";
            else dateHint += "��";
            cout << dateHint << " ";
            cout << "ʱ�Σ�" << (reservation.getReservationData(i, "interval") == "1" ? "����" : "����") << " ";
            cout << "������" << reservation.getReservationData(i, "roomId") << "��" << " ";
            cout << "ԤԼ״̬�������" << endl;
        }
    }

}
