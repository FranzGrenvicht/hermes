#
# CMake for examples
#

# HEX
if(WITH_HEX)
    # H1
	if(H3D_REAL)
		add_subdirectory(elasticity-cubit-hex)
		add_subdirectory(heat-conduction)
		add_subdirectory(heat-cubit)
	endif(H3D_REAL)
	if(H3D_COMPLEX)
		add_subdirectory(rough)
	endif(H3D_COMPLEX)
endif(WITH_HEX)

if(WITH_TETRA)
		add_subdirectory(elasticity-cubit-tet)
endif(WITH_TETRA)
