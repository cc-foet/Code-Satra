class Solution {

    public int[] sortJumbled(int[] mapping, int[] nums) {
        ArrayList<Integer[]> storePairs = new ArrayList<>();

        for (int i = 0; i < nums.length; ++i) {
            // Convert current value to string
            String number = Integer.toString(nums[i]);
            String formed = "";
            for (int j = 0; j < number.length(); ++j) {
                formed = formed +
                Integer.toString(mapping[number.charAt(j) - '0']);
            }
            // Store the mapped value.
            int mappedValue = Integer.parseInt(formed);
            // Push a pair consisting of mapped value and original value's index.
            storePairs.add(new Integer[] { mappedValue, i });
        }

        // Sort the array in non-decreasing order by the first value (default).
        Collections.sort(
            storePairs,
            new Comparator<Integer[]>() {
                @Override
                public int compare(Integer[] o1, Integer[] o2) {
                    return o1[0].compareTo(o2[0]);
                }
            }
        );

        int[] answer = new int[nums.length];
        for (int i = 0; i < storePairs.size(); i++) {
            answer[i] = nums[storePairs.get(i)[1]];
        }
        return answer;
    }
}
