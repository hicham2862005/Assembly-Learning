import ctypes		# to call the functions from the library
import os		# for the path functionalities

# the abslout path of the library
library_path = os.path.abspath("operations.so")		# in case of Linux

# Getting an interface with the library so we can use it's functions
operations = ctypes.CDLL(library_path)

# Example of using one the functions from the library through the interface
result = operations.Add(10,20)
print("Result: ",result)
