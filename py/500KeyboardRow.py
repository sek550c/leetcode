#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
Example 1:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:

    You may use one character in the keyboard more than once.
    You may assume the input string will only contain letters of alphabet.
'''
import time

def findWords(words):
	k = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
	res = []
	for w in words:
		if set(w.lower()).issubset(set(k[0])) or \
		set(w.lower()).issubset(set(k[1])) or \
		set(w.lower()).issubset(set(k[2])):
			res.append(w)
	return res

def findWords2(words):
	dic = {'q':1,'w':1,'e':1,'r':1,'t':1,'y':1,'u':1,'i':1,'o':1,'p':1,\
	'a':2,'s':2,'d':2,'f':2,'g':2,'h':2,'j':2,'k':2,'l':2,\
	'z':3,'x':3,'c':3,'v':3,'b':3,'n':3,'m':3}
	res = []
	for w in words:
		for x in w.lower():
			if dic[x] != dic[w.lower()[0]]: # any letter not in 1st letter's row (in different row)
				break
		else:
			res.append(w)
	return res

words = ["Hello", "Alaska", "Dad", "Peace"]
time0 = time.clock()

print findWords(words)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print findWords2(words)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)
