#!/usr/bin/env sh

set -e

[ $# != 1 ] && echo "Usage: `basename $0` path/to/EXE" && exit 1

printf "Calculating runtime...\n"
# Run it 100 time and report the quickest execution
_runtime_=$(for i in `seq 1 100`
do
    $1 | grep 'Summary' | awk '{print $5$6}' | tr -d ']'
done | sort -n | head -n 1)

printf "Calculating memory usage...\n"
# Memory usage
_mem_usage_=$(valgrind $1 2>&1 \
    | grep 'total heap' \
    | awk '{print $9}' \
    | tr -d ',' \
    | numfmt --to=iec-i --suffix=B)

printf "Run time: %s\nMemory: %s\n" $_runtime_ $_mem_usage_
