void
vectorAdd(const float *A, const float *B, float *C, int numElements, int blockDim, int blockIdx, int threadIdx)
{
    int i = blockDim * blockIdx + threadIdx;

    if (i < numElements)
    {
        C[i] = A[i] + B[i];
    }
}

int main() {
    int numElements = 50000;
    size_t size = numElements * sizeof(float);
    printf("[Vector addition of %d elements]\n", numElements);

    // Allocate the host input vector A
    float *h_A = (float *)malloc(size);

    // Allocate the host input vector B
    float *h_B = (float *)malloc(size);

    // Allocate the host output vector C
    float *h_C = (float *)malloc(size);

	    // Verify that allocations succeeded
    if (h_A == NULL || h_B == NULL || h_C == NULL)
    {
        fprintf(stderr, "Failed to allocate host vectors!\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the host input vectors
    for (int i = 0; i < numElements; ++i)
    {
        h_A[i] = rand()/(float)RAND_MAX;
        h_B[i] = rand()/(float)RAND_MAX;
    }

	int threadsPerBlock = 256;
    int blocksPerGrid =(numElements + threadsPerBlock - 1) / threadsPerBlock;
    printf("CUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
	for (int blockIdx = 0 ; blockIdx < blocksPerGrid ; ++blockIdx ) {
		for (int threadIdx = 0 ; threadIdx < threadsPerBlock ; ++threadIdx ) {
			vectorAdd(h_A, h_B, h_C, numElements , threadsPerBlock /* blockDim */, blockIdx, threadIdx);
		}
	}
}