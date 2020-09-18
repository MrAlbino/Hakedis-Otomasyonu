/****************************************************************************
**							SAKARYA ÜNÝVERSÝTESÝ
**					BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**						BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**							PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**						ÖDEV NUMARASI : 1.Proje
**						ÖÐRENCÝ ADI : Ayberk KÖSE
**						ÖÐRENCÝ NUMARASI : B181210001
**						DERS GRUBU : 1/A
****************************************************************************/

//satýr sonu ignore lamak için tanýmladým
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
// Urunler.txt dosyasýnda yer alancak alanlar
double toplamFiyat = 0;
int i = 1;
string secim, secim1;
int urunNo;
string urunAdi;
string birim;
float birimFiyati;
string marka;

//Projeler.txt dosyasýnda yer alacak alanlar
int projeNo;
string projeAdi;
string projeYurutucuFirma;
string projeSorumlusu;
string projeKontroloru;

//Hakediþ.txt dosyasýnda yer alacak alanlar
string hakedisTarihi;

//fonksiyon gövdeleri main in altýnda olduðu için burada fonksiyon imzasý atýyoruz.
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

		if (secim == "1") //kullanýcýnýn 1 e basma durumu
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
			//secim1 5 olmadýðý sürece menüden çýkmýyor.

		}
		if (secim == "2") { //kullanýcýnýn 2 yi seçme durumu
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
			} while ((secim1 != "1" && secim1 != "2" && secim1 != "3" && secim1 != "4") || secim1 != "5"); //secim1 5 olana kadar menüde kalýyor
		}
		if (secim == "3") { //kullanýcýnýn 3 üncü seçeneði seçme durumu
			
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
	} while ((secim != "1" && secim != "2" && secim != "3" && secim != "4") || secim != "4"); //kullanýcý 4 e basana kadar program devam ediyor

	system("PAUSE");
	return EXIT_SUCCESS;
}
void anaMenuyuGoster() { //ana menü seçeneklerini ekrana yazdýran fonksiyon
	cout << " Ne yapmak istiyorsunuz ? " << endl;
	cout << " 1) Urun Islemleri " << endl;
	cout << " 2) Proje Islemleri " << endl;
	cout << " 3) Hakedis Islemleri" << endl;
	cout << " 4) Programdan Cikis" << endl;
}
void urunMenusunuGoster() { // ürünlerle ilgili seçenekleri ekrana yazdýran fonksiyon
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
		cout << "Urun No: "; //kullanýcýdan eklenecek ürün numarasý isteniyor.
		cin >> _urunNumara;

		DosyaYaz.open("Urunler.txt", ios::app);
		ifstream DosyaOkuma("Urunler.txt");
		while (true) { //kullanýcýnýn girdiði numara baþka ürüne ait mi kontrolü
			DosyaOkuma >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

			if (DosyaOkuma.eof()) {//dosya sonu okunduðunda döngüden çýkma komutu.
				break;
			}

			while (urunNo == _urunNumara) {//eðer ayný numaraya sahip baþka ürün varsa hata veriyor. Ve yeni numara girmesi isteniyor.
				cout << "Bu Urun No Baska Urune Ait !!" << endl;
				cout << "Urun No: ";
				cin >> _urunNumara;
				//yeni numarayý girdikten sonra okuma iþlemi baþa gönderiliyor ve dosya baþtan kontrol ediliyor. Yeni ürün no baþka ürüne aitse yine hata versin diye.
				DosyaOkuma.clear();
				DosyaOkuma.seekg(ios::beg);
			}

		}
		urunNo = _urunNumara;
		cout << "\n Urun Adi :"; cin >> urunAdi; // ürünün diðer bilgileri kullanýcýdan isteniyor.
		cout << "\n Birim :"; cin >> birim;
		cout << "\n Birim Fiyati :"; cin >> birimFiyati;
		cout << "\n Markasi :"; cin >> marka;
		//kullanýcýdan alýnan bilgiler dosyaya yazýlýyor.
		DosyaYaz << urunNo << " " << urunAdi << ' ' << birim << ' ' << birimFiyati << ' ' << marka << ' ' << "\n";
		DosyaYaz.close();
		cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
	} while (!(cevap == 'h')); //cevap h olmadýðý sürece kayýt iþlemi tekrarlanýyor

	cout << "Dosyaya yazim tamamlandi. " << endl;
}
void urunSil() {
	int _urunNo;
	char cevap2 = 'e';
	while (cevap2 == 'e') { // cevap e olduðu sürece tekrarlanan döngü
		cout << " Silinecek Urun No :"; cin >> _urunNo; // kullanýcýdan silinecek ürün numarasý isteniyor.

		ifstream DosyaOku("Urunler.txt");
		ofstream DosyaYaz("temp.txt"); //silme iþlemini ürünleri yeni bir dosyaya yazarak yapacaðýmýz için temp.txt dosyasý açýyoruz.
		while (true)
		{
			DosyaOku >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

			if (DosyaOku.eof()) break;//dosya sonu okunduðunda döngüden çýkma komutu.

			if (urunNo == _urunNo) //eðer silinecek ürün no bulunursa continue diyerek yazma iþlemini atlýyoruz.
			{
				continue; //bu sayede silinecek ürün temp.txt ye yazýlmýyor.
			}
			DosyaYaz << urunNo << " " << urunAdi << " " << birim << " " << birimFiyati << " " << marka << "\n";

		}
		cout << "Baska Urun Silinecek Mi? (e/h)" << endl;
		cin >> cevap2;
		DosyaOku.close();
		DosyaYaz.close();
		remove("Urunler.txt"); //eski dosya siliniyor.
		rename("temp.txt", "Urunler.txt"); //temp.txt Urunler.txt olarak adlandýrýlýyor böylece iþlem tamamlanýyor.
	}
}
void urunAra() {
	int urunNoAra;

	bool bulunduMu = false;

	char cevap1 = 'e';

	while (cevap1 == 'e') { //kullanýcýnýn cevabý e olduðu sürece devam edecek iþlemler

		cout << " Urun No :"; cin >> urunNoAra; //aranacak ürün no isteniyor.

		bulunduMu = false;

		ifstream DosyaOku("Urunler.txt");

		while (true)
		{
			DosyaOku >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

			if (DosyaOku.eof()) break;//dosya sonu okunduðunda döngüden çýkma komutu.

			if (urunNo == urunNoAra) // kullanýcýnýn girdiði ürün no dosyada bulunursa bulunduMu deðiþkeni true yapýlýyor.
			{
				bulunduMu = true;
				break;
			}

		}
		if (bulunduMu) //bulunduysa ürünün bilgileri ekrana yazdýrýlýyor.
		{
			cout << "\n Urun Bilgileri \n";
			cout << " Urun No :" << urunNoAra << endl;
			cout << " Urun Adi :" << urunAdi << endl;
			cout << " Birim :" << birim << endl;
			cout << " Birim Fiyati :" << birimFiyati << endl;
			cout << " Marka :" << marka << endl;
			cout << " Baska Urun Sorgulanacak Mi? (e/h)" << endl;
			cin >> cevap1; //kullanýcýdan baþka ürün sorgulayýp sorgulamayacaðý bilgisi isteniyor
		}
		else { //ürünün bulunamadýðý durum
			cout << " Urun Bulunamadi" << endl;
			cout << " Baska Urun Sorgulanacak Mi? (e/h)" << endl;
			cin >> cevap1; //kullanýcýdan baþka ürün sorgulayýp sorgulamayacaðý bilgisi isteniyor
		}
		DosyaOku.close();
	}

}
void urunRaporla() { //dosyadaki tüm ürünleri ve bilgilerini yazdýran fonksiyon
	ifstream DosyaOku("Urunler.txt");
	cout << "\n Urun Bilgileri \n";
	while (true) //sürekli çalýþan döngü
	{
		DosyaOku >> urunNo >> urunAdi >> birim
			>> birimFiyati >> marka;

		if (DosyaOku.eof()) break; //dosya sonu okunduðunda döngüden çýkma komutu.
		//ürünün bilgileri yazdýrýlýyor. 
		cout << " Urun No :" << urunNo << endl;
		cout << " Urun Adi :" << urunAdi << endl;
		cout << " Birim :" << birim << endl;
		cout << " Birim Fiyati :" << birimFiyati << endl;
		cout << " Marka :" << marka << endl << endl;

	}

	DosyaOku.close();
}
void projeMenusunuGoster() { // proje ile ilgili seçeneklerin ekrana yazdýrýldýðý fonksiyon
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
		cin >> _projeNumara; //kullanýcýdan eklemek istediði proje numarasý isteniyor.

		DosyaYaz.open("Projeler.txt", ios::app);
		ifstream DosyaOkuma("Projeler.txt");

		while (true) { //kullanýcýnýn girdiði proje numarasý dosyada mevcut mu kontrolü yapýlýyor.
			DosyaOkuma >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

			if (DosyaOkuma.eof()) {
				break;
			}

			while (projeNo == _projeNumara) { //kullanýcý baþka proje ait bir numara girdiyse 
				cout << "Bu Proje No Baska Projeye Ait !!" << endl;
				cout << "Proje No: ";
				cin >> _projeNumara; //baþka bir proje no girmesi isteniyor.

				//dosya okuma iþlemi baþa sarýlýyor. Bu sayede yeni proje numarasý baþka projeye ait mi onun da kontrolü saðlanýyor.
				DosyaOkuma.clear();
				DosyaOkuma.seekg(ios::beg);
			}

		}
		projeNo = _projeNumara; //eþsiz bir proje numarasý elde edildiðinde projeye ait diðer bilgiler isteniyor.
		cout << "\n Proje Adi :"; cin >> projeAdi;
		cout << "\n Proje Yuruyucu Firma :"; cin >> projeYurutucuFirma;
		cout << "\n Proje Sorumlusu  :"; cin >> projeSorumlusu;
		cout << "\n Proje Kontroloru :"; cin >> projeKontroloru;

		// kullanýcýnýn verdiði bilgiler dosyaya yazýlýyor.
		DosyaYaz << projeNo << " " << projeAdi << ' ' << projeYurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << ' ' << "\n";
		DosyaYaz.close();

		cout << "\n baska kayit yapacak misin?(e/h) "; cin >> projeCevap;
	} while (!(projeCevap == 'h')); //kullanýcý h yanýtýný verene kadar iþlem devam ediyor.

	cout << "Dosyaya yazim tamamlandi. " << endl;
}
void projeSilme() {
	int _projeNo;
	bool projeSilinemez;
	char cevap2 = 'e';

	while (cevap2 == 'e') {
		cout << " Silinecek Proje No :"; cin >> _projeNo; //silinecek proje numarasý isteniyor.

		projeSilinemez = false; //projeye hakediþ verilmiþ mi kontrolünü tutacak deðiþken

		ifstream DosyaOku("Projeler.txt");
		ifstream HakedisKontrol("Hakedis.txt");

		while (true) {
			HakedisKontrol >> projeNo;

			if (HakedisKontrol.eof())break;

			if (_projeNo == projeNo) { //silinecek proje numarasý hakediþ dosyasýnda bulunduysa yani
										//projeye hakediþ verildiyse projeSilinemez deðiþkeni true yapýlýyor.
				projeSilinemez = true;
			}
			HakedisKontrol.ignore(numeric_limits<streamsize>::max(), '\n'); //proje no yu okuyup diðer bilgileri ignore layýp alt satýra geçme kodu
		}
		if (!projeSilinemez) { //projeye hakediþ verilmediyse silme iþlemi baþlýyor
			ofstream DosyaYaz("temp.txt"); //yine temp.txt oluþturuyorum.

			while (true)
			{
				DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

				if (DosyaOku.eof()) break;

				if (projeNo == _projeNo) //silinecek proje no ya sýra gelince continue ile yazma iþlemini atlýyorum.
				{		//bu sayede temp.txt de silinecek olan proje bilgileri yazmamýþ oluyor.
					continue;
				}
				DosyaYaz << projeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";

			}
			cout << " Baska Proje Silinecek Mi? (e/h)" << endl;
			cin >> cevap2;

			DosyaOku.close();
			DosyaYaz.close();
			HakedisKontrol.close();

			remove("Projeler.txt"); //eski dosyayý siliyoruz.
			rename("temp.txt", "Projeler.txt"); //güncel dosyamýzý Projeler.txt olarak adlandýrýyoruz. Silme iþlemi tamamlanýyor.
		}
		else { //projeye hakediþ verilmiþ olma durumu.
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
	bool _bulunduMu = false; //proje bulunursa bu deðiþken true yapýlacak
	char cevap1 = 'e';
	while (cevap1 == 'e') { //kullanýcýnýn cevabý e olduðu sürece tekrar edecek iþlemler döngüsü
		cout << " Proje No :"; cin >> projeNoAra; //aranacak proje numarasý isteniyor.
		_bulunduMu = false; 
		ifstream DosyaOku("Projeler.txt");
		while (true)
		{
			DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma
				>> projeSorumlusu >> projeKontroloru;

			if (DosyaOku.eof()) break; //dosya sonu okununca döngüden çýkma kodu

			if (projeNo == projeNoAra) //dosyada kullanýcýnýn aradýðý proje numarasý bulunduysa
			{
				_bulunduMu = true; //deðiþken true yapýlýyor
				break; //döngüden çýkýlýyor.
			}
		}
		if (_bulunduMu) //_bulunduMu deðiþkeni true olduðu zaman aþaðýdaki kodlar çalýþýyor.
		{
			//projenin bulunduðu numarada break yaptýðýmýz için elimizdeki deðiþkenler aranan projeye ait bilgileri tutuyor
			//bu yüzden bu deðiþkenleri yazdýrýyoruz.
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
void projeRaporlama() { //Projeler.txt dosyasýndaki tüm projeleri ve bilgilerini yazdýran fonksiyon
	ifstream DosyaOku("Projeler.txt");
	while (true)
	{		//proje bilgileri okunuyor.
		DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma
			>> projeSorumlusu >> projeKontroloru;

		if (DosyaOku.eof()) break; //dosya sonu okununca döngüden çýkma komutu

		//proje bilgileri yazdýrýlýyor.
		cout << "\n Proje Bilgileri \n";
		cout << " Proje No :" << projeNo << endl;
		cout << " Proje Adi :" << projeAdi << endl;
		cout << " Proje Yurutucu Firma :" << projeYurutucuFirma << endl;
		cout << " Proje Sorumlusu :" << projeSorumlusu << endl;
		cout << " Proje Kontroloru :" << projeKontroloru << endl;

	}
	DosyaOku.close();
}
void hakedisMenusunuGoster() { //hakediþ menüsü seçeneklerini ekrana yazdýran fonksiyon
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

	bool projeVarMi = false; //hakediþ verilmek istenen proje var mý kontrolünü tutacak deðiþken

	do {
		projeVarMi = false;

		cout << " Hakedis Verilecek Proje No: ";

		cin >> hakedisVerilecekProjeNo; //hakediþ verilmek istenen proje no kullanýcýdan isteniyor.

		ifstream ProjeleriOku("Projeler.txt");

		while (true) {

			ProjeleriOku >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

			if (ProjeleriOku.eof()) {
				break;
			}
			if (projeNo == hakedisVerilecekProjeNo) { //Projeler.txt dosyasýnda kullanýcýnýn girdiði proje no var ise
				projeVarMi = true; //projeVarMi deðiþkeni true yapýlýyor. 
				break; //ve döngüden çýkýlýyor.
			}

		}
		if (projeVarMi) { //projeVarMi deðiþkeni true olursa iþlemler devam ediyor

			ifstream UrunleriKontrol("Urunler.txt");

			cout << "Hakedis Tarihi: ";
			cin >> hakedisTarihi; //hakediþ tarihi girilmesi isteniyor örneðin: 25.08.2020

			HakedisVer << projeNo << " " << hakedisTarihi << " "; //dosyaya bilgiler yazýlýyor.
			cout << "\n!!Eklenecek Urunleri Giriniz.. Eklenecek Urunler Bittiginde Urun No yerine '0' Yazip Enter'a Basin.!!" << endl;

			cout << "Bu Projede Hangi Urun Kullanilacak? Urun No : ";
			cin >> urunler; //projeye verilecek ürün no isteniyor.
			cout << "Urun Adedi: ";
			cin >> urunAdet; //kaç adet kullanýlacaðý isteniyor.

			while (urunler != 0) { //kullanýcý ürün no yerine 0 girmediði sürece çalýþan döngü

				while (true) {
					UrunleriKontrol >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;
					if (UrunleriKontrol.eof())break;

					if (urunler == urunNo) { //kullanýcýnýn girdiði ürün mevcutsa durumu
						urunFiyat = birimFiyati; //birim fiyat deðeri alýnýyor.
						HakedisVer << urunler << " " << urunAdet << " " << urunFiyat << " "; //dosyaya yazýlýyor.
						break; //döngüden çýkýþ
					}

				}
				//Urunler.txt okuma iþlemi baþa sarýlýyor bu sayede yeni eklenen ürün en baþtan kontrol ediliyor.
				UrunleriKontrol.clear();
				UrunleriKontrol.seekg(ios::beg);

				cout << "Bu Projede Hangi Urun Kullanilacak? Urun No : ";
				cin >> urunler; //tekrar ürün numarasý isteniyor.

				if (urunler != 0) { //kullanýcý 0 girmediyse ürün adedi isteniyor.
					cout << "Urun Adedi: ";
					cin >> urunAdet;

				}

			}
			HakedisVer << "\n"; //iþlem bitince dosyada yeni satýr yaparak iþlemi sonlandýrýyoruz.

			cout << "Baska Hakedis Verilecek Mi? (e/h)" << endl;
			cin >> _cevap;

		}
		else { //hakediþ verilecek proje no Projeler.txt dosyasýnda mevcut olmama durumu
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
	cin >> urunEklenecekProjeNo; //hangi projeye ürün eklenecek onu soruyoruz
	cout << "Hangi Tarihe Eklenecek?: ";
	cin >> eklenecekTarih; //hangi hakediþ tarihine sahip projeye ürün eklenecek onu soruyoruz.

	while (true) {
		ProjeKontrol >> projeNo >> hakedisTarihi;
		if (ProjeKontrol.eof())break;
		 //Hakedis.txt dosyasýnda kullanýcýnýn girdiði proje no ve hakediþ tarihine sahip proje var mý kontrolü
		if (projeNo == urunEklenecekProjeNo && hakedisTarihi == eklenecekTarih) {

			cout << "Eklenecek Urun No: " ; //eklenecek ürün no isteniyor
			cin >> eklenecekUrunNo;

			cout << "Eklenecek Urun Adet: " ; //kaç adet ekleneceði isteniyor
			cin >> eklenecekUrunAdet;


			while (true) {
				//kullanýcýnýn girdiði ürün Urunler.txt de mevcut mu kontrolü
				_UrunKontrol >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;
				if (_UrunKontrol.eof())break;

				if (eklenecekUrunNo == urunNo) { //eðer ürün mevcutsa çalýþacak kodlar
					eklenecekUrunFiyat = birimFiyati; //birim fiyatý tutacak deðiþkene atanýyor

					ProjeKontrol.clear(); 
					ProjeKontrol.seekg(ios::beg); //dosya baþýna gidiliyor.
					char ch;

					while (true) {
						ProjeKontrol >> projeNo;

						if (ProjeKontrol.eof())break;

						Gecici << projeNo;

						tarihTutucu = ""; //hakediþ tarihi kontrol deðiþkeni
						sayac = 0; //boþluk sayacý

						while (ProjeKontrol >> noskipws >> ch) {
							Gecici << ch;
							if (ch != ' ') { //karakter boþluk olmadýðý sürece tarihTutucu deðiþkenini karakteri ekliyoruz.
								tarihTutucu += ch;
							}
							if (ch == ' ') sayac++;

							if (sayac >= 2)break; //sayac 2 ye eþit veya büyük olduðunda döngüden çýkýyoruz.
						}
						//proje no ve hakediþ tarihi kontrolü yapýlýyor. Eðer eþleþme saðlanýrsa yazma iþlemi baþlýyor.
						if (projeNo == urunEklenecekProjeNo && tarihTutucu == eklenecekTarih) {
							_projeVarMi = true;

							while (ProjeKontrol >> noskipws >> ch) {
								if (ch == '\n') //satýr sonuna gelindiyse eklenecek ürünü yazma iþlemi yapýlýyor.
								{
									Gecici << eklenecekUrunNo << " " << eklenecekUrunAdet << " " << eklenecekUrunFiyat << " " << "\n";

									break; //iþlem bitince break ile döngüden çýkýlýyor.
								}
								Gecici << ch;
							}
						}
						else { //eðer eþleþme saðlanmadýysa var olan dosyayý temp.txt ye yazmaya devam ediyor.
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
	if (_projeVarMi) { //ekleme iþlemi yapýldýysa durumu
		_UrunKontrol.close();
		ProjeKontrol.close();
		Gecici.close();

		remove("Hakedis.txt"); //eski dosya siliniyor.
		rename("temp.txt", "Hakedis.txt"); //güncel temp.txt dosyasý Hakedis.txt olarak adlandýrýlýyor.
	}
	else { //proje bulunamama veya eklenecek ürün bulunamama durumu.
		cout << "Proje Bulunamadi veya Urun Bulunamadi..." << endl;
		_UrunKontrol.close();
		ProjeKontrol.close();
		Gecici.close();
		remove("temp.txt"); //oluþturulmuþ temp.txt dosyasýna iþlem yapýlmadýðý için siliyoruz.
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

	cin >> urunSilinecekProjeNo; //hangi projeden ürün silineceði bilgisini alýyoruz.

	cout << "Hangi Tarihten Silinecek?: ";
	cin >> silinecekTarih; //projenin hakediþ tarihini istiyoruz. Çünkü ayný projeye birden fazla hakediþ verilmiþ olabilir.

	while (true) {

		ProjeVarMi >> projeNo >> hakedisTarihi;

		if (ProjeVarMi.eof())break;
		//proje no ve hakediþ tarihi Hakedis.txt dosyasýnda mevcut mu kontrolü
		if (urunSilinecekProjeNo == projeNo && hakedisTarihi == silinecekTarih) {
			_projeVarMi = true; //proje bulunduysa deðiþkene true atýyoruz.
			break;
		}

		ProjeVarMi.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (_projeVarMi) { //proje varsa çalýþacak kod bloðu

		cout << "Silinecek Urun No: ";
		cin >> silinecekUrunNo; //silinmek istenen ürün numarasýný alýyoruz.

		ProjeVarMi.clear();
		ProjeVarMi.seekg(ios::beg); //dosya baþýna gidiyoruz

		char ch;
		string kontrol = "";
		while (true) {

			ProjeVarMi >> projeNo;


			if (ProjeVarMi.eof())break;

			Temp << projeNo;

			_tarihTutucu = ""; //hakediþ tarihini tutacak deðiþken
			_sayac = 0; //boþluk sayacý

			while (ProjeVarMi >> noskipws >> ch) {
				Temp << ch;
				if (ch != ' ') { //karakter boþluk olmadýðý sürece gördüðü karakteri deðiþkene ekliyoruz
					_tarihTutucu += ch;
				}
				if (ch == ' ') _sayac++;

				if (_sayac >= 2)break;
			}
			//proje numarasý ve hakediþ tarihi eþleþme saðlandý mý kontrolü
			if (projeNo == urunSilinecekProjeNo && _tarihTutucu == silinecekTarih) {
				_boslukSayici = 0;

				while (ProjeVarMi >> noskipws >> ch) {

					if (ch != ' ') { //boþluk olmadýðý sürece string deðiþkene karakteri ekliyoruz
						kontrol += ch;
					}

					if (ch == ' ') {
						_boslukSayici++;
						if (kontrol == silinecekUrunNo && _boslukSayici%3==1) { //ürün adeti veya fiyatý ile silinecek ürün no ayný satýrda bulunursa tekrar iþleme girmesin diye
																				//yani ürün adet veya fiyat ürün no gibi algýlanmasýn diye boþluk sayýsý kontrolü yaptým.
							int boslukSayac = 0;

							while (ProjeVarMi >> noskipws >> ch) {

								if (ch == ' ' || ch == '\n') {
									_boslukSayici++;
									boslukSayac++;
								}

								if (boslukSayac == 2) { //burada demek istenen ürünle ilgili bilgiler bitince durumu
									if (ch == '\n') {
										Temp << ch; //eðer dosya sonuysa bunu dosyaya yazýyoruz
									}
									break; //döngüden çýkýyoruz.
								}

							}
						}
						else { //eðer silinecek ürün numarasý ile eþleþme saðlanmazsa dosyaya kontrol deðiþkenindeki deðeri yazýyoruz devam ediyoruz.
							Temp << kontrol << " ";
						}
						kontrol = ""; //kontrol deðiþkeni sýfýrlanýyor
					}

					if (ch == '\n') {

						Temp << kontrol;

						break;
					}
				}
			}
			else { //proje no ve hakediþ tarihi eþleþmeme durumu
				while (ProjeVarMi >> noskipws >> ch) {

					Temp << ch;
					//satýr sonuna kadar dosyaya direkt yazýyoruz. satýr sonuna gelince döngüden çýkýyoruz 
					//tekrardan baþa dönerek kontrolleri tekrarlýyoruz.
					if (ch == '\n')
					{
						break;
					}
				}
			}

		}
		ProjeVarMi.close();

		Temp.close();

		remove("Hakedis.txt"); //eski dosyayý siliyoruz

		rename("temp.txt", "Hakedis.txt"); //güncel temp.txt dosyasýný Hakedis.txt olarak adlandýrýyoruz.
	}
	else { //proje yok durumu.
		cout << "Proje Bulunamadi" << endl;
		ProjeVarMi.close();
		Temp.close();
		remove("temp.txt"); //oluþturulan temp.txt ye bir þey yazmadýðýmýz için siliyoruz. Çünkü proje bulunamadý 
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

	cin >> urunGuncellenecekProjeNo; //hangi projedeki ürünün güncelleneceði bilgisini alýyoruz.

	cout << "Hangi Tarihten Guncellenecek?: ";
	cin >> guncellenecekTarih; //projenin hakediþ tarihini istiyoruz. Çünkü ayný projeye birden fazla hakediþ verilmiþ olabilir.

	while (true) {

		ProjeVarMi >> projeNo >> hakedisTarihi;

		if (ProjeVarMi.eof())break;
		//proje no ve hakediþ tarihi Hakedis.txt dosyasýnda mevcut mu kontrolü
		if (urunGuncellenecekProjeNo == projeNo && hakedisTarihi == guncellenecekTarih) {
			_projeVarMi = true; //proje bulunduysa deðiþkene true atýyoruz.
			break;
		}

		ProjeVarMi.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (_projeVarMi) { //proje varsa çalýþacak kod bloðu

		cout << "Guncellenecek Urun No: ";
		cin >> guncellenecekUrunNo; //güncellenmek istenen ürün numarasýný alýyoruz.
		cout << "Guncel Adet Nedir?: ";
		cin >> guncelAdet; //güncel ürün adedini istiyoruz

		ProjeVarMi.clear();
		ProjeVarMi.seekg(ios::beg); //dosya baþýna gidiyoruz

		char ch;
		string kontrol = "";
		while (true) {

			ProjeVarMi >> projeNo;


			if (ProjeVarMi.eof())break;

			Temp << projeNo;

			_tarihTutucu = ""; //hakediþ tarihini tutacak deðiþken
			_sayac = 0; //boþluk sayacý

			while (ProjeVarMi >> noskipws >> ch) {
				Temp << ch;
				if (ch != ' ') { //karakter boþluk olmadýðý sürece gördüðü karakteri deðiþkene ekliyoruz
					_tarihTutucu += ch;
				}
				if (ch == ' ') _sayac++;

				if (_sayac >= 2)break;
			}
			//proje numarasý ve hakediþ tarihi eþleþme saðlandý mý kontrolü
			if (projeNo == urunGuncellenecekProjeNo && _tarihTutucu == guncellenecekTarih) {
				_boslukSayici = 0;

				while (ProjeVarMi >> noskipws >> ch) {

					if (ch != ' ') { //boþluk olmadýðý sürece string deðiþkene karakteri ekliyoruz
						kontrol += ch;
					}

					if (ch == ' ') {
						_boslukSayici++;
						if (kontrol == guncellenecekUrunNo && _boslukSayici % 3 == 1) { //ürün adeti veya fiyatý ile güncellenecek ürün no ayný satýrda bulunursa tekrar iþleme girmesin diye
																				//yani ürün adet veya fiyat ürün no gibi algýlanmasýn diye boþluk sayýsý kontrolü yaptým.
							int boslukSayac = 0;
							Temp << kontrol; //kontrol deðiþkeninde ürün numarasý tutulduðu için onu direkt yazýyoruz.
							kontrol = ""; //kontrol deðiþkenini sýfýrlýyoruz.
							while (ProjeVarMi >> noskipws >> ch) {

								if (ch != ' ') { //boþluk görmediði sürece kontrol deðiþkenine karakteri ekliyoruz.
									kontrol += ch;
								}
								if (ch == ' ' || ch == '\n') {
									_boslukSayici++;
									boslukSayac++;
									if (boslukSayac == 1) { //boþluk gördüðünde yani ürün adedini okuma iþlemi bittiðinde
										Temp << ch << guncelAdet; //boþluðu ve güncel adeti dosyaya yazýyoruz bu sayede güncellenmiþ oluyor.
									}
									else { //boþluk sayac 1 olmadýðýnda yani ürün adeti kýsmýnda olmadýðýmýzda ise boþluk ve kontrol deðiþkenini yazýyoruz bir de boþluk atarak iþlemi düzgün
										//bir þekilde tamamlýyoruz.
										Temp << ch<<kontrol<<" ";
									}
									kontrol = "";
								}							

								if (boslukSayac == 2) { //burada demek istenen ürünle ilgili bilgiler bitince durumu
									if (ch == '\n') {
										Temp << ch; //eðer dosya sonuysa bunu dosyaya yazýyoruz
									}
									break; //döngüden çýkýyoruz.
								}

							}
						}
						else { //eðer silinecek ürün numarasý ile eþleþme saðlanmazsa dosyaya kontrol deðiþkenindeki deðeri yazýyoruz devam ediyoruz.
							Temp << kontrol << " ";
						}
						kontrol = ""; //kontrol deðiþkeni sýfýrlanýyor
					}

					if (ch == '\n') {

						Temp << kontrol;

						break;
					}
				}
			}
			else { //proje no ve hakediþ tarihi eþleþmeme durumu
				while (ProjeVarMi >> noskipws >> ch) {

					Temp << ch;
					//satýr sonuna kadar dosyaya direkt yazýyoruz. satýr sonuna gelince döngüden çýkýyoruz 
					//tekrardan baþa dönerek kontrolleri tekrarlýyoruz.
					if (ch == '\n')
					{
						break;
					}
				}
			}

		}
		ProjeVarMi.close();

		Temp.close();

		remove("Hakedis.txt"); //eski dosyayý siliyoruz

		rename("temp.txt", "Hakedis.txt"); //güncel temp.txt dosyasýný Hakedis.txt olarak adlandýrýyoruz.
	}
	else { //proje yok durumu.
		cout << "Proje Bulunamadi" << endl;
		ProjeVarMi.close();
		Temp.close();
		remove("temp.txt"); //oluþturulan temp.txt ye bir þey yazmadýðýmýz için siliyoruz. Çünkü proje bulunamadý 
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

		cout << "Hangi Projenin Urunleri Listelenecek ? Proje No: "; //proje numarasý isteniyor
		cin >> listelenecekProjeNo;
		cout << "Projenin Hakedis Tarihi Nedir? :"; //projenin hakediþ tarihi isteniyor
		cin >> _hakedisTarih;

		while (true) {

			HakedisListele >> _projectNo >> _hakedis;

			if (HakedisListele.eof())break;
			//kullanýcýnýn girdiði bilgilerle eþleþme saðlanma kontrolü
			if (listelenecekProjeNo == _projectNo&&_hakedis==_hakedisTarih) {
				projeVarmi = true;
			}
			HakedisListele.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (projeVarmi) {

			cout << "/(Urun No - Kullanilan Urun Adedi - Birim Fiyati)/" << endl;

			HakedisListele.clear();
			HakedisListele.seekg(ios::beg); //dosya baþýna gidiliyor.

			while (true) {
				HakedisListele >> _projectNo;

				if (HakedisListele.eof())break;

				tarihHesaplama = "";
				tarihSayac = 0;
				//hakediþ tarihini bulma döngüsü
				while (HakedisListele >> noskipws >> _ch) {

					if (_ch != ' ') {
						tarihHesaplama += _ch;
					}
					if (_ch == ' ') tarihSayac++;

					if (tarihSayac >= 2)break;
				}

				//proje numarasý ve hakediþ tarihi eþleþen satýra gelindi mi kontrolü
				if (_projectNo == listelenecekProjeNo && tarihHesaplama==_hakedisTarih) {

					while (HakedisListele >> noskipws >> _ch) { //ürün no,kullanýlan adet,fiyat bilgileri yazdýrýlýyor

						if (_ch == '\n')
						{
							cout << endl;
							cout << "Baska Listeleme Yapacak Misiniz ?(e/h)";
							cin >> cevap;
							break;
						}

						cout << _ch;

					}
					break;//listeleme yapýldýðý için döngüden çýkýyoruz.
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

		cout << "Hangi Projeye Ait Urun Aranacak? Proje No: "; //proje numarasý isteniyor
		cin >> aranacakProje;
		cout << "Projenin Hakedis Tarihi?: "; //projenin hakediþ tarihi isteniyor
		cin >> hangiTarih;

		ifstream ProjeKontrol("Hakedis.txt");

		while (true) {
			ProjeKontrol >> projeNo >>hakedisTarihi;

			if (ProjeKontrol.eof())break;
			//proje mevcut mu kontrolü
			if (projeNo == aranacakProje&&hakedisTarihi==hangiTarih) {
				projeMevcut = true;
				break;
			}

			ProjeKontrol.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (projeMevcut) { //proje mevcutsa çalýþacak kod bloðu
			ProjeKontrol.clear();
			ProjeKontrol.seekg(ios::beg); //dosya baþýna gidiliyor

			cout << "Aranacak Urun No: "; //aranacak ürün no isteniyor.
			cin >> aranacakUrun;

			while (true) {
				ProjeKontrol >> projeNo;

				if (ProjeKontrol.eof())break;

				_tarihTutucu = "";
				_sayac = 0;
				boslukSayici = 0;
				//hakediþ tarihi hesaplama döngüsü
				while (ProjeKontrol >> noskipws >> ch) {

					if (ch != ' ') {
						_tarihTutucu += ch;
					}
					if (ch == ' ') _sayac++;

					if (_sayac >= 2)break;
				}
				//hakediþ tarihi ve proje no eþleþmesi saðlanýyor mu kontrolü
				if (projeNo == aranacakProje&&_tarihTutucu==hangiTarih) {

					while (ProjeKontrol >> noskipws >> ch) {

						if (ch == '\n')break;

						if (ch != ' ') { //karakter boþluk olmadýðý sürece kelime deðiþkenine atýyoruz
							kelime += ch;
						}
						if (ch == ' ') { //boþluk görünce kelime deðiþkenini ve aranacak ürünü birbirlerine eþit mi diye kontrol ediyoruz
							boslukSayici++;
							if (kelime == aranacakUrun&&boslukSayici%3==1) { //boþluk sayacýnýn 3 e göre modu 1 olmalý çünkü kelime ürün no ile karþýlaþtýrýlmalý.
									//örneðin kullanýlan ürün adedi 351 ise ve aranan ürün numarasý da 351 ise bu koþul saðlanýr bunu engellemek için boþluk sayacýyla kontrolü ekliyorum.
								//bu sayede karþýlaþtýrýlan deðerlerin ürün numarasý olduðundan emin oluyorum.
								ifstream UrunOku("Urunler.txt");

								while (true) { //bulunan ürünün bilgileri Urunler.txt dosyasýndan çekiliyor.
									UrunOku >> urunNo >> urunAdi >> birim >> birimFiyati >> marka;

									if (UrunOku.eof())break;

									if (urunNo == atoi(aranacakUrun.c_str())) { //aranacakUrun stringini integer a çevirip ürün no ile karþýlaþtýrýyorum.
										urunMevcut = true;
										//ürün bilgilerini yazdýrýyoruz. ve ürün bulundu bilgisini veriyoruz.
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
							kelime = ""; //eþleþme olmuyorsa kelimeyi sýfýrlýyoruz ve kontrol tekrardan baþlýyor.
						}
					}
					if (urunMevcut == false) { //ürünün bulunmama durumu
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
				cout << " -> Tutar: " << geciciTutar << "TL" << endl; //projeye ait tutar yazdýrýlýyor.
				geciciTutar = 0;
				break;

			}
			cout << ch; 

			if (ch == ' ') {
				boslukSayaci++;
			}
			//aþaðýdaki kontrol proje no ve hakediþ tarihini geçti mi kontrolü
			if (boslukSayaci >= 3 && boslukSayaci % 3 == 0) {

				while (Raporla >> noskipws >> ch) {
					cout << ch;

					if (ch == '\n')break;

					if (ch != ' ') { //ürün adeti okunuyor
						adet += ch;
					}
					if (ch == ' ') {
						boslukSayaci++;
						while (Raporla >> noskipws >> ch) {
							cout << ch;

							if (ch == '\n')break;

							if (ch != ' ') { //ürün fiyatý okunuyor.
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
				toplamTutar += (atof(fiyat.c_str()) * atof(adet.c_str())); //fiyat ve adet double a dönüþtürülüyor ve çarpýlarak double toplamTutar deðiþkenine atanýyor.
				geciciTutar += (atof(fiyat.c_str()) * atof(adet.c_str())); //fiyat ve adet double a dönüþtürülüyor ve çarpýlarak double geciciTutar deðiþkenine atanýyor.
				fiyat = ""; //fiyat deðiþkeni sýfýrlanýyor.
				adet = ""; //adet deðiþkeni sýfýrlanýyor.
			}


		}

	}
	cout << "Toplam Tutar: " << toplamTutar << "TL" << endl << endl; //toplam tutar yazdýrýlýyor.
	Raporla.close();
}