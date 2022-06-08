#define _CRT_SECURE_NO_WARNINGS
#define LEFT 75 //방향키 정의
#define RIGHT 77
#define UP 72
#define DOWN 80
#include <stdio.h>
#include <stdbool.h>//boolean 타입 전용 헤더
#include <conio.h> //방향키 입력받을 때 사용하는 헤더
void display_manu(); //게임 시작 화면
bool answer_check(int problem_num, int sol); //정답체크
void selected_num(int num);//입력받은 메뉴 번호로 어떻게 동작할지
int get_number(); // 메뉴 번호 입력받음
void go_on(int story_num); //스토리 진행 함수
void how_to_play(); //게임 방법
void problem_bedroom(); //침실
void problem_kitchen(); //주방
int lock_input(void);//주방-방향자물쇠
void problem_storage(); //창고
void problem_yard(); //마당
void problem_diningroom(); //거실
void selected_bedroom1();
void selected_bedroom2();
void selected_bed();
void selected_namecard();
void selected_desk1();
void selected_desk2();
void selected_thirddesk();
void selected_clothse();
void selected_roomchoice();
void selected_kitchen1();
void selected_kitchen2();
void selected_kitchen3();
void selected_saucejar();
void selected_microwave();
void selected_kitchenchoice();
void selected_yard1();
void selected_yard2();
void selected_chickenhouse();
void selected_water();
void selected_letterbox();
void selected_storage1();
void selected_storage2();
void selected_fusebox();
void selected_paper();
void selected_storagechoice();
void selected_diningroom();
void selected_sofa();
void selected_diningroomchoice();
void selected_allchoice();
void selected_bedroomfinal();
void selected_kitchenfinal();
void selected_yardfinal();
void selected_storagefinal();
void selected_bedfinal();
void selected_clothsefinal();
void selected_deskfinal();
void selected_microwavefinal();
void selected_waterfinal();
void selected_letterboxfinal();
void selected_paperfinal();
void get_hint(int probelm_num, int hint_num);//힌트함수
//get_key(); //각 방에서 문제 풀때마다 얻는 열쇠 저장하는 함수  구현 필요
//demage(); //데미지 함수     구현 필요
//seek(); //방안 탐색 함수     구현 필요

void main(void) //메인
{
	int num;
	display_manu();
	while (1) {
		num = get_number();
		if (num == 3) {
			printf("종료합니다.\n");
			break;
		}
	}
}
void display_manu() //게임 시작 화면 보이기
{
	for (int i = 0; i < 30; i++) printf("=");
	printf("\n방 탈 출\n");
	for (int i = 0; i < 30; i++) printf("=");
	printf("\n환영합니다!\n방탈출 하러 오셨죠?\n");
	printf("\n1. GAME START\n2. HOW TO PLAY \n3. QUIT\n");
}

int get_number() //번호 입력 받음, 잘못된 번호인지 체크
{
	int num;
	printf("번호를 입력하세요: ");
	scanf("%d", &num);
	if ((num > 3) || (num < 1))
	{
		printf("잘못된 번호를 입력하였습니다.\n");
		get_number();
	}
	else if (num == 3)
	{
		return num;
	}
	else
		selected_num(num);
}
bool answer_check(int problem_num, int sol) //정답체크함수, 일단 정수 형태의 정답만 체크하는데 문자 형태는 어떻게 할지 고민 필요
{
	int answer;
	int hint_num = 0;
	printf("정답을 입력하세요: ");
	scanf("%d", &answer);
	if (answer == 0) {
		hint_num++;
		get_hint(problem_num, hint_num);
	}
	else {
		if (sol != answer)
		{
			return false;
		}

		else
		{
			return true;
		}
	}
}


void get_hint(int probelm_num, int hint_num) {
	switch (probelm_num)
	{
	case 1:
		if (hint_num == 1) {
			printf("침실을 살펴봐라.\n");
		}
		else if (hint_num == 2) {
			printf("침대를 살펴봐라.\n");
		}
		else if (hint_num == 3) {
			printf("침대 숫자를 살펴봐라.\n");
		}
		break;
	case 2:
		if (hint_num == 1) {
			printf("자물쇠는 5자리다.");
		}
		else if (hint_num == 2)
		{
			printf("각각 어떤 방향을 갖는지 유추해보면 된다");
		}
		else if(hint_num == 3)
		{
			printf("물은 어디에서 어디로 흘러가는가?");
		}
		break;
	case 3:
		if (hint_num == 1)
		{
			printf("동물과 ?을 조합해봐라.\n(소 + ? = o)\n");
		}
		else if (hint_num == 2)
		{
			printf("한글(동물)을 영어로 바꿔서 생각해봐라.\n(cow + ? = o)\n");
		}
		else if(hint_num == 3)
		{
			printf("알파벳을 하나씩 나열한 뒤 문제에서 나타난 알파벳의 자릿수를 생각해봐라.\n(c (1) o (2) w (3) + ? = o)\n");
		}
		break;
	case 4:
		if (hint_num == 1)
		{
			printf("덧셈을 해봐라.");
		}
		else if (hint_num == 2)
		{
			printf("앞과 뒤에가 관련이 있다.");
		}
		else if(hint_num == 3)
		{
			printf("두개씩 묶어 앞에서부터 차례대로 숫자를 더해봐라.\n(1+1=2)");
		}
		break;
	case 5:
		if (hint_num == 1)
		{
			printf("영어와 숫자를 조합해봐라.\n");
		}
		else if (hint_num == 2)
		{
			printf("알파벳과 숫자를 나열해봐라.\n");
		}
		else if (hint_num == 3)
		{
			printf("A부터 Z까지 나열하고 A부터 1부터 맞춰봐라.\n");
		}
		break;
	}
}
int damage(int heart) {
	heart--;
	if (heart == 0) {
		go_on(7);
	}
	return heart;
}

void selected_num(int num) //메뉴 선택 시 동작 어떻게 할지 정해주는 함수
{
	int story_num = 1;
	switch (num)
	{
	case 1:
		go_on(story_num);
		printf("메인 메뉴로 돌아갑니다.\n");
		break;
	case 2:
		how_to_play();
		printf("메인 메뉴로 돌아갑니다.\n");
		break;
	case 3:
		printf("종료합니다.\n");
		break;
	}
}
void go_on(int story_num) { //스토리 진행 함수
	while (1) {
		switch (story_num)
		{
		case 1:
			printf("환영합니다!!!\n방탈출 하러 오셨죠? 꼭 탈출 하시길 바랍니다.\n그럼 시작하겠습니다.\n");
			printf(".\n.\n.\n.\n.\n꿈벅 꿈벅\n이 곳은 어디지? 처음보는 곳이다.\n아늑해 보이면서 서늘한 기운이 감돈다.\n");
			printf("이 곳을 나가야 한다.\n둘러보니\n");
			selected_bedroom1();
			break;
		case 2:
			printf("끼익-\n이 곳은 주방인 것 같다.\n");
			selected_kitchen1();
			break;
		case 3:
			printf("끼익-\n햇빛이 비춘다.\n높은 담이 사방에 둘러져 있다. 담을 타고 탈출하기에는 어렵다.\n");
			selected_yard1();
			break;
		case 4:
			printf("끼익-\n캐캐한 냄새가 난다.\n어둡다.불을 켜보자.\n");
			printf(".\n.\n.\n탁!\n");
			selected_storage1();
			break;
		case 5:
			printf("끼익-\n거실이다.\n");
			selected_diningroom();
			break;
		case 6:
			printf("철컥\n문이 열렸다!!\n눈이 부시다.푸른 들판이 펼쳐져 있다.\n===Happy Ending===\n");
			display_manu();
			break;
		default:
			printf("움직일 수가 없다.\n 차갑다\n 기계 소리가 크게 들린다.\n 위잉 위잉\n 아프다..아프다..\n");
			printf(".\n.\n.\n.\n.\n.\n일련번호:1226 A++ 돼지고기 금액:$$$$$\n===Bad Ending===\n");
			break;
		}
		break;
	}
}
void how_to_play() {
	printf("텍스트로 된 방 탈출 게임이다. 총 스테이지가 5개로 구성되어 있다. 각 스테이지를 클리어하면 다음 스테이지로 넘어간다. 스테이지를 넘어가기 전에 문제들이 있다.\n");
	printf("문제를 틀릴 때마다 데미지가 하나씩 소멸된다. 데미지는 3번 부여된다.\n");
	printf("문제가 어렵다고 느끼면 힌트를 사용하면 된다. 힌트는 3번 사용할 수 있다.\n");
	printf("꼭 탈출을 하길 바란다.\n");
}

void problem_bedroom() { //침실 문제
	printf("침실을 살펴봐라.\n_ _ _ _ (숫자)\n");
	int sol = 1226; //문제의 정답
	if (!answer_check(1, sol)) { // 정답과 입력한 답 비교해서 오답이면 메시지 출력 후 하트 감소
		for (int damage = 2; damage > 0; damage--) {
			printf("오답입니다. ♥ 1개 감소됩니다.\n");
			answer_check(1, sol); //problem_bedroom();//오답이니 같은 문제로 다시 돌아감
		}
		go_on(7);
	}
	else {
		printf("열쇠를 획득했다!!\n");
		selected_bedroom2(); // 정답이면 다음 스테이지로.
	}
}

void problem_kitchen() {
	int thing;
	int c;
	printf("아래는 어깨 형님들의 대화 녹취록이다. 잘 보고 답을 유추해서 방향 자물쇠를 해제해라!\n");
	printf(" ---------------------------------------------- \n");
	printf("|                 M E M O                      |\n");
	printf("|                                              |\n");
	printf("| 한놈: 9시까지 어떻게 좀 해봐..               |\n");
	printf("| 두식이: 물 흐르듯이 진행시키겠습니다!        |\n");
	printf("| 석삼이: 그런데요 행님, 천장이 좀 이상한데요? |\n");
	printf("| 너구리: 왼손잡이 전용 칼은 없나?             |\n");
	printf("| 오징어: 이러다 다 죽어~ alright?             |\n");
	printf(" ----------------------------------------------\n");
	printf("방향 자물쇠를 풀어 볼까?\n1.예 2.아니오:");
	scanf("%d", &c);
	if (c == 1) {
		lock_input();
	}
	else
		selected_kitchen1();
}

int lock_input(void) {
	char c;
	int lock[5];
	int locknum;
	int sol[5] = { 1,4,3,1,2 };
	for (int i = 0; i < 5; i++) {
		c = _getch();
		if (c == -32) {
			c = _getch();
			switch (c) {
			case LEFT:
				locknum = 1;
				printf("←\n");
				break;
			case RIGHT:
				locknum = 2;
				printf("→\n");
				break;
			case UP:
				locknum = 3;
				printf("↑\n");
				break;
			case DOWN:
				locknum = 4;
				printf("↓\n");
				break;
			}
		}
		lock[i] = locknum;
	}
	int hint_yn = 1;
	int hint_num = 1;
	int heart = 3;
	for (int j = 0; j < 5; j++) {
		if (lock[j] != sol[j]) {
			printf("오답입니다. ♥ 1개 감소됩니다.");
			printf("힌트를 쓰시려면 0번을 입력해주세요.");
			scanf("%d", &hint_yn);
			if (hint_yn == 0) {
				get_hint(2, hint_num);
				hint_num++;
				//damage(heart);  //데미지 함수 만들기
				problem_kitchen();//오답이니 같은 문제로 다시 돌아감
			}
		}
		else {
			printf("열쇠를 획득했다!!\n");
			selected_kitchen2(); // 정답이면 다음 스테이지로.
		}
	}
	return 0;
}

void problem_storage() {//창고 문제 함수
	printf("닭 ? + 소 2 + 돼지 ? + 말2 ? = pork\n _ _ _ _(숫자)\n");
	int sol = 5213;  //문제의 정답
	if (!answer_check(3, sol)) { // 정답과 입력한 답 비교해서 오답이면 메시지 출력 후 하트 감소
		for (int damage = 2; damage > 0; damage--) {
			printf("오답입니다. ♥ 1개 감소됩니다.\n");
			answer_check(3, sol);//오답이니 같은 문제로 다시 돌아감
		}
		go_on(7);
	}
	else {
		printf("열쇠를 획득했다!!\n");
		selected_storage2(); // 정답이면 다음 스테이지로.
	}
}
void problem_yard() {
	printf("1123581321????489144233");
	int sol = 3455; //문제의 정답
	if (!answer_check(4, sol)) { // 정답과 입력한 답 비교해서 오답이면 메시지 출력 후 하트 감소
		for (int damage = 2; damage > 0; damage--) {
			printf("오답입니다. ♥ 1개 감소됩니다.\n");
			answer_check(4, sol);//오답이니 같은 문제로 다시 돌아감
		}
	}
	else {
		printf("열쇠를 획득했다!!\n");
		selected_yard2(); // 정답이면 다음 스테이지로.
	}
}
void problem_diningroom() {
	char ans[6]={0};
	printf("모은 종이들을 종합해보시오.\n_ _ _ _ _ _(대문자영어)\n");
	printf("종이들을 모아보니 1, 9, 9, 16, 7, 13이 나왔다.");
	scanf("%s", &ans);
	char sol[6] = "IAMPIG"; //문제의 정답
	int hint_yn = 1;
	int hint_num = 1;
	for (int j = 0; j < 6; j++) {
		if (ans[j] != sol[j]) {
			printf("오답입니다. ♥ 1개 감소됩니다.");
			printf("힌트를 쓰시려면 0번을 입력해주세요.");
			scanf("%d", &hint_yn);
			if (hint_yn == 0) {
				get_hint(5, hint_num);
				hint_num++;
				//damage();  //데미지 함수 만들기
				problem_diningroom();//오답이니 같은 문제로 다시 돌아감

			}
			else
				break;
		}
		else {
			//go_on(6); // 정답이면 다음 스테이지로.
			printf("철컥\n문이 열렸다!!\n눈이 부시다.푸른 들판이 펼쳐져 있다.\n===Happy Ending===\n");
			display_manu();
		}
	}
}

void selected_bedroom1()
{
	int num;
	printf("1.침대 2.옷장 3.책상 4.문\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("이불을 들쳐 보니 피가 묻어 있다. 피??\n지푸라기도 여기저기 있다.\n");
		printf("글자가 있다.\n");
		selected_bed();
		selected_bedroom1();
		break;
	case 2:
		printf("매캐한 냄새가 난다. 옷이 많지 않다.\n");
		printf("옷??\n");
		selected_clothse();
		break;
	case 3:
		printf("의자를 꺼내 앉았다. 책상 위에는 담배, 이름표, 맥주 2병이 있다.\n");
		printf("이름표??\n");
		selected_namecard();
		selected_desk1();
		break;
	case 4:
		printf("닫혔습니다.\n");
		selected_bedroom1();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_bedroom1();
		break;
	}
}

void selected_bedroom2() {
	int num;
	printf("1.침대 2.옷장 3.책상 4.문\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("이불을 들쳐 보니 피가 묻어 있다. 피??\n지푸라기도 여기저기 있다.\n");
		printf("글자가 있다.\n");
		selected_bed();
		selected_bedroom2();
		break;
	case 2:
		printf("매캐한 냄새가 난다. 옷이 많지 않다.\n");
		printf("옷??\n");
		selected_clothse();
		break;
	case 3:
		printf("의자를 꺼내 앉았다. 책상 위에는 담배, 이름표, 맥주 2병이 있다.\n");
		printf("이름표??\n");
		selected_namecard();
		selected_desk2();
		break;
	case 4:
		printf("철컥\n열렸다!\n");
		selected_roomchoice();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_bedroom2();
		break;
	}
}
void selected_bed() {
	int num;
	printf("1.본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("12시..26분..\n");
		printf("무엇을 뜻하는 걸까?\n");
		selected_bedroom1();
		selected_bedroom2();
		break;
	case 2:
		selected_bedroom1();
		selected_bedroom2();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_bed();
		break;
	}
}
void selected_namecard()
{
	int num;
	printf("1.본다. 2.안 본다.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("1226 A++\n");
		printf("무슨 뜻일까?\n");
		break;
	case 2:
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_namecard();
		break;
	}
}
void selected_desk1()
{
	int num;
	printf("밑에 서랍이 있다.서랍??\n");
here:
	printf("1.첫번째 2.두번째 3.세번째 4.지나간다.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("비어있다.\n");
		goto here;
		break;
	case 2:
		printf("아무것도 적혀있지 않는 이름표들이 있다.\n");
		goto here;
		break;
	case 3:
		printf("비밀번호를 풀어야 열린다.\n");
		selected_thirddesk();
		break;
	case 4:
		selected_bedroom1();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_desk1();
		break;
	}
}
void selected_desk2() {
	int num;
	printf("밑에 서랍이 있다.서랍??\n");
here:
	printf("1.첫번째 2.두번째 3.세번째 4.지나간다.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("비어있다.\n");
		goto here;
		break;
	case 2:
		printf("아무것도 적혀있지 않는 이름표들이 있다.\n");
		goto here;
		break;
	case 3:
		printf("비어있다.\n");
		goto here;
		break;
	case 4:
		selected_bedroom2();
		selected_bedroomfinal();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_desk2();
		break;
	}
}

void selected_thirddesk()
{
	int num;
	printf("1.푼다. 2.안 푼다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_bedroom(3);
		break;
	case 2:
		selected_desk1();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_thirddesk();
		break;
	}
}
void selected_clothse()
{
	int num;
	printf("1.살펴본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("종이가 있다.\n");
		printf("\'16\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_bedroom1();
		selected_bedroom2();
		break;
	case 2:
		selected_bedroom1();
		selected_bedroom2();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_clothse();
		break;
	}
}

void selected_roomchoice()
{
	int num;
	printf("1.다음 방으로 간다. 2.다시 둘러본다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		go_on(2);
		break;
	case 2:
		selected_bedroom2();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_roomchoice();
		break;
	}
}

void selected_kitchen1()
{
	int num;
	printf("1.냉장고 2.싱크대 3.식탁 4.흰 문 5.갈색 문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("문을 열어보니 돼지고기, 닭고기, 계란, 맥주들이 있다.\n");
		selected_kitchen1();
		break;
	case 2:
		printf("다 먹은 컵라면들이 여기저기 널 부려져 있다. 피가 묻어 있는 칼과 도마가 있다.\n");
		printf("빈 소스통 안에 열쇠가 있다.\n");
		printf("열쇠를 얻을려면 비밀번호를 풀어한다.\n");
		selected_saucejar();
		break;
	case 3:
		printf("여기저기 빈 맥주병들이 있고 전자레인지가 있다.\n");
		printf("전자레인지??\n");
		selected_microwave();
		break;
	case 4:
		printf("잠겨있다\n");
		selected_kitchen1();
		break;
	case 5:
		printf("잠겨있다\n");
		selected_kitchen1();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_kitchen1();
		break;
	}
}
void selected_kitchen2()
{
	int num;
	printf("1.냉장고 2.싱크대 3.식탁 4.흰 문 5.갈색 문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("문을 열어보니 돼지고기, 닭고기, 계란, 맥주들이 있다.\n");
		selected_kitchen2();
		break;
	case 2:
		printf("다 먹은 컵라면들이 여기저기 널 부려져 있다. 피가 묻어 있는 칼과 도마가 있다.\n");
		printf("소스통이 열려있다.\n");
		selected_kitchen2();
		break;
	case 3:
		printf("여기저기 빈 맥주병들이 있고 전자레인지가 있다.\n");
		printf("전자레인지??\n");
		selected_microwave();
		break;
	case 4:
		printf("철컥철컥\n열리지 않는다. 이 문이 아닌 것 같다.\n");
		selected_kitchen2();
		break;
	case 5:
		printf("철컥\n열렸다!\n");
		selected_kitchenchoice();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_kitchen2();
		break;
	}
}
void selected_saucejar()
{
	int num;
	printf("1.푼다. 2.안 푼다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_kitchen();
		break;
	case 2:
		selected_kitchen1();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_kitchen1();
		break;
	}

}
void selected_microwave()
{
	int num;
	printf("1.살펴본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("종이가 있다.\n");
		printf("\'1\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_kitchen1();
		selected_kitchen2();
		selected_kitchen3();
		break;
	case 2:
		selected_kitchen1();
		selected_kitchen2();
		selected_kitchen3();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_kitchen1();
		selected_kitchen2();
		selected_kitchen3();
		break;
	}
}
void selected_kitchenchoice() {
	int num;
	printf("1.다음 방으로 간다. 2.다시 둘러본다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		go_on(3);
		break;
	case 2:
		selected_kitchen2();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_kitchenchoice();
		break;
	}
}
void selected_yard1()
{
	int num;
	printf("1.우물 2.텃밭 3.우체통 4.닭장 5.부엌\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("깊어 보이지 않는다. 목마른데 물을 마실까?\n");
		selected_water();
		break;
	case 2:
		printf("상추, 토마토, 고추들이 주렁주렁 있다.\n");
		selected_yard1();
		break;
	case 3:
		printf("우체통??\n");
		selected_letterbox();
		break;
	case 4:
		printf("닭들이 있다. 자세히 보니 안 쪽에 열쇠가 있다.\n");
		printf("열쇠를 얻을려면 비밀번호를 풀어야한다.\n");
		selected_chickenhouse();
		break;
	case 5:
		selected_kitchen2();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_yard1();
		break;
	}
}
void selected_yard2() {
	int num;
	printf("1.우물 2.텃밭 3.우체통 4.닭장 5.부엌\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("깊어 보이지 않는다. 목마른데 물 마실까?\n");
		selected_water();
		break;
	case 2:
		printf("상추, 토마토, 고추들이 주렁주렁 있다.\n");
		selected_yard2();
		break;
	case 3:
		printf("우체통??\n");
		selected_letterbox();
		break;
	case 4:
		printf("닭들이 있다.\n");
		selected_yard2();
		break;
	case 5:
		selected_kitchen3();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_yard2();
		break;
	}
}
void selected_chickenhouse()
{
	int num;
	printf("1.푼다. 2.안푼다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_yard();
		break;
	case 2:
		selected_yard1();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_chickenhouse();
		break;
	}
}
void selected_water()
{
	int num;
	printf("1.마신다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("시원하다~\n");
		selected_yard1();
		selected_yard2();
		break;
	case 2:
		selected_yard1();
		selected_yard2();
		break;
	default:
		printf("잘못된 번호입니다.\n");
		selected_water();
		break;
	}
}
void selected_letterbox()
{
	int num;
	printf("1.연다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("종이가 있다.\n");
		printf("\'7\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_yard1();
		selected_yard2();
		break;
	case 2:
		selected_yard1();
		selected_yard2();
		break;
	}
}

void selected_kitchen3() {
	int num;
	printf("1.냉장고 2.싱크대 3.식탁 4.흰 문 5.갈색 문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("문을 열어보니 돼지고기, 닭고기, 계란, 맥주들이 있다.\n");
		selected_kitchen3();
		break;
	case 2:
		printf("다 먹은 컵라면들이 여기저기 널 부려져 있다. 피가 묻어 있는 칼과 도마가 있다.\n");
		printf("소스통이 열려있다.\n");
		selected_kitchen3();
		break;
	case 3:
		printf("여기저기 빈 맥주병들이 있고 전자레인지가 있다.\n");
		printf("전자레인지??\n");
		selected_microwave();
		break;
	case 4:
		printf("철컥\n열렸다!\n");
		go_on(4);
		break;
	case 5:
		printf("철컥\n열렸다!\n");
		selected_kitchenchoice();
		break;
	}
}

void selected_storage1()
{
	int num;
	printf("1.펜스 2.벽 3.책상 4.문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("돼지들이 있다. 안 쪽에 무언가 있는 것 같은데..\n");
		printf("어두워 보이지 않는다. 안 쪽에서 기계소리가 들리는 것 같다\n");
		selected_storage1();
		break;
	case 2:
		printf("날카로운 도끼들이 걸어져 있다. 칼날 끝에 피가 묻어 있다.\n");
		printf("퓨즈박스가 있다. 열려면 비밀번호를 풀어야한다.\n");
		selected_fusebox();
		break;
	case 3:
		printf("의자에 빨간 앞치마가 걸쳐 있다.\n책상 위에는 담배, 종이, 펜들이 있다.\n");
		printf("종이들 사이에 한 종이가 눈에 띈다\n");
		selected_paper();
		break;
	case 4:
		printf("잠겨있다.\n");
		selected_storage1();
		break;
	}
}

void selected_storage2() {
	int num;
	printf("1.펜스 2.벽 3.책상 4.문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("돼지들이 있다. 안 쪽에 무언가 있는 것 같은데..\n");
		printf("어두워 보이지 않는다. 안 쪽에서 기계소리가 들리는 것 같다\n");
		selected_storage2();
		break;
	case 2:
		printf("날카로운 도끼들이 걸어져 있다. 칼날 끝에 피가 묻어 있다.\n");
		printf("퓨즈박스가 있다. 비어있다.\n");
		selected_storage2();
		break;
	case 3:
		printf("의자에 빨간 앞치마가 걸쳐 있다.\n책상 위에는 담배, 종이, 펜들이 있다.\n");
		printf("종이들 사이에 한 종이가 눈에 띈다\n");
		selected_paper();
		break;
	case 4:
		printf("철컥\n열렸다!\n");
		selected_storagechoice();
		break;
	}

}
void selected_fusebox()
{
	int num;
	printf("1.푼다. 2.안푼다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_storage();
		break;
	case 2:
		selected_storage1();
		selected_storage2();
		break;
	}
}
void selected_paper()
{
	int num;
	printf("1.살펴본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("\'9\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_storage1();
		selected_storage2();
		break;
	case 2:
		selected_storage1();
		selected_storage2();
		break;
	}
}

void selected_storagechoice() {
	int num;
	printf("1.다음 방으로 간다. 2.다시 둘러본다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		go_on(5);
		break;

	case 2:
		selected_storage2();
		break;
	}
}

void selected_diningroom()
{
	int num;
	printf("1.소파 2.티비 3.게시판 4.문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("오래된 갈색 가죽 소파이다.\n사이에 무언가 있다.\n");
		selected_sofa();
		break;
	case 2:
		printf("꺼져있다.\n");
		selected_diningroom();
		break;
	case 3:
		printf("&&월&&일 거래완료 금액:$$$$$$.\n&&월&&일 거래 금액:$$$$$$.\n");
		printf("&&월&&일 거래 금액:$$$$$$$.\n");
		printf("'13'\n");
		selected_diningroom();
		break;
	case 4:
		printf("잠겨있다.\n");
		selected_diningroomchoice();
		break;
	}
}
void selected_sofa()
{
	int num;
	printf("1.살펴본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("종이가 있다.\n");
		printf("\'9\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_diningroom();
		break;
	case 2:
		selected_diningroom();
		break;
	}
}
void selected_diningroomchoice() {
	int num;
	printf("1.탈출한다. 2.둘러본다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_diningroom();
		break;
	case 2:
		selected_allchoice();
		break;
	}
}
void selected_allchoice() {
	int num;
	printf("1.거실 2.침실 3.주방 4.마당 5.창고\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		selected_diningroom();
		break;
	case 2:
		selected_bedroomfinal();
		break;
	case 3:
		selected_kitchenfinal();
		break;
	case 4:
		selected_yardfinal();
		break;
	case 5:
		selected_storagefinal();
		break;
	}
}
void selected_bedroomfinal()
{
	int num;
	printf("1.침대 2.옷장 3.책상 4.거실 문\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("이불을 들쳐 보니 피가 묻어 있다. 피??\n지푸라기도 여기저기 있다.\n");
		printf("글자가 있다.\n");
		selected_bedfinal();
		selected_bedroomfinal();
		break;
	case 2:
		printf("매캐한 냄새가 난다. 옷이 많지 않다.\n");
		printf("옷??\n");
		selected_clothsefinal();
		break;
	case 3:
		printf("의자를 꺼내 앉았다. 책상 위에는 담배, 이름표, 맥주 2병이 있다.\n");
		printf("이름표??\n");
		selected_namecard();
		selected_deskfinal();
		break;
	case 4:
		selected_diningroomchoice();
		break;
	}
}
void selected_bedfinal() {
	int num;
	printf("1.본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("12시..26분..\n");
		printf("무엇을 뜻하는 걸까?\n");
		selected_bedroomfinal();
		break;
	case 2:
		selected_bedroomfinal();
		break;
	}
}
void selected_clothsefinal() {
	int num;
	printf("1.살펴본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("종이가 있다.\n");
		printf("\'16\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_bedroomfinal();
		break;
	case 2:
		selected_bedroomfinal();
		break;
	}
}
void selected_deskfinal() {
	int num;
	printf("밑에 서랍이 있다.서랍??\n");
here:
	printf("1.첫번째 2.두번째 3.세번째 4.지나간다.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("비어있다.\n");
		goto here;
		break;
	case 2:
		printf("아무것도 적혀있지 않는 이름표들이 있다.\n");
		goto here;
		break;
	case 3:
		printf("비어있다.\n");
		goto here;
		break;
	case 4:
		selected_bedroomfinal();
		break;
	}
}

void selected_kitchenfinal() {
	int num;
	printf("1.냉장고 2.싱크대 3.식탁 4.거실 문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("문을 열어보니 돼지고기, 닭고기, 계란, 맥주들이 있다.\n");
		selected_kitchenfinal();
		break;
	case 2:
		printf("다 먹은 컵라면들이 여기저기 널 부려져 있다. 피가 묻어 있는 칼과 도마가 있다.\n");
		printf("소스통이 열려있다.\n");
		selected_kitchenfinal();
		break;
	case 3:
		printf("여기저기 빈 맥주병들이 있고 전자레인지가 있다.\n");
		printf("전자레인지??\n");
		selected_microwavefinal();
		break;
	case 4:
		selected_diningroomchoice();
		break;
	}
}
void selected_microwavefinal() {
	int num;
	printf("1.살펴본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("종이가 있다.\n");
		printf("\'1\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_kitchenfinal();
		break;
	case 2:
		selected_kitchenfinal();
		break;
	}
}
void selected_yardfinal() {
	int num;
	printf("1.우물 2.텃밭 3.우체통 4.닭장 5.거실 문\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("깊어 보이지 않는다. 목마른데 물 마실까?\n");
		selected_waterfinal();
		break;
	case 2:
		printf("상추, 토마토, 고추들이 주렁주렁 있다.\n");
		selected_yardfinal();
		break;
	case 3:
		printf("우체통??\n");
		selected_letterboxfinal();
		break;
	case 4:
		printf("닭들이 있다.\n");
		selected_yardfinal();
		break;
	case 5:
		selected_diningroomchoice();
		break;
	}
}
void selected_waterfinal() {
	int num;
	printf("1.마신다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("시원한다~\n");
		selected_yardfinal();
		break;
	case 2:
		selected_yardfinal();
		break;
	}
}
void selected_letterboxfinal() {
	int num;
	printf("1.연다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("종이가 있다.\n");
		printf("\'7\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_yardfinal();
		break;
	case 2:
		selected_yardfinal();
		break;
	}
}
void selected_storagefinal() {
	int num;
	printf("1.펜스 2.벽 3.책상 4.거실 문\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("돼지들이 있다. 안 쪽에 무언가 있는 것 같은데..\n");
		printf("어두워 보이지 않는다. 안 쪽에서 기계소리가 들리는 것 같다\n");
		selected_storagefinal();
		break;
	case 2:
		printf("날카로운 도끼들이 걸어져 있다. 칼날 끝에 피가 묻어 있다.\n");
		printf("퓨즈박스가 있다. 비어있다.\n");
		selected_storagefinal();
		break;
	case 3:
		printf("의자에 빨간 앞치마가 걸쳐 있다.\n책상 위에는 담배, 종이, 펜들이 있다.\n");
		printf("종이들 사이에 한 종이가 눈에 띈다\n");
		selected_paperfinal();
		break;
	case 4:
		selected_diningroomchoice();
		break;
	}
}
void selected_paperfinal() {
	int num;
	printf("1.살펴본다. 2.지나간다.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("\'9\'라고 적혀있다.\n");
		printf("가지고 있어야겠다.\n");
		selected_storagefinal();
		break;
	case 2:
		selected_storagefinal();
		break;
	}
}

