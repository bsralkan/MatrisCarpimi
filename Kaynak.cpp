/* Buþra Alkan
   1306170037
*/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>


int main() {

	FILE* f = NULL;
	int satir, sutun; // 1.matrisin satýr ve sutun deðerleri
	int satir1, sutun1; // 2.matrisin satýr ve sutun deðerleri
	int a, b, toplam = 0; // geçici deðiþkenler a->1.matrisin satir baþlangýç deðerleri, b->2.matrisin sutun baþlangýç deðerleri toplam->matrislerin çarpým deðerlerini tutan deðiþken

	if ((f = fopen("matrisler.txt", "r")) != NULL) {
		fscanf(f, "%d" "%d", &satir, &sutun);

		int* matris1 = (int*)malloc((satir * sutun) * sizeof(int));

		for (int i = 0; i < (satir * sutun); i++) {

			fscanf(f, "%d", &matris1[i]);


		}


		fscanf(f, "%d" "%d", &satir1, &sutun1);
		int* matris2 = (int*)malloc((satir1 * sutun1) * sizeof(int));

		for (int i = 0; i < (satir1 * sutun1); i++) {

			fscanf(f, "%d", &matris2[i]);


		}

		if (satir == sutun1) { // matris çarpým kural kontrolü

			int* sonuc = (int*)malloc((satir * sutun1) * sizeof(int));
			int c = 0;
			int sayac = 0;

			for (int k = 0; k < sutun; k++) // 1.matrisin satýr döngüsü
			{
				for (int i = 0; i < satir; i++) // 2.matrisin sutun döngüsü
				{
					toplam = 0;
					a = c;
					b = i;

					for (int j = 0; j < sutun1; j++) // 1.matrisin satýrý ve 2.matrisin sutun döngüsü
					{
						toplam += matris1[a] * matris2[b];
						a++;
						b += satir;
					}
					sonuc[sayac] = toplam;
					sayac++;
				}
				c += satir;
			}
			int k = 0;
			FILE* s;
			s = fopen("sonuc.txt", "w");
			for (int i = 0; i < satir; i++) {
				for (int j = 0; j < sutun1; j++)
				{
					if (sonuc[k] < 100) {
						fprintf(s, "%d    ||   ", sonuc[k]);
						k++;
					}
					else if (sonuc[k] < 10) {
						fprintf(s, "%d     ||   ", sonuc[k]);
						k++;
					}
					else {
						fprintf(s, "%d   ||   ", sonuc[k]);
						k++;
					}
				}
				fprintf(s, "\n ---------------------------------------------------\n");


			}
			fprintf(s, "\n ----------------Büþra Alkan--------------------\n");
			fprintf(s, "\n ----------------1306170037---------------------\n");

			printf("islem basarili bir sekilde gerceklesti");

		}
		else {
			printf("matrisler matris carpim kosullarýna uygun degil!!");
		}
	}
	else {
		printf("dosya acilamadi!!");
	}





	return 0;
}