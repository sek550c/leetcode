#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# decorator
def start_finish(f):
    def new_f(*args, **kwargs):
        print("%s starting..."%(f.__name__))
        f(*args, **kwargs)
        print("%s finished."%(f.__name__))
    return new_f

####################################################
### 22 Generate Parentheses ###
"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
"""
def generateParenthesisDFS(res, parentheses, leftRemain, rightRemain):
    if leftRemain > rightRemain or leftRemain < 0 or rightRemain < 0: # 回溯条件
        return
    if leftRemain == 0 and rightRemain == 0: # 返回结果, 注意是and
        res.append(parentheses)
        return res
    generateParenthesisDFS(res, parentheses+"(", leftRemain-1, rightRemain)
    generateParenthesisDFS(res, parentheses+")", leftRemain, rightRemain-1)

def generateParenthesis(n):
    res = []
    generateParenthesisDFS(res, "", n, n)
    return res


@start_finish
def generateParenthesisMain():
    for n in xrange(1, 5):
        print("generate n = %s valid Parenthesis: %s"%(n, generateParenthesis(n)))
####################################################

### 39 Combination Sum ###
"""
Given a set of candidate numbers ( candidates ) (without duplicates) and a target number
( target ), find all unique combinations in candidates where the candidate numbers sums to
target .
The same repeated number may be chosen from candidates unlimited number of times.
Note:
All numbers (including target ) will be positive integers.
The solution set must not contain duplicate combinations.
eg.
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
[7],
[2,2,3]
]
"""
def combinationSum(nums, target):
    res = []
    return res


@start_finish
def combinationSumMain():
    nums = [2,3,6,7]
    target = 7
    print("nums = %s, taget = %s, result: %s"%(nums, target, combinationSum(nums, target)))
####################################################
"""
blabla
"""
if __name__ == '__main__':
    generateParenthesisMain()
    combinationSumMain()