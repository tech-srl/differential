int sum(int *arr,unsigned len) {
  int result = 0, i;
  for (i = 1; i < len; i+=2) {
    result += arr[i];
  }
  return result;
}
