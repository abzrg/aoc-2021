#!/usr/bin/env sh

set -e

# Run from this directory
cd ${0%/*} || exit 1

DAY=$1
# If user didn't provide any input argument to the script
[ $# = 0 ] && read -p "Fetch input for which day? " DAY

# Fetch input data of day $DAY from adventofcode.com using curl and session
# cookie stored in .cookie file
curl -s -H "Cookie: session=$(cat .cookie)" \
    https://adventofcode.com/2021/day/${DAY#0}/input > ../$DAY/input.txt

# With slight change to:
# https://www.github.com/lento234/advent2021/tools/fetch_input.sh
