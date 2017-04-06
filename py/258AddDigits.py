#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime? 
'''
# naive method
def addDigits(num):
	res = 0
	while num >= 10: # keep doing
		res = 0
		while num: # calculate digit root
			res += num % 10
			num /= 10
		num = res
	return num

# digital root = num % 9 and need to consider when num is 0, 9 or 9 multiple
# see digital root: https://en.wikipedia.org/wiki/Digital_root
def addDigits1(num):
	if num == 0:
		return 0
	else: 
		return (num - 1) % 9 + 1

for i in xrange(30):
	print '%d: %d' %(i, addDigits(i))
	#print addDigits1(i)
