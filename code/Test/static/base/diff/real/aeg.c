extern int * realloc(int* p, int n);

void foo(int input) {
	int *ptr;
	int s;

	if (input % 2 == 0) 
		s = input + 2;
  else 
		s = input + 3;
	ptr = realloc(ptr,s);
	// use ptr[0], ptr[1], … ptr[input-1]
	while (input >= 0){
		ptr[input] = input;
		input--;
	}
}
