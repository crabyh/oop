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
#include "courses.h"
class grades{
private:
    short grade;
	courses *course;
	grades *next_grade;//用链表储存学生成绩
	grades(){}
public:
	grades(const short grad, courses *cour):
		grade(grad), course(cour), next_grade(NULL){}//构造函数
	~grades(){}//析构函数
	void set_grade(const short grad);//修改成绩
	const short get_grade() const;//返回成绩
	friend class students;
};

#endif
