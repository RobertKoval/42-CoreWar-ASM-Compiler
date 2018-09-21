#!/usr/bin/env bash

#Remove all *.cor files or clean pre-build directories
if [ "$1" = "-cor" ]
then
    find . -name '*.cor' -delete
    exit 1
elif [ "$1" = "-all" ]
then
    rm -rf ./my/
    rm -rf ./original/
    rm compile.log
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
rm compile.log
#Copy bots to pre-build directories
mkdir -p my
mkdir -p original

for bot in ./bots/*.s
do
    cp "$bot" my/
    cp "$bot" original/
done

#compile bots
for org in ./original/*.s
do
    ./asm_original "$org" >/dev/null
done

for my in ./my/*.s
do
    echo "$my" >> compile.log
    ./asm_my "$my" >> compile.log  2>&1
    echo "" >> compile.log
done

#compare result and save
diff -rq my/ original/ > result.txt
