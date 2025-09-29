/*
 * LICENSE: All Rights Reserved
 * (c) 2025 Willsoon Tulus P. Simanjuntak
 * (c) 2025 Universitas Pendidikan Indonesia
 *
 * Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
 * Tugas Praktikum 3 dalam mata kuliah Desain Pemrograman
 * Berorientasi Objek untuk keberkahanNya maka saya tidak
 * melakukan kecurangan seperti yang telah dispesifikasikan.
 * Aamiin.
 */

/* Deklarasi header custom */
#include "header.hpp"

/* Deklarasi kelas */

// Deklarasi konstruktor awal untuk inisialisasi
Karyawan::Karyawan() {
    this->status = "";
    this->bidang = "";
};

// Konstruktor untuk membuat objek baru oleh fungsi luar
Karyawan::Karyawan(string nik, string nama, string nomorHP, string status, string bidang, Manager manager) 
                : Penduduk(nik, nama, nomorHP) 
{
    this->status = status;
    this->bidang = bidang;
    this->manager = manager;
};

// Fungsi setter untuk menentukan bidang karyawan
void Karyawan::setBidang(string bidang) {
    this->bidang = bidang;
};

// Fungsi setter untuk menentukan manajer karyawan
void Karyawan::setManager(Manager manager) {
    this->manager = manager;
};
// Fungsi getter untuk mendapatkan status karyawan
string Karyawan::getStatus() {
    return this->status;
};

// Fungsi getter untuk mendapatkan bidang karyawan
string Karyawan::getBidang() {
    return this->bidang;
};

// Fungsi getter untuk mendapatkan manager dari karyawan
Manager Karyawan::getManager() {
    return this->manager;
};

// Deklarasi destruktor
Karyawan::~Karyawan() {};
