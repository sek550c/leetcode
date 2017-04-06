#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.


'''
import time

def rob(nums):
	planA, planB = 0, 0
	for i in xrange(len(nums)):
		if i % 2 == 0:
			planA = max(planB, planA + nums[i])
		else:
			planB = max(planA, planB + nums[i])
	return max(planA, planB)
	
def rob2(nums):
	PreRob, PreNotRob = 0, 0
	for i in xrange(len(nums)):
		CurRob = PreNotRob + nums[i] # rob
		CurNotRob = max(PreRob, PreNotRob)
		PreRob = CurRob
		PreNotRob = CurNotRob
	return max(PreRob, PreNotRob)
	
def rob3(nums):
	preRob, preNotRob = 0, 0
	for num in nums: # fater than rob2
		curRob = preNotRob + num
		curNotRob = max(preRob, preNotRob)
		preRob = curRob
		preNotRob = curNotRob
	return max(preRob, preNotRob)
	
	
nums = [1, 2, 4, 5, 3, 2, 8, 7]
time0 = time.clock()

print rob(nums)
time1 = time.clock()
print 'cost %f s' % (time1-time0)

print rob2(nums)
time2 = time.clock()
print 'cost %f s' % (time2-time1)

print rob3(nums)
time3 = time.clock()
print 'cost %f s' % (time3-time2)


