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

def combinationSum(nums, target):
    if len(nums) == 0:
        return res
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
"""
blabla
"""
if __name__ == '__main__':
    generateParenthesisMain()
    # combinationSumMain()