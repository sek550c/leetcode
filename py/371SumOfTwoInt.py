#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3. 

'''

# this does not work for -1 and +1
# however in C it works, probably interpreters are different 
def getSum(a, b):
	res, c = 0, -1
	while c != 0: # carry exists
		res = a^b # xor => add without carry
		c = (a&b) << 1 # and => carry
		a, b = res, c
	return res

# for fun
def getSum2(a, b):
	return sum([a, b])

print 'sum: ', getSum(7, 6)
print 'sum: ', getSum2(1, -1)
