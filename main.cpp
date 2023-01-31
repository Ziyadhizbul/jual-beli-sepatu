#include <iostream>
#include <vector>

using namespace std;

struct Sepatu{
  string merek;
  vector<string>model;
  vector<string> warna;
  vector<int> ukuran;
  vector<long> harga;
};

struct Keranjang{
  string merek;
  string model;
  string warna;
  int ukuran;
  long harga;
};

vector<Keranjang> keranjang;

vector<Sepatu> daftarSepatu{
  {
    "Adidas",
    {"Duramo", "Supernova", "Ultraboost"},
    {"Navy", "Hitam", "Putih"},
    {38, 40, 42},
    {900000, 1900000, 3300000},
  },
  {
    "Nike",
    {"Pegasus", "Zoom Rival", "Alphafly"},
    {"Navy", "Hitam", "Putih"},
    {38, 40, 42},
    {900000, 1900000, 3300000},
  },
};

void masukkanKeranjang(string merek, string model, string warna, int ukuran, long harga) {
  keranjang.push_back({merek, model, warna, ukuran, harga});
}

void tampilkanDetailSepatu(Sepatu sepatu) {
  int pilihNomorModel, pilihNomorWarna, pilihNomorUkuran;

  cout << "==== Sepatu Merek " << sepatu.merek << " ====\n\n";

  // model sepatu
  cout << "Daftar model sepatu :";
  for (int i = 0; i < sepatu.model.size(); i++) {
    cout << (i == 0 ? "\t" : "\t\t\t\t\t\t") << i + 1 << ". " << sepatu.model[i] << "\n";
  }

  cout << "Pilih model sepatu : ";
  cin >> pilihNomorModel;
  // model sepatu

  // warna sepatu
  cout << "Daftar warna sepatu :";
  for (int i = 0; i < sepatu.warna.size(); i++) {
    cout << (i == 0 ? "\t" : "\t\t\t\t\t\t") << i + 1 << ". " << sepatu.warna[i] << "\n";
  }

  cout << "Pilih warna sepatu : ";
  cin >> pilihNomorWarna;
  // warna sepatu

  // ukuran sepatu
  cout << "Daftar ukuran sepatu : ";
  for (int i = 0; i < sepatu.ukuran.size(); i++) {
    cout << (i == 0 ? "\t" : "\t\t\t\t\t\t") << i + 1 << ". " << sepatu.ukuran[i] << "\n";
  }

  cout << "Pilih ukuran sepatu : ";
  cin >> pilihNomorUkuran;
  // ukuran sepatu

  masukkanKeranjang(sepatu.merek, sepatu.model[pilihNomorModel - 1], sepatu.warna[pilihNomorWarna - 1], sepatu.ukuran[pilihNomorUkuran - 1], sepatu.harga[pilihNomorModel - 1]);
}

int main() {
  int pilihNomorMerek;
  char ulang;
  long totalHarga;

  do {
    cout << "================ Toko Sepatu ================\n";
    cout << "Keranjang : " << keranjang.size() << "\n\n";
    
    for (int i = 0; i < daftarSepatu.size(); i++) {
      cout << i + 1 << ". " << daftarSepatu[i].merek << "\n";
    }

    cout << "\nPilih merek sepatu (1 - " << daftarSepatu.size() << ") : ";
    cin >> pilihNomorMerek;

    system("cls");

    tampilkanDetailSepatu(daftarSepatu[pilihNomorMerek - 1]);


    cout << "\n\nApakah ingin membeli sepatu yang lain? (y/t) : ";
    cin >> ulang;

    system("cls");
  } while (ulang == 'y');

  cout << "==== Keranjang Belanja ====\n\n";
  for (int i = 0; i < keranjang.size(); i++) {
    cout << i + 1 << ". " << keranjang[i].model << " (" << keranjang[i].merek << " | " << keranjang[i].warna << " | " << keranjang[i].ukuran << ") - Rp " << keranjang[i].harga << "\n";
  }

  cout << "\nTotal harga : Rp ";
  for (int i = 0; i < keranjang.size(); i++) {
    totalHarga = keranjang[i].harga + totalHarga;
  }

  cout << totalHarga;
}