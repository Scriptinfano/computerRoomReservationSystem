#include "reservation.h"

//�ڹ��캯���н��ļ������е�ԤԼ��Ϣ��ȡ���ڲ�Ƕ�׵�map������
reservationClass::reservationClass() {
    m_reservationData.clear();

    ifstream fileIn(reservationFile, ios::in);

    string date;//����
    string interval;//ʱ���
    string roomId;//�������
    string studentId;//ѧ��ѧ��
    string studentName;//ѧ������
    string status;//ԤԼ״̬

    this->autoSetReservationSize();

    int i = 0;
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
        m_reservationData.insert(make_pair(i+1, singleReservationInformation));
        i++;
    }
}

void reservationClass::updateReservation() {

}

void reservationClass::getSizeOfReservation() {

}

void reservationClass::setReservationSize(int reservationSize) {
    m_reservationSize = reservationSize;
}

void reservationClass::autoSetReservationSize() {
    m_reservationSize = m_reservationData.size();
}
