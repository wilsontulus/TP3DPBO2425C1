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

from penduduk import Penduduk
from manager import Manager

# Deklarasi kelas objek #

class Karyawan(Penduduk):

    # constructor untuk inisialisasi atribut

    def __init__(self, nik: str, nama: str, nomorHP: str, kode: str, status: str, bidang: str, manager: Manager) -> None:
        super().__init__(nik, nama, nomorHP)
        self._kode: str = kode
        self._status: str = status
        self._bidang: str = bidang
        self._manager: Manager = manager

    # Fungsi setter (write atribut)
    def setKode(self, kode: str) -> None:
        self._kode = str(kode)

    def setStatus(self, status: str) -> None:
        self._status = str(status)

    def setBidang(self, bidang: str) -> None:
        self._bidang = str(bidang)

    def setManager(self, manager: Manager) -> None:
        self._manager = manager

    # Fungsi getter (read atribut)
    def getKode(self) -> str:
        return self._kode

    def getStatus(self) -> str:
        return self._status

    def getBidang(self) -> str:
        return self._bidang

    def getManager(self) -> Manager:
        return self._manager
