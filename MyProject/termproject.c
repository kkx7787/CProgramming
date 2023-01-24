#define _CRT_SECURE_NO_WARNINGS // scanf 사용문
#include <string.h> // 문자열 처리 라이브러리
#include <conio.h> // _getch 함수를 사용하기 위한 라이브러리
#include <stdio.h>
#include <stdlib.h> // 화면 전환 함수인 system("cls")과 exit를 사용하기 위한 라이브러리
#include <time.h> // 시간 함수를 사용하기 위한 라이브러리 (환불에 사용)

void menu1();
void menu2(); // 메뉴 함수
int get_input(); // 정수를 입력받는 함수
void change_price(); // 관리자 모드의 가격 전환 함수
void change_number(); // 관리자 모드의 재고량 전환 함수
void purchase(); // 사용자 모드의 구매 함수
void mypage(); // 마이 페이지를 보여주는 함수
void refund(char c[1000], int n); // 환불 함수

int money = 1000000; // 사용자의 초기 금액을 100000으로 초기화한다. (모든 함수에서 사용되기 때문에 전역 변수로 사용)

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
	printf("\n\t\t\t\t\t <<스포츠 신발 쇼핑몰 관리 프로그램>> \t\t\t\t\t\t\n\n\n\n\n");
	printf("\t\t\t\t\t      Press any key to continue\n\n\n\n");
	printf("\t\t\t\t\t\t\t   ");
	if ((input = _getch()) != EOF)
		system("cls"); // 키 입력 받고 화면 전환

	printf("\n\n\n\n\n\n\t\t쇼핑몰에서 사용할 닉네임 : ");
	scanf("%s", &id);

	cpid = strcmp("admin", id); // 만약 닉네임으로 admin을 입력했다면

	if (cpid == 0)
	{
		while (1)
		{
			printf("\n\n\t\t관리자의 비밀번호 : ");
			scanf("%s", &pw);

			cppw = strcmp("7881", pw); // 비밀번호도 옳게 입력했다면

			if (cppw == 0) // 관리자 모드로 접속
			{
				while (1)
				{
					system("cls");
					menu1(); // 관리자 모드 메뉴 함수 호출
					num1 = get_input(); // 번호 입력

					switch (num1) {

					case 1:

						change_price(); // 가격 전환 함수
						fp = fopen("shoes2.txt", "r");

						if (fp == NULL) {

							printf("파일 열기 실패\n");
							return 0;

						}

						fpout = fopen("shoes.txt", "w");

						if (fpout == NULL) {

							printf("파일 열기 실패\n");
							return 0;

						}
						while (fgets(buffer, 1000, fp) != NULL)
							fputs(buffer, fpout); // shoes2.txt 파일에서 shoes.txt 파일로 복사한다. (가격 전환한 것이 shoes2.txt에 적용되어 있음)

						fclose(fp);
						fclose(fpout);
						continue;

					case 2:

						change_number(); // 재고량 전환 함수
						fp = fopen("shoes2.txt", "r");

						if (fp == NULL) {

							printf("파일 열기 실패\n");
							return 0;

						}

						fpout = fopen("shoes.txt", "w");

						if (fpout == NULL) {

							printf("파일 열기 실패\n");
							return 0;

						}
						while (fgets(buffer, 1000, fp) != NULL)
							fputs(buffer, fpout); // shoes2.txt 파일에서 shoes.txt 파일로 복사한다. (재고량 전환한 것이 shoes2.txt에 적용되어 있음)

						fclose(fp);
						fclose(fpout);

						continue;

					case 3:

						printf("\n\n\t\t");
						return 0; // 프로그램 종료

					defalut:

						continue; // 이외의 것을 입력한다면, 관리자 모드 메뉴 함수 다시 호출

					}
				}
			}
			else // 관리자 비밀번호 불일치 시
			{
				printf("\n\n\t\t비밀번호가 일치하지 않습니다.\n");
				printf("\n\n\t\t<프로그램을 종료하겠습니다.....>\n\n\t\t");
				return 0;
			}

		}
	}
	else // 사용자 모드일 경우
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t%s님 반갑습니다.\n\n\n", id);
		printf("\t\t스포츠 신발 쇼핑몰로 이동합니다.\n\n");
		printf("\n\n\n\n\n\n\t\t\t\t\t      <<Press any key to continue>> \n\n\n\n");
		printf("\t\t\t\t\t\t\t     ");
		if ((input = _getch()) != EOF)
			system("cls"); // 화면 전환 함수
		while (1)
		{
			system("cls");
			menu2(); // 사용자 모드 메뉴 함수
			num2 = get_input();

			switch (num2) {

			case 1:

				system("cls");
				purchase(); // 사용자 모드 구매 함수
				printf("\n\n\n\t\t\t\t\t      <<Press any key to continue>> \n\n\n\n");
				if ((input = _getch()) != EOF)
					system("cls");
				fp = fopen("shoes3.txt", "r");

				if (fp == NULL) {

					printf("파일 열기 실패\n");
					return 0;

				}

				fpout = fopen("shoes.txt", "w");

				if (fpout == NULL) {

					printf("파일 열기 실패\n");
					return 0;

				}
				while (fgets(buffer, 1000, fp) != NULL)
					fputs(buffer, fpout); // shoes3.txt 파일에서 shoes.txt 파일로 복사한다. (구매 완료한 것이 shoes3.txt에 적용되어 있음)

				fclose(fp);
				fclose(fpout);

				continue;

			case 2:
				system("cls");
				mypage(); // 마이 페이지 불러오는 함수(환불 함수 포함) 
				printf("\n\n\n\t\t\t\t\t      <<Press any key to continue>> \n\n\n\n");
				if ((input = _getch()) != EOF)
					system("cls");
				fp = fopen("purchase2.txt", "r");

				if (fp == NULL) {

					printf("파일 열기 실패\n");
					return 0;

				}

				fpout = fopen("purchase.txt", "w");

				if (fpout == NULL) {

					printf("파일 열기 실패\n");
					return 0;

				}

				while (fgets(buffer, 1000, fp) != NULL)
					fputs(buffer, fpout);

				fp2 = fopen("shoes4.txt", "r");

				if (fp2 == NULL) {

					printf("파일 열기 실패\n");
					return 0;

				}

				fpout2 = fopen("shoes.txt", "w");

				if (fpout2 == NULL) {

					printf("파일 열기 실패\n");
					return 0;

				}

				while (fgets(buffer2, 1000, fp2) != NULL)
					fputs(buffer2, fpout2); // shoes4.txt 파일에서 shoes.txt 파일로 복사하고 purchase2.txt 파일에서 purchase.txt 파일로 복사한다. (환불 완료한 것이 shoes3.txt에 적용되어 있음)

				fclose(fp);
				fclose(fpout);
				fclose(fp2);
				fclose(fpout2);

				continue;

			case 3:

				printf("\n\n\t\t");
				return 0; // 프로그램 종료

			default:

				continue; // 이외의 것을 입력한다면, 사용자 모드 메뉴 함수 다시 호출

			}



		}



	}

}

void menu1() { // 관리자 모드 메뉴 함수

	printf("\n\n\t\t====================");

	printf("\n\n\t\t <<관리자 프로그램>>");

	printf("\n\n\t\t1. 가격 변경");

	printf("\n\n\t\t2. 재고량 변경");

	printf("\n\n\t\t3. 종료");

	printf("\n\n\t\t====================\n");

}

void menu2() { // 사용자 모드 메뉴 함수

	printf("\n\n\t\t====================");

	printf("\n\n\t\t <<사용자 프로그램>>");

	printf("\n\n\t\t1. 상품 구매");

	printf("\n\n\t\t2. 마이 페이지");

	printf("\n\n\t\t3. 종료");

	printf("\n\n\t\t====================\n");

}

int get_input() { // 정수 입력받는 함수

	int num;

	printf("\n\n\t\t 정수값을 입력하시오 : ");

	scanf("%d", &num);

	return num;

}

void change_price() // 가격 전환 함수
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

		printf("파일 열기 실패\n");

	}

	fpout = fopen("shoes2.txt", "w");

	if (fpout == NULL) {

		printf("파일 열기 실패\n");

	}
	printf("\n\n\t\t 어떤 제품의 가격을 변경하시겠습니까? ");
	scanf("%s", &fname); // 원하는 제품 이름 fname에 저장

	while (fgets(buffer, 1000, fp) != NULL) {

		sscanf(buffer, "%s %s %d %d", &brand, &name, &price, &number);

		fprintf(fpout, "%s ", brand);
		fprintf(fpout, "%s ", name); // 차례대로 shoes2.txt 파일에 복사한다.
		if (strcmp(name, fname) == 0)
		{
			printf("\n\n\t\t 변경할 가격 : ");
			scanf("%d", &fprice);
			if (fprice < 0)
			{
				printf("\n\n\t\t잘못 가격 입력하셨습니다. 프로그램을 종료합니다.\n");
				exit(1);
			}
			fprintf(fpout, "%d ", fprice); // 여기서 변경된 가격을 입력받고 shoes2.txt 파일에 변경된 가격 적용
			count++;
		}
		else
			fprintf(fpout, "%d ", price); // 이름이 같지 않다면 그대로의 가격 적용 

		fprintf(fpout, "%d\n", number);

	}

	if (count == 0)
	{
		printf("\n\n\t\t잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
		exit(1);
	} // 만약 입력받은 이름이 물품 리스트에 없다면 종료

	fclose(fp);
	fclose(fpout);

}

void change_number() // 재고량 전환 함수
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

		printf("파일 열기 실패\n");

	}

	fpout = fopen("shoes2.txt", "w");

	if (fpout == NULL) {

		printf("파일 열기 실패\n");

	}
	printf("\n\n\t\t 어떤 제품의 재고량을 변경하시겠습니까? ");
	scanf("%s", &fname); // 재고량 변경을 원하는 물품 이름을 입력받는다.
	while (fgets(buffer, 1000, fp) != NULL) {

		sscanf(buffer, "%s %s %d %d", &brand, &name, &price, &number);

		fprintf(fpout, "%s ", brand);
		fprintf(fpout, "%s ", name);
		fprintf(fpout, "%d ", price); // 차례대로 shoes2.txt 파일에 복사한다.
		if (strcmp(name, fname) == 0) // 입력받은 이름과 리스트의 이름이 같다면
		{
			printf("\n\n\t\t 변경하실 재고량 : ");
			scanf("%d", &fnumber);
			if (fnumber < 0)
			{
				printf("\n\n\t\t잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
				exit(1);
			}
			fprintf(fpout, "%d\n", fnumber); // 이름이 같다면 해당되는 제품의 재고량 변경
			count++;
		}
		else
			fprintf(fpout, "%d\n", number); // 이름이 같지 않다면 그대로의 재고량 적용

	}

	if (count == 0)
	{
		printf("\n\n\t\t잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
		exit(1);
	} // 만약 입력받은 물품 이름이 물품 리스트에 없다면 종료

	fclose(fp);
	fclose(fpout);
}

void purchase() // 사용자 모드 구매 함수
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

		printf("파일 열기 실패\n");
		exit(1);
	}

	if (fp2 == NULL) {

		printf("파일 열기 실패\n");
		exit(1);
	}

	if (fpout == NULL) {

		printf("파일 열기 실패\n");
		exit(1);
	}

	if (fpout2 == NULL) {

		printf("파일 열기 실패\n");
		exit(1);
	}

	printf("\n\n\t\t <<구매 프로그램>> \n");
	printf("\n\n\t\t 소유금액 : %d\n", money); // 소유 금액은 전역 변수로 선언한 money 사용
	while (fgets(buffer, 1000, fp1) != NULL) {

		sscanf(buffer, "%s %s %d %d", &brand, &name, &price, &number);

		printf("\n\t\t%s ", brand);
		printf("%s ", name);
		printf("%d ", price);
		printf("%d ", number);

	} // 리스트 목록을 출력한다.

	printf("\n\n\t\t 구매하고 싶은 상품 이름 : ");
	scanf("%s", &pname);

	printf("\n\n\t\t 구매수량 : ");
	scanf("%d", &pnumber); // 구매하고 싶은 제품의 이름과 수량을 입력받는다.

	while (fgets(buffer2, 1000, fp2) != NULL) {

		sscanf(buffer2, "%s %s %d %d", &brand2, &name2, &price2, &number2);
		fprintf(fpout2, "%s ", brand2);
		fprintf(fpout2, "%s ", name2);
		fprintf(fpout2, "%d ", price2);

		if (strcmp(name2, pname) == 0)
		{
			if ((number2 - pnumber) < 0)
			{
				printf("\n\n\t\t 구매 수량을 잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
				exit(1);
			}
			printf("\n\n\t\t <<구매가 완료되었습니다!!>>");
			fprintf(fpout, "%s ", brand2);
			fprintf(fpout, "%s ", name2);
			fprintf(fpout, "%d ", price2);
			fprintf(fpout, "%d ", pnumber);
			tm = time(NULL); // time 함수를 사용하여 구매 시간을 저장한다.
			fprintf(fpout, "%d\n", tm);
			money = money - pnumber * price2; // 돈은 구매 수량 * 가격만큼 빼준다.
			number2 = number2 - pnumber;
			fprintf(fpout2, "%d\n", number2);
			count++;
		}
		else
			fprintf(fpout2, "%d\n", number2);
	}

	if (count == 0) {
		printf("\n\n\t\t 이름을 잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
		exit(1);
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fpout);
	fclose(fpout2);

}

void mypage() // 마이 페이지를 보여주는 함수
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

		printf("파일 열기 실패\n");
		exit(1);
	}

	if (fp2 == NULL) {

		printf("파일 열기 실패\n");
		exit(1);
	}


	printf("\n\n\t\t <<마이 페이지>> \n");
	printf("\n\n\t\t소유금액 : %d", money);
	printf("\n\n\n\t\t <<현재구입목록>>");
	while (fgets(buffer, 1000, fp1) != NULL) {

		sscanf(buffer, "%s %s %d %d %d", &brand, &name, &price, &number, &tm);

		printf("\n\n\n\t\t%s ", brand);
		printf("%s ", name);
		printf("%d ", price);
		printf("%d ", number);
		printf("%d ", tm);

	} // 사용자의 현재 구입 목록을 출력한다.

	printf("\n\n\n\t\t환불하시겠습니까?(y = 1/n = 0) ");
	scanf("%d", &rd); // 환불 여부 체크

	if (rd == 1) // 환불하겠다면
	{
		printf("\n\n\t\t환불한 상품의 이름을 입력하십시오 : ");
		scanf("%s", &rname); // 상품 이름 체크
		rtm = time(NULL); // 현재 시간을 rtm에 저장

		while (fgets(buffer2, 1000, fp2) != NULL) {

			sscanf(buffer2, "%s %s %d %d %d", &brand2, &name2, &price2, &number2, &tm2);
			if (strcmp(rname, name2) == 0) // 리스트에 환불하고 싶은 제품의 이름이 있다면
			{
				if (rtm - tm2 < 3600) // 그리고 구매 시간과 현재 시간의 차이가 1시간이 아직 안 지났다면
				{
					money = money + price2; // 환불 성공했으므로 돈은 되돌려 받는다.
					refund(name2, number2); // 환불 함수 호출
					printf("\n\n\t\t축하합니다.  %d초 차이로 환불에 성공하셨습니다.", rtm - tm2);
				}
				else
				{
					printf("\n\n\t\t죄송합니다.  %d초 차이로 환불이 불가능합니다.", rtm - tm2);
					exit(1); // 종료
				}
				count++;
			}

			if (count == 0) {
				printf("\n\n\t\t잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
				exit(1);
			} // 환불하고 싶은 제품의 이름이 리스트에 없을 경우 종료
		}
	}
	else if (rd == 0) // 환불 의사 여부가 부정이라면
		exit(1); // 종료
	else
	{
		printf("\n\n\t\t잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
		exit(1);
	}

	fclose(fp1);
	fclose(fp2);

}

void refund(char c[1000], int n) // 환불 함수
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

		printf("파일 열기 실패\n");
		exit(1);
	}

	if (fpout1 == NULL) {

		printf("파일 열기 실패\n");
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