#!/usr/bin/env sh

set -e

# Run from this directory
cd ${0%/*} || exit 1

DAY=$1
# If user didn't provide any input argument to the script
[ $# = 0 ] && read -p "Fetch README for which day? " DAY

printf "# Day %s\n\n" $DAY > ../$DAY/README.md

# Fetch day $DAY using curl and cookie
# convert from HTML to pandoc
# delete all unwanted lines and HTML tags containing {}
# write to README.md
curl -s -H "Cookie: session=$(cat .cookie)" \
    https://adventofcode.com/2021/day/${DAY#0} | pandoc -f html -t markdown \
    | sed -e '/<div>/,/::: {role="main"}/d' -e '/Both parts of this puzzle are complete!/,//d' -e 's/{[^{}]*}//g' \
    >> ../$DAY/README.md

# With slight change to:
# https://www.github.com/lento234/advent2021/tools/fetch_readme.sh
