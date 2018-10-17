package snippet;

public class Snippet {
	ByteArrayOutputStream swapStream = new ByteArrayOutputStream();  
	byte[] buff = new byte[1024];  
	int len = 0;  
	while ((len = in.read(buff, 0, 100)) > 0) {  
		swapStream.write(buff, 0, len);  
	}  
	byte[] body = swapStream.toByteArray();
}

