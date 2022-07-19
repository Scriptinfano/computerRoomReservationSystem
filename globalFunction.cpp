//
// Created by USER on 17/07/2022.
//

#include "globalFunction.h"

int fileIsEmpty(ifstream &fileIn) {
    if (fileIn.is_open()) {
        fileIn.seekg(0, ios::end);
        streampos position = fileIn.tellg();
        fileIn.seekg(0, ios::beg);//在执行此语句之前，文件指针在文件末尾，导致回到reservationClass的构造函数要将文件中的信息读入容器时读不出数据，因此要将文件指针重新指向文件开头位置
        if ((int) position == 0) {
//文件为空的情况
            return 1; //
        } else
            return 0;//文件不为空的情况
    } else {
        return -1;//传入的文件流对象没有和文件关联
    }
}

void reservationInformationToMap(string &reservationUnit, map<string, string> &singleReservationInformation) {
    int colonPosition = reservationUnit.find(":");//find函数返回冒号在字符串中的下标
    if (colonPosition != -1) {
        string key = reservationUnit.substr(0, colonPosition);//substr的第一个参数是从下标为几的字符开始截取子串，第二个参数是截几个字符
        string value = reservationUnit.substr(colonPosition + 1, reservationUnit.size() - 1 - colonPosition);
        singleReservationInformation.insert(make_pair(key, value));

    } else {
        cout << "未找到冒号" << endl;
        exit(0);
    }

}

