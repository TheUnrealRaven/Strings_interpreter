%option noyywrap

%{
        #include <iostream>
        #include <string>
        #include <cstdlib>
        
        #include "str.hpp"
        #include "parser.tab.hpp"
        
        using namespace std;
        
        
        
%}


%%

":=" { return assign_token; }
"print" { return print_token; }
"index" { return index_token; }
"lower" { return lower_token; }
"upper" { return upper_token; }
"=="    { return eq_token; }
"<="    { return lt_token; }
">="    { return gt_token; }
"!="    { return neq_token; }
"islower" { return islower_token; }
"isupper" { return isupper_token; }
"replace" { return rep_token; }
"reverse" { return reverse_token; }
"center"  { return center_token; }
"find"  { return find_token; }
"isDigit" { return isDigit_token; }
"isSpace" { return isSpace_token; }
"equalsIgnoreCase" { return ignore_token; }
\"[a-zA-Z0-9 ]*\" { yylval.str = new string(yytext); return str_token; }
[a-zA-Z_][A-Za-z0-9]* { yylval.id = new string(yytext); return id_token; }
[0-9]+ { yylval.value = stoi(yytext, NULL, 10); return num_token; }
[()+\n<>,\"|:\]\[*] { return *yytext; }    
[ \t] {    }
. {
        std::cerr << "Leksicka greska " << *yytext << std::endl;
        exit(EXIT_FAILURE); 
  }    

%%
