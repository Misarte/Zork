#pragma once
#ifndef __STRING_H__
#define __STRING_H__


class String {
public:
	char* buffer;
	int length;

public:

	String();
	String(const char* string);
	String(const String& string);
	~String();

	unsigned int Length()const;

	unsigned int Strlen()const;//gives the length of the buffer
	const char* Cstr()const;//returns the buffer
	bool Empty()const;

	bool stringcomparison(const String& string)const;
	bool stringcomparison(const char* string)const;

	void operator=(const String& string);
	void operator=(const char* string);

	void operator+=(const String& string);
	void operator+=(const char* string);

	char* operator+(const String& string)const;
	char* operator+(const char* string)const;

	char* GetWordFromString(const int word_position)const;




	void Clean();


};

#endif

