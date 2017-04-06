#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? 
'''
import time

# if array is sorted, binary search is preferred, otherwise xor is good

# math
def missingNumber(nums):
	n = len(nums)
	total = (n*n + n) / 2
	return total - sum(nums)

# xor	O(2n)
def missingNumber2(nums):
	xor = 0
	complete_nums = list(xrange(len(nums)+1)) # O(n) space
	for num in nums:
		xor ^= num
	for num in complete_nums:
		xor ^= num
	return xor
	
# another xor, O(n), no extra space
def missingNumber3(nums):
	xor = len(nums)
	for i in xrange(len(nums)):
		xor ^= i
		xor ^= nums[i]
	return xor
	
# pointer
def missingNumber4(nums):
	nums = sorted(nums)
	complete_nums = list(xrange(len(nums)+1)) # O(n) space
	i = 0
	while i < len(nums):
		if nums[i] != complete_nums[i]:
			return complete_nums[i] # not return nums[i]
		i += 1
	return complete_nums[-1]
	
# binary search
def missingNumber5(nums):
	nums = sorted(nums) # make sure it is sorted
	left, right = 0, len(nums)
	while left < right:
		mid = left + (right - left) / 2
		if nums[mid] > mid: # missing num in the left part
			right = mid # you CANNOT use mid-1 here !!!
		else:
			left = mid+1
	return left
	
	
nums = [9, 7, 11, 5, 6, 3, 0, 2, 1, 10, 14, 12, 13, 4]
time0 = time.clock()

print missingNumber(nums)
time1 = time.clock()
print 'math cost: %f s' % (time1 - time0)

print missingNumber2(nums)
time2 = time.clock()
print 'xor cost: %f s' % (time2 - time1)

print missingNumber3(nums)
time3 = time.clock()
print 'xor cost: %f s' % (time3 - time2)

print missingNumber4(nums)
time4 = time.clock()
print 'comparison cost: %f s' % (time4 - time3)

print missingNumber5(nums)
time5 = time.clock()
print 'binary search cost: %f s' % (time5 - time4)
