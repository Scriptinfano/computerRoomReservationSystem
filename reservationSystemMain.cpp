/*程序设计说明：
 *
 * 一、身份简介（三种身份使用该程序）
 * 1、学生代表：申请使用机房
 * 2、教师：审核学生的预约申请
 * 3、管理员：给学生，教师创建账号
 * 二、机房简介（总共有三间机房）
 * 1、1号机房：最大容量20人
 * 2、2号机房：最大容量50人
 * 3、3号机房：最大容量100人
 * 三、申请简介
 * 1、申请的订单每周由管理员负责清空
 * 2、学生可以预约未来一周内的机房使用，预约的日期为周一到周五，预约时需要选择预约时段（上午和下午）
 * 3、教师来审核预约，依据实际情况审核预约通过还是不通过
 * 四、系统具体要求
 * 1、首先进入登录界面，可登录的身份有学生代表、老师、管理员
 * 2、每个身份需要验证之后才能进入子菜单：
 *  学生要输入：学号、姓名、登录密码
 *  老师要输入：职工号、姓名、登录密码
 *  管理员要输入：管理员姓名、登录密码
 * 3、学生的具体功能：
 *  申请预约、
 *  查看自己的预约状态、
 *  查看所有的预约信息和预约状态、
 *  取消预约（不管是预约成功还是审核中的预约）、
 *  退出登录
 * 4、教师的具体功能：
 *  查看所有预约的信息以及预约状态、
 *  审核预约、
 *  注销登录
 * 5、管理员的具体功能：
 *  添加学生或老师的账号（需要检测学生编号或教师职工号是否重复）、
 *  查看学生或教师账号的所有信息、
 *  查看机房信息、
 *  清空所有预约记录、
 *  注销登录
 * */


#include <iostream>
#include<string>
#include"systemManager.h"
#include"globalFile.h"

using namespace std;

int main() {
    systemManager manager;
    string select;
    while (true) {
        manager.showMenu();
        getline(cin,select);
        //根据用户选择实现不同接口
        if (select == "1") {
            //选择学生代表
            manager.login(studentFile, student);
        } else if (select == "2") {
            //选择老师
            manager.login(teacherFile, teacher);
        } else if (select == "3") {
            //选择管理员
            manager.login(administratorFile,administrator);

        } else if (select == "0") {
            //退出
            manager.exitSystem();

        } else {
            //输入不合法
            cout << "输入有误，重新输入选项：" << endl;
            system("pause");
            system("cls");
        }
    }

}
