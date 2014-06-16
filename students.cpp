//
//  students.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "students.h"

const void students::add_grade(grades &grad)//添加成绩
{
	grades *temp_pointer;
	if (grade_pointer == NULL){
		grade_pointer = &grad;
	}
	else{
		temp_pointer = grade_pointer;
		while (temp_pointer->next_grade != NULL){
			temp_pointer = temp_pointer->next_grade;
		}
		temp_pointer->next_grade = &grad;
	}
}

const string students::show_grade() const//显示学生所有成绩
{
	string grade_out;
	grades *temp_pointer=grade_pointer;
	while (temp_pointer != NULL){
		grade_out += temp_pointer->course->course_info() + ' ' + to_string(temp_pointer->course->get_credit()) + ' ' + to_string(temp_pointer->get_grade()) + '\n';
		temp_pointer = temp_pointer->next_grade;
	}
	return grade_out;
}

const double students::get_GPA() const//计算学生均绩
{
	double sum=0.0, cred = 0.0, gpa;
	grades *temp_pointer = grade_pointer;
	while (temp_pointer != NULL){
		sum += temp_pointer->course->get_credit() * (5 - (95 - temp_pointer->get_grade()) / 10.0);
		cred += temp_pointer->course->get_credit();
		temp_pointer = temp_pointer->next_grade;
	}
	return gpa = sum / cred;
}

const string students:: show_info() const//显示学生信息
{
	return student_name + ' ' + student_id + ' ' + gender;
}