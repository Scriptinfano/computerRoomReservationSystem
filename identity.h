#pragma once

#include<iostream>
#include<string>
#include<vector>
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

    string m_name;//用户名
    string m_password;//密码
};

