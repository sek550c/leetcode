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
####################################################
### YangHui Triangle ###
def getYanghuiNum(row, col):
	if row == col or col == 1: return 1
	else: return getYanghuiNum(row-1,col-1)+getYanghuiNum(row-1,col)
		
def yanghuiTriRecursive(numRow):
	res = []
	for r in xrange(1,numRow+1):
		row = []
		for c in xrange(1,r+1):
			row.append(getYanghuiNum(r,c))
			#print(r,c)
		res += [row]
	return res

def yanghuiTri(numRow):
	res = [[1]]
	for i in xrange(1, numRow):	
		res += [map(lambda x, y: x+y, res[-1] + [0], [0] + res[-1])] # map compute (see map and lambda)
	return res[:numRow] # in case numRow = 0
	
@start_finish
def yanghuiTriMain():
	numRow = 5
	print("YangHui Triangle: %s"%(yanghuiTriRecursive(numRow)))
	print("YangHui Triangle: %s"%(yanghuiTri(numRow)))

	
	
	
if __name__ == '__main__':
	#twoSumMain()
	yanghuiTriMain()