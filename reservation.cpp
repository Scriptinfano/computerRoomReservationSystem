#include "reservation.h"

//在构造函数中将文件中所有的预约信息读取到内部嵌套的map容器中
reservationClass::reservationClass() {
    m_reservationData.clear();

    ifstream fileIn(reservationFile, ios::in);

    if (fileIsEmpty(fileIn) == 1)return;

    string date;//日期
    string interval;//时间段
    string roomId;//机房编号
    string studentId;//学生学号
    string studentName;//学生姓名
    string status;//预约状态


    while (fileIn >> date && fileIn >> interval && fileIn >> roomId && fileIn >> studentId && fileIn >> studentName &&
           fileIn >> status) {
        map<string, string> singleReservationInformation;//预约信息单元容器，六个预约信息单元组成一个完整的预约信息
        //目前预约信息类型和具体信息之间还有:连接，下来我们要分离信息类型和具体信息
        //每个循环读到一条预约信息
        reservationInformationToMap(date, singleReservationInformation);
        reservationInformationToMap(interval, singleReservationInformation);
        reservationInformationToMap(roomId, singleReservationInformation);
        reservationInformationToMap(studentId, singleReservationInformation);
        reservationInformationToMap(studentName, singleReservationInformation);
        reservationInformationToMap(status, singleReservationInformation);
        m_reservationData.insert(make_pair(m_reservationData.size(), singleReservationInformation));//
    }
    fileIn.close();
}

void reservationClass::updateReservation() {
    int reservationSize = m_reservationData.size();
    if (reservationSize == 0) {
        return;
    }
    ofstream fileOut(reservationFile, ios::out | ios::trunc);
    for (int i = 0; i < reservationSize; i++) {
        fileOut << "date:" << m_reservationData.at(i).at("date") << " ";
        fileOut << "interval:" << m_reservationData.at(i).at("interval") << " ";
        fileOut << "roomId:" << m_reservationData.at(i).at("roomId") << " ";
        fileOut << "studentId:" << m_reservationData.at(i).at("studentId") << " ";
        fileOut << "studentName:" << m_reservationData.at(i).at("studentName") << " ";
        fileOut << "status:" << m_reservationData.at(i).at("status") << " " << endl;
    }
    fileOut.close();
}

int reservationClass::getReservationSize() {
    return m_reservationData.size();
}

string reservationClass::getReservationData(int index, string key) {
    return m_reservationData.at(index).at(key);
}



