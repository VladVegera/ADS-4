// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] <= value) {
      for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
  }
  return count;
}

int binarsearch(int* arr, int len, int value, int left) {
  int L = left, R = len - 1, count = 0;
  while (L < R) {
    int mid = L + (R - L) / 2;
    if (arr[mid] == value && mid != left) {
      count++;
      int x = mid, xx = mid;
      while (arr[++x] == value) {
        count++;
      }
      while (arr[--xx] == value && xx > left) {
         count++;
       }
       return count;
       } else if (arr[mid] > value) {
           R = mid;
       } else {
           L = mid + 1;
       }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    k += binarsearch(arr, len, value - arr[i], i);
  }
  return k;
}
