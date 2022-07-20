# fftw3_pybind

For a simple FFT computation, we observed some differences between the C program call and the
Python call.

The build environment needs cmake, pybind11 and fftw3 in it

Build can be reproduced by cleaning the build folder and doing the following :
```
cd build
cmake ../src
cmake --build .
./Main > result_call_c.txt
python -c "from bindings import foo;foo()" > result_call_python.txt
```

Then the diff between the output can be visualized :
`diff  result_call_python.txt result_call_c.txt`

Note that for simplicity the foo() function is duplicated between bindings.cpp and main.c. A simple diff between the source files shows that the functions are identical.
