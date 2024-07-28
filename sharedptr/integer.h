#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
/*
class Integer {
private:
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    ~Integer();
    Integer(const Integer &obj);//but here we should pass an object by value
    //Integer(Integer &&obj);//move constructor
    int GetValue()const;
    void SetValue(int value);
    void PrintValue();
};
*/
class Project{
	std::string m_Name;
public:
	void SetName(const std::string &name) {
		m_Name = name;
	}
	void ShowProjectDetails() {
		std::cout<<" [Project Name]"<<m_Name<<'\n';
	}
};

class Employee {
	std::shared_ptr<Project> m_pProject{};
public:
	void SetProject(const std::shared_ptr<Project> &prj) {
		m_pProject = prj;
	}

	const std::shared_ptr<Project>& GetProject() const {
		return m_pProject;
	}

};

//void ShowInfo(const std::unique_ptr<Employee>& emp) {
//	std::cout<<" EMployee project details:";
//	emp->GetProject()->ShowProjectDetails();
//}


