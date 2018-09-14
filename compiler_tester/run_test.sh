#!/usr/bin/env bash

#For remove all *.cor files
if [ "$1" = "-c" ]
then
    find . -name '*.cor' -delete
    exit 1
elif [ "$1" = "-ca" ]
then
    rm -rf ./my/
    rm -rd ./original/
    exit 1
fi


#Remove all files from folders before compiling
for cor in ./my
do
    rm -rf "$cor"
done

for cor in ./original/
do
    rm -rf "$cor"
done


#Copy bots to folders
mkdir -p my
mkdir -p original

for bot in ./bots/*.s
do
    cp "$bot" my/
    cp "$bot" original/
done






#compile files with 2 different compilers
for org in ./original/*.s
do
    ./asm_original "$org"
done

for my in ./my/*.s
do
    ./asm_my "$my"
done

#compare result
diff -rq my/ original/ > result.txt



#TODO (1) Make only 1 dir with boot, copy to 2 dir before compiling