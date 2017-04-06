#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
          ↑   ↑

The above arrows point to positions where the corresponding bits are different.
'''
import time
#https://tech.liuchao.me/2016/11/count-bits-of-integer/

def hammingDistance(x, y):
	n, count = x^y, 0
	while n:
		count += 1
		n = n&(n-1)
	return count

def hammingDistance2(x, y):
	n, count = x^y, 0
	while n: # 32-bit
		count += n & 1
		n >>= 1
	return count
	
def hammingDistance3(x, y):
	return bin(x^y).count('1')

x = 1
y = 2
time0 = time.clock()

print 'Hamming distance: %d' %(hammingDistance(x, y))
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print 'Hamming distance: %d' %(hammingDistance2(x, y))
time2 = time.clock()
print 'cost: %f s' % (time2-time1)

print 'Hamming distance: %d' %(hammingDistance3(x, y))
time3 = time.clock()
print 'cost: %f s' % (time3-time2)
