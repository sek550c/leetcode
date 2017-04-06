#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
'''
import time

#https://tech.liuchao.me/2016/11/count-bits-of-integer/

# n's 1 bit number = n&(n-1) 's 1 bit number + 1
# or: use n&(n-1) trick to clear the least bit
# too slow when n is large
def hammingWeight(n):
	if n == 0: return 0
	return hammingWeight(n&(n-1))+1
	
def hammingWeight2(n): # much faster than recursive method
	count = 0
	while n:
		count += 1
		n = n&(n-1) # this will clear the right one
	return count

def hammingWeight3(n):
	count = 0
	while n:
		count += (n>>i) & 1
	return count

def hammingWeight4(n): # much faster than recursive method
	return bin(n).count('1')

	
n = 2**59-1
time0 = time.clock()

print 'number of 1''s: %d ' % hammingWeight(n)
time1 = time.clock()
print 'cost %f s' % (time1-time0)

print 'number of 1''s: %d ' % hammingWeight2(n)
time2 = time.clock()
print 'cost %f s' % (time2-time1)

print 'number of 1''s: %d ' % hammingWeight3(n)
time3 = time.clock()
print 'cost %f s' % (time3-time2)

print 'number of 1''s: %d ' % hammingWeight4(n)
time4 = time.clock()
print 'cost %f s' % (time4-time3)
