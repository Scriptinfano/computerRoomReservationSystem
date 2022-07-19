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

    void updateReservation();//更新预约状态，将容器中的预约信息写入文件

    int getReservationSize();

    string getReservationData(int index,string key);//得到预约容器中具体某一条容器中某个类型的value值
    //index代表整条预约记录的索引值，key代表某条预约记录中某项具体信息的key值
    void setStatus(int index, string status);
    //date interval roomId studentId studentName status
private:
    map<int, map<string, string>> m_reservationData;
    /*解释上面的嵌套map容器：外层map容器的int代表预约记录在外层map容器中的下标，如第一个预约记录的下标就是0
     * 内层map容器的第一个string代表预约中的日期间隔等信息类型，
     * 第二个string代表每个信息类型下的具体信息内容*/
};