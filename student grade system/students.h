//
//  students.h
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#ifndef __students_h
#define __students_h

#include "head.h"
#include "exception.h"
class grades;

class students{
private:
    string student_id;
    string student_name;
    string gender;
	vector<grades> sgp;
	friend class grades;
public:
	students(){}//默认构造函数
	students(string sid, string sname, string gend):
        student_id(sid), student_name(sname), gender(gend){}//构造函数
	students(const students& s):
		student_id(s.student_id), student_name(s.student_name), gender(s.gender), sgp(NULL){}//拷贝构造函数
	~students(){}//析构函数
	string get_all_grade();//显示学生所有成绩
	string get_student_info();//显示学生信息
	double get_GPA();//计算学生均绩
	void add_grade_to_student(vector<grades> grad);//添加成绩到学生
};

#endif
