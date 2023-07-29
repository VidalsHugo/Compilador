all: 	
		clear
		lex lexica.l
		yacc -d -v sintatica.y
		g++ -o glf y.tab.c -ll

		./glf < exemplo.foca
