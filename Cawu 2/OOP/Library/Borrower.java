import java.util.ArrayList;

public class Borrower {
    String peminjam;
    ArrayList<Book> pinjaman = new ArrayList<Book>();

    public Borrower(String string1){
        peminjam = string1;
    }

    public void displayBorrowedBooks() {
        System.out.println(peminjam + "'s Borrowed Books:" );
        for (Book temp : pinjaman) {
            System.out.println("Title: " + temp.title);
            System.out.println("ISBN: " + temp.ISBN);
            System.out.println("Author: " + temp.author.nama);
            System.out.println("Biography: " + temp.author.deskripsi);
            System.out.println("---------------------------");
        }
    }
}
