{
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
    depfiles_gcc = "main.o: 33_std_accumulate/main.cpp 33_std_accumulate/../exercise.h\
",
    files = {
        "33_std_accumulate/main.cpp"
    }
}