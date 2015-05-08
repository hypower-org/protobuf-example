project (prototest)

link_directories(/usr/local/lib)
add_executable(Prototest write_message.cpp command.pb.cc)
target_link_libraries (Prototest protobuf)
