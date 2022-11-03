#!/bin/sh
# megatestpartyfunk v.5
# @nkimel si vous avez des questions

Clone()
{
	if [ -d "$UPSTREAM" ]; then
		printf "%s\n" "cp -R $UPSTREAM $CLONE_DIST"
		cp -R "$UPSTREAM" "$CLONE_DIST" || PanicExit
		make -C "$UPSTREAM" fclean
	else
		git clone "$UPSTREAM" "$CLONE_DIST/libft" || PanicExit
	fi
}

Usage()
{
	printf "usage: sh mtpf.sh <git source> [function]\n"
	exit 1
}

PanicExit()
{
	rm -Rf "$CLONE_DIST"
	exit 1
}

PressEnter()
{
	printf "mtpf> Press enter to continue" || PanicExit
	read NOTHING || PanicExit
}

Norminette()
{
	printf "RUNNING NORMINETTE\n" || PanicExit
	cd "$CLONE_DIST" || PanicExit
	norminette
}

WarMachine()
{
	printf "RUNNING LIBFT WAR MACHINE\n" || PanicExit
	git clone "https://github.com/y3ll0w42/libft-war-machine" "$CLONE_DIST/libft/warmachine" || PanicExit
	cd "$CLONE_DIST/libft/warmachine" || PanicExit
	bash grademe.sh || PanicExit
	if [ "$FUNCTION" = "" ]; then
		bash grademe.sh
	else
		bash grademe.sh "ft_$FUNCTION"
	fi
	cp -v "$PWD/deepthought" "$RESULT_DIR" || PanicExit
}

UnitTest()
{
	printf "RUNNING LIBFT UNIT TEST\n" || PanicExit
	git clone "https://github.com/alelievr/libft-unit-test" "$CLONE_DIST/unittest" || PanicExit
	cd "$CLONE_DIST/unittest" || PanicExit
	make || PanicExit
	if [ "$FUNCTION" = "" ]; then
		./run_test
	else
		./run_test "$FUNCTION"
	fi
	cp -v "$PWD/result.log" "$RESULT_DIR" || PanicExit
}

LibftTester()
{
	printf "RUNNING LIBFT TESTER\n" || PanicExit
	git clone "https://github.com/Tripouille/libftTester" "$CLONE_DIST/libft/libfttester" || PanicExit
	cd "$CLONE_DIST/libft/libfttester" || PanicExit
	sed -i -e '13cCC=g++' -e '14s/-ldl/-Wl,--no-as-needed -ldl/' Makefile
	if [ "$FUNCTION" = "" ]; then
		make a
	else
		make "$FUNCTION"
	fi
}

UPSTREAM="$1"
[ "$UPSTREAM" = "" ] && Usage
FUNCTION="$2"
CLONE_DIST="$(mktemp -d || exit 1)"
RESULT_DIR="$PWD"
Clone
Norminette
PressEnter
WarMachine
PressEnter
LibftTester
PressEnter
UnitTest
rm -Rf "$CLONE_DIR"
