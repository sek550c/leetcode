#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
'''
import random
import copy

class MyArray(object):

	def __init__(self, _nums):
		self.nums = _nums
		self.size = len(_nums)
		
	def reset(self):
		return self.nums
	
	# aka fisher yates shuffle
	# https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
	def shuffle(self):
		# need to understand assignment, copy, deep copy
		res = self.nums[:] # copy, cannot use '=' directly here, see http://greybeard.iteye.com/blog/1442259
		# or use copy here
		# res = copy.copy(self.nums)
		for i in xrange(self.size-1, 0, -1):
			j = random.randrange(0, i+1)
			res[i], res[j] = res[j], res[i]
		return res

nums = list(xrange(10))
print 'original: ', nums
array = MyArray(nums)
print 'shuffle:  ', array.shuffle()
print 'reset:    ', array.reset()


