import java.util.Scanner;

public class LatihanTicTacToe {
  static Integer kordinat_x, kordinat_y; // Variabel koordinat
  char map[][] = { // Map game
    {'-', '-', '-'}, 
    {'-', '-', '-'},
    {'-', '-', '-'}
  };

  public void drawMap() {
    for (int i = 0; i < 3; i++) { // View Map
      for (int j = 0; j < 3; j++) {
        System.out.print(map[i][j] + " ");
      }
      System.out.println();
    }
  }

  public boolean checkWin(char player) {
    for (int i = 0; i < 3; i++) {
      if (map[i][0] == player && map[i][1] == player && map[i][2] == player) return true; // Baris
      if (map[0][i] == player && map[1][i] == player && map[2][i] == player) return true; // Kolom
    }
    if (map[0][0] == player && map[1][1] == player && map[2][2] == player) return true; // Diagonal
    if (map[0][2] == player && map[1][1] == player && map[2][0] == player) return true; // Diagonal sisa
    return false;
  }

  public boolean isFull() {
    for (int i = 0; i < 3; i++) { // Memeriksa apakah peta penuh/tidak ada yang kosong ('-')
      for (int j = 0; j < 3; j++) {
        if (map[i][j] == '-') return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int choice;

    do {
      System.out.println("1. Play Game"); // Pilihan menu
      System.out.println("0. Exit");
      System.out.print("Choice: ");
      choice = input.nextInt();

      if (choice == 1) { // Jika pemain memilih untuk bermain
        LatihanTicTacToe game = new LatihanTicTacToe(); // Membuat objek permainan
        game.drawMap(); // Menggambar peta awal

        char currentPlayer = 'X'; // Pemain pertama adalah 'X'
        while (true) {
          System.out.print("Player " + currentPlayer + ": "); // Menunjukkan giliran pemain
          kordinat_x = input.nextInt(); // Input koordinat X
          kordinat_y = input.nextInt(); // Input koordinat Y

          // Memeriksa apakah langkah valid
          if (kordinat_x < 0 || kordinat_x > 2 || kordinat_y < 0 || kordinat_y > 2 || game.map[kordinat_x][kordinat_y] != '-') {
            System.out.println("Invalid move, try again."); // Jika tidak valid, cetak pesan
            continue;
          }

          game.map[kordinat_x][kordinat_y] = currentPlayer; // Memasukkan langkah ke dalam peta
          game.drawMap(); // Menggambar peta setelah pemain bergerak

          // Memeriksa apakah ada pemain yang menang
          if (game.checkWin(currentPlayer)) {
            System.out.println("Player " + currentPlayer + " wins!"); // Jika ada yang menang
            break; // Keluar dari loop
          }

          // Memeriksa apakah permainan seri
          if (game.isFull()) {
            System.out.println("The game is a draw!"); // Jika peta penuh dan tidak ada yang menang
            break; // Keluar dari loop
          }

          currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Ganti giliran pemain
        }
      }
    } while (choice != 0); // Mengulang permainan jika pemain memilih untuk bermain lagi
    input.close(); // Menutup scanner
  }
}