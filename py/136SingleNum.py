#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

'''
import time
'''
      |xor
----------
0 | 0 | 0
0 | 1 | 1
1 | 0 | 1
1 | 1 | 0
'''
# XOR
def singleNumber(nums):
	temp = nums[0]
	for i in xrange(1, len(nums)):
		temp ^= nums[i] # if use nums[0] ^= nums[i], this will change nums[0]
	return temp

# sum difference
def singleNumber2(nums):
	return 2 * sum(set(nums)) - sum(nums)

# hashtable
def singleNumber3(nums):
	hashtable = {}
	for num in nums:		
		if num in hashtable:
			hashtable[num] += 1
		else:
			hashtable[num] = 1
	for num in nums:
		if hashtable[num] == 1:
			return num 

# hashtable 
def singleNumber4(nums):
	hashtable = {}
	for num in nums:		
		hashtable[num] = hashtable.get(num, 0) + 1 # same to method 3 but with nice implementation
	for num in nums:
		if hashtable[num] == 1:
			return num 

nums = [1, 1, 4, 2, 3, 3, 2]
time0 = time.clock()

print 'single number(XOR method): ', singleNumber(nums)
time1 = time.clock()
print 'cost %f s' % (time1 - time0)

print 'single number(sum diff): ', singleNumber2(nums)
time2 = time.clock()
print 'cost %f s' % (time2 - time1)

print 'single number(hash table): ', singleNumber3(nums)
time3 = time.clock()
print 'cost %f s' % (time3 - time2)

print 'single number(hash table 2): ', singleNumber4(nums)
time4 = time.clock()
print 'cost %f s' % (time4 - time3)

