//
// Created by USER on 13/07/2022.
//

#include "student.h"
#include "reservation.h"

//含参构造函数
studentClass::studentClass(int id, string name, string password) {
    //初始化属性
    this->setStudentId(id);
    this->setNamePassword(name, password);
    //初始化机房信息
    this->initComputerRoom();
}

//显示子菜单
void studentClass::showSubMenu() {
    cout << "欢迎学生代表--" << this->getName() << "登录!" << endl;
    cout << "=======================请输入您的选择=====================" << endl;
    cout << "|                       1 申请预约                      | " << endl;
    cout << "|                       2 查看我的预约                   |" << endl;
    cout << "|                       3 查看所有预约                   |" << endl;
    cout << "|                       4 取消预约                      |" << endl;
    cout << "|                       5 退出登录                      |" << endl;
    cout << "========================================================" << endl;
    cout << "请输入您的选择";

}

//申请预约
void studentClass::applyReservation() {
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "请选择申请预约的时间：" << endl;
    cout << "1、周一" << endl;
    cout << "2、周二" << endl;
    cout << "3、周三" << endl;
    cout << "4、周四" << endl;
    cout << "5、周五" << endl;

    //创建三个变量用于接受用户输入
    int date = 0;//日期
    int interval = 0;//时间段
    int room = 0;//机房编号

    while (true) {
        (cin >> date).get();
        if (date >= 1 && date <= 5) {
            //输入的日期正确
            break;
        } else
            cout << "输入有误，请重新输入" << endl;
    }
    cout << "请输入申请预约的时间段：" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;
    while (true) {
        (cin >> interval).get();
        if (interval == 1 || interval == 2) {
            break;
        } else
            cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << v_computerRooms.at(i).getRoomNumber() << "号机房\t" << "容量：" << v_computerRooms.at(i).getMaxVolume()
             << endl;
    }
    while (true) {
        (cin >> room).get();
        if (room >= 1 && room <= 3) {
            break;

        }
        cout << "输入有误，请重新输入" << endl;

    }
    cout << "预约成功！审核中" << endl;
    ofstream fileOut(reservationFile, ios::out | ios::app);
    fileOut << "date:" << date << " " << "interval:" << interval << " " << "roomId:" << room << " " << "studentId:"
            << m_studentId << " " << "studentName:" << m_name << " " << "status:1" << " " << endl;
    fileOut.close();
    system("pause");
    system("cls");
}

//查看自身预约信息
void studentClass::showMyReservation() {
    reservationClass reservation;
    int reservationSize = reservation.getReservationSize();
    if (reservationSize == 0) {
        cout << "没有预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < reservationSize; i++) {
        //stoi函数将数字字符串转换为整型输出
        if (stoi(reservation.getReservationData(i, "studentId")) == this->getStudentId()) {
            string dateHint = "预约日期：周", reservationDate = reservation.getReservationData(i, "dateHint");
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
    system("pause");
    system("cls");
}

//显示所有人的预约
void studentClass::showAllReservation() {
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
        string dateHint = "预约日期：周", reservationDate = reservation.getReservationData(i, "dateHint");
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

//取消预约
void studentClass::cancelReservation() {

}

void studentClass::operateSubMenu() {
    string select;
    studentClass *student = (studentClass *) this;
    while (true) {
        this->showSubMenu();
        getline(cin, select);
        if (select == "1") {
            //申请预约
            student->applyReservation();
        } else if (select == "2") {
            //查看我的预约
            student->showMyReservation();

        } else if (select == "3") {
            //查看所有预约
            student->showAllReservation();

        } else if (select == "4") {
            //取消预约
            student->cancelReservation();
        } else if (select == "5") {
            //退出登录
            student->logout();
            return;
        } else {
            cout << "输入的选项错误，请输入正确的选项" << endl;
            system("pause");
            system("cls");
        }
    }

}
