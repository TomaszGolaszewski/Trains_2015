//	TRAINS 
//	by Tomasz Golaszewski 
//	2015




#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>

double pi=4.*atan(1.);

//----------------------------------------------------------
//Funkcje

void TomaszGames(int Rx,int Ry)
{
	int x;
	int y;
	x=Rx/30;
	y=Ry/20;
	if(y<x)x=y;
	else y=x;
	
	setcolor(BLUE);
	//T
	bar(1*x,2*y,9*x,4*y);
	bar(4*x,2*y,6*x,10*y);
	//o
	bar(7*x,5*y,11*x,6*y);
	bar(7*x,9*y,11*x,10*y);
	bar(7*x,5*y,8*x,10*y);
	bar(10*x,5*y,11*x,10*y);
	//m
	bar(12*x,5*y,17*x,6*y);
	bar(12*x,5*y,13*x,10*y);
	bar(14*x,5*y,15*x,10*y);
	bar(16*x,5*y,17*x,10*y);
	//a
	bar(18*x,5*y,21*x,6*y);
	bar(18*x,5*y,19*x,10*y);
	bar(20*x,5*y,21*x,10*y);
	bar(18*x,7*y,21*x,8*y);
	//s
	bar(22*x,5*y,25*x,6*y);
	bar(22*x,7*y,25*x,8*y);
	bar(22*x,9*y,25*x,10*y);
	bar(22*x,5*y,23*x,8*y);
	bar(24*x,7*y,25*x,10*y);
	//z
	bar(26*x,5*y,29*x,6*y);
	bar(26*x,7*y,29*x,8*y);
	bar(26*x,9*y,29*x,10*y);
	bar(28*x,5*y,29*x,8*y);
	bar(26*x,7*y,27*x,10*y);
	//G
	bar(5*x,11*y,11*x,13*y);
	bar(5*x,17*y,11*x,19*y);
	bar(5*x,11*y,7*x,19*y);
	bar(9*x,15*y,11*x,19*y);
	//a
	bar(12*x,14*y,15*x,15*y);
	bar(12*x,14*y,13*x,19*y);
	bar(14*x,14*y,15*x,19*y);
	bar(12*x,16*y,15*x,17*y);
	//m
	bar(16*x,14*y,21*x,15*y);
	bar(16*x,14*y,17*x,19*y);
	bar(18*x,14*y,19*x,19*y);
	bar(20*x,14*y,21*x,19*y);
	//e
	bar(22*x,14*y,25*x,15*y);
	bar(22*x,16*y,25*x,17*y);
	bar(22*x,18*y,25*x,19*y);
	bar(22*x,14*y,23*x,19*y);
	//s
	bar(26*x,14*y,29*x,15*y);
	bar(26*x,16*y,29*x,17*y);
	bar(26*x,18*y,29*x,19*y);
	bar(26*x,14*y,27*x,17*y);
	bar(28*x,16*y,29*x,19*y);
/*	while(1)
	{
		if(mousedown())
		{
			exit(-1);
		}
	}
*/
	delay(2000);
	setcolor(BLACK);
	bar(0,0,Rx,Ry);
	setcolor(WHITE);
}

/*
void funkcja(int x,int y,int r)
{
	setcolor(WHITE);
	line(x*r,y*r,x*r+r,y*r);
	bar(x*r,y*r,x*r+r,y*r+r);
	pieslice(x*r+7*r/10,y*r+r/10,235,-55,2*r/5);
}
*/

double norma(double x1,double y1,double x2, double y2)
{
	double norm;
	norm=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return norm;
}

double atan2(double y2,double y1,double x2,double x1)
{
	double alfa;
	alfa=atan((double)(y2-y1)/(double)(x2-x1));
	if(x2<x1) alfa=alfa+pi;
	return alfa;
}

void elektrowoz(int x,int y,double alfa,int c,int p)
{
	int odst=3;
	int r=3;

	if(c==0) setcolor(WHITE);//nic
	if(c==1) setcolor(GREEN);//stoi
	if(c==2) setcolor(YELLOW);//jedzie
	if(c==3) setcolor(RED);//zderzenie
	if(c==8) setcolor(BLUE);//wyszczegolnienie
	if(c==9) setcolor(BLACK);//znikniecie

	pieslice(x,y,0,0,r);
	pieslice(x+odst*cos(alfa),y+odst*sin(alfa),0,0,r);
	pieslice(x-odst*cos(alfa),y-odst*sin(alfa),0,0,r);
	pieslice(x+2*odst*cos(alfa),y+2*odst*sin(alfa),0,0,r);
	pieslice(x-2*odst*cos(alfa),y-2*odst*sin(alfa),0,0,r);

	if(c!=9)
	{
		setcolor(BLACK);
		//line(x,y,x+odst*cos(alfa),y+odst*sin(alfa));
		pieslice(x+p*odst*cos(alfa),y+p*odst*sin(alfa),0,0,2);
	}
}

void wagon(int x,int y,double alfa,int c)
{
	int odst=3;
	int r=3;

	if(c==0) setcolor(WHITE);//nic
	if(c==1) setcolor(GREEN);//stoi
	if(c==2) setcolor(YELLOW);//jedzie
	if(c==3) setcolor(RED);//zderzenie
	if(c==8) setcolor(BLUE);//wyszczegolnienie
	if(c==9) setcolor(BLACK);//znikniecie

	circle(x,y,3);
	circle(x+odst*cos(alfa),y+odst*sin(alfa),r);
	circle(x-odst*cos(alfa),y-odst*sin(alfa),r);
	circle(x+2*odst*cos(alfa),y+2*odst*sin(alfa),r);
	circle(x-2*odst*cos(alfa),y-2*odst*sin(alfa),r);
}

void pojazd(int x,int y,double alfa, int c, int a, int p)
{
	switch(a)
	{
	case 1:
		elektrowoz(x,y,alfa,c,p);
		break;
	case 2:
		wagon(x,y,alfa,c);
		break;
	}
}

void zwrotnica(int x,int y)
{
	int r=4;
/*
	setcolor(GREEN);
	pieslice(x,y,270,360,r);
	setcolor(RED);
	pieslice(x,y,0,90,r);
	pieslice(x,y,180,270,r);
	setcolor(GREEN);
	pieslice(x,y,90,180,r);
*/	
	setcolor(BLUE);
	pieslice(x,y,0,0,r);
}

void stan(int x,int y,int c)
{
	int odst=3;
	int r=4;

	if(c==0) setcolor(WHITE);//nic
	if(c==1) setcolor(GREEN);//stoi
	if(c==2) setcolor(YELLOW);//jedzie
	if(c==3) setcolor(RED);//zderzenie
	if(c==8) setcolor(BLUE);//wyszczegolnienie
	if(c==9) setcolor(BLACK);//znikniecie

	pieslice(x,y,0,0,r);
}

void suwak(int y)
{
	setcolor(WHITE);
	line(1175,y+5,1175,y+16);//-3.5
	line(1180,y+7,1180,y+14);//-3
	line(1200,y+7,1200,y+14);//-1
	line(1205,y+5,1205,y+16);//-0.5
	line(1210,y+8,1210,y+13);//0
	line(1215,y+5,1215,y+16);//0.5
	line(1220,y+7,1220,y+14);//1
	line(1240,y+7,1240,y+14);//3
	line(1245,y+5,1245,y+16);//3.5
	line(1175,y+10,1245,y+10);//---
}

void predkosc(int y,int x)
{
	if(x==9) //znikanie
	{
		setcolor(BLACK);
		bar(1175,y+8,1245,y+13);
	}
	else //predkosc aktualna
	{
		setcolor(RED);
		bar(1210,y+8,x,y+13);
	}	
}

//----------------------------------------------------------
//Funkcja glowna

void main()
{
	int x;
	int y;

	int lP;
	int lL;
	int lZ;
	int smiec;
	int starytor;
	int nowytor;
	int punkt;
	int drugipunkt;
	int pociag;
	int wagon;
	int zwrot;
	double norm;
	double beta;

	int iE[5][2]={{0,1},{1,1},{92,1},{95,1},{97,1}};
	double dE[5][4]={{350,10,0,0},{300,20,0,0},{250,30,0,0},{240,40,0,0},{230,50,0,0}};
	int e=5;

	int iW[50][2]={{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},
		{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},
		{92,1},{92,1},{92,1},{92,1},{92,1},{92,1},{92,1},{92,1},{92,1},{92,1},
		{95,1},{95,1},{95,1},{95,1},{95,1},{95,1},{95,1},{95,1},{95,1},{95,1},
		{97,1},{97,1},{97,1},{97,1},{97,1},{97,1},{97,1},{97,1},{97,1},{97,1}};
	double dW[50][4]={{30,10,0,0},{50,10,0,0},{70,10,0,0},{90,10,0,0},{110,10,0,0},{130,10,0,0},{150,10,0,0},{170,10,0,0},{190,10,0,0},{210,10,0,0},
		{30,20,0,0},{50,20,0,0},{70,20,0,0},{90,20,0,0},{110,20,0,0},{130,20,0,0},{150,20,0,0},{170,20,0,0},{190,20,0,0},{210,20,0,0},
		{30,30,0,0},{50,30,0,0},{70,30,0,0},{90,30,0,0},{110,30,0,0},{130,30,0,0},{150,30,0,0},{170,30,0,0},{190,30,0,0},{210,30,0,0},
		{30,40,0,0},{50,40,0,0},{70,40,0,0},{90,40,0,0},{110,40,0,0},{130,40,0,0},{150,40,0,0},{170,40,0,0},{190,40,0,0},{210,40,0,0},
		{30,50,0,0},{50,50,0,0},{70,50,0,0},{90,50,0,0},{110,50,0,0},{130,50,0,0},{150,50,0,0},{170,50,0,0},{190,50,0,0},{210,50,0,0}};
	int w=50;

	int v=e+w;

	int **iV;
	iV=(int**)malloc(v*sizeof(int*));
	for(int i=0;i<v;++i) 			
		iV[i]=(int*)malloc(7*sizeof(int));

	for(int i=0;i<e;++i)
	{
		for(int k=0;k<2;++k)
		{
			iV[i][k]=iE[i][k];
		}
		iV[i][2]=0;
		iV[i][3]=1;
		iV[i][4]=i; //999;
		iV[i][5]=1;
		iV[i][6]=1;
	}

	for(int i=0;i<w;++i)
	{
		for(int k=0;k<2;++k)
		{
			iV[e+i][k]=iW[i][k];
		}
		iV[e+i][2]=0;
		iV[e+i][3]=1;
		iV[e+i][4]=999;
		iV[e+i][5]=1;
		iV[e+i][6]=2;
	}

	double **dV;
	dV=(double**)malloc(v*sizeof(double*));
	for(int i=0;i<v;++i) 			
		dV[i]=(double*)malloc(4*sizeof(double));

	for(int i=0;i<e;++i)
	{
		for(int k=0;k<4;++k)
		{
			dV[i][k]=dE[i][k];
		}
	}

	for(int i=0;i<w;++i)
	{
		for(int k=0;k<4;++k)
		{
			dV[e+i][k]=dW[i][k];
		}
		//dV[e+i][2]=1;
		//iV[e+i][1]=2;
		//iV[e+i][5]=2;
	}

	FILE *F;

	printf("\"TRAINS\"\nby Tomasz Golaszewski\n2015\n");

	if(1)
	{
		F=fopen("Mapy/Mapa3.txt","r");
	}

	fscanf(F,"%d\t%d\t%d\n",&lP,&lL,&lZ);

	lP++;
	lL++;
	lZ++;

	int **P;
	P=(int**)malloc(lP*sizeof(int*));
	for(int i=0;i<lP;++i) 			
		P[i]=(int*)malloc(4*sizeof(int));

	for(int i=0;i<lP;++i)
	{
		for(int k=0;k<5;++k)
		{
			if(k)fscanf(F,"%d",&P[i][k-1]);
			else fscanf(F,"%d",&smiec);
		}
	}

	int **L;
	L=(int**)malloc(lL*sizeof(int*));
		for(int i=0;i<lL;++i)
			L[i]=(int*)malloc(2*sizeof(int));

	for(int i=0;i<lL;++i)
	{
		for(int k=0;k<3;++k)
		{
			if(k)fscanf(F,"%d",&L[i][k-1]);
			else fscanf(F,"%d",&smiec);
		}
	}

	int **Z;
	Z=(int**)malloc(lZ*sizeof(int*));
		for(int i=0;i<lZ;++i)
			Z[i]=(int*)malloc(8*sizeof(int));

	for(int i=0;i<lZ;++i)
	{
		for(int k=0;k<7;++k)
		{
			if(k)fscanf(F,"%d",&Z[i][k-1]);
			else fscanf(F,"%d",&smiec);
		}
		Z[i][6]=0;
		Z[i][7]=0;
	}

	fclose(F);

	graphics(1260,710);
	TomaszGames(1260,710);
	line(1150,0,1150,800);
	line(1170,0,1170,20*e);
	//line(1130,100,1130,500);

	for(int i=0;i<e;++i)
	{
		line(1150,20*(i+1),1400,20*(i+1));
		suwak(20*i);
	}
	line(1150,20*(e+1),1400,20*(e+1));

	setcolor(RED);
	bar(1157,20*e+7,1246,20*(e+1)-6);

	//line(10,10,400,10);
	//line(10,20,400,20);

	setcolor(WHITE);
	for(int i=0;i<lL;++i)
	{
		line(P[L[i][0]][0],P[L[i][0]][1],P[L[i][1]][0],P[L[i][1]][1]);
	}

	for(int i=0;i<lP;++i)
	{
		if((P[i][2]==9999)||(P[i][3]==9999))
		{
			if(P[i][2]==9999) starytor=P[i][3];
			else starytor=P[i][2];

			//printf("%d\t%d\n",i,starytor);
			if(L[starytor][0]==i) drugipunkt=L[starytor][1];
			else drugipunkt=L[starytor][0];

			if(P[i][0]==P[drugipunkt][0]) line(P[i][0]-2,P[i][1],P[i][0]+3,P[i][1]);
			if(P[i][1]==P[drugipunkt][1]) line(P[i][0],P[i][1]-2,P[i][0],P[i][1]+3);

		}
	}

	setcolor(BLUE);
	norm=25;
	for(int i=0;i<lZ;++i)
	{	
		zwrotnica(Z[i][0],Z[i][1]);
		zwrot=Z[i][4];
		punkt=Z[i][5];
		if(L[zwrot][0]==punkt)drugipunkt=L[zwrot][1];
		else drugipunkt=L[zwrot][0];
		if((P[punkt][0]==P[drugipunkt][0])||(P[punkt][1]==P[drugipunkt][1]))
		{
			beta=atan2(P[drugipunkt][1],P[punkt][1],P[drugipunkt][0],P[punkt][0]);
			Z[i][6]=P[punkt][0]+norm*cos(beta);
			Z[i][7]=P[punkt][1]+norm*sin(beta);
		}
		else 
		{
			Z[i][6]=P[drugipunkt][0];
			Z[i][7]=P[drugipunkt][1];
		}
		line(P[punkt][0],P[punkt][1],Z[i][6],Z[i][7]);
	}
	
/*
	for(int i=0;i<e;++i)
	{
		elektrowoz(dE[i][0],dE[i][1],0,iE[i][1]);
	}
*/

//Perony
	setcolor(DARKGRAY);
	//TomaszLand Zachodni
	bar(24,270,27,550);
	//TomaszLand Centralny
	bar(450,644,730,647);
	bar(450,664,730,667);
	bar(450,684,730,687);
	//TomaszLand Wschodni
	//bar(1124,140,1127,420);
	bar(1114,140,1117,420);
	bar(1134,140,1137,420);



	//wagon(20,30,0,0);
	//wagon(40,30,0,0);
	//wagon(60,30,0,0);
	//setcolor(WHITE);

/*
	for(int i=0;i<64;i++)
	{
		setcolor(i);
		bar(i*15,200,i*15+15,600);
	}
*/	
	while(1)
	{
		if(mousedown()) 
		{	
			x=mousecurrentx();
			y=mousecurrenty();

			if(x<1150)
			{
				for(int i=0;i<lZ;++i)
				{
					if(norma(x,y,Z[i][0],Z[i][1])<10.)
					{
						//printf("%d\n",i);
						norm=25;
						setcolor(WHITE);
						line(P[Z[i][5]][0],P[Z[i][5]][1],Z[i][6],Z[i][7]);

						punkt=Z[i][5];

						zwrot=Z[i][3];
						Z[i][3]=Z[i][4];
						Z[i][4]=zwrot;

						if(P[punkt][2]==zwrot) P[punkt][2]=Z[i][3];
						else P[punkt][3]=Z[i][3];

						if(L[zwrot][0]==punkt)drugipunkt=L[zwrot][1];
						else drugipunkt=L[zwrot][0];
						if((P[punkt][0]==P[drugipunkt][0])||(P[punkt][1]==P[drugipunkt][1]))
						{
							beta=atan2(P[drugipunkt][1],P[punkt][1],P[drugipunkt][0],P[punkt][0]);
							Z[i][6]=P[punkt][0]+norm*cos(beta);
							Z[i][7]=P[punkt][1]+norm*sin(beta);
						}
						else 
						{
							Z[i][6]=P[drugipunkt][0];
							Z[i][7]=P[drugipunkt][1];
						}
					}
				}
			}

			if((x>1150)&&(x<1250)&&(y<(e*20)))
			{
				pociag=y/20;

				if(iV[pociag][1]!=3)
				{
//Do tylu					
					if((x>1175)&&(x<1205))
					{
						for(int i=0;i<v;i++)
						{
							if(iV[i][4]==pociag)
							{
								if(iV[i][3]>0) dV[i][3]=dV[i][3]-pi;
								dV[i][2]=(1210-x)/10.;
								iV[i][1]=2;
								iV[i][3]=-1;
								if(iV[i][5]!=8) iV[i][5]=2;
								predkosc(20*pociag,9);
								predkosc(20*pociag,x);
								suwak(20*pociag);
							}
						}
					}
//Stop
					if((x>1205)&&(x<1215))
					{
						for(int i=0;i<v;i++)
						{
							if(iV[i][4]==pociag)
							{
								dV[i][2]=0;
								iV[i][1]=1;
								if(iV[i][5]!=8) iV[i][5]=1;
								predkosc(20*pociag,9);
								//predkosc(20*pociag,x);
								suwak(20*pociag);
							}
						}
					}
//Do przodu
					if((x>1215)&&(x<1245))
					{
						for(int i=0;i<v;i++)
						{
							if(iV[i][4]==pociag)
							{
								if(iV[i][3]<0) dV[i][3]=dV[i][3]+pi;
								dV[i][2]=(x-1210)/10.;
								iV[i][1]=2;
								iV[i][3]=1;
								if(iV[i][5]!=8) iV[i][5]=2;
								predkosc(20*pociag,9);
								predkosc(20*pociag,x);
								suwak(20*pociag);
							}
						}
					}
				}
//Wyszczegolnienie
				if((x>1150)&&(x<1170))
				{	
					for(int i=0;i<v;i++) 
					{
						iV[i][5]=iV[i][1];
						if(iV[i][4]==pociag) iV[i][5]=8;
					}
				}
			}
			if((x>1150)&&(x<1250)&&(y>(e*20))&&(y<((e+1)*20)))
			{
//Stop radiowy
				for(int i=0;i<v;++i)
				{
					if(iV[i][1]==2)
					{
						dV[i][2]=0;
						iV[i][1]=1;
						if(iV[i][5]!=8) iV[i][5]=1;
						if(iV[i][6]==1)
						{
							predkosc(20*i,9);
							suwak(20*i);
						}
					}
				}
			}
			if((x>1150)&&(x<1250)&&(y>((e+1)*20)))
			{
				break;
				//while(1);
			}
		}

//Znikniecie
		for(int i=0;i<v;++i)
		{
			if(iV[i][1]==2) pojazd(dV[i][0],dV[i][1],dV[i][3],9,iV[i][6],0);
		}
//Rysowanie linii
		setcolor(WHITE);
		for(int i=0;i<v;++i)
		{
			if(iV[i][1]==2) 
			{
				line(P[L[iV[i][0]][0]][0],P[L[iV[i][0]][0]][1],P[L[iV[i][0]][1]][0],P[L[iV[i][0]][1]][1]);
				line(P[L[iV[i][2]][0]][0],P[L[iV[i][2]][0]][1],P[L[iV[i][2]][1]][0],P[L[iV[i][2]][1]][1]);
			}
		}
//Zwrotnice
		setcolor(BLUE);
		for(int i=0;i<lZ;++i)
		{
			line(P[Z[i][5]][0],P[Z[i][5]][1],Z[i][6],Z[i][7]);
		}
//Nowa pozycja
		for(int i=0;i<v;++i)
		{
			if(iV[i][1]==2)
			{
				dV[i][0]=dV[i][0]+dV[i][2]*cos(dV[i][3]);
				dV[i][1]=dV[i][1]+dV[i][2]*sin(dV[i][3]);
			}
		}
		//printf("%d\t%lf\n",E[3][0],cos(dE[3]));

//Szukanie kolizji
		for(int i=0;i<v;++i)
		{
			for(int k=i+1;k<v;++k)
			{
				if(iV[i][0]==iV[k][0])
				{
//Przylaczenie wagonu
					if(norma(dV[i][0],dV[i][1],dV[k][0],dV[k][1])<18.)
					{
						if(iV[i][4]==999)
						{
							iV[i][1]=iV[k][1];
							iV[i][3]=iV[k][3];
							iV[i][4]=iV[k][4];
							iV[i][5]=iV[k][5];
							dV[i][2]=dV[k][2];
							dV[i][3]=dV[k][3];
						}
						if(iV[k][4]==999)
						{
							iV[k][1]=iV[i][1];
							iV[k][3]=iV[i][3];
							iV[k][4]=iV[i][4];
							iV[k][5]=iV[i][5];
							dV[k][2]=dV[i][2];
							dV[k][3]=dV[i][3];
						}
//Wewnetrzna kolizja
						if(iV[i][1]==3||iV[k][1]==3)
						{
							dV[i][2]=0;
							iV[i][1]=3;
							if(iV[i][5]!=8) iV[i][5]=3;
							dV[k][2]=0;
							iV[k][1]=3;
							if(iV[k][5]!=8) iV[k][5]=3;
						}
					}
//Kolizja
					//if(iV[i][4]!=iV[k][4]||iV[i][1]==3||iV[k][1]==3)
					if(norma(dV[i][0],dV[i][1],dV[k][0],dV[k][1])<16.)
					{
						dV[i][2]=0;
						iV[i][1]=3;
						if(iV[i][5]!=8) iV[i][5]=3;
						dV[k][2]=0;
						iV[k][1]=3;
						if(iV[k][5]!=8) iV[k][5]=3;
					}
				}
/*
				if(norma(dV[i][0],dV[i][1],dV[k][0],dV[k][1])<8.)
				{
					dV[i][2]=0;
					iV[i][1]=3;
					if(iV[i][5]!=8) iV[i][5]=3;
					dV[k][2]=0;
					iV[k][1]=3;
					if(iV[k][5]!=8) iV[k][5]=3;
				}
*/
			}
//Zakret
			if(iV[i][1]==2)
			{
				if(norma(dV[i][0],dV[i][1],P[L[iV[i][0]][0]][0],P[L[iV[i][0]][0]][1])<10.)
				{
					//printf("1\n");
					starytor=iV[i][0];
					punkt=L[starytor][0];
					//printf("%d\n",starytor);
					if((dV[i][2]>2.9)||(P[punkt][2]==9999)||(P[punkt][3]==9999))//Predkosc i koniec toru
					{
						dV[i][2]=0;
						iV[i][1]=3;
						if(iV[i][5]!=8) iV[i][5]=3;
					}
					else
					{
						if(norma(P[punkt][0],P[punkt][1],P[L[starytor][1]][0],P[L[starytor][1]][1])<norma(dV[i][0],dV[i][1],P[L[starytor][1]][0],P[L[starytor][1]][1]))//Czy wyszlismy poza tor
						{
							norm=norma(dV[i][0],dV[i][1],P[punkt][0],P[punkt][1]);
							iV[i][2]=starytor;
							if(starytor==P[punkt][2])//Szukanie nowego toru
							{
								nowytor=P[punkt][3];
								iV[i][0]=nowytor;
								if(L[nowytor][0]==punkt)drugipunkt=L[nowytor][1];
								else drugipunkt=L[nowytor][0];
								dV[i][3]=atan2(P[drugipunkt][1],P[punkt][1],P[drugipunkt][0],P[punkt][0]);
								//smiec=0;
								dV[i][0]=P[punkt][0]+norm*cos(dV[i][3]);
								dV[i][1]=P[punkt][1]+norm*sin(dV[i][3]);
							}
							else if(starytor==P[punkt][3]) 
							{
								nowytor=P[punkt][2];
								iV[i][0]=nowytor;
								if(L[nowytor][0]==punkt) drugipunkt=L[nowytor][1];
								else drugipunkt=L[nowytor][0];
								dV[i][3]=atan2(P[drugipunkt][1],P[punkt][1],P[drugipunkt][0],P[punkt][0]);
								//smiec=1;
								dV[i][0]=P[punkt][0]+norm*cos(dV[i][3]);
								dV[i][1]=P[punkt][1]+norm*sin(dV[i][3]);
							}
							else
							{
								dV[i][2]=0;
								iV[i][1]=3;
								if(iV[i][5]!=8) iV[i][5]=3;
								//smiec=4;
							}
						}
					}
				}
				else if(norma(dV[i][0],dV[i][1],P[L[iV[i][0]][1]][0],P[L[iV[i][0]][1]][1])<10.)
				{
					//printf("2\n");
					starytor=iV[i][0];
					punkt=L[starytor][1];
					if((dV[i][2]>2.9)||(P[punkt][2]==9999)||(P[punkt][3]==9999))//Predkosc i koniec toru
					{
						dV[i][2]=0;
						iV[i][1]=3;
						if(iV[i][5]!=8) iV[i][5]=3;
					}
					else
					{
						if(norma(P[L[starytor][0]][0],P[L[starytor][0]][1],P[punkt][0],P[punkt][1])<norma(dV[i][0],dV[i][1],P[L[starytor][0]][0],P[L[starytor][0]][1]))//Czy wyszlismy poza tor
						{
							norm=norma(dV[i][0],dV[i][1],P[punkt][0],P[punkt][1]);
							iV[i][2]=starytor;
							if(starytor==P[punkt][2])//Szukanie nowego toru
							{
								nowytor=P[punkt][3];
								iV[i][0]=nowytor;
								if(L[nowytor][0]==punkt) drugipunkt=L[nowytor][1];
								else drugipunkt=L[nowytor][0];
								dV[i][3]=atan2(P[drugipunkt][1],P[punkt][1],P[drugipunkt][0],P[punkt][0]);
								//smiec=2;
								dV[i][0]=P[punkt][0]+norm*cos(dV[i][3]);
								dV[i][1]=P[punkt][1]+norm*sin(dV[i][3]);
							}
							else if(starytor==P[punkt][3]) 
							{
								nowytor=P[punkt][2];
								iV[i][0]=nowytor;
								if(L[nowytor][0]==punkt) drugipunkt=L[nowytor][1];
								else drugipunkt=L[nowytor][0];
								dV[i][3]=atan2(P[drugipunkt][1],P[punkt][1],P[drugipunkt][0],P[punkt][0]);
								//smiec=3;
								dV[i][0]=P[punkt][0]+norm*cos(dV[i][3]);
								dV[i][1]=P[punkt][1]+norm*sin(dV[i][3]);
							}
							else
							{
								dV[i][2]=0;
								iV[i][1]=3;
								if(iV[i][5]!=8) iV[i][5]=3;
								//smiec=5;
							}
						}
					}
				}
				//else //printf("0\n");
			}
		}
		//printf("%lf\t%d\n",dV[3][3],smiec);
		//printf("%d\t%d\n",iV[3][0],iV[3][2]);
		//printf("%d\n",smiec);

//Rysowanie
		for(int i=0;i<v;++i)
		{
			pojazd(dV[i][0],dV[i][1],dV[i][3],iV[i][5],iV[i][6],iV[i][3]);
			if(i<e) stan(1160,10+20*i,iV[i][5]);
		}

		delay(30);
		//delay(40);
	}
/*
	P=fopen("Mapy/Mapa.txt","w");
			fprintf(P,"%d\t%d\t%d\n",Rx,Ry,r);
			
			for(int i=0;i<Rx;++i)
			{
				for(int k=0;k<Ry;++k)
				{
					fprintf(P,"%d\t",A[k][i]);
				}
				fprintf(P,"\n");
			}
			fclose(P);
			*/
	
	for(int i=0;i<lP;++i) free(P[i]);
	free(P);	
	for(int i=0;i<lL;++i) free(L[i]);
	free(L);
	for(int i=0;i<lZ;++i) free(Z[i]);
	free(Z);
	
	//wait();
}

