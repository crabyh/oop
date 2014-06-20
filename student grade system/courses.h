//
//  courses.h
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#ifndef _____courses_h
#define _____courses_h

#include "head.h"
#include "exception.h"
class grades;

class courses{
private:
    string course_id;
	string course_name;
	double credit;
	string teacher;
	vector<grades> cgp;
	friend class grades;
	friend class students;
public:
	courses(){}//默认构造函数
	courses(string cid, string cname, double cred, string t):
		course_id(cid), course_name(cname), credit(cred), teacher(t){}//构造函数
	~courses(){}//析构函数
	double get_credit();//返回学分
	string get_course_info();//返回课程信息
	void add_grade_to_course(vector<grades> grad);//添加成绩到课程
	double get_course_average();//计算课程平均分
};

#endif
