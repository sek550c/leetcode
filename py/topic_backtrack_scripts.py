#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time

# decorator
def start_finish(f):
    def new_f(*args, **kwargs):
        print("%s starting..."%(f.__name__))
        start_time = time.perf_counter()
        f(*args, **kwargs)
        end_time = time.perf_counter()
        print("%s finished. %f s elapsed."%(f.__name__, end_time - start_time))
    return new_f

####################################################
### 22 Generate Parentheses ###
"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
"""
def generateParenthesis(n):
    res = []

    # 回溯
    def generateParenthesisDFS(res, parentheses, leftRemain, rightRemain):
        if leftRemain > rightRemain or leftRemain < 0 or rightRemain < 0: # 回溯条件
            return
        if leftRemain == 0 and rightRemain == 0: # 返回结果, 注意是and
            res.append(parentheses)
            return res
        generateParenthesisDFS(res, parentheses+"(", leftRemain-1, rightRemain)
        generateParenthesisDFS(res, parentheses+")", leftRemain, rightRemain-1)

    generateParenthesisDFS(res, "", n, n)
    return res


@start_finish
def generateParenthesisMain():
    for n in range(1, 5):
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
    if len(nums) == 0:
        return res

    # 回溯
    def combinationSumDFS(nums, target, begin, path, res):
        path = path[:] # python2, 只拷贝一层，对于对象中含对象，需要使用深拷贝deepcopy()
        # 递归终止条件，当余数target==0时，我们找到了这样一组答案res
        if target == 0:
            res.append(path)
            return
        # 当余数target！=0，我们继续探索数组中的元素
        for i in range(begin, len(nums)): # 注意是从begin开始，表示可以重复使用元素
            # 如果加上元素后超过目标值，则表示此元素不符合条件，返回
            if target - nums[i] < 0:
                return
            # 如果没超过目标值，进入下一层
            path.append(nums[i])
            combinationSumDFS(nums, target-nums[i], i, path, res)
            # 下一层返回上来的，表示此节点不符合条件，舍去
            path.pop()      

    res = []
    path = []
    nums = sorted(nums)
    combinationSumDFS(nums, target, 0, path, res)
    return res

@start_finish
def combinationSumMain():
    nums = [2,3,6,7]
    target = 7
    print("nums = %s, taget = %s, result: %s"%(nums, target, combinationSum(nums, target)))
####################################################

### 17. Letter Combinations of a Phone Number ###
"""
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does
not map to any letters.
eg.
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
"""

def letterCombinations(digits):
    if digits == '': return []
    lettermap = {
                    '2':['a','b','c'],
                    '3':['d','e','f'],
                    '4':['g','h','i'],
                    '5':['j','k','l'],
                    '6':['m','n','o'],
                    '7':['p','q','r','s'],
                    '8':['t','u','v'],
                    '9':['w','x','y','z']
                    }
    # 回溯法
    def letterCombinationsDFS(combination, nextdigit): 
        if nextdigit == '':
            return res.append(combination)
        else:
            for letter in lettermap[nextdigit[0]]:
                letterCombinationsDFS(combination + letter, nextdigit[1:])
                
    res = []
    letterCombinationsDFS('', digits)
    return res

def letterCombinations2(digits):
    lettermap = {
                    '2':['a','b','c'],
                    '3':['d','e','f'],
                    '4':['g','h','i'],
                    '5':['j','k','l'],
                    '6':['m','n','o'],
                    '7':['p','q','r','s'],
                    '8':['t','u','v'],
                    '9':['w','x','y','z']
                    }
    res = ['']
    if digits == '':
        return res
    for n in digits:
        res = [pre+suf for pre in res for suf in lettermap[n]]
    return res

@start_finish
def letterCombinationsMain():
    digits = '23'
    print("input digits = %s, letter combinations: %s"%(digits, letterCombinations(digits)))
####################################################

"""
blabla
"""
if __name__ == '__main__':
    # generateParenthesisMain()
    # combinationSumMain()
    letterCombinationsMain()