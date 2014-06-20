//
//  grades.h
//  1
//
//  Created by Myh on 14-5-5.
//  Copyright (c) 2014Äê myh. All rights reserved.
//

#ifndef _____exception_h
#define _____exception_h

class base_exception{
	virtual void except ()= 0;
};

class input_exception :base_exception{
	virtual void except(){}
};

class file_exception :base_exception{
	virtual void except(){}
};

class login_exception :base_exception{
	virtual void except(){}
};
#endif