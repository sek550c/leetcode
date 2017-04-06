#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
'''
import time

# hash table
def twoSum(nums, target):
	hashtable = {}
	for i, num in enumerate(nums):
		if (target-num) in hashtable:
			return [hashtable[target-num], i+1]
		hashtable[num] = i+1
	return []

# two pointer O(N)
def twoSum2(nums, target):
	low, high = 0, len(nums)-1
	while low < high:
		res = nums[low] + nums[high]
		if res == target:
			return [low+1, high+1]
		elif res > target:
			high -= 1
		else:
			low += 1
	return []

# binary search
def binarysearch(nums, low, high, target):
	while low <= high: # '<=' important
		mid = low + (high-low)/2
		if nums[mid] == target:
			return mid
		elif nums[mid] < target:
			low = mid+1
		else:
			high = mid-1
	return -1 # not found
	
def twoSum3(nums, target):
	for i, num in enumerate(nums):
		idx = binarysearch(nums, i+1, len(nums)-1, target-num) # find right part of nums
		if idx == -1:
			continue # next iteration
		return [i+1, idx+1]
	return []
		
		
nums = [2, 3, 4]
target = 6
time0 = time.clock()

print 'index: ', twoSum(nums, target)
time1 = time.clock()
print 'cost %f s' % (time1 - time0)

print 'index: ', twoSum2(nums, target)
time2 = time.clock()
print 'cost %f s' % (time2 - time1)

print 'index: ', twoSum3(nums, target)
time3 = time.clock()
print 'cost %f s' % (time3 - time2)
