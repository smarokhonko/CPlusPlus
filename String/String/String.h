#pragma once

#include <iostream>

class String
{
public:

   String();

   String(const char* str);

   ~String();

   String(const String& other);

   String& operator=(const String& other);

   String(String&& other);
   String& operator=(String&& other);

   size_t length() const;

   const char* c_str() const;

   char& operator[](const size_t index);

   String operator+(const String& other);
   
   String& operator+=(const String& other);

   friend std::ostream& operator<<(std::ostream& out, const String& str);

private:
   size_t strlen(const char* str);
   void strcpy(char* dest, const char* source, bool addNullTerminated = true);


private:
   char* m_data;
   int m_length;
};

std::ostream& operator<<(std::ostream& out, const String& str);

