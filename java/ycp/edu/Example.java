package ycp.edu;


import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintStream;

import ycp.edu.PhysicloudProtos.Command;

public class Example {
	public static void main(String[] args) throws Exception {
	    if (args.length != 1) {
	      System.err.println("Usage:  Example COMMAND_FILE");
	      System.exit(-1);
	    }

	    Command.Builder commandBuilder = Command.newBuilder();

	    // Read the existing address book.
	    try {
	      commandBuilder.mergeFrom(new FileInputStream(args[0]));
	    } catch (FileNotFoundException e) {
	      System.out.println(args[0] + ": File not found.  Creating a new file.");
	    }

	    // Add an address.
//	    commandBuilder.setName("GTG");
//	    commandBuilder.setV((float) 1.67);
//	    commandBuilder.setW((float)6.67);
	    Command command = commandBuilder.build(); 
	    // Write the new address book back to disk.
	    FileOutputStream output = new FileOutputStream(args[0]);
	    command.writeTo(output);
	    System.out.println(command.getName());
	    System.out.println(command.getV());
	    System.out.println(command.getW());
	    output.close();
	  }
}
