# LICENSE: All Rights Reserved
# (c) 2025 Willsoon Tulus P. Simanjuntak
# (c) 2025 Universitas Pendidikan Indonesia
#
# Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
# Tugas Praktikum 3 dalam mata kuliah Desain Pemrograman
# Berorientasi Objek untuk keberkahanNya maka saya tidak
# melakukan kecurangan seperti yang telah dispesifikasikan.
# Aamiin.

# Deklarasi dependency #

from manager import Manager
from karyawan import Karyawan
from aset import Aset
from proyek import Proyek

# Deklarasi kelas objek #

class Kantor:

    # constructor untuk inisialisasi atribut

    def __init__(self, kode, nama, lokasi) -> None:
        self._kode: str = kode
        self._nama: str = nama
        self._lokasi: str = lokasi
        self._manager: list[Manager] = []
        self._karyawan: list[Karyawan] = []
        self._proyek: list[Proyek] = []
        self._aset: list[Aset] = []

    # Fungsi setter (write atribut)
    def setKode(self, kode: str) -> None:
        self._kode = str(kode)

    def setNama(self, nama: str) -> None:
        self._nama = str(nama)

    def setLokasi(self, lokasi: str) -> None:
        self._lokasi = str(lokasi)

    # Fungsi adder (write to list)
    def addManager(self, manager: Manager) -> None:
        self._manager.append(manager)

    def addKaryawan(self, karyawan: Karyawan) -> None:
        self._karyawan.append(karyawan)

    def addProyek(self, proyek: Proyek) -> None:
        self._proyek.append(proyek)

    def addAset(self, aset: Aset) -> None:
        self._aset.append(aset)

    # Fungsi getter (read atribut)
    def getKode(self) -> str:
        return self._kode

    def getNama(self) -> str:
        return self._nama

    def getLokasi(self) -> str:
        return self._lokasi

    def getManager(self) -> list[Manager]:
        return self._manager

    def getKaryawan(self) -> list[Karyawan]:
        return self._karyawan

    def getProyek(self) -> list[Proyek]:
        return self._proyek

    def getAset(self) -> list[Aset]:
        return self._aset
