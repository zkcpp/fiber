'''
This is a sample build script to show how to write cpp rules
that cppbuild can use to generate Makefile.
'''

from defs import *

cpp_library(
  name = 'libfiber.a',
  srcs = [
           'ReferenceCounter.cpp',
         ]
)


cpp_binary(
  name = 'reference_counter_test',
  srcs = [
           'ReferenceCounterTest.cpp',
         ],
  deps = [
           'fiber:libfiber.a',
         ],
)
