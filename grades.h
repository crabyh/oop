//
//  grades.h
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#ifndef _____grades_h
#define _____grades_h

#include "head.h"
#include "students.h"
#include "courses.h"

class grades{
private:
    string grade_id;
    short grade;
	courses *course;
	students *student;
public:
	grades(){}//默认构造函数
	grades(string gid, short grad, courses *cour, students *stu) :
		grade_id(gid), grade(grad), course(cour), student(stu){}//构造函数
	~grades(){}//析构函数
	void set_grade(short grad);//修改成绩
	string get_grade_info();//返回成绩信息
	friend class students;
	friend class courses;
};

#endif
