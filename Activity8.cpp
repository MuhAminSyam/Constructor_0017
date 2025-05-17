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
