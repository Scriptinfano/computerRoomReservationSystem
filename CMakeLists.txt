cmake_minimum_required(VERSION 3.22)
project(computerRoomReservationSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(computerRoomReservationSystem reservationSystemMain.cpp identity.h student.cpp student.h teacher.cpp teacher.h administrator.cpp administrator.h globalFile.h systemManager.cpp systemManager.h computerRoom.h identity.cpp reservation.cpp reservation.h globalFunction.cpp globalFunction.h identityName.h)
