#!/bin/bash
gcc ./src/test.c ./src/user.c -o tr -std=c89 -Wall -Wextra -Werror -Wpedantic
./tr
rm tr
