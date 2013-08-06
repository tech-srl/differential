int sum(int *arr,unsigned len) {
  int result = 0, i = 0;
  while (i + 1 < len) {
    i++;
    result += arr[i];
    i++;
  }
  return result;
}
