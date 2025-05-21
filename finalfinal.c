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
printf("Fatura oluþturulamadý");
}
else {
printf("Fatura oluþturuldu, fatura bilgilerini giriniz: \n");

printf("\n\nFirma Adý: "); scanf("%s", fb1.firma);
printf("\n\nHizmet: "); scanf("%s",fb1.malhizmet);
printf("\n\nBirim fiyat: "); scanf("%f", &fb1.birimfiyat);
printf("\n\nKDV: "); scanf("%d", &fb1.kdv);
printf("\n\nAdet/KG: "); scanf("%f",&fb1.adet);
fb1.toplamtutar=(fb1.birimfiyat*fb1.adet)+(fb1.birimfiyat*fb1.kdv*fb1.adet)/100;

fprintf(dosya, "%s\t%s\t%.2f\t%d\t%.2f\t%.2f\n",fb1.firma,fb1.malhizmet,fb1.birimfiyat,fb1.kdv,fb1.adet,fb1.toplamtutar);
printf("\n\n\nFatura kayýt iþlemi tamamlandý. Arþivlenmiþ Faturalarda görüntüleyebilirsiniz.\n\n");
fclose(dosya);

}
}

void faturaListele() {
    printf("Kesilen Faturalar: \n\n");
    printf("Firma\t\t\t\tMal Hizmet\t\t\tFiyat\t\t\tKDV Oraný\t\tAdet\t\t\tToplam Tutar\n\n\n");
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
        printf("Fatura açýlamadý.\n");
    }
} 


void faturaAra(){

system("cls");

dosya = fopen("efatura.txt", "r"); 
char afi[20];
int bulunamadi=0;
printf("Þu firma/þahsa ait fatura ara: ");
scanf("%s",afi);

printf("\n\n %s Adýna Kesilen Faturalar:\n\n\n");

printf("Firma\t\t\t\tMal Hizmet\t\t\tFiyat\t\t\tKDV Oraný\t\tAdet\t\t\tToplam Tutar\n\n\n");
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

printf("\n\n%s adýna kesilmiþ fatura bulunamadý.\n\n",afi);
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
printf("                                                  * Çýkacak ilk menüde kayýt olup giriþ yapýlýr.           *\n");
printf("                                                  * Ýþlemler arasýnda geri dönmek için 0(sýfýra) basmanýz  *\n");
printf("                                                  * yeterlidir. Herhangi bir iþlemi yapmak için iþlemin    *\n");
printf("                                                  * solundaki numarayý girdikten sonra enter tuþuna basý-  *\n");
printf("                                                  * nýz. Yönlendirildiðiniz ekran yapmak istediðiniz iþle- *\n");
printf("                                                  * min ekraný olacaktýr.                                  *\n");
printf("                                                  *                                                        *\n");
printf("                                                  *           KILAVUZU GEÇMEK ÝÇÝN 0'A ARDINDAN            *\n");
printf("                                                  *                 ENTER TUÞUNA BASINIZ.                  *\n");
printf("                                                  *                                                        *\n");
printf("                                                  **********************************************************\n\n\n");



printf("\n\n\n");
printf("                                                                          Seçim: ");
scanf("%d", &tus);




if(tus==0) {

system("cls");

int menusecim;

menuekrani:;

printf("\n\n\n\n\n\n");
printf("                                                  ***********************************************************\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                           MENÜ                          *\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                       1- Giriþ Yap                      *\n");
printf("                                                  *                       2- Kayýt Ol                       *\n");
printf("                                                  *                       3- Çýkýþ Yap                      *\n");
printf("                                                  *                                                         *\n");
printf("                                                  *                                                         *\n");
printf("                                                  ***********************************************************\n");

printf("\n\n\n");
printf("                                                                             Seçim: ");
scanf("%d", &menusecim);


system("cls");

if(menusecim==1) {


char kullanici[20];
    int sifre;
        kullanicigirisi:;
   
   printf("\n\n\n\n\n\n");
  printf("                                                                    Kayýtlý Kullanýcý Giriþi\n\n\n\n");

  printf("                                                                    Kullanýcý Adý: ");
  scanf("%s", kullanici);
  printf("\n\n");
  printf("                                                                    Þifre: ");
  scanf("%d", &sifre);
   
    FILE *usersign;

  if ((usersign = fopen("kullanicikayit.txt", "r")) == NULL) {
    printf("\n\nKayýt oluþturulamadý.");
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
      printf("\n\n\n                                                   Kullanýcý adý ya da þifre hatalý.");
      sleep(3);
      system("cls");
      goto kullanicigirisi;
    } else {
    	
    	system("cls");
    	
    giris:;
	printf("\n\n\n");

    printf("                                                                 Hoþ geldiniz, %s.", kullanici);
    int islem;
    printf("\n\n\n\n\n");
    printf("                                                                 1- Müþteri Kayýt \n\n");
    printf("                                                                 2- E-Fatura Oluþtur \n\n");
    printf("                                                                 3- Arþivlenmiþ Faturalar \n\n");
    printf("                                                                 4- Fatura Ara \n\n");
    printf("                                                                 5- Ýptal Edilen Faturalar \n\n");
       
        printf("\n\n");

        printf("Seçim: ");
        scanf("%d", &islem);
       
        system("cls");

        if (islem == 1) {
            int secim;
            musterikaydi:;

            printf("\n\n                                                                Müþteri Kaydý Oluþtur \n\n\n");
            printf("1- E-Fatura için Oluþtur \n\n");
            printf("2- E-Ýrsaliye için Oluþtur \n\n");
            printf("0- Anasayfa \n\n");
            printf("Seçim: ");
            scanf("%d", &secim);
            while(secim==0){
           
            system("cls");
            goto giris;
}

system("cls");


            switch (secim) {
            case 1: printf("\n\n                                                                  E-Fatura Oluþtur\n\n\n\n");
           
            faturaolustur:;
           
           
printf("Firma/Þahýs Bilgisi\n\n\n");
printf("Vergi Numarasý: ");
scanf("%d",&mb1.vergino);
if(mb1.vergino<1000000000 || mb1.vergino>9999999999){
printf("Bu numaraya kayýtlý firma/þahýs yok.");
sleep(3);
system("cls");
goto faturaolustur;
}
else{
goto firmaadi;
}

firmaadi:;

printf("\n\n");
printf("Firma adý: ");
scanf("%s", mb1.firmaisim);

printf("\n\n");
printf("Firma il: ");
scanf("%s", mb1.mb2.il);
printf("Firma ilçe: ");
scanf("%s", mb1.mb2.ilce);

printf("\n\n");
printf("Telefon numarasý: ");
scanf("%d",&mb1.telefonno);

printf("Kayýt oluþturuldu.");
sleep(3);
system("cls");


goto musterikaydi;
break;

            case 2: printf("\n\n                                                                 E-Ýrsaliye Oluþtur\n\n\n\n");
           
irsaliyeolustur:;
           
           
printf("Firma/Þahýs Bilgisi\n\n\n");
printf("Vergi Numarasý: ");
scanf("%d",&ib1.vergino);
if(ib1.vergino<1000000000 || ib1.vergino>9999999999){
printf("Bu numaraya kayýtlý firma/þahýs yok.");
sleep(3);
system("cls");
goto irsaliyeolustur;
}
else{
goto firmaismi;
}

firmaismi:;

printf("\n\n");
printf("Firma adý: ");
scanf("%s", ib1.firmaisim);

printf("\n\n");
printf("Firma il: ");
scanf("%s", ib1.ib2.il);
printf("Firma ilçe: ");
scanf("%s", ib1.ib2.ilce);

printf("\n\n");
printf("Telefon numarasý: ");
scanf("%d",&ib1.telefonno);

printf("Kayýt oluþturuldu.");
sleep(3);
system("cls");


goto musterikaydi;
break;
            default: system("cls"); goto giris; break;
            }
     


        } else if (islem == 2) {

            printf("\n\n                                                                   E- FATURA OLUÞTUR\n\n ");
            
            int i,j;
            
            printf("\n\nKaç fatura oluþturmak istersiniz?: ");
            scanf("%d",&j);
            
            for(i=0;i<j;i++){
			
            faturaYaz();
            
            }
           
            int secimmm;
           
            printf("\n\n\nGeri dönmek için 0'a basýnýz.");
            scanf("%d",&secimmm);
           
            while(secimmm==0){
           
            system("cls");
            goto giris;
}
           
}

   else if (islem == 3) {

        printf("\n\n                                                                       ARÞÝVLENMÝÞ BELGELER\n");
        printf("\n\n");
        faturaListele();
       
        int option;
        printf("\n\nGeri dönmek için 0'a basýnýz: ");
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
            printf("\n\nGeri dönmek için 0'a basýnýz: ");
            scanf("%d",&option2);
           
            while(option2==0){
           
            system("cls");
            goto giris;
}
           
        }


else if (islem ==5 ) {
           int secenek;
              printf("\n\n                                                                 ÝPTAL EDÝLEN FATURALAR");
              
              printf("\n\n\n");
              
            printf("Firma\t\t\tMal Hizmet\t\tFiyat\t\tKDV Oraný\tAdet\t\tToplam Tutar\n\n");
            printf("ruken\t\t\tyemek\t\t500,00\t\t20\t20,00\t\t492,00\n");
            printf("saliha\t\t\tulaþým\t\t156\t\t20\t12,00\t\t374,40\n");
            printf("gülümser\t\t\tilaç\t\t1235,00\t\t20\t80,00\t\t19760,00\n");
            printf("sümeyyeto\t\tdsfdsbh\t\t96,00\t\t20\t63,00\t\t1209,60\n");
            printf("sümeyyege\t\tdfjskfkds\t\t74,00\t\t20\t32,00\t\t473,60\n");

            printf("\n\n\nListe sonu. Geri dönmek için 0'a basýnýz.");
            scanf("%d", &secenek);
            
            
            while(secenek==0){
            	
            	system("cls");
            	goto giris;
			}
            
        }else {
        	
        	printf("\n\n\n");
        	printf("Lütfen yapacaðýnýz iþlemin solundaki numarayý giriniz.");
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
printf("\n\nKayýt oluþturulamadý.");
}

else{

printf("\n\n\n\n\n");
printf("                                                    ******************************************************\n");
printf("                                                    *                      KAYIT EKRANI                  *\n\n\n");
printf("                                                                  Kullanýcý adý: ");
scanf("%s", kullaniciadi);



parolaekrani:;

printf("                                                                  Þifre(5 haneli): ");
scanf("%d", &sifre);


if(sifre<10000 || sifre>99999){

printf("\n\n\n                                                Lütfen yalnýzca 5 basamaklý bir rakamlardan oluþan þifre giriniz.");
sleep(3);
system("cls");
goto parolaekrani;

}

fprintf(usersign,"%s\t%d\n",kullaniciadi,sifre);
fclose(usersign);
int gekranitusu;

printf("                                                     Kullanýcý kaydý baþarýyla alýndý.");
printf("\n");
printf("                                                     Giriþ ekranýna dönmek için 0'a basýnýz: ");

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
printf("                                                   Ýþlemin solundaki numarayý tuþlayýnýz.");
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

