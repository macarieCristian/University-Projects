package reverseString;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;


class MyThread extends Thread
{
	
	private DatagramSocket ds;
	private InetAddress ia;
	
	public MyThread(DatagramSocket s, InetAddress a)
	{
		ds = s;
		ia = a;
	}
	
	@Override
	public void run()
	{
		try
		{
			byte[] b = new byte[1024];
			DatagramPacket dp = new DatagramPacket(b,b.length);
			ds.receive(dp);
		
			String str = new String(dp.getData()).trim();
			StringBuffer rev = new StringBuffer(str);
			rev.reverse();
		
			byte[] b1 = rev.toString().getBytes();
			DatagramPacket dp1 = new DatagramPacket(b1,b1.length,ia,dp.getPort());
			ds.send(dp1);
		
		
			//ds.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}

class CThread extends Thread
{
	private int port;
	DatagramPacket dp;
	private InetAddress ia;
	
	public CThread(DatagramPacket d) 
	{
		dp=d;
		port=d.getPort();
		ia = d.getAddress();
	}
	
	@Override
	public void run()
	{
		try(DatagramSocket ss = new DatagramSocket(5006);)
		{
		
			String str = new String(dp.getData()).trim();
			StringBuffer rev = new StringBuffer(str);
			rev.reverse();
			
			byte[] b1 = rev.toString().getBytes();
			DatagramPacket dp1 = new DatagramPacket(b1,b1.length,ia,5006);
			ss.send(dp1);
		} catch (IOException e) 
		{
			e.printStackTrace();
		}
		
	}
}

class A extends Thread
{
	
	@Override
	public void run()
	{
		Example.x = 7;
		System.out.println(Example.x+"");
	}
}

class Example
{
	static int x;
}


public class ServerUDP {
	

	static String s;
	
	public static void main(String[] args) throws Exception
	{
		
		DatagramSocket ds = new DatagramSocket(7777);
		InetAddress ia = InetAddress.getLocalHost();
		
//		byte[] b = new byte[1024];
//		DatagramPacket dp = new DatagramPacket(b,b.length);
//		ds.receive(dp);
//		
//		String str = new String(dp.getData()).trim();
//		StringBuffer rev = new StringBuffer(str);
//		rev.reverse();
////		for(int i=str.length()-1;-1<i;i--)
////		{
////			rev.append(str.charAt(i));
////		}
//		
//		byte[] b1 = rev.toString().getBytes();
//		DatagramPacket dp1 = new DatagramPacket(b1,b1.length,ia,dp.getPort());
//		ds.send(dp1);
//		
//		
//		ds.close();
		
		
//		while(true)
//		{
//			byte[] b = new byte[1024];
//			DatagramPacket dp = new DatagramPacket(b,b.length);
//			ds.receive(dp);
//			CThread t = new CThread(dp);
//			t.run();
//			
//		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
//		Runnable t = new Runnable() 
//		{
//
//			@Override
//			public void run() 
//			{
//				System.out.println("Ceva");
//				
//			}
//			
//		};
		//t.run();
		
		
//		MyThread mt = new MyThread(ds,ia);
//		mt.start();
		
//		MyThread mt1 = new MyThread(ds,ia);
//		mt1.start();
		
	}

}
