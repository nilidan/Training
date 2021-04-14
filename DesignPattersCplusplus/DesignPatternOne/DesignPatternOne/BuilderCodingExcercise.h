#pragma once
#include <string>
#include <ostream>
#include <vector>
using namespace std;

//solution for Desing Pattersn in Modern C++  in Undemy
// this output the fields
struct Field
{
	string name, type;

	Field(const string& name, const string& type)
		: name{ name },
		type{ type }
	{
	}


	friend ostream& operator<<(ostream& os, const Field& obj)
	{
		return os << obj.type << " " << obj.name << ";";
	}
};

//creates vector of the fields  and provides output
struct Class
{
	string name;
	vector<Field> fields;

	friend ostream& operator<<(ostream& os, const Class& obj)
	{
		os << "class " << obj.name << "\n{\n";
		for (auto&& field : obj.fields)
		{
			os << "  " << field << "\n";
		}
		return os << "};\n";
	}
};
class CodeBuilder
{

	Class classes;
public:
	CodeBuilder(const string& class_name)
	{
		// todo
		classes.name = class_name;
	}

	CodeBuilder& add_field(const string& name, const string& type)
	{
		// todo
		classes.fields.emplace_back(Field{ name, type });
		return *this;
	}

	friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
	{
		// todo
		return os << obj.the_class;
	}
};