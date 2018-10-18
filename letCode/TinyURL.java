public class Codec {
    
    HashMap<Integer, String> shorttwo;
    static int number;
    String elements;
    Codec() {
        
        shorttwo = new HashMap<Integer, String>();
        number = 1;
        elements = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    
    public String to62(int num){
        StringBuffer str= new StringBuffer();
        while(num!=0){
            str.insert(0,elements.charAt(num%62));
            num/=62;
        }
        while(str.length()<6){
            str.insert(0,'0');
        }
        return str.toString();
    }

    public String encode(String longUrl) {
        StringBuffer str = new StringBuffer();
        shorttwo.put(number,longUrl);
        str.append("http://tinyurl.com/");
        str.append(to62(number));
        number++;
        System.out.println(longUrl + " : "+str.toString());
        return str.toString();
        
        
    }
    
   public int to10(String s) {
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            n = n * 62 + charToInt(s.charAt(i));
        }
        return n;
        
    }
    public int charToInt(char c) {
        if (c >= '0' && c <= '9')
            return c - '0';
        if (c >= 'a' && c <= 'z') {
            return c - 'a' + 10;
        }
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 36;
        }
        return -1;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
     
                System.out.println(shortUrl.substring("http://tinyurl.com/".length()));
       
        int num = to10(shortUrl.substring("http://tinyurl.com/".length()));
        
        return shorttwo.get(num);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
