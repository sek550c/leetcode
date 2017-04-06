#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
'''
import time

# two pointer
def moveZeroes(nums):
	cur, zero = 0, 0
	while cur < len(nums):
		if nums[cur] != 0: # not zero
			if cur != zero:
				nums[cur], nums[zero] = nums[zero], nums[cur] # swap with zero
			zero += 1 # and zero plus 1
		cur += 1
	return nums

# pop and append
def moveZeroes2(nums):
	for x in nums:
		if x == 0:
			nums.pop(nums.index(x))
			nums.append(x)
	return nums
	
nums = [0, 1, 0, 0, 3, 2]
time0 = time.clock()
print  moveZeroes(nums)
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)

print  moveZeroes2(nums)
time2 = time.clock()
print 'cost: %f s' % (time2 - time1)
