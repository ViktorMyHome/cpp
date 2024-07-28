#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>


class Printer{
	std::weak_ptr<int> m_pValue{};
public:
	void SetValue(std::weak_ptr<int> p){
		m_pValue = p;
	}
	void Print() {
		std::cout<<" Ref count: "<<m_pValue.use_count()<<std::endl;
		if(m_pValue.expired()) {
			std::cout<<"Resource is no longer available"<<std::endl;
			return;
		}
		auto sp = m_pValue.lock();
		std::cout<<"Value is: "<<*sp<<std::endl;
		std::cout<<"Ref count: "<< sp.use_count() <<std::endl;
	}

};


