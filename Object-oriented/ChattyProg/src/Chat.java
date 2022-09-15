import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.WindowConstants;

public class Chat 
{
	private static JTextArea texts;
	private String name, msg;
	private JTextField input;
	private JButton send;
	private Server server = new Server();
	

	public Chat(String Name) throws IOException 
	{
			name = Name;
			
			
			if(!Server.file.exists())
			{
				Server.file.createNewFile();
			}
			else
			{
				Server.file.delete();
				Server.file.createNewFile();
			}
			
			//Title of Chat
			JFrame jf = new JFrame("Chat");
			
			//Text Area of Messages
			JTextArea texts = new JTextArea(10,60);
			texts.setBounds(50,50,680,500);
			
		    //UserName on Messages
	       	JLabel label = new JLabel(name);
		       
		    //Input from the user
		    JTextField input = new JTextField(20);
		    
		    //Sends the messages
		    JButton send = new JButton("Send");   
		    send.addActionListener(new ActionListener() 
		    {
		    	@Override
		    	public void actionPerformed(ActionEvent e)
		    	{
					msg = input.getText();
					try 
					{
						Server.Server(msg,name,texts);
					} 
					catch (IOException e1) 
					{
						e1.printStackTrace();
					}
		    	}	    	   
		    }); 
	           
		    JPanel panel = new JPanel();
		    panel.add(label);
		    panel.add(input);
		    panel.add(send);
		    panel.add(texts);
		    jf.add(panel);
		    
		    Timer timer = new Timer();
		    TimerTask Update = new TimerTask() 
		    {
		    	@Override
		    	public void run()
		    	{
		    		try {
						Server.update(texts);
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					}
		    	}
		    };
		    timer.scheduleAtFixedRate(Update,5,5);
		    
		     
			jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
			jf.setSize(700,600);
			jf.setVisible(true);
	}
	
	public static void main(String[] args) throws IOException
	{	
		
		for(int i = 0; i < 2; i++)
		{
			String name = JOptionPane.showInputDialog("Enter your name : ");
			Chat chat = new Chat(name);
		}
		
	}
	
}
