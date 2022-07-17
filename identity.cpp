#include<iostream>

using namespace std;

#include"identity.h"

void identityClass::initComputerRoom() {
    //读取机房文件信息
    ifstream fileIn(computerRoomFile, ios::in);
    computerRoomClass computerRoom;
    int roomNumber, maxVolume;
    while (fileIn >> roomNumber && fileIn >> maxVolume) {
        computerRoom.setRoomNumberAndMaxVolume(roomNumber, maxVolume);
        v_computerRooms.push_back(computerRoom);
    }
    fileIn.close();

}
