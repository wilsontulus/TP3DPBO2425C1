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

class Penduduk:

    # constructor untuk inisialisasi atribut

    def __init__(self, nik: str, nama: str, nomorHP: str) -> None:
        self._nik: str = nik
        self._nama: str = nama
        self._nomorHP: str = nomorHP

    # Fungsi setter (write atribut)
    def setNik(self, nik: str) -> None:
        self._nik = str(nik)

    def setNama(self, nama: str) -> None:
        self._nama = str(nama)

    def setNomorHP(self, nomorHP: str) -> None:
        self._nomorHP = str(nomorHP)

    # Fungsi getter (read atribut)
    def getNik(self) -> str:
        return self._nik

    def getNama(self) -> str:
        return self._nama

    def getNomorHP(self) -> str:
        return self._nomorHP
