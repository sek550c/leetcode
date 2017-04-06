#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

'''
import time

# count
def majorityElement(nums):
	for num in nums:
		if nums.count(num) > len(nums)/2:
			return num
	return 0

# sort	
def majorityElement2(nums):
	return sorted(nums)[len(nums)/2]

# hash
def majorityElement3(nums):
	hashtable = {}
	count = len(nums)/2
	for num in nums:
		if num in hashtable:
			hashtable[num] += 1
			if hashtable[num] > count: # you need to compare AFTER EVERY update!
				return num
		else:
			hashtable[num] = 1
			if hashtable[num] > count: # you need to compare AFTER EVERY update! for test case [1]
				return num
	return 0

#Boyer-Moore Majority Vote Algorithm # majority must exist
#http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
# O(n)
def majorityElement4(nums):
	major, count = nums[0], 1
	for i in xrange(1, len(nums)):
		if count == 0:
			major = nums[i] # change major
			count = 1
		elif major == nums[i]:
			count += 1
		else:
			count -= 1
	return major
			

nums = [1, 1, 2, 4, 5, 1, 4, 2, 4, 2, 4, 1, 5, 1, 5, 2, 1, 1, 1, 1, 1, 1, 1, 1] # make sure the majority exists!!!

time0 = time.clock()

print majorityElement(nums)
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)

print majorityElement2(nums)
time2 = time.clock()
print 'cost: %f s' % (time2 - time1)

print majorityElement3(nums)
time3 = time.clock()
print 'cost: %f s' % (time3 - time2)

print majorityElement4(nums)
time4 = time.clock()
print 'cost: %f s' % (time4 - time3)
