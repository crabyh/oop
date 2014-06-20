//
//  students.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "students.h"
#include "grades.h"


void students::add_grade_to_student(vector<grades> grad)//添加成绩到学生
{
	sgp = grad;
}

string students::get_all_grade()//显示学生所有成绩
{
	vector<grades>::iterator i;
	string grade_out;
	for (i = sgp.begin(); i != sgp.end(); ++i){
		grade_out += i->grade_id + ' ' + i->course->get_course_info() + ' ' + to_string(i->course->get_credit()) + ' ' + to_string(i->grade) + '\n';
	}
	return grade_out;
}

double students::get_GPA()//计算学生均绩
{
	double sum = 0.0, cred = 0.0, gpa;
	vector<grades>::iterator j;
	for (j = sgp.begin(); j != sgp.end(); ++j){
		sum += j->course->get_credit() * (5 - (95 - j->grade) / 10.0);
		cred += j->course->get_credit();
	}
	return gpa = sum / cred;
}

 string students::get_student_info()//显示学生信息
{
	return student_id + ' ' + student_name + ' ' + gender;
}