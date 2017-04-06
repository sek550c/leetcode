#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1

'''
import time

def DigSquSum(n):
	res, tmp = 0, 0
	while n:
		tmp = n % 10
		res += tmp*tmp
		n /= 10
	return res

# display, for debug use
def printRecord(n):
	record = set([])
	while 1:
		if n == 1: break
		if n in record: return False
		else: record.add(n)
		n = DigSquSum(n)
		
def isHappy(n):
	if n <= 0: return False
	record = set([]) # keep tracking
	while 1:
		if n == 1: return True
		if n in record: return False
		else: record.add(n)
		n = DigSquSum(n)

# Floyd Cycle detection algorithm
def isHappy2(n):
	if n <= 0: return False
	slow, fast = n, n
	while 1: # this part work as do...while
		slow = DigSquSum(slow)
		fast = DigSquSum(fast)
		fast = DigSquSum(fast) # fast go twice
		if fast == 1: return True
		if slow == fast: break # slow catch up with fast, which means repeat
	return False
	
# https://en.wikipedia.org/wiki/Happy_number#Sequence_behavior
def isHappy3(n):
	if n == 1: return True
	if n == 4: return False
	return isHappy3(DigSquSum(n))
	
def isHappy4(n): # slightly faster than recursive method
	while 1:
		if n == 1: return True
		if n == 4: return False
		n = DigSquSum(n)
	

n = 91
time0 = time.clock()
print 'is %d happy number?' % n

print isHappy(n)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print isHappy2(n)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)

print isHappy3(n)
time3 = time.clock()
print 'cost: %f s' % (time3-time2)

print isHappy4(n)
time4 = time.clock()
print 'cost: %f s' % (time4-time3)
