package reverseString;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class Client1UDP {
	
	public static void main(String[] args) throws Exception
	{
		
		DatagramSocket ds = new DatagramSocket();
		InetAddress ia = InetAddress.getLocalHost();
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String message = sc.nextLine();
		sc.close();
		
		byte[] b = message.trim().getBytes();
		
		DatagramPacket dp = new DatagramPacket(b,b.length,ia,50005);
		ds.send(dp);
		
		DatagramSocket ds1 = new DatagramSocket(5006);
		
		byte[] b1 = new byte[1024];
		DatagramPacket dp1 = new DatagramPacket(b1,b1.length,ia,5006);
		ds1.receive(dp1);
		
		System.out.println("result: "+new String(dp1.getData()).trim());
		
		ds.close();
	}

}
