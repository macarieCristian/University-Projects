package secoundUDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ServerUDP {

	public static void main(String[] args) throws Exception
	{
		DatagramSocket ds = new DatagramSocket(5555);
		
		
		
			byte[] b1 = new byte[1024];
			byte[] be = new byte[1024];
			
			//DatagramPacket dp = new DatagramPacket(b1,b1.length);
			//ds.receive(dp);
			
			//String res = new String(dp.getData());
			//int len = Integer.parseInt(res.trim());
			int nr = 0;
			
			DatagramPacket dpe = new DatagramPacket(be,be.length);
				
			ds.receive(dpe);
			//String str = new String(dpe.getData());
			String str = new String(dpe.getData());
			//System.out.println(str);
			String[] el = str.split(",");
			for(String e : el)
			{
				nr += Integer.parseInt(e.trim());
			}
				
			
			
			
			byte[] b2 = (nr+"").getBytes();
			InetAddress ia = InetAddress.getLocalHost();
			//InetAddress ad = InetAddress.getByName("172.30.119.52");
			
			DatagramPacket dp1 = new DatagramPacket(b2,b2.length,dpe.getAddress(),dpe.getPort());
			ds.send(dp1);
		
		
		ds.close();

	}

}
