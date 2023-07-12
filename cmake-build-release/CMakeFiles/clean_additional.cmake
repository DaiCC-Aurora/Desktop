# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Desktop_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Desktop_autogen.dir\\ParseCache.txt"
  "Desktop_autogen"
  )
endif()
