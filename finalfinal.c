#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <conio.h>

struct faturabilgi{
	char firma[20];
	char malhizmet[20];
	int kdv;
	float toplamtutar,birimfiyat,adet;
}fb1;

struct musbilgi{
	
	struct adres{
	char il[15], ilce[15];
	}mb2;
	
    int vergino,telefonno;
    char firmaisim[30];
	
}mb1;

struct irsbilgi{
	
	struct irsadres{
	char il[15], ilce[15];
	}ib2;
	
    int vergino,telefonno;
    char firmaisim[30];
	
}ib1;

FILE *dosya;
FILE *silinenler;



void faturaYaz()
{

	
if(( dosya= fopen("efatura.txt", "a")) ==NULL)
{
printf("Fatura olu�turulamad�");
}
else {
printf("Fatura olu�turuldu, fatura bilgilerini giriniz: \n");

printf("\n\nFirma Ad�: "); scanf("%s", fb1.firma);
printf("\n\nHizmet: "); scanf("%s",fb1.malhizmet);
printf("\n\nBirim fiyat: "); scanf("%f", &fb1.birimfiyat);
printf("\n\nKDV: "); scanf("%d", &fb1.kdv);
printf("\n\nAdet/KG: "); scanf("%f",&fb1.adet);
fb1.toplamtutar=(fb1.birimfiyat*fb1.adet)+(fb1.birimfiyat*fb1.kdv*fb1.adet)/100;

fprintf(dosya, "%s\t%s\t%.2f\t%d\t%.2f\t%.2f\n",fb1.firma,fb1.malhizmet,fb1.birimfiyat,fb1.kdv,fb1.adet,fb1.toplamtutar);
printf("\n\n\nFatura kay�t i�lemi tamamland�. Ar�ivlenmi� Faturalarda g�r�nt�leyebilirsiniz.\n\n");
fclose(dosya);

}
}

void faturaListele() {
    printf("Kesilen Faturalar: \n\n");
    printf("Firma\t\t\t\tMal Hizmet\t\t\tFiyat\t\t\tKDV Oran�\t\tAdet\t\t\tToplam Tutar\n\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    dosya = fopen("efatura.txt", "r"); 

    if (dosya != NULL) {
        while (fscanf(dosya, "%s %s %f %d %f %f\n", &fb1.firma, &fb1.malhizmet, &fb1.birimfiyat, &fb1.kdv, &fb1.adet, &fb1.toplamtutar) == 6) {
            printf("%s\t\t\t\t%s\t\t\t\t%.2f\t\t\t%d\t\t\t%.2f\t\t\t%.2f\n", fb1.firma, fb1.malhizmet, fb1.birimfiyat, fb1.kdv, fb1.adet, fb1.toplamtutar);
            printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }

        printf("\n\nListe Sonu\n");
        fclose(dosya); 
    } else {
        printf("Fatura a��lamad�.\n");
    }
} 


void faturaAra(){

system("cls");

dosya = fopen("efatura.txt", "r"); 
char afi[20];
int bulunamadi=0;
printf("�u firma/�ahsa ait fatura ara: ");
scanf("%s",afi);

printf("\n\n %s Ad�na Kesilen Faturalar:\n\n\n");

printf("Firma\t\t\t\tMal Hizmet\t\t\tFiyat\t\t\tKDV Oran�\t\tAdet\t\t\tToplam Tutar\n\n\n");
printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

if((dosya)!=NULL){

while(!feof(dosya)){
fscanf(dosya, "%s %s %f %d %f %f\n",fb1.firma,fb1.malhizmet,&fb1.birimfiyat,&fb1.kdv,&fb1.adet,&fb1.toplamtutar);
if(strcmp(afi,fb1.firma)==0){
printf("%s\t\t\t\t%s\t\t\t\t%.2f\t\t\t%d\t\t%.2f\t\t\t%.2f\n", fb1.firma, fb1.malhizmet, fb1.birimfiyat, fb1.kdv, fb1.adet, fb1.toplamtutar);
printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

fclose(dosya);
bulunamadi=1;
break;
}

}

printf("\n\nListe Sonu");
fclose(dosya);
if(bulunamadi==0){

printf("\n\n%s ad�na kesilmi� fatura bulunamad�.\n\n",afi);
}
}

}


int main(int argc, char *argv[]) {


setlocale(LC_ALL, "Turkish");

faturaotomasyonu:;

printf("\n\n\n\n");
printf("                                                  **********************************************************\n");
printf("                                                  *                                                        *\n");
printf("                                                  *                                                        *\n");
printf("                                                  *                            *                           *\n");
printf("                                                  *                          *   *                         *\n");
printf("                                                  *                        *       *                       *\n");
printf("                                                  *                      *   SRSS    *                     *\n");
printf("                                                  *                        *       *                       *\n");
printf("                                                  *                          *   *                         *\n");
printf("                                                  *                            *                           *\n");
printf("                                                  *                                                        *\n");
printf("                                                  *                                                        *\n");
printf("                                                  *                    E-FATURA OTOMASYONU                 *\n");
printf("                                                  *                                                        *\n");
printf("                                                  *                                                        *\n");
printf("                                                  **********************************************************");



sleep(3);
system("cls");

nasil:;


int tus;

printf("\n\n\n");
printf("                                                  **********************************************************\n");
printf("                                                  *                   NASIL KULLANILIR?                    *\n");
printf("                                                  *                                                        *\n");
printf("                                                  * ��kacak ilk men�de kay�t olup giri� yap�l�r.           *\n");
printf("                                                  * ��lemler aras�nda geri d�nmek i�in 0(s�f�ra) basman�z  *\n");
printf("                                                  * yeterlidir. Herhangi bir i�lemi yapmak i�in i�lemin    *\n");
printf("                                                  * solundaki numaray� girdikten sonra enter tu�una bas�-  *\n");
printf("                                                  * n�z. Y�nlendirildi�iniz ekran yapmak istedi�iniz i�le- *\n");
printf("                                                  * min ekran� olacakt�r.                                  *\n");
printf("                                                  *                                                        *\n");
printf("                                                  *           KILAVUZU GE�MEK ���N 0'A ARDINDAN            *\n");
printf("                                                  *                 ENTER TU�UNA BASINIZ.                  *\n");
printf("                                                  *                                                        *\n");
printf("                                                  **********************************************************\n\n\n");



printf("\n\n\n");
printf("                                                                          Se�im: ");
scanf("%d", &tus);




if(tus==0) {

system("cls");

int menusecim;

menuekrani:;

printf("\n\n\n\n\n\n");
printf("                                                  ***********************************************************\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                           MEN�                          *\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                       1- Giri� Yap                      *\n");
printf("                                                  *                       2- Kay�t Ol                       *\n");
printf("                                                  *                       3- ��k�� Yap                      *\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                                                         *\n");
printf("                                                  ***********************************************************\n");

printf("\n\n\n");
printf("                                                                             Se�im: ");
scanf("%d", &menusecim);


system("cls");

if(menusecim==1) {


char kullanici[20];
    int sifre;
        kullanicigirisi:;
   
   printf("\n\n\n\n\n\n");
  printf("                                                                    Kay�tl� Kullan�c� Giri�i\n\n\n\n");

  printf("                                                                    Kullan�c� Ad�: ");
  scanf("%s", kullanici);
  printf("\n\n");
  printf("                                                                    �ifre: ");
  scanf("%d", &sifre);
   
    FILE *usersign;

  if ((usersign = fopen("kullanicikayit.txt", "r")) == NULL) {
    printf("\n\nKay�t olu�turulamad�.");
  } else {
    char kullaniciadi[25];
    int sifrekayit;

    int Eslestirme = 0;

    while (!feof(usersign)) {
      fscanf(usersign, "%s\t%d\n", kullaniciadi, &sifrekayit);

      if (strcmp(kullanici, kullaniciadi) == 0 && sifre == sifrekayit) {
        Eslestirme = 1; 
        break;
      }
    }

    fclose(usersign);

    if (!Eslestirme) {
      printf("\n\n\n                                                   Kullan�c� ad� ya da �ifre hatal�.");
      sleep(3);
      system("cls");
      goto kullanicigirisi;
    } else {
    	
    	system("cls");
    	
    giris:;
	printf("\n\n\n");

    printf("                                                                 Ho� geldiniz, %s.", kullanici);
    int islem;
    printf("\n\n\n\n\n");
    printf("                                                                 1- M��teri Kay�t \n\n");
    printf("                                                                 2- E-Fatura Olu�tur \n\n");
    printf("                                                                 3- Ar�ivlenmi� Faturalar \n\n");
    printf("                                                                 4- Fatura Ara \n\n");
    printf("                                                                 5- �ptal Edilen Faturalar \n\n");
       
        printf("\n\n");

        printf("Se�im: ");
        scanf("%d", &islem);
       
        system("cls");

        if (islem == 1) {
            int secim;
            musterikaydi:;

            printf("\n\n                                                                M��teri Kayd� Olu�tur \n\n\n");
            printf("1- E-Fatura i�in Olu�tur \n\n");
            printf("2- E-�rsaliye i�in Olu�tur \n\n");
            printf("0- Anasayfa \n\n");
            printf("Se�im: ");
            scanf("%d", &secim);
            while(secim==0){
           
            system("cls");
            goto giris;
}

system("cls");


            switch (secim) {
            case 1: printf("\n\n                                                                  E-Fatura Olu�tur\n\n\n\n");
           
            faturaolustur:;
           
           
printf("Firma/�ah�s Bilgisi\n\n\n");
printf("Vergi Numaras�: ");
scanf("%d",&mb1.vergino);
if(mb1.vergino<1000000000 || mb1.vergino>9999999999){
printf("Bu numaraya kay�tl� firma/�ah�s yok.");
sleep(3);
system("cls");
goto faturaolustur;
}
else{
goto firmaadi;
}

firmaadi:;

printf("\n\n");
printf("Firma ad�: ");
scanf("%s", mb1.firmaisim);

printf("\n\n");
printf("Firma il: ");
scanf("%s", mb1.mb2.il);
printf("Firma il�e: ");
scanf("%s", mb1.mb2.ilce);

printf("\n\n");
printf("Telefon numaras�: ");
scanf("%d",&mb1.telefonno);

printf("Kay�t olu�turuldu.");
sleep(3);
system("cls");


goto musterikaydi;
break;

            case 2: printf("\n\n                                                                 E-�rsaliye Olu�tur\n\n\n\n");
           
irsaliyeolustur:;
           
           
printf("Firma/�ah�s Bilgisi\n\n\n");
printf("Vergi Numaras�: ");
scanf("%d",&ib1.vergino);
if(ib1.vergino<1000000000 || ib1.vergino>9999999999){
printf("Bu numaraya kay�tl� firma/�ah�s yok.");
sleep(3);
system("cls");
goto irsaliyeolustur;
}
else{
goto firmaismi;
}

firmaismi:;

printf("\n\n");
printf("Firma ad�: ");
scanf("%s", ib1.firmaisim);

printf("\n\n");
printf("Firma il: ");
scanf("%s", ib1.ib2.il);
printf("Firma il�e: ");
scanf("%s", ib1.ib2.ilce);

printf("\n\n");
printf("Telefon numaras�: ");
scanf("%d",&ib1.telefonno);

printf("Kay�t olu�turuldu.");
sleep(3);
system("cls");


goto musterikaydi;
break;
            default: system("cls"); goto giris; break;
            }
     


        } else if (islem == 2) {

            printf("\n\n                                                                   E- FATURA OLU�TUR\n\n ");
            
            int i,j;
            
            printf("\n\nKa� fatura olu�turmak istersiniz?: ");
            scanf("%d",&j);
            
            for(i=0;i<j;i++){
			
            faturaYaz();
            
            }
           
            int secimmm;
           
            printf("\n\n\nGeri d�nmek i�in 0'a bas�n�z.");
            scanf("%d",&secimmm);
           
            while(secimmm==0){
           
            system("cls");
            goto giris;
}
           
}

   else if (islem == 3) {

        printf("\n\n                                                                       AR��VLENM�� BELGELER\n");
        printf("\n\n");
        faturaListele();
       
        int option;
        printf("\n\nGeri d�nmek i�in 0'a bas�n�z: ");
        scanf("%d",&option);
       
        while(option==0){
       
        system("cls");
        goto giris;
}
               
        }
   


else if (islem == 4) {
            printf("\n\n                                                                   FATURA ARA\n\n\n");

            faturaAra();
           
            int option2;
            printf("\n\nGeri d�nmek i�in 0'a bas�n�z: ");
            scanf("%d",&option2);
           
            while(option2==0){
           
            system("cls");
            goto giris;
}
           
        }


else if (islem ==5 ) {
           int secenek;
              printf("\n\n                                                                 �PTAL ED�LEN FATURALAR");
              
              printf("\n\n\n");
              
            printf("Firma\t\t\tMal Hizmet\t\tFiyat\t\tKDV Oran�\tAdet\t\tToplam Tutar\n\n");
            printf("ruken\t\t\tyemek\t\t500,00\t\t20\t20,00\t\t492,00\n");
            printf("saliha\t\t\tula��m\t\t156\t\t20\t12,00\t\t374,40\n");
            printf("g�l�mser\t\t\tila�\t\t1235,00\t\t20\t80,00\t\t19760,00\n");
            printf("s�meyyeto\t\tdsfdsbh\t\t96,00\t\t20\t63,00\t\t1209,60\n");
            printf("s�meyyege\t\tdfjskfkds\t\t74,00\t\t20\t32,00\t\t473,60\n");

            printf("\n\n\nListe sonu. Geri d�nmek i�in 0'a bas�n�z.");
            scanf("%d", &secenek);
            
            
            while(secenek==0){
            	
            	system("cls");
            	goto giris;
			}
            
        }else {
        	
        	printf("\n\n\n");
        	printf("L�tfen yapaca��n�z i�lemin solundaki numaray� giriniz.");
        	sleep(3);
        	system("cls");
            goto giris;
        }
    }

}}

else if(menusecim==2){



char kullaniciadi[25];
int sifre;

FILE *usersign;


if((usersign=fopen("kullanicikayit.txt","a"))==NULL)
{
printf("\n\nKay�t olu�turulamad�.");
}

else{

printf("\n\n\n\n\n");
printf("                                                    ******************************************************\n");
printf("                                                    *                      KAYIT EKRANI                  *\n\n\n");
printf("                                                                  Kullan�c� ad�: ");
scanf("%s", kullaniciadi);



parolaekrani:;

printf("                                                                  �ifre(5 haneli): ");
scanf("%d", &sifre);


if(sifre<10000 || sifre>99999){

printf("\n\n\n                                                L�tfen yaln�zca 5 basamakl� bir rakamlardan olu�an �ifre giriniz.");
sleep(3);
system("cls");
goto parolaekrani;

}

fprintf(usersign,"%s\t%d\n",kullaniciadi,sifre);
fclose(usersign);
int gekranitusu;

printf("                                                     Kullan�c� kayd� ba�ar�yla al�nd�.");
printf("\n");
printf("                                                     Giri� ekran�na d�nmek i�in 0'a bas�n�z: ");

scanf("%d",&gekranitusu);

while(gekranitusu==0){
	
	system("cls");
	goto kullanicigirisi;

}
}

}

else if(menusecim==3){

system("cls");
goto faturaotomasyonu;
}
else if(menusecim!=1 || menusecim!=2 || menusecim!=3){


system("cls");
printf("                                                   ��lemin solundaki numaray� tu�lay�n�z.");
sleep(3);
goto menuekrani;
}

}


else if(tus=!0){

system("cls");
goto nasil;

}

return 0;
}

