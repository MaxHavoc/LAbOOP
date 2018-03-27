#pragma once

#include <iostream>
#include<fstream>
#include <locale.h>
#include <string>
#include "MyForm.h"
#include "Fab.h"
#include<vector>
# define M_PI           3.14159265358979323846
using namespace System;
using namespace std;
using namespace System::Runtime::InteropServices;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Input;
using namespace System::IO;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

ifstream fin;
ofstream fout;




char * and_SysStringToChar(System::String^ string)
{
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}


class shape
{
protected:
	shape *prev, *next;
	int X, Y;
	bool isSelected;
	string name;
	int radius;
	int angle;
	int color;
public:
	shape(int x, int y)
	{
		isSelected = false;
		name = "shape";
		angle = 0;
		prev = NULL;
		next = NULL;
		X = x;
		Y = y;
		color = 1;
	}
	shape()
	{
		isSelected = false;
		name = "shape";
		angle = 0;
		radius = 1;
		X = 0;
		Y = 0;
		prev = NULL;
		next = NULL;
		color = 1;
	};
	void SetNext(shape *a) {
		next = a;
	}

	shape* GetNext() {
		return next;
	}
	void SetPrev(shape *a) {
		prev = a;
	}

	shape* GetPrev() {
		return prev;
	}

	int GetX() {
		return X;
	}

	int GetY() {
		return Y;
	}
	virtual void ChangeX(int x)
	{
		X += x;
	}
	virtual void ChangeY(int y)
	{
		Y += y;
	}
	bool GetisSelected() {
		return isSelected;
	}
	void SetisSelected() {
		if (isSelected == true) isSelected = false;
		else isSelected = true;
	}
	int GetRadius()
	{
		return radius;
	}
	virtual void SetRadius(int r)
	{
		radius = r;
	}
	virtual void ChangeRadius(int a)
	{
		if(radius + a>0)radius = radius + a;
		else radius = 1;
	}
	string GetName()
	{
		return name;
	}
	int GetAngle()
	{
		return angle;
	}
	virtual void ChangeAngle(int a)
	{
		angle += a;
	}
	int GetColor()
	{
		return color;
	}
	void SetColor(int c)
	{
		color = c;
	}
	virtual void Save() {};
	virtual void Load() {};
	virtual void Draw(Color c, Graphics^ GR) {};
	virtual shape* GetObj() { return NULL; };
	virtual bool GetN() { return false; };
};


class CCircle :public shape
{
public:
	CCircle(int x, int y, int R) :shape(x, y)
	{
		name = "circle";
		radius = R;
	};
	CCircle() : shape()
	{
		name = "circle";
		
	}
	void Save() override
	{
		fout << "circle " << X << " " << Y<<" "<< color << " " << radius << endl;
	}
	void Load() override
	{
		fin >> X >> Y >>color>> radius;
	}
	void Draw(Color c, Graphics^ GR)
	{
		Pen^ myPen = gcnew Pen(c, 2);
		GR->DrawEllipse(myPen, Rectangle(X - radius, Y - radius, 2 * radius, 2 * radius));
	}
};

class Polygon :public shape
{
	int K;
public:
	Polygon(int x, int y, int R,int k) :shape(x, y)
	{
		name = "polygon";
		radius = R;
		K = k;
	}
	Polygon() :shape()
	{
		name = "polygon";
		radius = 10;
		K = 4;
	}
	void Save() override
	{
		fout << "polygon " << X << " " << Y<<" "<<color<< " " << radius<< " "<<angle<< " "<<K << endl;
	}
	void Load() override
	{
		fin >> X >> Y >> color>> radius>>angle>>K;
	}
	int GetK()
	{
		return K;
	}
	void Draw(Color c, Graphics^ GR)
	{
		Pen^ myPen = gcnew Pen(c, 2);
		float X1, Y1, X2, Y2;
		float Angle = angle;
		X1 = X + radius*cos(Angle*(M_PI / 180));
		Y1 = Y + radius*sin(Angle*(M_PI / 180));
		do
		{
			X2 = X + radius*cos(Angle*(M_PI / 180));
			Y2 = Y + radius*sin(Angle*(M_PI / 180));
			GR->DrawLine(myPen, X1, Y1, X2, Y2);
			X1 = X2;
			Y1 = Y2;
			Angle = Angle + 360 / K;
		} while (Angle <= 360 + angle);
		delete myPen;
	}
};
class Star :public shape
{
	int K;
public:
	Star(int x, int y, int R, int k) :shape(x, y)
	{
		name = "star";
		radius = R;
		K = k;
	}
	Star() :shape()
	{
		name = "star";
		radius = 10;
		K = 4;
	}
	void Save() override
	{
		fout << "star "<< X << " " << Y << " " << color << " " << radius << " " << angle << " " << K << endl;
	}
	void Load() override
	{
		fin >> X >> Y >> color >> radius >> angle >> K;
	}
	int GetK()
	{
		return K;
	}
	void Draw(Color c, Graphics^ GR)
	{
		Pen^ myPen = gcnew Pen(c, 2);
		float X1, Y1, X2, Y2, X3, Y3;
		float Angle = angle;
		int an = (K / 2);
		int an2 = (K / 2) + 1;
		for (int i = 0; i < K / 2; i++)
		{
			X1 = X + radius*cos(Angle*(M_PI / 180));
			Y1 = Y + radius*sin(Angle*(M_PI / 180));
			X2 = X + radius*cos((Angle + 360 * an / K)*(M_PI / 180));
			Y2 = Y + radius*sin((Angle + 360 * an / K)*(M_PI / 180));
			X3 = X + radius*cos((Angle + 360 * an2 / K)*(M_PI / 180));
			Y3 = Y + radius*sin((Angle + 360 * an2 / K)*(M_PI / 180));
			GR->DrawLine(myPen, X1, Y1, X2, Y2);
			GR->DrawLine(myPen, X1, Y1, X3, Y3);
			Angle = Angle + 360 / K;
		}
		X1 = X + radius*cos(Angle*(M_PI / 180));
		Y1 = Y + radius*sin(Angle*(M_PI / 180));
		X2 = X + radius*cos((Angle + 360 * an / K)*(M_PI / 180));
		Y2 = Y + radius*sin((Angle + 360 * an / K)*(M_PI / 180));
		GR->DrawLine(myPen, X1, Y1, X2, Y2);
		delete myPen;
	}
};

class Group : public shape
{
	vector<shape*> V;
	shape* S;
	int k,j;
public:
	Group() :shape() 
	{
		name = "group";
		j = 0;
		k = 0;
	};
	void Add(shape *Item)
	{
		X = Item->GetX();
		Y = Item->GetY();
		V.push_back(Item);
		k++;
	}
	void Draw(Color c, Graphics^ GR)
	{
		for (int i=0; i < k; i++) V[i]->Draw(c,GR);
	}
	void ChangeX(int x)
	{
		for (int i = 0; i < k; i++) V[i]->ChangeX(x);
	}
	void ChangeY(int y)
	{
		for (int i = 0; i < k; i++) V[i]->ChangeY(y);
	}
	void SetRadius(int r)
	{
		for (int i = 0; i < k; i++) V[i]->SetRadius(r);
	}
	void ChangeAngle(int a)
	{
		for (int i = 0; i < k; i++) V[i]->ChangeAngle(a);
	}
	void ChangeRadius(int a)
	{
		for (int i = 0; i < k; i++) V[i]->ChangeRadius(a);
	}
	void Save()
	{
		fout << "group " << k <<endl;
		for (int i = 0; i < k; i++) V[i]->Save();
	}
	void Load()
	{
		int kol;
		fin >> kol;
		GenericObjectFactory<string, shape> F;
		F.add<CCircle>("circle");
		F.add<Polygon>("polygon");
		F.add<Star>("star");
		F.add<Group>("group");
		for (int i = 0; i < kol; i++)
		{
			string name;
			shape* tmp;
			fin >> name;
			tmp = F.get(name)();
			Add(tmp);
			tmp->Load();
		}
	}
	shape* GetObj()
	{
		return V[j];
	}
	bool GetN()
	{
		if (j + 1 == k)
		{
			j = 0;
			return false;
		}
		j++;
		return true;
	}
};


class storage {
private:
	int k;
	shape *first, *last, *Selected, *Item;
public:

	storage()
	{
		Selected = NULL;
		k = 0;
	}
	int GetIndex() {
		return k;
	}
	void SetIndex(int a) {
		k = a;
	}

	shape* Getlast() {
		return last;
	}

	shape* GetItem() {
		return Item;
	}
	void load_file(string  file)
	{
		delet_all();
		fin.open(file, ios_base::in);
		int kol;
		fin >> kol;
		GenericObjectFactory<string, shape> Factory;
		Factory.add<CCircle>("circle");
		Factory.add<Polygon>("polygon");
		Factory.add<Star>("star");
		Factory.add<Group>("group");
		shape* tmp;
		for (int i = 0; i < kol; i++)
		{
			string name;
			fin >> name;
			tmp = Factory.get(name)();
			AddItem(tmp);
			tmp->Load();
		}
		fin.close();
	}
	void save_file(string  file)
	{
		fout.open(file, ios_base::out);
		fout << k << endl;
		shape* tmp = first;

		for (int j = 0; j < k; j++)
		{
			tmp->Save();
			tmp = tmp->GetNext();
		}
		fout.close();
	}


	shape *GetSelected() {
		return Selected;
	}

	shape *GetFirst() {
		return first;
	}

	void SetSelected(shape *a) {
		Selected = a;
	}
	void AddItem(shape* Item)
	{
		k++;
		if (k == 1) {
			first = Item;
			last = Item;
		}
		else
		{
			last->SetNext(Item);
			Item->SetPrev(last);
			last = Item;
			last->SetNext(NULL);
		}
	}
	void AddCircle(int x, int y, int r) {
		Item = new CCircle(x, y, r);
		AddItem(Item);
	}
	void AddPolygon(int x, int y, int r, int k)
	{
		Item = new Polygon(x, y, r, k);
		AddItem(Item);
	}
	void AddStar(int x, int y, int r, int k)
	{
		Item = new Star(x, y, r, k);
		AddItem(Item);
	}
	void DeleteItem(shape *a) {
		if (k > 0) {
			if (k == 1)
			{
				last = NULL;
				first = NULL;
				delete a;
				a = NULL;
			}
			else
				if (a == first) {
					first = a->GetNext();
					first->SetPrev(last);
					last->SetNext(first);
					delete a;
					a = first;
				}
				else
					if (a == last) {
						last = a->GetPrev();
						last->SetNext(first);
						first->SetPrev(last);
						delete a;
						a = last;
					}
					else
					{
						(a->GetNext())->SetPrev(a->GetPrev());
						(a->GetPrev())->SetNext(a->GetNext());
						delete a;
					}
			k--;
		}
	}
	void Delet(shape *a)
	{
		if (k > 0) {
			if (k == 1)
			{
				last = NULL;
				first = NULL;
			}
			else
				if (a == first) {
					first = a->GetNext();
					first->SetPrev(NULL);
				}
				else
					if (a == last) {
						last = a->GetPrev();
						last->SetNext(NULL);
					}
					else
					{
						(a->GetNext())->SetPrev(a->GetPrev());
						(a->GetPrev())->SetNext(a->GetNext());
					}
			k--;
		}
	}
	void delet_all()
	{
		while (k>0)
		{
			Item = first;
			if (k == 1)
			{
				delete Item;
			}
			else
			{
				(Item->GetNext())->SetPrev(NULL);
				first = Item->GetNext();
				delete Item;
			}
			k--;
		}
		last = NULL;
		first = NULL;
		Selected = NULL;
	}

};

class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
	virtual void unExecute() = 0;
protected:
	Command(shape* p)
	{
		s = p;
	}
	shape* s;
};

class ChangeXCommand : public Command
{
	int a;
public:
	ChangeXCommand(shape* p, int A) : Command(p)
	{
		a = A;
	}
	void Execute()
	{
		s->ChangeX(a);
	}
	void unExecute()
	{
		if(s!=NULL) s->ChangeX(-a);
	}
};

class ChangeYCommand : public Command
{
	int a;
public:
	ChangeYCommand(shape* p, int A) : Command(p)
	{
		a = A;
	}
	void Execute()
	{
		s->ChangeY(a);
	}
	void unExecute()
	{
		if (s != NULL) s->ChangeY(-a);
	}
};

class ChangeRadiusCommand : public Command
{
	int r;
public:
	ChangeRadiusCommand(shape *p, int R) : Command(p)
	{
		r = R;
	}
	void Execute()
	{
		s->ChangeRadius(r);
	}
	void unExecute()
	{
		if (s != NULL) s->ChangeRadius(-r);
	}
};

class ChangeAngleCommand : public Command
{
	int a;
public:
	ChangeAngleCommand(shape *p, int A) :Command(p)
	{
		a = A;
	}
	void Execute()
	{
		s->ChangeAngle(a);
	}
	void unExecute()
	{
		if (s != NULL) s->ChangeAngle(-a);
	}
};

class Receiver
{
	vector<Command*> DoneCommands;
	Command* com;
public:
	void ChangeX(shape *p, int x)
	{
		com = new ChangeXCommand(p, x);
		com->Execute();
		DoneCommands.push_back(com);
	}
	void ChangeY(shape *p, int x)
	{
		com = new ChangeYCommand(p, x);
		com->Execute();
		DoneCommands.push_back(com);
	}
	void ChangeAngle(shape *p, int x)
	{
		com = new ChangeAngleCommand(p, x);
		com->Execute();
		DoneCommands.push_back(com);
	}
	void ChangeRad(shape *p, int x)
	{
		com = new ChangeRadiusCommand(p, x);
		com->Execute();
		DoneCommands.push_back(com);
	}
	void Undo()
	{
		if (DoneCommands.size() != 0)
		{
			com = DoneCommands.back();
			DoneCommands.pop_back();
			com->unExecute();
			delete com;
		}
	}
	void Delete()
	{
		DoneCommands.clear();
		com = NULL;
	}
};

