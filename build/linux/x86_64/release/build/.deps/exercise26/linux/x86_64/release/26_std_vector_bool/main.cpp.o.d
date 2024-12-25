{
    files = {
        "26_std_vector_bool/main.cpp"
    },
    depfiles_gcc = "main.o: 26_std_vector_bool/main.cpp 26_std_vector_bool/../exercise.h\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-Wall",
            "-O3",
            "-std=c++17",
            "-finput-charset=UTF-8",
            "-fexec-charset=UTF-8",
            "-DNDEBUG"
        }
    }
}