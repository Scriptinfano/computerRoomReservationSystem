//由于不同的身份会用到不同的文件操作，所以将所有的文件名定义到一个全局的头文件中
#pragma once
#include<string>

const std::string administratorFile= R"(D:/ClionProjects/computerRoomReservationSystem/txtFiles/administrator.txt)";
const std::string computerRoomFile=R"(D:/ClionProjects/computerRoomReservationSystem/txtFiles/computerRoom.txt)";
const std::string reservationFile=R"(D:/ClionProjects/computerRoomReservationSystem/txtFiles/reservation.txt)";
const std::string teacherFile= R"(D:/ClionProjects/computerRoomReservationSystem/txtFiles/teacher.txt)";
const std::string studentFile=R"(D:/ClionProjects/computerRoomReservationSystem/txtFiles/student.txt)";
