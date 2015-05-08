#include <iostream>
#include <fstream>
#include <string>
#include "command.pb.h"
using namespace std;

// This function fills in a Person message based on user input.
void createCommand(control::Command* command) {
  command->set_name("gtg");
  command->set_v(1.67);
  command->set_w(5.67);
}

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " COMMAND_FILE" << endl;
    return -1;
  }

  control::Command command;

  {
    // Read the existing address book.
    fstream input(argv[1], ios::in | ios::binary);
    if (!input) {
      cout << argv[1] << ": File not found.  Creating a new file." << endl;
    } else if (!command.ParseFromIstream(&input)) {
      cerr << "Failed to parse command from file." << endl;
      return -1;
    }
  }
  cout << command.DebugString()  << endl;
  createCommand(&command);
  
  {
    // Write the new address book back to disk.
    fstream output(argv[1], ios::out | ios::trunc | ios::binary);
    if (!command.SerializeToOstream(&output)) {
      cerr << "Failed to write command." << endl;
      return -1;
    }
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}