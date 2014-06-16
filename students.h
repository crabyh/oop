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
#include "grades.h"
#include "courses.h"
class students{
private:
	const string student_name;
	const string student_id;
	const string gender;
	grades *grade_pointer;//用链表储存学生成绩
	students(){}//阻止默认构造
public:
	students(const string sname, const string sid, const string gend):
		student_name(sname), student_id(sid), gender(gend), grade_pointer(NULL){}//构造函数
	~students(){}//析构函数
	const void add_grade(grades &grad);//添加成绩
	const string show_grade() const;//显示学生所有成绩
	const double get_GPA() const;//计算学生均绩
	const string show_info() const;//显示学生信息
};

#endif
