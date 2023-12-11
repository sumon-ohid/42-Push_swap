# push_swap

## Introduction
Push Swap is a project that involves sorting a stack of integers using two stacks and a specific set of instructions. The goal is to implement an algorithm that efficiently sorts the stack with the minimum possible number of moves. This project is part of the 42 school curriculum and is designed to test algorithmic and problem-solving skills.

You can use the checker program to verify if the output instructions correctly sort the stack:

## For MAC
```bash
git clone git@github.com:julien-ctx/push-swap-tester.git && mv push-swap-tester/tester.py . && mv push-swap-tester/checker_Mac . && rm -rf push-swap-tester && chmod 777 checker_Mac && make && python3 tester.py
```
## For LINUX

```bash
git clone git@github.com:julien-ctx/push-swap-tester.git && mv push-swap-tester/tester.py . && mv push-swap-tester/checker_linux . && rm -rf push-swap-tester && chmod 777 checker_linux && sed -i -- 's/checker_Mac/checker_linux/g' tester.py && make && python3 tester.py
```
## Algorithm
I used Radix Sort for my project.
[Radix Sort Explained](https://www.geeksforgeeks.org/radix-sort/)
