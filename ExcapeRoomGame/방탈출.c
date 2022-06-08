#define _CRT_SECURE_NO_WARNINGS
#define LEFT 75 //����Ű ����
#define RIGHT 77
#define UP 72
#define DOWN 80
#include <stdio.h>
#include <stdbool.h>//boolean Ÿ�� ���� ���
#include <conio.h> //����Ű �Է¹��� �� ����ϴ� ���
void display_manu(); //���� ���� ȭ��
bool answer_check(int problem_num, int sol); //����üũ
void selected_num(int num);//�Է¹��� �޴� ��ȣ�� ��� ��������
int get_number(); // �޴� ��ȣ �Է¹���
void go_on(int story_num); //���丮 ���� �Լ�
void how_to_play(); //���� ���
void problem_bedroom(); //ħ��
void problem_kitchen(); //�ֹ�
int lock_input(void);//�ֹ�-�����ڹ���
void problem_storage(); //â��
void problem_yard(); //����
void problem_diningroom(); //�Ž�
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
void get_hint(int probelm_num, int hint_num);//��Ʈ�Լ�
//get_key(); //�� �濡�� ���� Ǯ������ ��� ���� �����ϴ� �Լ�  ���� �ʿ�
//demage(); //������ �Լ�     ���� �ʿ�
//seek(); //��� Ž�� �Լ�     ���� �ʿ�

void main(void) //����
{
	int num;
	display_manu();
	while (1) {
		num = get_number();
		if (num == 3) {
			printf("�����մϴ�.\n");
			break;
		}
	}
}
void display_manu() //���� ���� ȭ�� ���̱�
{
	for (int i = 0; i < 30; i++) printf("=");
	printf("\n�� Ż ��\n");
	for (int i = 0; i < 30; i++) printf("=");
	printf("\nȯ���մϴ�!\n��Ż�� �Ϸ� ������?\n");
	printf("\n1. GAME START\n2. HOW TO PLAY \n3. QUIT\n");
}

int get_number() //��ȣ �Է� ����, �߸��� ��ȣ���� üũ
{
	int num;
	printf("��ȣ�� �Է��ϼ���: ");
	scanf("%d", &num);
	if ((num > 3) || (num < 1))
	{
		printf("�߸��� ��ȣ�� �Է��Ͽ����ϴ�.\n");
		get_number();
	}
	else if (num == 3)
	{
		return num;
	}
	else
		selected_num(num);
}
bool answer_check(int problem_num, int sol) //����üũ�Լ�, �ϴ� ���� ������ ���丸 üũ�ϴµ� ���� ���´� ��� ���� ��� �ʿ�
{
	int answer;
	int hint_num = 0;
	printf("������ �Է��ϼ���: ");
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
			printf("ħ���� �������.\n");
		}
		else if (hint_num == 2) {
			printf("ħ�븦 �������.\n");
		}
		else if (hint_num == 3) {
			printf("ħ�� ���ڸ� �������.\n");
		}
		break;
	case 2:
		if (hint_num == 1) {
			printf("�ڹ���� 5�ڸ���.");
		}
		else if (hint_num == 2)
		{
			printf("���� � ������ ������ �����غ��� �ȴ�");
		}
		else if(hint_num == 3)
		{
			printf("���� ��𿡼� ���� �귯���°�?");
		}
		break;
	case 3:
		if (hint_num == 1)
		{
			printf("������ ?�� �����غ���.\n(�� + ? = o)\n");
		}
		else if (hint_num == 2)
		{
			printf("�ѱ�(����)�� ����� �ٲ㼭 �����غ���.\n(cow + ? = o)\n");
		}
		else if(hint_num == 3)
		{
			printf("���ĺ��� �ϳ��� ������ �� �������� ��Ÿ�� ���ĺ��� �ڸ����� �����غ���.\n(c (1) o (2) w (3) + ? = o)\n");
		}
		break;
	case 4:
		if (hint_num == 1)
		{
			printf("������ �غ���.");
		}
		else if (hint_num == 2)
		{
			printf("�հ� �ڿ��� ������ �ִ�.");
		}
		else if(hint_num == 3)
		{
			printf("�ΰ��� ���� �տ������� ���ʴ�� ���ڸ� ���غ���.\n(1+1=2)");
		}
		break;
	case 5:
		if (hint_num == 1)
		{
			printf("����� ���ڸ� �����غ���.\n");
		}
		else if (hint_num == 2)
		{
			printf("���ĺ��� ���ڸ� �����غ���.\n");
		}
		else if (hint_num == 3)
		{
			printf("A���� Z���� �����ϰ� A���� 1���� �������.\n");
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

void selected_num(int num) //�޴� ���� �� ���� ��� ���� �����ִ� �Լ�
{
	int story_num = 1;
	switch (num)
	{
	case 1:
		go_on(story_num);
		printf("���� �޴��� ���ư��ϴ�.\n");
		break;
	case 2:
		how_to_play();
		printf("���� �޴��� ���ư��ϴ�.\n");
		break;
	case 3:
		printf("�����մϴ�.\n");
		break;
	}
}
void go_on(int story_num) { //���丮 ���� �Լ�
	while (1) {
		switch (story_num)
		{
		case 1:
			printf("ȯ���մϴ�!!!\n��Ż�� �Ϸ� ������? �� Ż�� �Ͻñ� �ٶ��ϴ�.\n�׷� �����ϰڽ��ϴ�.\n");
			printf(".\n.\n.\n.\n.\n�޹� �޹�\n�� ���� �����? ó������ ���̴�.\n�ƴ��� ���̸鼭 ������ ����� ������.\n");
			printf("�� ���� ������ �Ѵ�.\n�ѷ�����\n");
			selected_bedroom1();
			break;
		case 2:
			printf("����-\n�� ���� �ֹ��� �� ����.\n");
			selected_kitchen1();
			break;
		case 3:
			printf("����-\n�޺��� �����.\n���� ���� ��濡 �ѷ��� �ִ�. ���� Ÿ�� Ż���ϱ⿡�� ��ƴ�.\n");
			selected_yard1();
			break;
		case 4:
			printf("����-\nĳĳ�� ������ ����.\n��Ӵ�.���� �Ѻ���.\n");
			printf(".\n.\n.\nŹ!\n");
			selected_storage1();
			break;
		case 5:
			printf("����-\n�Ž��̴�.\n");
			selected_diningroom();
			break;
		case 6:
			printf("ö��\n���� ���ȴ�!!\n���� �νô�.Ǫ�� ������ ������ �ִ�.\n===Happy Ending===\n");
			display_manu();
			break;
		default:
			printf("������ ���� ����.\n ������\n ��� �Ҹ��� ũ�� �鸰��.\n ���� ����\n ������..������..\n");
			printf(".\n.\n.\n.\n.\n.\n�Ϸù�ȣ:1226 A++ ������� �ݾ�:$$$$$\n===Bad Ending===\n");
			break;
		}
		break;
	}
}
void how_to_play() {
	printf("�ؽ�Ʈ�� �� �� Ż�� �����̴�. �� ���������� 5���� �����Ǿ� �ִ�. �� ���������� Ŭ�����ϸ� ���� ���������� �Ѿ��. ���������� �Ѿ�� ���� �������� �ִ�.\n");
	printf("������ Ʋ�� ������ �������� �ϳ��� �Ҹ�ȴ�. �������� 3�� �ο��ȴ�.\n");
	printf("������ ��ƴٰ� ������ ��Ʈ�� ����ϸ� �ȴ�. ��Ʈ�� 3�� ����� �� �ִ�.\n");
	printf("�� Ż���� �ϱ� �ٶ���.\n");
}

void problem_bedroom() { //ħ�� ����
	printf("ħ���� �������.\n_ _ _ _ (����)\n");
	int sol = 1226; //������ ����
	if (!answer_check(1, sol)) { // ����� �Է��� �� ���ؼ� �����̸� �޽��� ��� �� ��Ʈ ����
		for (int damage = 2; damage > 0; damage--) {
			printf("�����Դϴ�. �� 1�� ���ҵ˴ϴ�.\n");
			answer_check(1, sol); //problem_bedroom();//�����̴� ���� ������ �ٽ� ���ư�
		}
		go_on(7);
	}
	else {
		printf("���踦 ȹ���ߴ�!!\n");
		selected_bedroom2(); // �����̸� ���� ����������.
	}
}

void problem_kitchen() {
	int thing;
	int c;
	printf("�Ʒ��� ��� ���Ե��� ��ȭ ������̴�. �� ���� ���� �����ؼ� ���� �ڹ��踦 �����ض�!\n");
	printf(" ---------------------------------------------- \n");
	printf("|                 M E M O                      |\n");
	printf("|                                              |\n");
	printf("| �ѳ�: 9�ñ��� ��� �� �غ�..               |\n");
	printf("| �ν���: �� �帣���� �����Ű�ڽ��ϴ�!        |\n");
	printf("| ������: �׷����� ���, õ���� �� �̻��ѵ���? |\n");
	printf("| �ʱ���: �޼����� ���� Į�� ����?             |\n");
	printf("| ��¡��: �̷��� �� �׾�~ alright?             |\n");
	printf(" ----------------------------------------------\n");
	printf("���� �ڹ��踦 Ǯ�� ����?\n1.�� 2.�ƴϿ�:");
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
				printf("��\n");
				break;
			case RIGHT:
				locknum = 2;
				printf("��\n");
				break;
			case UP:
				locknum = 3;
				printf("��\n");
				break;
			case DOWN:
				locknum = 4;
				printf("��\n");
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
			printf("�����Դϴ�. �� 1�� ���ҵ˴ϴ�.");
			printf("��Ʈ�� ���÷��� 0���� �Է����ּ���.");
			scanf("%d", &hint_yn);
			if (hint_yn == 0) {
				get_hint(2, hint_num);
				hint_num++;
				//damage(heart);  //������ �Լ� �����
				problem_kitchen();//�����̴� ���� ������ �ٽ� ���ư�
			}
		}
		else {
			printf("���踦 ȹ���ߴ�!!\n");
			selected_kitchen2(); // �����̸� ���� ����������.
		}
	}
	return 0;
}

void problem_storage() {//â�� ���� �Լ�
	printf("�� ? + �� 2 + ���� ? + ��2 ? = pork\n _ _ _ _(����)\n");
	int sol = 5213;  //������ ����
	if (!answer_check(3, sol)) { // ����� �Է��� �� ���ؼ� �����̸� �޽��� ��� �� ��Ʈ ����
		for (int damage = 2; damage > 0; damage--) {
			printf("�����Դϴ�. �� 1�� ���ҵ˴ϴ�.\n");
			answer_check(3, sol);//�����̴� ���� ������ �ٽ� ���ư�
		}
		go_on(7);
	}
	else {
		printf("���踦 ȹ���ߴ�!!\n");
		selected_storage2(); // �����̸� ���� ����������.
	}
}
void problem_yard() {
	printf("1123581321????489144233");
	int sol = 3455; //������ ����
	if (!answer_check(4, sol)) { // ����� �Է��� �� ���ؼ� �����̸� �޽��� ��� �� ��Ʈ ����
		for (int damage = 2; damage > 0; damage--) {
			printf("�����Դϴ�. �� 1�� ���ҵ˴ϴ�.\n");
			answer_check(4, sol);//�����̴� ���� ������ �ٽ� ���ư�
		}
	}
	else {
		printf("���踦 ȹ���ߴ�!!\n");
		selected_yard2(); // �����̸� ���� ����������.
	}
}
void problem_diningroom() {
	char ans[6]={0};
	printf("���� ���̵��� �����غ��ÿ�.\n_ _ _ _ _ _(�빮�ڿ���)\n");
	printf("���̵��� ��ƺ��� 1, 9, 9, 16, 7, 13�� ���Դ�.");
	scanf("%s", &ans);
	char sol[6] = "IAMPIG"; //������ ����
	int hint_yn = 1;
	int hint_num = 1;
	for (int j = 0; j < 6; j++) {
		if (ans[j] != sol[j]) {
			printf("�����Դϴ�. �� 1�� ���ҵ˴ϴ�.");
			printf("��Ʈ�� ���÷��� 0���� �Է����ּ���.");
			scanf("%d", &hint_yn);
			if (hint_yn == 0) {
				get_hint(5, hint_num);
				hint_num++;
				//damage();  //������ �Լ� �����
				problem_diningroom();//�����̴� ���� ������ �ٽ� ���ư�

			}
			else
				break;
		}
		else {
			//go_on(6); // �����̸� ���� ����������.
			printf("ö��\n���� ���ȴ�!!\n���� �νô�.Ǫ�� ������ ������ �ִ�.\n===Happy Ending===\n");
			display_manu();
		}
	}
}

void selected_bedroom1()
{
	int num;
	printf("1.ħ�� 2.���� 3.å�� 4.��\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("�̺��� ���� ���� �ǰ� ���� �ִ�. ��??\n��Ǫ��⵵ �������� �ִ�.\n");
		printf("���ڰ� �ִ�.\n");
		selected_bed();
		selected_bedroom1();
		break;
	case 2:
		printf("��ĳ�� ������ ����. ���� ���� �ʴ�.\n");
		printf("��??\n");
		selected_clothse();
		break;
	case 3:
		printf("���ڸ� ���� �ɾҴ�. å�� ������ ���, �̸�ǥ, ���� 2���� �ִ�.\n");
		printf("�̸�ǥ??\n");
		selected_namecard();
		selected_desk1();
		break;
	case 4:
		printf("�������ϴ�.\n");
		selected_bedroom1();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_bedroom1();
		break;
	}
}

void selected_bedroom2() {
	int num;
	printf("1.ħ�� 2.���� 3.å�� 4.��\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("�̺��� ���� ���� �ǰ� ���� �ִ�. ��??\n��Ǫ��⵵ �������� �ִ�.\n");
		printf("���ڰ� �ִ�.\n");
		selected_bed();
		selected_bedroom2();
		break;
	case 2:
		printf("��ĳ�� ������ ����. ���� ���� �ʴ�.\n");
		printf("��??\n");
		selected_clothse();
		break;
	case 3:
		printf("���ڸ� ���� �ɾҴ�. å�� ������ ���, �̸�ǥ, ���� 2���� �ִ�.\n");
		printf("�̸�ǥ??\n");
		selected_namecard();
		selected_desk2();
		break;
	case 4:
		printf("ö��\n���ȴ�!\n");
		selected_roomchoice();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_bedroom2();
		break;
	}
}
void selected_bed() {
	int num;
	printf("1.����. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("12��..26��..\n");
		printf("������ ���ϴ� �ɱ�?\n");
		selected_bedroom1();
		selected_bedroom2();
		break;
	case 2:
		selected_bedroom1();
		selected_bedroom2();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_bed();
		break;
	}
}
void selected_namecard()
{
	int num;
	printf("1.����. 2.�� ����.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("1226 A++\n");
		printf("���� ���ϱ�?\n");
		break;
	case 2:
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_namecard();
		break;
	}
}
void selected_desk1()
{
	int num;
	printf("�ؿ� ������ �ִ�.����??\n");
here:
	printf("1.ù��° 2.�ι�° 3.����° 4.��������.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("����ִ�.\n");
		goto here;
		break;
	case 2:
		printf("�ƹ��͵� �������� �ʴ� �̸�ǥ���� �ִ�.\n");
		goto here;
		break;
	case 3:
		printf("��й�ȣ�� Ǯ��� ������.\n");
		selected_thirddesk();
		break;
	case 4:
		selected_bedroom1();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_desk1();
		break;
	}
}
void selected_desk2() {
	int num;
	printf("�ؿ� ������ �ִ�.����??\n");
here:
	printf("1.ù��° 2.�ι�° 3.����° 4.��������.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("����ִ�.\n");
		goto here;
		break;
	case 2:
		printf("�ƹ��͵� �������� �ʴ� �̸�ǥ���� �ִ�.\n");
		goto here;
		break;
	case 3:
		printf("����ִ�.\n");
		goto here;
		break;
	case 4:
		selected_bedroom2();
		selected_bedroomfinal();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_desk2();
		break;
	}
}

void selected_thirddesk()
{
	int num;
	printf("1.Ǭ��. 2.�� Ǭ��.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_bedroom(3);
		break;
	case 2:
		selected_desk1();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_thirddesk();
		break;
	}
}
void selected_clothse()
{
	int num;
	printf("1.���캻��. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���̰� �ִ�.\n");
		printf("\'16\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
		selected_bedroom1();
		selected_bedroom2();
		break;
	case 2:
		selected_bedroom1();
		selected_bedroom2();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_clothse();
		break;
	}
}

void selected_roomchoice()
{
	int num;
	printf("1.���� ������ ����. 2.�ٽ� �ѷ�����.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		go_on(2);
		break;
	case 2:
		selected_bedroom2();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_roomchoice();
		break;
	}
}

void selected_kitchen1()
{
	int num;
	printf("1.����� 2.��ũ�� 3.��Ź 4.�� �� 5.���� ��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���� ����� �������, �߰��, ���, ���ֵ��� �ִ�.\n");
		selected_kitchen1();
		break;
	case 2:
		printf("�� ���� �Ŷ����� �������� �� �η��� �ִ�. �ǰ� ���� �ִ� Į�� ������ �ִ�.\n");
		printf("�� �ҽ��� �ȿ� ���谡 �ִ�.\n");
		printf("���踦 �������� ��й�ȣ�� Ǯ���Ѵ�.\n");
		selected_saucejar();
		break;
	case 3:
		printf("�������� �� ���ֺ����� �ְ� ���ڷ������� �ִ�.\n");
		printf("���ڷ�����??\n");
		selected_microwave();
		break;
	case 4:
		printf("����ִ�\n");
		selected_kitchen1();
		break;
	case 5:
		printf("����ִ�\n");
		selected_kitchen1();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_kitchen1();
		break;
	}
}
void selected_kitchen2()
{
	int num;
	printf("1.����� 2.��ũ�� 3.��Ź 4.�� �� 5.���� ��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���� ����� �������, �߰��, ���, ���ֵ��� �ִ�.\n");
		selected_kitchen2();
		break;
	case 2:
		printf("�� ���� �Ŷ����� �������� �� �η��� �ִ�. �ǰ� ���� �ִ� Į�� ������ �ִ�.\n");
		printf("�ҽ����� �����ִ�.\n");
		selected_kitchen2();
		break;
	case 3:
		printf("�������� �� ���ֺ����� �ְ� ���ڷ������� �ִ�.\n");
		printf("���ڷ�����??\n");
		selected_microwave();
		break;
	case 4:
		printf("ö��ö��\n������ �ʴ´�. �� ���� �ƴ� �� ����.\n");
		selected_kitchen2();
		break;
	case 5:
		printf("ö��\n���ȴ�!\n");
		selected_kitchenchoice();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_kitchen2();
		break;
	}
}
void selected_saucejar()
{
	int num;
	printf("1.Ǭ��. 2.�� Ǭ��.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_kitchen();
		break;
	case 2:
		selected_kitchen1();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_kitchen1();
		break;
	}

}
void selected_microwave()
{
	int num;
	printf("1.���캻��. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���̰� �ִ�.\n");
		printf("\'1\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
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
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_kitchen1();
		selected_kitchen2();
		selected_kitchen3();
		break;
	}
}
void selected_kitchenchoice() {
	int num;
	printf("1.���� ������ ����. 2.�ٽ� �ѷ�����.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		go_on(3);
		break;
	case 2:
		selected_kitchen2();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_kitchenchoice();
		break;
	}
}
void selected_yard1()
{
	int num;
	printf("1.�칰 2.�Թ� 3.��ü�� 4.���� 5.�ξ�\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("��� ������ �ʴ´�. �񸶸��� ���� ���Ǳ�?\n");
		selected_water();
		break;
	case 2:
		printf("����, �丶��, ���ߵ��� �ַ��ַ� �ִ�.\n");
		selected_yard1();
		break;
	case 3:
		printf("��ü��??\n");
		selected_letterbox();
		break;
	case 4:
		printf("�ߵ��� �ִ�. �ڼ��� ���� �� �ʿ� ���谡 �ִ�.\n");
		printf("���踦 �������� ��й�ȣ�� Ǯ����Ѵ�.\n");
		selected_chickenhouse();
		break;
	case 5:
		selected_kitchen2();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_yard1();
		break;
	}
}
void selected_yard2() {
	int num;
	printf("1.�칰 2.�Թ� 3.��ü�� 4.���� 5.�ξ�\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("��� ������ �ʴ´�. �񸶸��� �� ���Ǳ�?\n");
		selected_water();
		break;
	case 2:
		printf("����, �丶��, ���ߵ��� �ַ��ַ� �ִ�.\n");
		selected_yard2();
		break;
	case 3:
		printf("��ü��??\n");
		selected_letterbox();
		break;
	case 4:
		printf("�ߵ��� �ִ�.\n");
		selected_yard2();
		break;
	case 5:
		selected_kitchen3();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_yard2();
		break;
	}
}
void selected_chickenhouse()
{
	int num;
	printf("1.Ǭ��. 2.��Ǭ��.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		problem_yard();
		break;
	case 2:
		selected_yard1();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_chickenhouse();
		break;
	}
}
void selected_water()
{
	int num;
	printf("1.���Ŵ�. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("�ÿ��ϴ�~\n");
		selected_yard1();
		selected_yard2();
		break;
	case 2:
		selected_yard1();
		selected_yard2();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		selected_water();
		break;
	}
}
void selected_letterbox()
{
	int num;
	printf("1.����. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���̰� �ִ�.\n");
		printf("\'7\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
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
	printf("1.����� 2.��ũ�� 3.��Ź 4.�� �� 5.���� ��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���� ����� �������, �߰��, ���, ���ֵ��� �ִ�.\n");
		selected_kitchen3();
		break;
	case 2:
		printf("�� ���� �Ŷ����� �������� �� �η��� �ִ�. �ǰ� ���� �ִ� Į�� ������ �ִ�.\n");
		printf("�ҽ����� �����ִ�.\n");
		selected_kitchen3();
		break;
	case 3:
		printf("�������� �� ���ֺ����� �ְ� ���ڷ������� �ִ�.\n");
		printf("���ڷ�����??\n");
		selected_microwave();
		break;
	case 4:
		printf("ö��\n���ȴ�!\n");
		go_on(4);
		break;
	case 5:
		printf("ö��\n���ȴ�!\n");
		selected_kitchenchoice();
		break;
	}
}

void selected_storage1()
{
	int num;
	printf("1.�潺 2.�� 3.å�� 4.��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("�������� �ִ�. �� �ʿ� ���� �ִ� �� ������..\n");
		printf("��ο� ������ �ʴ´�. �� �ʿ��� ���Ҹ��� �鸮�� �� ����\n");
		selected_storage1();
		break;
	case 2:
		printf("��ī�ο� �������� �ɾ��� �ִ�. Į�� ���� �ǰ� ���� �ִ�.\n");
		printf("ǻ��ڽ��� �ִ�. ������ ��й�ȣ�� Ǯ����Ѵ�.\n");
		selected_fusebox();
		break;
	case 3:
		printf("���ڿ� ���� ��ġ���� ���� �ִ�.\nå�� ������ ���, ����, ����� �ִ�.\n");
		printf("���̵� ���̿� �� ���̰� ���� ���\n");
		selected_paper();
		break;
	case 4:
		printf("����ִ�.\n");
		selected_storage1();
		break;
	}
}

void selected_storage2() {
	int num;
	printf("1.�潺 2.�� 3.å�� 4.��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("�������� �ִ�. �� �ʿ� ���� �ִ� �� ������..\n");
		printf("��ο� ������ �ʴ´�. �� �ʿ��� ���Ҹ��� �鸮�� �� ����\n");
		selected_storage2();
		break;
	case 2:
		printf("��ī�ο� �������� �ɾ��� �ִ�. Į�� ���� �ǰ� ���� �ִ�.\n");
		printf("ǻ��ڽ��� �ִ�. ����ִ�.\n");
		selected_storage2();
		break;
	case 3:
		printf("���ڿ� ���� ��ġ���� ���� �ִ�.\nå�� ������ ���, ����, ����� �ִ�.\n");
		printf("���̵� ���̿� �� ���̰� ���� ���\n");
		selected_paper();
		break;
	case 4:
		printf("ö��\n���ȴ�!\n");
		selected_storagechoice();
		break;
	}

}
void selected_fusebox()
{
	int num;
	printf("1.Ǭ��. 2.��Ǭ��.\n");
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
	printf("1.���캻��. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("\'9\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
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
	printf("1.���� ������ ����. 2.�ٽ� �ѷ�����.\n");
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
	printf("1.���� 2.Ƽ�� 3.�Խ��� 4.��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("������ ���� ���� �����̴�.\n���̿� ���� �ִ�.\n");
		selected_sofa();
		break;
	case 2:
		printf("�����ִ�.\n");
		selected_diningroom();
		break;
	case 3:
		printf("&&��&&�� �ŷ��Ϸ� �ݾ�:$$$$$$.\n&&��&&�� �ŷ� �ݾ�:$$$$$$.\n");
		printf("&&��&&�� �ŷ� �ݾ�:$$$$$$$.\n");
		printf("'13'\n");
		selected_diningroom();
		break;
	case 4:
		printf("����ִ�.\n");
		selected_diningroomchoice();
		break;
	}
}
void selected_sofa()
{
	int num;
	printf("1.���캻��. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���̰� �ִ�.\n");
		printf("\'9\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
		selected_diningroom();
		break;
	case 2:
		selected_diningroom();
		break;
	}
}
void selected_diningroomchoice() {
	int num;
	printf("1.Ż���Ѵ�. 2.�ѷ�����.\n");
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
	printf("1.�Ž� 2.ħ�� 3.�ֹ� 4.���� 5.â��\n");
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
	printf("1.ħ�� 2.���� 3.å�� 4.�Ž� ��\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("�̺��� ���� ���� �ǰ� ���� �ִ�. ��??\n��Ǫ��⵵ �������� �ִ�.\n");
		printf("���ڰ� �ִ�.\n");
		selected_bedfinal();
		selected_bedroomfinal();
		break;
	case 2:
		printf("��ĳ�� ������ ����. ���� ���� �ʴ�.\n");
		printf("��??\n");
		selected_clothsefinal();
		break;
	case 3:
		printf("���ڸ� ���� �ɾҴ�. å�� ������ ���, �̸�ǥ, ���� 2���� �ִ�.\n");
		printf("�̸�ǥ??\n");
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
	printf("1.����. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("12��..26��..\n");
		printf("������ ���ϴ� �ɱ�?\n");
		selected_bedroomfinal();
		break;
	case 2:
		selected_bedroomfinal();
		break;
	}
}
void selected_clothsefinal() {
	int num;
	printf("1.���캻��. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���̰� �ִ�.\n");
		printf("\'16\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
		selected_bedroomfinal();
		break;
	case 2:
		selected_bedroomfinal();
		break;
	}
}
void selected_deskfinal() {
	int num;
	printf("�ؿ� ������ �ִ�.����??\n");
here:
	printf("1.ù��° 2.�ι�° 3.����° 4.��������.\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("����ִ�.\n");
		goto here;
		break;
	case 2:
		printf("�ƹ��͵� �������� �ʴ� �̸�ǥ���� �ִ�.\n");
		goto here;
		break;
	case 3:
		printf("����ִ�.\n");
		goto here;
		break;
	case 4:
		selected_bedroomfinal();
		break;
	}
}

void selected_kitchenfinal() {
	int num;
	printf("1.����� 2.��ũ�� 3.��Ź 4.�Ž� ��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���� ����� �������, �߰��, ���, ���ֵ��� �ִ�.\n");
		selected_kitchenfinal();
		break;
	case 2:
		printf("�� ���� �Ŷ����� �������� �� �η��� �ִ�. �ǰ� ���� �ִ� Į�� ������ �ִ�.\n");
		printf("�ҽ����� �����ִ�.\n");
		selected_kitchenfinal();
		break;
	case 3:
		printf("�������� �� ���ֺ����� �ְ� ���ڷ������� �ִ�.\n");
		printf("���ڷ�����??\n");
		selected_microwavefinal();
		break;
	case 4:
		selected_diningroomchoice();
		break;
	}
}
void selected_microwavefinal() {
	int num;
	printf("1.���캻��. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���̰� �ִ�.\n");
		printf("\'1\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
		selected_kitchenfinal();
		break;
	case 2:
		selected_kitchenfinal();
		break;
	}
}
void selected_yardfinal() {
	int num;
	printf("1.�칰 2.�Թ� 3.��ü�� 4.���� 5.�Ž� ��\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("��� ������ �ʴ´�. �񸶸��� �� ���Ǳ�?\n");
		selected_waterfinal();
		break;
	case 2:
		printf("����, �丶��, ���ߵ��� �ַ��ַ� �ִ�.\n");
		selected_yardfinal();
		break;
	case 3:
		printf("��ü��??\n");
		selected_letterboxfinal();
		break;
	case 4:
		printf("�ߵ��� �ִ�.\n");
		selected_yardfinal();
		break;
	case 5:
		selected_diningroomchoice();
		break;
	}
}
void selected_waterfinal() {
	int num;
	printf("1.���Ŵ�. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("�ÿ��Ѵ�~\n");
		selected_yardfinal();
		break;
	case 2:
		selected_yardfinal();
		break;
	}
}
void selected_letterboxfinal() {
	int num;
	printf("1.����. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("���̰� �ִ�.\n");
		printf("\'7\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
		selected_yardfinal();
		break;
	case 2:
		selected_yardfinal();
		break;
	}
}
void selected_storagefinal() {
	int num;
	printf("1.�潺 2.�� 3.å�� 4.�Ž� ��\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("�������� �ִ�. �� �ʿ� ���� �ִ� �� ������..\n");
		printf("��ο� ������ �ʴ´�. �� �ʿ��� ���Ҹ��� �鸮�� �� ����\n");
		selected_storagefinal();
		break;
	case 2:
		printf("��ī�ο� �������� �ɾ��� �ִ�. Į�� ���� �ǰ� ���� �ִ�.\n");
		printf("ǻ��ڽ��� �ִ�. ����ִ�.\n");
		selected_storagefinal();
		break;
	case 3:
		printf("���ڿ� ���� ��ġ���� ���� �ִ�.\nå�� ������ ���, ����, ����� �ִ�.\n");
		printf("���̵� ���̿� �� ���̰� ���� ���\n");
		selected_paperfinal();
		break;
	case 4:
		selected_diningroomchoice();
		break;
	}
}
void selected_paperfinal() {
	int num;
	printf("1.���캻��. 2.��������.\n");
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("\'9\'��� �����ִ�.\n");
		printf("������ �־�߰ڴ�.\n");
		selected_storagefinal();
		break;
	case 2:
		selected_storagefinal();
		break;
	}
}

