#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
	
 Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

'''

def twoSum(nums, target):
	hashtable = {}
	for index, num in enumerate(nums):
		# find
		if (target - num) in hashtable:
			return [hashtable[(target - num)], index]
        # not find then store
		hashtable[num] = index
        
	return [] # not found
	
nums = [2, 7, 11, 15]
target = 13
print 'index: ', twoSum(nums, target)
