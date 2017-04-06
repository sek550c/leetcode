#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
  Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

'''
import time

# hash table 
def singleNumber(nums):
	hashtable = {}
	res = []
	for num in nums: # save to hash
		hashtable[num] = hashtable.get(num, 0) + 1
	for num in nums: # find
		if hashtable[num] == 1:
			res.append(num)
	return res
	
# set
# NOTE: this method is Time Limit Exceeded on leetcode.com
def singleNumber2(nums):
	res = []
	for num in set(nums):
		if nums.count(num) == 1:
			res.append(num)
	return res

# xor
def singleNumber3(nums):
	xor, a, b = 0, 0, 0
	for num in nums:
		xor ^= num 
	# xor = a^b 0110
	# mask = xor & (-xor) # this also works(need to understand 2's complement)
	mask = 1
	# equivalent to keep the most right 1 and set other bits 0
	while(xor & mask == 0):
		mask = mask << 1
	# mask = 0010
	# we divide nums into two sets: 
	for num in nums:
		if num & mask:	# 1. num has form: __1_ and a is among these nums
			a ^= num
		else:			# 2. num has form: __0_ and b is among these nums
			b ^= num
	return [a, b]


nums = [1, 2, 1, 3, 2, 5]
time0 = time.clock()
print singleNumber(nums)
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)

print singleNumber2(nums)
time2 = time.clock()
print 'cost: %f s' % (time2 - time1)

print singleNumber3(nums)
time3 = time.clock()
print 'cost: %f s' % (time3 - time2)
