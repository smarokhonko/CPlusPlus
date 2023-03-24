#include "String.h"

String::String() : m_data(nullptr), m_length(0)
{
}

String::String(const char* str)
{
   m_length = strlen(str);
   m_data = new char[m_length + 1];
   strcpy(m_data, str);
}

String::~String()
{
   if (m_data)
      delete[] m_data;
}

String::String(const String& other)
{
   m_length = other.m_length;
   m_data = new char[other.m_length + 1];
   strcpy(m_data, other.m_data);
}

String& String::operator=(const String& other)
{
   if (this == &other)
      return *this;

   delete[] m_data; //delete array it points to since m_data will point to the new memory 
   m_length = other.m_length;
   m_data = new char[other.m_length + 1];
   strcpy(m_data, other.m_data);

   return *this;
}

String::String(String&& other)
{
   m_length = other.m_length;
   m_data = other.m_data;

   other.m_length = 0;
   other.m_data = nullptr;
}

String& String::operator=(String&& other)
{
   if (this == &other)
      return *this;

   delete[] m_data;

   m_length = other.m_length;
   m_data = other.m_data;

   other.m_length = 0;
   other.m_data = nullptr;

   return *this;
}

size_t String::length() const
{
   return m_length;
}

const char* String::c_str() const
{
   return m_data;
}

char& String::operator[](const size_t index)
{
   return m_data[index];
}

String String::operator+(const String& other)
{
   String temp;
   temp.m_length = m_length + other.m_length;
   temp.m_data = new char[temp.m_length + 1];

   strcpy(temp.m_data, m_data, false);
   strcpy(temp.m_data + m_length, other.m_data);

   return temp;
}

String& String::operator+=(const String& other)
{
   size_t newLength = m_length + other.m_length;
   char* newData = new char[newLength + 1];

   strcpy(newData, m_data, false);
   strcpy(newData + m_length, other.m_data);

   delete[] m_data;
   m_data = newData;
   m_length = newLength;

   return *this;
}

size_t String::strlen(const char* str)
{
   size_t length = 0;
   while (*str++ != '\0')
      ++length;

   return length;
}

void String::strcpy(char* dest, const char* source, bool addNullTerminated)
{
   while (*source != '\0')
   {
      *dest = *source;
      ++dest;
      ++source;
   }

   if(addNullTerminated)
      *dest = '\0';
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
   out << str.m_data << std::endl;

   return out;
}