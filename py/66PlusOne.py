#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
'''
import time

# simulate add operation
def plusOne(digits):
	if not digits: return []
	c = 1 # carry
	for i in xrange(len(digits)-1, -1, -1): # from right to left
		c += digits[i]
		digits[i] = c % 10
		c /= 10 # carry to next digit
	if c > 0: # still have carry
		return [c] + digits
	else:
		return digits

# not using add 
def plusOne2(digits):
	if not digits: return []
	for i in xrange(len(digits)-1, -1, -1):
		if digits[i] == 9:
			digits[i] = 0
		else:
			digits[i] += 1
			return digits
	#print digits
	return [1] + digits # carry to the highest
	

digits = [9]
time0 = time.clock()

print plusOne(digits)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

digits = [8, 9] # reinit becasue previous function change digits contents already
print plusOne2(digits)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)

