//
//  main.cpp
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#include "head.h"
#include "courses.h"
#include "courses.h"
#include "students.h"

int main()
{
	courses c1("c01", "oop", 2.5, "hulanqing");
	courses c2("c02", "ads", 1.5, "fengyan");
	grades g1(88, &c1);
	grades g2(87, &c1);
	grades g3(92, &c2);
	grades g4(90, &c2);
	students s1("maoyuhan", "s01", "male");
	students s2("yuxin", "s02", "female");
	s1.add_grade(g1);
	s1.add_grade(g4);
	s2.add_grade(g2);
	s2.add_grade(g3);
	cout << g1.get_grade() << endl;
	cout << g2.get_grade() << endl;
	cout << g3.get_grade() << endl;
	cout << g4.get_grade() << endl;
	cout << c1.course_info() << endl;
	cout << c1.get_credit() << endl;
	cout << c2.course_info() << endl;
	cout << c2.get_credit() << endl;
	cout << s1.show_info() << endl;
	cout << s1.get_GPA() << endl;
	cout << s1.show_grade() << endl;
	cout << s2.show_info() << endl;
	cout << s2.get_GPA() << endl;
	cout << s2.show_grade() << endl;
	system("pause");
	return 0;
}

