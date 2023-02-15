import javax.swing.JFrame;
 
public class MyRectPanelExam
{
	public static void main(String[] args){
		JFrame frame = new JFrame("Rectangle Example");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		MyRectPanel primary = new MyRectPanel();
		
		frame.getContentPane().add(primary);
		frame.pack();
		frame.setVisible(true);
		 
	} //main()
 
	
} // MyRectPanelExam class
