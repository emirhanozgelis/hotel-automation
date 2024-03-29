#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int menuYazdir();

class Oda
{
public:
	int odaNumarasi;
	int odaUcreti;

	void odaEkle()
	{
		char secim;

		ofstream odaEkleme("odalar.txt", ios::app);

		cout << "Lutfen oda numarasini giriniz..: ";
		cin >> odaNumarasi;

		cout << "Lutfen oda ucretini giriniz..: ";
		cin >> odaUcreti;

		odaEkleme << odaNumarasi << "    " << odaUcreti << endl;
		odaEkleme.close();

		cout << "Oda eklemeye devam etmek icin e, Bir Ust Menuye Gitmek icin h tusuna basiniz..." << endl;
		cin >> secim;

		switch (secim)
		{
		case 'e':
		case 'E':
		{
			return odaEkle();
			break;
		}
		case 'H':
		case 'h':
		{
			odaMenu();
			break;
		}
		default:
			cout << "Hatali Secim";
			break;
		}
	}
	void odaSil()
	{
		odalariListele();
		int arananOda = 0;
		cout << "Silinecek oda numarasi ";
		cin >> arananOda;
		ifstream odaOku("odalar.txt");
		ofstream odaYaz("odalar.tmp");

		while (odaOku >> odaNumarasi >> odaUcreti)
		{

			if (arananOda == odaNumarasi)
			{

			}
			else
			{
				odaYaz << "Oda Numarasi :" << odaNumarasi << " " << "Oda Ucreti :" << odaUcreti << endl;


			}
		}
		odaYaz.close();
		odaOku.close();
		remove("odalar.txt");
		rename("odalar.tmp", "odalar.txt");
		odalariListele();
	}
	void odalariListele()
	{
		ifstream odaListeleme;
		string temp;

		odaListeleme.open("odalar.txt");

		while (odaListeleme >> odaNumarasi >> odaUcreti)
		{
			cout << "Oda Numarasi : " << odaNumarasi << "Oda Ucreti : " << odaUcreti << endl;
			cout << endl;
		}
		odaListeleme.close();
	}

	void odaMenu()
	{
		system("cls");
		int secim;
		cout << "Oda Islemleri" << endl;
		cout << "------------------" << endl;
		cout << "1-Oda Ekle" << endl;
		cout << "2-Oda Sil" << endl;
		cout << "3-Odalari Listele" << endl;
		cout << "99-Ust Menu" << endl;

		cout << "Seciminiz :";
		cin >> secim;
		if (secim == 1)
		{

			odaEkle();
		}
		else if (secim == 2)
		{
			odaSil();
		}
		else if (secim == 3)
		{
			odalariListele();
		}
		else if (secim == 99)
		{
			menuYazdir();
		}
		else
			cout << "Hatali Secim";

	}


};

class Musteri
{
public:
	int musteriNumarasi;
	string musteriAdi;
	string musteriSoyadi;
	int musteriTCNo;

	void musteriEkle()
	{
		char secim;

		ofstream musteriEkleme("musteriler.txt", ios::app);

		cout << "Lutfen musteri numarasini giriniz..: ";
		cin >> musteriNumarasi;

		cout << "Lutfen musteri adini giriniz..: ";
		cin >> musteriAdi;

		cout << "Lutfen musteri soyadini giriniz..: ";
		cin >> musteriSoyadi;

		cout << "Lutfen musteri TC No giriniz..: ";
		cin >> musteriTCNo;

		musteriEkleme << musteriNumarasi << "    " << musteriAdi << "   " << musteriSoyadi << "  " << musteriTCNo << endl;
		musteriEkleme.close();

		cout << "Musteri eklemeye devam etmek icin e, Bir Ust Menuye Gitmek icin h tusuna basiniz..." << endl;
		cin >> secim;

		switch (secim)
		{
		case 'e':
		case 'E':
		{
			return musteriEkle();
			break;
		}
		case 'H':
		case 'h':
		{
			musteriMenu();
			break;
		}
		default:
			cout << "Hatali Secim";
			break;
		}
	}
	void musteriSil()
	{
		musteriListele();

		int arananMusteriNo = 0;
		cout << "Silinecek musteri numarasi ";
		cin >> arananMusteriNo;
		ifstream musteriOku("musteriler.txt");
		ofstream musteriYaz("musteriler.tmp");

		while (musteriOku >> musteriNumarasi >> musteriAdi >> musteriSoyadi >> musteriTCNo)
		{

			if (arananMusteriNo == musteriNumarasi)
			{

			}
			else
			{
				musteriYaz << musteriNumarasi << " " << musteriAdi << " " << musteriSoyadi << " " << musteriTCNo << endl;
			}
		}
		musteriYaz.close();
		musteriOku.close();

		remove("musteriler.txt");
		rename("musteriler.tmp", "musteriler.txt");
		musteriListele();

	}

	void musteriListele()
	{

		ifstream musteriListeleme;
		string temp;

		musteriListeleme.open("musteriler.txt");

		while (getline(musteriListeleme, temp))
		{
			cout << temp << endl;
			cout << endl;
		}
		musteriListeleme.close();
	}
	void musteriMenu()
	{
		system("cls");
		int secim;
		cout << "Musteri Islemleri" << endl;
		cout << "------------------" << endl;
		cout << "1-Musteri Ekle" << endl;
		cout << "2-Musteri Sil" << endl;
		cout << "3-Musteri Listele" << endl;
		cout << "99-Ust Menu" << endl;

		cout << "Seciminiz :";
		cin >> secim;

		switch (secim)
		{
		case 1:
		{
			musteriEkle();
			break;
		}
		case 2:
		{
			musteriSil();
			break;
		}
		case 3:
		{
			musteriListele();
			break;
		}
		case 99:
		{
			menuYazdir();
			break;
		}
		default:
			cout << "Hatali Secim";
			break;
		}
	}

};

class odaKayit
{
	Musteri musteri1;
	Oda oda1;
	void odaKayitEkle()
	{

		musteri1.musteriListele();
		cout << "Kayit edilecek musterinin numarasini giriniz..: ";
	}

	void odaKayitSil()
	{

	}
	void odaKayitListele()
	{

	}
	void odaKayitMenu()
	{
		system("cls");
		int secim;
		cout << "Oda Kayit Islemleri" << endl;
		cout << "------------------" << endl;
		cout << "1-Oda Kayit Ekle" << endl;
		cout << "2-Oda Kayit Sil" << endl;
		cout << "3-Oda Kayit Listele" << endl;
		cout << "99-Ust Menu" << endl;

		cout << "Seciminiz :";
		cin >> secim;

		switch (secim)
		{
		case 1:
		{
			odaKayitEkle();
			break;
		}
		case 2:
		{
			odaKayitSil();
			break;
		}
		case 3:
		{
			odaKayitListele();
			break;
		}
		case 99:
		{
			menuYazdir();
			break;
		}
		default:
			cout << "Hatali Secim";
			break;
		}
	}
};
int menuYazdir()
{
	Musteri musteri;
	Oda oda;
	odaKayit kayit;
	system("cls");
	int secim;
	cout << "Oda Kayit Islemleri" << endl;
	cout << "------------------" << endl;
	cout << "1-Oda Islemleri" << endl;
	cout << "2-Musteri Islemleri" << endl;
	cout << "3-Oda Kayit Islemleri" << endl;
	cout << "99-Cikis" << endl;

	cout << "Seciminiz :";
	cin >> secim;


	switch (secim)
	{
	case 1:
	{
		system("cls");
		oda.odaMenu();
		break;
	}
	case 2:
	{
		system("cls");
		musteri.musteriMenu();
		break;
	}
	case 3:
	{
		system("cls");
		kayit.kayitAta();
		break;
	}
	default:
	{
		system("cls");
		cout << "Hatali Secim";
		menuYazdir();
	}
	}
	return 0;
}
int main()
{
	menuYazdir();


	return 0;
}



