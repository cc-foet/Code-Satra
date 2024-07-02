## Problem statement
Given an array of intergers, write a function that sorts the array using the bubble sort algorithm and count the number of swaps performed during the sorting process. The function should return both the sorted array and the number of count ;

Solution
```js
const bubbleSorting = (arr) => {
  const n = arr.length;
  let swapped = false;
  let count = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        count += 1;
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
  return { sortedArray: arr, swappedCount: count };
}
let arr = [64, 34, 25, 12, 22, 11, 90]

console.log(bubbleSorting(arr))
```

We are going to check the element in pairs and swap if the first number is smaller than the second on and keep on repeating this util the array is sorted.
Accoding to the given array
first it will check 64,34
since 34 is smaller than 64 we will swap their position
and set the count to be count ++ ;
and set swapped = true;

At the end we will return an obejct with the sorted array and count ;
