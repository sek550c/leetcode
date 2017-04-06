#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

'''
import time

# you can use all even and all odd but minus one
# "aabbbccc" => "abcccba" 7
def longestPalindrome(s):
	longest = 0
	hasOdd = False
	for c in set(s):
		count = s.count(c)
		if count % 2 == 0: # even
			longest += count
		else: # odd
			longest += count - 1 # can use odd count-1
			hasOdd = True
	return longest+1 if hasOdd else longest

# set
def longestPalindrome2(s):
	s_set, pair = set([]), 0
	for c in s:
		if c in s_set:
			s_set.remove(c)
			pair += 1
		else:
			s_set.add(c)
	if s_set:
		return 2*pair+1
	else:
		return 2*pair

# hash, same as set	but faster
def longestPalindrome3(s):
	hashtable, pair = {}, 0
	for c in s:
		if c in hashtable:
			hashtable.pop(c) # remove it
			pair += 1
		else:
			hashtable[c] = 0 # just add it to dict
	if hashtable: # remains element
		return 2*pair+1
	else:
		return 2*pair
			
	
#s = "abcccdd"
# shuold be 983
s =  "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"

time0 = time.clock()

print longestPalindrome(s)
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)

print longestPalindrome2(s)
time2 = time.clock()
print 'cost: %f s' % (time2 - time1)

print longestPalindrome3(s)
time3 = time.clock()
print 'cost: %f s' % (time3 - time2)

