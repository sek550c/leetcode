#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

    Each element in the result must be unique.
    The result can be in any order.
'''
import time

def intersection(nums1, nums2):
	res = []
	for num in set(nums1):
		if num in nums2:
			res.append(num)
	return res
	
def intersection2(nums1, nums2):
	return list(set(nums1) & set(nums2))
	
def intersection3(nums1, nums2):	
	return list(set(nums1).intersection(set(nums2)))

nums1 = [1, 2, 2, 1]
nums2 = [2, 2]

time0 = time.clock()

print intersection(nums1, nums2)
time1 = time.clock()
print "cost: %f s" % (time1 - time0)

print intersection2(nums1, nums2)
time2 = time.clock()
print "cost: %f s" % (time2 - time1)

print intersection3(nums1, nums2)
time3 = time.clock()
print "cost: %f s" % (time3 - time2)

# for test use only
# print list(xrange(5))
