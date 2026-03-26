func twoSum(numbers []int, target int) []int {
    left, right := 0, len(numbers) - 1
    for left < right {
        currSum := numbers[left] + numbers[right]
        if currSum == target {
            return []int{left+1, right+1}
        } else if currSum > target {
            right--;
        } else {
            left++;
        }
    }
    return nil
}