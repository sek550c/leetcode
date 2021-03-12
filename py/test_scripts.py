#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# decorator
def start_finish(f):
    def new_f(*args, **kwargs):
        print("%s starting..."%(f.__name__))
        f(*args, **kwargs)
        print("%s finished."%(f.__name__))
    return new_f

### twoSum hash###
def twoSum_hash(nums, target):
	hash = {}
	for idx, n in enumerate(nums):
		find = target-n
		if find in hash:
			return [idx, hash[find]]
		hash[n] = idx
	return []

### twoSum pointer###
def twoSum_pointer(nums, target):
	low, high = 0, len(nums)-1
	while low < high:
		res = nums[low]+nums[high]
		if res == target:
			return [low, high]
		elif res > target:
			high = high-1
		else:
			low = low+1
	return []
@start_finish
def twoSumMain():	
	nums = [2, 7, 11, 15]
	target = 13
	print("index:%s"%(twoSum_hash(nums, target)))
	print("index:%s"%(twoSum_pointer(nums, target)))

if __name__ == '__main__':
	twoSumMain()