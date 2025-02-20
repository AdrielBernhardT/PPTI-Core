import java.util.ArrayList;

public class Library {
    ArrayList<Book> Perpustakaan = new ArrayList<Book>();

    public void addBook(Book namaBuku){
        Perpustakaan.add(namaBuku);
    }

    public void borrowBook(Borrower borrower, Book book1) {
        borrower.pinjaman.add(book1);
        Perpustakaan.remove(book1);
        System.out.println(borrower.peminjam + " borrowed: " + book1.title);
    }

    public void returnBook(Borrower borrower, Book book1) {
        borrower.pinjaman.remove(book1);
        Perpustakaan.add(book1);
        System.out.println(borrower.peminjam + " returned: " + book1.title);
    }

    public void displayLibraryBooks() {
        for (Book temp : Perpustakaan) {
            System.out.println("Title: " + temp.title);
            System.out.println("ISBN: " + temp.ISBN);
            System.out.println("Author: " + temp.author.nama);
            System.out.println("Biography: " + temp.author.deskripsi);
            System.out.println("---------------------------");
        }
    }
}
