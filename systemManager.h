#pragma once

#include <iostream>

using namespace std;
enum identityNameUnion{student=1,teacher,administrator};
class systemManager {

public:
    systemManager();

    ~systemManager();

    void showMenu();

    void login(string fileName, identityNameUnion identityName);//第一个参数是要操作的文件路径，第二个参数是身份代号

    void exitSystem();

};