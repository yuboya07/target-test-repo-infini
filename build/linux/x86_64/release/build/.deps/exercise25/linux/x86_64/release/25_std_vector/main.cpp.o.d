{
    files = {
        "25_std_vector/main.cpp"
    },
    depfiles_gcc = "main.o: 25_std_vector/main.cpp 25_std_vector/../exercise.h\
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