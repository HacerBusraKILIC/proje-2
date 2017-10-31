#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Ogrenci
{
    int Ogr_no;
    char OgrNo[8];
    char ad[25];
    char soyad[25];
    char kayitSirasi[10];
    char ogretimTuru[5];
};

int eskiKayitI=0, eskiKayitII=0;


int main()
{
    time_t basla, son;
    time(&basla);

    int elemansayisi=1;
    struct Ogrenci * liste = (struct Ogrenci *)malloc(elemansayisi*sizeof(struct Ogrenci));
    struct Ogrenci * ONoListe = (struct Ogrenci *)malloc(elemansayisi*sizeof(struct Ogrenci));

    int i=0, j=0, k=0, listeUzunlugu=0, yedek;

    FILE *dosya = fopen("D:\\Serhan\\ornek_ogrenci_kayit_bilgileri.txt", "r"); // dosyayi ac
    FILE *yazilan_dosya = fopen("D:\\Serhan\\ornek_ogrenci_kayit_bilgileri_sirali.txt", "w"); // yazilacak dosyayi ac

    if (dosya == NULL)   // dosyaya erisilemiyorsa NULL olur
    {
        printf("dosya acilamadi\n");
        exit(1);
    }
    else
    {
        char temp[500];
        fgets(temp,500,dosya);
        printf("%s",temp);
        while( !feof(dosya)  )  // dosya sonu kontrolu.
        {
            fscanf( dosya,"%s %s %s %s %s",liste[i].OgrNo, liste[i].ad, liste[i].soyad, liste[i].kayitSirasi, liste[i].ogretimTuru );
            elemansayisi++;
            liste = realloc(liste,elemansayisi*sizeof(struct Ogrenci));
            printf( "%d) %-10s  %-10s  %-10s  %10s  %-10s\n", listeUzunlugu+1, liste[i].OgrNo, liste[i].ad, liste[i].soyad,liste[i].kayitSirasi, liste[i].ogretimTuru );
            i++;
            listeUzunlugu++;
        }

        printf("Kisi sayisi %d\n", listeUzunlugu);


    }

    int a = 1;
    //kisilerin karsilastirmalari
    printf("Ismi tekrar edilenler\n");
    int tekraredenler=0;
    int tekrarlikayitnO[tekraredenler];
    for(i=0; i<listeUzunlugu; i++)
    {

        for(a=i+1; a<listeUzunlugu; a++)
        {
            if( ( (strcmp(liste[i].ad, liste[a].ad)) == 0) && ( (strcmp(liste[i].soyad, liste[a].soyad)) == 0) )
            {

                tekraredenler++;
                printf( "%d) %s %s %s %s %s\n", i, liste[i].OgrNo, liste[i].ad, liste[i].soyad, liste[i].kayitSirasi, liste[i].ogretimTuru );
                strcpy(liste[a].OgrNo, " ");
                strcpy(liste[a].ad, " ");
                strcpy(liste[a].soyad, " ");
                strcpy(liste[a].ogretimTuru, " ");
                printf("%d) %s  %s  (%s, %s)  %s\n", a, liste[a].OgrNo, liste[a].ad, liste[a].soyad, liste[a].kayitSirasi, liste[a].ogretimTuru );



                printf("%s\n",liste[a].kayitSirasi);


                  /*for(k=0;k<listeUzunlugu;k++)
                {

                if(atoi(liste[a].kayitSirasi)!=-1 && atoi(liste[a].kayitSirasi)<atoi(liste[k].kayitSirasi)){

                int sayi=atoi(liste[k].kayitSirasi);

                sayi--;

                    sprintf(liste[k].kayitSirasi,"%d",sayi);

                }
                }

                strcpy(liste[a].kayitSirasi,"-1");*/
            }

        }

    }
    tekraredenler--;
    printf("%d\n", tekraredenler);


    int artis = 0;
    for(i=0; i<listeUzunlugu; i++)
    {
        if ( strcmp(liste[i].ad, " ") == 0 )
        {
            strcpy( liste[i].OgrNo, liste[(listeUzunlugu-1)-artis].OgrNo );
            strcpy( liste[i].ad, liste[(listeUzunlugu-1)-artis].ad );
            strcpy( liste[i].soyad, liste[(listeUzunlugu-1)-artis].soyad );
            strcpy( liste[i].kayitSirasi, liste[(listeUzunlugu-1)-artis].kayitSirasi );
            strcpy( liste[i].ogretimTuru, liste[(listeUzunlugu-1)-artis].ogretimTuru );
            artis++;
        }
    }


    /*liste = realloc(liste,(elemansayisi-tekraredenler)*sizeof(struct Ogrenci));
    printf("%d\n", (elemansayisi-tekraredenler) );
    for(i=0; i<(elemansayisi); i++)
    {

        printf( "%d) %-10s  %-10s  %-10s  %10s  %-10s\n", i, liste[i].OgrNo, liste[i].ad, liste[i].soyad, liste[i].kayitSirasi, liste[i].ogretimTuru );

    }*/

    /*for(i=0; i<listeUzunlugu-tekraredenler; i++)
    {
        printf( "%d) %-10s  %-10s  %-10s  %10s  %-10s\n", i+1, liste[i].OgrNo, liste[i].ad, liste[i].soyad,liste[i].kayitSirasi, liste[i].ogretimTuru );
    }*/


    int kayitDizisi[listeUzunlugu];
    int O_No;
    int eleman=0;
    for(i=0; i<(listeUzunlugu-tekraredenler); i++)
    {
        if( (atoi(liste[i].kayitSirasi) == 0)   )
        {
            O_No =  atoi(liste[i].OgrNo);
            kayitDizisi[eleman] = O_No;
        }
        else
        {
            kayitDizisi[eleman] = atoi(liste[i].kayitSirasi);

        }
        printf( "%s) %d\n",liste[i].kayitSirasi,   kayitDizisi[eleman] );
        eleman++;
    }


    listeUzunlugu-=tekraredenler;
    int sirali=1, l = 0;
    while( sirali )
    {
        sirali = 0;
        l++;
        for(j=0; j<listeUzunlugu-l; j++)
        {
            if( kayitDizisi[j] == 0)
            {
                // sifir ise bisey yapilmasin
            }
            else
            {
                if( kayitDizisi[j] > kayitDizisi[j+1] )
                {
                    yedek = kayitDizisi[j];
                    kayitDizisi[j] = kayitDizisi[j+1];
                    kayitDizisi[j+1] = yedek;
                    sirali = 1;
                }
            }
        }
    }

    ONoListe = realloc(ONoListe,elemansayisi*sizeof(struct Ogrenci));
    int sayacI=0, sayacII=0;

    /*for(j=0; j<listeUzunlugu; j++){
        printf("%d(%d): \n", kayitDizisi[j], j);
    }*/

    ///Ogrenci numara atamasi
    for(j=0; j<(listeUzunlugu); j++)
    {
        for(i=0; i<(listeUzunlugu); i++)
        {
            if( kayitDizisi[j] == atoi(liste[i].kayitSirasi) )
            {
                if( strcmp(liste[i].ogretimTuru, "I") == 0 )
                {
                    sayacI++;
                    ONoListe[i].Ogr_no = 17001000 + sayacI;
                    strcpy(ONoListe[i].ad, liste[i].ad);
                    strcpy(ONoListe[i].soyad, liste[i].soyad);
                    strcpy(ONoListe[i].kayitSirasi, liste[i].kayitSirasi);
                    strcpy(ONoListe[i].ogretimTuru, liste[i].ogretimTuru);

                }
                else if( strcmp(liste[i].ogretimTuru, "II") == 0 )
                {
                    sayacII++;
                    ONoListe[i].Ogr_no = 17002000 + sayacII;
                    strcpy(ONoListe[i].ad, liste[i].ad);
                    strcpy(ONoListe[i].soyad, liste[i].soyad);
                    strcpy(ONoListe[i].kayitSirasi, liste[i].kayitSirasi);
                    strcpy(ONoListe[i].ogretimTuru, liste[i].ogretimTuru);
                }

            }
             else if( kayitDizisi[j] == atoi(liste[i].OgrNo) )
                {
                ONoListe[i].Ogr_no = atoi(liste[i].OgrNo);
                strcpy(ONoListe[i].ad, liste[i].ad);
                strcpy(ONoListe[i].soyad, liste[i].soyad);
                strcpy(ONoListe[i].kayitSirasi, liste[i].kayitSirasi);
                strcpy(ONoListe[i].ogretimTuru, liste[i].ogretimTuru);

                if( strcmp(liste[i].ogretimTuru, "I") )
                {
                    eskiKayitI++;
                }
                else
                {
                    eskiKayitII++;
                }


                }
        }
    }



    ///OgrNo ya göre siralama
    sirali=1, l = 0;

    for(i=0; i<listeUzunlugu; i++)
    {
        kayitDizisi[i] = ONoListe[i].Ogr_no;
    }

    while( sirali )
    {
        sirali = 0;
        l++;
        for(j=0; j<listeUzunlugu-l; j++)
        {
            if( kayitDizisi[j] > kayitDizisi[j+1] )
            {
                yedek = kayitDizisi[j];
                kayitDizisi[j] = kayitDizisi[j+1];
                kayitDizisi[j+1] = yedek;
                sirali = 1;
            }
        }
    }

    for(j=0; j<(listeUzunlugu); j++)
    {
        for(i=0; i<(listeUzunlugu); i++)
        {
            if( kayitDizisi[j] == ONoListe[i].Ogr_no )
            {
                ONoListe[j].Ogr_no = kayitDizisi[j];
                strcpy( ONoListe[j].ad, ONoListe[j].ad );
                strcpy( ONoListe[j].soyad, ONoListe[j].soyad );
                strcpy( ONoListe[j].kayitSirasi, ONoListe[j].kayitSirasi );
                strcpy( ONoListe[j].ogretimTuru, ONoListe[j].ogretimTuru );

            }
        }
    }

    for(i=0; i<listeUzunlugu; i++)
    {
        printf( "%d) %-10d  %-10s  %-10s  %-10s  %-10s\n", i, ONoListe[i].Ogr_no, ONoListe[i].ad, ONoListe[i].soyad, ONoListe[i].kayitSirasi, ONoListe[i].ogretimTuru );
        //dosyaya yazdirma
        fprintf(yazilan_dosya, "%d) %-10d  %-10s  %-10s  %-10s  %-10s\n" , i+1, ONoListe[i].Ogr_no, ONoListe[i].ad, ONoListe[i].soyad, ONoListe[i].kayitSirasi, ONoListe[i].ogretimTuru );
    }


    //Sinif daðilimlari
    int sinifSayisi, syc=0, topKapasite = 0;
    int sinifKapasite[sinifSayisi];



    printf("Sinif sayisini giriniz.\n");
    scanf("%d", &sinifSayisi);
    printf("Sinif kapasitelerini giriniz.\n");
    for(i=0; i<sinifSayisi; i++)
    {
        scanf("%d", &sinifKapasite[i] );
        topKapasite += sinifKapasite[i];
    }
    for(i=0; i<sinifSayisi; i++)
    {
        printf("%d ", sinifKapasite[i] );
    }
    printf("\n");

    int ogretimI =sayacI+eskiKayitI;
    int ogretimII =sayacII+eskiKayitII;
    printf("Dersi alan 1. ogretim %d ,  2. ogretim %d  kisidir.\n", ogretimI, ogretimII);

    //Esitlik icin
    sirali = 1, l=0;
    while( sirali )
    {
        sirali = 0;
        l++;
        for(j=0; j<sinifSayisi-l; j++)
        {
                if( sinifKapasite[j] > sinifKapasite[j+1] )
                {
                    yedek = sinifKapasite[j];
                    sinifKapasite[j] = sinifKapasite[j+1];
                    sinifKapasite[j+1] = yedek;
                    sirali = 1;
                }
        }
    }
    printf("Siralanmis hali:  ");
    for(i=0; i<sinifSayisi; i++)//siralanmis hali
    {
        printf("%d ", sinifKapasite[i] );
    }
    printf("\n");


    int olusturulanSinifK[sinifSayisi];
    //int topI=0;
    int ortI = ogretimI/sinifSayisi;
    int ortII = ogretimII/sinifSayisi;

    //I.ogretim icin
    for(i=0; i<sinifSayisi; i++){
        for(j=0; j<sinifSayisi; j++){
                if( olusturulanSinifK[j] == sinifKapasite[i] ){
                    olusturulanSinifK[j] += sinifKapasite[i];
                }
        }
    }
    for(i=0; i<sinifSayisi; i++)
    {
        printf("%d ", olusturulanSinifK[i] );
    }
    printf("\n");



    free (liste);
    free (ONoListe);



fclose(dosya);  // dosyayi kapat

time(&son);
printf("Programin calisma zamani %.2lf saniye surdu.", difftime(son,basla));
return 0;
}


