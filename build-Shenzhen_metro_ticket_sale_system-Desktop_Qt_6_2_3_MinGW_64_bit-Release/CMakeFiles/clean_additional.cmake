# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Shenzhen_metro_ticket_sale_system_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Shenzhen_metro_ticket_sale_system_autogen.dir\\ParseCache.txt"
  "Shenzhen_metro_ticket_sale_system_autogen"
  )
endif()
