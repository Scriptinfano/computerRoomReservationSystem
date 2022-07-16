//学校管理员

#pragma once

#include<iostream>
#include"identity.h"
#include"teacher.h"
#include"student.h"
#include "computerRoom.h"

using namespace std;

class administratorClass : public identityClass {
public:
    //默认构造
    administratorClass()=default;

    //有参构造
    administratorClass(string name, string password);

    //菜单界面
    virtual void showSubMenu();

    //操作子菜单
    virtual void operateSubMenu();

    //添加账号
    void addAccount();

    //查看账号
    void showAccount();

    //查看机房信息
    void showComputerRoom();

    //清空预约记录
    void clearReservation();

    //注销登录的功能继承父类无需再次定义

    //初始化内部vector容器，将文件中的内容读取到vector容器中
    void initVector();

    //初始化机房信息，因为机房信息只需要初始化一次，不同于initVector()需要多次调用
    void initComputerRoom();
    //在添加账号时检测是否添加了重复的id
    bool checkRepeatId(int id,string identity);

private:
    vector<teacherClass>v_teachers;
    vector<studentClass>v_students;
    vector<computerRoomClass>v_computerRooms;
};