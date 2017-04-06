#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58. 
'''

'''
2	1+1		1
3	2+1		2
4	2+2		4
5	3+2		6
6	3+3		9
7	3+4		12
8	3+3+2	18
9	3+3+3	27
10	3+3+4	36
11	3+3+3+2	54
12	3+3+3+3	81

'''
# contains how many 3
def integerBreak(n):
	if n < 2: return -1
	if n < 4: return n-1
	prod = 1
	while n > 4:
		n -= 3
		prod *= 3
	return n*prod

for n in xrange(2, 20):
	print '%d: %d' % (n, integerBreak(n))
