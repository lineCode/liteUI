
macro(symlink source destination)
    if (NOT EXISTS ${destination})
        get_filename_component(DESTINATION_DIR "${destination}" DIRECTORY)
        file(MAKE_DIRECTORY ${DESTINATION_DIR})
        execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination})
    endif ()
endmacro()

file(GLOB_RECURSE SOURCE_FILES *.cpp *.h)
add_executable(liteUI ${SOURCE_FILES})
target_link_libraries(liteUI Atomic UrhoUI litehtml)

symlink (${CMAKE_SOURCE_DIR}/dep/AtomicGameEngine/Resources/CoreData ${CMAKE_BINARY_DIR}/bin/CoreData)
symlink (${CMAKE_SOURCE_DIR}/bin/GameData ${CMAKE_BINARY_DIR}/bin/GameData)
