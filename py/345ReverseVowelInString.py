#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede". 
'''
import time
import re

# worst: O(n), avg: O(n/2)
def reverseVowels(s):
	i, j = 0, len(s)-1
	vowel = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
	while i < j:
		if s[i] not in vowel:
			i += 1
		if s[j] not in vowel:
			j -= 1
		# after update i and j, they may be equal(i = j), and we do not update. not use i != j and try 'cat'
		if i != j and s[i] in vowel and s[j] in vowel: 
			#s[i], s[j] = s[j], s[i] # string type not support assignment, use below line instead
			s = s[:i] + s[j] + s[i+1:j] + s[i] + s[j+1:]
			i += 1
			j -= 1
	return s

# store vowel
def reverseVowels2(s):
	vowel = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
	record = []
	for c in s:
		if c in vowel:
			record.append(c)
	for i in xrange(len(s)):
		if s[i] in vowel:
			s = s[:i] + record[-1] + s[i+1:]
			record.pop()
	return s

def reverseVowels3(s):
    vowels = re.findall('(?i)[aeiou]', s)
    return re.sub('(?i)[aeiou]', lambda m: vowels.pop(), s)

def reverseVowels4(s):
	vowel = 'AEIOUaeiou'
	s = list(s)
	i,j = 0, len(s)-1
	while i<j:
		while s[i] not in vowel and i<j:
			i = i + 1
		while s[j] not in vowel and i<j:
			j = j - 1
		s[i], s[j] = s[j], s[i]
		i, j = i + 1, j - 1
	return ''.join(s)

s = "aA"
time0 = time.clock()

s1 = reverseVowels(s)
print s1
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

s2 = reverseVowels2(s)
print s2
time2 = time.clock()
print 'cost: %f s' % (time2-time1)

s3 = reverseVowels3(s)
print s3
time3 = time.clock()
print 'cost: %f s' % (time3-time2)

s4 = reverseVowels4(s)
print s4
time4 = time.clock()
print 'cost: %f s' % (time4-time3)

print s1 == s2 and s2 == s3 and s3 == s4
