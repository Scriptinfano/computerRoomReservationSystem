//
// Created by USER on 14/07/2022.
//
#include<iostream>
#include<fstream>
#include<string>
#include"globalFunction.h"
#include "systemManager.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "administrator.h"

using namespace std;

systemManager::systemManager() {

}

systemManager::~systemManager() {

}

void systemManager::login(string fileName, identityNameUnion identityName) {
    identityClass *person = nullptr;//创建一个父类指针便于实现多态

    ifstream fileIn(fileName, ios::in);

    //准备一些变量接受用户的输入
    int id = 0;//工号或学号
    string name;//用户名
    string password;//密码

    //用户输入学号，工号，用户名，密码
    if (identityName == student) {
        cout << "输入你的学号：";
        (cin >> id).get();
    } else if (identityName == teacher) {
        cout << "请输入您的工号：";
        (cin >> id).get();
    } else {}
    cout << "请输入用户名：";
    getline(cin, name);
    cout << "请输入密码：";
    getline(cin, password);

    int idFromFile;//存储从文件中读取的学号或工号
    string nameFromFile;//存储从文件中读取的用户名
    string passwordFromFile;//存储从文件中读取的密码

    //三个身份的验证
    if (identityName == student) {
        //学生身份验证

        //每次循环判断时读取一行数据，分别将以空格为间隔的数据分别读入到三个变量中，将三个变量分别和用户输入的做对比
        while (fileIn >> idFromFile && fileIn >> nameFromFile && fileIn >> passwordFromFile) {
            if (id == idFromFile && name == nameFromFile && password == passwordFromFile) {
                cout << "学生验证登录成功" << endl;
                system("pause");
                system("cls");
                person = new studentClass(id, name, password);//父类指针指向派生类对象实现多态

                //进入学生可执行的操作子菜单
                person->operateSubMenu();
                //在上面的函数退出登录后person被delete掉了，将person变为空指针
                person = nullptr;
                return;
            }
        }
    } else if (identityName == teacher) {
        //老师身份验证
        while (fileIn >> idFromFile && fileIn >> nameFromFile && fileIn >> passwordFromFile) {
            if (id == idFromFile && name == nameFromFile && password == passwordFromFile) {
                cout << "教师验证登录成功" << endl;
                system("pause");
                system("cls");
                person = new teacherClass(id, name, password);//父类指针指向派生类对象实现多态

                //进入老师可执行菜单
                person->operateSubMenu();
                person = nullptr;

                return;
            }
        }
    } else {
        //管理员身份验证
        while (fileIn >> nameFromFile && fileIn >> passwordFromFile) {
            if (name == nameFromFile && password == passwordFromFile) {
                cout << "管理员验证登录成功" << endl;
                system("pause");
                system("cls");

                person = new administratorClass(name, password);

                //进入管理员可执行的菜单
                person->operateSubMenu();
                person = nullptr;

                return;
            }
        }
    }
    cout << "验证登录失败!" << endl;
    system("pause");
    system("cls");
}

void systemManager::showMenu() {
    cout << "====================欢迎来到机房预约系统===================" << endl;
    cout << "=======================请输入您的身份=====================" << endl;
    cout << "|                       1 学生代表                      | " << endl;
    cout << "|                       2 老师                          |" << endl;
    cout << "|                       3 管理员                        |" << endl;
    cout << "|                       0 退出                          |" << endl;
    cout << "========================================================" << endl;
    cout << "请输入您的选择";

}

void systemManager::exitSystem() {
    cout << "欢迎下一次使用" << endl;
    system("pause");
    exit(0);
}
