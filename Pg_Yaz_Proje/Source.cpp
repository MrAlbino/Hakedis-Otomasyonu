/****************************************************************************
**							SAKARYA �N�VERS�TES�
**					B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**						B�LG�SAYAR M�HEND�SL��� B�L�M�
**							PROGRAMLAMAYA G�R��� DERS�
**
**						�DEV NUMARASI : 1.Proje
**						��RENC� ADI : Ayberk K�SE
**						��RENC� NUMARASI : B181210001
**						DERS GRUBU : 1/A
****************************************************************************/

//sat�r sonu ignore lamak i�in tan�mlad�m
#define NOMINMAX

#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include<iomanip>
#include<ctime>
#include<limits>
#include<cstdlib>

using namespace std;

char cevap = 'e';	
char projeCevap = 'e';
char _cevap;
// Urunler.txt dosyas�nda yer alancak alanlar
double toplamFiyat = 0;
int i = 1;
string secim, secim1;
int urunNo;
string urunAdi;
string birim;
float birimFiyati;
string marka;

//Projeler.txt dosyas�nda yer alacak alanlar
int projeNo;
string projeAdi;
string projeYurutucuFirma;
string projeSorumlusu;
string projeKontroloru;

//Hakedi�.txt dosyas�nda yer alacak alanlar
string hakedisTarihi;

//fonksiyon g�vdeleri main in alt�nda oldu�u i�in burada fonksiyon imzas� at�yoruz.
void anaMenuyuGoster();
void urunMenusunuGoster();
void urunEkle();
void urunSil();
void urunAra();
void urunRaporla();
void projeMenusunuGoster();
void projeEkle();
void projeSilme();
void projeArama();
void projeRaporlama();
void hakedisMenusunuGoster();
void hakedisVer();
void hakediseUrunEkle();
void hakedistenUrunSil();
void hakedisUrunGuncelle();
void hakedisUrunListele();
void hakedisUrunAra();
void hakedisDonemRaporla();

int main(int argc, char *argv[])
{
	do
	{

		anaMenuyuGoster();

		cin >> secim;

		if (secim == "1") //kullan�c�n�n 1 e basma durumu
		{

			do {

				urunMenusunuGoster();
	
				cin >> secim1;

				if (secim1 == "1") {

					urunEkle();
				}
				if (secim1 == "2") {
					urunSil();
				}
				if (secim1 == "3") {

					urunAra();
				}
				if (secim1 == "4") {
					urunRaporla();
				}
				if (secim1 == "5") {
					break;
				}
			} while ((secim1 != "1" && secim1 != "2" && secim1 != "3" && secim1 != "4") || secim1 != "5");
			//secim1 5 olmad��� s�rece men�den ��km�yor.

		}
		if (secim == "2") { //kullan�c�n�n 2 yi se�me durumu
			do {
				projeMenusunuGoster();

				cin >> secim1;

				if (secim1 == "1") {
					projeEkle();
				}
				if (secim1 == "2") {
					projeSilme();
				}
				if (secim1 == "3") {

					projeArama();
				}
				if (secim1 == "4") {
					projeRaporlama();
				}
				if (secim1 == "5") {
					break;
				}
			} while ((secim1 != "1" && secim1 != "2" && secim1 != "3" && secim1 != "4") || secim1 != "5"); //secim1 5 olana kadar men�de kal�yor
		}
		if (secim == "3") { //kullan�c�n�n 3 �nc� se�ene�i se�me durumu
			
			string _hakedisSecim;

			do {
				hakedisMenusunuGoster();

				cin >> _hakedisSecim;

				if (_hakedisSecim == "1") {

					hakedisVer();

				}
				if (_hakedisSecim == "2") {

					hakediseUrunEkle();
				}

				if (_hakedisSecim == "3") {

					hakedistenUrunSil();

				}
				if (_hakedisSecim == "4") {
					hakedisUrunGuncelle();
				}
				if (_hakedisSecim == "5") {

					hakedisUrunListele();
				}
				if (_hakedisSecim == "6") {

					hakedisUrunAra();
				}

				if (_hakedisSecim == "7") {

					hakedisDonemRaporla();
				}

				if (_hakedisSecim == "8") {
					break;
				}

			} while ((_hakedisSecim != "1" && _hakedisSecim != "2"&& _hakedisSecim != "3"&& _hakedisSecim != "4"&& _hakedisSecim != "5"&& _hakedisSecim != "6"&& _hakedisSecim != "7"&& _hakedisSecim != "8")||_hakedisSecim!="8");
		}
	} while ((secim != "1" && secim != "2" && secim != "3" && secim != "4") || secim != "4"); //kullan�c� 4 e basana kadar program devam ediyor

	system("PAUSE");
	return EXIT_SUCCESS;
}
void anaMenuyuGoster() { //ana men� se�eneklerini ekrana yazd�ran fonksiyon
	cout << " Ne yapmak istiyorsunuz ? " << endl;
	cout << " 1) Urun Islemleri " << endl;
	cout << " 2) Proje Islemleri " << endl;
	cout << " 3) Hakedis Islemleri" << endl;
	cout << " 4) Programdan Cikis" << endl;
}
void urunMenusunuGoster() { // �r�nlerle ilgili se�enekleri ekrana yazd�ran fonksiyon
	cout << " 1) Urun Ekleme" << endl;
	cout << " 2) Urun Silme" << endl;
	cout << " 3) Urun Arama" << endl;
	cout << " 4) Urun Raporlama" << endl;
	cout << " 5) Menuden Cik" << endl;
}
void urunEkle() {
	ofstream DosyaYaz;

	int _urunNumara;

	do
	{
		cout << "Urun No: "; //kullan�c�dan eklenecek �r�n numaras� isteniyor.
		cin >> _urunNumara;

		DosyaYaz.open("Urunler.txt", ios::app);
		ifstream DosyaOkuma("Urunler.txt");
		while (true) { //kullan�c�n�n girdi�i numara ba�ka �r�ne ait mi kontrol�
			DosyaOkuma >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

			if (DosyaOkuma.eof()) {//dosya sonu okundu�unda d�ng�den ��kma komutu.
				break;
			}

			while (urunNo == _urunNumara) {//e�er ayn� numaraya sahip ba�ka �r�n varsa hata veriyor. Ve yeni numara girmesi isteniyor.
				cout << "Bu Urun No Baska Urune Ait !!" << endl;
				cout << "Urun No: ";
				cin >> _urunNumara;
				//yeni numaray� girdikten sonra okuma i�lemi ba�a g�nderiliyor ve dosya ba�tan kontrol ediliyor. Yeni �r�n no ba�ka �r�ne aitse yine hata versin diye.
				DosyaOkuma.clear();
				DosyaOkuma.seekg(ios::beg);
			}

		}
		urunNo = _urunNumara;
		cout << "\n Urun Adi :"; cin >> urunAdi; // �r�n�n di�er bilgileri kullan�c�dan isteniyor.
		cout << "\n Birim :"; cin >> birim;
		cout << "\n Birim Fiyati :"; cin >> birimFiyati;
		cout << "\n Markasi :"; cin >> marka;
		//kullan�c�dan al�nan bilgiler dosyaya yaz�l�yor.
		DosyaYaz << urunNo << " " << urunAdi << ' ' << birim << ' ' << birimFiyati << ' ' << marka << ' ' << "\n";
		DosyaYaz.close();
		cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
	} while (!(cevap == 'h')); //cevap h olmad��� s�rece kay�t i�lemi tekrarlan�yor

	cout << "Dosyaya yazim tamamlandi. " << endl;
}
void urunSil() {
	int _urunNo;
	char cevap2 = 'e';
	while (cevap2 == 'e') { // cevap e oldu�u s�rece tekrarlanan d�ng�
		cout << " Silinecek Urun No :"; cin >> _urunNo; // kullan�c�dan silinecek �r�n numaras� isteniyor.

		ifstream DosyaOku("Urunler.txt");
		ofstream DosyaYaz("temp.txt"); //silme i�lemini �r�nleri yeni bir dosyaya yazarak yapaca��m�z i�in temp.txt dosyas� a��yoruz.
		while (true)
		{
			DosyaOku >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

			if (DosyaOku.eof()) break;//dosya sonu okundu�unda d�ng�den ��kma komutu.

			if (urunNo == _urunNo) //e�er silinecek �r�n no bulunursa continue diyerek yazma i�lemini atl�yoruz.
			{
				continue; //bu sayede silinecek �r�n temp.txt ye yaz�lm�yor.
			}
			DosyaYaz << urunNo << " " << urunAdi << " " << birim << " " << birimFiyati << " " << marka << "\n";

		}
		cout << "Baska Urun Silinecek Mi? (e/h)" << endl;
		cin >> cevap2;
		DosyaOku.close();
		DosyaYaz.close();
		remove("Urunler.txt"); //eski dosya siliniyor.
		rename("temp.txt", "Urunler.txt"); //temp.txt Urunler.txt olarak adland�r�l�yor b�ylece i�lem tamamlan�yor.
	}
}
void urunAra() {
	int urunNoAra;

	bool bulunduMu = false;

	char cevap1 = 'e';

	while (cevap1 == 'e') { //kullan�c�n�n cevab� e oldu�u s�rece devam edecek i�lemler

		cout << " Urun No :"; cin >> urunNoAra; //aranacak �r�n no isteniyor.

		bulunduMu = false;

		ifstream DosyaOku("Urunler.txt");

		while (true)
		{
			DosyaOku >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

			if (DosyaOku.eof()) break;//dosya sonu okundu�unda d�ng�den ��kma komutu.

			if (urunNo == urunNoAra) // kullan�c�n�n girdi�i �r�n no dosyada bulunursa bulunduMu de�i�keni true yap�l�yor.
			{
				bulunduMu = true;
				break;
			}

		}
		if (bulunduMu) //bulunduysa �r�n�n bilgileri ekrana yazd�r�l�yor.
		{
			cout << "\n Urun Bilgileri \n";
			cout << " Urun No :" << urunNoAra << endl;
			cout << " Urun Adi :" << urunAdi << endl;
			cout << " Birim :" << birim << endl;
			cout << " Birim Fiyati :" << birimFiyati << endl;
			cout << " Marka :" << marka << endl;
			cout << " Baska Urun Sorgulanacak Mi? (e/h)" << endl;
			cin >> cevap1; //kullan�c�dan ba�ka �r�n sorgulay�p sorgulamayaca�� bilgisi isteniyor
		}
		else { //�r�n�n bulunamad��� durum
			cout << " Urun Bulunamadi" << endl;
			cout << " Baska Urun Sorgulanacak Mi? (e/h)" << endl;
			cin >> cevap1; //kullan�c�dan ba�ka �r�n sorgulay�p sorgulamayaca�� bilgisi isteniyor
		}
		DosyaOku.close();
	}

}
void urunRaporla() { //dosyadaki t�m �r�nleri ve bilgilerini yazd�ran fonksiyon
	ifstream DosyaOku("Urunler.txt");
	cout << "\n Urun Bilgileri \n";
	while (true) //s�rekli �al��an d�ng�
	{
		DosyaOku >> urunNo >> urunAdi >> birim
			>> birimFiyati >> marka;

		if (DosyaOku.eof()) break; //dosya sonu okundu�unda d�ng�den ��kma komutu.
		//�r�n�n bilgileri yazd�r�l�yor. 
		cout << " Urun No :" << urunNo << endl;
		cout << " Urun Adi :" << urunAdi << endl;
		cout << " Birim :" << birim << endl;
		cout << " Birim Fiyati :" << birimFiyati << endl;
		cout << " Marka :" << marka << endl << endl;

	}

	DosyaOku.close();
}
void projeMenusunuGoster() { // proje ile ilgili se�eneklerin ekrana yazd�r�ld��� fonksiyon
	cout << " 1) Proje Ekleme" << endl;
	cout << " 2) Proje Silme" << endl;
	cout << " 3) Proje Arama" << endl;
	cout << " 4) Proje Raporlama" << endl;
	cout << " 5) Menuden Cik" << endl;
}
void projeEkle() {
	ofstream DosyaYaz;

	int _projeNumara;
	do
	{
		cout << "Proje No: ";
		cin >> _projeNumara; //kullan�c�dan eklemek istedi�i proje numaras� isteniyor.

		DosyaYaz.open("Projeler.txt", ios::app);
		ifstream DosyaOkuma("Projeler.txt");

		while (true) { //kullan�c�n�n girdi�i proje numaras� dosyada mevcut mu kontrol� yap�l�yor.
			DosyaOkuma >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

			if (DosyaOkuma.eof()) {
				break;
			}

			while (projeNo == _projeNumara) { //kullan�c� ba�ka proje ait bir numara girdiyse 
				cout << "Bu Proje No Baska Projeye Ait !!" << endl;
				cout << "Proje No: ";
				cin >> _projeNumara; //ba�ka bir proje no girmesi isteniyor.

				//dosya okuma i�lemi ba�a sar�l�yor. Bu sayede yeni proje numaras� ba�ka projeye ait mi onun da kontrol� sa�lan�yor.
				DosyaOkuma.clear();
				DosyaOkuma.seekg(ios::beg);
			}

		}
		projeNo = _projeNumara; //e�siz bir proje numaras� elde edildi�inde projeye ait di�er bilgiler isteniyor.
		cout << "\n Proje Adi :"; cin >> projeAdi;
		cout << "\n Proje Yuruyucu Firma :"; cin >> projeYurutucuFirma;
		cout << "\n Proje Sorumlusu  :"; cin >> projeSorumlusu;
		cout << "\n Proje Kontroloru :"; cin >> projeKontroloru;

		// kullan�c�n�n verdi�i bilgiler dosyaya yaz�l�yor.
		DosyaYaz << projeNo << " " << projeAdi << ' ' << projeYurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << ' ' << "\n";
		DosyaYaz.close();

		cout << "\n baska kayit yapacak misin?(e/h) "; cin >> projeCevap;
	} while (!(projeCevap == 'h')); //kullan�c� h yan�t�n� verene kadar i�lem devam ediyor.

	cout << "Dosyaya yazim tamamlandi. " << endl;
}
void projeSilme() {
	int _projeNo;
	bool projeSilinemez;
	char cevap2 = 'e';

	while (cevap2 == 'e') {
		cout << " Silinecek Proje No :"; cin >> _projeNo; //silinecek proje numaras� isteniyor.

		projeSilinemez = false; //projeye hakedi� verilmi� mi kontrol�n� tutacak de�i�ken

		ifstream DosyaOku("Projeler.txt");
		ifstream HakedisKontrol("Hakedis.txt");

		while (true) {
			HakedisKontrol >> projeNo;

			if (HakedisKontrol.eof())break;

			if (_projeNo == projeNo) { //silinecek proje numaras� hakedi� dosyas�nda bulunduysa yani
										//projeye hakedi� verildiyse projeSilinemez de�i�keni true yap�l�yor.
				projeSilinemez = true;
			}
			HakedisKontrol.ignore(numeric_limits<streamsize>::max(), '\n'); //proje no yu okuyup di�er bilgileri ignore lay�p alt sat�ra ge�me kodu
		}
		if (!projeSilinemez) { //projeye hakedi� verilmediyse silme i�lemi ba�l�yor
			ofstream DosyaYaz("temp.txt"); //yine temp.txt olu�turuyorum.

			while (true)
			{
				DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

				if (DosyaOku.eof()) break;

				if (projeNo == _projeNo) //silinecek proje no ya s�ra gelince continue ile yazma i�lemini atl�yorum.
				{		//bu sayede temp.txt de silinecek olan proje bilgileri yazmam�� oluyor.
					continue;
				}
				DosyaYaz << projeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";

			}
			cout << " Baska Proje Silinecek Mi? (e/h)" << endl;
			cin >> cevap2;

			DosyaOku.close();
			DosyaYaz.close();
			HakedisKontrol.close();

			remove("Projeler.txt"); //eski dosyay� siliyoruz.
			rename("temp.txt", "Projeler.txt"); //g�ncel dosyam�z� Projeler.txt olarak adland�r�yoruz. Silme i�lemi tamamlan�yor.
		}
		else { //projeye hakedi� verilmi� olma durumu.
			cout << "Projeye Hakedis Verilmis Bu Proje Silinemez..." << endl;
			DosyaOku.close();
			HakedisKontrol.close();
			cout << " Baska Proje Silinecek Mi? (e/h)" << endl;
			cin >> cevap2;
		}
		

	}
}
void projeArama() {
	int projeNoAra;
	bool _bulunduMu = false; //proje bulunursa bu de�i�ken true yap�lacak
	char cevap1 = 'e';
	while (cevap1 == 'e') { //kullan�c�n�n cevab� e oldu�u s�rece tekrar edecek i�lemler d�ng�s�
		cout << " Proje No :"; cin >> projeNoAra; //aranacak proje numaras� isteniyor.
		_bulunduMu = false; 
		ifstream DosyaOku("Projeler.txt");
		while (true)
		{
			DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma
				>> projeSorumlusu >> projeKontroloru;

			if (DosyaOku.eof()) break; //dosya sonu okununca d�ng�den ��kma kodu

			if (projeNo == projeNoAra) //dosyada kullan�c�n�n arad��� proje numaras� bulunduysa
			{
				_bulunduMu = true; //de�i�ken true yap�l�yor
				break; //d�ng�den ��k�l�yor.
			}
		}
		if (_bulunduMu) //_bulunduMu de�i�keni true oldu�u zaman a�a��daki kodlar �al���yor.
		{
			//projenin bulundu�u numarada break yapt���m�z i�in elimizdeki de�i�kenler aranan projeye ait bilgileri tutuyor
			//bu y�zden bu de�i�kenleri yazd�r�yoruz.
			cout << "\n Proje Bilgileri \n";
			cout << " Proje No :" << projeNoAra << endl;
			cout << " Proje Adi :" << projeAdi << endl;
			cout << " Proje Yurutucu Firma :" << projeYurutucuFirma << endl;
			cout << " Proje Sorumlusu :" << projeSorumlusu << endl;
			cout << " Proje Kontroloru :" << projeKontroloru << endl;
			cout << " Baska Proje Sorgulanacak Mi? (e/h)" << endl;
			cin >> cevap1;
		}
		else { //proje bulunamadi durumu
			cout << " Proje Bulunamadi" << endl;
			cout << " Baska Proje Sorgulanacak Mi? (e/h)" << endl;
			cin >> cevap1;
		}
		DosyaOku.close();
	}

}
void projeRaporlama() { //Projeler.txt dosyas�ndaki t�m projeleri ve bilgilerini yazd�ran fonksiyon
	ifstream DosyaOku("Projeler.txt");
	while (true)
	{		//proje bilgileri okunuyor.
		DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma
			>> projeSorumlusu >> projeKontroloru;

		if (DosyaOku.eof()) break; //dosya sonu okununca d�ng�den ��kma komutu

		//proje bilgileri yazd�r�l�yor.
		cout << "\n Proje Bilgileri \n";
		cout << " Proje No :" << projeNo << endl;
		cout << " Proje Adi :" << projeAdi << endl;
		cout << " Proje Yurutucu Firma :" << projeYurutucuFirma << endl;
		cout << " Proje Sorumlusu :" << projeSorumlusu << endl;
		cout << " Proje Kontroloru :" << projeKontroloru << endl;

	}
	DosyaOku.close();
}
void hakedisMenusunuGoster() { //hakedi� men�s� se�eneklerini ekrana yazd�ran fonksiyon
	cout << " 1) Hakedis Ver" << endl;
	cout << " 2) Hakedis Urun Ekle" << endl;
	cout << " 3) Kullanilan Urun Sil" << endl;
	cout << " 4) Kullanilan Urun Guncelle" << endl;
	cout << " 5) Kullanilan Urunleri Listele" << endl;
	cout << " 6) Kullanilan Urun Ara" << endl;
	cout << " 7) Donem Raporla" << endl;
	cout << " 8) Menuden Cik" << endl;
}
void hakedisVer() {
	int urunler;
	int urunAdet;
	double urunFiyat;
	ofstream HakedisVer;

	HakedisVer.open("Hakedis.txt", ios::app);

	int hakedisVerilecekProjeNo;

	bool projeVarMi = false; //hakedi� verilmek istenen proje var m� kontrol�n� tutacak de�i�ken

	do {
		projeVarMi = false;

		cout << " Hakedis Verilecek Proje No: ";

		cin >> hakedisVerilecekProjeNo; //hakedi� verilmek istenen proje no kullan�c�dan isteniyor.

		ifstream ProjeleriOku("Projeler.txt");

		while (true) {

			ProjeleriOku >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

			if (ProjeleriOku.eof()) {
				break;
			}
			if (projeNo == hakedisVerilecekProjeNo) { //Projeler.txt dosyas�nda kullan�c�n�n girdi�i proje no var ise
				projeVarMi = true; //projeVarMi de�i�keni true yap�l�yor. 
				break; //ve d�ng�den ��k�l�yor.
			}

		}
		if (projeVarMi) { //projeVarMi de�i�keni true olursa i�lemler devam ediyor

			ifstream UrunleriKontrol("Urunler.txt");

			cout << "Hakedis Tarihi: ";
			cin >> hakedisTarihi; //hakedi� tarihi girilmesi isteniyor �rne�in: 25.08.2020

			HakedisVer << projeNo << " " << hakedisTarihi << " "; //dosyaya bilgiler yaz�l�yor.
			cout << "\n!!Eklenecek Urunleri Giriniz.. Eklenecek Urunler Bittiginde Urun No yerine '0' Yazip Enter'a Basin.!!" << endl;

			cout << "Bu Projede Hangi Urun Kullanilacak? Urun No : ";
			cin >> urunler; //projeye verilecek �r�n no isteniyor.
			cout << "Urun Adedi: ";
			cin >> urunAdet; //ka� adet kullan�laca�� isteniyor.

			while (urunler != 0) { //kullan�c� �r�n no yerine 0 girmedi�i s�rece �al��an d�ng�

				while (true) {
					UrunleriKontrol >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;
					if (UrunleriKontrol.eof())break;

					if (urunler == urunNo) { //kullan�c�n�n girdi�i �r�n mevcutsa durumu
						urunFiyat = birimFiyati; //birim fiyat de�eri al�n�yor.
						HakedisVer << urunler << " " << urunAdet << " " << urunFiyat << " "; //dosyaya yaz�l�yor.
						break; //d�ng�den ��k��
					}

				}
				//Urunler.txt okuma i�lemi ba�a sar�l�yor bu sayede yeni eklenen �r�n en ba�tan kontrol ediliyor.
				UrunleriKontrol.clear();
				UrunleriKontrol.seekg(ios::beg);

				cout << "Bu Projede Hangi Urun Kullanilacak? Urun No : ";
				cin >> urunler; //tekrar �r�n numaras� isteniyor.

				if (urunler != 0) { //kullan�c� 0 girmediyse �r�n adedi isteniyor.
					cout << "Urun Adedi: ";
					cin >> urunAdet;

				}

			}
			HakedisVer << "\n"; //i�lem bitince dosyada yeni sat�r yaparak i�lemi sonland�r�yoruz.

			cout << "Baska Hakedis Verilecek Mi? (e/h)" << endl;
			cin >> _cevap;

		}
		else { //hakedi� verilecek proje no Projeler.txt dosyas�nda mevcut olmama durumu
			cout << "Proje Bulunamadi." << endl;
			cout << "Baska Hakedis Verilecek Mi (e/h)" << endl;
			cin >> _cevap;
		}
		ProjeleriOku.close();
	} while (_cevap != 'h');

	HakedisVer.close();
}
void hakediseUrunEkle() {
	int urunEklenecekProjeNo;
	int eklenecekUrunNo;
	int eklenecekUrunAdet;
	int sayac = 0;
	string eklenecekTarih;
	double eklenecekUrunFiyat;
	bool _projeVarMi = false;
	string tarihTutucu = "";

	ifstream ProjeKontrol("Hakedis.txt");
	ofstream Gecici("temp.txt");
	ifstream _UrunKontrol("Urunler.txt");

	cout << "Urunun Eklenecegi Proje No: ";
	cin >> urunEklenecekProjeNo; //hangi projeye �r�n eklenecek onu soruyoruz
	cout << "Hangi Tarihe Eklenecek?: ";
	cin >> eklenecekTarih; //hangi hakedi� tarihine sahip projeye �r�n eklenecek onu soruyoruz.

	while (true) {
		ProjeKontrol >> projeNo >> hakedisTarihi;
		if (ProjeKontrol.eof())break;
		 //Hakedis.txt dosyas�nda kullan�c�n�n girdi�i proje no ve hakedi� tarihine sahip proje var m� kontrol�
		if (projeNo == urunEklenecekProjeNo && hakedisTarihi == eklenecekTarih) {

			cout << "Eklenecek Urun No: " ; //eklenecek �r�n no isteniyor
			cin >> eklenecekUrunNo;

			cout << "Eklenecek Urun Adet: " ; //ka� adet eklenece�i isteniyor
			cin >> eklenecekUrunAdet;


			while (true) {
				//kullan�c�n�n girdi�i �r�n Urunler.txt de mevcut mu kontrol�
				_UrunKontrol >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;
				if (_UrunKontrol.eof())break;

				if (eklenecekUrunNo == urunNo) { //e�er �r�n mevcutsa �al��acak kodlar
					eklenecekUrunFiyat = birimFiyati; //birim fiyat� tutacak de�i�kene atan�yor

					ProjeKontrol.clear(); 
					ProjeKontrol.seekg(ios::beg); //dosya ba��na gidiliyor.
					char ch;

					while (true) {
						ProjeKontrol >> projeNo;

						if (ProjeKontrol.eof())break;

						Gecici << projeNo;

						tarihTutucu = ""; //hakedi� tarihi kontrol de�i�keni
						sayac = 0; //bo�luk sayac�

						while (ProjeKontrol >> noskipws >> ch) {
							Gecici << ch;
							if (ch != ' ') { //karakter bo�luk olmad��� s�rece tarihTutucu de�i�kenini karakteri ekliyoruz.
								tarihTutucu += ch;
							}
							if (ch == ' ') sayac++;

							if (sayac >= 2)break; //sayac 2 ye e�it veya b�y�k oldu�unda d�ng�den ��k�yoruz.
						}
						//proje no ve hakedi� tarihi kontrol� yap�l�yor. E�er e�le�me sa�lan�rsa yazma i�lemi ba�l�yor.
						if (projeNo == urunEklenecekProjeNo && tarihTutucu == eklenecekTarih) {
							_projeVarMi = true;

							while (ProjeKontrol >> noskipws >> ch) {
								if (ch == '\n') //sat�r sonuna gelindiyse eklenecek �r�n� yazma i�lemi yap�l�yor.
								{
									Gecici << eklenecekUrunNo << " " << eklenecekUrunAdet << " " << eklenecekUrunFiyat << " " << "\n";

									break; //i�lem bitince break ile d�ng�den ��k�l�yor.
								}
								Gecici << ch;
							}
						}
						else { //e�er e�le�me sa�lanmad�ysa var olan dosyay� temp.txt ye yazmaya devam ediyor.
							while (ProjeKontrol >> noskipws >> ch) {

								Gecici << ch;
								if (ch == '\n')break;
							}
						}

					}
				}

			}
		}
		ProjeKontrol.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (_projeVarMi) { //ekleme i�lemi yap�ld�ysa durumu
		_UrunKontrol.close();
		ProjeKontrol.close();
		Gecici.close();

		remove("Hakedis.txt"); //eski dosya siliniyor.
		rename("temp.txt", "Hakedis.txt"); //g�ncel temp.txt dosyas� Hakedis.txt olarak adland�r�l�yor.
	}
	else { //proje bulunamama veya eklenecek �r�n bulunamama durumu.
		cout << "Proje Bulunamadi veya Urun Bulunamadi..." << endl;
		_UrunKontrol.close();
		ProjeKontrol.close();
		Gecici.close();
		remove("temp.txt"); //olu�turulmu� temp.txt dosyas�na i�lem yap�lmad��� i�in siliyoruz.
	}

}
void hakedistenUrunSil() {
	int urunSilinecekProjeNo;
	string _tarihTutucu = "";
	int _sayac = 0;
	string silinecekUrunNo;
	string silinecekTarih;
	int _boslukSayici = 0;
	bool _projeVarMi = false;
	ifstream ProjeVarMi("Hakedis.txt");
	ofstream Temp("temp.txt");

	cout << "Urun Hangi Projede Silinecek? Proje No: ";

	cin >> urunSilinecekProjeNo; //hangi projeden �r�n silinece�i bilgisini al�yoruz.

	cout << "Hangi Tarihten Silinecek?: ";
	cin >> silinecekTarih; //projenin hakedi� tarihini istiyoruz. ��nk� ayn� projeye birden fazla hakedi� verilmi� olabilir.

	while (true) {

		ProjeVarMi >> projeNo >> hakedisTarihi;

		if (ProjeVarMi.eof())break;
		//proje no ve hakedi� tarihi Hakedis.txt dosyas�nda mevcut mu kontrol�
		if (urunSilinecekProjeNo == projeNo && hakedisTarihi == silinecekTarih) {
			_projeVarMi = true; //proje bulunduysa de�i�kene true at�yoruz.
			break;
		}

		ProjeVarMi.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (_projeVarMi) { //proje varsa �al��acak kod blo�u

		cout << "Silinecek Urun No: ";
		cin >> silinecekUrunNo; //silinmek istenen �r�n numaras�n� al�yoruz.

		ProjeVarMi.clear();
		ProjeVarMi.seekg(ios::beg); //dosya ba��na gidiyoruz

		char ch;
		string kontrol = "";
		while (true) {

			ProjeVarMi >> projeNo;


			if (ProjeVarMi.eof())break;

			Temp << projeNo;

			_tarihTutucu = ""; //hakedi� tarihini tutacak de�i�ken
			_sayac = 0; //bo�luk sayac�

			while (ProjeVarMi >> noskipws >> ch) {
				Temp << ch;
				if (ch != ' ') { //karakter bo�luk olmad��� s�rece g�rd��� karakteri de�i�kene ekliyoruz
					_tarihTutucu += ch;
				}
				if (ch == ' ') _sayac++;

				if (_sayac >= 2)break;
			}
			//proje numaras� ve hakedi� tarihi e�le�me sa�land� m� kontrol�
			if (projeNo == urunSilinecekProjeNo && _tarihTutucu == silinecekTarih) {
				_boslukSayici = 0;

				while (ProjeVarMi >> noskipws >> ch) {

					if (ch != ' ') { //bo�luk olmad��� s�rece string de�i�kene karakteri ekliyoruz
						kontrol += ch;
					}

					if (ch == ' ') {
						_boslukSayici++;
						if (kontrol == silinecekUrunNo && _boslukSayici%3==1) { //�r�n adeti veya fiyat� ile silinecek �r�n no ayn� sat�rda bulunursa tekrar i�leme girmesin diye
																				//yani �r�n adet veya fiyat �r�n no gibi alg�lanmas�n diye bo�luk say�s� kontrol� yapt�m.
							int boslukSayac = 0;

							while (ProjeVarMi >> noskipws >> ch) {

								if (ch == ' ' || ch == '\n') {
									_boslukSayici++;
									boslukSayac++;
								}

								if (boslukSayac == 2) { //burada demek istenen �r�nle ilgili bilgiler bitince durumu
									if (ch == '\n') {
										Temp << ch; //e�er dosya sonuysa bunu dosyaya yaz�yoruz
									}
									break; //d�ng�den ��k�yoruz.
								}

							}
						}
						else { //e�er silinecek �r�n numaras� ile e�le�me sa�lanmazsa dosyaya kontrol de�i�kenindeki de�eri yaz�yoruz devam ediyoruz.
							Temp << kontrol << " ";
						}
						kontrol = ""; //kontrol de�i�keni s�f�rlan�yor
					}

					if (ch == '\n') {

						Temp << kontrol;

						break;
					}
				}
			}
			else { //proje no ve hakedi� tarihi e�le�meme durumu
				while (ProjeVarMi >> noskipws >> ch) {

					Temp << ch;
					//sat�r sonuna kadar dosyaya direkt yaz�yoruz. sat�r sonuna gelince d�ng�den ��k�yoruz 
					//tekrardan ba�a d�nerek kontrolleri tekrarl�yoruz.
					if (ch == '\n')
					{
						break;
					}
				}
			}

		}
		ProjeVarMi.close();

		Temp.close();

		remove("Hakedis.txt"); //eski dosyay� siliyoruz

		rename("temp.txt", "Hakedis.txt"); //g�ncel temp.txt dosyas�n� Hakedis.txt olarak adland�r�yoruz.
	}
	else { //proje yok durumu.
		cout << "Proje Bulunamadi" << endl;
		ProjeVarMi.close();
		Temp.close();
		remove("temp.txt"); //olu�turulan temp.txt ye bir �ey yazmad���m�z i�in siliyoruz. ��nk� proje bulunamad� 
	}


}
void hakedisUrunGuncelle() {
	int urunGuncellenecekProjeNo;
	string _tarihTutucu = "";
	int _sayac = 0;
	string guncellenecekUrunNo;
	string guncellenecekTarih;
	int guncelAdet;
	int _boslukSayici = 0;
	bool _projeVarMi = false;
	ifstream ProjeVarMi("Hakedis.txt");
	ofstream Temp("temp.txt");

	cout << "Urun Hangi Projede Guncellenecek? Proje No: ";

	cin >> urunGuncellenecekProjeNo; //hangi projedeki �r�n�n g�ncellenece�i bilgisini al�yoruz.

	cout << "Hangi Tarihten Guncellenecek?: ";
	cin >> guncellenecekTarih; //projenin hakedi� tarihini istiyoruz. ��nk� ayn� projeye birden fazla hakedi� verilmi� olabilir.

	while (true) {

		ProjeVarMi >> projeNo >> hakedisTarihi;

		if (ProjeVarMi.eof())break;
		//proje no ve hakedi� tarihi Hakedis.txt dosyas�nda mevcut mu kontrol�
		if (urunGuncellenecekProjeNo == projeNo && hakedisTarihi == guncellenecekTarih) {
			_projeVarMi = true; //proje bulunduysa de�i�kene true at�yoruz.
			break;
		}

		ProjeVarMi.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (_projeVarMi) { //proje varsa �al��acak kod blo�u

		cout << "Guncellenecek Urun No: ";
		cin >> guncellenecekUrunNo; //g�ncellenmek istenen �r�n numaras�n� al�yoruz.
		cout << "Guncel Adet Nedir?: ";
		cin >> guncelAdet; //g�ncel �r�n adedini istiyoruz

		ProjeVarMi.clear();
		ProjeVarMi.seekg(ios::beg); //dosya ba��na gidiyoruz

		char ch;
		string kontrol = "";
		while (true) {

			ProjeVarMi >> projeNo;


			if (ProjeVarMi.eof())break;

			Temp << projeNo;

			_tarihTutucu = ""; //hakedi� tarihini tutacak de�i�ken
			_sayac = 0; //bo�luk sayac�

			while (ProjeVarMi >> noskipws >> ch) {
				Temp << ch;
				if (ch != ' ') { //karakter bo�luk olmad��� s�rece g�rd��� karakteri de�i�kene ekliyoruz
					_tarihTutucu += ch;
				}
				if (ch == ' ') _sayac++;

				if (_sayac >= 2)break;
			}
			//proje numaras� ve hakedi� tarihi e�le�me sa�land� m� kontrol�
			if (projeNo == urunGuncellenecekProjeNo && _tarihTutucu == guncellenecekTarih) {
				_boslukSayici = 0;

				while (ProjeVarMi >> noskipws >> ch) {

					if (ch != ' ') { //bo�luk olmad��� s�rece string de�i�kene karakteri ekliyoruz
						kontrol += ch;
					}

					if (ch == ' ') {
						_boslukSayici++;
						if (kontrol == guncellenecekUrunNo && _boslukSayici % 3 == 1) { //�r�n adeti veya fiyat� ile g�ncellenecek �r�n no ayn� sat�rda bulunursa tekrar i�leme girmesin diye
																				//yani �r�n adet veya fiyat �r�n no gibi alg�lanmas�n diye bo�luk say�s� kontrol� yapt�m.
							int boslukSayac = 0;
							Temp << kontrol; //kontrol de�i�keninde �r�n numaras� tutuldu�u i�in onu direkt yaz�yoruz.
							kontrol = ""; //kontrol de�i�kenini s�f�rl�yoruz.
							while (ProjeVarMi >> noskipws >> ch) {

								if (ch != ' ') { //bo�luk g�rmedi�i s�rece kontrol de�i�kenine karakteri ekliyoruz.
									kontrol += ch;
								}
								if (ch == ' ' || ch == '\n') {
									_boslukSayici++;
									boslukSayac++;
									if (boslukSayac == 1) { //bo�luk g�rd���nde yani �r�n adedini okuma i�lemi bitti�inde
										Temp << ch << guncelAdet; //bo�lu�u ve g�ncel adeti dosyaya yaz�yoruz bu sayede g�ncellenmi� oluyor.
									}
									else { //bo�luk sayac 1 olmad���nda yani �r�n adeti k�sm�nda olmad���m�zda ise bo�luk ve kontrol de�i�kenini yaz�yoruz bir de bo�luk atarak i�lemi d�zg�n
										//bir �ekilde tamaml�yoruz.
										Temp << ch<<kontrol<<" ";
									}
									kontrol = "";
								}							

								if (boslukSayac == 2) { //burada demek istenen �r�nle ilgili bilgiler bitince durumu
									if (ch == '\n') {
										Temp << ch; //e�er dosya sonuysa bunu dosyaya yaz�yoruz
									}
									break; //d�ng�den ��k�yoruz.
								}

							}
						}
						else { //e�er silinecek �r�n numaras� ile e�le�me sa�lanmazsa dosyaya kontrol de�i�kenindeki de�eri yaz�yoruz devam ediyoruz.
							Temp << kontrol << " ";
						}
						kontrol = ""; //kontrol de�i�keni s�f�rlan�yor
					}

					if (ch == '\n') {

						Temp << kontrol;

						break;
					}
				}
			}
			else { //proje no ve hakedi� tarihi e�le�meme durumu
				while (ProjeVarMi >> noskipws >> ch) {

					Temp << ch;
					//sat�r sonuna kadar dosyaya direkt yaz�yoruz. sat�r sonuna gelince d�ng�den ��k�yoruz 
					//tekrardan ba�a d�nerek kontrolleri tekrarl�yoruz.
					if (ch == '\n')
					{
						break;
					}
				}
			}

		}
		ProjeVarMi.close();

		Temp.close();

		remove("Hakedis.txt"); //eski dosyay� siliyoruz

		rename("temp.txt", "Hakedis.txt"); //g�ncel temp.txt dosyas�n� Hakedis.txt olarak adland�r�yoruz.
	}
	else { //proje yok durumu.
		cout << "Proje Bulunamadi" << endl;
		ProjeVarMi.close();
		Temp.close();
		remove("temp.txt"); //olu�turulan temp.txt ye bir �ey yazmad���m�z i�in siliyoruz. ��nk� proje bulunamad� 
	}


}
void hakedisUrunListele() {

	string _hakedisTarih;
	int _projectNo;
	string _hakedis;
	int listelenecekProjeNo;
	char _ch;
	char cevap;

	string tarihHesaplama = "";
	int tarihSayac = 0;

	bool projeVarmi;
	int boslukSayac;

	do {

		boslukSayac = 0;
		projeVarmi = false;

		ifstream HakedisListele("Hakedis.txt");

		cout << "Hangi Projenin Urunleri Listelenecek ? Proje No: "; //proje numaras� isteniyor
		cin >> listelenecekProjeNo;
		cout << "Projenin Hakedis Tarihi Nedir? :"; //projenin hakedi� tarihi isteniyor
		cin >> _hakedisTarih;

		while (true) {

			HakedisListele >> _projectNo >> _hakedis;

			if (HakedisListele.eof())break;
			//kullan�c�n�n girdi�i bilgilerle e�le�me sa�lanma kontrol�
			if (listelenecekProjeNo == _projectNo&&_hakedis==_hakedisTarih) {
				projeVarmi = true;
			}
			HakedisListele.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (projeVarmi) {

			cout << "/(Urun No - Kullanilan Urun Adedi - Birim Fiyati)/" << endl;

			HakedisListele.clear();
			HakedisListele.seekg(ios::beg); //dosya ba��na gidiliyor.

			while (true) {
				HakedisListele >> _projectNo;

				if (HakedisListele.eof())break;

				tarihHesaplama = "";
				tarihSayac = 0;
				//hakedi� tarihini bulma d�ng�s�
				while (HakedisListele >> noskipws >> _ch) {

					if (_ch != ' ') {
						tarihHesaplama += _ch;
					}
					if (_ch == ' ') tarihSayac++;

					if (tarihSayac >= 2)break;
				}

				//proje numaras� ve hakedi� tarihi e�le�en sat�ra gelindi mi kontrol�
				if (_projectNo == listelenecekProjeNo && tarihHesaplama==_hakedisTarih) {

					while (HakedisListele >> noskipws >> _ch) { //�r�n no,kullan�lan adet,fiyat bilgileri yazd�r�l�yor

						if (_ch == '\n')
						{
							cout << endl;
							cout << "Baska Listeleme Yapacak Misiniz ?(e/h)";
							cin >> cevap;
							break;
						}

						cout << _ch;

					}
					break;//listeleme yap�ld��� i�in d�ng�den ��k�yoruz.
				}
				HakedisListele.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else { //proje bulunamama durumu
			cout << "Proje Bulunamadi.." << endl;
			cout << "Baska Listeleme Yapacak Misiniz ?(e/h)";
			cin >> cevap;
		}
		HakedisListele.close();

	} while (cevap != 'h');
}
void hakedisUrunAra() {

	int aranacakProje;
	string aranacakUrun;
	string _tarihTutucu;
	string hangiTarih;
	bool projeMevcut;
	bool urunMevcut;
	int _sayac = 0;
	char cevap = 'e';
	char ch;
	int boslukSayici = 0;

	string kelime;
	do {
		boslukSayici = 0;
		kelime = "";
		_tarihTutucu = "";
		_sayac = 0;
		projeMevcut = false;
		urunMevcut = false;

		cout << "Hangi Projeye Ait Urun Aranacak? Proje No: "; //proje numaras� isteniyor
		cin >> aranacakProje;
		cout << "Projenin Hakedis Tarihi?: "; //projenin hakedi� tarihi isteniyor
		cin >> hangiTarih;

		ifstream ProjeKontrol("Hakedis.txt");

		while (true) {
			ProjeKontrol >> projeNo >>hakedisTarihi;

			if (ProjeKontrol.eof())break;
			//proje mevcut mu kontrol�
			if (projeNo == aranacakProje&&hakedisTarihi==hangiTarih) {
				projeMevcut = true;
				break;
			}

			ProjeKontrol.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (projeMevcut) { //proje mevcutsa �al��acak kod blo�u
			ProjeKontrol.clear();
			ProjeKontrol.seekg(ios::beg); //dosya ba��na gidiliyor

			cout << "Aranacak Urun No: "; //aranacak �r�n no isteniyor.
			cin >> aranacakUrun;

			while (true) {
				ProjeKontrol >> projeNo;

				if (ProjeKontrol.eof())break;

				_tarihTutucu = "";
				_sayac = 0;
				boslukSayici = 0;
				//hakedi� tarihi hesaplama d�ng�s�
				while (ProjeKontrol >> noskipws >> ch) {

					if (ch != ' ') {
						_tarihTutucu += ch;
					}
					if (ch == ' ') _sayac++;

					if (_sayac >= 2)break;
				}
				//hakedi� tarihi ve proje no e�le�mesi sa�lan�yor mu kontrol�
				if (projeNo == aranacakProje&&_tarihTutucu==hangiTarih) {

					while (ProjeKontrol >> noskipws >> ch) {

						if (ch == '\n')break;

						if (ch != ' ') { //karakter bo�luk olmad��� s�rece kelime de�i�kenine at�yoruz
							kelime += ch;
						}
						if (ch == ' ') { //bo�luk g�r�nce kelime de�i�kenini ve aranacak �r�n� birbirlerine e�it mi diye kontrol ediyoruz
							boslukSayici++;
							if (kelime == aranacakUrun&&boslukSayici%3==1) { //bo�luk sayac�n�n 3 e g�re modu 1 olmal� ��nk� kelime �r�n no ile kar��la�t�r�lmal�.
									//�rne�in kullan�lan �r�n adedi 351 ise ve aranan �r�n numaras� da 351 ise bu ko�ul sa�lan�r bunu engellemek i�in bo�luk sayac�yla kontrol� ekliyorum.
								//bu sayede kar��la�t�r�lan de�erlerin �r�n numaras� oldu�undan emin oluyorum.
								ifstream UrunOku("Urunler.txt");

								while (true) { //bulunan �r�n�n bilgileri Urunler.txt dosyas�ndan �ekiliyor.
									UrunOku >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

									if (UrunOku.eof())break;

									if (urunNo == atoi(aranacakUrun.c_str())) { //aranacakUrun stringini integer a �evirip �r�n no ile kar��la�t�r�yorum.
										urunMevcut = true;
										//�r�n bilgilerini yazd�r�yoruz. ve �r�n bulundu bilgisini veriyoruz.
										cout << "Urun Bulundu..!!" << endl;
										cout << "Urun No:" << urunNo << endl << "Urun Adi:" << urunAdi << endl << "Birim:" << birim
											<< endl << "Birim Fiyati:" << birimFiyati << endl << "Marka:" << marka << endl;
										cout << "Baska Sorgulama Yapacak Misiniz?(e/h) ";
										cin >> cevap;
										break;
									}

								}

								UrunOku.close();
								break;
							}
							kelime = ""; //e�le�me olmuyorsa kelimeyi s�f�rl�yoruz ve kontrol tekrardan ba�l�yor.
						}
					}
					if (urunMevcut == false) { //�r�n�n bulunmama durumu
						cout << "Urun Bulunamadi.." << endl;
						cout << "Baska Sorgulama Yapacak Misiniz?(e/h) ";
						cin >> cevap;
						break;
					}
					break;
				}

				ProjeKontrol.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else { //projenin bulunamama durumu
			cout << "Proje Bulunamadi..." << endl;
			cout << "Baska Sorgulama Yapacak Misiniz?(e/h) ";
			cin >> cevap;

		}

	} while (cevap != 'h');


}
void hakedisDonemRaporla() {
	double geciciTutar = 0;
	double toplamTutar = 0;
	char ch;
	int boslukSayaci = 0;

	string adet = "";
	string fiyat = "";

	ifstream Raporla("Hakedis.txt");

	cout << "----Toplam Tutar ve Proje Basina Tutar Raporlama----" << endl;
	cout << "/(Proje No)-(Hakedis Tarihi)-(Urun No,Adet,Fiyat)/" << endl;
	while (true) {

		boslukSayaci = 0;

		Raporla >> projeNo;

		if (Raporla.eof())break;

		cout << projeNo;

		while (Raporla >> noskipws >> ch) {

			if (ch == '\n') {
				cout << " -> Tutar: " << geciciTutar << "TL" << endl; //projeye ait tutar yazd�r�l�yor.
				geciciTutar = 0;
				break;

			}
			cout << ch; 

			if (ch == ' ') {
				boslukSayaci++;
			}
			//a�a��daki kontrol proje no ve hakedi� tarihini ge�ti mi kontrol�
			if (boslukSayaci >= 3 && boslukSayaci % 3 == 0) {

				while (Raporla >> noskipws >> ch) {
					cout << ch;

					if (ch == '\n')break;

					if (ch != ' ') { //�r�n adeti okunuyor
						adet += ch;
					}
					if (ch == ' ') {
						boslukSayaci++;
						while (Raporla >> noskipws >> ch) {
							cout << ch;

							if (ch == '\n')break;

							if (ch != ' ') { //�r�n fiyat� okunuyor.
								fiyat += ch;
							}
							if (ch == ' ') {
								boslukSayaci++;
								break;
							}
						}
						break;
					}

				}
				toplamTutar += (atof(fiyat.c_str()) * atof(adet.c_str())); //fiyat ve adet double a d�n��t�r�l�yor ve �arp�larak double toplamTutar de�i�kenine atan�yor.
				geciciTutar += (atof(fiyat.c_str()) * atof(adet.c_str())); //fiyat ve adet double a d�n��t�r�l�yor ve �arp�larak double geciciTutar de�i�kenine atan�yor.
				fiyat = ""; //fiyat de�i�keni s�f�rlan�yor.
				adet = ""; //adet de�i�keni s�f�rlan�yor.
			}


		}

	}
	cout << "Toplam Tutar: " << toplamTutar << "TL" << endl << endl; //toplam tutar yazd�r�l�yor.
	Raporla.close();
}