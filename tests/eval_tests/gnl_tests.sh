BUFF_SIZE=8

if [ $1 = 'clean' ]; then
	/bin/rm	-f *.o
	/bin/rm -f tests_basic tests_middle tests_advanced tests_error tests_buff tests_multifd tests_custom tests_bible
	/bin/rm -f testfiles/bible.txt testfiles/bible2.txt
	/bin/rm	-f ../get_next_line.o
	exit 1
fi

if [ $1 = 'make' ]; then
	make -C ../libft
	exit 1
fi

if [ $1 = 'all' ]; then
	./gnl_tests.sh 1
	./gnl_tests.sh 2
	./gnl_tests.sh 3
	./gnl_tests.sh 4
	./gnl_tests.sh 5
	./gnl_tests.sh 6
	./gnl_tests.sh 7
	exit 1
fi

if [ $1 -eq 1 ]; then

printf "\033[0;35m======================= BASIC TESTS =======================\033[0m\n"
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_basic_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_basic $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_basic

printf "\n\033[0;35m===========================================================\033[0m\n"

fi

if [ $1 -eq 2 ]; then

printf "\033[0;35m======================= MIDDLE TESTS =======================\033[0m\n"
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_middle_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_middle $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_middle

printf "\n\033[0;35m===========================================================\033[0m\n"

fi

if [ $1 -eq 3 ]; then

printf "\033[0;35m======================= ADVANCED TESTS =======================\033[0m\n"
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_advanced_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_advanced $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_advanced

printf "\n\033[0;35m=============================================================\033[0m\n"

fi

if [ $1 -eq 4 ]; then

printf "\033[0;35m======================= ERROR MANAGEMENT =======================\033[0m\n"
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_errors_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_error $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_error

printf "\n\033[0;35m===============================================================\033[0m\n"

fi

if [ $1 -eq 5 ]; then

printf "\033[0;35m======================= BUFF_SIZE 1 =======================\033[0m\n"
BUFF_SIZE=1
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_basic_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_buff $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_buff

printf "\n\033[0;35m===============================================================\033[0m\n"

printf "\033[0;35m======================= BUFF_SIZE 32 =======================\033[0m\n"
BUFF_SIZE=32
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_basic_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_buff $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_buff

printf "\n\033[0;35m===============================================================\033[0m\n"

printf "\033[0;35m======================= BUFF_SIZE 9999 =======================\033[0m\n"
BUFF_SIZE=9999
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_basic_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_buff $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_buff

printf "\n\033[0;35m===============================================================\033[0m\n"

printf "\033[0;35m======================= BUFF_SIZE 10000000 =======================\033[0m\n"
BUFF_SIZE=10000000
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_basic_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_buff $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_buff

printf "\n\033[0;35m===============================================================\033[0m\n"

fi

if [ $1 -eq 6 ]; then

printf "\033[0;35m======================= MULTIPLE FD =======================\033[0m\n"
BUFF_SIZE=8
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_multifd_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_multifd $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_multifd

printf "\n\033[0;35m===============================================================\033[0m\n"

fi

if [ $1 -eq 7 ]; then

printf "\033[0;35m======================== CUSTOM TESTS =========================\033[0m\n"
BUFF_SIZE=8
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_custom_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_custom $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_custom $2 $3

printf "\n\033[0;35m===============================================================\033[0m\n"

fi

if [ $1 -eq 8 ]; then

printf "\033[0;35m===================== BIBLE 1000000 BUFF ========================\033[0m\n"
BUFF_SIZE=1000000
printf "BUFF_SIZE="
printf $BUFF_SIZE
printf "\n\n"

TESTMAIN="tests_bible_main"

clang -Wall -Wextra -Werror -g -I ../libft/includes -DBUFF_SIZE=$BUFF_SIZE -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -g -I ../libft/includes -o $TESTMAIN.o -c -x c $TESTMAIN.test

clang -o tests_bible $TESTMAIN.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

./tests_bible

printf "\n\033[0;35m===============================================================\033[0m\n"

fi