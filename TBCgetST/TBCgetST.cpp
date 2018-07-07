// TBCgetST.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "TBCgetST.h"

#define MAX_LOADSTRING 100

// ���������� ����������:
HINSTANCE hInst;                                // ������� ���������
WCHAR szTitle[MAX_LOADSTRING];                  // ����� ������ ���������
WCHAR szWindowClass[MAX_LOADSTRING];            // ��� ������ �������� ����

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: ���������� ��� �����.



//	int normaS()//������������ ������� ������� � ������ � ����� ��������. ��� ������ � �� Tbase.
				//
				//� ����� t1.txt NC ������������ ����� � ������ ������ ��������� � ��������������� �������
				// N1 N2 N3 ��� �������� T A1 A2 A3 A4 A5
				// ��� �������� �� ����� ���� ������ ��� ��������� �������. ������ ����� <=100 ������
				// N1   - ����� ������, ����� �����
				// N3   - ����� �������� � ����� �����������, �������������� ������ N2=2 � N2=3, ��������� ������������
				// N3=2 - �������� ��� ��������� ��������, ���� ������������ ����������� �����.
				//        ��������� �������� - ����� �����
				// N3=3 - ��� �������� � ��������� ������� ��� ������������ � ���������� � �������� �������. 
				//        ����� ����������� ����� ���������� � ���������� ��������� ������������.
				//        �������������� ������ �� �������� ��������, ��� ������� �������� N3=1
				//        ����� ���� ������� �� 50 ����� ���������.
				// N=2 - ��� �������� � ���������������� �������. ��� ������������� �� ������ ��������, �� � ����������.
				//������:
				//2
				//1 C:\Users\User\Desktop\sourcT\
										//2 C:\Users\User\Desktop\normaT\
//
// �������� ������ ��������� � ������ 0.txt � �������� �� ����� 1000 ������
// �������� ����� 0.txt ��� �������� ������:
// Nf  Nt  ND          Nf - ���������� ������ 1 <= Nf <= 1000
//                     Nt - ��� ������� �������
//                     ND - �������� ������� ��������������� ������, ��������� ��������� ������� ���������������
//                          �������. ���� ND <0, �� ND=0.
//�����, � ����������� �� �������� Nt, ������:
// i1 i2 ..... iN      - ����� ������ ����� ������, �� ����� Nf ���� (Nt==0)
//��� N1 N2            - ����� ������� �����, ��� ����������� ����������� ����������� N(i)=N(i-1)+N2, N(0)=N1 (Nt!=0)
//
// ����� i1 i2 ..... iN  ������ ��������: 1.txt, 2.txt � �.�. ��� �������� ������ ������� ���������� ���� 
//                       � �������� �������� �� �����
//
// �������� ����� 0.txt ��� ��������������� ������:
// Nfn  L                   Nfn - ���������� ������ 1 <= Nfn <= 500, ����� ���������� �� Nf, ���� ������� ����������
//                          L   - ������� ������ ���������������� �����.
//                                �������������� �������� ��� ����� ������������ �������� Nfn =0 L=0.
// i1 +d1 i2 +d2 ..... iN+dN    - ����� ������ ����� ������ + �� �����, �� ����� Nfn ����
//                                ����� ��������������� ������ � �������� ������ ����������� �� ����������� ����
//
// ���� ����� ���������� �� ��� �����, �� ����� ��������� ������ ��������, � � ����� �������� ������ �� �����
// ������� �������� ���������. ���� � �������� ��������������� ������ ���� � ����� ������ ��� ����������, �� ��
// ����� �������. ���� ������ ����� � �������� ���, �� ������� ����� �������� (� ����������� ���������������).
//
//
//����� � ��������������� ����� ����������� �� ���������������� ����� (����������, �������) �������� <=500000 ������.
//� ��������� ����� ����������� ����� ���������� ����� ���������� � ����� ���������� ������ � �����.
//�� ��������� ������ ����������� ����� ��������� � ������� _N_ 
//�� ��������� ������ ���� ����� ��������� - � ��� ��� ���� ����� (�������, ����������) ������.
//
//������� �����:    t1.txt - ������ ���������
//                  t0.txt - ������� ������ ��
//				    t4.txt - ������ ������� ��������� ������
//				    t5.txt - ������ ������� ��������� �������
//				   t20.txt - ���������� ������� �� ������
//              
//              + ����� �� �����, ������������ � t1.txt � ����� �������� 0.txt �� ���� �����
//
//�������� �����:
//
//                  t3.txt - ������� �������
//				    d8.txt - ������ ������
//				    d9.txt - ������ ���������
//				   d10.txt - ������ ��������
//
//               return 0 - ��� � �������
//               return 1 - �� ������ ������� (��������)
//               return 2 - �������� ����������� ������: ��������� (���������) ������  > 10000
//														 ��������� (���������) ������� > 20000
//														 ������������ ����� 5000 ������
//
	{
		char c, c0;
		char s[500000];
		char IA[50];

		char F0[10] = "0.txt";
		char F1[10] = ".txt";

		char CC[11] = "0123456789";
		char NB[11];


		char srT[50][100]; int ssT[50];
		char nnT, nmT[100];            //����� ��
		int kt, w, SV;

		int nsF, SF[1000], STC, DNC;
		int ntF;
		int TAB[30];
		int i4, IC;

		//NbF - ����� � �������� �������
		//NNF - ������ ������� ������� � ��������
		//NNL - ����� ���������, ��� NLL[0] - ���������� ����������� ���������, NLL[1] � ����� - ���-�� ������, ������ �������
		//SF - ����� ��� �������� ������� ���������

		int NNF[1000], NNL[4000], NLL[1000], nF, nL, tb4, tb5, tb20, nf1, nt1;

		int NC, NT, NTT, NBB, fg, zt, NN, cT, NRZ;
		int i, j, t, z, x, lns, m, g1, g3, p, zp;
		int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13;
		int vT[50], v1[50], v2[50], v3[50], v4[50], v5[50]; //��������


		int FileNameNumber = 0;
		int  NNN, k;
		char NameOfText[256] = { "" };
		char Buf[256] = { "" };
		char c1, c2;
		int Nd10, d10, NbF[1920], Ndx;
		int t1, t2, t3, NT10;

		char ANm[1001] = { "" };
		int nofAs = 1;
		int nInSABuff = 1;


		FILE *f, *f1, *f2, *f3, *f4, *f5;
		//
		//���������� ����� �������� � ��������������� ������� � ��������������� �������� � ������ 0.txt
		//
		fopen_s(&f2, "C:\\Tbase\\t0.txt", "r"); //���� c ����������� ������� 
		fopen_s(&f4, "C:\\Tbase\\t1.txt", "r"); //���� � ������ ������ (����) ����� �������� (NT=1) � ��������������� (NT=2) ������� 

		while ((c = fgetc(f2)) != '\n'); //������� ����
		for (x = 0; x < 20; x++)         //������ ���������� ������� ������ - "������" (� 1)
		{
			fscanf_s(f2, "%d;%d", &NTT, &TAB[x]); while ((c = fgetc(f2)) != '\n'); //�������
		}

		fclose(f2); //������� t0.txt

		NC = TAB[0];  if (NC < 2)return 1; //�� ������ ������� (��������)
		SV = 0;

		while ((c = fgetc(f4)) != '\n'); //������� ����
		t = m = kt = 0;
		for (x = 0; x < NC; x++)
		{
			fscanf_s(f4, "%d;%d;%d;", &NTT, &NBB, &NT);
			if ((NT == 3) && (NBB == 1))
			{
				c = fgetc(f4); 	i = 0; while ((c = fgetc(f4)) != '\"') { srT[kt][i] = c; i++; }
				ssT[kt] = i;
				j = 0; while (F0[j] != '\0') { srT[kt][i] = F0[j]; i++; j++; }
				srT[kt][i] = '\0';

				t = 1;
				//������ ���������
				fscanf_s(f4, ";%d;%d;%d;%d;%d;%d\n", &vT[kt], &v1[kt], &v2[kt], &v3[kt], &v4[kt], &v5[kt]);
				kt++;
			}
			else
			{
				if (NT == 2)
				{
					c = fgetc(f4); i = 0; while ((c = fgetc(f4)) != '\"') { nmT[i] = c; i++; }
					nnT = i;
					j = 0; while (F0[j] != '\0') { nmT[i] = F0[j]; i++; j++; }
					nmT[i] = '\0';

					m = 1;
					while ((c = fgetc(f4)) != '\n');              //������� ���������
				}
				else while ((c = fgetc(f4)) != '\n');              //������� �����
			}
		}
		fclose(f4); //������� t1.txt


		if (t != 1 || m != 1)return 1; //�� ������ ������� (��������)



		tb4 = TAB[3]; tb5 = TAB[4]; tb20 = TAB[19];
		//������ ������ ��������� ������� ������  - "������_�" (� 4)
		if (tb4 > 10000) return 2; //��������� ������ ������ 10000
		if (tb4 > 0)
		{
			fopen_s(&f2, "C:\\Tbase\\t4.txt", "r");
			while ((c = fgetc(f2)) != '\n'); //������� ����
			for (x = 0; x < tb4; x++) fscanf_s(f2, "%d\n", &NNF[x]);
			fclose(f2); //������� t4.txt
		}
		//������ ������ ��������� ������� �������  - "������_�" (� 5)
		if (tb5 > 20000) return 2; //��������� ������� ������ 20000
		if (tb5 > 0)
		{
			fopen_s(&f2, "C:\\Tbase\\t5.txt", "r");
			while ((c = fgetc(f2)) != '\n'); //������� ����
			for (x = 0; x < 2 * tb5; x = x + 2) fscanf_s(f2, "%d;%d;%d\n", &NTT, &NNL[x], &NNL[x + 1]);
			fclose(f2); //������� t5.txt
		}
		//������ ���������� ������� �� ������  - "�����_�" (� 20)
		if (tb20 > 5000) return 2; //������ ������ 5000
		if (tb20 > 0)
		{
			fopen_s(&f2, "C:\\Tbase\\t20.txt", "r");
			while ((c = fgetc(f2)) != '\n'); //������� ����
			for (x = 0; x < 2 * tb20; x = x + 2) fscanf_s(f2, "%d;%d\n", &NLL[x], &NLL[x + 1]);
			fclose(f2); //������� t20.txt
		}


		nF = nL = 0;

		nt1 = 0;
		t = m = w = fg = 0;
		ntF = TAB[1] + TAB[3]; NRZ = 0;

		fopen_s(&f3, "C:\\Tbase\\t3.txt", "w");

		fprintf(f3, "\"���\";\"�������\";\"�_������\";\"�����\";\"�_�����\";\"�_��\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"����\"\n");




		//
		// ������� ���� w �� ����� �������� ��������� �������� �������
		//

		for (w = 0; w < kt; w++)
		{

			p = 0; for (x = 0; x < tb20; x = x + 2) if (v1[w] == NLL[x])p = 1;
			if (p == 0)continue; //������� ��������� � ����������� ������

			g1 = g3 = 1;
			fopen_s(&f, &srT[w][0], "r");                          //������ �������� �������� �������
			fscanf_s(f, "%d %d %d\n", &nsF, &STC, &DNC); if (DNC < 0)DNC = 0;

			if (STC == 0) for (i = 0; i < nsF; i++) { fscanf_s(f, "%d", &SF[i]); SF[i] = SF[i] + DNC; }
			else
				if (STC == 1) for (i = 0; i < nsF; i++) { fscanf_s(f, "%d\n", &SF[i]); SF[i] = SF[i] + DNC; }
				else
					if (STC == 2) { fscanf_s(f, "%d %d\n", &g1, &g3); for (i = 0; i < nsF; i++) { SF[i] = g1 + DNC; g1 = g1 + g3; } }
					else
						if (STC == 3)
						{
							for (i = 0; i < nsF; i++)
							{
								fscanf_s(f, "%d;%d;%d;%d;%d", &n1, &n2, &n3, &n4, &n5);
								while ((c = fgetc(f)) != '\n'); //������� ����
								SF[i] = n5 + DNC;
							}
							//�_��� ������� �_������ ����� �_����� �_�� �_���� �_��� �_��� �_��� �_��� �_��� �_��� ����
						}
						else continue; //������� ��������� � ����������� �����


						fclose(f);
						//
						// ���� i4 �� ����� nsF �������� � �������� �������� ������� ������
						//

						for (i4 = 0; i4 < nsF; i4++)
						{

							//����� ������ �� integer � char + ������ ���� � �����
							//��������
							p = 0; IC = SF[i4]; for (i = 0; i < 10; i++) { z = IC % 10; if (z > 0)p = i; NB[i] = CC[z]; IC = IC / 10; }
							i = ssT[w]; for (z = 0; z < p + 1; z++)srT[w][i + z] = NB[p - z];
							for (z = 0; z < 5; z++)srT[w][i + p + z + 1] = F1[z];
							//���������������
							if (tb4 > 0) { nf1 = NNF[nF]; nF++; tb4--; }
							else { ntF++; nf1 = ntF; }

							p = 0; IC = nf1; for (i = 0; i < 10; i++) { z = IC % 10; if (z > 0)p = i; NB[i] = CC[z]; IC = IC / 10; }
							j = nnT; nmT[j] = 'f'; j++;
							for (z = 0; z < p + 1; z++)nmT[j + z] = NB[p - z];
							for (z = 0; z < 5; z++)nmT[j + p + z + 1] = F1[z];


							//1
							//���� ������������ �������
							//����������: ��������� �� ���� ������ � ��������, �������� �����, ����������� ����� �������. �������� "�" �� "�"
							//������� ������ ������ ��� ����� ������ �����, �������� ������. ������� ��������� � �������� �����.
							//������������� ����� ������ ����� ������ �����
							//

							//��������� � ����� ����� ����� ������. ����� ����� ���������� �� 50-�������� ���������� '�'
							//������� ����� ��������� '\t' � '�'
							//�������� � ������ '�'�� '�'
							//
							fopen_s(&f, &srT[w][0], "r");
							fopen_s(&f1, nmT, "w");
							zt = z = 0;
							j = 0; i = 0; x = 0; NN = 500000;

						NBG:
							while ((c = fgetc(f)) != '�'&& i < NN)
							{
								if (c != '\n')
								{
									if (c0 == '-'&& c == ' ') continue;
									else
										if ((c0 == '.' || cT == 1) && c == '.') continue;
										else
										{
											if (c == '.') cT = 1; else if (c != ' ') cT = 0; if (c == '\t')c = ' '; c0 = c;
											if (c != '-'&& c != '�') { s[i] = c; i++; }
										}
								}
								else if (c0 != '-'&& c0 != '�') { s[i] = ' '; i++; }
							}

							lns = i;

							if (c != '�'&& i == NN)
							{
								for (j = 0; j < NN; j++)fputc(s[j], f1); z = z + NN;
								if (c == '\t')c = ' ';
								if (c == '\n'&& c0 != '-'&& c0 != '�')c = ' '; c0 = c;
								if (c != '-'&& c != '�'&& c != '\n') { s[0] = c; i = 1; }
								else i = 0; goto NBG;
							}

							if (c == '�')
							{
								i = 1; IA[0] = '�'; x = 1; c0 = c;
								for (j = 1; j < 50; j++)
								{
									c = fgetc(f); if (c == '�') { i++; c = '�'; }
									if (c == '\t')c = ' ';
									if (c == '\n'&& c0 != '-'&& c0 != '�')c = ' '; c0 = c;
									if (c != '-'&& c != '�'&& c != '\n') { IA[x] = c; x++; }
								}
								if (i != j)
								{
									if (lns + x <= NN) { for (j = 0; j < x; j++)s[lns + j] = IA[j]; i = lns + x; goto NBG; }
									else {
										for (j = 0; j < lns; j++)fputc(s[j], f1); z = z + lns;
										for (j = 0; j < x; j++)s[j] = IA[j]; i = x; goto NBG;
									}
								}
								else { for (j = 0; j < lns; j++)fputc(s[j], f1); c = '\n'; fputc(c, f1); goto ENFL; }
							}
						ENFL:
							fclose(f);
							fclose(f1);


							//
							/////////////////////////// ���� 1 ��������


							zt = z + lns; fg++;

							//����������� ������ ������

							p = 0; for (x = 0; x < 2 * tb5; x = x + 2)p = p + NNL[x + 1];
							if (tb5 > 0 && p != 0)
							{
								p = 0;
								for (x = 0; x < 2 * tb5; x = x + 2)
									if (v1[w] == NNL[x] && NNL[x + 1] != 0)
									{
										p = 1; nt1 = NNL[x + 1]; NNL[x + 1] = 0; break;
									}

							}

							if (p == 0)
							{
								nt1++;
								zp = 0; for (x = 0; x < 2 * tb5; x = x + 2)if (v1[w] == NNL[x]) zp++;
								for (x = 0; x < 2 * tb20; x = x + 2)
									if (v1[w] == NLL[x]) { nt1 = NLL[x + 1] + 1; NLL[x + 1] = nt1; nt1 = nt1 + zp; }
							}



							fprintf(f3, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;11.11.2018 0:00:00\n", fg, 0, nt1, zt, nf1, v1[w], 0, v2[w], v3[w], v4[w], 0, 0, v5[w]);
							//�_��� ������� �_������ ����� �_����� �_�� �_���� �_��� �_��� �_��� �_��� �_��� �_��� ����			


						}

		}

		fclose(f3);


		TAB[2] = fg;      //���������� ������� � "������_�" (� 3)
		fopen_s(&f2, "C:\\Tbase\\t0.txt", "w");  //���� c ����������� ������� 
		fprintf(f2, "\"�_���\";\"�_���\";\"����������\"\n");
		for (x = 0; x < 20; x++)
		{
			fprintf(f2, "%d;%d;\"w\"\n", x + 1, TAB[x]);
		}
		fclose(f2); //������� t0.txt
//		



//���� ��������� ��������
//
// �������� ����������� ����� ������ ������� || � ������ � �����
// �� �������� ���������� ������ ������ 255 ������
// �������������� 1920 ����� ��������. ���� �� ������, �� � �������� 1920 -��  ��������� ���������
//
		fopen_s(&f, "C:\\Tbase\\tmp.txt", "w");
		fopen_s(&f3, "C:\\Tbase\\t3.txt", "r");   //���� ����������� �������
		while ((c = fgetc(f3)) != '\n'); //������� ����
		fprintf(f, "\"���\";\"�������\";\"�_������\";\"�����\";\"�_�����\";\"�_��\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"����\"\n");



		fopen_s(&f2, "C:\\Tbase\\d10.txt", "w");  //���� ����� ��������

		fprintf(f2, "\"���\";\"��������\";\"�_���\";\"�������\"\n");


		Nd10 = d10 = 0; NT10 = TAB[9];

		for (i4 = 0; i4 < fg; i4++)

		{
			fscanf_s(f3, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13);
			while ((c = fgetc(f3)) != '\n'); //������� ����

			p = 0; IC = n5; for (i = 0; i < 10; i++) { z = IC % 10; if (z > 0)p = i; NB[i] = CC[z]; IC = IC / 10; }
			j = nnT; nmT[j] = 'f'; j++;
			for (z = 0; z < p + 1; z++)nmT[j + z] = NB[p - z];
			for (z = 0; z < 5; z++)nmT[j + p + z + 1] = F1[z];


			fopen_s(&f1, nmT, "r");  //�����
			FileNameNumber = 0;
			for (x = 0; x < 255; x++)NameOfText[x] = '\0';

			j = NNN = p = 0; c1 = c2 = '\0';
			while ((c = fgetc(f1)) != EOF && NNN == 0) {
				c1 = c2; c2 = c;
				if (c1 == '|' && c2 == '|')
					if (p == 0)  p++; else { NNN = 1; p = 0; }

				if (p == 1 && NNN == 0 && c != '|') if (j < 255) { NameOfText[j] = c; j++; }
			}
			fclose(f1);//������� �����.txt

			if (j > 0)
			{
				//������ �������� � �������
				k = 0;
				fopen_s(&f1, "C:\\Tbase\\t10.txt", "r");  //���� ������������ ��������
				while ((c = fgetc(f1)) != '\n'); //������� ����
				for (x = 0; x < NT10; x++)
				{
					fscanf_s(f1, "%d;", &t1);
					c = fgetc(f1); Buf[0] = c; j = 1;
					while ((c = fgetc(f1)) != '\"') { Buf[j] = c; j++; };
					Buf[j] = c;
					fscanf_s(f1, ";%d;%d\n", &t2, &t3);
					c = NameOfText[0]; p = 0; j = 0;
					while (c != '\0') { if (c != Buf[j]) { p = 1; break; } else { j++; c = NameOfText[j]; } }
					if (p == 1)k = t2; //�������������� ��������������� ������� �� �����������
					if (p == 0) { FileNameNumber = t2; break; }

				}
				fclose(f1);//������� t10.txt

				if (FileNameNumber == 0) {
					if (Nd10 < 1921) Ndx = Nd10; else Ndx = 1920;
					for (x = 0; x < Ndx; x++)
					{
						c = NameOfText[0]; p = 0; j = 0; w = 0;
						while (c != '\0') { if (c != s[w + j]) { p = 1; break; } else { j++; c = NameOfText[j]; } }

						if (p == 0) { FileNameNumber = NbF[x]; break; }
						w = w + 260;
					}

				}
				if (FileNameNumber == 0) {
					k = k + Nd10 + 1;
					fprintf_s(f2, "%d;", Nd10 + 1);
					FileNameNumber = k;
					fprintf_s(f2, "\"%s\";", NameOfText);
					fprintf_s(f2, "%d;0\n", k);
					if (Nd10 < 1921) NbF[Nd10] = k;
					Nd10++;
					c = NameOfText[0]; p = 0; j = 0;
					while (c != '\0'&& j < 255) { s[d10 + j] = c; j++; c = NameOfText[j]; }
					s[d10 + j] = c;
					if (Nd10 < 1921)d10 = d10 + 260;
				}
			}
			n12 = FileNameNumber;
			fprintf(f, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;11.11.2018 0:00:00\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13);
			//�_��� ������� �_������ ����� �_����� �_�� �_���� �_��� �_��� �_��� �_��� �_��� �_��� ����			


		}
		fclose(f);
		fclose(f3);
		fclose(f2);//������� d10.txt

		fopen_s(&f, "C:\\Tbase\\tmp.txt", "r");
		fopen_s(&f3, "C:\\Tbase\\t3.txt", "w");

		while ((c = fgetc(f)) != '\n'); //������� ����
		fprintf(f3, "\"���\";\"�������\";\"�_������\";\"�����\";\"�_�����\";\"�_��\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"����\"\n");

		while ((c = fgetc(f)) != EOF)fputc(c, f3);
		fclose(f);
		fclose(f3);
		_fcloseall();

		//
		//�������� ����������   ���� ��������



		//���� ��������� ������ �������
		//
		// ������ ���������� ����� ������ ������� ^^ � ������ � �����
		// �� ������ ���������� ������ ������ 99 ������
		// ������ � ������ ����������� �������
		// 
		//	
		//for (i = 0; i < 500000; i++) s[i] = '\0';

		fopen_s(&f, "C:\\Tbase\\tmp.txt", "w");
		fprintf(f, "\"���\";\"�������\";\"�_������\";\"�����\";\"�_�����\";\"�_��\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"����\"\n");

		fopen_s(&f2, "C:\\Tbase\\d8.txt", "w");   //����� ������
		fopen_s(&f5, "C:\\Tbase\\d9.txt", "w");   //����� ��������


		fprintf(f2, "\"���\"; \"���\"; \"�_���\"; \"�������\"\n");
		fprintf(f5, "\"���\"; \"�_����\"; \"�_����\"\n");


		Nd10 = d10 = nL = NN = 0; NT10 = TAB[7];

		fopen_s(&f3, "C:\\Tbase\\t3.txt", "r");   //���� ����������� �������
		while ((c = fgetc(f3)) != '\n'); //������� ����
		for (i = 0; i < 4000; i++) { NNL[i] = 0; }
		for (i = 0; i < 1000; i++) { NLL[i] = 0; }
		for (i = 0; i < 1000; i++) { NNF[i] = 0; }
		for (i = 0; i < 1000; i++) { SF[i] = 0; }
		for (i = 0; i < 1920; i++) { NbF[i] = 0; }

		for (i4 = 0; i4 < fg; i4++)
		{
			fscanf_s(f3, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13);
			while ((c = fgetc(f3)) != '\n'); //������� ����

			p = 0; IC = n5; for (i = 0; i < 10; i++) { z = IC % 10; if (z > 0)p = i; NB[i] = CC[z]; IC = IC / 10; }
			j = nnT; nmT[j] = 'f'; j++;
			for (z = 0; z < p + 1; z++)nmT[j + z] = NB[p - z];
			for (z = 0; z < 5; z++)nmT[j + p + z + 1] = F1[z];

			fopen_s(&f1, nmT, "r");  //�����
			for (x = 0; x < 256; x++)Buf[x] = '\0';

			FileNameNumber = j = NNN = p = 0; c1 = c2 = '\0';
			nofAs = 1;
			while ((c = fgetc(f1)) != EOF && NNN == 0) {
				c1 = c2; c2 = c;
				if (c1 == '^' && c2 == '^')
					if (p == 0)  p++; else { NNN = 1; p = 0; }

				if (p == 1 && NNN == 0 && c != '^') if (j < 99)
				{
					ANm[j] = c;
					j++;
					if (c == ',') nofAs++;
				}
			}
			ANm[j] = '\0';
			fclose(f1);//������� �����.txt

			if (ANm[0] != '\0')
			{
				if (nofAs == 1)
				{
					fopen_s(&f1, "C:\\Tbase\\t8.txt", "r");   //������
					while ((c = fgetc(f1)) != '\n'); //������� ����

					for (x = 0; x < NT10; x++)
					{
						fscanf_s(f1, "%d;", &t1);
						c = fgetc(f1);
						i = 0;
						while ((c = fgetc(f1)) != '\"') { Buf[i] = c; i++; };
						Buf[i] = '\0';

						fscanf_s(f1, ";%d;%d\n", &t2, &t3);
						c = ANm[0]; p = 0; i = 0;
						while (c != '\0')
						{
							if (c != Buf[i])
							{
								p = 1;
								break;
							}
							else
							{
								i++;
								c = ANm[i];
							}
						}
						if (p == 1)k = t2; //�������������� ��������������� ������� �� �����������
						else if ((p == 0) && (Buf[i] == '\0')) { FileNameNumber = t2; break; }
					}
					fclose(f1);

					if (FileNameNumber == 0) {
						if (Nd10 < 1921) Ndx = Nd10; else Ndx = 1920;
						w = 0;
						for (x = 0; x < Ndx; x++)
						{
							c = ANm[0]; p = 0; i = 0;
							while (c != '\0') { if (c != s[w + i]) { p = 1; break; } else { i++; c = ANm[i]; } }
							if (p == 0) { FileNameNumber = NbF[x]; break; }
							w = w + 260;
						}
					}

					if (FileNameNumber == 0) {
						k = k + Nd10 + 1;
						fprintf_s(f2, "%d;", Nd10 + 1);
						FileNameNumber = k;
						fprintf_s(f2, "\"%s\";", ANm);
						fprintf_s(f2, "%d;0\n", k);
						if (Nd10 < 1921)  NbF[Nd10 - NNL[0]] = k;
						Nd10++;
						c = ANm[0]; p = 0; i = 0;
						while (c != '\0'&& i < 255) { s[d10 + i] = c; i++; c = ANm[i]; }
						s[d10 + i] = c;
						if (Nd10 < 1921)d10 = d10 + 260;
					}
				}//��������� ������ ������ ���������
				else
				{
					m = 0; NNN = 0;
					for (t = 0; t < nofAs; t++)//���� �� ���������� �������
					{
						for (j = 0; j < 256; j++) NameOfText[j] = '\0';
						c = ANm[m];
						j = p = 0;
						while (c != ','&& c != '\0') {
							if (c != ' ')p = 1;
							if (p == 1 && j < 255) { NameOfText[j] = c; j++; } m++; c = ANm[m];
						}
						NameOfText[j] = '\0';
						m++;
						k = 0; FileNameNumber = 0;

						fopen_s(&f1, "C:\\Tbase\\t8.txt", "r");   //������
						while ((c = fgetc(f1)) != '\n'); //������� ����

						// ���� �� ��� ������ � ������� �������?
						for (x = 0; x < NT10; x++)
						{
							fscanf_s(f1, "%d;", &t1);
							c = fgetc(f1);
							i = 0;
							while ((c = fgetc(f1)) != '\"') { Buf[i] = c; i++; };
							Buf[i] = '\0';
							fscanf_s(f1, ";%d;%d\n", &t2, &t3);
							c = NameOfText[0]; p = 0; i = 0;
							while (c != '\0')
							{
								if (c != Buf[i])
								{
									p = 1;
									break;
								}
								else
								{
									i++;
									c = NameOfText[i];
								}
							}
							if (p == 1)k = t2; //�������������� ��������������� ������� �� �����������
							else if ((p == 0) && (Buf[i] == '\0')) { FileNameNumber = t2; }
						}
						fclose(f1);

						if (FileNameNumber == 0)
						{
							if (Nd10 < 1921) Ndx = Nd10; else Ndx = 1920;
							w = 0;

							for (x = 0; x < Ndx; x++)
							{
								c = NameOfText[0]; p = 0; i = 0;
								while (c != '\0') 
								{ 
									if (c != s[w + i]) 
									{ 
										p = 1; 
										break; 
									} 
									else
									{ 
										i++; 
										c = NameOfText[i];
									} 
								}

								if (p == 0) { FileNameNumber = NbF[x]; break; }
								w = w + 260;
							}
						}

						if (FileNameNumber == 0)
						{
							k = k + Nd10+1;

							fprintf_s(f2, "%d;", Nd10 + 1);
							FileNameNumber = k;
							fprintf_s(f2, "\"%s\";", NameOfText);
							fprintf_s(f2, "%d;0\n", k);
							if (Nd10 < 1921) NbF[Nd10-NNL[0]] = k;
							Nd10++;
							NNN++;
							c = NameOfText[0]; p = 0; i = 0;
							while (c != '\0'&& i < 255) { s[d10 + i] = c; i++; c = NameOfText[i]; }
							s[d10 + i] = c;
							if (Nd10 < 1921)d10 = d10 + 260;
						}
						NNF[t] = FileNameNumber;
					}

					// ����� � �������� ���� �������, ���������
					x = 0;
					for (i = 0; i < nofAs - 1; i++) {
						for (z = 0; z < nofAs - i - 1; z++) {
							if (NNF[z] >NNF[z + 1]) {
								// ������ �������� �������
								x = NNF[z];
								NNF[z] = NNF[z + 1];
								NNF[z + 1] = x;
							}
						}
					}

					//�������� ������ � �������� ���������
					
					FileNameNumber = 0;
					if (NNN == 0) {//���� ��� ������ ��� ����
						fopen_s(&f1, "C:\\Tbase\\t9.txt", "r");   //��������
						while ((c = fgetc(f1)) != '\n'); //������� ����
						t2 = t3 = m = z = 0;
						while (!feof(f1)) {
							fscanf_s(f1, "%*d;%d;%d\n", &t2, &t3);
							//���� ����� �������� ��������� � ����������, ������ ������
							if (((t2 == z) ^ (m == 0)) && (t3 == NNF[m])) {
								m++;
								if (m == nofAs) { FileNameNumber = t2; }
								if (m > nofAs) { FileNameNumber = 0; }
							}
							z = t2;
						}
						fclose(f1);

						m = 1;
						// �������� �� ������
						if (FileNameNumber == 0) {
							for (x = 0; x < NNL[0]; x++)
							{
								p = 0;
								if (NNL[m] != nofAs)
								{
									m += (NNL[m] + 1);
									continue;
								}
								for (z = 0; z < nofAs; z++) {
									if (NNF[z] != NNL[m + z + 1])
									{ p = 1;}
									z++;
								}
								m += (NNL[m] + 1);
								if (p == 0) { FileNameNumber = SF[x]; break; }
							}
						}

						//������ � ���� � �����
						if (FileNameNumber == 0) {
							//� ���� �������
							k += (Nd10 + 1);
							//k++;
							fprintf_s(f2, "%d;", Nd10 + 1);
							FileNameNumber = k;

							fprintf_s(f2, "\"�������%d\";", k);
							fprintf_s(f2, "%d;0\n", k);
							//if (Nd10 < 1921) NbF[Nd10] = k;
							Nd10++;

							//� ���� ���������
							for (x = 0; x < nofAs; x++) {
								fprintf_s(f5, "%d;", NN + 1);
								fprintf_s(f5, "%d;", FileNameNumber);
								fprintf_s(f5, "%d\n", NNF[x]);
								NN++;
							}
							//� �����
							if (nInSABuff + nofAs + 1 < 4000) {
								SF[NNL[0]] = FileNameNumber;
								NNL[0]++;
								NNL[nInSABuff] = nofAs;
								for (x = 0; x < nofAs; x++) {
									nInSABuff++;
									NNL[nInSABuff] = NNF[x];
								}
								nInSABuff++;
							}
						}
					}//�������� ��������� ���� ��� ������ ��� ����
					else
					{
						//� ���� �������
						k++;
						//k += (Nd10 + 1);
						fprintf_s(f2, "%d;", Nd10 + 1);
						FileNameNumber = k;

						fprintf_s(f2, "\"�������%d\";", k);
						fprintf_s(f2, "%d;0\n", k);
						//if (Nd10 < 1921) NbF[Nd10] = k;
						Nd10++;

						//� ���� ���������
						for (x = 0; x < nofAs; x++) {
							fprintf_s(f5, "%d;", NN + 1);
							fprintf_s(f5, "%d;", FileNameNumber);
							fprintf_s(f5, "%d\n", NNF[x]);
							NN++;
						}
						//� �����
						if (nInSABuff + nofAs + 1 < 4000) {
							SF[NNL[0]] = FileNameNumber;
							NNL[0]++;
							NNL[nInSABuff] = nofAs;
							for (x = 0; x < nofAs; x++) {
								nInSABuff++;
								NNL[nInSABuff] = NNF[x];
							}
							nInSABuff++;
						}
					}
				}
			}
			n11 = FileNameNumber;
			fprintf(f, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;11.11.2018 0:00:00\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13);
			//�_��� ������� �_������ ����� �_����� �_�� �_���� �_��� �_��� �_��� �_��� �_��� �_��� ����			
		}
		fclose(f);
		fclose(f3);
		fclose(f2);//������� d10.txt

		fopen_s(&f, "C:\\Tbase\\tmp.txt", "r");
		fopen_s(&f3, "C:\\Tbase\\t3.txt", "w");

		while ((c = fgetc(f)) != '\n'); //������� ����
		fprintf(f3, "\"���\";\"�������\";\"�_������\";\"�����\";\"�_�����\";\"�_��\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"�_���\";\"����\"\n");

		while ((c = fgetc(f)) != EOF)fputc(c, f3);
		_fcloseall();
		return 0;
	}
	////////////////
	////////////////


	// ������������� ���������� �����
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_TBCGETST, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ��������� ������������� ����������:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TBCGETST));

	MSG msg;

	// ���� ��������� ���������:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  �������: MyRegisterClass()
//
//  ����������: ������������ ����� ����.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TBCGETST));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TBCGETST);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   �������: InitInstance(HINSTANCE, int)
//
//   ����������: ��������� ��������� ���������� � ������� ������� ����.
//
//   �����������:
//
//        � ������ ������� ���������� ���������� ����������� � ���������� ����������, � �����
//        ��������� � ��������� �� ����� ������� ���� ���������.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  �������: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����������:  ������������ ��������� � ������� ����.
//
//  WM_COMMAND � ���������� ���� ����������
//  WM_PAINT � ���������� ������� ����
//  WM_DESTROY � ��������� ��������� � ������ � ���������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// ��������� ����� � ����:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: �������� ���� ����� ��� ����������, ������������ HDC...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���������� ��������� ��� ���� "� ���������".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}