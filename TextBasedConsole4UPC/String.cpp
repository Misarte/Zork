#include "stdafx.h"
#include "String.h"
#include "string.h"
#include <string>

String::String()
{
	length = 100;
	buffer = new char[length];
}

String::String(const char* string)
{

	int len = strlen(string);
	length = len + 1;
	buffer = new char[length];
	strcpy_s(buffer, length, string);

}

String::String(const String& string)
{

	int len = Strlen();
	length = len + 1;
	buffer = new char[length];
	strcpy_s(buffer, length, string.buffer);

}

String::~String()
{
	delete[] buffer;
}

unsigned int String::Strlen() const
{
	return strlen(buffer);
}

const char* String::Cstr()const
{
	return buffer;
}

bool String::Empty()const
{

	if (strlen(buffer) == 0)
		return true;
	else return false;

}

bool String::stringcomparison(const char* string)const
{

	return (strcmp(buffer, string) == 0);

}

bool String::stringcomparison(const String& string)const
{

	return (strcmp(buffer, string.buffer) == 0);

}


void String::operator=(const String& string)
{

	int len = string.Strlen();

	if (len >= length)
	{
		length = len + 1;
		delete[] buffer;
		buffer = new char[length];
	}

	strcpy_s(buffer, length + 1, string.Cstr());

}

void String::operator=(const char* string)
{
	int len = strlen(string);

	if (len >= length)
	{
		length = len + 1;
		delete[] buffer;
		buffer = new char[length];

	}

	strcpy_s(buffer, len + 1, string);

}


char* String::operator+(const char* string)const
{
	char* new_string;

	int len = Strlen() + strlen(string) + 1;

	new_string = new char[len];
	strcpy_s(new_string, len, buffer);
	strcat_s(new_string, len, string);

	return new_string;
}

char* String::operator+(const String& string)const
{
	char* new_string;

	int len = Strlen() + string.Strlen() + 1;

	new_string = new char[len];
	strcpy_s(new_string, len, buffer);
	strcat_s(new_string, len, string.buffer);

	return new_string;
}


void String::operator+=(const String& string)
{

	int len1 = Strlen();
	int len2 = string.Strlen();
	length = len1 + len2 + 1;
	char* new_string;
	new_string = new char[length];

	strcpy_s(new_string, length, buffer);
	strcat_s(new_string, length, string.Cstr());

	delete[] buffer;

	buffer = new_string;


}

void String::operator+=(const char* string)
{

	int len1 = Strlen();
	int len2 = strlen(string);
	length = len1 + len2 + 1;
	char* new_char;
	new_char = new char[length];

	strcpy_s(new_char, length, buffer);
	strcat_s(new_char, length, string);

	delete[] buffer;

	buffer = new_char;

}

unsigned int String::Length()const
{
	return length;
}


void String::Clean()
{
	buffer[0] = '\0';
}
char* String::GetWordFromString(const int word_position)const
{
	char* word;
	int length = Strlen();
	int number = 0;
	int i;
	int word_length;
	//this for is to downcase every character
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		if ((buffer[i] > 'A') && (buffer[i] < 'Z')) buffer[i] = buffer[i] + 32;
		if (buffer[i] == ' ') number++;
	}
	number = 0;


	for (i = 0, word_length = 0; i < length; i++)
	{
		if (buffer[i] == ' ')
			number++;
		if (number >= (word_position - 1))
			word_length++;
	}
	//now we are in the position of our word

	word = new char[word_length + 1];// +1 because /0

	for (i = 0, word_length = 0, number = 0; i < length; i++)
	{

		if ((buffer[i] == ' ') || (buffer[i] == NULL))
		{
			number++;
			i++;
		}

		if (number == word_position - 1)
		{
			word[word_length] = buffer[i];
			word_length++;
		}
	}
	word[word_length] = '\0';

	return word;




}
