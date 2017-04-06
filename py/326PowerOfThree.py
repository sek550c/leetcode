#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion? 
'''
import time

# loop keep dividing
def isPowerOfThree(n):
	if n <= 0: return False
	while n%3 == 0:
		n /= 3
	return n == 1

# math
# assume 3**20 is the possible max power of 3
# in general, use max = 3**(log(max_int)/log3)
def isPowerOfThree2(n):
	return n > 0 and 3**20 % n == 0

n = 3**7
time0 = time.clock()
print 'is %d power of 3?' % n

print isPowerOfThree(n)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print isPowerOfThree2(n)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)
