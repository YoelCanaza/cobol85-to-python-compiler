all:
	flex lexer.l
	bison -d parser.y -Wcounterexamples
	gcc lex.yy.c parser.tab.c -o cobol2py -Wno-implicit-function-declaration

test: all
	./cobol2py < test.cbl > output.py
	@echo "=== Generated Python code ==="
	@cat output.py
	@echo "=== Execution output ==="
	@python3 output.py

clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h cobol2py output.py