//
//  grades.h
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014年 myh. All rights reserved.
//

#ifndef _____exception_h
#define _____exception_h

//异常类
class base_exception{
	virtual void except ()= 0;
};

//不同子类异常继承基类异常
class input_exception :base_exception{
	virtual void except(){}
};

class file_exception :base_exception{
	virtual void except(){}
};

class login_exception :base_exception{
	virtual void except(){}
};

class not_found_exception :base_exception{
	virtual void except(){}
};

class exist_exception :base_exception{
	virtual void except(){}
};

#endif