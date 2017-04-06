#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
'''

def productExceptSelf(nums):
	res = []
	front, behind = 1, 1
	for i in xrange(len(nums)): # ->
		res.append(front)
		front *= nums[i]
	for i in xrange(len(nums)-1, -1, -1): # <- # xrange(start, end(exclusive), increment)
		print i
		res[i] *= behind
		behind *= nums[i]
	return res
	
nums = [1, 2, 3, 4]
print productExceptSelf(nums)

''' for test use only
print ' '
for i in xrange(10, 0, -1):
	print i
'''
