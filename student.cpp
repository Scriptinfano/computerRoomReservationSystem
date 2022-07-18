//
// Created by USER on 13/07/2022.
//

#include "student.h"
#include "reservation.h"

//���ι��캯��
studentClass::studentClass(int id, string name, string password) {
    //��ʼ������
    this->setStudentId(id);
    this->setNamePassword(name, password);
    //��ʼ��������Ϣ
    this->initComputerRoom();
}

//��ʾ�Ӳ˵�
void studentClass::showSubMenu() {
    cout << "��ӭѧ������--" << this->getName() << "��¼!" << endl;
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
void studentClass::applyReservation() {
    cout << "��������ʱ��Ϊ��һ�����壡" << endl;
    cout << "��ѡ������ԤԼ��ʱ�䣺" << endl;
    cout << "1����һ" << endl;
    cout << "2���ܶ�" << endl;
    cout << "3������" << endl;
    cout << "4������" << endl;
    cout << "5������" << endl;

    //���������������ڽ����û�����
    int date = 0;//����
    int interval = 0;//ʱ���
    int room = 0;//�������

    while (true) {
        (cin >> date).get();
        if (date >= 1 && date <= 5) {
            //�����������ȷ
            break;
        } else
            cout << "������������������" << endl;
    }
    cout << "����������ԤԼ��ʱ��Σ�" << endl;
    cout << "1������" << endl;
    cout << "2������" << endl;
    while (true) {
        (cin >> interval).get();
        if (interval == 1 || interval == 2) {
            break;
        } else
            cout << "������������������" << endl;
    }

    cout << "��ѡ�������" << endl;
    for (int i = 0; i < 3; i++) {
        cout << v_computerRooms.at(i).getRoomNumber() << "�Ż���\t" << "������" << v_computerRooms.at(i).getMaxVolume()
             << endl;
    }
    while (true) {
        (cin >> room).get();
        if (room >= 1 && room <= 3) {
            break;

        }
        cout << "������������������" << endl;

    }
    cout << "ԤԼ�ɹ��������" << endl;
    ofstream fileOut(reservationFile, ios::out | ios::app);
    fileOut << "date:" << date << " " << "interval:" << interval << " " << "roomId:" << room << " " << "studentId:"
            << m_studentId << " " << "studentName:" << m_name << " " << "status:1" << " " << endl;
    fileOut.close();
    system("pause");
    system("cls");
}

//�鿴����ԤԼ��Ϣ
void studentClass::showMyReservation() {
    reservationClass reservation;
    int reservationSize = reservation.getReservationSize();
    if (reservationSize == 0) {
        cout << "û��ԤԼ��¼" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < reservationSize; i++) {
        //stoi�����������ַ���ת��Ϊ�������
        if (stoi(reservation.getReservationData(i, "studentId")) == this->getStudentId()) {
            string dateHint = "ԤԼ���ڣ���", reservationDate = reservation.getReservationData(i, "dateHint");
            if (reservationDate == "1")dateHint += "һ";
            else if (reservationDate == "2")dateHint += "��";
            else if (reservationDate == "3")dateHint += "��";
            else if (reservationDate == "4")dateHint += "��";
            else dateHint += "��";
            cout << dateHint;

            cout << "ʱ�Σ�" << (reservation.getReservationData(i, "interval") == "1" ? "����" : "����");
            cout << "������" << reservation.getReservationData(i, "roomId") << "��";
            string status = "״̬��";
            if (reservation.getReservationData(i, "status") == "1") {
                status += "�����";
            } else if (reservation.getReservationData(i, "status") == "2") {
                status += "ԤԼ�ɹ�";
            } else if (reservation.getReservationData(i, "status") == "-1") {
                status += "���δͨ����ԤԼʧ��";
            } else {
                //��reservation.getReservationData(i,"status")=="0"ʱ
                status += "ԤԼ��ȡ��";
            }
            cout << "ԤԼ״̬��" << status << endl;


        }
    }
    system("pause");
    system("cls");
}

//��ʾ�����˵�ԤԼ
void studentClass::showAllReservation() {
    reservationClass reservation;
    int reservationSize = reservation.getReservationSize();
    if (reservationSize == 0) {
        cout << "û��ԤԼ��¼" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < reservationSize; i++) {
        cout << i + 1 << "��";
        string dateHint = "ԤԼ���ڣ���", reservationDate = reservation.getReservationData(i, "dateHint");
        if (reservationDate == "1")dateHint += "һ";
        else if (reservationDate == "2")dateHint += "��";
        else if (reservationDate == "3")dateHint += "��";
        else if (reservationDate == "4")dateHint += "��";
        else dateHint += "��";
        cout << dateHint;

        cout << "ʱ�Σ�" << (reservation.getReservationData(i, "interval") == "1" ? "����" : "����");
        cout << "������" << reservation.getReservationData(i, "roomId") << "��";
        string status = "״̬��";
        if (reservation.getReservationData(i, "status") == "1") {
            status += "�����";
        } else if (reservation.getReservationData(i, "status") == "2") {
            status += "ԤԼ�ɹ�";
        } else if (reservation.getReservationData(i, "status") == "-1") {
            status += "���δͨ����ԤԼʧ��";
        } else {
            //��reservation.getReservationData(i,"status")=="0"ʱ
            status += "ԤԼ��ȡ��";
        }
        cout << "ԤԼ״̬��" << status << endl;

    }
}

//ȡ��ԤԼ
void studentClass::cancelReservation() {

}

void studentClass::operateSubMenu() {
    string select;
    studentClass *student = (studentClass *) this;
    while (true) {
        this->showSubMenu();
        getline(cin, select);
        if (select == "1") {
            //����ԤԼ
            student->applyReservation();
        } else if (select == "2") {
            //�鿴�ҵ�ԤԼ
            student->showMyReservation();

        } else if (select == "3") {
            //�鿴����ԤԼ
            student->showAllReservation();

        } else if (select == "4") {
            //ȡ��ԤԼ
            student->cancelReservation();
        } else if (select == "5") {
            //�˳���¼
            student->logout();
            return;
        } else {
            cout << "�����ѡ�������������ȷ��ѡ��" << endl;
            system("pause");
            system("cls");
        }
    }

}
