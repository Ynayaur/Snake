//�ߵ���󳤶�
#define length	55

typedef int BOOL;
#define false 0
#define true 1



//������
int snake[length][3] = { '0' };
//����
enum { up = -1, down = 1, left = -2, right = 2 };
//��ͷ�ı仯����
int snakedirection = left;
//ʳ����
int food = 0;
//ʳ������
int X, Y;
//������Ľű�
int lengthofsnake = 2;
//����
int score;
//�Ѷ��趨
int hard;
//����ʱ���
int flag = 1;
//ͨ�ر��
int g_flaga = 0;
//�����
int m=0;
//��ͣ����ʱ��
int j = 0;
//����ʳ���ͳ��
int fooda = 0;
int foodb = 0;


//����
char background[20][48] = { "����������������������������������������������\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"��                                          ��\n",
							"����������������������������������������������\n"

};


//����ͼ
char boomy[25][60]={ 
					"*                             qBMBBBMBMY\n",
					"*                            8BBBBBOBMBMv\n",
					"*                          iMBMM5vOY:BMBBv\n",
					"*           .r,            OBM;   .: rBBBBBY\n",
					"*           vUl            7BB   .;7. LBMMBBM.\n",
					"*          .@Wwz           :uvir .i:.iLMOMOBM..\n",
					"*          vv::r;             iY. ...rv,@arqiao.\n",
					"*           Li. i:             v:.::::7vOBBMBL..\n",
					"*           ,i7: vSUi,         :M7.:.,:uO8OP. .\n",
					"*             .N2k5u1ju7,..     BMGiiL7   ,i,i.\n",
					"*              :rLjFYjvjLY7r::.  ;v  vr...rE8q,.:,,\n",
					"*             751jSLXPFu5uU@guohezou.,1vjY2E8@Yizero.\n",
					"*             BB:FMu rkM8Eq0PFjF15FZOXu15F25uuLuu25Gi.\n",
					"*           ivSvvXL    :v58ZOGZXF2UUkFSFkU1u125uUJUUZ.\n",
					"*         :@kevensun       ,iY2OGOXSUXkSuS2F5XXkUX5SEv.\n",
					"*     .:iOBMBMBBOOBMUi:,        ,:8PkFP5NkPXkFqPEqqkZu.\n",
					"*   .rqMqBBMOMMBMBBBM .           @kexianli.S11kFSU5q5 \n",
					"* .7BBOi1L1MM8BBBOMBB..,          8kqS52XkkU1Uqkk1kUEJ \n",
					"* .;MBZ:iiMBMBMMOBBBu ,           1OkS1F1X5kPP112F51kU \n",
					"*   .rPY  OMBMBBBMBB2 ,.          rME5SSSFk1XPqFNkSUPZ,.\n",
					"*          ;;JuBML::r:.:.,,        SZPXOSXSP5kXGNP15UBr.\n",
					"*            L     :@sanshao.      :MNZqNXqSqXk2EOPSXPE.\n",
					"*          vuLBX.,,v8Bj. i:r7:      2ZkqqOXXSNNONOXXSXOU \n",
					"*        :r2. rMBGBMGi .7Y, 1i::i   vOOPMNNSXXEqP@Secbone.\n",
					"*           .i1r..jkY     vE.iY....  2OFqOq5X5F1S2F22uuv1M;\n"
};