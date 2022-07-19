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
    cout << "欢迎教师--" << this->getName() << "登录!" << endl;
    cout << "=======================请输入您的选择=====================" << endl;
    cout << "|                       1 查看所有预约                      | " << endl;
    cout << "|                       2 审核预约                      |" << endl;
    cout << "|                       3 退出登录                      |" << endl;
    cout << "========================================================" << endl;
    cout << "请输入您的选择";

}


void teacherClass::verifyReservation() {
    reservationClass reservation;
    int reservationSize = reservation.getReservationSize();
    if (reservationSize == 0) {
        cout << "没有预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "待审核的预约记录如下" << endl;
    this->showAllReservation();
    cout << "请输入要审核的预约记录，0代表返回" << endl;

    string select;
    string verifyResult;
    while (true) {
        getline(cin, select);
        int int_select = stoi(select);
        if (int_select >= 0 && int_select <= v_reservationToBeVerify.size()) {
            if (int_select == 0)return;
            else {

                //审核通过还是不通过的具体代码
                cout << "请输入审核结果" << endl;
                cout << "1、通过" << endl;
                cout << "2、不通过" << endl;
                getline(cin, verifyResult);

                //在审核状态中，1代表审核中，0代表审核取消，2代表审核通过，-1代表审核不通过
                if (verifyResult == "1") {
                    reservation.setStatus(v_reservationToBeVerify.at(stoi(select) - 1), "2");
                } else if (verifyResult == "2") {
                    reservation.setStatus(v_reservationToBeVerify.at(stoi(select) - 1), "-1");

                } else {
                    cout << "输入的选项有误，请重新输入" << endl;
                    break;
                }
                cout << "已审核预约" << endl;
                reservation.updateReservation();
                break;

            }
        } else {
            cout << "输入有误，请重新输入：";
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
            //查看所有预约
            teacher->showAllReservation();

        } else if (select == "2") {
            //审核预约
            teacher->verifyReservation();

        } else if (select == "3") {
            //退出登录
            teacher->logout();
            return;
        } else {
            cout << "输入的选项错误，请输入正确的选项" << endl;
            system("pause");
            system("cls");
        }
    }
}

void teacherClass::showAllReservation() {
    reservationClass reservation;
    int reservationSize = reservation.getReservationSize();
    if (reservationSize == 0) {
        cout << "没有预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "待审核的预约记录如下：" << endl;
    int index = 0;
    for (int i = 0; i < reservationSize; i++) {

        if (reservation.getReservationData(i, "status") == "1")//审核预约中的记录
        {
            v_reservationToBeVerify.push_back(i);

            //输出待审核的预约记录
            cout << ++index << "、";
            string dateHint = "预约日期：周", reservationDate = reservation.getReservationData(i, "date");
            if (reservationDate == "1")dateHint += "一";
            else if (reservationDate == "2")dateHint += "二";
            else if (reservationDate == "3")dateHint += "三";
            else if (reservationDate == "4")dateHint += "四";
            else dateHint += "五";
            cout << dateHint << " ";
            cout << "时段：" << (reservation.getReservationData(i, "interval") == "1" ? "上午" : "下午") << " ";
            cout << "机房：" << reservation.getReservationData(i, "roomId") << "号" << " ";
            cout << "预约状态：审核中" << endl;
        }
    }

}
