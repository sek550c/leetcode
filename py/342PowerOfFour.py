#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion? 
'''
import time

# loop
def isPowerOfFour(n):
	while n > 0 and n % 4 == 0:
		n /= 4
	return n == 1

# this func not work properly	
def isPowerOfFour2(n):
	return n > 0 and 4**15 % n == 0 # not work
	
def isPowerOfFour3(n):
	mask = 0x55555555 # 01010101...(32 bits)
	return n > 0 and n & (n-1) == 0 and n & mask != 0

# Mathematical Induction proof:
# k = 0 => 4^0-1 = 0 => 0 % 3 = 0
# assume k = n => (4^n - 1) % 3 = 0
# k = n + 1 => 4^(n+1) - 1 = 4*4^n - 1 = 4*(4^n - 1) + 3, according to assumption (4^n - 1) % 3 = 0, so [4*(4^n - 1) + 3] % 3 = 0
# hence, (4^n - 1) is dividable by 3
def isPowerOfFour4(n):
	return n > 0 and n & (n-1) == 0 and (n-1) % 3 == 0

n = 4**10
time0 = time.clock()
print 'is %d power of 4?' % n

print isPowerOfFour(n)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print isPowerOfFour2(n)
time2 = time.clock()
print 'this method not working properly'
print 'cost: %f s' % (time2-time1)

print isPowerOfFour3(n)
time3 = time.clock()
print 'cost: %f s' % (time3-time2)

print isPowerOfFour4(n)
time4 = time.clock()
print 'cost: %f s' % (time4-time3)
