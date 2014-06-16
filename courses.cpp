//
//  courses.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "courses.h"

const double courses::get_credit()//返回学分
{
	return credit;
}

const string courses::course_info()//返回课程信息
{
	return course_id + ' ' + course_name + ' ' + teacher;
}