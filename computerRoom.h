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

    int m_roomNumber;
    int m_maxVolume;
};