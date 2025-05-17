// Class Mahasiswa menyimpan informasi seperti nama, NIM, dan nilai.
// Atribut nilai bersifat privat dan tidak boleh diubah langsung oleh objek lain, kecuali oleh dosen yang mengajar.
// Oleh karena itu, class Dosen harus dideklarasikan sebagai friend class dari Mahasiswa,
// sehingga dosen dapat mengakses dan memberikan nilai menggunakan method seperti beriNilai(Mahasiswa* m, float nilai).

// Class Dosen menyimpan atribut pribadi seperti nama, NIDN, pangkat, dan gaji, dengan gaji bersifat privat.
// Pangkat dosen hanya dapat diubah oleh Staff, sehingga class Staff harus dijadikan friend class oleh Dosen.
// Namun, berbeda dari akses gaji, pihak Universitas tidak dijadikan friend class secara langsung,
// melainkan hanya dapat mengakses informasi gaji dosen melalui sebuah fungsi friend yang dideklarasikan secara eksplisit di dalam class Dosen.
// Fungsi tersebut akan menerima objek Dosen* sebagai argumen dan dideklarasikan sebagai friend dari class Dosen,
// tetapi didefinisikan di luar sebagai bagian dari class Universitas.

// Class Staff menyimpan informasi seperti nama, ID staff, dan gaji, dengan gaji bersifat privat.
// Staff memiliki kemampuan untuk mengubah pangkat dosen melalui pointer menggunakan method ubahPangkat(Dosen* d, string pangkatBaru).
// Sama seperti dosen, data gaji staff tidak bisa diakses langsung oleh class Universitas,
// tetapi disediakan melalui sebuah fungsi friend bernama lihatGajiStaff(Staff* s) yang dideklarasikan sebagai friend dalam class Staff, dan diimplementasikan dalam class Universitas.

#include <iostream> // Untuk input-output
#include <string>   // Untuk penggunaan tipe data string
using namespace std;

// Forward declaration untuk menghindari error referensi silang
class Mahasiswa;
class Dosen;
class Staff;
class Universitas;

// Class Mahasiswa
class Mahasiswa
{
private:
    string nama; // Nama mahasiswa
    string NIM;  // NIM mahasiswa
    float nilai; // Nilai mahasiswa (bersifat private)

public:
    // Constructor untuk inisialisasi nama dan NIM
    Mahasiswa(string nama, string NIM)
    {
        this->nama = nama;
        this->NIM = NIM;
        this->nilai = 0; // Default nilai = 0
    }

    // Fungsi untuk menampilkan informasi mahasiswa
    void tampilkanInfo()
    {
        cout << "Mahasiswa: " << nama << " | NIM: " << NIM << " | Nilai: " << nilai << endl;
    }

    // Menjadikan class Dosen sebagai friend agar bisa mengubah nilai
    friend class Dosen;
};

// =======================
// Class Dosen
// =======================
class Dosen
{
private:
    string nama;    // Nama dosen
    string NIDN;    // Nomor induk dosen nasional
    string pangkat; // Pangkat dosen
    float gaji;     // Gaji dosen

public:
    // Constructor untuk inisialisasi dosen
    Dosen(string nama, string NIDN, string pangkat, float gaji)
    {
        this->nama = nama;
        this->NIDN = NIDN;
        this->pangkat = pangkat;
        this->gaji = gaji;
    }

    // Fungsi untuk memberi nilai ke mahasiswa (mengakses nilai secara langsung)
    void beriNilai(Mahasiswa *m, float nilai)
    {
        m->nilai = nilai; // karena class ini friend, bisa akses langsung nilai
    }

    // Fungsi untuk menampilkan informasi dosen
    void tampilkanInfo()
    {
        cout << "Dosen: " << nama << " | NIDN: " << NIDN << " | Pangkat: " << pangkat << endl;
    }

    // Menjadikan Staff sebagai friend agar bisa ubah pangkat
    friend class Staff;

    // Menjadikan fungsi aksesGaji sebagai friend agar bisa akses gaji
    friend float aksesGaji(Dosen *d);
};

// Fungsi friend untuk mengakses gaji dosen
float aksesGaji(Dosen *d)
{
    return d->gaji;
}

// =======================
// Class Staff
// =======================
class Staff
{
private:
    string nama; // Nama staff
    int IDStaff; // ID staff
    float gaji;  // Gaji staff

public:
    // Constructor untuk inisialisasi staff
    Staff(string nama, int IDStaff, float gaji)
    {
        this->nama = nama;
        this->IDStaff = IDStaff;
        this->gaji = gaji;
    }

    // Fungsi untuk mengubah pangkat dosen (pakai pointer)
    void ubahPangkat(Dosen *d, string pangkatBaru)
    {
        d->pangkat = pangkatBaru;
    }

    // Menampilkan informasi staff
    void tampilkanInfo()
    {
        cout << "Staff: " << nama << " | ID: " << IDStaff << endl;
    }

    // Menjadikan fungsi lihatGajiStaff sebagai friend agar bisa akses gaji
    friend float lihatGajiStaff(Staff *s);
};

// Fungsi friend untuk mengakses gaji staff
float lihatGajiStaff(Staff *s)
{
    return s->gaji;
}

// =======================
// Class Universitas
// =======================
class Universitas
{
public:
    // Fungsi untuk menampilkan gaji dosen (lewat fungsi friend)
    void infoGajiDosen(Dosen *d)
    {
        cout << "Gaji Dosen: " << aksesGaji(d) << endl;
    }

    // Fungsi untuk menampilkan gaji staff (lewat fungsi friend)
    void infoGajiStaff(Staff *s)
    {
        cout << "Gaji Staff: " << lihatGajiStaff(s) << endl;
    }
};

// =======================
// Fungsi Utama (main)
// =======================
int main()
{
    // Membuat objek Mahasiswa
    Mahasiswa m1("Amin", "2023012345");

    // Membuat objek Dosen
    Dosen d1("Pak Budi", "001122", "Lektor", 12000000);

    // Membuat objek Staff
    Staff s1("Bu Rina", 1001, 8000000);

    // Membuat objek Universitas
    Universitas u;

    // Dosen memberi nilai ke mahasiswa
    d1.beriNilai(&m1, 88.5);

    // Menampilkan info mahasiswa setelah diberi nilai
    m1.tampilkanInfo();

    // Staff mengubah pangkat dosen
    s1.ubahPangkat(&d1, "Guru Besar");

    // Menampilkan info dosen setelah diubah pangkat
    d1.tampilkanInfo();

    // Universitas mengakses dan menampilkan gaji dosen
    u.infoGajiDosen(&d1);

    // Universitas mengakses dan menampilkan gaji staff
    u.infoGajiStaff(&s1);

    return 0;
}

// activity 9
// chainfunction
#include <iostream>  // Library input/output
using namespace std; // Menggunakan namespace std

class buku // Deklarasi class buku
{
    string judul;

public: // Bagian public
    buku setJudul(string judul)
    {
        this->judul = judul;
        return *this;
    }
    string getJudul()
    {
        return this->judul;
    }
} bukunya;

int main() // Fungsi utama program
{
    // bukunya.setJudul("Matematika");
    // cout << bukunya.getJudul();
    cout << bukunya.setJudul("Matematika").getJudul();
    return 0;
}

// activity 9
// destruktor
#include <iostream>  // library input/output
using namespace std; // menggunakan namespace std

class angka
{ // deklarasi class angka
private:
    int *arr;
    int panjang;

public:
    angka(int);       // konstruktor
    ~angka();         // destruktor
    void cetakData(); // fungsi untuk cetak data
    void isiData();   // fungsi untuk input data
};

// implementasi fungsi anggota
angka::angka(int i)
{ // konstruktor
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka()
{ // destruktor
    cout << endl;
    cetakData();
    delete[] arr;
    cout << "Alamat Array Sudah Dilepaskan" << endl;
}
