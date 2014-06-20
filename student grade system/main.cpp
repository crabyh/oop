//
//  main.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "head.h"
#include "grades.h"
#include "courses.h"
#include "students.h"

void split(const string& src, const string& separator, vector<string>& dest)//以分隔符拆分字符串函数
{
	string str = src;
	string substring;
	string::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator, start);
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, index);
			if (start == string::npos) return;
		}
	} while (index != string::npos);

	//最后一个标记
	substring = str.substr(start);
	dest.push_back(substring);
}

students read_find_student(int flag, string sid, string location, string object[])//读取构建students类
{
	fstream f(location, ios::_Nocreate);//以非覆盖形式打开文件
	if (!f){//抛出文件操作异常
		throw file_exception();
	}
	string info;
	int count;
	int flag1 = 0;
	while (getline(f, info)){//逐行读取文件信息
		if (flag == 0){//显示信息
			cout << info << endl;
		}
		else{//根据文件信息重构对象
			vector<string> d;
			vector<string>::iterator p;
			split(info, " ", d);
			count = 0;
			for (p = d.begin(); p != d.end(); ++p)
			{
				object[count++] = *p;
			}
			if (object[0] == sid){//找到对应信息则重构对象
				if (flag == 4){//抛出信息已存在异常
					throw exist_exception();
				}
				students s(object[0], object[1], object[2]);
				return s;
				flag1 = 1;
			}
		}	
	}
	f.close();
	if (flag == 1 && flag1 == 0){//若未找到信息，抛出异常
		throw not_found_exception();
	}
	return *(new students);
}

courses read_find_course(int flag, string cid, string location, string object[])//读取构建courses类
{
	fstream f(location, ios::_Nocreate);//以非覆盖形式打开文件
	if (!f){//抛出文件操作异常
		throw file_exception();
	}
	string info;
	int count;
	int flag1 = 0;
	while (getline(f, info)){//逐行读取文件信息
		if (flag == 0){//显示信息
			cout << info << endl;
		}
		else{//根据文件信息重构对象
			vector<string> d;
			vector<string>::iterator p;
			split(info, " ", d);
			count = 0;
			for (p = d.begin(); p != d.end(); ++p)
			{
				object[count++] = *p;
			}
			if (object[0] == cid){//找到对应信息则重构对象
				if (flag == 4){//抛出信息已存在异常
					throw exist_exception();
				}
				courses c(object[0], object[1], atof(object[3].c_str()), object[2]);
				return c;
				flag1 = 1;
			}
		}	
	}
	f.close();
	if (flag == 1 && flag1 == 0){//若未找到信息，抛出异常
		throw not_found_exception();
	}
	return *(new courses);
}

vector<grades> read_find_grade(int flag, string gid, string cid, string sid, string location, string object[], short grade = 0)//读取构建grades类
{
	fstream f(location, ios::_Nocreate);//以非覆盖形式打开文件
	fstream f1("./grades1.txt", ios::out);//以输出到文件形式打开文件并清空
	if (!f || !f1){//抛出文件操作异常
		throw file_exception();
	}
	string info;
	int count;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	vector<grades> gpt;
	courses *cptemp;
	students *sptemp;
	while (getline(f, info)){//逐行读取文件信息
		if (flag == 0){//显示信息
			cout << info << endl;
		}
		else{
			vector<string> d;
			vector<string>::iterator p;
			split(info, " ", d);
			count = 0;
			for (p = d.begin(); p != d.end(); ++p)
			{
				object[count++] = *p;
			}
			if (flag == 1){//根据文件信息重构对象，并输出到另一文件
				cptemp = new courses;
				sptemp = new students;
				string courtemp[4], stutemp[3];
				*cptemp = read_find_course(1, object[1], "./courses.txt", courtemp);
				*sptemp = read_find_student(1, object[5], "./students.txt", stutemp);
				grades g(object[0], atoi(object[8].c_str()), cptemp, sptemp);
				if (object[0] == gid){
					g.set_grade(grade);
					gpt.push_back(g);
					flag1 = 1;
				}
				f1 << g.get_grade_info() << endl;
			}
			else if (flag == 2 && object[1] == cid){//找到对应信息则重构对象
				cptemp = new courses;
				sptemp = new students;
				string courtemp[4], stutemp[3];
				*cptemp = read_find_course(1, object[1], "./courses.txt", courtemp);
				*sptemp = read_find_student(1, object[5], "./students.txt", stutemp);
				grades g(object[0], atoi(object[8].c_str()), cptemp, sptemp);
				gpt.emplace_back(g);
				flag2 = 1;
			}
			else if (flag == 3 && object[5] == sid){//找到对应信息则重构对象
				cptemp = new courses;
				sptemp = new students;
				string courtemp[4], stutemp[3];
				*cptemp = read_find_course(1, object[1], "./courses.txt", courtemp);
				*sptemp = read_find_student(1, object[5], "./students.txt", stutemp);
				grades g(object[0], atoi(object[8].c_str()), cptemp, sptemp);
				gpt.emplace_back(g);
				flag3 = 1;
			}
			else if (flag == 4){
				if (object[0] == gid){//抛出信息已存在异常
					throw exist_exception();
				}
			}
		}
	}
	f.close();
	f1.close();
	if (flag == 1 && flag1 ==1){//删除原文件，将改写后文件重命名为原文件名以实现文件改写
		DeleteFile("./grades.txt");
		rename("./grades1.txt", "./grades.txt");
	}
	else if(flag == 1 && flag1 == 0){//抛出未找到信息异常
		DeleteFile("./grades1.txt");
		throw not_found_exception();
	}
	else{//删除改写文件
		DeleteFile("./grades1.txt");
	}
	if (flag == 3 && flag3 == 0){//若未找到信息，抛出异常
		throw not_found_exception();
	}
	if (flag == 2 && flag2 == 0){//若未找到信息，抛出异常
		throw not_found_exception();
	}
	return gpt;
}

int main()
{
	try{//检测登录异常
		cout << "*****************" << endl;
		cout << "学生成绩管理系统" << endl;
		cout << "*****************" << endl;
		cout << "请输入密码：（密码什么的才不可能是admin）" << endl;
		string password;
		cin >> password;
		if (password != "admin"){//密码错误，抛出异常
			throw login_exception();
		}
	}
	catch (login_exception &){//捕捉登录异常
		cout << "密码错误！！" << endl;
		system("pause");
		exit(0);
	}
	while (1){
		try{//检测运行异常
			system("cls");//清空屏幕
			cout << "*****************" << endl;//功能界面
			cout << "学生成绩管理系统" << endl;
			cout << "*****************" << endl;
			cout << "0) 退出系统" << endl;
			cout << "1) 查看学生信息" << endl;
			cout << "2) 添加学生信息" << endl;
			cout << "3) 查看课程信息" << endl;
			cout << "4) 添加课程信息" << endl;
			cout << "5) 查看成绩信息" << endl;
			cout << "6) 添加成绩信息" << endl;
			cout << "7) 修改成绩信息" << endl;
			cout << "8) 查看学生所有成绩" << endl;
			cout << "9) 查看课程平均成绩" << endl;

			students st;
			courses ct;
			vector<grades> gv;
			string stu[3], cour[4], grad[9];
			string gid, cid, sid;
			int swit;
			cin >> swit;
			system("cls");
			switch (swit)//选择功能
			{
			case 0:
			{
					  exit(0); break;
			}
			case 1://查看学生信息
			{
					  cout << "学生ID 姓名 性别"<<endl;
					  read_find_student(0, sid, "./students.txt", stu);//读入文件信息
					  break;
			}
			case 2://添加学生信息
			{
					  fstream fs("./students.txt", ios::app);//追加写入方式打开文件
					  if (!fs){//抛出文件操作异常
						  throw file_exception();
					  }
					  string sid, sname, sgender;
					  cout << "输入学生号、姓名、性别，输入0返回上一级" << endl;
					  cout << "例如：s01 maoyuhan male" << endl;
					  cin >> sid;
					  if (sid == "0"){
						  break;
					  }
					  cin >> sname >> sgender;
					  if (sid[0] != 's' || (sgender != "male" && sgender != "female")) {//抛出输入格式异常
						  throw input_exception();
					  }
					  read_find_student(4, sid, "./students.txt", stu);//检测信息是否已存在
					  students s(sid, sname, sgender);//重构students类对象
					  fs << s.get_student_info() << endl;
					  fs.close();
					  cout << "添加成功！" << endl;
					  cout << s.get_student_info() << endl;
					  break;
			}
			case 3: //查看课程信息
			{
					  cout << "课程ID 课程名称 任课老师 学分" << endl;
					  read_find_course(0, cid, "./courses.txt", cour);//读入文件信息
					  break;
			}
			case 4://添加课程信息
			{
					  fstream fc("./courses.txt", ios::app);//追加写入方式打开文件
					  if (!fc){//抛出文件操作异常
						  throw file_exception();
					  }
					  cout << "输入课程号、课程名称、学分、老师，输入0返回上一级" << endl;
					  cout << "例如：c01 oop hulanqing 2.5" << endl;
					  string cid, cname, ct;
					  double ccredit;
					  cin >> cid;
					  if (cid == "0"){
						  break;
					  }
					  cin >> cname >> ct >> ccredit;
					  if (cid[0] != 'c'){//抛出输入格式异常
						  throw input_exception();
					  }
					  read_find_course(4, cid, "./courses.txt", cour);//检测信息是否已存在
					  courses c(cid, cname, ccredit, ct);//重构courses类对象
					  fc << c.get_course_info() + ' ' + to_string(c.get_credit()) << endl;
					  fc.close();
					  cout << "添加成功！" << endl;
					  cout << c.get_course_info() + ' ' + to_string(c.get_credit()) << endl;
					  break;
			}
			case 5://查看成绩信息
			{
					  cout << "成绩编号 课程ID 课程名称 任课老师 学分 学生ID 学生姓名 性别 成绩" << endl;
					  read_find_grade(0, gid, cid, sid, "./grades.txt", grad);//读入文件信息
					  break;
			}
			case 6://添加成绩信息
			{
					  fstream fg("./grades.txt", ios::app);//追加写入方式打开文件
					  if (!fg){//抛出文件操作异常
						  throw file_exception();
					  }
					  short grade;
					  cout << "输入成绩号、成绩、课程号、学生号，输入0返回上一级" << endl;
					  cout << "例如：g01 89 c01 s01 " << endl;
					  cin >> gid;
					  if (gid == "0"){
						  break;
					  }
					  cin >> grade >> cid >> sid;
					  if (gid[0] != 'g' || cid[0] != 'c' || sid[0] != 's' || grade < 0 || grade > 100){//抛出输入格式异常
						  throw input_exception();
					  }
					  st = read_find_student(1, sid, "./students.txt", stu);//重构students类对象
					  ct = read_find_course(1, cid, "./courses.txt", cour);//重构courses类对象
					  read_find_grade(4, gid, cid, sid, "./grades.txt", grad);//检测信息是否已存在
					  grades g(gid, grade, &ct, &st);//重构grades类对象
					  fg << g.get_grade_info() << endl;
					  fg.close();
					  cout << "添加成功！" << endl;
					  cout << g.get_grade_info() << endl;
					  break;
			}
			case 7://修改成绩信息
			{
					  short grade;
					  cout << "输入成绩号、新成绩，输入0返回上一级" << endl;
					  cout << "例如：g01 89" << endl;
					  cin >> gid;
					  if (gid == "0"){
						  break;
					  }
					  cin >> grade;
					  if (gid[0] != 'g' || grade < 0 || grade > 100){//抛出输入格式异常
						  throw input_exception();
					  }
					  gv = read_find_grade(1, gid, cid, sid, "./grades.txt", grad, grade);//修改文件信息
					  cout << "修改成功！" << endl;
					  cout << gv.data()->get_grade_info() << endl;
					  break;
			}
			case 8://查看学生所有成绩
			{
					  cout << "输入学生号，输入0返回上一级" << endl;
					  cout << "例如：s01" << endl;
					  cin >> sid;
					  if (sid == "0"){
						  break;
					  }
					  if (sid[0] != 's'){//抛出输入格式异常
						  throw input_exception();
					  }
					  st = read_find_student(1, sid, "./students.txt", stu);//重构students类对象
					  cout << st.get_student_info() << endl;
					  gv = read_find_grade(3, gid, cid, sid, "./grades.txt", grad);//返回grades类vector
					  st.add_grade_to_student(gv);//加入某学生所有成绩
					  cout << st.get_all_grade();
					  cout << "均绩：" << st.get_GPA() << endl;
					  break;
			}
			case 9://查看课程平均成绩
			{
					  cout << "输入课程号，输入0返回上一级" << endl;
					  cout << "例如：c01" << endl;
					  cin >> cid;
					  if (cid == "0"){
						  break;
					  }
					  if (cid[0] != 'c'){//抛出输入格式异常
						  throw input_exception();
					  }
					  ct = read_find_course(1, cid, "./courses.txt", cour);//重构courses类对象
					  cout << ct.get_course_info() + ' ' + to_string(ct.get_credit()) << endl;
					  gv = read_find_grade(2, gid, cid, sid, "./grades.txt", grad);//返回grades类vector
					  ct.add_grade_to_course(gv);//加入某课程所有成绩
					  cout << "平均分：" << ct.get_course_average() << endl;
					  break;
			}
			default: throw input_exception();//抛出输入格式异常
			}//switch
		} // try
		catch (input_exception &){//捕捉输入格式异常
			cout << "输入格式错误！！" << endl;
		}
		catch (file_exception &){//捕捉文件操作异常
			cout << "文件存储失败！" << endl;
		}
		catch (not_found_exception &){//捕捉未找到信息异常
			cout << "未找到相关信息！" << endl;
		}
		catch (exist_exception &){
			cout << "相关信息已存在！" << endl;
		}
		system("pause");
	}//while
	return 0;
}
