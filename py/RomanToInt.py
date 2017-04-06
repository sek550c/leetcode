#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given a roman numeral, convert it to an integer.

1 ~ 10:
I, II, III, IV, V, VI, VII, VIII, IX, X
L = 50, C = 100, D = 500, M = 1000

Input is guaranteed to be within the range from 1 to 3999.
'''
import time

def romanToInt(s):
	roman = {'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1}
	z = 0
	for i in range(0, len(s) - 1):
		if s[i] not in roman or s[i+1] not in roman: # check if it is a valid number
			print "not a valid Roman number"
			return 0
		if roman[s[i]] < roman[s[i+1]]:
			z -= roman[s[i]]
		else:
			z += roman[s[i]]
	return z + roman[s[-1]] # last bit always add

''' test with intToRoman    
s = "VIII"
time0 = time.clock()

print romanToInt(s)
time1 = time.clock()
print "roman to int cost: %f s" % (time1-time0)
'''
