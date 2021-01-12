

#pragma once
#include <vector>
/*
interface segregation principle is basically to get you to not create interfaces
which are too large and which require the implementors to maybe implement too much.
Avoid stuffing implementation too much, segregate interface or make it smaller. 
*/
struct Document;

//struct IMachine
//{
//  virtual void print(Document& doc) = 0;
//  virtual void fax(Document& doc) = 0;
//  virtual void scan(Document& doc) = 0;
//};
//
//struct MFP : IMachine
//{
//  void print(Document& doc) override;
//  void fax(Document& doc) override;
//  void scan(Document& doc) override;
//};

/*
 If you have have a machine that can do print, scan, and fax, then interface is no problem.
 But what if a client only need to scan  for the machine or only needed one of the function.  Then You would have to implement whole interface. 
 The scan method will be implement, but what about 2 other methods. You can have it as  null body, but you are sending the 
 wrong message to client. Because the client will see these methods and think the machine can do both, which it cant at all.
 you're giving them the API anyway simply because the interface that's been defined for handling all of this stuff is just too big.
*/

//Best way is to breakup the interface or segregate the interface. Now you be able to implement one, combo, or all of the features
// 1. Recompile
// 2. Client does not need this
// 3. Forcing implementors to implement too much

struct IPrinter
{
	virtual void print(Document& doc) = 0;
};

struct IScanner
{
	virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter
{
	void print(Document& doc) override;
};

struct Scanner : IScanner
{
	void scan(Document& doc) override;
};

//implements a combination of features
struct IMachine : IPrinter, IScanner
{
};

struct Machine : IMachine
{
	IPrinter& printer;
	IScanner& scanner;

	//Decorator pattern
	
	Machine(IPrinter& printer, IScanner& scanner)
		: printer{ printer },
		scanner{ scanner }
	{
	}

	//Implement them interms of members
	void print(Document& doc) override {
		printer.print(doc);
	}
	void scan(Document& doc) override {
		scanner.scan(doc);
	}
};

// IPrinter --> Printer
// everything --> Machine