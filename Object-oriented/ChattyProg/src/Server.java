import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import javax.swing.JTextArea;

public class Server {
	
	public static File file = new File("textmessages.txt");
	
	public static void Server(String msg, String name, JTextArea texts) throws IOException 
	{	
		
		BufferedWriter out = new BufferedWriter(new FileWriter(file,true));
		out.write(name + ": " + msg + "\n");
		out.close();
		Scanner scanner = new Scanner(file);
		texts.setText("");  
	    while (scanner.hasNext()){
	        texts.append(scanner.nextLine() + "\n");
	    }
	}
	public static void update(JTextArea texts) throws FileNotFoundException
	{
		Scanner scanner = new Scanner(file);
		texts.setText("");  
	    while (scanner.hasNext()){
	        texts.append(scanner.nextLine() + "\n");
	    }
	}
	public static void main() throws IOException
	{

	}
}
