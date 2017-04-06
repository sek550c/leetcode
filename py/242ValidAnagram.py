#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
'''
import time

# set
''' this is wrong for case like "ab", "bba". not test all letters
def isAnagram(s, t):
	for c in set(s):	
		return s.count(c) == t.count(c)
'''
def isAnagram(s, t):
	for c in set(s):	
		if s.count(c) != t.count(c):
			return False
	return True

# sort
def isAnagram2(s, t):
	s = "".join((lambda x:(x.sort(),x)[1])(list(s)))
	t = "".join((lambda x:(x.sort(),x)[1])(list(t)))
	return s == t

# sort
def isAnagram3(s, t): # 1st
	return sorted(s) == sorted(t)

# dict/hash table
def isAnagram4(s, t): # 2nd
    dic1, dic2 = {}, {}
    for c in s:
        dic1[c] = dic1.get(c, 0) + 1
    for c in t:
        dic2[c] = dic2.get(c, 0) + 1
    return dic1 == dic2

s, t = "abc", "ccba"
time0 = time.clock()

if isAnagram(s, t):
	print 'Yes, anagram'
else:
	print 'No, not anagram'
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)
	
if isAnagram2(s, t):
	print 'Yes, anagram'
else:
	print 'No, not anagram'
time2 = time.clock()
print 'cost: %f s' % (time2 - time1)
	
if isAnagram3(s, t):
	print 'Yes, anagram'
else:
	print 'No, not anagram'
time3 = time.clock()
print 'cost: %f s' % (time3 - time2)
	
if isAnagram4(s, t):
	print 'Yes, anagram'
else:
	print 'No, not anagram'
time4 = time.clock()
print 'cost: %f s' % (time4 - time3)
