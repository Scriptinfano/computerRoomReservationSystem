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
    studentClass(int id, string name, string password);

    //子菜单界面
    virtual void showSubMenu();

    //操作子菜单
    virtual void operateSubMenu();


    //申请预约
    void applyReservation();

    //查看我的预约
    void showMyReservation();

    //查看所有预约
    void showAllReservation();

    //取消预约
    void cancelReservation();

    //注销登录的功能继承父类无需再次定义

    void setStudentId(int studentId) { m_studentId = studentId; }

    int getStudentId() { return m_studentId; }


private:
    //机房容器继承自父类

    int m_studentId;//学生独有的成员变量

};
