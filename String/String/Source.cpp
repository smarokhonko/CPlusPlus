#include <iostream>
#include "String.h"

void main()
{
   String str = "aaaaaa";
   String str1= "bbbb";


   String str2 = str; // copy constructor
   
   str1 = str2;       //copy assigment operator
   str1 = "cccc";     //conversion constructor + copy assigment operator

   String str3 = str1 + "xxx";
   str1 += "yyy";

   String str4 = "4444";
   String str5 = std::move(str4); //move constructor

   str3 = std::move(str5); //move assigment

}