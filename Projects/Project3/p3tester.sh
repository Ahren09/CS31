#!bin/bash

NAME=poll
TESTMAIN=test_main
PROG=sdfuiewpoweupoiwupqrne

if [ ! -r $NAME.cpp ]
 then	echo "Your current directory is $PWD"
	echo "There is no readable file in this directory named $NAME.cpp"
	echo "Here's what's in this directory:"
	ls
	exit 1
fi

GXX="g++ -std=c++17 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -fsanitize=bounds $OPT -Wall -Wextra -Wno-sign-compare -Werror=return-type "

if ! $GXX -o $PROG $NAME.cpp $TESTMAIN.cpp
 then	cat <<\END-END-END
Your program failed to build.
END-END-END
	exit 1
fi

./$PROG

rm $PROG

