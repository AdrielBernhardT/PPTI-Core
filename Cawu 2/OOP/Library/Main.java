public class Main { // Harus sama dengan nama File
   public Main() { // Nama Method harus sama dengan nama File (Declare Struct kalau di C)
      // [Class == Struct]

      // <nama Class> <nama Variable> = new <nama Class>(<parameter>); -> Manggil Class Author baru untuk masukin ke isi
      Author author1 = new Author("James Gosling", "Creator of the Java programming language."); 
      Author author2 = new Author("Robert C. Martin", "Known for his works on software craftsmanship.");

      // author1 -> Class Author yang kita buat di atas dengan isi Name, Biography
      // Class book perlu judul, ISBN, dan class author yang udah di isi
      Book book1 = new Book("Java Programming", "123456789", author1); 
      Book book2 = new Book("Clean Code", "987654321", author2);

      // <nama Class> <nama Variable> = new <nama Class>(); -> declare library isinya adalah class Library.java
      Library library = new Library();

      // <nama Variable>.<nama function>(<parameter>); -> Manggil function addBook di Class Library dimana sudah di masukin di library
      library.addBook(book1); // book1 -> Class buku yang kita buat di atas dengan isi Title, ISBN, Author
      library.addBook(book2); // book2 -> Class buku yang kita buat di atas dengan isi Title, ISBN, Author

      // Declare class Borrower baru dengan nama variable borower yang di isi "Alice"
      Borrower borrower = new Borrower("Alice");

      // manggil function borrowBook di class Library dimana sudah di masukin di library
      library.borrowBook(borrower, book1);
      library.borrowBook(borrower, book2);

      // Panggil function displayBorrowedBooks di class Borrower
      borrower.displayBorrowedBooks();

      // Panggil function returnBook di class Library
      library.returnBook(borrower, book1);

      // Panggil function displayBorrowedBooks di class Borrower
      borrower.displayBorrowedBooks();
      
      // Panggil function displayLibraryBooks di class Library
      library.displayLibraryBooks();
   }

   // kalau di-C == int main -> buat menjalankan program
   public static void main(String[] args) {
      // Buat ngejalanin program Main makanya new Main(); -> jalanin class main baru
      new Main();
   }
   // Ga harus ada di setiap Class
}
