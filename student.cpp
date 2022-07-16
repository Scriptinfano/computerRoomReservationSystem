//
// Created by USER on 13/07/2022.
//

#include "student.h"


//含参构造函数
studentClass::studentClass(int id, string name, string passord) {
    //初始化属性
    this->setStudentId(id);
    this->setNamePassword(name, passord);
    //初始化机房信息
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
void studentClass::applyAppointment() {

}

//显示自己的预约
void studentClass::showMyAppointment() {

}

//显示所有人的预约
void studentClass::showAllAppointment() {

}

//取消预约
void studentClass::cancelAppointment() {

}

void studentClass::operateSubMenu() {
    string select;
    studentClass *student = (studentClass *) this;
    while (true) {
        this->showSubMenu();
        getline(cin, select);
        if (select == "1") {
            //申请预约
            student->applyAppointment();
        } else if (select == "2") {
            //查看我的预约
            student->showMyAppointment();

        } else if (select == "3") {
            //查看所有预约
            student->showAllAppointment();

        } else if (select == "4") {
            //取消预约
            student->cancelAppointment();
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
