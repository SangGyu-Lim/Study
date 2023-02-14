package com.example.echoclient;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

	public TextView ReceiveTextView;	
	public EditText SendEditText;
	public Button SendButton;	
	
	public Socket socket;
	public int SERVER_PORT = 8086;
	public String SERVER_IP = "210.107.230.201";
	//public String SERVER_IP = "235.7.8.9";
	public int BUFFER_SIZE = 1023;
	
	public BufferedReader inMsg = null;
	public BufferedWriter outMsg = null;		
	public String str;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		
		ReceiveTextView = ( TextView ) findViewById ( R.id.ReceiveTextView );
		SendEditText = ( EditText ) findViewById ( R.id.SendEditText );
		SendButton = ( Button ) findViewById ( R.id.SendButton );
				
		Thread thread = new Thread() {
			public void run() {
				try {
					socket = new Socket( SERVER_IP, SERVER_PORT );
					ReceiveTextView.setText( "echo client 연결 성공" );					
					
					inMsg = new BufferedReader( new InputStreamReader( socket.getInputStream() ), BUFFER_SIZE);
					outMsg = new BufferedWriter( new OutputStreamWriter( socket.getOutputStream() ), BUFFER_SIZE);
										
					try {						
						while(true) {
							str = inMsg.readLine();						
							ReceiveTextView.post( new Runnable() {							
							@Override
								public void run() {
									// TODO Auto-generated method stub
									ReceiveTextView.setText( str );
								}
							});
						}
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}										
					
				} catch (UnknownHostException e) {
					ReceiveTextView.setText( "UnknownHostException 에러" );
					e.printStackTrace();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		};
		
		thread.start();		
		
		SendButton.setOnClickListener( new OnClickListener() {			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				PrintWriter out = new PrintWriter( outMsg, true);
				out.println( SendEditText.getText() );
			}
		});		
	}	
}
