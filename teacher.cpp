//
// Created by USER on 14/07/2022.
//

#include "teacher.h"

teacherClass::teacherClass(int employeeId, string name, string password) {
    this->setEmployeeId(employeeId);
    this->setNamePassword(name, password);
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
