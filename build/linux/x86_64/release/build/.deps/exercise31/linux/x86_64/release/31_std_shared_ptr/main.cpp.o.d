{
    depfiles_gcc = "main.o: 31_std_shared_ptr/main.cpp 31_std_shared_ptr/../exercise.h\
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
    },
    files = {
        "31_std_shared_ptr/main.cpp"
    }
}