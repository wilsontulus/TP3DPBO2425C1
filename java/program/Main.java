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

/* Deklarasi library */

import java.util.ArrayList;
import java.util.Scanner;

/* Deklarasi "kelas" fungsi utama */

public class Main {
    public static void main(String[] args) {


        /* Deklarasi variabel angka pilihan menu */
        int choiceNum = -1;

        /* Deklarasi objek untuk input CLI */
        Scanner input = new Scanner(System.in);

        // Tampilkan menu hingga angka 0
        while (choiceNum != 0)
        {
            System.out.println("Menu Pilihan: ");
            System.out.println("1. Tambah item");
            System.out.println("2. Tampilkan List");
            System.out.println("0. Keluar dari program");

            // Minta masukan input pilihan, dengan error handling jika bukan bilangan integer
            try {
                System.out.printf("Masukkan pilihan: ");
                choiceNum = input.nextInt();
                input.nextLine();
            } catch (Exception errorMsg) {
                System.out.println("Masukan harus berupa angka.");
                input.nextLine();
                continue;
            }

            switch(choiceNum) {
                case 1: // Tambah data baru.

                    break;
                case 2: // Tampilkan list

                    break;
                case 0: // Sambutan keluar program
                    System.out.println("Program selesai digunakan.");
                    break;
                default: // Peringatkan jika diluar pilihan
                    System.out.println("Masukan harus sesuai dengan menu yang ditentukan (0-2).");
                    break;
            }
        }

        /* Selesai */
        input.close();
    }
}
