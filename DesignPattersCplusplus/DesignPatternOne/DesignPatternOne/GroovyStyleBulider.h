#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;

struct Tag {
	
		string name;
		string text;
		vector<Tag> children;
		vector<pair<string, string>> attributes;

		/*Using the tag as a base class to allow the client
		  to wright something that looks like html
		  
		  */

		// used to print out all the tags, children, and content
		friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
		{
			os << "<" << tag.name;

			for (const auto& att : tag.attributes)
				os << " " << att.first << "=\"" << att.second << "\"";

			if (tag.children.size() == 0 && tag.text.length() == 0)
			{
				os << "/>" << std::endl;
			}
			else
			{
				os << ">" << std::endl;

				if (tag.text.length())
					os << tag.text << std::endl;

				for (const auto& child : tag.children)
					os << child;

				os << "</" << tag.name << ">" << std::endl;
			}



	
			return os;
		}


protected:

		Tag(const string& name, const string& text)
			: name( name ),	text( text ){}


		Tag(const string& name, const vector<Tag> &children)
			: name( name ), children( children ){}
};

//callls base tag, p is paragragh tag in html
struct P : Tag
{
	explicit P(const std::string& text)
		: Tag{ "p", text }
	{
	}

	//provides children 
	P(std::initializer_list<Tag> children)
		: Tag("p", children)
	{
	}

};

struct IMG : Tag
{
	explicit IMG(const std::string& url)
		: Tag{ "img", "" }
	{
		attributes.emplace_back(make_pair("src", url));
	}
};