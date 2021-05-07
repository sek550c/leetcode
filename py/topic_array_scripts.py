#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# decorator
def start_finish(f):
    def new_f(*args, **kwargs):
        print("%s starting..."%(f.__name__))
        f(*args, **kwargs)
        print("%s finished."%(f.__name__))
    return new_f

### 1,167 twoSum ###
def twoSum_hash_my(nums, target):
    hash = {} # store element:index
    for i,n in enumerate(nums):
        if target-n in hash: # found
            return [i, hash[target-n]]
        else: # not found, store
            hash[n] = i
    return []
                
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
    print("index:%s"%(twoSum_hash_my(nums, target)))
    print("index:%s"%(twoSum_pointer(nums, target)))
    
####################################################

### 118 YangHui Triangle ###
def getYanghuiNum(row,col):
    if row == col or col == 1: return 1
    else: return getYanghuiNum_my(row-1, col-1)+getYanghuiNum_my(row-1, col)

def yanghuiTriRecursive(numRow):
    res = []
    for r in xrange(1,numRow+1):
        row = []
        for c in xrange(1, r+1):
            row += [getYanghuiNum_my(r, c)]
        res.append(row)
    return res

def yanghuiTri(numRow):
    pascal = [[1]*(i+1) for i in xrange(numRow)]
    for i in xrange(2, numRow):
        for j in xrange(1,i):
            pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j]
    return pascal

def yanghuiTri_map(numRow):
    res = [[1]]
    for r in xrange(1,numRow):
        res += [map(lambda x,y:x+y, res[-1]+[0], [0]+res[-1])] 
    return res[:numRow] # in case numRow=0 
    
@start_finish
def yanghuiTriMain():
    numRow = 5
    print("list aadd: %s"%([1]+[2]))
    l1 = [1]
    l1.append(2)
    print("list append: %s"%(l1))
    print("YangHui Triangle recursive: %s"%(yanghuiTriRe_my(numRow)))
    print("YangHui Triangle: %s"%(yanghuiTri(numRow)))
####################################################

### 27 remove element ###
def removeElement(nums, val):
    new_i = 0
    for i in xrange(len(nums)):
        if nums[i] != val:
            nums[new_i] = nums[i]
            new_i += 1
    return new_i
    
@start_finish
def removeElementMain():
    nums = [3, 2, 2, 3]
    val = 3
    print("%s remove element %s: %s"%(nums, val, nums[:removeElement(nums, val)]))
####################################################

### 26 remove duplicated element ###
def removeDupElement(nums):
    if len(nums) < 2: return 1
    new_i = 1
    for i in xrange(1,len(nums)):
        if nums[i] != nums[i-1]:
            nums[new_i] = nums[i]
            new_i += 1
        
    return new_i
    
@start_finish
def removeDupElementMain():
    nums = [0, 1, 2, 2, 3, 3, 3, 4]
    print(nums[:removeDupElement(nums)])
    print("%s remove duplicated element: %s"%(nums, nums[:removeDupElement(nums)]))

####################################################

### 35 search insert ###
def searchInsert(nums, target):
    for idx, n in enumerate(nums):
        if n >= target:
            return idx
    return len(nums)

@start_finish
def searchInsertMain():
    nums = [1, 3, 5, 6]
    print(nums)
    target = 0
    print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
    target = 2
    print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
    target = 3
    print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
    target = 7
    print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
####################################################

### 53 max subarray ###
def maxSubArray(nums):
    local_max = nums[0]
    global_max = nums[0]
    for n in nums[1:]:
        local_max = max(n, local_max+n)
        global_max = max(local_max, global_max)
    return global_max

@start_finish
def maxSubArrayMain():
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print("%s has the largest sum: %s"%(nums, maxSubArray(nums)))
    nums = [5,4,-1,7,8]
    print("%s has the largest sum: %s"%(nums, maxSubArray(nums)))
    nums = [1]
    print("%s has the largest sum: %s"%(nums, maxSubArray(nums)))
####################################################

### 66 plus one ###
def plusOne(nums):
    for i in xrange(len(nums)-1, -1, -1):
        if nums[i] == 9:
            nums[i] = 0
        else:
            nums[i] += 1
            return nums
    nums.append(0)
    nums[0] = 1
    return nums

def plusOne2(nums):
    total = nums[0]
    for n in nums[1:]:
        total = 10*total+n
    return [int(i) for i in str(total+1)]

@start_finish
def plusOneMain():
    fun = plusOne2
    nums = [1,2,3]
    print(nums)
    print("plus one: %s"%(fun(nums)))
    nums = [0]
    print(nums)
    print("plus one: %s"%(fun(nums)))
    nums = [1,9,9]
    print(nums)
    print("plus one: %s"%(fun(nums)))
    nums = [9,9,9]
    print(nums)
    print("plus one: %s"%(fun(nums)))

####################################################

### 67 add binary ###
def addBinaryDecimal(a, b):
    if a == "0" or a == "": return b
    if b == "0" or b == "": return a
    return bin(int(a,2)+int(b,2))[2:]

def addBinary(a, b):
    if a == "0" or a == "": return b
    if b == "0" or b == "": return a
    if len(a) < len(b):
        a = "0"*(len(b)-len(a))+a
    if len(b) < len(a):
        b = "0"*(len(a)-len(b))+b
    # print(a,b)
    i,j = len(a)-1, len(b)-1
    carry = 0
    res = ""
    while i >= 0 and j >= 0:
        # print(i,j)
        tmp = str((int(a[i])+int(b[j])+carry)%2)
        # print tmp
        res = tmp+res
        # print(res)
        carry = (int(a[i])+int(b[j])+carry)/2
        i = i-1
        j = j-1
    if carry > 0: return "1"+res
    else: return res

@start_finish
def addBinaryMain():
    fun = addBinaryDecimal
    fun2 = addBinary
    a = "111"
    b = ""
    print(a)
    print(b)
    print("add binary using decimal: %s"%(fun(a, b)))
    print("add binary using brute-force: %s"%(fun2(a, b)))

####################################################
### 83 delete duplicates ###
"""
Given the head of a sorted linked list, delete all duplicates 
such that each element appears only once. Return the linked 
list sorted as well.
"""
#TODO
def deleteDulicates(head):
    for i, n in enumerate(head):
        pass



def deleteDulicates2(head):
    pass



@start_finish
def deleteDulicatesMain():
    fun = deleteDulicates
    # fun2 = addBinary
    nums = [0,1,2,3,3]
    # b = ""
    print(a)
    # print(b)
    print("delete dulicates: %s"%(fun(nums)))

####################################################
### 88 merge sorted array ###
"""
Given two sorted integer arrays nums1 and nums2, merge nums2 
into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m 
and n respectively. You may assume that nums1 has a size 
equal to m + n such that it has enough space to hold 
additional elements from nums2.

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]。
"""
def merge(nums1, m, nums2, n):
    mergesize = m+n-1
    j = 0
    # copy nums2 to nums1
    for i in xrange(m, mergesize+1):
        nums1[i] = nums2[j]
        j = j+1
    # print(nums1)
    nums1 = sorted(nums1)
    return nums1

def merge2(nums1, m, nums2, n):
    mergesize = m+n
    i, j = m-1, n-1
    new_i = mergesize-1
    while i >=0 and j >= 0:
        print(nums1[i],nums2[j])
        if nums1[i] <= nums2[j]:
            nums1[new_i] = nums2[j]
            new_i = new_i-1
            j = j-1
        else:
            nums1[new_i] = nums1[i]
            new_i = new_i-1
            i = i-1
    return nums1


@start_finish
def mergeMain():
    fun = merge
    fun2 = merge2
    nums1 = [1,1,7,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    print(nums1)
    print(nums2)
    print("merge: %s"%(fun(nums1, m, nums2, n)))
    print("merge2: %s"%(fun2(nums1, m, nums2, n)))

####################################################

####################################################
### 121 best time to sell and buy ###
"""
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share
of the stock), design an algorithm to find the maximum profit.
Input: [7,1,5,3,6,4]
Output: 5
"""
def maxProfit(price):
    minPrice = price[0]
    maxProfit = 0
    for s in price:
        minPrice = min(minPrice, s)
        maxProfit = max(maxProfit, s-minPrice)
    return maxProfit

@start_finish
def maxProfitMain():
    fun = maxProfit
    price = [6,5,5,4,3]
    print(price)
    print("max profile: %s"%(fun(price)))


####################################################

### 122 best time to sell and buy 2 ###
"""
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you
like (i.e., buy one and sell one share of the stock multiple times).
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6),
profit = 6-3 = 3.
"""
def maxProfit122(price):
    profit = 0
    for i in xrange(len(price)-1):
        if price[i+1] > price[i]:
            profit = profit+price[i+1]-price[i]
    return profit


@start_finish
def maxProfit122Main():
    fun = maxProfit122
    price = [7,1,5,3,6,7]
    print(price)
    print("max profit: %s"%(fun(price)))


####################################################
### 217 contains duplicates ###
"""
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should
return false if every element is distinct.
"""
def containsDup(nums):
    nums = sorted(nums)
    for i in xrange(len(nums)-1):
        if nums[i+1] == nums[i]:
            return True
    return False

def containsDup2(nums):
    hash_map = {}
    for n in nums:
        if n in hash_map:
            return True
        else:
            hash_map[n] = 1
    return False

def containsDup3(nums):
    # print(set(nums))
    # print(sum(set(nums)))
    if sum(nums) == sum(set(nums)):
        return False
    else:
        return True

@start_finish
def containsDupMain():
    nums = [7,1,5,5,6,4]
    print(nums)
    print("contains duplicates?: %s"%(containsDup(nums)))
    print("contains duplicates?: %s"%(containsDup2(nums)))
    print("contains duplicates?: %s"%(containsDup3(nums)))

####################################################


####################################################
### 219 contains duplicates 2 ###
"""
Given an array of integers and an integer k, find out whether there are two distinct indices i and j
in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
"""
def containsNearbyDup(nums, k):
    hash_map = {}
    for i, n in enumerate(nums):
        if n in hash_map:
            if abs(i-hash_map[n]) <= k:
                return True
            else:
                hash_map[n] = i
        else:
            hash_map[n] = i
    return False


@start_finish
def containsNearbyDupMain():
    nums = [1,0,1,1]
    k = 1
    print(nums, k)
    print("contains nearby duplicates?: %s"%(containsNearbyDup(nums, k)))

####################################################
### 283 move zeros ###
"""
Given an array nums, write a function to move all 0's to the end of it while maintaining the
relative order of the non-zero elements.
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
"""
def moveZeros(nums):
    cur, zero = 0, 0
    while cur < len(nums):
        if nums[cur] != 0:
            if cur != zero:
                nums[cur], nums[zero] = nums[zero], nums[cur] # swap
                print(nums)
            zero = zero+1
        cur = cur+1
    return nums
    # return False


@start_finish
def moveZerosMain():
    nums = [1,2,0,3,0,12]
    # k = 1
    print(nums)
    print("move zeros: %s"%(moveZeros(nums)))

####################################################

### 287 find duplicated num ###
"""
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist. Assume that there is only one duplicate
number, find the duplicate one.
Input: [1,3,4,2,2]
Output: 2
"""

"""
将此数组看成链表，通过快慢指针解题
需2个循环，快指针走2步，慢指针走1步。第一个循环找到相遇点；第二个循环从头走和慢指针会在环入口，即重复元素处相遇
具体解释参考：
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d/
"""
def findDup(nums):
    slow = nums[0]
    fast = nums[nums[0]]
    while fast != slow: # 快慢指针相遇
        slow = nums[slow]
        fast = nums[nums[fast]]
    #fast = slow
    print(slow, fast)
    dup = 0
    while dup != slow: # 新指针和慢指针一起走，会在环入口相遇
        dup = nums[dup]
        slow = nums[slow]
    return dup

# binary search
def findDup2(nums):
    low, high = 0, len(nums)-1
    while low < high:
        mid, count = low+(high-low)/2, 0
        for n in nums:
            if n <= mid: count = count+1
        if count > mid:
            high = mid
        else:
            low = mid+1
    return low

@start_finish
def findDupMain():
    nums = [1,3,4,2,2]
    # k = 1
    print(nums)
    print("find duplicate: %s"%(findDup(nums)))
    print("find duplicate: %s"%(findDup2(nums)))
    print("2>>1: %s"%(2>>1)) # 右移1位，相当于/2
    print("2/2: %s"%(2/2))
####################################################

### 532 k-diff pairs in an array ###
"""
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in
the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in
the array and their absolute difference is k.
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
"""
def findPairs(nums, k):
    if k < 0 or len(nums) == 0:
        return 0
    count = 0
    count_table = {}
    # 计数dict: 元素:个数
    for n in nums:
        count_table[n] = count_table.get(n, 0) + 1
    # print(count_table, len(count_table))

    for i in count_table:
        if k == 0 and count_table[i] > 1: # k=0且有重复的数，计数
            count = count+1
            continue 
        # print(i,k)
        if k > 0 and count_table.get(i+k, 0) > 0: # k>0且有相差k的数，计数
            count = count+1
    # print(count_table)
    return count


@start_finish
def findPairsMain():
    nums = [3, 1, 4, 1, 5]
    k = 2
    print(nums)
    print("k-diff pairs in an array: %s"%(findPairs(nums, k)))

####################################################

### 11 container with most water ###
"""
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n
vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container, such that the container contains the most water.
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
"""
def maxArea(height):
    left, right = 0, len(height)-1
    maxA = 0
    while left < right:
        w = right-left
        h = 0
        print(left, right)
        if height[left] < height[right]:
            h = height[left]
            left = left+1
        else:
            h = height[right]
            right = right-1
        area = w*h
        maxA = max(area, maxA)
    return maxA


@start_finish
def maxAreaMain():
    height = [1,8,6,2,5,4,8,3,7]
    print(height)
    print("max area: %s"%(maxArea(height)))


####################################################

### 15 3sum ###
"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find
all unique triplets in the array which gives the sum of zero.
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
"""
def threeSum_bf(nums):
    res = []
    # nums = sorted(nums)
    for i in xrange(len(nums)):
        for j in xrange(i+1, len(nums)):
            for k in xrange(j+1, len(nums)):
                if nums[i]+nums[j]+nums[k] == 0:
                    res.append([nums[i], nums[j], nums[k]])
    return res

def threeSum_map(nums):
    res = []
    if len(nums) < 3:
        return res
    count_table = {} # 计数dict: 元素:个数
    for n in nums:
        count_table[n] = count_table.get(n, 0) + 1
    # print(count_table)
    uniqueNum = [] # 去重之后的数列
    for k in count_table:
        uniqueNum.append(k)
    # print(uniqueNum)
    uniqueNum = sorted(uniqueNum) # 对去重后的数列排序
    print(uniqueNum)

    for i in xrange(len(uniqueNum)): # 遍历去重后的数列
        if uniqueNum[i]*3 == 0 and count_table[uniqueNum[i]] >= 3: # 如果重复3次以上的元素加起来为0，即0重复3次以上，返回结果
            res.append([uniqueNum[i], uniqueNum[i], uniqueNum[i]])
        for j in xrange(i+1, len(uniqueNum)): # 固定了i元素，遍历i之后的元素，注意是从i+1开始
            if uniqueNum[i]*2 + uniqueNum[j] == 0 and count_table[uniqueNum[i]] >= 2: # 如果重复2次以上的i元素+当前j元素为0，返回结果
                res.append([uniqueNum[i], uniqueNum[i], uniqueNum[j]])
            if uniqueNum[j]*2 + uniqueNum[i] == 0 and count_table[uniqueNum[j]] >= 2: # 如果重复2次以上的j元素+当前i元素为0，返回结果
                res.append([uniqueNum[i], uniqueNum[j], uniqueNum[j]])
            c = 0 - uniqueNum[j] - uniqueNum[i] # 固定了2个元素，若找到c元素使得：i元素+j元素+c为0，则返回结果
            if c > uniqueNum[j] and count_table.get(c, 0) >= 1: # 需保证c在元素i和元素j之后且存在
                res.append([uniqueNum[i], uniqueNum[j], c])
    return res


@start_finish
def threeSumMain():
    nums = [-1,0,1,2,-1,-4]
    print(nums)
    # print("3 sum brute-force: %s"%(threeSum_bf(nums)))
    print("3 sum map: %s"%(threeSum_map(nums)))
####################################################

### 16 3sum closest###
"""
Given an array nums of n integers and an integer target, find three integers in nums such that the
sum is closest to target. Return the sum of the three integers. You may assume that each input
would have exactly one solution.
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
"""
def threeSum_closest(nums, target):
    res = 0
    n = len(nums)
    nums = sorted(nums) # 排序，注意不要使用set去重，会丢失重复数字
    diff = float('inf') # 设置为最大数
    # print(diff)
    # print(nums)
    if n >= 3: 
        for i in xrange(n-2): # 固定一个数，在使用双指针夹逼结果
            j = i+1 
            k = n-1
            while j < k:
                total = nums[i]+nums[j]+nums[k]
                if abs(total-target) < diff:
                    diff = abs(total-target)
                    res = total
                if total == target: # 如果等于目标，即为最小，diff=0
                    return res
                elif total > target: # 如果大于目标，减小结果
                    k = k-1
                else: # 小于目标，增加结果
                    j = j+1
    return res


@start_finish
def threeSumClosestMain():
    nums, target = [-1, 2, 1, -4], 1 # answer = 1
    # nums, target = [1, 1, -1], 0 # answer = 1
    # nums, target = [1, 1, 1, 1], 0 # answer = 3
    print(nums, target)
    # print("3 sum brute-force: %s"%(threeSum_bf(nums)))
    print("3 sum closest: %s"%(threeSum_closest(nums, target)))
####################################################

### 18 4sum ###
"""
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums
such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of
target.
Note:
The solution set must not contain duplicate quadruplets.
Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
[-1, 0, 0, 1],
[-2, -1, 1, 2],
[-2, 0, 0, 2]
]
"""


def fourSum_map(nums, target):
    print(nums, target) # testcase
    res = []
    if len(nums) < 4:
        return res
    count_table = {} # 计数dict: 元素:个数
    for n in nums:
        count_table[n] = count_table.get(n, 0) + 1
    # print(count_table)
    uniqueNum = [] # 去重之后的数列
    for x in count_table:
        uniqueNum.append(x)
    # print(uniqueNum)
    uniqueNum = sorted(uniqueNum) # 对去重后的数列排序
    print(uniqueNum)

    for i in xrange(len(uniqueNum)): # 遍历去重后的数列
        if uniqueNum[i]*4 == target and count_table[uniqueNum[i]] >= 4: # 如果重复4次以上的元素加起来为0，即0重复4次以上，返回结果
            res.append([uniqueNum[i], uniqueNum[i], uniqueNum[i], uniqueNum[i]])
            # print("4i")

        for j in xrange(i+1, len(uniqueNum)): # 固定了i元素，遍历i之后的元素，注意是从i+1开始
            if uniqueNum[i]*3 + uniqueNum[j] == target and count_table[uniqueNum[i]] >= 3: # 如果重复3次以上的i元素+当前j元素为0，返回结果
                res.append([uniqueNum[i], uniqueNum[i], uniqueNum[i], uniqueNum[j]])
                # print("3i,j")
            if uniqueNum[j]*3 + uniqueNum[i] == target and count_table[uniqueNum[j]] >= 3: # 如果重复3次以上的j元素+当前i元素为0，返回结果
                res.append([uniqueNum[i], uniqueNum[j], uniqueNum[j], uniqueNum[j]])
                # print("i,3j")
            # 如果重复2次以上的j元素+重复2次以上i元素为0，返回结果
            if uniqueNum[i]*2 + uniqueNum[j]*2 == target and count_table[uniqueNum[i]] >= 2 and count_table[uniqueNum[j]] >= 2: 
                res.append([uniqueNum[i], uniqueNum[i], uniqueNum[j], uniqueNum[j]])
                # print("2i,2j")

            for k in xrange(j+1, len(uniqueNum)): # 固定了i元素及j元素，遍历j+1之后的元素，注意是从j+1开始
                # 如果重复2次以上的i元素+当前j元素+k元素为0，返回结果
                if uniqueNum[i]*2 + uniqueNum[j] + uniqueNum[k] == target and count_table[uniqueNum[i]] >= 2:
                    res.append([uniqueNum[i], uniqueNum[i], uniqueNum[j], uniqueNum[k]])
                    # print("2i,j,k")
                # 如果重复2次以上的j元素+当前i元素+k元素为0，返回结果
                if uniqueNum[j]*2 + uniqueNum[i] + uniqueNum[k] == target and count_table[uniqueNum[j]] >= 2:
                    res.append([uniqueNum[i], uniqueNum[j], uniqueNum[j], uniqueNum[k]])
                    # print("i,2j,k")
                # 如果重复2次以上的k元素+当前j元素+k元素为0，返回结果
                if uniqueNum[k]*2 + uniqueNum[j] + uniqueNum[i] == target and count_table[uniqueNum[k]] >= 2:
                    res.append([uniqueNum[i], uniqueNum[j], uniqueNum[k], uniqueNum[k]])
                    # print("i,j,2k")

                c = target - uniqueNum[i] - uniqueNum[j] - uniqueNum[k] # 固定了3个元素，若找到c元素使得：i元素+j元素+c为0，则返回结果
                if c > uniqueNum[k] and count_table.get(c, 0) >= 1: # 需保证c在元素k之后且存在
                    res.append([uniqueNum[i], uniqueNum[j], uniqueNum[k], c])
                    # print("i,j,k,c")
    return res


@start_finish
def fourSumMain():
    # nums = [1, 0, -1, 0, -2, 2]
    # testcase
    nums = [-2,-1,-1,1,1,2,2]
    target = 0
    # nums = [2,2,2,2,2]
    # target = 8
    print(nums)
    # print("4 sum brute-force: %s"%(threeSum_bf(nums)))
    print("4 sum map: %s"%(fourSum_map(nums, target)))
####################################################

### 22 Generate Parentheses ###
"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
"""
def generateParenthesisDFS(res, parentheses, leftRemain, rightRemain):
    if leftRemain > rightRemain or leftRemain < 0 or rightRemain < 0: # 回溯条件
        return
    if leftRemain == 0 and rightRemain == 0: # 返回结果, 注意是and
        res.append(parentheses)
        return res
    generateParenthesisDFS(res, parentheses+"(", leftRemain-1, rightRemain)
    generateParenthesisDFS(res, parentheses+")", leftRemain, rightRemain-1)

def generateParenthesis(n):
    res = []
    generateParenthesisDFS(res, "", n, n)
    return res


@start_finish
def generateParenthesisMain():
    for n in xrange(1, 5):
        print("generate n = %s valid Parenthesis: %s"%(n, generateParenthesis(n)))
####################################################



"""
blabla
"""
if __name__ == '__main__':
    # twoSumMain()
    # yanghuiTriMain()
    # removeElementMain()
    # removeDupElementMain()
    # searchInsertMain()    
    # maxSubArrayMain()
    # plusOneMain()
    # addBinaryMain()
    # deleteDulicatesMain()
    # mergeMain()
    # maxProfitMain()
    # maxProfit122Main()
    # containsDupMain()
    # containsNearbyDupMain()
    # moveZerosMain()
    # findDupMain()
    # findPairsMain()
    # maxAreaMain()
    # threeSumMain()
    # threeSumClosestMain()
    # fourSumMain()
    # generateParenthesisMain()
    combinationSumMain()