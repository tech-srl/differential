int main() {
    int array_size;
    int * numbers;
    int i, j, temp;
    array_size--; // patch
    // sort
    for ( i = (array_size - 1); i > 0; i-- )
        for ( j = 1; j <= i; j++ )
            if ( numbers[j-1] > numbers[j] ) {
                temp = numbers[j-1];
                numbers[j-1] = numbers[j];
                numbers[j] = temp;
            }
    return 0;
}
