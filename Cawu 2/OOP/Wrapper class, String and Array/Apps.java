import java.util.*;

class Mahasiswa { // Struct
    int NIM;
    char[] name = new char[20];
    int umur;
}

public class Apps {
    // Declare
    int x;
    Integer y;
    ArrayList<Integer> ArrayLagi = new ArrayList<Integer>();

    // Function Main
    public Apps(){ // Harus sesuai Nama File
        // Data type Integer bisa di ikuti dengan function bawaan 
        // y.toString();

        // Data type Integer bisa di ikuti dengan function konversi data type
        /*
        y.longValue();
        y.floatValue();
        y.doubleValue();
        y.byteValue();
        y.shortValue();
         */

        // Setiap data numeric, punya data constant
        /*
            System.out.println(y.MAX_VALUE);
        */
        x = Integer.parseInt("99996");

        System.out.println(x);

        String nama = "Joko";
        System.out.println(nama);
        /*
            function pada String:
            1. length()
            2. charAt(Index)
            3. concat(s1)
            4. toUpperCase()
            5. toLowerCase()
            6. trim()
            
            function yang mirip string.h di C:
            1. equals(s1)
            2. equalsIgnoreCase(s1)
            3. compareTo(s1)
            4. compareToIgnoreCase(s1)
            5. startsWith(prefix)
            6. endWith(suffix)
            7. contains(s1)
        */

        /*
            System.out.println(nama.equals("joko"));
            System.out.println(nama.equalsIgnoreCase("joko"));
            System.out.println(nama.compareTo("budi")); // strcmp perbedaan ascii
            System.out.println(nama.compareToIgnoreCase("budi"));
            System.out.println(nama.startsWith("Jok"));
            System.out.println(nama.startsWith("jok"));
            System.out.println(nama.endsWith("ko"));
            System.out.println(nama.endsWith("Ko"));
        */

        // String kata = "Pro-192143158351Adriel";
        
        /* 
        function pada String 2:
            1. substring(beginingIndex)
            2. substring(beginingIndex,endIndex)
        */

        // Size boleh sesuai tanpa di lebihkan untuk Null Terminator
        // int[] ArraySial = new int [105];
        // String[] kataSialan = new String [50];
        // Mahasiswa[] mhs = new Mahasiswa [100];

        // arr 2D
        // Integer [][] = duade new int [50][50];
        Integer duade[][] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        for(Integer n = 0; n < duade.length; n++){
            for(Integer m = 0; m < duade[n].length; m++){
                System.out.print(duade[n][m] + " ");
            }
            System.out.println();
        }

        // ArrayLagi.add(9);
        // ArrayLagi.add(3);
        // ArrayLagi.add(2);
        // ArrayLagi.add(8);
        // for (Integer n : ArrayLagi){
        //     System.out.println(n);
        // }

    }

    // Function main buat ngejalanin function yang ada di atasnya
    public static void main(String[] args){
        new Apps(); // manggil function yang sesuai nama File
    }

}