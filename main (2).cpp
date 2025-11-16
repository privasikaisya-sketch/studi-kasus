#include <iostream>
using namespace std;

// Struct untuk barang
struct Barang
{
    string nama;
    int harga;
};

// Fungsi menghitung total harga
int hitungTotal(int harga, int jumlah)
{
    return harga * jumlah;
}

// fungsi menghitung diskon berdasarkan total belanja (fungsi yang baru ditambahkan)
double HitungDiskon(int totalBelanja)
{
    if (totalBelanja >= 70000)
        return totalBelanja * 0.2; // Diskon 20% untuk belanja di atas 50.000
    else if (totalBelanja >= 50000)
        return totalBelanja * 0.1; // Diskon 10% untuk belanja di atas 40.000
    else if (totalBelanja >= 30000)
        return totalBelanja * 0.05; // Diskon 5% untuk belanja di atas 30.000
    else
        return 0; // Tidak ada diskon
}

int main()
{
    // nama menu yang ditambahkan : Air mineral, Mie Goreng, dan Telor Dadar
    Barang daftar[6] = {{"Ayam Geprek", 10000}, {"Teh Manis", 4000}, {"Nasi", 3000}, { "Air mineral" , 3000}, {"Mie Goreng", 3500}, {"Telor Dadar", 6000}};
    int totalKeseluruhan = 0;
    char lanjut;

    do
    {
        cout << "\n\n"; // Jarak tambahan antar looping

        // Tampilkan menu
        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << ". " << daftar[i].nama << " - Rp." << daftar[i].harga << endl;
        }

        cout << "\n"; // Jarak tambahan

        int pilih, jumlah;
        cout << "Pilih menu (1-6): ";
        cin >> pilih;
        cout << "Jumlah: ";
        cin >> jumlah;

        int total = hitungTotal(daftar[pilih - 1].harga, jumlah);
        totalKeseluruhan += total;

        cout << "Total " << daftar[pilih - 1].nama << " = Rp." << total << endl;

        cout << "Pesan lagi? (y/n): ";
        cin >> lanjut;

        cout << "\n\n"; // Jarak tambahan

    } while (lanjut == 'y' || lanjut == 'Y');

    // Tampilan untuk diskon yang didapat (baru ditambahkan)
    double diskon = HitungDiskon(totalKeseluruhan);
    cout << "\nDiskon yang didapat: Rp. " << diskon << endl;

    // Menghitung total keseluruhan setelah diskon (baru ditambahkan)
    totalKeseluruhan = totalKeseluruhan - diskon;

    // Tampilkan total keseluruhan setelah di diskon )(baru ditambahkan)
    cout << "\nTotal yang perlu dibayar: Rp." << totalKeseluruhan << endl;

    // Pesan penutup berdasarkan total keseluruhan dari pemesanan (ini juga yang baru ditambahkan)
    if (totalKeseluruhan > 100000){
        cout << "Beuh makasih banyak bang, sumpah lo baik banget, semoga lo sehat sehat terus bang, rezeki lo dimudahkan, keinginan lu juga semoga terwujud, dateng lagi ya jangan lupa!";
    } else if (totalKeseluruhan == 100000){
        cout << "Terima Kasih telah berbelanja disini, semoga hari anda menyenangkan, dan dipenuhi dengan kebahagiaan!";
    } else if (totalKeseluruhan >= 60000){
        cout << "Terima Kasih telah belanja di sini, semoga hari anda menyenangkan!";
    } else if (totalKeseluruhan >= 40000){
        cout << "Terima kasih"; 
    } else {
        cout << "ok bang";
    }

    return 0;
}