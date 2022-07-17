#pragma once

#include<iostream>
#include<map>
#include<fstream>
#include "globalFile.h"
#include"globalFunction.h"
using namespace std;

//预约管理类，每个对象来管理所有预约记录
class reservationClass {
public:
    reservationClass();

    void updateReservation();//更新预约状态

    void getSizeOfReservation();//取得预约的条数

    void setReservationSize(int reservationSize);//自由设定预约条数，只在特殊情况下使用

    void autoSetReservationSize();//根据容器中储存的元素数量自动设定预约条数

private:
    map<int, map<string, string>> m_reservationData;
    /*解释上面的嵌套map容器：外层map容器的int代表第几条预约记录
     * ，内层map容器的第一个string代表预约中的日期间隔等信息类型，
     * 第二个string代表每个信息类型下的具体信息内容*/
    int m_reservationSize;//预约记录的条数
};