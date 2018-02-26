package UDPConcurrent;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;


class SThread extends Thread
{
	private DatagramPacket dpr;
	int socketPort;
	Thread t;
	
	public SThread(DatagramPacket dp, int p)
	{
		dpr = dp;
		socketPort = p;
		t = new Thread(this);
		t.start();
	}
	
	@Override
	public void run()
	{
		try(DatagramSocket dst = new DatagramSocket(socketPort);)
		{
//			DatagramSocket dst = new DatagramSocket(socketPort);
//			System.out.println(Thread.currentThread().getId());
			
			StringBuffer sb = new StringBuffer(new String(dpr.getData()).trim());
			String res = sb.reverse().toString();
			
			
			byte[] b = res.getBytes();
			byte[] b2 = new byte[1024];
			
			DatagramPacket dp = new DatagramPacket(b,b.length,dpr.getAddress(),dpr.getPort());
			dst.send(dp);
			
			byte[] bport = new String(socketPort+"").trim().getBytes();
			DatagramPacket dp2 = new DatagramPacket(bport,bport.length,dpr.getAddress(),dpr.getPort());
			dst.send(dp2);
			
			DatagramPacket dp3 = new DatagramPacket(b2,b2.length);
			dst.receive(dp3);
			
			String result = new String(dp3.getData()).trim();
//			System.out.println(result);
			
			StringBuffer buff = new StringBuffer(result);
			String tos = buff.reverse().toString();
			byte[] bb = tos.getBytes();
			DatagramPacket dp4 = new DatagramPacket(bb,bb.length,dp3.getAddress(),dp3.getPort());
			dst.send(dp4);
			
			
		}
		catch (IOException e) 
		{
			
			e.printStackTrace();
		}
		
	}
}

class Global
{
	public static int port=7000;
}

public class ServerCo 
{
	
	public static void main(String[] argv)
	{
		try (DatagramSocket ds = new DatagramSocket(7000,InetAddress.getLocalHost());)
		{
//			InetAddress ia = InetAddress.getLocalHost();
//			DatagramSocket ds = new DatagramSocket(7000,ia);
			
			int x = 7000;
			
			while(true)
			{
				byte[] b = new byte[1024];
				DatagramPacket dp = new DatagramPacket(b,b.length);
				ds.receive(dp);
			
				
//				Global.port++;
				x++;
				new SThread(dp,x);
			}
			
			
//			StringBuffer sb = new StringBuffer(new String(dp.getData()).trim());
//			String res = sb.reverse().toString();
//			//System.out.println(res);
//			
//			b = res.getBytes();
//			DatagramPacket dps = new DatagramPacket(b,b.length,dp.getAddress(),dp.getPort());
//			System.out.println(dp.getPort());
//			ds.send(dps);
			
			
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
