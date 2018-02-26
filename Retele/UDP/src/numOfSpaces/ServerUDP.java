package numOfSpaces;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ServerUDP {

	public static void main(String[] args) throws Exception
	{
		
		DatagramSocket ds = new DatagramSocket(5000);
		InetAddress ia = InetAddress.getLocalHost();
		
		byte[] b = new byte[1024];
		DatagramPacket dp = new DatagramPacket(b,b.length);
		ds.receive(dp);
		
		String str = new String(dp.getData()).trim();
		int nrOfSpaces = 0;
		for(int i=0;i<str.length();i++)
		{
			if(str.charAt(i)==' ')
				nrOfSpaces++;
		}
		
		byte[] b1 = (nrOfSpaces+"").getBytes();
		DatagramPacket dp1 = new DatagramPacket(b1,b1.length,ia,dp.getPort());
		ds.send(dp1);
		
		
		ds.close();
		
	}

}
