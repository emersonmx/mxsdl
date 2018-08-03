set(MXG_PREFIX mxg)

message(STATUS "${CC} ${CXX}")

ExternalProject_Add(${MXG_PREFIX}
    URL https://github.com/emersonmx/${MXG_PREFIX}/archive/master.zip
    PREFIX thirdparty/${MXG_PREFIX}
    INSTALL_COMMAND ""
    LOG_DOWNLOAD 1
)

ExternalProject_Get_Property(${MXG_PREFIX} SOURCE_DIR BINARY_DIR)

set(MXG_INCLUDE_DIRS "${SOURCE_DIR}/include" CACHE INTERNAL "Path to include folder for mxg")
include_directories(${MXG_INCLUDE_DIRS})

set(MXG_LIBRARY_DIRS "${BINARY_DIR}/src/${MXG_PREFIX}")
set(MXG_LIBRARIES "${MXG_LIBRARY_DIRS}/lib${MXG_PREFIX}.a")
