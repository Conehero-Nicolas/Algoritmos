#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include "meuconio.h"

#define TF 100

//struct
	
struct TPalunos{
	char RA[10], nome[30];
};

struct TPdisciplinas{
	char disciplina[30], CodDisc[4];
};

struct TPalunos_disciplinas{
	float nota;
	char RA[10], CodDisc[4];
};

//buscas

int busca_RA(TPalunos aln[TF], int TLA, char auxRA[10]){
	int pos = 0;
	while(pos<TLA && stricmp(auxRA,aln[pos].RA)!=0)
		pos++;
	if(pos<TLA)
		return pos;
	else 
		return -1;
}

int busca_CodDisc(TPdisciplinas dcp[TF], int TLD, char aux_cod[4]){
	int pos = 0;
	while(pos<TLD && stricmp(aux_cod,dcp[pos].CodDisc)!=0)
		pos++;
	if(pos<TLD)
		return pos;
	else 
		return -1;
}

int busca_nota(TPalunos_disciplinas ad[TF], char auxRA[10],char aux_cod[4], int TLAD){
	int pos = 0;
	while(pos<TLAD && (strcmp(auxRA,ad[pos].RA)!=0 || strcmp(aux_cod,ad[pos].CodDisc)!=0))
		pos++;
	if(pos<TLAD)
		return pos;
	else
		return -1;
}

int busca_notaRA(TPalunos_disciplinas ad[TF], char auxRA[10], int TLAD){
	int pos = 0;
	while(pos<TLAD && stricmp(auxRA,ad[pos].RA)!=0)
		pos++;
	if(pos<TLAD)
		return pos;
	else 
		return -1;
}

int busca_notaCodDisc(TPalunos_disciplinas ad[TF], char aux_cod[4], int TLAD){
	int pos = 0;
	while(pos<TLAD && stricmp(aux_cod,ad[pos].CodDisc)!=0)
		pos++;
	if(pos<TLAD)
		return pos;
	else 
		return -1;
}

//formatar

void erase(void){
	int i;
	gotoxy(14,23);
	for(i=0;i<24;i++)
		printf(" ");
}

char formatar_ra2(char ra[13]) {
    char ra_formatado[13];
    ra_formatado[0] = ra[0];
    ra_formatado[1] = ra[1];
    ra_formatado[2] = '.';
    ra_formatado[3] = ra[2];
    ra_formatado[4] = ra[3];
    ra_formatado[5] = '.';
    ra_formatado[6] = ra[4];
    ra_formatado[7] = ra[5];
    ra_formatado[8] = ra[6];
    ra_formatado[9] = ra[7];
    ra_formatado[10] = '-';
    ra_formatado[11] = ra[8];
    ra_formatado[12] = '\0';
    printf("%s",ra_formatado);
}

//preencher
	
//void preencher(TPalunos aln[TF],int &TLA, TPdisciplinas dcp[TF], int &TLD, TPalunos_disciplinas ad[TF], int &TLAD){
//	//	Alunos
//		strcpy(aln[TLA].RA,"260910451");
//		strcpy(aln[TLA].nome,"Bertalia");
//		TLA++;
//		strcpy(aln[TLA].RA,"100910553");
//		strcpy(aln[TLA].nome,"Creusa");
//		TLA++;
//		strcpy(aln[TLA].RA,"260920121");
//		strcpy(aln[TLA].nome,"Florisbela");
//		TLA++;
//		strcpy(aln[TLA].RA,"100930526");
//		strcpy(aln[TLA].nome,"Jurema");
//		TLA++;
//		strcpy(aln[TLA].RA,"260934448");
//		strcpy(aln[TLA].nome,"Petronio");
//		TLA++;
//	//	Disciplinas
//		strcpy(dcp[TLD].CodDisc,"100");
//		strcpy(dcp[TLD].disciplina,"ATP 1");
//		TLD++;
//		strcpy(dcp[TLD].CodDisc,"105");
//		strcpy(dcp[TLD].disciplina,"ATP 2");
//		TLD++;
//		strcpy(dcp[TLD].CodDisc,"120");
//		strcpy(dcp[TLD].disciplina,"Estruturade Dados 1");
//		TLD++;
//		strcpy(dcp[TLD].CodDisc,"150");
//		strcpy(dcp[TLD].disciplina,"Pesquisa e Ordenacao");
//		TLD++;
//		strcpy(dcp[TLD].CodDisc,"210");
//		strcpy(dcp[TLD].disciplina,"Ferramentas 1");
//		TLD++;
//		strcpy(dcp[TLD].CodDisc,"156");
//		strcpy(dcp[TLD].disciplina,"ATP 6");
//		TLD++;
//	//	Notas
//		strcpy(ad[TLAD].RA,"260910451");
//		strcpy(ad[TLAD].CodDisc,"120");
//		ad[TLAD].nota=8;
//		TLAD++;
//		strcpy(ad[TLAD].RA,"260910451");
//		strcpy(ad[TLAD].CodDisc,"210");
//		ad[TLAD].nota=4.5;
//		TLAD++;
//		strcpy(ad[TLAD].RA,"260910451");
//		strcpy(ad[TLAD].CodDisc,"100");
//		ad[TLAD].nota=6.5;
//		TLAD++;
//		strcpy(ad[TLAD].RA,"100910553");
//		strcpy(ad[TLAD].CodDisc,"150");
//		ad[TLAD].nota=5;
//		TLAD++;
//		strcpy(ad[TLAD].RA,"100910553");
//		strcpy(ad[TLAD].CodDisc,"100");
//		ad[TLAD].nota=4.5;
//		TLAD++;
//}

//interface

//void MolduraInicial(int CI, int LI, int CF, int LF, int CorT, int CorF)
//{
//    int i;
//    textcolor(CorT);
//    textbackground(CorF);
//    gotoxy(CI,LI);    printf("%c",201);
//    gotoxy(CF,LI);    printf("%c",187);
//    gotoxy(CI,LF);    printf("%c",200);
//    gotoxy(CF,LF);     printf("%c",188);
//    for(i=CI+1; i<CF; i++)
//    {
//        gotoxy(i,LI);    printf("%c",205);
//        Sleep(10);
//        gotoxy(i,LF);    printf("%c",205);
//    }
//    for(i=LI+1; i<LF; i++)
//    {
//        gotoxy(CI,i);    printf("%c",186);
//        Sleep(10);
//        gotoxy(CF,i);    printf("%c",186);
//    }
//    textcolor(7);
//    textbackground(0);
//}
void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
    int i;
    textcolor(CorT);
    textbackground(CorF);
    gotoxy(CI,LI);    printf("%c",201);
    gotoxy(CF,LI);    printf("%c",187);
    gotoxy(CI,LF);    printf("%c",200);
    gotoxy(CF,LF);     printf("%c",188);
    for(i=CI+1; i<CF; i++)
    {
        gotoxy(i,LI);    printf("%c",205);
        gotoxy(i,LF);    printf("%c",205);
    }
    for(i=LI+1; i<LF; i++)
    {
        gotoxy(CI,i);    printf("%c",186);
        gotoxy(CF,i);    printf("%c",186);
    }
    textcolor(7);
    textbackground(0);
}

void PainelPrincipal(void)
{
    clrscr();
    Moldura(1,1,80,25,15,1);
    Moldura(2,2,79,4,14,2);
    textcolor(15);
    gotoxy(28,3);
    printf("ALGORITIMOS DE PROGRAMACAO");
    Moldura(2,5,30,21,13,3);
    Moldura(31,5,79,21,11,5);
    Moldura(2,22,79,24,12,4);
    textcolor(10);
    gotoxy(4,23);
    printf("Mensagens:");
}

//cores

void red () {
  printf("\033[1;31m");
}

void yellow (){
  printf("\033[1;33m");
}

//menus
	
int menu_inicial(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU");
    yellow();
    gotoxy(32, 6);
    printf("[A]-Alunos");
    gotoxy(32, 7);
    printf("[B]-Disciplinas");
    gotoxy(32, 8);
    printf("[C]-Notas");
    gotoxy(32, 9);
    printf("[D]-Relatorios");
    gotoxy(32, 10);
    printf("[ESC]-Sair");
    gotoxy(32, 11);
    printf("Opcao Desejada:");

    return toupper(getch());
}

int menu_alunos(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU DE ALUNOS");
    yellow();
    gotoxy(32, 6);
    printf("[A]-Cadastro de Alunos");
    gotoxy(32, 7);
    printf("[B]-Exclusao de Alunos");
    gotoxy(32, 8);
    printf("[C]-Alteracao de Alunos");
    gotoxy(32, 9);
    printf("[D]-Consulta de Alunos");
    gotoxy(32, 10);
    printf("[ESC]-Sair");
    gotoxy(32, 11);
    printf("Opcao Desejada:");

    return toupper(getch());
}

int menu_disciplinas(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU DISCIPLINAS");
    yellow();
    gotoxy(32, 6);
    printf("[A]-Cadastro de Disciplinas\n");
    gotoxy(32, 7);
    printf("[B]-Exclusao de Disciplinas\n");
    gotoxy(32, 8);
    printf("[C]-Alteracao de Disciplinas\n");
    gotoxy(32, 9);
    printf("[D]-Consulta de Disciplinas\n");
    gotoxy(32, 10);
    printf("[ESC]-Sair\n\n");
    gotoxy(32, 11);
    printf("Opcao Desejada:");

    return toupper(getch());
}

int menu_notas(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU NOTAS");
    yellow();
    gotoxy(32, 6);
    printf("[A]-Cadastro de Notas\n");
    gotoxy(32, 7);
    printf("[B]-Exclusao de Notas\n");
    gotoxy(32, 8);
    printf("[C]-Alteracao de Notas\n");
    gotoxy(32, 9);
    printf("[D]-Consulta de Notas\n");
    gotoxy(32, 10);
    printf("[ESC]-Sair\n\n");
    gotoxy(32, 11);
    printf("Opcao Desejada:");

    return toupper(getch());
}

int menu_relatorios(){
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("MENU RELATORIOS");
	yellow();
	gotoxy(32, 6);
	printf("[1]-Alunos");
	gotoxy(32, 7);
	printf("[2]-Disciplinas");
	gotoxy(32, 8);
	printf("[3]-Notas");
	gotoxy(32, 9);
	printf("[4]-Reprovados em duas ou mais disciplinas");
	gotoxy(32, 10);
	printf("[5]-Alunos com determida inicial");
	gotoxy(32, 11);
	printf("[6]-Disciplinas com determinado termo");
	gotoxy(32, 12);
	printf("[7]-Disciplinas com media geral abaixo de 6.0");
	gotoxy(32, 13);
	printf("[8]-Relatorio geral");
	gotoxy(32, 14);
	printf("[ESC]-Voltar");
	gotoxy(32, 15);
	printf("Opcao Desejada:");
	
	return getch();
}

//alunos

void cadastro_alunos(TPalunos aln[TF], int &TLA){
	char auxRA[10];
	int pos,i=6;
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("CADASTRO DE ALUNOS\n");
	yellow();
	gotoxy(32, 6);
	if(TLA==TF) {
		printf("Cadastro de alunos cheio");
	}
	else{
		gotoxy(32, i);
		printf("Digite o %do. RA: ",TLA+1);
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();
		while(TLA<TF && stricmp(auxRA,"\0")!=0){
			pos=busca_RA(aln, TLA, auxRA);
			if(pos==-1){
				strcpy(aln[TLA].RA,auxRA);
				i+=2;
				gotoxy(32, i);
				printf("Digite o nome do aluno:");
				fflush(stdin);
				gotoxy(14,23);
				gets(aln[TLA].nome);
				erase();
				TLA++;
			}
			else {
				gotoxy(32, ++i);
				printf("Aluno ja cadastrado");
			}
			if(TLA<TF){
				i+=2;
				gotoxy(32, i);
				printf("Digite o %do. RA: ",TLA+1);
				fflush(stdin);
				gotoxy(14,23);
				gets(auxRA);
				erase();
			}
			else{
				gotoxy(32, ++i);
				printf("Cadastro cheio");
				strcpy(auxRA,"\0");
			}
		}
	}
	gotoxy(32, i);
	getch();
}

void exclusao_alunos(TPalunos aln[TF], int &TLA, TPalunos_disciplinas ad[TF], int TLAD){
	int pos, pos2, i=6;
	char auxRA[10], op;
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("EXCLUSAO DE ALUNOS");
	yellow();
	gotoxy(32, 6);
	if(TLA==0)
		printf("Nao ha alunos cadastrados");
	else{
		gotoxy(32, i);
		printf("Digite o RA do aluno a ser excluido: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();
		while(stricmp(auxRA,"\0")!=0){
			pos=busca_RA(aln, TLA, auxRA);
			if(pos==-1)
				printf("Aluno nao cadastrado");
			else{
				pos2=busca_notaRA(ad, auxRA, TLAD);
				if(pos2==-1){
					i+=2;
					gotoxy(32, i);
					printf("Deseja excluir o aluno %s? [S]/[N]",aln[pos].nome);
					gotoxy(14,23);
					scanf(" %c",&op);
					erase();
					if(op=='s'){
						for(;pos<TLA;pos++)
							aln[pos]=aln[pos+1];
						i++;
						gotoxy(32, i);
						printf("Aluno excluido com sucesso");
						TLA--;
					}
				}
				else{
					i++;
					gotoxy(32,i);
					printf("Este RA esta cadastrado na tabela de notas,");
					i++;
					gotoxy(32,i);
					printf("faca a alteracao na tabela de notas primeiro.");
				}
			}
			if(TLA>0){
				i+=2;
				gotoxy(32, i);
				printf("Digite o RA do aluno a ser excluido: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(auxRA);
				erase();
			}
			else{
				i+=2;
				gotoxy(32, i);
				printf("Nao ha mais alunos para excluir");
				strcpy(auxRA,"\0");
			}

		}
	}
	getch();
}

void alteracao_alunos(TPalunos aln[TF], int TLA, TPalunos_disciplinas ad[TF], int TLAD){
	int pos,pos2,i=6;
	char auxRA[10];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("ALTERACAO DE ALUNOS");
	yellow();
	gotoxy(32, 6);
	if(TLA==0)
		printf("Nao ha alunos cadastrados");
	else{
		gotoxy(32, i);
		printf("Digite o RA do aluno que deseja alterar: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();
		while(stricmp(auxRA,"\0")!=0){
			pos=busca_RA(aln, TLA, auxRA);
			if(pos==-1) {
				i+=2;
				gotoxy(32, i);
				printf("Aluno nao cadastrado");
			}
			else{
				pos2=busca_notaRA(ad, auxRA, TLAD);
				if(pos2==-1){
					i+=2;
					gotoxy(32, i);
					printf("Digite o novo RA: ");
					fflush(stdin);
					gotoxy(14,23);
					gets(aln[pos].RA);
					erase();
					i++;
					gotoxy(32, i);
					printf("Digite o novo nome: ");
					fflush(stdin);
					gotoxy(14,23);
					gets(aln[pos].nome);
					erase();
				}
				else{
					i++;
					gotoxy(32,i);
					printf("Este RA esta cadastrado na tabela de notas,");
					i++;
					gotoxy(32,i);
					printf("faca a alteracao na tabela de notas primeiro.");
				}
			}
			i+=2;
			gotoxy(32, i);
			printf("Digite o RA do aluno que deseja alterar: ");
			fflush(stdin);
			gotoxy(14,23);
			gets(auxRA);
			erase();
		}
	}
	getch();
}

void consulta_alunos(TPalunos aln[TF], int TLA){
	int pos,i=6;
	char auxRA[10];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("CONSULTA DE ALUNOS");
	yellow();
	gotoxy(32, 6);
	if(TLA==0)
		printf("Nao ha alunos cadastrados");
	else{
		gotoxy(32, i);
		printf("Digite o RA para consulta: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();
		while(stricmp(auxRA, "\0")!=0){
			pos=busca_RA(aln, TLA, auxRA);
			if(pos==-1) {
				i+=2;
				gotoxy(32, i);
				printf("RA nao cadastrado");
			}	
			else{
				i+=2;
				gotoxy(32, i);
				printf("RA: ");
				formatar_ra2(aln[pos].RA);
				i++;
				gotoxy(32, i);
				printf("Nome: %s",aln[pos].nome);
			}
			i+=2;
			gotoxy(32, i);
			printf("Digite o RA para consulta: ");
			fflush(stdin);
			gotoxy(14,23);
			gets(auxRA);
			erase();
		}
	}
	getch();
}

//disciplinas

void cadastro_disciplinas(TPdisciplinas dcp[TF], int &TLD){
	int pos,i=6;
	char aux_cod[4];
	clrscr();
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("CADASTRO DE DISCIPLINAS");
	yellow();
	gotoxy(32, 6);
	if(TLD==TF)
		printf("Cadastro de disciplinas cheio");
	else{
		gotoxy(32, i);
		printf("Digite o %do. Codigo: ",TLD+1);
		fflush(stdin);
		gotoxy(14,23);
		gets(aux_cod);
		erase();
		while(TLD<TF && stricmp(aux_cod, "\0")!=0){
			pos=busca_CodDisc(dcp, TLD, aux_cod);
			if(pos==-1){
				strcpy(dcp[TLD].CodDisc,aux_cod);
				i+=2;
				gotoxy(32, i);
				printf("Digite o nome da disciplina:");
				fflush(stdin);
				gotoxy(14,23);
				gets(dcp[TLD].disciplina);
				erase();
				TLD++;
			}
			else {
				i++;
				gotoxy(32, ++i);
				printf("Disciplina ja cadastrada");
			}
			if(TLD<TF){
				i+=2;
				gotoxy(32, i);
				printf("Digite o %do. Codigo: ",TLD+1);
				fflush(stdin);
				gotoxy(14,23);
				gets(aux_cod);
				erase();
			}
			else{
				gotoxy(32, ++i);
				printf("Cadastro cheio");
				strcpy(aux_cod,"\0");
			}
		}
	}
	getch();
}

void exclusao_disciplinas(TPdisciplinas dcp[TF], int &TLD, TPalunos_disciplinas ad[TF], int TLAD){
	int pos, pos2, i=6;
	char aux_cod[4], op;
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("EXCLUSAO DE DISCIPLINAS");
	yellow();
	gotoxy(32, i);
	if(TLD==0)
		printf("Nao ha disciplinas cadastradas");
	else{
		gotoxy(32, i);
		printf("Digite o codigo da disciplina a ser excluida: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(aux_cod);
		erase();
		while(stricmp(aux_cod, "\0")!=0){
			pos=busca_CodDisc(dcp, TLD, aux_cod);
			if(pos==-1){
				i+=2;
				gotoxy(32, i);
				printf("Disciplina nao cadastrada");
			}
			else{
				pos2=busca_notaCodDisc(ad, aux_cod, TLAD);
				if(pos2==-1){
					i+=2;
					gotoxy(32, i);
					printf("Deseja excluir a disciplina %s? [S]/[N]",dcp[pos].disciplina);
					gotoxy(14,23);
					scanf(" %c",&op);
					erase();
					if(op=='s'){
						for(;pos<TLD;pos++)
							dcp[pos]=dcp[pos+1];
						i++;
						gotoxy(32, i);
						printf("Disciplina excluida com sucesso");
						TLD--;
					}
				}
				else{
					i++;
					gotoxy(32,i);
					printf("Este RA esta cadastrado na tabela de notas,");
					i++;
					gotoxy(32,i);
					printf("faca a alteracao na tabela de notas primeiro.");
				}	
			}
			if(TLD>0){
				i+=2;
				gotoxy(32, i);
				printf("Digite o codigo da disciplina a ser excluida: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(aux_cod);
				erase();
			}
			else{
				i+=2;
				gotoxy(32, i);
				printf("Nao ha mais disciplinas para excluir");
				strcpy(aux_cod,"\0");
			}
		}
	}
	getch();
}

void alteracao_disciplinas(TPdisciplinas dcp[TF], int TLD,TPalunos_disciplinas ad[TF], int TLAD){
	int pos,pos2,i=6;
	char aux_cod[4];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4,6);
	printf("ALTERACAO DE DISCIPLINAS");
	yellow();
	gotoxy(32, 6);
	if(TLD==0)
		printf("Nao ha disciplinas cadastradas");
	else{
		gotoxy(32, i);
		printf("Digite o codigo que deseja alterar: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(aux_cod);
		erase();
		while(stricmp(aux_cod, "\0")!=0){
			pos=busca_CodDisc(dcp, TLD, aux_cod);
			if(pos==-1) {
				i+=2;
				gotoxy(32, i);
				printf("Disciplinas nao cadastrado");
			}
			else{
				pos2=busca_notaCodDisc(ad, aux_cod, TLAD);
				if(pos2==-1){
					i+=2;
				gotoxy(32, i);
				printf("Digite o novo codigo: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(dcp[pos].CodDisc);
				erase();
				i++;
				gotoxy(32, i);
				printf("Digite o novo nome da disciplina: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(dcp[pos].disciplina);
				erase();
				}
				else{
					i++;
					gotoxy(32,i);
					printf("Este RA esta cadastrado na tabela de notas,");
					i++;
					gotoxy(32,i);
					printf("faca a alteracao na tabela de notas primeiro.");
				}
			}
			i+=2;
			gotoxy(32, i);
			printf("Digite o codigo que deseja alterar: ");
			fflush(stdin);
			gotoxy(14,23);
			gets(aux_cod);
			erase();
		}
	}
	getch();
}

void consulta_disciplinas(TPdisciplinas dcp[TF], int TLD){
	int pos,i=6;
	char aux_cod[4];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("CONSULTA DE DISCIPLINAS");
	yellow();
	gotoxy(32, 6);
	if(TLD==0)
		printf("Nao ha disciplinas cadastradas");
	else{
		gotoxy(32, i);
		printf("Digite o codigo para consulta: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(aux_cod);
		erase();
		while(stricmp(aux_cod, "\0")!=0){
			pos=busca_CodDisc(dcp, TLD, aux_cod);
			if(pos==-1) {
				i+=2;
				gotoxy(32, i);
				printf("Disciplina nao cadastrada");
			}
			else{
				i+=2;
				gotoxy(32, i);
				printf("Codigo: %s",dcp[pos].CodDisc);
				i++;
				gotoxy(32, i);
				printf("Disciplina: %s",dcp[pos].disciplina);
			}
			i+=2;
			gotoxy(32, i);
			printf("Digite o codigo para consulta: ");
			fflush(stdin);
			gotoxy(14,23);
			gets(aux_cod);
			erase();
		}
	}
	getch();
}

//notas

void cadastro_notas(TPalunos_disciplinas ad[TF], int &TLAD, TPalunos aln[TF], int TLA, TPdisciplinas dcp[TF], int TLD){
	int pos1,pos2,pos3,i=6;
	char auxRA[10], aux_cod[4];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("CADASTRO DE NOTAS");
	yellow();
	gotoxy(32, 6);
	if(TLAD==TF)
		printf("Cadastro de notas cheio");
	else{
		gotoxy(32, i);
		printf("Digite o RA: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();
		while(TLAD<TF && stricmp(auxRA, "\0")!=0){
			pos1=busca_RA(aln, TLA, auxRA);
			if(pos1>=0){
				i++;
				gotoxy(32, i);
				printf("Digite o codigo da disciplina: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(aux_cod);
				erase();
				pos2=busca_CodDisc(dcp, TLD, aux_cod);
				if(pos2>=0){
					pos3=busca_nota(ad, auxRA, aux_cod, TLAD);
					if(pos3==-1){
						strcpy(ad[TLAD].RA,auxRA);
						strcpy(ad[TLAD].CodDisc,aux_cod);
						i++;
						gotoxy(32, i);
						printf("Digite a nota: ");
						gotoxy(14,23);
						scanf("%f",&ad[TLAD].nota);
						erase();
						TLAD++;
					}
					else {
						i++;
						gotoxy(32,i);
						printf("Nota ja Cadastrada");
					}
				}
				else {
					i+=2;
					gotoxy(32, i);
					printf("Disciplina nao cadastrada");
				}
			}
			else{
				i+=2;
				gotoxy(32, i);
				printf("RA nao cadastrado");
			}
			if(TLAD<TF){
				i+=2;
				gotoxy(32, i);
				printf("Digite o RA: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(auxRA);
				erase();
			}
			else{
				i+=2;
				gotoxy(32, i);
				printf("Cadastro cheio");
				strcpy(auxRA,"\0");
			}
		}
	}
	getch();
}

void exclusao_notas(TPalunos_disciplinas ad[TF], int &TLAD, TPalunos aln[TF], int TLA, TPdisciplinas dcp[TF], int TLD){
	int pos1,pos2,pos3,j=6;
	char auxRA[10], aux_cod[4];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("EXCLUSAO DE NOTAS");
	yellow();
	gotoxy(32, j);
	if(TLAD==0)
		printf("Nenhuma nota cadastrada.");
	else{
		gotoxy(32, j);
		printf("Digite o RA da nota que deseja excluir: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();	
		while(stricmp(auxRA, "\0")!=0){
			pos1=busca_RA(aln, TLA, auxRA);
			if(pos1>=0){
				j++;
				gotoxy(32, j);
				printf("Digite o codigo da disciplina que deseja excluir: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(aux_cod);
				erase();
				pos2=busca_CodDisc(dcp, TLD, aux_cod);
				if(pos2>=0){
					pos3=busca_nota(ad, auxRA, aux_cod, TLAD);
					if(pos3>=0){
						for(int i=pos3;i<TLAD;i++)
							ad[i]=ad[j+1];
						TLAD--;
						j++;
						gotoxy(32, j);
						printf("Nota excluida com sucesso.");
					}
					else{
						j++;
						gotoxy(32, j);
						printf("Nota nao cadastrada");
					}
				}
				else{
					j++;
					gotoxy(32, j);
					printf("Disciplina nao cadastrada");
				}
			}
			else{
				j++;
				gotoxy(32, j);
				printf("RA nao cadastrado");
			}
			if(TLAD>0){
				j+=2;
				gotoxy(32, j);
				printf("Digite o RA da nota que deseja excluir: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(auxRA);
				erase();
			}
			else{
				j++;
				gotoxy(32, j);
				printf("Nao ha mais notas para excluir");
				strcpy(auxRA,"\0");
			}
		}
	}
	getch();
}

void alteracao_notas(TPalunos_disciplinas ad[TF], int &TLAD, TPalunos aln[TF], int TLA, TPdisciplinas dcp[TF], int TLD){
	int pos1,pos2,pos3,i=6;
	char auxRA[10], aux_cod[4];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4,6);
	printf("ALTERACAO DE NOTAS");
	yellow();
	gotoxy(32, 6);
	if(TLAD==0)
		printf("Nenhuma nota cadastrada.");
	else{
		gotoxy(32, i);
		printf("Digite o RA que deseja alterar: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();	
		while(stricmp(auxRA, "\0")!=0){
			pos1=busca_RA(aln, TLA, auxRA);
			if(pos1>=0){
				i++;
				gotoxy(32, i);
				printf("Digite o codigo da disciplina que deseja: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(aux_cod);
				erase();
				pos2=busca_CodDisc(dcp, TLD, aux_cod);
				if(pos2>=0){
					pos3=busca_nota(ad, auxRA, aux_cod, TLAD);
					if(pos3>=0){
						i+=2;
						gotoxy(32, i);
						printf("Digite o novo RA: ");
						gotoxy(14,23);
						gets(ad[pos3].RA);
						erase();
						i++;
						gotoxy(32, i);
						printf("Digite o novo codigo da disciplina: ");
						gotoxy(14,23);
						gets(ad[pos3].CodDisc);
						erase();
						i++;
						gotoxy(32, i);
						printf("Digite a nova nota: ");
						gotoxy(14,23);
						scanf("%f",&ad[pos3].nota);
						erase();
						i+=2;
						gotoxy(32, i);
						printf("Nota alterada com sucesso.");
					}
					else{
						i++;
						gotoxy(32, i);
						printf("Nota nao cadastrada");
					}	
				}
				else{
					i++;
					gotoxy(32, i);
					printf("Disciplina nao cadastrada");
				}
			}
			else{
				i+=2;
				gotoxy(32, i);
				printf("RA nao cadastrado\n");
			}
			i+=2;
			gotoxy(32, i);
			printf("Digite o RA que deseja: ");
			fflush(stdin);gotoxy(14,23);
			gets(auxRA);
			erase();
		}
	}
	getch();
}

void consulta_notas(TPalunos_disciplinas ad[TF], int &TLAD, TPalunos aln[TF], int TLA, TPdisciplinas dcp[TF], int TLD){
	int pos1,pos2,pos3,i=6;
	char auxRA[10], aux_cod[4];
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(5,6);
	printf("CONSULTA DE NOTAS");
	yellow();
	gotoxy(32, 6);
	if(TLAD==0)
		printf("Nenhuma nota cadastrada.");
	else{
		gotoxy(32, i);
		printf("Digite o RA: ");
		fflush(stdin);
		gotoxy(14,23);
		gets(auxRA);
		erase();	
		while(stricmp(auxRA, "\0")!=0){
			pos1=busca_RA(aln, TLA, auxRA);
			if(pos1>=0){
				i++;
				gotoxy(32, i);
				printf("Digite o codigo da disciplina: ");
				fflush(stdin);
				gotoxy(14,23);
				gets(aux_cod);
				erase();
				pos2=busca_CodDisc(dcp, TLD, aux_cod);
				if(pos2>=0){
					pos3=busca_nota(ad, auxRA, aux_cod, TLAD);
					if(pos3>=0){	
						i+=2;
						gotoxy(32, i);
						printf("RA: %s",ad[pos3].RA);
						i++;
						gotoxy(32, i);
						printf("Codigo: %s",ad[pos3].CodDisc);
						i++;
						gotoxy(32, i);
						printf("Nota: %.2f",ad[pos3].nota);
					}
					else {
						i+=2;
						gotoxy(32, i);
						printf("Nota nao cadastrada");
					}
						
				}
				else{
					i+=2;
					gotoxy(32, i);
					printf("Disciplina nao cadastrada");
				}
					
			}
			else {
				i+=2;
				gotoxy(32, i);
				printf("RA nao cadastrado");
			}
			i+=2;
			gotoxy(32, i);
			printf("Digite o RA: ");
			fflush(stdin);
			gotoxy(14,23);
			gets(auxRA);
			erase();
		}
	}
	getch();
}

//relatorios

void relatorio_alunos(TPalunos aln[TF], int TLA){
	system("cls");
	red();
	if(TLA==0)
		printf("Nenhum aluno cadastrado\n");
	else{
		printf("TABELA ALUNOS\n");
		yellow();
		printf("\n   RA \t \t Nome\n");
		for(int i=0;i<TLA;i++){
			printf("%d| ",i+1);
			formatar_ra2(aln[i].RA);
			printf("  %s\n",aln[i].nome);
		}
	}
	getch();
}

void relatorio_disciplinas(TPdisciplinas dcp[TF], int TLD){
	system("cls");
	red();
	if(TLD==0)
		printf("Nenhuma disciplina cadastrada\n");
	else{
		printf("TABELA DISCIPLINAS\n");
		yellow();
		printf("\n   CodDisc \t Disciplina\n");
		for(int i=0;i<TLD;i++)
			printf("%d| %s \t\t %s\n",i+1,dcp[i].CodDisc,dcp[i].disciplina);
	}
	getch();
}

void relatorio_notas(TPalunos_disciplinas ad[TF], int TLAD){
	system("cls");
	red();
	if(TLAD==0)
		printf("\nNenhuma nota cadastrada\n");
	else{
		printf("TABELA NOTAS\n");
		yellow();
		printf("\n   RA \t\t CodDisc  Nota\n");
		for(int i=0,j=9;i<TLAD;i++,j++){
			printf("%d| ",i+1);
			formatar_ra2(ad[i].RA);
			printf("\t %s \t  %.2f\n",ad[i].CodDisc, ad[i].nota);
		}		
	}
	getch();
}

void relatorio_reprovados2(TPalunos aln[TF],int TLA,TPalunos_disciplinas ad[TF],int TLAD) {
    int i,j,reprovado;
    system("cls");
    red();
    printf("REPROVADOS EM DUAS OU MAIS DISCIPLINAS\n\n");
    yellow();
    for(i=0;i<TLA;i++) {
        reprovado=0;
        for(j=0;j<TLAD;j++) {
            if(strcmp(aln[i].RA,ad[j].RA)==0 && ad[j].nota<6) {
                reprovado++;
            }
        }
        if(reprovado>=2) {
            printf("RA: ");
            formatar_ra2(aln[i].RA);
            printf(" Nome: %s\n",aln[i].nome);
        }
    }
    getch();
}

void relatorio_lnome(TPalunos aln[TF], int TLA, char letra){
	char aux_letra;
	system("cls");
	printf("\nNOMES C/ A LETRA %c\n",letra);
	for(int i=0;i<TLA;i++){
		aux_letra=aln[i].nome[0];
		if(toupper(aux_letra)==toupper(letra))
			printf("\nRA: %s \t %s\n",aln[i].RA,aln[i].nome);
	}
	getch();
}

void relatorio_termo(TPdisciplinas dcp[TF], int TLD, char termo[10]) {
    char c[20][15],auxDisc[20];
    int i=0,j=0,x=0,nPalavras=0,indiceStruct=0,oi;
    while(indiceStruct<TLD) {
        i=0;
        j=0;
        x=0;
        nPalavras=0;
        strcpy(auxDisc,dcp[indiceStruct].disciplina);
        while(i<=strlen(auxDisc))
        {
            if(auxDisc[i]==' ' || auxDisc[i]=='\0'){

                while(j<i && auxDisc[j]!=' ') {
                    c[nPalavras][x]= auxDisc[j];
                    x++;
                    j++;
                }
                nPalavras++;
                j++;
            }
            i++;
            x=0;
        }
        for(i=0;i<=nPalavras;i++) {
            if(stricmp(c[i],termo)==0) {
            	printf("%s\n",auxDisc);
            }
        }
        indiceStruct++;
    }
    getch();
}

void mediag_abaixo(TPalunos_disciplinas ad[TF], int TLAD, TPdisciplinas dcp[TF], int TLD){
	int cont;
	float soma;
	system("cls");
	red();
	printf("\nDISCIPLINAS COM MEDIAS ABAIXO DE 6\n");
	yellow();
	for(int i=0;i<TLD;i++){
		cont=0;
		soma=0;
		for(int j=0;j<TLAD;j++){
			if(stricmp(dcp[i].CodDisc,ad[j].CodDisc)==0){
				cont++; 
				soma+=ad[j].nota;
			}
		}
		if(soma/cont<6)
			printf("\nDisciplina: %s Media: %.2f\n",dcp[i].disciplina,float(soma/cont));
	}
	getch();	
}

void relatorio_geral(TPalunos_disciplinas ad[TF], int TLAD, TPalunos aln[TF], int TLA, TPdisciplinas dcp[TF], int TLD){
	int pos;
	system("cls");
	red();
	printf("RELATORIO GERAL\n\n");
	yellow();
	for(int i=0;i<TLA;i++){
		printf("RA: ");
		formatar_ra2(aln[i].RA);
		printf(" Nome: %s\n\n",aln[i].nome);
		for(int j=0;j<TLAD;j++){
			if(stricmp(aln[i].RA,ad[j].RA)==0){
				pos=busca_CodDisc(dcp, TLD, ad[j].CodDisc);
				if(ad[j].nota>=6){
					printf("Disciplina: %s - %s \t Nota: %.2f  Situacao: Aprovado\n",dcp[pos].CodDisc,dcp[pos].disciplina,ad[j].nota);
				}
				else{
					printf("Disciplina: %s - %s \t Nota: %.2f  Situacao: Reprovado\n",dcp[pos].CodDisc,dcp[pos].disciplina,ad[j].nota);
				}
			}
		}
	}
	getch();
}

//executars

void executar_alunos(TPalunos aln[TF], int &TLA, TPalunos_disciplinas ad[TF], int TLAD){
	char op;
	do{
		op=menu_alunos();
		switch(op){
			case 'A': cadastro_alunos(aln, TLA);
				break;
			case 'B': exclusao_alunos(aln, TLA, ad, TLAD);
				break;
			case 'C': alteracao_alunos(aln, TLA, ad, TLAD);
				break;
			case 'D': consulta_alunos(aln, TLA);
				break;
		}
	}while(menu_alunos() != 27);
}

void executar_disciplinas(TPdisciplinas dcp[TF], int &TLD, TPalunos_disciplinas ad[TF], int TLAD){
	char op;
	do{
		op=menu_disciplinas();
		switch(op){
			case 'A': cadastro_disciplinas(dcp, TLD);
				break;
			case 'B': exclusao_disciplinas(dcp, TLD, ad, TLAD);
				break;
			case 'C': alteracao_disciplinas(dcp, TLD, ad, TLAD);
				break;
			case 'D':consulta_disciplinas(dcp, TLD);
				break;
		}
	}while(menu_disciplinas() != 27);
}

void executar_notas(TPalunos_disciplinas ad[TF], int &TLAD, TPalunos aln[TF], int TLA, TPdisciplinas dcp[TF], int TLD){
	char op;
	do{
		op=menu_notas();
		switch(op){
			case 'A':cadastro_notas(ad, TLAD, aln, TLA, dcp, TLD);
				break;
			case 'B':exclusao_notas(ad, TLAD, aln, TLA, dcp, TLD);
				break;
			case 'C':alteracao_notas(ad, TLAD, aln, TLA, dcp, TLD);
				break;
			case 'D':consulta_notas(ad, TLAD, aln, TLA, dcp, TLD);
				break;
		}
	}while(menu_notas() != 27);
}

void executar_relatorios(TPalunos_disciplinas ad[TF], int TLAD, TPalunos aln[TF], int TLA, TPdisciplinas dcp[TF], int TLD){
	int op;
	char letra, termo[10];
	do{
		op=menu_relatorios();
		switch(op){
			case '1': relatorio_alunos(aln, TLA);
				break;
			case '2': relatorio_disciplinas(dcp, TLD);
				break;
			case '3': relatorio_notas(ad, TLAD);
				break;
			case '4': relatorio_reprovados2(aln, TLA, ad, TLAD);
				break;
			case '5': 
				system("cls");
				printf("\nDigite a letra que deseja:");
				scanf(" %c",&letra);
				relatorio_lnome(aln, TLA, letra);
				break;
			case '6': 
				system("cls");
				printf("\nDigite o termo que deseja:");
				gets(termo);
				relatorio_termo(dcp, TLD, termo);
				break;
			case '7': mediag_abaixo(ad, TLAD, dcp, TLD);
				break;
			case '8': relatorio_geral(ad, TLAD, aln, TLA, dcp, TLD);
				break;
		}
	}while(menu_relatorios() != 27);
}

void executar_inicial(){
	TPalunos aln[TF];
	TPdisciplinas dcp[TF];
	TPalunos_disciplinas ad[TF];
	int TLA = 0, TLD = 0, TLAD = 0;
//	preencher(aln, TLA, dcp, TLD, ad, TLAD);
	char op;
	do{
		op=menu_inicial();
		switch(op){
			case 'A': executar_alunos(aln, TLA, ad, TLAD);
				break;
			case 'B': executar_disciplinas(dcp, TLD, ad, TLAD);
				break;
			case 'C': executar_notas(ad, TLAD, aln, TLA, dcp, TLD);
				break;
			case 'D': executar_relatorios(ad, TLAD, aln, TLA, dcp, TLD);
				break;
		}
	}while(menu_inicial() != 27);
}

//main

int main() {
	executar_inicial();
	return 0;
}
