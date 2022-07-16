#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>

using namespace std;

#include "identity.h"

class teacherClass : public identityClass {
public:

    //默认构造
    teacherClass() = default;

    //有参构造
    teacherClass(int employeeId, string name, string password);

    //菜单界面
    virtual void showSubMenu();

    //操作子菜单
    virtual void operateSubMenu();

    //查看所有预约
    void showAllReservation();

    //审核预约
    void verifyReservation();

    void setEmployeeId(int employeeId) { m_employeeId = employeeId; }

    int getEmployeeId() { return m_employeeId; }

private:
    int m_employeeId;

    //注销登录的功能继承父类无需再次定义

};