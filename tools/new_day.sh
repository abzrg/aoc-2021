#!/usr/bin/env sh

set -e

# Run from this directory
cd ${0%/*} || exit 1

DAY=$1
# If user didn't provide any input argument to the script
[ $# = 0 ] && read -p "Create which day? " DAY

# Make new directory
# Copy template to new day
mkdir -v ../$DAY \
    && cp -rv ../template/day00/* ../$DAY/ \
    && find ../$DAY -type f -exec sed -i "s/00/$DAY/g" {} \;

# With slight change to:
# https://www.github.com/lento234/advent2021/tools/new_day.sh
