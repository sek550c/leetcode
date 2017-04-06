#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number. 
'''
import time

def isUgly(num):
	if num <= 0: return False
	while num % 5 == 0:
		num /= 5
	while num % 3 == 0:
		num /= 3
	while num % 2 == 0:
		num /= 2
	return num == 1

# more concise way
def isUgly2(num):
	if num <= 0: return False
	for p in 2, 3, 5:
		while num % p == 0:
		    num /= p
	return num == 1
	
n = 120
time0 = time.clock()

print isUgly(n)
time1 = time.clock()
print 'cost %f s' % (time1-time0)

print isUgly2(n)
time2 = time.clock()
print 'cost %f s' % (time2-time1)
	
