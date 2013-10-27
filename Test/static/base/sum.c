

int sum(int arr,unsigned len) {
  int result = 0, i;
  i = 1;
  loop:
  if (i < len) {
    result = result + arr;
    i+=2;
    goto loop;
  }
  return result;
}
