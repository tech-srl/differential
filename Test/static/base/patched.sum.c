

int sum(int arr,unsigned len) {
  int result = 0, i = 0;
  loop:
  if (i + 1 < len) {
    i++;
    result += arr;
    i++;
    goto loop;
  }
  return result;
}
