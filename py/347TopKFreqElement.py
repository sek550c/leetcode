#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
'''
from collections import Counter
import heapq
import time

# better see c++ implementation

def topKFrequent(nums, k):
	hashtable = {}
	for num in nums:
		hashtable[num] = hashtable.get(num, 0) + 1
	return sorted(hashtable, key=hashtable.get, reverse=True)[:k]

def topKFrequent2(nums, k):		
	c = Counter(nums)
	return heapq.nlargest(k, c, c.get)

nums = [1,1,1,3,2,3]
k = 2
time0 = time.clock()
print topKFrequent(nums, k)
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print topKFrequent2(nums, k)
time2 = time.clock()
print 'cost: %f s' % (time2-time1)
