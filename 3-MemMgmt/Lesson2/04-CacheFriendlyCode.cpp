#include <chrono>
#include <iostream>

int main() {
  // create array
  const int size = 4;
  static int x[size][size];

  auto t1 = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      x[i][j] = i + j;
//      std::cout << &x[j][i] << ": j=" << j << " i=" << i << std::endl;
    }
  }

  // print execution time to console
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << "Execution time: " << duration << " microseconds." << std::endl;

  return 0;
}

/*
  Given that C++ follows a "row-major" as memory layout rule, the x[][] array will be stored in a single line as follows:

  0.0 | 0.1 | 0.2 |  0.3 | 1.0 | 1.1 | 1.2 | 1.3 | 2.0 | 2.1 | 2.2 | 2.3 | 3.0 | 3.1 | 3.2 | 3.3 (given a size=4)

  When trying to access x[][] in line 12, the two for-loops will be faster when accessing x[i][j] rather than x[j][i].

  The reason for being faster in [i][j] can be seen when printing out the addresses of each coordinate:

  0x6021e0: i=0, j=0
  0x6021e4: i=0, j=1
  0x6021e8: i=0, j=2
  0x6021ec: i=0, j=3

  0x6021f0: i=1, j=0
  0x6021f4: i=1, j=1
  0x6021f8: i=1, j=2
  0x6021fc: i=1, j=3

  0x602200: i=2, j=0
  0x602204: i=2, j=1
  0x602208: i=2, j=2
  0x60220c: i=2, j=3

  0x602210: i=3, j=0
  0x602214: i=3, j=1
  0x602218: i=3, j=2
  0x60221c: i=3, j=3

  The difference here is only of 0x04 between the two inner loops, whereas with [j][i] we get:

  0x6021e0: i=0, j=0
  0x6021f0: i=1, j=0
  0x602200: i=2, j=0
  0x602210: i=3, j=0

  0x6021e4: i=0, j=1
  0x6021f4: i=1, j=1
  0x602204: i=2, j=1
  0x602214: i=3, j=1

  0x6021e8: i=0, j=2
  0x6021f8: i=1, j=2
  0x602208: i=2, j=2
  0x602218: i=3, j=2

  0x6021ec: i=0, j=3
  0x6021fc: i=1, j=3
  0x60220c: i=2, j=3
  0x60221c: i=3, j=3

  which has a difference of 0x10 (which is 16 in decimal), This means that with each access to the matrix,
  four memory cells are skipped and the principle of spatial locality is violated.
  As a result, the wrong data is loaded into the L1 cache, leading to cache misses and costly reload operations,
  hence the significantly increased execution time between the two code samples.
*/
