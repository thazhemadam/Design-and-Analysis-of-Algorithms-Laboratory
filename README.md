# Design and Analysis of Algorithms - Laboratory

## Introduction
This repository contains programs that were created as a part of the coursework for ***Design and Analysis of Algorithms - Laboratory***.</br>

## Structure
For each of the algorithms implemented, four files can be found (generally).

1. **<header_file_name>.h** : <br />
	The header file elaborating the functions to be implemented.

2. **<implementation_file_name>.c** : <br /> 
	The implementation file which implements the algorithm required.

3. **<sample_test_file_name>.c** : <br />
	The sample test file helps in understanding and implementing the required. 
	
4. **<tests_object_file_name>.o** : <br />
	The tests object file has an exhaustive set of test cases to assess the implementation.<br />
	Note: Not all algorithms have a tests object file.

## Execution

*	The implementation can be tested against sample test cases by running the following command.
	```
	$ gcc -Wall <implementation_file_name>.c <sample_test_file_name>.c -o sampletests.out
	$ ./sampletests.out
	```
*	The implementation can be tested against the tests object file by running the following command.
	```
	$ gcc -Wall <implementation_file_name>.c <tests_object_file_name>.o -o ss_tests.out
	$ ./tests.out
	```

