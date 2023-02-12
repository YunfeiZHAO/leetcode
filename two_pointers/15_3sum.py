from typing import *


def twoSum(nums, value):
    complement = set()
    result = []
    n = len(nums)

    comp = value - nums[0]
    if comp not in complement:
        complement.add(comp)

    for i in range(1,n):
        if nums[i] not in complement:
            complement.add(value - nums[i])
        else:
            result.append([value-nums[i], nums[i]])
    return result


def threeSum(nums: List[int]) -> List[List[int]]:
    nums.sort()
    result = []
    n = len(nums)
    i = 0
    while i < n-2:
        if not (i > 0 and nums[i] == nums[i-1]):
            partial_result = set()
            left = i+1
            right = n-1
            while left < right:
                if nums[left] + nums[right] < -nums[i]:
                    left += 1
                elif nums[left] + nums[right] > -nums[i]:
                    right -= 1
                else:
                    if (nums[left], nums[right]) not in partial_result:
                        partial_result.add((nums[left], nums[right]))
                        result.append([nums[i], nums[left], nums[right]])
                    left += 1
        i += 1
    return result



if __name__ == '__main__':
    # nums = [-1,0,1,2,-1,-4]
    nums = [0,0,0,0]
    print(threeSum(nums))