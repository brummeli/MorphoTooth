project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES
        Cell.h
        Geometrics.h
        Initial.h
        Model.h
        Output.h
        ImplementParams.h
        )
set(SOURCE_FILES
        Geometrics.cpp
        Initial.cpp
        Model.cpp
        Output.cpp
        Input.cpp Input.h consts.h ProgramMorphoTooth.cpp ProgramMorphoTooth.h Noise.cpp Noise.h Print.cpp Print.h Utility.cpp Utility.h ModelParams.h json.h json.h ModelParams.cpp)


add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )
