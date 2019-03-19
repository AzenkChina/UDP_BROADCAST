package com.azenk.comm_socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.lang.Thread;

public class CommReceiver extends Thread {
	public CommReceiver(int Port){
		try {
			this.socket = new DatagramSocket(Port);
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		byte[] buff = new byte[4096];
		packet = new DatagramPacket(buff, buff.length);
	}

	@Override public void run() {
		while (true) {
			try {
				this.socket.receive(this.packet);
				this.result = this.packet.getData();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	protected void finalize() {
		this.socket.close();
	}

	private DatagramSocket socket;
	private DatagramPacket packet;
	private byte[] result;

	public byte[] Receive() {
		byte[] result = null;
		if(this.result != null) {
			result = new byte[this.result.length];
			System.arraycopy(this.result, 0, result, 0, this.result.length);
			this.result = null;
		}
		
		return result;
	}
}
