#pragma once

#include <iostream>

using namespace std;
class systemManager {

public:
    systemManager();

    ~systemManager();

    void showMenu();

    void login(string fileName, identityNameUnion identityName);//��һ��������Ҫ�������ļ�·�����ڶ�����������ݴ���

    void exitSystem();

};