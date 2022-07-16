//
// Created by USER on 14/07/2022.
//

#include "administrator.h"
#include "globalFile.h"
#include <fstream>
#include<vector>

administratorClass::administratorClass(string name, string password) {
    this->setNamePassword(name,password);
    this->initVector();
    this->initComputerRoom();//ֻ��Ҫ��ʼ��һ�λ�����Ϣ����Ϊ��������Ϣ����ʦ��ѧ������Ϣ��ͬ���䲻��Ҫ��ɾ�Ĳ�
}

//��ʾ����Ա�Ӳ˵�
void administratorClass::showSubMenu() {
    cout << "��ӭ����Ա--" << this->m_name << "��¼!" << endl;
    cout << "=======================����������ѡ��=====================" << endl;
    cout << "|                       1 ����˺�                      | " << endl;
    cout << "|                       2 �鿴�˺�                      |" << endl;
    cout << "|                       3 �鿴����                      |" << endl;
    cout << "|                       4 ���ԤԼ                      |" << endl;
    cout << "|                       5 �˳���¼                      |" << endl;
    cout << "========================================================" << endl;
    cout << "����������ѡ��";

}

//����˺�
void administratorClass::addAccount() {
    cout << "����������˺ŵ����ͣ�" << endl;
    cout << "1�����ѧ��" << endl;
    cout << "2�������ʦ" << endl;
    cout << "3������" << endl;

    string fileName;
    string inputHint;//����id����ʾ����Ϊ��ݲ�ͬ��id�ſɷ�Ϊְ���ź�ѧ�ţ�������ʾ�ﲻͬ
    string reInputHint;//��id���ظ�ʱ����ʾ
    string select;//�û�����ѡ��ʱ���������
    while (true) {
        getline(cin, select);
        if (select == "1") {
            fileName = studentFile;
            inputHint = "������ѧ�ţ�";
            reInputHint = "�������ѧ�������е�ѧ���ظ�������������";
            break;
        } else if (select == "2") {
            fileName = teacherFile;
            inputHint = "������ְ���ţ�";
            reInputHint = "�������ְ���������е�ѧ���ظ�������������";
            break;
        } else if (select == "3") {
            return;
        } else {
            cout << "�����ѡ���ȷ�����������룺";
        }
    }

    ifstream fileIn(fileName, ios::in);
    ofstream fileOut(fileName, ios::out | ios::app);
    if (!fileOut.is_open() || !fileIn.is_open()) {
        cout << "�ļ������ڣ���ʧ��" << endl;
        exit(0);
    }


    int idFromBoard;//�û������id
    string nameFromBoard;
    string passwardFromBoard;
    bool judgmentOfRepeatedInput;
    bool judgementOfReInputHint = false;
    do {
        if (judgementOfReInputHint) {
            judgementOfReInputHint = false;
            cout << reInputHint;
        } else {
            cout << inputHint;//�����ʾ���
        }
        (cin >> idFromBoard).get();
        judgmentOfRepeatedInput = this->checkRepeatId(idFromBoard, select);
        if (judgmentOfRepeatedInput) {
            judgementOfReInputHint = true;
        }
    } while (judgmentOfRepeatedInput);///ע��do whileѭ������ķֺ�

    /* �ж��Ƿ��ظ�����һ�ֲ���Ҫ��Ա����checkRepeatId�ķ�����
     * //����û������id�Ƿ���ļ��б������ͬ���Ƚ��ļ��е�id��ȡ��vector�����У��ٱ���һһ�Ա�
    bool judgmentOfRepeatedInput = true;
    bool judgementOfRestartWhileLoop = false;
    bool judgementOfReInputHint = false;
    while (judgmentOfRepeatedInput) {
        if (judgementOfReInputHint) {
            judgementOfReInputHint = false;
            cout << reInputHint;
        } else {
            cout << inputHint;//�����ʾ���
        }
        (cin >> idFromBoard).get();
        for (auto idInContainer: ) {
            if (idFromBoard == idInContainer) {
                //�������ѭ����ʼ��
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

    cout << "������������";
    getline(cin, nameFromBoard);

    cout << "���������룺";
    getline(cin, passwardFromBoard);

    fileOut << idFromBoard << " " << nameFromBoard << " " << passwardFromBoard << " " << endl;
    cout << "��ӳɹ�" << endl;

    this->initVector();//�ո������һ���ˣ�����ֻд�����ļ�û��д��������ͨ���˺�������һ�����������������¶�ȡ�ļ��е�����

    system("pause");
    system("cls");
    fileOut.close();
}

//�鿴�˺�
//������������������for_each()���������ѧ������󣬻����������ʦ�����ʱ�Ļص�����
void printStudent(studentClass &student) {
    cout << "ѧ�ţ�" << student.m_studentId << " ������" << student.m_name << " ���룺" << student.m_password << endl;
}

void printTeacher(teacherClass &teacher) {
    cout << "ְ���ţ�" << teacher.m_employeeId << " ������" << teacher.m_name << " ���룺" << teacher.m_password << endl;

}

void printComputerRoom(computerRoomClass &computerRoom) {
    cout << "������ţ�" << computerRoom.m_roomNumber << " �������������" << computerRoom.m_maxVolume << endl;
}

void administratorClass::showAccount() {
    string select;

    while (true) {
        cout << "1���鿴����ѧ��" << endl;
        cout << "2���鿴���н�ʦ" << endl;
        cout << "3������" << endl;
        cout << "��ѡ��鿴���ݣ�";
        getline(cin, select);
        if (select == "1") {
            //�鿴ѧ��
            for_each(v_students.begin(), v_students.end(), printStudent);
            break;
        } else if (select == "2") {
            //�鿴��ʦ
            for_each(v_teachers.begin(), v_teachers.end(), printTeacher);
            break;
        } else if (select == "3") {
            return;
        } else {
            cout << "�����ѡ���ȷ������������" << endl;
            continue;
        }
    }
    system("pause");
    system("cls");
}

//�鿴����
void administratorClass::showComputerRoom() {
    cout << "������Ϣ���£�" << endl;
    for_each(v_computerRooms.begin(), v_computerRooms.end(), printComputerRoom);
    system("pause");
    system("cls");
}

//���ԤԼ
void administratorClass::clearReservation() {
    ofstream fileOut(reservationFile, ios::trunc);
    fileOut.close();
    cout << "��ճɹ�" << endl;
    system("pause");
    system("cls");
}

void administratorClass::operateSubMenu() {
    string select;
    administratorClass *administrator = (administratorClass *) this;//��������������Ǹ���ָ�룬��Ҫ������ָ��ǿתΪ����ָ����ܵ����������еĽӿں���
    while (true) {
        this->showSubMenu();//��ʾ�Ӳ˵�
        getline(cin, select);
        if (select == "1") {
            //����˺�
            administrator->addAccount();

        } else if (select == "2") {
            //�鿴�˺�
            administrator->showAccount();

        } else if (select == "3") {
            //�鿴����
            administrator->showComputerRoom();

        } else if (select == "4") {
            //���ԤԼ
            administrator->clearReservation();
        } else if (select == "5") {
            //�˳���¼
            administrator->logout();
            return;
        } else {
            cout << "�����ѡ�������������ȷ��ѡ��" << endl;
            system("pause");
            system("cls");
        }
    }
}

void administratorClass::initVector() {
    v_teachers.clear();
    v_students.clear();
    v_computerRooms.clear();

    //��ȡѧ���ļ��е���Ϣ
    ifstream fileIn;
    fileIn.open(studentFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "��ʧ��" << endl;
        exit(0);
    }
    studentClass student;
    while (fileIn >> student.m_studentId && fileIn >> student.m_name && fileIn >> student.m_password) {
        v_students.push_back(student);
    }
    fileIn.close();

    //��ȡ��ʦ�ļ���Ϣ
    fileIn.open(teacherFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "��ʧ��" << endl;
        exit(0);
    }
    teacherClass teacher;
    while (fileIn >> teacher.m_employeeId && fileIn >> teacher.m_name && fileIn >> teacher.m_password) {
        v_teachers.push_back(teacher);
    }
    fileIn.close();
}

//����ظ� ������������û������id�������������ͣ� ����ֵ��true�������ظ�,false�������ظ�
bool administratorClass::checkRepeatId(int id, string identity) {
    if (identity == "1")//���ѧ����ѧ��
    {
        for (auto studentInContainer: v_students) {
            if (id == studentInContainer.m_studentId)//���ظ������
            {
                return true;
            }
        }
    } else {
        for (auto teacherInContainer: v_teachers) {
            if (id == teacherInContainer.m_employeeId) {
                return true;
            }
        }
    }
    return false;//����û���ظ�
}

void administratorClass::initComputerRoom() {
//��ȡ�����ļ���Ϣ
    ifstream fileIn(computerRoomFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "�ļ�������" << endl;
        exit(0);
    }

    fileIn.open(computerRoomFile, ios::in);
    if (!fileIn.is_open()) {
        cout << "��ʧ��" << endl;
        exit(0);
    }
    computerRoomClass computerRoom;
    while (fileIn >> computerRoom.m_roomNumber && fileIn >> computerRoom.m_maxVolume) {
        v_computerRooms.push_back(computerRoom);
    }
    fileIn.close();
}
