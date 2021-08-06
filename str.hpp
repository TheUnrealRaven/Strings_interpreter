#ifndef __STR__
#define __STR__

#include <iostream>
#include <string>

using namespace std;


class Str 
{
   public:
        Str();
        Str(string str);
        
        Str(const Str& str_copy);
        
        
        
        Str* operator+(const Str &st);
        Str* multiplication(const int value);
        
        Str* reverse();
        Str* lower();
        Str* upper();
        int index(string str2) const;
        
        bool operator==(const Str &st);
        bool operator>=(const Str &st);
        bool operator<=(const Str &st);
        bool operator!=(const Str &st);
        bool operator<(const Str &st);
        bool operator>(const Str &st);
        bool islower() const;
        bool isupper() const;
        bool find(const Str&) const;
        bool ignoreCase(Str&);
        bool isDigit() const;
        bool isSpace() const;
        
        
        
        Str* replace(int a, int b, string s);
        
        string getStr() const;
        
        void print_str() const;
        
        Str* center(const Str&, int value);
        
        Str* subscript(int n, int m);
        int len_str() const;
        
        void setStr(string);
        
        
        
        
        
     
   
   private:
        string str;
        int length;
        



};

#endif
