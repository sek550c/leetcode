#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
'''
import time

# back tracking/DFS method see c++ implementation

# 9*9*8*7*6*5*4*3*2
def countNumbersWithUniqueDigits(n):
	if n == 0: return 1 
	if n == 1: return 10 
	count = 10 # base, start with 2
	for k in xrange(2, n+1):
		ans = 9
		for i in xrange(2, min(10, k+1)):
			ans *= 11 - i
		count += ans
	return count

time0 = time.clock()

n = 2
print countNumbersWithUniqueDigits(n)
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)
