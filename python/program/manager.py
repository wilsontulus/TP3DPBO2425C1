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

# Deklarasi kelas objek #

class Manager(Penduduk):

    # constructor untuk inisialisasi atribut

    def __init__(self, nik, nama, nomorHP, kode, bidang, periode):
        super().__init__(nik, nama, nomorHP)
        self._kode = kode
        self._bidang = bidang
        self._periode = periode

    # Fungsi setter (write atribut)
    def setKode(self, kode: str) -> None:
        self._kode = str(kode)

    def setBidang(self, bidang: str) -> None:
        self._bidang = str(bidang)

    def setPeriode(self, periode: str) -> None:
        self._periode = str(periode)

    # Fungsi getter (read atribut)
    def getKode(self) -> str:
        return self._kode

    def getBidang(self) -> str:
        return self._bidang

    def getPeriode(self) -> str:
        return self._periode
