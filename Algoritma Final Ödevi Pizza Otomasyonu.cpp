#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>
#include <clocale> 
#include <windows.h>

using namespace std;

struct Pizza
{
	char pizza_no[100];
	char anamadde[100];
	char kenartipi[100];
	char hamurturu[100];
	char malzemeler[100];
	char soscesidi[100];
	char boyut[100];
	int fiyat;
};

Pizza pizza;

void PizzaEkle();
void PizzaListeleme();
void PizzaArama();
void PizzaSil();
void PizzaDuzenle();


int main(){
	
	setlocale(LC_ALL, "Turkish");
	system("Color 0B");
	char anamenu;

	do
	{
	system("cls");

	cout << "##############################################" << endl;
	cout << "#                                            #" << endl;
	cout << "#              Ho� Geldiniz!                 #" << endl;
	cout << "#                                            #" << endl;
	cout << "##############################################" << endl;
	cout << endl;

	cout << "##############################################" << endl;
	cout << "#                                            #" << endl;
	cout << "#           ** Se�im Yap�n�z **              #" << endl;
	cout << "#                                            #" << endl;
	cout << "#           1 - Pizza Ekleme                 #" << endl;
	cout << "#           2 - Pizza Listeleme              #" << endl;
	cout << "#           3 - Pizza Arama                  #" << endl;
	cout << "#           4 - Pizza Silme                  #" << endl;
	cout << "#           5 - Pizza D�zenleme              #" << endl;
	cout << "#                                            #" << endl;
	cout << "##############################################" << endl;
	cout << endl;
    
	char secim;
	cin >> secim;
	
	switch(secim) 
	{
		case '1': 
		{
		PizzaEkle();
		break;	
		}
		case '2': 
		{
		PizzaListeleme();
		break;
		}
		case '3': 
		{
		PizzaArama();
		break;
		}
		case '4': 
		{
		PizzaSil();
		break;
		}
		case '5': 
		{
		PizzaDuzenle();
		break;
		}
	}
	
	cout << "Anamen�ye d�nmek i�in: \'a\' tu�una bas�n, ��kmak i�in \'c\' tu�una bas�n." << endl; 
	anamenu = getche();
	
    } while(anamenu == 'a');
     

return 0;
}

// ----------------------------------------------------------------- //

void PizzaEkle()
{
	setlocale(LC_ALL, "Turkish");
	ofstream yaz("Pizza.dat", ios::binary | ios::app);
	char secim;
	int adet = 0;
	
	do
	{
	cout << "Pizza Numaras�n� Giriniz" << endl;
	cin >> pizza.pizza_no;
	cout << "Pizza Ana Maddesini Giriniz" << endl;
	cin >> pizza.anamadde;
	cout << "Pizzan�n Kenar Tipini Giriniz" << endl;
	cin >> pizza.kenartipi;
	cout << "Pizzan�n Hamur T�r�n� Giriniz" << endl;
	cin >> pizza.hamurturu;
	cout << "Pizzan�n Malzemelerini Giriniz" << endl;
	cin >> pizza.malzemeler;
	cout << "Pizzan�n Sos �e�idini Giriniz" << endl;
	cin >> pizza.soscesidi;
	cout << "Pizzan�n ebat�n� giriniz(k���k/orta/b�y�k)" << endl;
	cin >> pizza.boyut;
	cout << "Pizzan�n fiyat�n� giriniz" << endl;
	cin >> pizza.fiyat;
	
	cout << endl;
	yaz.write((char*)&pizza, sizeof(pizza));	
	adet++;	
	cout << "Ba�ka Pizza Eklemek �ster misiniz? (E/H)" << endl;
	secim = getche();
	cout << endl;
	} while(secim == 'e' || secim == 'E');
	
	cout << adet << " adet Pizza Ekledi!" << endl;
	
	yaz.close();
	
}

// ----------------------------------------------------------------- //
	

void PizzaListeleme()
{
	setlocale(LC_ALL, "Turkish");
	
	ifstream oku("Pizza.dat", ios::binary | ios::app);
	
	oku.seekg(0, ios::end);
	int kayits = oku.tellg() / sizeof(pizza);
	
	// kontrol etmek i�in cout << oku.tellg(); yaz�p de�eri g�r�p cout << sizeof(pizza); yaz�p de�eri g�r�p b�l�m�n� hesaplayabiliriz.
	
	cout << "Toplam Mevcut Pizza Say�s�:"<< kayits << endl;
	
	if(kayits > 0) 
	{
		for(int i = 0; i < kayits; i++) 
		
		{
			oku.seekg(i*sizeof(pizza));
			oku.read((char*)&pizza, sizeof(pizza));	
			cout << "----------------------------------" << endl;
			cout << i+1 << ". Pizzanin Bilgileri"<< endl;
			cout << "Pizzan�n Ana Maddesi: "<< pizza.anamadde << endl;
			cout << "Pizzan�n Kenar Tipi: "<< pizza.kenartipi << endl;
			cout << "Pizzan�n Hamur T�r�: "<< pizza.hamurturu << endl;
			cout << "Pizzan�n ��indeki Malzemeleri: "<< pizza.malzemeler << endl;
			cout << "Pizzan�n Sos �e�itleri: "<< pizza.soscesidi << endl;
			cout << "Pizzan�n Boyutu: "<< pizza.boyut << endl;
			cout << "Pizzan�n Fiyat�: "<< pizza.fiyat << endl;
		}
	}
	else 
	{
		cout << "Kayit Bulunamadi..." << endl;
	}

	oku.close();
}

// ----------------------------------------------------------------- //

void PizzaArama()
{
	setlocale(LC_ALL, "Turkish");
	ifstream oku("Pizza.dat", ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	
	int kayits = oku.tellg() / sizeof(pizza);
	
	cout << "Toplam Pizza Kayit Sayisi: " << kayits << endl;

	cout << "Aranan Pizza Noyu Giriniz: " << endl;
	char pizza_no[100];
	cin >> pizza_no;
 		
	if(kayits > 0)
	{
		for(int i = 0; i < kayits; i++) 
		{
			oku.seekg(i*sizeof(pizza));
			oku.read((char*)&pizza, sizeof(pizza));
			
			if(strcmp(pizza.pizza_no, pizza_no) == 0)
			{
			cout << "Pizzan�n Ana Maddesi: "<< pizza.anamadde <<endl ;
			cout << "Pizzan�n Kenar Tipi: "<< pizza.kenartipi <<endl ;
			cout << "Pizzan�n Hamur T�r�: "<< pizza.hamurturu <<endl ;
			cout << "Pizzan�n ��indeki Malzemeleri: "<< pizza.malzemeler <<endl ;
			cout << "Pizzan�n Sos �e�itleri: "<< pizza.soscesidi <<endl ;
			cout << "Pizzan�n Boyutu: "<< pizza.boyut <<endl ;
			cout << "Pizzan�n Fiyat�: "<< pizza.fiyat <<endl ;
		    }
		}	
	}
	else {
	cout << "Kayit Bulunamadi..." << endl;
	}
	oku.close();
}

// ----------------------------------------------------------------- //

void PizzaSil()
{
	setlocale(LC_ALL, "Turkish");
	
	char pizzano[100];
    char secim = ' ';
    bool var = false;
     
    ifstream oku("Pizza.dat", ios::binary | ios::app);
	
	oku.seekg(0, ios::end);

	int kayitsayisi = oku.tellg() / sizeof(pizza);
	
    cout<<"Kayd�n� Silece�iniz Pizza Numaras�n� Giriniz: ";
    cin >> pizzano;

    for(int i = 0; i < kayitsayisi; i++)
    {
        oku.seekg(i*sizeof(pizza));
		oku.read((char*)&pizza, sizeof(pizza));
			
    	if(strcmp(pizza.pizza_no, pizzano) == 0)
    	{
            cout<<endl;
            cout<<"Pizzan�n";
            cout << "Ana Maddesi: "<< pizza.anamadde <<endl ;
			cout << "Kenar Tipi: "<< pizza.kenartipi <<endl ;
			cout << "Hamur T�r�: "<< pizza.hamurturu <<endl ;
			cout << "��indeki Malzemeleri: "<< pizza.malzemeler <<endl ;
			cout << "Sos �e�itleri: "<< pizza.soscesidi <<endl ;
			cout << "Boyutu: "<< pizza.boyut <<endl ;
			cout << "Fiyat�: "<< pizza.fiyat <<endl ;
 	 				  
            cout<<"\n\nSilmek Istediginiz Kayit Bu Mu? [E/H] : ";
            secim=getche();
            
	        if(secim == 'H' || secim == 'h')
	        {      
			    Pizza y_pizza;
	            ofstream y_dosya("Yedek.dat", ios::app | ios::binary);
	            
	            strcpy(y_pizza.anamadde,pizza.anamadde);
	            strcpy(y_pizza.kenartipi,pizza.kenartipi);
	            strcpy(y_pizza.hamurturu,pizza.hamurturu);
	            strcpy(y_pizza.malzemeler,pizza.malzemeler);
	            strcpy(y_pizza.soscesidi,pizza.soscesidi);
	            strcpy(y_pizza.boyut,pizza.boyut);
	            pizza.fiyat=y_pizza.fiyat;
	                    
	            y_dosya.write((char*)&pizza, sizeof(pizza));
	            y_dosya.close();
	        }
	        
	        if(secim == 'e' || secim == 'E')
	        {
	   		   	var = true;
	  		}
	    }
	    
        else
     	{
      	Pizza y_pizza;
      	ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
      
      	strcpy(y_pizza.anamadde,pizza.anamadde);
        strcpy(y_pizza.kenartipi,pizza.kenartipi);
        strcpy(y_pizza.hamurturu,pizza.hamurturu);
        strcpy(y_pizza.malzemeler,pizza.malzemeler);
        strcpy(y_pizza.soscesidi,pizza.soscesidi);
        strcpy(y_pizza.boyut,pizza.boyut);
        pizza.fiyat=y_pizza.fiyat;
               
      	y_dosya.write((char*)&pizza, sizeof(pizza));
      	y_dosya.close();
     	}
	}
    oku.close();
   
    if(var)
    {
       remove("Pizza.dat");
       rename("Yedek.dat","Pizza.dat");
       cout<<"\n Kayit Silindi"<<endl;
	}
   
    else
    {
       remove("Yedek.dat");
       cout<<"\n Kayit Bulunamadi"<<endl;                  
    }

}

// ----------------------------------------------------------------- //


void PizzaDuzenle()
{
	setlocale(LC_ALL, "Turkish");
	char pizzano[100];
    char secim = ' ';
    bool var = false;
     
    ifstream oku("Pizza.dat", ios::binary | ios::app);
	
	oku.seekg(0, ios::end);

	int kayitsayisi = oku.tellg() / sizeof(pizza);
		
    cout << "Kayd�n� D�zeltece�iniz Numaray� Giriniz: ";
     
	cin >> pizzano;

    for(int i = 0; i < kayitsayisi; i++)
    {
        oku.seekg(i*sizeof(pizza));
		oku.read((char*)&pizza, sizeof(pizza));
		
 		if(strcmp(pizza.pizza_no, pizzano) == 0)
 		{
            cout<<"Pizzan�n" << endl;
            cout << "Ana Maddesi: "<< pizza.anamadde <<endl ;
			cout << "Kenar Tipi: "<< pizza.kenartipi <<endl ;
			cout << "Hamur T�r�: "<< pizza.hamurturu <<endl ;
			cout << "��indeki Malzemeleri: "<< pizza.malzemeler <<endl ;
			cout << "Sos �e�itleri: "<< pizza.soscesidi <<endl ;
			cout << "Boyutu: "<< pizza.boyut <<endl ;
			cout << "Fiyat�: "<< pizza.fiyat <<endl ;
            
            cout<<"\n\nDuzeltmek Istediginiz Kayit Bu Mu? [E/H] : ";
        	secim=getche();
        	if(secim == 'E' || secim == 'e')
          	{	
             	var = true;
                ofstream dosya("Yedek.dat", ios::app | ios::binary);
                
				cout << "Pizza Numaras�n� Giriniz" << endl;
				cin >> pizza.pizza_no;
				
				cout << "Pizza Ana Maddesini Giriniz" << endl;
				cin >> pizza.anamadde;
				
				cout << "Pizzan�n Kenar Tipini Giriniz" << endl;
				cin >> pizza.kenartipi;
				
				cout << "Pizzan�n Hamur T�r�n� Giriniz" << endl;
				cin >> pizza.hamurturu;
				
				cout << "Pizzan�n Malzemelerini Giriniz" << endl;
				cin >> pizza.malzemeler;
				
				cout << "Pizzan�n Sos �e�idini Giriniz" << endl;
				cin >> pizza.soscesidi;
				
				cout << "Pizzan�n ebat�n� giriniz(k���k/orta/b�y�k)" << endl;
				cin >> pizza.boyut;
				
				cout << "Pizzan�n fiyat�n� giriniz" << endl;
				cin >> pizza.fiyat;
  
                dosya.write((char*)&pizza, sizeof(pizza));
                dosya.close();
    		}
    		else
         	{
                Pizza y_pizza;
                ofstream y_dosya;
                y_dosya.open("Yedek.dat", ios::app | ios::binary);
                
            	strcpy(y_pizza.anamadde,pizza.anamadde);
                strcpy(y_pizza.kenartipi,pizza.kenartipi);
                strcpy(y_pizza.hamurturu,pizza.hamurturu);
                strcpy(y_pizza.malzemeler,pizza.malzemeler);
                strcpy(y_pizza.soscesidi,pizza.soscesidi);
                strcpy(y_pizza.boyut,pizza.boyut);
                pizza.fiyat=y_pizza.fiyat;
                         
     			y_dosya.write((char*)&y_pizza, sizeof(y_pizza));
                y_dosya.close();
            }
 		}
 	}
    oku.close();
    if(var)
    {
       remove("Pizza.dat");
       rename("Yedek.dat", "Pizza.dat");
       cout << "\nKay�t D�zeltildi." << endl;
	}
    else
    {
       remove("Yedek.dat");
       cout << "\nKay�t Bulunamad�" << endl;                  
	}

}


