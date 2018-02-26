package secoundUDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.Scanner;

public class ClientUDP {

	public static void main(String[] args) throws Exception 
	{
		
		DatagramSocket ds = new DatagramSocket();
		InetAddress ia = InetAddress.getLocalHost();
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the length: ");
		int len;
		len = sc.nextInt();
		ArrayList<Integer> al = new ArrayList<Integer>();
		for(int i=0;i<len;i++)
		{
			System.out.print("Enter the "+(i+1)+" num: ");
			al.add(sc.nextInt());
		}
		sc.close();
		
		byte[] b = (len+"").getBytes();
		DatagramPacket dp = new DatagramPacket(b,b.length,ia,7777);
		ds.send(dp);
		
		String arr="";
		
		for(int x : al)
		{
//			byte[] b1 = (x+"").getBytes();
//			DatagramPacket dpx = new DatagramPacket(b1,b1.length,ia,7777);
//			ds.send(dpx);
			arr += x+",";
		}
		arr = arr.substring(0,arr.length()-1);
//		System.out.println(arr);
		byte[] b1 = arr.getBytes();
		DatagramPacket dpx = new DatagramPacket(b1,b1.length,ia,7777);
		ds.send(dpx);
		
		
		
		
		byte[] b2 = new byte[1024];
		DatagramPacket dp1 = new DatagramPacket(b2,b2.length);
		ds.receive(dp1);
		
		String result = new String(dp1.getData());
		System.out.println("Sum is: "+result);
		
		ds.close();
	}

}
