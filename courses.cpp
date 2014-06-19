//
//  courses.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "courses.h"
#include "grades.h"
/*
void courses::add_grade_to_course(grades &gra)//添加成绩到课程
{
	grades *temp_pointer;
	if (cgp == NULL){
		cgp = &gra;
	}
	else{
		temp_pointer = cgp;
		while (temp_pointer->cn != NULL){
			temp_pointer = temp_pointer->cn;
		}
		temp_pointer->cn = &gra;
	}
}

double courses::get_course_average()//计算课程平均分
{
	double sum = 0.0, average;
	int count = 0;
	grades *temp_pointer = cgp;
	while (temp_pointer != NULL){
		count++;
		sum += temp_pointer->grade;
		temp_pointer = temp_pointer->cn;
	}
	return average = sum / count;
}
*/

void courses::add_grade_to_course(vector<grades> grad)//添加成绩到课程
{
	cgp = grad;
}

double courses::get_credit()//返回学分
{
	return credit;
}

string courses::get_course_info()//返回课程信息
{
	return course_id + ' ' + course_name + ' ' + teacher;
}

double courses::get_course_average()//计算课程平均分
{
	double sum = 0.0, average;
	int count = 0;
	vector<grades>::iterator k;
	for (k = cgp.begin(); k != cgp.end(); ++k){
		count++;
		sum += k->grade;
	}
	return average = sum / count;
}
