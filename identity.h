#pragma once

#include<iostream>
#include<string>
#include<vector>
#include "computerRoom.h"
#include "globalFile.h"
#include<fstream>
using namespace std;

//身份抽象类
class identityClass {
public:
    virtual void showSubMenu() = 0;//因为每种身份的子菜单是不一样的，所以要设为纯虚函数以实现多态

    void logout() {
        //三种身份的退出登录的代码相同，三种身份对象可直接调用继承自父类的接口函数实现退出登录操作
        delete this;
        cout << "退出登录成功" << endl;
        system("pause");
        system("cls");
    }

    virtual void operateSubMenu() = 0;//将接口函数的集合写入该函数的定义中

    virtual string getName(){return m_name;}
    virtual string getPassword(){return m_password;}

    virtual void setNamePassword(string name,string password){m_password=name;m_password=password;}
    virtual void setName(string name){m_name=name;}
    virtual void setPassword(string password){m_password=password;}

    //初始化机房信息，因为机房信息只需要初始化一次，不同于initVector()需要多次调用

protected:

   virtual void initComputerRoom();
protected:
    string m_name;//用户名
    string m_password;//密码
    vector<computerRoomClass>v_computerRooms;//便于子类身份访问机房信息，因此将机房容器定为protected
};
