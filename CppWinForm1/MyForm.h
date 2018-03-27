#pragma once
#include "Storage.h"
#include <sstream>
#include <fstream>
#include<cmath>
# define M_PI           3.14159265358979323846
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Input;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	//Storage_obj Storage();

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Receiver *R=new Receiver();
		Color Standart = Color::Black;
		Color Selected = Color::Blue;
		Color C = Color::Red;
		Color C1 = Color::Yellow;
		Color C2 = Color::Green;
		int r = 40;
		storage *Storage = new storage();
		bool isLastSelected = true;
		int type = 1; //1-ÍÛ„, 2-ÏÌÓ„ÓÛ„ÓÎ¸ÌËÍ, 3-Á‚ÂÁ‰‡
		int k=3,k2=5, a=1;
		int index = 1;
		int kolc = 0, kolp = 0, kols = 0, kolg = 0;
		int ob = 0;
		int si = 0;
		int met = 0;
	private: 
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::ToolStripMenuItem^  Ó˜ËÒÚËÚ¸ToolStripMenuItem;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::OpenFileDialog^  openFileDialog1;
		System::Windows::Forms::PictureBox^  pictureBox1;
		System::Windows::Forms::NumericUpDown^  numericUpDown1;	
		System::Windows::Forms::RadioButton^  radioButton1;
		System::Windows::Forms::RadioButton^  radioButton2;
		System::Windows::Forms::RadioButton^  radioButton3;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::ImageList^  imageList1;

			 System::Windows::Forms::NumericUpDown^  numericUpDown3;
			 
	public:
		Bitmap^ myBitmap;
	private: System::Windows::Forms::Button^  button10;


	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::TreeView^  treeView1;

	public:
		Graphics^ gr;
		MyForm(void)
		{
			InitializeComponent();
			DoubleBuffered = true;
			numericUpDown1->Value = r;
			numericUpDown2->Value = k2;
			numericUpDown3->Value = k;
			radioButton1->Checked = true;
			treeView1->BeginUpdate();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private:
		void Paint() {
			myBitmap = gcnew Bitmap(pictureBox1->Size.Width, pictureBox1->Size.Height);
			gr = Graphics::FromImage(myBitmap);	
			gr->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			if(Storage->GetIndex()!=0)
			{
				Color c;
				int i = 0;
				Storage->SetSelected(Storage->GetFirst());
				do {
					if(Storage->GetSelected()->GetColor()==1) c = Standart;
					else if (Storage->GetSelected()->GetColor() == 2) c = C1;
					else c = C2;
					if (Storage->GetSelected()->GetisSelected()) c = C;
					if (i == si) c = Selected;
					Storage->GetSelected()->Draw(c, gr);
					Storage->SetSelected(Storage->GetSelected()->GetNext());
					i++;
				} while (i<Storage->GetIndex());
			}
			pictureBox1->Image = myBitmap;
			refresh();
		}
		void refresh()
		{
			treeView1->Nodes->Clear();
			TreeNode^ node = treeView1->Nodes->Add("Storage");
			if (Storage->GetIndex() != 0)
			{
				int i = 0;
				Storage->SetSelected(Storage->GetFirst());
				do
				{
					string str = Storage->GetSelected()->GetName();
					processNode(node->Nodes->Add(%String(str.c_str())), Storage->GetSelected());
					Storage->SetSelected(Storage->GetSelected()->GetNext());
					i++;
				} while (i<Storage->GetIndex());
				treeView1->ExpandAll();
			}
		}
		void processNode(System::Windows::Forms::TreeNode^ tree_node, shape* obj)
		{
			if (obj->GetName() == "group")
			{
				do
				{
					string str = obj->GetObj()->GetName();
					processNode(tree_node->Nodes->Add(%String(str.c_str())), obj->GetObj());
				} while (obj->GetN());
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ÓÚÍ˚Ú¸ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ÒÓı‡ÌËÚ¸ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ‚˚ıÓ‰ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ÒÔ‡‚Í‡ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ÓœÓ„‡ÏÏÂToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ó˜ËÒÚËÚ¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÓÚÍ˚Ú¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÒÓı‡ÌËÚ¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÒÔ‡‚Í‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Ù‡ÈÎToolStripMenuItem,
					this->ÒÔ‡‚Í‡ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1085, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->Ó˜ËÒÚËÚ¸ToolStripMenuItem,
					this->ÓÚÍ˚Ú¸ToolStripMenuItem, this->ÒÓı‡ÌËÚ¸ToolStripMenuItem, this->‚˚ıÓ‰ToolStripMenuItem
			});
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// Ó˜ËÒÚËÚ¸ToolStripMenuItem
			// 
			this->Ó˜ËÒÚËÚ¸ToolStripMenuItem->Name = L"Ó˜ËÒÚËÚ¸ToolStripMenuItem";
			this->Ó˜ËÒÚËÚ¸ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->Ó˜ËÒÚËÚ¸ToolStripMenuItem->Text = L"Œ˜ËÒÚËÚ¸";
			this->Ó˜ËÒÚËÚ¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Ó˜ËÒÚËÚ¸ToolStripMenuItem_Click);
			// 
			// ÓÚÍ˚Ú¸ToolStripMenuItem
			// 
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Name = L"ÓÚÍ˚Ú¸ToolStripMenuItem";
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Text = L"ŒÚÍ˚Ú¸";
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÓÚÍ˚Ú¸ToolStripMenuItem_Click);
			// 
			// ÒÓı‡ÌËÚ¸ToolStripMenuItem
			// 
			this->ÒÓı‡ÌËÚ¸ToolStripMenuItem->Name = L"ÒÓı‡ÌËÚ¸ToolStripMenuItem";
			this->ÒÓı‡ÌËÚ¸ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->ÒÓı‡ÌËÚ¸ToolStripMenuItem->Text = L"—Óı‡ÌËÚ¸";
			this->ÒÓı‡ÌËÚ¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÒÓı‡ÌËÚ¸ToolStripMenuItem_Click);
			// 
			// ‚˚ıÓ‰ToolStripMenuItem
			// 
			this->‚˚ıÓ‰ToolStripMenuItem->Name = L"‚˚ıÓ‰ToolStripMenuItem";
			this->‚˚ıÓ‰ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->‚˚ıÓ‰ToolStripMenuItem->Text = L"¬˚ıÓ‰";
			this->‚˚ıÓ‰ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::‚˚ıÓ‰ToolStripMenuItem_Click);
			// 
			// ÒÔ‡‚Í‡ToolStripMenuItem
			// 
			this->ÒÔ‡‚Í‡ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ÓœÓ„‡ÏÏÂToolStripMenuItem });
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Name = L"ÒÔ‡‚Í‡ToolStripMenuItem";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Text = L"—Ô‡‚Í‡";
			// 
			// ÓœÓ„‡ÏÏÂToolStripMenuItem
			// 
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Name = L"ÓœÓ„‡ÏÏÂToolStripMenuItem";
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Text = L"Œ ÔÓ„‡ÏÏÂ";
			this->ÓœÓ„‡ÏÏÂToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÓœÓ„‡ÏÏÂToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(538, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(438, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 4;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(14, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(574, 453);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(149, 18);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(39, 20);
			this->numericUpDown1->TabIndex = 6;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(11, 18);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(48, 17);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L" Û„";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(10, 39);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(103, 17);
			this->radioButton2->TabIndex = 8;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"ÃÌÓ„ÓÛ„ÓÎ¸ÌËÍ";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(10, 64);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(62, 17);
			this->radioButton3->TabIndex = 9;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"«‚ÂÁ‰‡";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(149, 41);
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(39, 20);
			this->numericUpDown3->TabIndex = 11;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown3_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(194, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"–‡‰ËÛÒ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(194, 43);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L" ÓÎË˜ÂÒÚ‚Ó Â·Â";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown2->Location = System::Drawing::Point(149, 64);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 21, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(39, 20);
			this->numericUpDown2->TabIndex = 15;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(194, 66);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L" ÓÎË˜ÂÒÚ‚Ó ‚Â¯ËÌ";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->numericUpDown3);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Location = System::Drawing::Point(756, 47);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(317, 101);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"œ‡‡ÏÂÚ˚ ÒÓÁ‰‡ÌËˇ ˝ÎÂÏÂÌÚ‡";
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(875, 172);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->numericUpDown4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(34, 20);
			this->numericUpDown4->TabIndex = 19;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(794, 172);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"¬ÎÂ‚Ó";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(915, 172);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 21;
			this->button2->Text = L"¬Ô‡‚Ó";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(794, 156);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"œÓ‚ÓÓÚ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(794, 207);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 13);
			this->label7->TabIndex = 23;
			this->label7->Text = L"œÂÂÏÂ˘ÂÌËÂ";
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(876, 261);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numericUpDown5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(34, 20);
			this->numericUpDown5->TabIndex = 24;
			this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(853, 232);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 25;
			this->button3->Text = L"¬‚Âı";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(917, 261);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 26;
			this->button4->Text = L"¬Ô‡‚Ó";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(794, 261);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 27;
			this->button5->Text = L"¬ÎÂ‚Ó";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(853, 287);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 28;
			this->button6->Text = L"¬ÌËÁ";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(599, 362);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(85, 23);
			this->button7->TabIndex = 29;
			this->button7->Text = L"”‰‡ÎËÚ¸";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(796, 322);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 13);
			this->label8->TabIndex = 30;
			this->label8->Text = L"÷‚ÂÚ";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(799, 338);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(65, 17);
			this->radioButton4->TabIndex = 31;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"◊ÂÌ˚È";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(799, 361);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(67, 17);
			this->radioButton5->TabIndex = 32;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"∆ÂÎÚ˚È";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(799, 384);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(70, 17);
			this->radioButton6->TabIndex = 33;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"«ÂÎÂÌ˚È";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton6_CheckedChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(902, 322);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(99, 13);
			this->label9->TabIndex = 34;
			this->label9->Text = L"»ÁÏÂÌËÚ¸ ‡ÁÏÂ";
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Location = System::Drawing::Point(934, 347);
			this->numericUpDown6->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(34, 20);
			this->numericUpDown6->TabIndex = 35;
			this->numericUpDown6->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(901, 344);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(27, 23);
			this->button8->TabIndex = 36;
			this->button8->Text = L"-";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(974, 344);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(27, 23);
			this->button9->TabIndex = 37;
			this->button9->Text = L"+";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(599, 413);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(85, 23);
			this->button10->TabIndex = 38;
			this->button10->Text = L"Œ·˙Â‰ËÌËÚ¸";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(599, 441);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(85, 23);
			this->button11->TabIndex = 40;
			this->button11->Text = L"ŒÚÏÂÌ‡";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(599, 387);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(85, 23);
			this->button12->TabIndex = 41;
			this->button12->Text = L"¬˚·‡Ú¸";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(599, 42);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(151, 314);
			this->treeView1->TabIndex = 42;
			this->treeView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::treeView1_KeyDown);
			this->treeView1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::treeView1_MouseDown);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1085, 522);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->numericUpDown6);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->radioButton6);
			this->Controls->Add(this->radioButton5);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->numericUpDown5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"√‡ÙË˜ÂÒÍËÈ Â‰‡ÍÚÓ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ÓœÓ„‡ÏÏÂToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("–‡·ÓÚÛ ‚˚ÔÓÎÌËÎË: ≈ÎËÒÂÂ‚ Ã‡ÍÒËÏ Ë ¡ÛÍ‡ÚËÌ‡ ¬ËÍÚÓËˇ");
	}
	
private: System::Void ‚˚ıÓ‰ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

private: System::Void Ó˜ËÒÚËÚ¸ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Storage->delet_all();
	Graphics^ formGraphics;
	formGraphics = this->CreateGraphics();
	formGraphics->Clear(Color::FromArgb(240,240,240));
	Paint();
}

private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
	private: System::Void ÒÓı‡ÌËÚ¸ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "txt files(*.txt) | *.txt";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (saveFileDialog1->FileName != "") {
				string file = and_SysStringToChar(saveFileDialog1->FileName);
				Storage->save_file(file);
			}
		}
	}
private: System::Void ÓÚÍ˚Ú¸ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog  ^openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "txt files(*.txt) | *.txt";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (openFileDialog1->FileName != "") {
				string file = and_SysStringToChar(openFileDialog1->FileName);
				Storage->load_file(file);
			}
		}
		Paint();
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int a = e->X;
	int b = e->Y;
	if ((e->Button == System::Windows::Forms::MouseButtons::Left)&&(a+r+2<pictureBox1->Size.Width)&& (a - r - 2>0)&& (b + r + 2<pictureBox1->Size.Height)&& (b - r - 2>0)) {
		if (type == 1)
		{			
			Storage->AddCircle(a, b, r);
			Paint();
		}
		if (type == 2)
		{

			Storage->AddPolygon(a, b,r,k);
			Paint();
		}
		if (type == 3)
		{
			Storage->AddStar(a, b, r, k2);
			Paint();
		}
		R->Delete();
	}
}
		 
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	r =  (int)numericUpDown1->Value;
}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 1;
	numericUpDown2->Enabled = false;
	numericUpDown3->Enabled = false;
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 2;
	numericUpDown3->Enabled = true;
	numericUpDown2->Enabled = false;
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 3;
	numericUpDown2->Enabled = true;
	numericUpDown3->Enabled = false;
}
private: System::Void numericUpDown3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	k = (int)numericUpDown3->Value;
}
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	k2 = (int)numericUpDown2->Value;
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (si < 0) button7->Enabled = false;
	else
	{
		button7->Enabled = true;
		if (Storage->GetIndex() != 0)
		{
			int i = 0;
			Storage->SetSelected(Storage->GetFirst());
			do {
				if (i == si)
				{
					if (Storage->GetSelected()->GetColor() == 1) radioButton4->Checked = true;
					else if (Storage->GetSelected()->GetColor() == 2) radioButton5->Checked = true;
					else radioButton6->Checked = true;
					break;
				}
				Storage->SetSelected(Storage->GetSelected()->GetNext());
				i++;
			} while (Storage->GetSelected() != 0);
		}
		if (ob != 0)
		{
			ob = 0;

		}
	}
	Paint();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int j;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				R->ChangeAngle(Storage->GetSelected(),-1* (int)numericUpDown4->Value);
				//Storage->GetSelected()->ChangeAngle(-1 * (int)numericUpDown4->Value);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int j;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				R->ChangeAngle(Storage->GetSelected(), (int)numericUpDown4->Value);
				//Storage->GetSelected()->ChangeAngle((int)numericUpDown4->Value);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int j;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if ((i == si) && ((Storage->GetSelected()->GetY() - Storage->GetSelected()->GetRadius()- numericUpDown5->Value>0)))
			{
				R->ChangeY(Storage->GetSelected(), -1 * (int)numericUpDown5->Value);
				//Storage->GetSelected()->ChangeY(-1 * (int)numericUpDown5->Value);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int j;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if ((i == si) && ((Storage->GetSelected()->GetY() + Storage->GetSelected()->GetRadius() + 2+ numericUpDown5->Value<pictureBox1->Size.Height)))
			{
				R->ChangeY(Storage->GetSelected(),(int)numericUpDown5->Value);
				//Storage->GetSelected()->ChangeY((int)numericUpDown5->Value);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int j;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if ((i == si) && ((Storage->GetSelected()->GetX() - Storage->GetSelected()->GetRadius()- numericUpDown5->Value>0)))
			{
				R->ChangeX(Storage->GetSelected(), -1 * (int)numericUpDown5->Value);
				//Storage->GetSelected()->ChangeX(-1 * (int)numericUpDown5->Value);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int j;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if ((i == si)&&((Storage->GetSelected()->GetX() + Storage->GetSelected()->GetRadius()+2+numericUpDown5->Value<pictureBox1->Size.Width)))
			{
				R->ChangeX(Storage->GetSelected(), (int)numericUpDown5->Value);
				//Storage->GetSelected()->ChangeX((int)numericUpDown5->Value);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				Storage->DeleteItem(Storage->GetSelected());
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				Storage->GetSelected()->SetColor(1);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				Storage->GetSelected()->SetColor(2);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				Storage->GetSelected()->SetColor(3);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int a;
		a = (int)numericUpDown6->Value;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				R->ChangeRad(Storage->GetSelected(), -a);
				//Storage->GetSelected()->ChangeRadius( - a);
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int a;
		a = (int)numericUpDown6->Value;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				if ((Storage->GetSelected()->GetX() - Storage->GetSelected()->GetRadius() - 2 - a > 0) && (Storage->GetSelected()->GetX() + Storage->GetSelected()->GetRadius() + 2 + a < pictureBox1->Size.Width) && (Storage->GetSelected()->GetY() - Storage->GetSelected()->GetRadius() - 2 - a > 0) && (Storage->GetSelected()->GetY() + Storage->GetSelected()->GetRadius() + 2 + a< pictureBox1->Size.Height))
					//Storage->GetSelected()->ChangeRadius(a);
					R->ChangeRad(Storage->GetSelected(), a);
				else if (Storage->GetSelected()->GetName() == "group")
				{
					R->ChangeRad(Storage->GetSelected(), a);
					//Storage->GetSelected()->ChangeRadius(a);
				}
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}


private: System::Void listBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {

	if ((Storage->GetIndex() != 0)&&(met==1))
	{
		int i = 0;
		int k = 0;
		shape* s;
		Group* tmp = new Group();
		Storage->SetSelected(Storage->GetFirst());
		do {
			s = Storage->GetSelected()->GetNext();
			if (Storage->GetSelected()->GetisSelected())
			{
				tmp->Add(Storage->GetSelected());
				Storage->Delet(Storage->GetSelected());
				k++;
			}
			s = Storage->GetSelected()->GetNext();
			Storage->SetSelected(s);
			i++;
		} while (Storage->GetSelected() != 0);
		Storage->AddItem(tmp);

	}
	met = 0;
	Paint();
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	R->Undo();
	Paint();
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	met = 1;
	if (Storage->GetIndex() != 0)
	{
		int i = 0;
		int a;
		a = (int)numericUpDown6->Value;
		Storage->SetSelected(Storage->GetFirst());
		do {
			if (i == si)
			{
				Storage->GetSelected()->SetisSelected();
				break;
			}
			Storage->SetSelected(Storage->GetSelected()->GetNext());
			i++;
		} while (Storage->GetSelected() != 0);
	}
	Paint();
}
private: System::Void treeView1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	TreeNode^ node;
	if (treeView1->GetNodeAt(e->X, e->Y))
	{
		node = treeView1->GetNodeAt(e->X, e->Y);
		si= node->Index;
	}
	Paint();
}
private: System::Void treeView1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::NumPad4)  button5_Click(button5, e);
	if (e->KeyCode == Keys::NumPad6)  button4_Click(button4, e);
	if (e->KeyCode == Keys::NumPad8)  button3_Click(button3, e);
	if (e->KeyCode == Keys::NumPad2)  button6_Click(button6, e);
	if (e->KeyCode == Keys::NumPad7)  button1_Click(button1, e);
	if (e->KeyCode == Keys::NumPad9)  button2_Click(button2, e);
	if (e->KeyCode == Keys::OemMinus)  button8_Click(button8, e);
	if (e->KeyCode == Keys::Oemplus)  button9_Click(button9, e);
}
};
}






