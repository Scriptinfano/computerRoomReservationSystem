#include<iostream>

using namespace std;

#include"identity.h"
#include "reservation.h"
void identityClass::initComputerRoom() {
    //��ȡ�����ļ���Ϣ
    ifstream fileIn(computerRoomFile, ios::in);
    computerRoomClass computerRoom;
    int roomNumber, maxVolume;
    while (fileIn >> roomNumber && fileIn >> maxVolume) {
        computerRoom.setRoomNumberAndMaxVolume(roomNumber, maxVolume);
        v_computerRooms.push_back(computerRoom);
    }
    fileIn.close();

}

void identityClass::showAllReservation() {
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
        string dateHint = "ԤԼ���ڣ���", reservationDate = reservation.getReservationData(i, "date");
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
