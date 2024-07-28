#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>

class Integer{
	int *pInt;
public:
	Integer() {
		std::cout<<"Integer()"<<std::endl;
		pInt = new int{0};
	}
	Integer(const Integer &val){
		std::cout<<"Integer(const Integer &val)"<<std::endl;
		pInt = new int(*val.pInt);
	}
	Integer(Integer &&val){
		std::cout<<"Integer(Integer &&val)"<<std::endl;
		*pInt = *val.pInt;
		val.pInt = nullptr;
	}
	Integer operator=(const Integer &val){
		*pInt = *val.pInt;
	}
	~Integer(){
		std::cout<<"~Integer"<<std::endl;
		delete pInt;
	}

};


