#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
'''
import time

# set
def containsDuplicate(nums):
	return len(set(nums)) < len(nums)

# hash
def containsDuplicate2(nums):
	hashtable = {}
	for num in nums:
		if num in hashtable:
			hashtable[num] += 1
		else:
			hashtable[num] = 1
	for num in hashtable:
		if hashtable[num] > 1:
			return True
	return False

# hash fater than above method
def containsDuplicate3(nums):
	hashtable = {}
	for num in nums:
		hashtable[num] = hashtable.get(num, 0) + 1
	for num in hashtable:
		if hashtable[num] > 1:
			return True
	return False

nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 9]
time0 = time.clock()

print containsDuplicate(nums)
time1 = time.clock()
print "cost: %f s" % (time1 - time0)

print containsDuplicate2(nums)
time2 = time.clock()
print "cost: %f s" % (time2 - time1)

print containsDuplicate3(nums)
time3 = time.clock()
print "cost: %f s" % (time3 - time2)
