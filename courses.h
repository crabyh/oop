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
class courses{
private:
	const string course_id;
	const string course_name;
	const double credit;
	const string teacher;
public:
	courses(const string cid, const string cname, const double cred, const string t):
		course_id(cid), course_name(cname), credit(cred), teacher(t){}//构造函数
	~courses(){}//析构函数
	const double get_credit();//返回学分
	const string course_info();//返回课程信息
	friend class grades;
};

#endif
