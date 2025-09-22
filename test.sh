#!/bin/bash

cloneurl=`git remote -v | cut -d ' ' -f 1 | cut -d $'\t' -f 2 | head -n 1`;
temp="temp";

git clone $cloneurl $temp


cd $temp


if make compile && make run; then
  echo "\nCompile and run succeeded!"
else
  echo "Compile and run failed"
fi

cd ..

rm -rf $temp

echo "repo removed"
