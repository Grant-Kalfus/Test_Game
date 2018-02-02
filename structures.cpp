#include"structures.h"
#include"helperFunctions.h"

structures::structures() {
	name = "NULL";
	material_type = WOOD;
	status_type = DEAD;
	size_type = NORMAL;
	can_break = true;
	can_enter = false;
	message = "NULL";
}

structures::structures(std::string name, std::string desc, material mat, status stat, size sz, bool can_enter, bool can_break, std::string message) {
	structures::name = name;
	structures::desc = desc;
	material_type = mat;
	status_type = stat;
	size_type = sz;
	structures::can_enter = can_enter;
	structures::can_break = can_break;	
	structures::message = message;
}

void structures::setPropStruc(std::string name, std::string desc, material mat, status stat, size sz, bool enterable, bool breakable, std::string message)
{
	structures::name = name;
	structures::desc = desc;
	material_type = mat;
	status_type = stat;
	size_type = sz;
	structures::can_enter = can_enter;
	structures::can_break = can_break;
	structures::message = message;
}

//Get Functions --------------------------------------------------------------------
std::string structures::getName() { return name; }

std::string structures::getDesc() { return desc; }

structures::material structures::getMaterial() { return material_type; }

structures::status structures::getStatus() { return status_type; }

structures::size structures::getSize() { return size_type; }

bool structures::getEnter() { return can_enter; }

bool structures::getBreak() { return can_break; }

std::string structures::getMsg() { return message; }
//----------------------------------------------------------------------------------

