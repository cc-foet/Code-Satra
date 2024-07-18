[Day-16 Question](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)

````java
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxCandies = Integer.MIN_VALUE;
        for (int candy : candies) {
            maxCandies = Math.max(candy, maxCandies);

        }
        // Creating a result list
        ArrayList<Boolean> result = new ArrayList<>();
        for (int i : candies) {
            result.add(i + extraCandies >= maxCandies);

        }
        return result;
    }
}
````