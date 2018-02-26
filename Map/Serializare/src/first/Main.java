package first;

import java.io.IOException;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws IOException 
	{
		ArrayList<Player> list = new ArrayList<Player>();
		
		list.add(new Player("a",1,"a"));
		list.add(new Player("a",1,"a"));
		list.add(new Player("a",1,"a"));
		list.add(new Player("a",1,"a"));
		
		SerializableUtil.serialize(list, "C:\\Users\\Cristian\\eclipseWork\\Serializare\\src\\serial.txt");
		

	}

}
