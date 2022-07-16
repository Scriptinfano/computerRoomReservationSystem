//
// Created by USER on 14/07/2022.
//

#include "administrator.h"
#include "globalFile.h"
#include <fstream>
#include <vector>

administratorClass::administratorClass(string name, string password) {
    this->setNamePassword(name,password);
    this->initVector();
    this->initComputerRoom();//只需要初始化一次机房信息，因为机房的信息和老师及学生的信息不同，其不需要增删改查
}

//显示管理员子菜单
void administratorClass::showSubMenu() {
    cout << "欢迎管理员--" <<this->getName() << "登录!" << endl;
    cout << "=======================请输入您的选择=====================" << endl;
    cout << "|                       1 添加账号                      | " << endl;
    cout << "|                       2 查看账号                      |" << endl;
    cout << "|                       3 查看机房                      |" << endl;
    cout << "|                       4 清空预约                      |" << endl;
    cout << "|                       5 退出登录                      |" << endl;
    cout << "========================================================" << endl;
    cout << "请输入您的选择";

}

//添加账号
void administratorClass::addAccount() {
    cout << "请输入添加账号的类型：" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;
    cout << "3、返回" << endl;

    string fileName;
    string inputHint;//输入id的提示，因为身份不同，id号可分为职工号和学号，所以提示语不同
    string reInputHint;//当id号重复时的提示
    string select;//用户做出选择时的输入代号
    while (true) {
        getline(cin, select);
        if (select == "1") {
            fileName = studentFile;
            inputHint = "请输入学号：";
            reInputHint = "您输入的学号与现有的学号重复，请重新输入";
            break;
        } else if (select == "2") {
            fileName = teacherFile;
            inputHint = "请输入职工号：";
            reInputHint = "您输入的职工号与现有的学号重复，请重新输入";
            break;
        } else if (select == "3") {
            return;
        } else {
            cout << "输入的选项不正确，请重新输入：";
        }
    }

    ifstream fileIn(fileName, ios::in);
    ofstream fileOut(fileName, ios::out | ios::app);
    if (!fileOut.is_open() || !fileIn.is_open()) {
        cout << "文件不存在，打开失败" << endl;
        exit(0);
    }


    int idFromBoard;//用户输入的id
    string nameFromBoard;
    string passwardFromBoard;
    bool judgmentOfRepeatedInput;
    bool judgementOfReInputHint = false;
    do {
        if (judgementOfReInputHint) {
            judgementOfReInputHint = false;
            cout << reInputHint;
        } else {
            cout << inputHint;//输出提示语句
        }
        (cin >> idFromBoard).get();
        judgmentOfRepeatedInput = this->checkRepeatId(idFromBoard, select);
        if (judgmentOfRepeatedInput) {
            judgementOfReInputHint = true;
        }
    } while (judgmentOfRepeatedInput);///注意do while循环后面的分号

    /* 判断是否重复的另一种不需要成员函数checkRepeatId的方法：
     * //检测用户输入的id是否和文件中保存的相同，先将文件中的id读取到vector容器中，再遍历一一对比
    bool judgmentOfRepeatedInput = true;
    bool judgementOfRestartWhileLoop = false;
    bool judgementOfReInputHint = false;
    while (judgmentOfRepeatedInput) {
        if (judgementOfReInputHint) {
            judgementOfReInputHint = false;
            cout << reInputHint;
        } else {
            cout << inputHint;//输出提示语句
        }
        (cin >> idFromBoard).get();
        for (auto idInContainer: ) {
            if (idFromBoard == idInContainer) {
                //返回外层循环开始处
                judgementOfRestartWhileLoop = true;
                break;
            }
        }
        if (judgementOfRestartWhileLoop) {
            judgementOfRestartWhileLoop = false;
            judgementOfReInputHint = true;
            continue;
        }
        judgmentOfRepeatedInput = false;
    }
*/

    cout << "请输入姓名：";
    getline(cin, nameFromBoard);

    cout << "请输入密码：";
    getline(cin, passwardFromBoard);

    fileOut << idFromBoard << " " << nameFromBoard << " " << passwardFromBoard << " " << endl;
    cout << "添加成功" << endl;

    this->initVector();//刚刚添加了一个人，但是只写入了文件没有写入容器，通过此函数更新一下容器，让容器重新读取文件中的数据

    system("pause");
    system("cls");
    fileOut.close();
}

//查看账号
//以下两个函数是在用for_each()输出容器中学生类对象，机房类对象，老师类对象时的回调函数
void printStudent(studentClass &student) {
    cout << "学号：" << student.getStudentId() << " 姓名：" << student.getName() << " 密码：" << student.getPassword() << endl;
}

void printTeacher(teacherClass &teacher) {
    cout << "职工号：" << teacher.getEmployeeId() << " 姓名：" << teacher.getName() << " 密码：" << teacher.getPassword() << endl;

}

void printComputerRoom(computerRoomClass &computerRoom) {
    cout << "机房编号：" << computerRoom.getRoomNumber() << " 机房最大容量：" << computerRoom.getMaxVolume() << endl;
}

void administratorClass::showAccount() {
    string select;

    while (true) {
        cout << "1、查看所有学生" << endl;
        cout << "2、查看所有教师" << endl;
        cout << "3、返回" << endl;
        cout << "请选择查看内容：";
        getline(cin, select);
        if (select == "1") {
            //查看学生
            for_each(v_students.begin(), v_students.end(), printStudent);
            break;
        } else if (select == "2") {
            //查看教师
            for_each(v_teachers.begin(), v_teachers.end(), printTeacher);
            break;
        } else if (select == "3") {
            return;
        } else {
            cout << "输入的选项不正确，请重新输入" << endl;
            continue;
        }
    }
    system("pause");
    system("cls");
}

//查看机房
void administratorClass::showComputerRoom() {
    cout << "机房信息如下：" << endl;
    for_each(v_computerRooms.begin(), v_computerRooms.end(), printComputerRoom);
    system("pause");
    system("cls");
}

//清空预约
void administratorClass::clearReservation() {
    ofstream fileOut(reservationFile, ios::trunc);
    fileOut.close();
    cout << "清空成功" << endl;
    system("pause");
    system("cls");
}

void administratorClass::operateSubMenu() {
    string select;
    administratorClass *administrator = (administratorClass *) this;//调用这个函数的是父类指针，需要将父类指针强转为子类指针才能调用子类特有的接口函数
    while (true) {
        this->showSubMenu();//显示子菜单
        getline(cin, select);
        if (select == "1") {
            //添加账号
            administrator->addAccount();

        } else if (select == "2") {
            //查看账号
            administrator->showAccount();

        } else if (select == "3") {
            //查看机房
            administrator->showComputerRoom();

        } else if (select == "4") {
            //清空预约
            administrator->clearReservation();
        } else if (select == "5") {
            //退出登录
            administrator->logout();
            return;
        } else {
            cout << "输入的选项错误，请输入正确的选项" << endl;
            system("pause");
            system("cls");
        }
    }
}

void administratorClass::initVector() {
    v_teachers.clear();
    v_students.clear();
    v_computerRooms.clear();

    //由于id,name,password等属性在各类中是私有变量，不能直接将文件中的信息放在其中，所以先将数据读到临时变量中，再通过接口函数将数据传入对象
    int id;
    string name;
    string password;


    //读取学生文件中的信息
    ifstream fileIn;
    fileIn.open(studentFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "打开失败" << endl;
        exit(0);
    }
    studentClass student;
    while (fileIn >> id && fileIn >> name && fileIn >> password) {
        student.setStudentId(id);
        student.setNamePassword(name,password);
        v_students.push_back(student);
    }
    fileIn.close();

    //读取老师文件信息
    fileIn.open(teacherFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "打开失败" << endl;
        exit(0);
    }
    teacherClass teacher;
    while (fileIn >>id && fileIn >>name && fileIn >> password) {
        teacher.setEmployeeId(id);
        teacher.setNamePassword(name,password);
        v_teachers.push_back(teacher);
    }
    fileIn.close();
}

//检测重复 参数（传入的用户输入的id，传入的身份类型） 返回值：true代表有重复,false代表无重复
bool administratorClass::checkRepeatId(int id, string identity) {
    if (identity == "1")//检测学生的学号
    {
        for (auto studentInContainer: v_students) {
            if (id == studentInContainer.getStudentId())//有重复的情况
            {
                return true;
            }
        }
    } else {
        for (auto teacherInContainer: v_teachers) {
            if (id == teacherInContainer.getEmployeeId()) {
                return true;
            }
        }
    }
    return false;//代表没有重复
}

void administratorClass::initComputerRoom() {
//读取机房文件信息
    ifstream fileIn(computerRoomFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "文件不存在" << endl;
        exit(0);
    }

    fileIn.open(computerRoomFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "打开失败" << endl;
        exit(0);
    }
    computerRoomClass computerRoom;
    int roomNumber,maxVolume;
    while (fileIn >>roomNumber && fileIn >> maxVolume) {
        computerRoom.setRoomNumberAndMaxVolume(roomNumber,maxVolume);
        v_computerRooms.push_back(computerRoom);
    }
    fileIn.close();
}
