CYTHON_ADD_MODULE_PYX(hermes2d)
CYTHON_ADD_MODULE_PYX(numpy_utils)

include_directories(${PROJECT_BINARY_DIR}/src)
add_python_library(numpy_utils numpy_utils.cpp)
add_python_library(hermes2d hermes2d.cpp)
target_link_libraries(hermes2d ${HERMES_REAL_BIN})
set(PY_PATH ${PYTHON_INSTALL_PATH}/hermes2d)
install(TARGETS hermes2d
            RUNTIME DESTINATION ${PY_PATH}
            ARCHIVE DESTINATION ${PY_PATH}
            LIBRARY DESTINATION ${PY_PATH}
        )
install(TARGETS numpy_utils
            RUNTIME DESTINATION ${PY_PATH}
            ARCHIVE DESTINATION ${PY_PATH}
            LIBRARY DESTINATION ${PY_PATH}
        )
install(FILES __init__.py plot.py
    DESTINATION ${PY_PATH}
    )


add_subdirectory(modules)
