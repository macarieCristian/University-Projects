package UDPConcurrent;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client11 {
public static void main(String[] args) {
		
		try (DatagramSocket ds = new DatagramSocket();)
		{
			InetAddress ia = InetAddress.getByName("172.30.114.6");
			
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter a string: ");
			String message = sc.nextLine();
//			sc.close();
			
			byte[] b = message.trim().getBytes();
			byte[] b2 = new byte[1024];
			
			DatagramPacket dp = new DatagramPacket(b,b.length,ia,7000);
			ds.send(dp);
			
			DatagramPacket dpr = new DatagramPacket(b,b.length);
			ds.receive(dpr);
			
			System.out.println(new String(dpr.getData()).trim());
			
			DatagramPacket dprport = new DatagramPacket(b2,b2.length);
			ds.receive(dprport);
			
			String portS = new String(dprport.getData()).trim();
			//System.out.println(portS.trim());
			int newServerP = Integer.parseInt(portS.trim());
			
			System.out.print("Enter a string: ");
			String mesage = sc.nextLine();
			
			
			byte[] btos = mesage.trim().getBytes();
			
			DatagramPacket dpsend = new DatagramPacket(btos,btos.length,ia,newServerP);
			ds.send(dpsend);
			
			byte[] fin = new byte[1024];
			DatagramPacket dpfin = new DatagramPacket(fin,fin.length);
			ds.receive(dpfin);
			System.out.println(new String(dpfin.getData()).trim());
			
			sc.close();
			
		}
		catch (SocketException e) 
		{
			
			e.printStackTrace();
		} 
		catch (UnknownHostException e) 
		{
			
			e.printStackTrace();
		} 
		catch (IOException e) 
		{
			
			e.printStackTrace();
		}


	}
}
