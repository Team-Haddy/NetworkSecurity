import java.util.Scanner;

import java.security.*;

public class DigitalSignature {

    public static byte[] createSign(byte[] input, PrivateKey privateKey) throws Exception {
        Signature signature = Signature.getInstance("SHA256withRSA");

        signature.initSign(privateKey);
        signature.update(input);

        return signature.sign();
    }

    public static KeyPair generateKeyPair() throws Exception {

        SecureRandom secureRandom = new SecureRandom();

        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(2048, secureRandom);

        return keyPairGenerator.generateKeyPair();
    }

    public static boolean verifySign(byte[] input, byte[] sign, PublicKey publicKey) throws Exception {

        Signature signature = Signature.getInstance("SHA256withRSA");

        signature.initVerify(publicKey);
        signature.update(input);

        return signature.verify(sign);
    }

    public static String bytesToHex(byte[] a) {

        StringBuilder sb = new StringBuilder(a.length * 2);

        for (byte b : a)
            sb.append(String.format("%02x", b));

        return sb.toString();
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string : ");
        String s = sc.nextLine();
        KeyPair keyPair = generateKeyPair();

        byte[] sign = createSign(s.getBytes(), keyPair.getPrivate());

        System.out.println(
                "Signature : " + bytesToHex(sign) +
                        "\n\nSignature Verification Status : " + verifySign(s.getBytes(), sign, keyPair.getPublic()));

        sc.close();
    }
}


/*
 OUTPUT:
 Enter a string : computer
 Signature : 507b83aaae0ea08f742656a8aec8103ba8862d82e0f5b68d4031df73910110a6f21249b2c2e83025a4c8f812f60f019e96aa22462f81ba21e5547564000672abe7c0548588de01a1136d4bcce343ec97d150b5a83fd119b5ccde3eacfe274fe1c5718682744829079ebdcbdc8c1f35639ae6eec372ed8e587d7545ebd705c9e1c23db74efa315cc586c336015fd4fa5b13da8632e463b122eb3ec17d0f15e917742ecd1c5ac12047fbc1e5cf97f5f49f60fc33196ad777bb5cb67d4f947ef29d0345870f33a62065adf9665986429b6e92097151fd15168556c13296be2226c3eff2316879b61384a6e52fb0b406d4a86bcd38da4069b3c3cf39c823c0ea2f82

 Signature Verification Status : true



 Enter the string to be encrypted : network
 Signature : 8593402fd6761f3bde154802f6511d548c09d85c6e41cbc11fab3d7603d7521f51921cda83a65620e06df74238c9a35c4542f76e18c825c3ae7619c6efb294749c205105e7a903135ce81bcb3bae6cecb92651756f9529b69608261862b3fa5a749527973c08827a950d6efeb95b297c3b2297932feae9313cf2a2380aa93029b9e136019f26d971e717948b0bbd031692e978f16a4d300b6381b5c4d968592d0a7b475a7679cbc32cdea0ac4a710b2178ac78f409d6a4487312d05e7ec821ca7679152d65ea277699a2a5664e0546cc6b0d0d5880c1c515ecdf280ed31c2ad3da73fb9a6befb59156510a0511e610e6daaab1ed52d9d7bf0c179770bf765f20

 Signature Verification Status : true

 */