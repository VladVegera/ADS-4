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
    } else {
      break;
    }
  }
  return count;
}

int binsearch(int *arr, int left, int right, int a) {
    int l = left, r = right, mid = 0;
    while (l <= r)  {
        mid = (l + r) / 2;
        if (arr[mid] == a) {
            return binsearch(arr, left, mid - 1, a) + binsearch(arr, mid + 1, right, a) + 1;
        }
        if (a < arr[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int values;
    for (int b = 0; b < len - 1; ++k) {
        values = value - arr[b];
        count += binsearch(arr, b, len, values);
    }
    return count;
}
