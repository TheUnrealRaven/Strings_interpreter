#include "str.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>

extern void yyerror(string s);

using namespace std;

        Str::Str() { }
        
        Str::Str(const Str& str_copy)
        {
           str = str_copy.getStr();
           length = str_copy.len_str();
        }

        Str::Str(string s)
        {
          this->str = s;
          this->length = s.length();        
        }

        
        Str* Str::operator+(const Str &st)
        {
             string s =   this->str + st.getStr();
             return new Str(s);
        }
        Str* Str::multiplication(const int value)
        {
            
             string newStr = "";
             for(int i=0; i<value; i++)
                newStr += str;
             
             return new Str(newStr);
        }
        string Str::getStr() const
        {
           return str;
        }
        
        Str* Str::reverse()
        {
             
             std::reverse(str.begin(), str.end());
             
             return new Str(str);
        }
        Str* Str::lower()
        {
             string tmp_str;
             
             
             
             auto begin = str.begin();
             auto end = str.end();
             
             char c = ' ';
             while(begin != end)
             {
                tmp_str.push_back(char(tolower(*begin)));             
                begin++;
                
             }
             
             return new Str(tmp_str);
        }
        bool Str::operator==(const Str &st)
        {
            return (str == st.getStr());
        }
        bool Str::operator>=(const Str &st)
        {
            return length >= st.len_str() ? true : false;
        }
        bool Str::operator<=(const Str &st)
        {
            return length <= st.len_str() ? true : false; 
        }
        bool Str::operator!=(const Str &st)
        {
            return !(str == st.getStr());
        }
        bool Str::operator<(const Str &st)
        {
            return length < st.len_str() ? true : false;
        }
        bool Str::operator>(const Str &st)
        {
            return length > st.len_str() ? true : false;
        }
        
        Str* Str::replace(int a, int b,string s)
        {
            if((b-a) < s.length())
                yyerror("Greska");
                
            string tmp = str;
            tmp.replace(a, b-a, s);
            
            return new Str(tmp);
        }
        Str* Str::center(const Str& str1,int value)
        {
            int add = value - length;
            
            if (add < 0)
                yyerror("Neispravan vrednost");
           
            
            int left = add / 2 + (add % 2);
            int right = add / 2;
            
            cout << left << " " << right << endl;
            string tmp;
            
            string character = str1.getStr();
            
           
            
            for(int i=0; i<left; i++)
                tmp += character[0];
            tmp += str;
            for(int i=0; i<right; i++)
                tmp += character[0];
          
            
          
            
            return new Str(tmp);
            
        }
        
        Str* Str::upper()
        {
             string tmp;
             
             auto begin = str.begin();
             auto end = str.end();
             
             while(begin != end)
             {
                tmp.push_back(char(toupper(*begin)));
                begin++;
             } 
             return new Str(tmp);
        }
        int Str::index(string str2) const
        {
             size_t found = str.find(str2);
             if(found != string::npos)
             {
                return found;
             }
             return 0;
             
        }
        
        Str* Str::subscript(int n, int m)
        {
             if(n == 0 && m == 0) 
                return new Str(str);
              
             if(n == 0) 
                return new Str(str.substr(0, m));               
             
             if(m == 0)
                return new Str(str.substr(n, len_str()));
                
             auto begin = str.begin();
             auto end = str.end();
             
             int i = 0;
             string temp = "";
             
             temp.append(str.begin()+n, str.begin()+m);
                
             return new Str(temp);   
                 
        }
        int Str::len_str() const
        {
           return str.length();
        }
        
        void Str::print_str() const
        {
           cout << str << endl;
        }
        
        bool Str::islower() const
        {
           auto begin = str.begin();
           auto end = str.end();
           
           char c = ' ';
           
           while(begin != end)
           {
              c = *begin;
              
              if(std::isupper(c))
                return false;
                
              begin++;
           }
           return true;
        }
        
        void Str::setStr(string tmp)
        {
            str = tmp;
        }
        
        bool Str::ignoreCase(Str& str1)
        {
            if(length != str1.len_str())
                return false;
                
            Str* tmp = new Str(this->lower()->getStr());
            Str* tmp1 = new Str(str1.lower()->getStr());
           // str1.setStr(str1.lower());
            
            if(tmp->getStr() == tmp1->getStr())
            {
                delete tmp;
                delete tmp1;
                
                return true;              
            }
            delete tmp1;
            delete tmp;
            
            return false;
               
        }
        
        
        bool Str::isDigit() const
        {
           for(int i=0;i<length; i++)
           {
               if(!isdigit(str[i]))
                    return false;
           }
           return true;      
        }
        
        
        
        bool Str::find(const Str& str1) const
        {
           size_t found = str.find(str1.getStr());
           if(found == string::npos)
                return false;
           return true;       
        }
        
        bool Str::isSpace() const
        {
           char tmp = ' ';
           for(int i=0; i<length; i++)
           {
               if(str[i] != tmp)
                  return false;
           }
           return true;
        }
        bool Str::isupper() const
        {
           auto begin = str.begin();
           auto end = str.end();
           
           char c = ' ';
           
           while(begin != end)
           {
              c = *begin;
              if(std::islower(c))
                return false;
              begin++;
           }
           return true;
        }
