#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"
Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
'''
import time
			
def isSubsequence(s, t):
	if s == t or not s: return True
	if not t: return False
	i, j = 0, 0
	while j < len(t):
		if s[i] == t[j]:
			i += 1
			if i == len(s): return True # finish s
		j += 1
	return False

def isSubsequence2(s, t):
	if s == t or not s: return True
	if not t: return False
	i, j = 0, 0
	while i < len(s) and j < len(t):
		if s[i] == t[j]:
			i += 1
		j += 1
	return i == len(s)
	
# testing whether all characters in s are also in t (in order)
# all(): if element is null or 0, returns false
def isSubsequence3(s, t):
    #t = iter(t)
    return all(c in t for c in s)	
	
s = "z"
t = "ahbgdc"
print 'is it subsequence?'
time0 = time.clock()

print isSubsequence(s, t)
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)

print isSubsequence2(s, t)
time2 = time.clock()
print 'cost: %f s' % (time2 - time1)

print isSubsequence3(s, t)
time3 = time.clock()
print 'cost: %f s' % (time3 - time2)
