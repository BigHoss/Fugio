#!/bin/bash

FILES=$1/*.dylib

for f in $FILES
do
  echo "Processing $f file..."

  deps=($( otool -L $f | grep '/usr/local/\|@executable_path/../Frameworks/lib' | cut -f 1 -d '(' - | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//' ))

  for d in "${deps[@]}"
  do
    if [ -n "$d" ]; then
      echo "Dependency: $d..."

      base=$(basename "$d")

      command="install_name_tool -change $d @rpath/$base $f"

      #echo "$command"

      eval $command
    fi
  done
done

