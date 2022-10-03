#ifndef __STRING_H__
#define __STRING_H__

#include "Account.h"

class String
{
	private:
		int len;
		char* str;
	public:
		String();
		String(const char* s);
		String(const String& s);
		~String();
		String& operator=(const String& s);
		String& operator+=(const String& s);
		bool operator==(const String& s);
		String operator+(const String& s);

		friend std::ostream& operator<<(std::ostream& os,const String& s);
		friend std::istream& operator>>(std::istream& is,String& s);
};

#endif
