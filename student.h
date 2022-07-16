#pragma once

#include<iostream>
#include<string>
#include "computerRoom.h"
#include"identity.h"

using namespace std;

class studentClass : public identityClass {
public:
    //默认无参构造函数
    studentClass() = default;

    //有参构造函数
    studentClass(int id, string name, string passord);

    //子菜单界面
    virtual void showSubMenu();

    //操作子菜单
    virtual void operateSubMenu();


    //申请预约
    void applyAppointment();

    //查看我的预约
    void showMyAppointment();

    //查看所有预约
    void showAllAppointment();

    //取消预约
    void cancelAppointment();

    //注销登录的功能继承父类无需再次定义

    void setStudentId(int studentId) { m_studentId = studentId; }

    int getStudentId() { return m_studentId; }


private:
    vector<computerRoomClass> v_computerRooms;    //学生需要访问机房信息，所以将机房信息放在类中的成员变量中


    int m_studentId;//学生独有的成员变量

};
