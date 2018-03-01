$(CC)      :=gcc
VPATH = src:bashlib:lib
BINPATH = $(shell cd ./bin; pwd)
# makefile created by fuhs

# put source code into src/
# put exec file into bin/
# put lib file into include/
# put link file into build/
	
bin/KSH-shell, bin/cat, bin/clear, bin/cmp, bin/cp, bin/date, bin/echo, bin/find, bin/ifconfig, bin/ls, \
bin/mkdir, bin/more, bin/mv, bin/ps, bin/pwd, bin/mesg, bin/rm, bin/sort, bin/tac, bin/tree, bin/who: src/cat.c src/clear.c src/cmp.c \
src/cp.c src/date.c src/echo.c src/find.c src/ifconfig.c src/ls.c src/mkdir.c src/more.c src/mv.c src/ps.c \
src/pwd.c src/mesg.c src/rm.c src/sort.c src/tac.c src/tree.c src/who.c bashlib/KSH-shell.h bashlib/KSH-shell.c \
bashlib/type_prompt.c bashlib/read_command.c bashlib/builtin_command.c bashlib/parsing.c
	mkdir -p bin
	$(CC) bashlib/KSH-shell.c bashlib/type_prompt.c bashlib/read_command.c \
	bashlib/builtin_command.c bashlib/parsing.c -o bin/KSH-shell
	$(CC) src/cat.c -o bin/cat
	$(CC) src/clear.c -o bin/clear
	$(CC) src/cmp.c -o bin/cmp
	$(CC) src/cp.c -o bin/cp
	$(CC) src/date.c -o bin/date
	$(CC) src/echo.c -o bin/echo
	$(CC) src/find.c -o bin/find
	$(CC) src/ifconfig.c -o bin/ifconfig
	$(CC) src/ls.c -o bin/ls
	$(CC) src/mkdir.c -o bin/mkdir
	$(CC) src/more.c -o bin/more
	$(CC) src/mv.c -o bin/mv
	$(CC) src/ps.c -o bin/ps
	$(CC) src/pwd.c -o bin/pwd
	$(CC) src/mesg.c -o bin/mesg
	$(CC) src/rm.c -o bin/rm
	$(CC) src/sort.c -o bin/sort
	$(CC) src/tac.c -o bin/tac
	$(CC) src/tree.c -o bin/tree
	$(CC) src/who.c -o bin/who




.PHONY: clean
clean:
	rm -r bin/*
