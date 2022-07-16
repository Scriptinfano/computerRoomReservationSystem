//
#pragma once

#include<iostream>

using namespace std;

class computerRoomClass {
public:
    computerRoomClass() {
        m_maxVolume = 0;
        m_roomNumber = 0;
    }

    int getRoomNumber() { return m_roomNumber; }

    int getMaxVolume() { return m_maxVolume; }



private:

    int m_roomNumber;
    int m_maxVolume;
};