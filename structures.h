#pragma once
#include<string>

class structures {
public:
	enum material {WOOD, METAL, STONE, WATER};
	enum status {LIVING, DEAD, CONSTRUCTED};
	enum size {BIG, NORMAL, MINI};
	
	//Default constructor
	structures();
	
	//Constructor with named parameters
	structures(std::string name, std::string desc, material mat, status stat, size sz, bool enterable, bool breakable, std::string message = "NULL");

	//Mass set all parameters
	void setPropStruc(std::string name, std::string desc, material mat, status stat, size sz, bool enterable, bool breakable, std::string message = "NULL");

	//Getters
	std::string getName();
	std::string getDesc();
	material getMaterial();
	status getStatus();
	size getSize();
	bool getEnter();
	bool getBreak();
	std::string getMsg();

private:
	std::string name;
	std::string desc;
	material    material_type;
	status      status_type;
	size        size_type;
	bool        can_enter;
	bool        can_break;
	std::string message = "NULL";
};