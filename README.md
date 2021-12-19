<div align="center">

# 🎅🎄 Advent of Code 2021 ☃️❄️

![](https://img.shields.io/badge/stars%20⭐-4-gold.svg)

![Last commit](https://img.shields.io/github/last-commit/reverseila/aoc-2021)
[![GitHub license](https://img.shields.io/github/license/reverseila/aoc-2021?color=blue)](https://github.com/reverseila/aoc-2021/blob/main/LICENSE)

</div>

## Description

- [Advent of code 2021](https://adventofcode.com/2021/)
- [Awesome Advent of Code](https://github.com/Bogdanp/awesome-advent-of-code)


Advent of Code is an Advent calendar of small programming puzzles for a variety
of skill sets and skill levels that can be solved in any programming language
you like. People use them as a speed contest, interview prep, company training,
university coursework, practice problems, or to challenge each other. 

If you have doubts:

- [About Advent of Code](https://adventofcode.com/2021/about)
- [What would you say are the minimal skills for beginners?](https://old.reddit.com/r/adventofcode/comments/7kd8jt/what_would_you_say_are_the_minimal_skills_for/dre0uu3/)

## Dependencies

- Clang compiler (`v13.0.0`)
- Clang libc++ (`v13.0.0`)
  - Of course you can change the compiler and Standard Library implementation
    via the settings in the `Makefile`
    - compiler: `CXX = clang++ | g++`
    - Standard Library: `CXX_FLAGS += -stdlib=libstdc++ | -stdlib=libstdc++`
- Valgrind (`v3.17.0`)
- GNU coreutils (`v9.0`)
- Curl (`v7.80.0`)
- Pandoc (`v2.14.1`)


## Benchmark

Performance benchmarked on `Pentium E5300 (2) @ 2.600GHz`, `clang 13.0.0`, and
with flags `-stdlib=libc++ -Ofast -march=native`. Memory usage profiled using
`valgrind`. Note that in order to determine the fastest execution time, I ran
each program 100 times and extract the fastest execution time, per the script
`benchmark.sh`.

|            Day          | Problem                     | Runtime (μs) |   Memory | Performance graph (`█ == 250 μs`)    |
| :---------------------: | :-------------------------- | -----------: | -------: | :----------------------------------- |
| [`01`](01/src/main.cpp) | **Sonar Sweep**             |          501 |   137 kB | `██`                                 |
| [`02`](02/src/main.cpp) | **Dive!**                   |          551 |   249 kB | `██`                                 |


## Scoreboard

```
      --------Part 1---------   --------Part 2---------
Day       Time    Rank  Score       Time    Rank  Score
  2       >24h  166610      0       >24h  161935      0
  1       >24h  198590      0       >24h  179292      0
```

## Credit

Thanks to [Lento Manickathan](https://github.com/lento234) I learned how to
write a proper README.md and organize my whole project. I also learned a lot by
looking at [the way you write](https://github.com/lento234/advent2021) utilities
for the project. So, thank you Lento!
