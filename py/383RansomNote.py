#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

'''

def canConstruct(ransomNote, magazine):
	for letter in set(ransomNote):
		if letter not in magazine or ransomNote.count(letter) > magazine.count(letter):
			return False
	return True
	
ransomNote = "aa"
magazine = "ab"
if canConstruct(ransomNote, magazine):
	print "Yes, can be constructed"
else:
	print "No, cannot be constructed"
