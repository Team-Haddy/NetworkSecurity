import java.util.Scanner;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class SHA {
    public static void main(String args[]) {
        System.out.print("Enter a string to be encrypted : ");

        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        System.out.println("Encrypted Hashcode : " + encrypt(str));

        sc.close();
    }

    public static String encrypt(String s) {

        try {
            MessageDigest m = MessageDigest.getInstance("SHA-1");

            byte[] messageDigest = m.digest(s.getBytes());

            BigInteger n = new BigInteger(1, messageDigest);

            String hashcode = n.toString(16);

            while (hashcode.length() < 32)
                hashcode += "0";

            return hashcode;
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }
}

/*
 OUTPUT:
 Enter a string to be encrypted : cse
 Encrypted Hashcode : 85ecd6d2618f55b416513a664cc4d7866f54feda

 Enter a string to be encrypted : hello world
 Encrypted Hashcode : 2aae6c35c94fcfb415dbe95f408b9ce91ee846ed

 Enter a string to be encrypted : tech
 Encrypted Hashcode : c95ee47689a0aaec70c3eb950244657722c69b1f
 */