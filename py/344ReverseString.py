#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh". 
'''
import time

def reverseStr(s):
	return s[::-1]
	
def reverseStr2(s):
    r = list(s)
    i, j  = 0, len(r) - 1
    while i < j:
        r[i], r[j] = r[j], r[i]
        i += 1
        j -= 1
    return "".join(r)

s = "hello"
print s
time0 = time.clock()
print reverseStr(s)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print reverseStr2(s)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)
