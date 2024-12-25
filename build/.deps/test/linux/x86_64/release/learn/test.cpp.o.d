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
            "-D__XMAKE__=\"/home/boyalv/infini/learning-cxx\"",
            "-finput-charset=UTF-8",
            "-fexec-charset=UTF-8",
            "-DNDEBUG"
        }
    },
    depfiles_gcc = "test.o: learn/test.cpp learn/test.h\
",
    files = {
        "learn/test.cpp"
    }
}