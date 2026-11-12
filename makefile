#macro_handler.c

mypreprocessor: preprocessor_main.o file_inclusion.o comment_removal_file.o macro_handler.o
	cc preprocessor_main.o file_inclusion.o comment_removal_file.o -o mypreprocessor macro_handler.o
preprocessor_main.o: preprocessor_main.c
	cc -c preprocessor_main.c
file_inclusion.o: file_inclusion.c
	cc -c file_inclusion.c
comment_removal_file.o: comment_removal_file.c
	cc -c comment_removal_file.c
macro_handler.o: macro_handler.c
	cc -c macro_handler.c
clear:
	@echo "cleaning up...."
	@rm -r *.o

