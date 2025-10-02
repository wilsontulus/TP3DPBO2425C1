# LICENSE: All Rights Reserved
# (c) 2025 Willsoon Tulus P. Simanjuntak
# (c) 2025 Universitas Pendidikan Indonesia
#
# Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
# Tugas Praktikum 3 dalam mata kuliah Desain Pemrograman
# Berorientasi Objek untuk keberkahanNya maka saya tidak
# melakukan kecurangan seperti yang telah dispesifikasikan.
# Aamiin.

# Deklarasi kelas objek #

class Aset:

    # constructor untuk inisialisasi atribut

    def __init__(self, kode: str, nama: str, jenis: str, jumlah: int) -> None:
        self._kode: str = kode
        self._nama: str = nama
        self._jenis: str = jenis
        self._jumlah: int = jumlah

    # Fungsi setter (write atribut)
    def setKode(self, kode: str) -> None:
        self._kode = str(kode)

    def setNama(self, nama: str) -> None:
        self._nama = str(nama)

    def setJenis(self, jenis: str) -> None:
        self._jenis = str(jenis)

    def setJumlah(self, jumlah: int) -> None:
        self._jumlah = int(jumlah)

    # Fungsi getter (read atribut)
    def getKode(self) -> str:
        return self._kode

    def getNama(self) -> str:
        return self._nama

    def getJenis(self) -> str:
        return self._jenis

    def getJumlah(self) -> int:
        return self._jumlah
