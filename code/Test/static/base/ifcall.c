extern int g(void);

int f(int x) {
  int y = 0;
  if (!g())
    y = 1;
}
