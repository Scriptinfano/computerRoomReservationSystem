#include<iostream>

using namespace std;

#include"identity.h"
#include "reservation.h"
void identityClass::initComputerRoom() {
    //读取机房文件信息
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
        cout << "没有预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < reservationSize; i++) {
        cout << i + 1 << "、";
        string dateHint = "预约日期：周", reservationDate = reservation.getReservationData(i, "date");
        if (reservationDate == "1")dateHint += "一";
        else if (reservationDate == "2")dateHint += "二";
        else if (reservationDate == "3")dateHint += "三";
        else if (reservationDate == "4")dateHint += "四";
        else dateHint += "五";
        cout << dateHint;

        cout << "时段：" << (reservation.getReservationData(i, "interval") == "1" ? "上午" : "下午");
        cout << "机房：" << reservation.getReservationData(i, "roomId") << "号";
        string status = "状态：";
        if (reservation.getReservationData(i, "status") == "1") {
            status += "审核中";
        } else if (reservation.getReservationData(i, "status") == "2") {
            status += "预约成功";
        } else if (reservation.getReservationData(i, "status") == "-1") {
            status += "审核未通过，预约失败";
        } else {
            //当reservation.getReservationData(i,"status")=="0"时
            status += "预约已取消";
        }
        cout << "预约状态：" << status << endl;

    }

}
