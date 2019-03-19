package com.azenk.comm_socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class CommEmitter {
    public CommEmitter(int Port) {
    	this.Port = Port;
    	try {
			this.socket = new DatagramSocket();
			this.socket.setBroadcast(true);
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
    
    private int Port;
    private DatagramSocket socket;
    
    public void Send(byte[] Buffer) {
    	DatagramPacket packet = null;
		try {
			packet = new DatagramPacket(Buffer, Buffer.length, InetAddress.getByName("255.255.255.255"), this.Port);
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        
    	try {
    		this.socket.send(packet);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
    
	protected void finalize() {
		this.socket.close();
	}
}
