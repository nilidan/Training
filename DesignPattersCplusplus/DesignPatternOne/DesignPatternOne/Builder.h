#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
/*Html Builder to Demonstrate builder*/
using namespace std;

struct HtmlBuilder;

// Reprents the tags  and text it contains
// object oriented  structure that helps it scale for different tags
struct HtmlElement
{
	// any text html may contain
	string name;
	string text;

	// htmls tags
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	HtmlElement() {}
	HtmlElement(const string& name, const string& text)
		: name(name),
		text(text)
	{
	}

	// indentions for html in a correct way for its elements and sub elements
	string str(int indent = 0) const
	{
		ostringstream oss;
		string i (indent_size*indent, ' '); //string contructor
		oss << i << "<" << name << ">" << endl;
		if (text.size() > 0)
			oss << string(indent_size*(indent + 1), ' ') << text << endl;

		for (const auto& e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}

	//A function to return HtmlBuilder  this gives a hent
	static unique_ptr<HtmlBuilder> build(string root_name)
	{
		return make_unique<HtmlBuilder>(root_name);
	}
};


// It will help build up the HTML using the object oriented strucures HTMLElement
// HTMLElement is utility class for modling an HTML ELemtn in object oriented way
// This help define root of element and build the children of the root
struct HtmlBuilder
{
	HtmlBuilder(string root_name)
	{
		root.name = root_name;
	}

	// void to start with
	// creates a new html element and adds it to a list
	// fluient interface if you reference or pointer
	HtmlBuilder& add_child(string child_name, string child_text)
	{
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return *this;
	}

	// pointer based api to use the  operator
	HtmlBuilder* add_child_2(string child_name, string child_text)
	{
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return this;
	}

	string str() { return root.str(); }

	//returning a copy of
	operator HtmlElement() const { return root; }
	HtmlElement root;
};

int demo()
{
	// <p>hello</p>
	//Approach doesn't scale
	auto text = "hello";
	string output;
	output += "<p>";
	output += text;
	output += "</p>";
	printf("<p>%s</p>", text);

	// <ul><li>hello</li><li>world</li></ul>
	// better idea but still put a string piece by piece
	// HTML has a structed format, what tags can contain other of tags
	// whether it is paragrah or list items. These different tags is not being enforced here
	// or in object oriented fasihon.
	// Better idea is to use a builder pattern which defines a  object oriented structur to support its transformation to a string
	string words[] = { "hello", "world" };
	ostringstream oss;
	oss << "<ul>";
	for (auto w : words)
		oss << "  <li>" << w << "</li>";
	oss << "</ul>";
	printf(oss.str().c_str());

	// easier
	// ul unorder list
	//Fluient inerface if method return is a reference or pointer instead of void
	HtmlBuilder builder{ "ul" };
	builder.add_child("li", "hello").add_child("li", "world");
	cout << builder.str() << endl;


	//Gives a hint of using the builder and of ways to put into put
	auto builder2 = HtmlElement::build("ul")
		->add_child_2("li", "hello")->add_child_2("li", "world");
	cout << builder2 << endl;

	getchar();
	return 0;
}