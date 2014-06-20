//
//  grades.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "grades.h"

void grades::set_grade(short grad)//修改成绩
{
	grade = grad;
}

string grades::get_grade_info()//返回成绩信息
{
	return grade_id + ' ' + course->get_course_info() + ' ' + to_string(course->get_credit()) + ' ' + student->get_student_info() + ' ' + to_string(grade);
}

