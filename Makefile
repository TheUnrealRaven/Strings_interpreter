interpreter: lex.yy.o parser.o str.o
	g++ -std=c++17 str.o lex.yy.o parser.o -o interpreter
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -std=c++17 -c lex.yy.c -o lex.yy.o

str.o: str.cpp str.hpp
	g++ -std=c++17 -c str.cpp -o str.o

parser.o: parser.tab.cpp parser.tab.hpp str.hpp
	g++ -std=c++17 -c parser.tab.cpp -o parser.o

lex.yy.c: lexer.l parser.tab.hpp str.hpp
	flex lexer.l

parser.tab.cpp parser.tab.hpp: parser.ypp str.hpp
	bison -d -v parser.ypp
