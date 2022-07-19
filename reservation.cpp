#include "reservation.h"

//�ڹ��캯���н��ļ������е�ԤԼ��Ϣ��ȡ���ڲ�Ƕ�׵�map������
reservationClass::reservationClass() {
    m_reservationData.clear();

    ifstream fileIn(reservationFile, ios::in);

    if (fileIsEmpty(fileIn) == 1)return;

    string date;//����
    string interval;//ʱ���
    string roomId;//�������
    string studentId;//ѧ��ѧ��
    string studentName;//ѧ������
    string status;//ԤԼ״̬


    while (fileIn >> date && fileIn >> interval && fileIn >> roomId && fileIn >> studentId && fileIn >> studentName &&
           fileIn >> status) {
        map<string, string> singleReservationInformation;//ԤԼ��Ϣ��Ԫ����������ԤԼ��Ϣ��Ԫ���һ��������ԤԼ��Ϣ
        //ĿǰԤԼ��Ϣ���ͺ;�����Ϣ֮�仹��:���ӣ���������Ҫ������Ϣ���ͺ;�����Ϣ
        //ÿ��ѭ������һ��ԤԼ��Ϣ
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

void reservationClass::setStatus(int index, string status) {
m_reservationData.at(index).at("status")=status;
}



