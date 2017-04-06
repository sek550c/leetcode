#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.

Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

'''
'''
Q1:
	If arrays are sorted, then use method 2, i.e. pointer method.
Q2:
	
Q3:
    If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, read chunks of array that fit into the memory, and record the intersections.

    If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort), then read 2 elements from each array at a time in memory, record intersections.

'''
import time

'''
this func not work for case [1, 2, 3][2, 1, 1]
def intersect(nums1, nums2):
	res = []
	i, j = 0, 0
	if len(nums1) < len(nums2): # make sure nums2 is smaller
		nums1, nums2 = nums2, nums1
	nums1 = sorted(nums1) # for test case [1, 2][2, 1]
	nums2 = sorted(nums2)
	print nums1
	print nums2
	while j < len(nums2) and i < len(nums1):
		if nums1[i] == nums2[j]:
			res.append(nums2[j])
			j += 1
		i += 1
	return res
'''
# assume nums1 size: m, nums2 size: n

# hash time:O(m+n), space: O(m) or O(n)
def intersect(nums1, nums2):
	res = []
	# store nums2 in hash table
	hashtable = {}
	for num in nums2:
		hashtable[num] = hashtable.get(num, 0) + 1
	# process through nums1
	for num in nums1:
		if num in hashtable and hashtable[num] != 0:
			res.append(num)
			hashtable[num] -= 1
	return res

# sort and pointer
def intersect2(nums1, nums2):
	nums1, nums2, i, j, res = sorted(nums1), sorted(nums2), 0, 0, []
	while i < len(nums1) and j < len(nums2):
		if nums1[i] == nums2[j]:
			res.append(nums1[i])
			i += 1
			j += 1
		elif nums1[i] < nums2[j]:
			i += 1
		else:
			j += 1
	return res
	
#nums1 = [-2147483647,1,2,3]
#nums2 = [1,-2147483647,-2147483647]
#nums2 = [1, 2]
#nums1 = [2, 1]
nums1 = [1, 2]
nums2 = [2, 1]
time0 = time.clock()

print intersect(nums1, nums2)
time1 = time.clock()
print "cost: %f s" % (time1 - time0)

print intersect2(nums1, nums2)
time2 = time.clock()
print "cost: %f s" % (time2 - time1)




