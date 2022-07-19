//
// Created by USER on 17/07/2022.
//

#include "globalFunction.h"

int fileIsEmpty(ifstream &fileIn) {
    if (fileIn.is_open()) {
        fileIn.seekg(0, ios::end);
        streampos position = fileIn.tellg();
        fileIn.seekg(0, ios::beg);//��ִ�д����֮ǰ���ļ�ָ�����ļ�ĩβ�����»ص�reservationClass�Ĺ��캯��Ҫ���ļ��е���Ϣ��������ʱ���������ݣ����Ҫ���ļ�ָ������ָ���ļ���ͷλ��
        if ((int) position == 0) {
//�ļ�Ϊ�յ����
            return 1; //
        } else
            return 0;//�ļ���Ϊ�յ����
    } else {
        return -1;//������ļ�������û�к��ļ�����
    }
}

void reservationInformationToMap(string &reservationUnit, map<string, string> &singleReservationInformation) {
    int colonPosition = reservationUnit.find(":");//find��������ð�����ַ����е��±�
    if (colonPosition != -1) {
        string key = reservationUnit.substr(0, colonPosition);//substr�ĵ�һ�������Ǵ��±�Ϊ�����ַ���ʼ��ȡ�Ӵ����ڶ��������ǽؼ����ַ�
        string value = reservationUnit.substr(colonPosition + 1, reservationUnit.size() - 1 - colonPosition);
        singleReservationInformation.insert(make_pair(key, value));

    } else {
        cout << "δ�ҵ�ð��" << endl;
        exit(0);
    }

}

