#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

// template <typename T>  //T - type of the object we observed
// class Observer
// {
// 	virtual void field_changed(
// 		T& source,
// 		const std::string& field_name) = 0;//T - whose field is changed
// };





class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const string& newMessage) = 0;
};