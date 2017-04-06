#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an integer, write a function to determine if it is a power of two. 
'''
import time
import math
import re # regular expression


# bit operation O(1)
def isPowerOfTwo(n):
	return n > 0 and n&(n-1) == 0

# loop O(logn)
def isPowerOfTwo2(n):
	while n and n % 2 == 0:
		n /= 2
	return n > 0 and n == 1

# recursive O(logn)
def isPowerOfTwo3(n):
	if n == 1: return True
	if n <= 0 or n % 2 == 1: return False
	return isPowerOfTwo3(n/2)

# math O(1)
# assume 32 bits, the max possible power of two = 2^30 = 1073741824.
# if n is 2^k, it is also divisor of max possible power of two
def isPowerOfTwo4(n):
	return n > 0 and 2**30 % n == 0

# math O(1)
def isPowerOfTwo5(n):
	k = math.log(n)/math.log(2)
	# return isinstance(k, int) # test if it is int type, but not good here
	# return k.isdigit() # this only work for string type
	# return re.match(r"d+$", k) # only work for string type
	# TODO
	# test float type number is an integer
	pass

n = 2**17
time0 = time.clock()
print 'is %d power of 2?' % n

print isPowerOfTwo(n)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print isPowerOfTwo2(n)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)

print isPowerOfTwo3(n)
time3 = time.clock()
print 'cost: %f s' % (time3-time2)

print isPowerOfTwo4(n)
time4 = time.clock()
print 'cost: %f s' % (time4-time3)

'''
print isPowerOfTwo5(n)
time5 = time.clock()
print 'cost: %f s' % (time5-time4)
'''
