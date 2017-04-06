#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
'''
import time
from RomanToInt import romanToInt # use romanToInt function

def intToRoman(num):
	M = ["", "M", "MM", "MMM"] # 1000, 2000, 3000
	C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"] # 100, 200 ,..., 900
	X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"] # 10, 20,..., 90
	I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"] # 1, 2,..., 9
	return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10]
    
num = 17
time0 = time.clock()

print "Now I have number: %d" %num
s = intToRoman(num)
print "change to roman: %s" %s
print "change back to number: %d" %romanToInt(s)

time1 = time.clock()
print "cost: %f s" % (time1-time0)
