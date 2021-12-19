#!/usr/bin/env sh

# Advent of code 2021
# Ali Bozorgzadeh <https:/github.com/reverseila>

# This script prints the execution time of a program (output of std::chrono) and
# its memory usage (using valgrind tool)
# Note that as each execution may have different runtime, I run the program 100
# times and report the quickest execution

set -e

_usage() {
    printf "Usage: %s path/to/EXE" `basename $0`
}

[ $# != 1 ] && _usage && exit 1


###############################################################################
# Runtime                                                                     #
###############################################################################

printf "Calculating runtime...\n"

# Run it 100 times and report the quickest execution
_runtime_=$(for i in `seq 1 100`
do
    $1 | grep 'Summary' | awk '{print $5$6}' | tr -d ']'
done | sort -n | head -n 1)


###############################################################################
# Memory usage                                                                #
###############################################################################

printf "Calculating memory usage...\n"

# Store the result of the valgrind in a temporary file
_temp_log_="$(mktemp)"
trap 'rm -rf -- "$_temp_log_"' EXIT

# Note that If you just pipe the result of the valgrind it will produce
# different result (Not sure why). For that I have to specify a log file to have
# its output in a file, so that then I can process the correct results
valgrind --log-file="${_temp_log_}" $1

# Extract memory usage
_mem_usage_=$(cat "$_temp_log_" \
    | grep 'total heap' \
    | awk '{print $9}' \
    | tr -d ',' \
    | numfmt --to=iec-i --suffix=B)

# Report the results
printf "Run time: %s\nMemory: %s\n" $_runtime_ $_mem_usage_
