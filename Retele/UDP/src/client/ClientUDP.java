package client;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class ClientUDP {

	public static void main(String[] args) throws Exception 
	{
		
		DatagramSocket ds = new DatagramSocket();
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int x;
		x = sc.nextInt();
		sc.close();
		
		byte[] b1 = (x+"").getBytes();
		
		InetAddress ia = InetAddress.getLocalHost();
		DatagramPacket dp = new DatagramPacket(b1,b1.length,ia,5555);
		ds.send(dp);
		
		
		byte[] b2 = new byte[1024];
		DatagramPacket dp1 = new DatagramPacket(b2,b2.length);
		ds.receive(dp1);
		
		String result = new String(dp1.getData());
		System.out.println(result);
		
		ds.close();
	}

}
