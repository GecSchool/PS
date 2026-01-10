function solution(nums) {
    const uniqueTypes = new Set(nums).size;
    return Math.min(uniqueTypes, nums.length / 2);
}