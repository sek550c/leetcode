#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
'''
#import numpy as np
import time

# number of 1's of n = number of 1's of n & (n-1)+1
# faster method
def countBits(num):
	res = [0] * (num + 1) # init all zeros
	for i in xrange(1, num + 1):
		res[i] = res[i & (i-1)] + 1
	return res

# even:  
# number of 1's of n = number of 1's of n/2
# odd:
# number of 1's of n = number of 1's of n/2 + 1
def countBits2(num):
	res = [0] * (num + 1)
	for i in xrange(1, num + 1):
		if i % 2 == 0:	# even
			res[i] = res[i / 2]
		else: 			# odd
			res[i] = res[i / 2] + 1
	return res

n = 199
time0 = time.clock()	
res = countBits(n)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

res2 = countBits2(n)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)
