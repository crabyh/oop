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

void split(const string& src, const string& separator, vector<string>& dest)//以分隔符拆分字符串
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

	//the last token
	substring = str.substr(start);
	dest.push_back(substring);
}

students read_find_student(int flag, string sid, string location, string object[])//读取构建students类
{
	fstream f(location, ios::_Nocreate);
	string info;
	int count;
	while (getline(f, info)){
		if (flag == 0){
			cout << info << endl;
		}
		else if(flag == 1){
			vector<string> d;
			vector<string>::iterator p;
			split(info, " ", d);
			count = 0;
			for (p = d.begin(); p != d.end(); ++p)
			{
				object[count++] = *p;
			}
			if (object[0] == sid){
				students s(object[0], object[1], object[2]);
				return s;
			}
		}	
	}
	f.close();
	return *(new students);
}

courses read_find_course(int flag, string cid, string location, string object[])//读取构建courses类
{
	fstream f(location, ios::_Nocreate);
	string info;
	int count;
	while (getline(f, info)){
		if (flag == 0){
			cout << info << endl;
		}
		else if(flag == 1){
			vector<string> d;
			vector<string>::iterator p;
			split(info, " ", d);
			count = 0;
			for (p = d.begin(); p != d.end(); ++p)
			{
				object[count++] = *p;
			}
			if (object[0] == cid){
				courses c(object[0], object[1], atof(object[3].c_str()), object[2]);
				return c;
				break;
			}
		}	
	}
	f.close();
	return *(new courses);
}

vector<grades> read_find_grade(int flag, string gid, string cid, string sid, string location, string object[], short grade = 0)//读取构建grades类
{
	fstream f(location, ios::_Nocreate);
	fstream f1("./grades1.txt", ios::out);
	string info;
	int count;
	vector<grades> gpt;
	courses *cptemp;
	students *sptemp;
	while (getline(f, info)){
		if (flag == 0){
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
			if (flag == 1){
				cptemp = new courses;
				sptemp = new students;
				string courtemp[4], stutemp[3];
				*cptemp = read_find_course(1, object[1], "./courses.txt", courtemp);
				*sptemp = read_find_student(1, object[5], "./students.txt", stutemp);
				grades g(object[0], atoi(object[8].c_str()), cptemp, sptemp);
				if (object[0] == gid){
					g.set_grade(grade);
					gpt.push_back(g);
				}
				f1 << g.get_grade_info() << endl;
			}
			else if (flag == 2 && object[1] == cid){
				cptemp = new courses;
				sptemp = new students;
				string courtemp[4], stutemp[3];
				*cptemp = read_find_course(1, object[1], "./courses.txt", courtemp);
				*sptemp = read_find_student(1, object[5], "./students.txt", stutemp);
				grades g(object[0], atoi(object[8].c_str()), cptemp, sptemp);
				gpt.emplace_back(g);
			}
			else if (flag == 3 && object[5] == sid){
				cptemp = new courses;
				sptemp = new students;
				string courtemp[4], stutemp[3];
				*cptemp = read_find_course(1, object[1], "./courses.txt", courtemp);
				*sptemp = read_find_student(1, object[5], "./students.txt", stutemp);
				grades g(object[0], atoi(object[8].c_str()), cptemp, sptemp);
				gpt.emplace_back(g);
			}
		}
	}
	f.close();
	f1.close();
	if (flag == 1){
		DeleteFile("./grades.txt");
		rename("./grades1.txt", "./grades.txt");
	}
	else{
		DeleteFile("./grades1.txt");
	}
	return gpt;
}

int main()
{
	try{
		cout << "*****************" << endl;
		cout << "学生成绩管理系统" << endl;
		cout << "*****************" << endl;
		cout << "请输入密码：（密码什么的才不可能是admin）" << endl;
		string password;
		cin >> password;
		if (password != "admin")
			throw login_exception();
	}
	catch (login_exception &){
		cout << "密码错误！！" << endl;
		system("pause");
		exit(0);
	}
	while (1){
		try{
			system("cls");
			cout << "*****************" << endl;
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
			switch (swit)
			{
			case 0:
			{
					  exit(0); break;
			}
			case 1:
			{
					  cout << "学生ID 姓名 性别"<<endl;
					  read_find_student(0, sid, "./students.txt", stu);
					  break;
			}
			case 2:
			{
					  fstream fs("./students.txt", ios::app);
					  if (!fs) return -1;
					  string sid, sname, sgender;
					  cout << "输入学生号、姓名、性别，输入0返回上一级" << endl;
					  cout << "例如：s01 maoyuhan male" << endl;
					  cin >> sid;
					  if (sid == "0")
						  break;
					  cin >> sname >> sgender;
					  students s(sid, sname, sgender);
					  fs << s.get_student_info() << endl;
					  fs.close();
					  cout << "添加成功！" << endl;
					  cout << s.get_student_info() << endl;
					  break;
			}
			case 3:
			{
					  cout << "课程ID 课程名称 任课老师 学分" << endl;
					  read_find_course(0, cid, "./courses.txt", cour);
					  break;
			}
			case 4:
			{
					  fstream fc("./courses.txt", ios::app);
					  if (!fc) return -1;
					  cout << "输入课程号、课程名称、学分、老师，输入0返回上一级" << endl;
					  cout << "例如：c01 oop hulanqing 2.5" << endl;
					  string cid, cname, ct;
					  double ccredit;
					  cin >> cid;
					  if (cid == "0")
						  break;
					  cin >> cname >> ccredit >> ct;
					  courses c(cid, cname, ccredit, ct);
					  fc << c.get_course_info() + ' ' + to_string(c.get_credit()) << endl;
					  fc.close();
					  cout << "添加成功！" << endl;
					  cout << c.get_course_info() + ' ' + to_string(c.get_credit()) << endl;
					  break;
			}
			case 5:
			{
					  cout << "成绩编号 课程ID 课程名称 任课老师 学分 学生ID 学生姓名 性别 成绩" << endl;
					  read_find_grade(0, gid, cid, sid, "./grades.txt", grad);
					  break;
			}
			case 6:
			{
					  fstream fg("./grades.txt", ios::app);
					  if (!fg) return -1;
					  short grad;
					  cout << "输入成绩号、成绩、课程号、学生号，输入0返回上一级" << endl;
					  cout << "例如：g01 89 c01 s01 " << endl;
					  cin >> gid;
					  if (gid == "0")
						  break;
					  cin >> grad >> cid >> sid;
					  st = read_find_student(1, sid, "./students.txt", stu);
					  ct = read_find_course(1, cid, "./courses.txt", cour);
					  grades g(gid, grad, &ct, &st);
					  fg << g.get_grade_info() << endl;
					  fg.close();
					  cout << "添加成功！" << endl;
					  cout << g.get_grade_info() << endl;
					  break;
			}
			case 7:
			{
					  short grade;
					  cout << "输入成绩号、新成绩，输入0返回上一级" << endl;
					  cout << "例如：g01 89" << endl;
					  cin >> gid;
					  if (gid == "0")
						  break;
					  cin >> grade;
					  gv = read_find_grade(1, gid, cid, sid, "./grades.txt", grad, grade);
					  cout << "修改成功！" << endl;
					  cout << gv.data()->get_grade_info() << endl;
					  break;
			}
			case 8:
			{
					  cout << "输入学生号，输入0返回上一级" << endl;
					  cin >> sid;
					  if (sid == "0")
						  break;
					  gv = read_find_grade(3, gid, cid, sid, "./grades.txt", grad);
					  st = read_find_student(1, sid, "./students.txt", stu);
					  st.add_grade_to_student(gv);
					  cout << st.get_student_info() << endl;
					  cout << st.get_all_grade();
					  cout << "均绩：" << st.get_GPA() << endl;
					  break;
			}
			case 9:
			{
					  cout << "输入课程号，输入0返回上一级" << endl;
					  cin >> cid;
					  if (cid == "0")
						  break;
					  gv = read_find_grade(2, gid, cid, sid, "./grades.txt", grad);
					  ct = read_find_course(1, cid, "./courses.txt", cour);
					  ct.add_grade_to_course(gv);
					  cout << ct.get_course_info() + ' ' + to_string(ct.get_credit()) << endl;
					  cout << "平均分：" << ct.get_course_average() << endl;
					  break;
			}
			default: throw input_exception();
			}//switch
		} // try
		catch (input_exception &){
			cout << "输入错误！！" << endl;
		}
		catch (write_exception &){
			cout << "写入文件失败" << endl;
		}
		catch (read_exception &){
			cout << "读取数据失败" << endl;
		}
		system("pause");
	}//while
	return 0;
}
