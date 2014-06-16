//
//  grades.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "grades.h"

void grades::set_grade(const short grad)//修改成绩
{
	grade = grad;
}

const short grades::get_grade() const//返回成绩
{
	return grade;
}
