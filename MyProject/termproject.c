#define _CRT_SECURE_NO_WARNINGS // scanf ��빮
#include <string.h> // ���ڿ� ó�� ���̺귯��
#include <conio.h> // _getch �Լ��� ����ϱ� ���� ���̺귯��
#include <stdio.h>
#include <stdlib.h> // ȭ�� ��ȯ �Լ��� system("cls")�� exit�� ����ϱ� ���� ���̺귯��
#include <time.h> // �ð� �Լ��� ����ϱ� ���� ���̺귯�� (ȯ�ҿ� ���)

void menu1();
void menu2(); // �޴� �Լ�
int get_input(); // ������ �Է¹޴� �Լ�
void change_price(); // ������ ����� ���� ��ȯ �Լ�
void change_number(); // ������ ����� ��� ��ȯ �Լ�
void purchase(); // ����� ����� ���� �Լ�
void mypage(); // ���� �������� �����ִ� �Լ�
void refund(char c[1000], int n); // ȯ�� �Լ�

int money = 1000000; // ������� �ʱ� �ݾ��� 100000���� �ʱ�ȭ�Ѵ�. (��� �Լ����� ���Ǳ� ������ ���� ������ ���)

int main(void)
{
	FILE* fp = NULL;
	FILE* fpout = NULL;
	FILE* fp2 = NULL;
	FILE* fpout2 = NULL;
	fp = fopen("shoes.txt", "r");
	int input;
	char id[10];
	char pw[10];
	char buffer[1000], buffer2[1000];
	int cpid, cppw;
	int num1, num2;

	printf("\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t <<������ �Ź� ���θ� ���� ���α׷�>> \t\t\t\t\t\t\n\n\n\n\n");
	printf("\t\t\t\t\t      Press any key to continue\n\n\n\n");
	printf("\t\t\t\t\t\t\t   ");
	if ((input = _getch()) != EOF)
		system("cls"); // Ű �Է� �ް� ȭ�� ��ȯ

	printf("\n\n\n\n\n\n\t\t���θ����� ����� �г��� : ");
	scanf("%s", &id);

	cpid = strcmp("admin", id); // ���� �г������� admin�� �Է��ߴٸ�

	if (cpid == 0)
	{
		while (1)
		{
			printf("\n\n\t\t�������� ��й�ȣ : ");
			scanf("%s", &pw);

			cppw = strcmp("7881", pw); // ��й�ȣ�� �ǰ� �Է��ߴٸ�

			if (cppw == 0) // ������ ���� ����
			{
				while (1)
				{
					system("cls");
					menu1(); // ������ ��� �޴� �Լ� ȣ��
					num1 = get_input(); // ��ȣ �Է�

					switch (num1) {

					case 1:

						change_price(); // ���� ��ȯ �Լ�
						fp = fopen("shoes2.txt", "r");

						if (fp == NULL) {

							printf("���� ���� ����\n");
							return 0;

						}

						fpout = fopen("shoes.txt", "w");

						if (fpout == NULL) {

							printf("���� ���� ����\n");
							return 0;

						}
						while (fgets(buffer, 1000, fp) != NULL)
							fputs(buffer, fpout); // shoes2.txt ���Ͽ��� shoes.txt ���Ϸ� �����Ѵ�. (���� ��ȯ�� ���� shoes2.txt�� ����Ǿ� ����)

						fclose(fp);
						fclose(fpout);
						continue;

					case 2:

						change_number(); // ��� ��ȯ �Լ�
						fp = fopen("shoes2.txt", "r");

						if (fp == NULL) {

							printf("���� ���� ����\n");
							return 0;

						}

						fpout = fopen("shoes.txt", "w");

						if (fpout == NULL) {

							printf("���� ���� ����\n");
							return 0;

						}
						while (fgets(buffer, 1000, fp) != NULL)
							fputs(buffer, fpout); // shoes2.txt ���Ͽ��� shoes.txt ���Ϸ� �����Ѵ�. (��� ��ȯ�� ���� shoes2.txt�� ����Ǿ� ����)

						fclose(fp);
						fclose(fpout);

						continue;

					case 3:

						printf("\n\n\t\t");
						return 0; // ���α׷� ����

					defalut:

						continue; // �̿��� ���� �Է��Ѵٸ�, ������ ��� �޴� �Լ� �ٽ� ȣ��

					}
				}
			}
			else // ������ ��й�ȣ ����ġ ��
			{
				printf("\n\n\t\t��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n");
				printf("\n\n\t\t<���α׷��� �����ϰڽ��ϴ�.....>\n\n\t\t");
				return 0;
			}

		}
	}
	else // ����� ����� ���
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t%s�� �ݰ����ϴ�.\n\n\n", id);
		printf("\t\t������ �Ź� ���θ��� �̵��մϴ�.\n\n");
		printf("\n\n\n\n\n\n\t\t\t\t\t      <<Press any key to continue>> \n\n\n\n");
		printf("\t\t\t\t\t\t\t     ");
		if ((input = _getch()) != EOF)
			system("cls"); // ȭ�� ��ȯ �Լ�
		while (1)
		{
			system("cls");
			menu2(); // ����� ��� �޴� �Լ�
			num2 = get_input();

			switch (num2) {

			case 1:

				system("cls");
				purchase(); // ����� ��� ���� �Լ�
				printf("\n\n\n\t\t\t\t\t      <<Press any key to continue>> \n\n\n\n");
				if ((input = _getch()) != EOF)
					system("cls");
				fp = fopen("shoes3.txt", "r");

				if (fp == NULL) {

					printf("���� ���� ����\n");
					return 0;

				}

				fpout = fopen("shoes.txt", "w");

				if (fpout == NULL) {

					printf("���� ���� ����\n");
					return 0;

				}
				while (fgets(buffer, 1000, fp) != NULL)
					fputs(buffer, fpout); // shoes3.txt ���Ͽ��� shoes.txt ���Ϸ� �����Ѵ�. (���� �Ϸ��� ���� shoes3.txt�� ����Ǿ� ����)

				fclose(fp);
				fclose(fpout);

				continue;

			case 2:
				system("cls");
				mypage(); // ���� ������ �ҷ����� �Լ�(ȯ�� �Լ� ����) 
				printf("\n\n\n\t\t\t\t\t      <<Press any key to continue>> \n\n\n\n");
				if ((input = _getch()) != EOF)
					system("cls");
				fp = fopen("purchase2.txt", "r");

				if (fp == NULL) {

					printf("���� ���� ����\n");
					return 0;

				}

				fpout = fopen("purchase.txt", "w");

				if (fpout == NULL) {

					printf("���� ���� ����\n");
					return 0;

				}

				while (fgets(buffer, 1000, fp) != NULL)
					fputs(buffer, fpout);

				fp2 = fopen("shoes4.txt", "r");

				if (fp2 == NULL) {

					printf("���� ���� ����\n");
					return 0;

				}

				fpout2 = fopen("shoes.txt", "w");

				if (fpout2 == NULL) {

					printf("���� ���� ����\n");
					return 0;

				}

				while (fgets(buffer2, 1000, fp2) != NULL)
					fputs(buffer2, fpout2); // shoes4.txt ���Ͽ��� shoes.txt ���Ϸ� �����ϰ� purchase2.txt ���Ͽ��� purchase.txt ���Ϸ� �����Ѵ�. (ȯ�� �Ϸ��� ���� shoes3.txt�� ����Ǿ� ����)

				fclose(fp);
				fclose(fpout);
				fclose(fp2);
				fclose(fpout2);

				continue;

			case 3:

				printf("\n\n\t\t");
				return 0; // ���α׷� ����

			default:

				continue; // �̿��� ���� �Է��Ѵٸ�, ����� ��� �޴� �Լ� �ٽ� ȣ��

			}



		}



	}

}

void menu1() { // ������ ��� �޴� �Լ�

	printf("\n\n\t\t====================");

	printf("\n\n\t\t <<������ ���α׷�>>");

	printf("\n\n\t\t1. ���� ����");

	printf("\n\n\t\t2. ��� ����");

	printf("\n\n\t\t3. ����");

	printf("\n\n\t\t====================\n");

}

void menu2() { // ����� ��� �޴� �Լ�

	printf("\n\n\t\t====================");

	printf("\n\n\t\t <<����� ���α׷�>>");

	printf("\n\n\t\t1. ��ǰ ����");

	printf("\n\n\t\t2. ���� ������");

	printf("\n\n\t\t3. ����");

	printf("\n\n\t\t====================\n");

}

int get_input() { // ���� �Է¹޴� �Լ�

	int num;

	printf("\n\n\t\t �������� �Է��Ͻÿ� : ");

	scanf("%d", &num);

	return num;

}

void change_price() // ���� ��ȯ �Լ�
{
	FILE* fp = NULL;
	FILE* fpout = NULL;

	char buffer[1000] = { 0 };
	char bf[1000] = { 0 };
	char brand[1000] = { 0 };
	char name[1000] = { 0 };
	char fname[1000] = { 0 };
	int fprice;
	int price, number;
	int count = 0;

	fp = fopen("shoes.txt", "r");

	if (fp == NULL) {

		printf("���� ���� ����\n");

	}

	fpout = fopen("shoes2.txt", "w");

	if (fpout == NULL) {

		printf("���� ���� ����\n");

	}
	printf("\n\n\t\t � ��ǰ�� ������ �����Ͻðڽ��ϱ�? ");
	scanf("%s", &fname); // ���ϴ� ��ǰ �̸� fname�� ����

	while (fgets(buffer, 1000, fp) != NULL) {

		sscanf(buffer, "%s %s %d %d", &brand, &name, &price, &number);

		fprintf(fpout, "%s ", brand);
		fprintf(fpout, "%s ", name); // ���ʴ�� shoes2.txt ���Ͽ� �����Ѵ�.
		if (strcmp(name, fname) == 0)
		{
			printf("\n\n\t\t ������ ���� : ");
			scanf("%d", &fprice);
			if (fprice < 0)
			{
				printf("\n\n\t\t�߸� ���� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
				exit(1);
			}
			fprintf(fpout, "%d ", fprice); // ���⼭ ����� ������ �Է¹ް� shoes2.txt ���Ͽ� ����� ���� ����
			count++;
		}
		else
			fprintf(fpout, "%d ", price); // �̸��� ���� �ʴٸ� �״���� ���� ���� 

		fprintf(fpout, "%d\n", number);

	}

	if (count == 0)
	{
		printf("\n\n\t\t�߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
		exit(1);
	} // ���� �Է¹��� �̸��� ��ǰ ����Ʈ�� ���ٸ� ����

	fclose(fp);
	fclose(fpout);

}

void change_number() // ��� ��ȯ �Լ�
{
	FILE* fp = NULL;

	FILE* fpout = NULL;

	char buffer[1000] = { 0 };
	char brand[1000] = { 0 };
	char name[1000] = { 0 };
	char fname[1000] = { 0 };
	int fnumber;
	int price, number;
	int count = 0;

	fp = fopen("shoes.txt", "r");

	if (fp == NULL) {

		printf("���� ���� ����\n");

	}

	fpout = fopen("shoes2.txt", "w");

	if (fpout == NULL) {

		printf("���� ���� ����\n");

	}
	printf("\n\n\t\t � ��ǰ�� ����� �����Ͻðڽ��ϱ�? ");
	scanf("%s", &fname); // ��� ������ ���ϴ� ��ǰ �̸��� �Է¹޴´�.
	while (fgets(buffer, 1000, fp) != NULL) {

		sscanf(buffer, "%s %s %d %d", &brand, &name, &price, &number);

		fprintf(fpout, "%s ", brand);
		fprintf(fpout, "%s ", name);
		fprintf(fpout, "%d ", price); // ���ʴ�� shoes2.txt ���Ͽ� �����Ѵ�.
		if (strcmp(name, fname) == 0) // �Է¹��� �̸��� ����Ʈ�� �̸��� ���ٸ�
		{
			printf("\n\n\t\t �����Ͻ� ��� : ");
			scanf("%d", &fnumber);
			if (fnumber < 0)
			{
				printf("\n\n\t\t�߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
				exit(1);
			}
			fprintf(fpout, "%d\n", fnumber); // �̸��� ���ٸ� �ش�Ǵ� ��ǰ�� ��� ����
			count++;
		}
		else
			fprintf(fpout, "%d\n", number); // �̸��� ���� �ʴٸ� �״���� ��� ����

	}

	if (count == 0)
	{
		printf("\n\n\t\t�߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
		exit(1);
	} // ���� �Է¹��� ��ǰ �̸��� ��ǰ ����Ʈ�� ���ٸ� ����

	fclose(fp);
	fclose(fpout);
}

void purchase() // ����� ��� ���� �Լ�
{
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	FILE* fpout = NULL;
	FILE* fpout2 = NULL;

	char buffer[1000] = { 0 };
	char brand[1000] = { 0 };
	char name[1000] = { 0 };
	char buffer2[1000] = { 0 };
	char brand2[1000] = { 0 };
	char name2[1000] = { 0 };
	char pname[1000] = { 0 };
	int pnumber;
	int price, number;
	int price2, number2;
	int tm;
	int count = 0;

	fp1 = fopen("shoes.txt", "r");
	fp2 = fopen("shoes.txt", "r");
	fpout = fopen("purchase.txt", "a");
	fpout2 = fopen("shoes3.txt", "w");

	if (fp1 == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}

	if (fp2 == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}

	if (fpout == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}

	if (fpout2 == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}

	printf("\n\n\t\t <<���� ���α׷�>> \n");
	printf("\n\n\t\t �����ݾ� : %d\n", money); // ���� �ݾ��� ���� ������ ������ money ���
	while (fgets(buffer, 1000, fp1) != NULL) {

		sscanf(buffer, "%s %s %d %d", &brand, &name, &price, &number);

		printf("\n\t\t%s ", brand);
		printf("%s ", name);
		printf("%d ", price);
		printf("%d ", number);

	} // ����Ʈ ����� ����Ѵ�.

	printf("\n\n\t\t �����ϰ� ���� ��ǰ �̸� : ");
	scanf("%s", &pname);

	printf("\n\n\t\t ���ż��� : ");
	scanf("%d", &pnumber); // �����ϰ� ���� ��ǰ�� �̸��� ������ �Է¹޴´�.

	while (fgets(buffer2, 1000, fp2) != NULL) {

		sscanf(buffer2, "%s %s %d %d", &brand2, &name2, &price2, &number2);
		fprintf(fpout2, "%s ", brand2);
		fprintf(fpout2, "%s ", name2);
		fprintf(fpout2, "%d ", price2);

		if (strcmp(name2, pname) == 0)
		{
			if ((number2 - pnumber) < 0)
			{
				printf("\n\n\t\t ���� ������ �߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
				exit(1);
			}
			printf("\n\n\t\t <<���Ű� �Ϸ�Ǿ����ϴ�!!>>");
			fprintf(fpout, "%s ", brand2);
			fprintf(fpout, "%s ", name2);
			fprintf(fpout, "%d ", price2);
			fprintf(fpout, "%d ", pnumber);
			tm = time(NULL); // time �Լ��� ����Ͽ� ���� �ð��� �����Ѵ�.
			fprintf(fpout, "%d\n", tm);
			money = money - pnumber * price2; // ���� ���� ���� * ���ݸ�ŭ ���ش�.
			number2 = number2 - pnumber;
			fprintf(fpout2, "%d\n", number2);
			count++;
		}
		else
			fprintf(fpout2, "%d\n", number2);
	}

	if (count == 0) {
		printf("\n\n\t\t �̸��� �߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
		exit(1);
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fpout);
	fclose(fpout2);

}

void mypage() // ���� �������� �����ִ� �Լ�
{
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;

	char buffer[1000] = { 0 };
	char brand[1000] = { 0 };
	char name[1000] = { 0 };
	char buffer2[1000] = { 0 };
	char brand2[1000] = { 0 };
	char name2[1000] = { 0 };
	char pname[1000] = { 0 };
	int rd;
	char rname[1000] = { 0 };
	int price, number, tm, tm2, rtm;
	int price2, number2;
	int count = 0;

	fp1 = fopen("purchase.txt", "r");
	fp2 = fopen("purchase.txt", "r");

	if (fp1 == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}

	if (fp2 == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}


	printf("\n\n\t\t <<���� ������>> \n");
	printf("\n\n\t\t�����ݾ� : %d", money);
	printf("\n\n\n\t\t <<���籸�Ը��>>");
	while (fgets(buffer, 1000, fp1) != NULL) {

		sscanf(buffer, "%s %s %d %d %d", &brand, &name, &price, &number, &tm);

		printf("\n\n\n\t\t%s ", brand);
		printf("%s ", name);
		printf("%d ", price);
		printf("%d ", number);
		printf("%d ", tm);

	} // ������� ���� ���� ����� ����Ѵ�.

	printf("\n\n\n\t\tȯ���Ͻðڽ��ϱ�?(y = 1/n = 0) ");
	scanf("%d", &rd); // ȯ�� ���� üũ

	if (rd == 1) // ȯ���ϰڴٸ�
	{
		printf("\n\n\t\tȯ���� ��ǰ�� �̸��� �Է��Ͻʽÿ� : ");
		scanf("%s", &rname); // ��ǰ �̸� üũ
		rtm = time(NULL); // ���� �ð��� rtm�� ����

		while (fgets(buffer2, 1000, fp2) != NULL) {

			sscanf(buffer2, "%s %s %d %d %d", &brand2, &name2, &price2, &number2, &tm2);
			if (strcmp(rname, name2) == 0) // ����Ʈ�� ȯ���ϰ� ���� ��ǰ�� �̸��� �ִٸ�
			{
				if (rtm - tm2 < 3600) // �׸��� ���� �ð��� ���� �ð��� ���̰� 1�ð��� ���� �� �����ٸ�
				{
					money = money + price2; // ȯ�� ���������Ƿ� ���� �ǵ��� �޴´�.
					refund(name2, number2); // ȯ�� �Լ� ȣ��
					printf("\n\n\t\t�����մϴ�.  %d�� ���̷� ȯ�ҿ� �����ϼ̽��ϴ�.", rtm - tm2);
				}
				else
				{
					printf("\n\n\t\t�˼��մϴ�.  %d�� ���̷� ȯ���� �Ұ����մϴ�.", rtm - tm2);
					exit(1); // ����
				}
				count++;
			}

			if (count == 0) {
				printf("\n\n\t\t�߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
				exit(1);
			} // ȯ���ϰ� ���� ��ǰ�� �̸��� ����Ʈ�� ���� ��� ����
		}
	}
	else if (rd == 0) // ȯ�� �ǻ� ���ΰ� �����̶��
		exit(1); // ����
	else
	{
		printf("\n\n\t\t�߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
		exit(1);
	}

	fclose(fp1);
	fclose(fp2);

}

void refund(char c[1000], int n) // ȯ�� �Լ�
{
	FILE* fp1 = NULL;
	FILE* fpout1 = NULL;
	FILE* fp2 = NULL;
	FILE* fpout2 = NULL;

	char buffer[1000] = { 0 };
	char brand[1000] = { 0 };
	char name[1000] = { 0 };
	char buffer2[1000] = { 0 };
	char brand2[1000] = { 0 };
	char name2[1000] = { 0 };
	char pname[1000] = { 0 };
	int rd;
	char rname[1000] = { 0 };
	int price, number, tm;
	int price2, number2;

	fp1 = fopen("purchase.txt", "r");
	fpout1 = fopen("purchase2.txt", "w");
	fp2 = fopen("shoes.txt", "r");
	fpout2 = fopen("shoes4.txt", "w");

	if (fp1 == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}

	if (fpout1 == NULL) {

		printf("���� ���� ����\n");
		exit(1);
	}

	while (fgets(buffer, 1000, fp1) != NULL)
	{
		sscanf(buffer, "%s %s %d %d %d", &brand, &name, &price, &number, &tm);

		if (strcmp(c, name) != 0)
		{
			fprintf(fpout1, "%s ", brand);
			fprintf(fpout1, "%s ", name);
			fprintf(fpout1, "%d ", price);
			fprintf(fpout1, "%d ", number);
			fprintf(fpout1, "%d\n", tm);
		}
	}

	while (fgets(buffer2, 1000, fp2) != NULL)
	{
		sscanf(buffer2, "%s %s %d %d", &brand2, &name2, &price2, &number2);

		fprintf(fpout2, "%s ", brand2);
		fprintf(fpout2, "%s ", name2);
		fprintf(fpout2, "%d ", price2);
		if (strcmp(c, name2) == 0)
		{
			number2 = number2 + n;
			fprintf(fpout2, "%d\n", number2);
		}
		else
			fprintf(fpout2, "%d\n", number2);
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fpout1);
	fclose(fpout2);

}