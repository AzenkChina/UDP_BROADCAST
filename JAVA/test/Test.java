package test;

import com.azenk.comm_socket.*;

public class Test {
	public static void main(String[] args) {
		CommReceiver Receiver = new CommReceiver(20001);
		
		Receiver.start();
		
		CommEmitter Emitter = new CommEmitter(20001);
		byte[] buff = "AAAAAAAA".getBytes();
		Emitter.Send(buff);
		
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		byte[] result = Receiver.Receive();
		String Result = new String(result);
		
		System.out.println(Result);
    }
}
