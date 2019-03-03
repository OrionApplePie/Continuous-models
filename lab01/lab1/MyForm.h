#include "rk.h"
#include "FTable.h"
#include "FChart1.h"
#include "FChart2.h"
#include "Compare.h" 
#pragma once

namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		double* velo_rk;
		double* way_rk;
		double* velo_e;
		int num;
		double det;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  tb_out;
	private: System::Windows::Forms::Button^  button9;

	public:
		double* way_e;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  решениеToolStripMenuItem;




	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb6;
	private: System::Windows::Forms::TextBox^  tb5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tb4;
	private: System::Windows::Forms::TextBox^  tb7;
	private: System::Windows::Forms::TextBox^  tb3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tb2;
	private: System::Windows::Forms::TextBox^  tb1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->решениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb6 = (gcnew System::Windows::Forms::TextBox());
			this->tb5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tb4 = (gcnew System::Windows::Forms::TextBox());
			this->tb7 = (gcnew System::Windows::Forms::TextBox());
			this->tb3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tb2 = (gcnew System::Windows::Forms::TextBox());
			this->tb1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tb_out = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->файлToolStripMenuItem,
					this->решениеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1220, 24);
			this->menuStrip1->TabIndex = 20;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// решениеToolStripMenuItem
			// 
			this->решениеToolStripMenuItem->Name = L"решениеToolStripMenuItem";
			this->решениеToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->решениеToolStripMenuItem->Text = L"Решение";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(497, 243);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(685, 308);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 22;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(836, 449);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(62, 91);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 23;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(40, 136);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"площадь сечения";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(16, 166);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(160, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"сила тяги двигателя";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(51, 109);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"расход топлива";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(100, 507);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(185, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"решение системы";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(50, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"конечная масса";
			// 
			// tb6
			// 
			this->tb6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb6->Location = System::Drawing::Point(207, 205);
			this->tb6->Name = L"tb6";
			this->tb6->Size = System::Drawing::Size(108, 22);
			this->tb6->TabIndex = 12;
			this->tb6->Text = L"0,45";
			// 
			// tb5
			// 
			this->tb5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb5->Location = System::Drawing::Point(207, 169);
			this->tb5->Name = L"tb5";
			this->tb5->Size = System::Drawing::Size(108, 22);
			this->tb5->TabIndex = 6;
			this->tb5->Text = L"200000000";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(36, 195);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(140, 32);
			this->label6->TabIndex = 13;
			this->label6->Text = L"коэфф. лобового \r\nсопротивления c";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// tb4
			// 
			this->tb4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb4->Location = System::Drawing::Point(207, 139);
			this->tb4->Name = L"tb4";
			this->tb4->Size = System::Drawing::Size(108, 22);
			this->tb4->TabIndex = 5;
			this->tb4->Text = L"20";
			// 
			// tb7
			// 
			this->tb7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb7->Location = System::Drawing::Point(207, 246);
			this->tb7->Name = L"tb7";
			this->tb7->Size = System::Drawing::Size(108, 22);
			this->tb7->TabIndex = 14;
			this->tb7->Text = L"0,1";
			// 
			// tb3
			// 
			this->tb3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb3->Location = System::Drawing::Point(207, 112);
			this->tb3->Name = L"tb3";
			this->tb3->Size = System::Drawing::Size(108, 22);
			this->tb3->TabIndex = 4;
			this->tb3->Text = L"100000";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(155, 252);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 16);
			this->label7->TabIndex = 15;
			this->label7->Text = L"dt";
			// 
			// tb2
			// 
			this->tb2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb2->Location = System::Drawing::Point(207, 77);
			this->tb2->Name = L"tb2";
			this->tb2->Size = System::Drawing::Size(108, 22);
			this->tb2->TabIndex = 3;
			this->tb2->Text = L"500000";
			// 
			// tb1
			// 
			this->tb1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb1->Location = System::Drawing::Point(207, 32);
			this->tb1->Name = L"tb1";
			this->tb1->Size = System::Drawing::Size(108, 22);
			this->tb1->TabIndex = 2;
			this->tb1->Text = L"20000000";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(363, 478);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"начальная масса m0";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(210, 411);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(185, 43);
			this->button3->TabIndex = 16;
			this->button3->Text = L"table";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(19, 411);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(185, 43);
			this->button4->TabIndex = 17;
			this->button4->Text = L"graphics";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(363, 507);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 18;
			this->button5->Text = L"go";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(321, 35);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(23, 16);
			this->label8->TabIndex = 19;
			this->label8->Text = L"кг";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(321, 79);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(23, 16);
			this->label9->TabIndex = 20;
			this->label9->Text = L"кг";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(321, 113);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(53, 16);
			this->label10->TabIndex = 21;
			this->label10->Text = L"кг\\сек";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(321, 139);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(43, 16);
			this->label11->TabIndex = 22;
			this->label11->Text = L"кв. м";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(321, 172);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(19, 16);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Н";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->tb1);
			this->groupBox1->Controls->Add(this->tb2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->tb3);
			this->groupBox1->Controls->Add(this->tb7);
			this->groupBox1->Controls->Add(this->tb4);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tb5);
			this->groupBox1->Controls->Add(this->tb6);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(12, 38);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(444, 536);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ДАННЫЕ";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(210, 469);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 29;
			this->button9->Text = L"ok\'!";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(16, 507);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 28;
			this->button8->Text = L"comp";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(19, 335);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(185, 60);
			this->button7->TabIndex = 27;
			this->button7->Text = L"решение в безразмерных\r\nРунге-Кутта\r\n";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(210, 335);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(185, 60);
			this->button6->TabIndex = 26;
			this->button6->Text = L"решение в безразмерных";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(321, 249);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(37, 16);
			this->label14->TabIndex = 25;
			this->label14->Text = L"сек.";
			// 
			// tb_out
			// 
			this->tb_out->Location = System::Drawing::Point(497, 47);
			this->tb_out->Multiline = true;
			this->tb_out->Name = L"tb_out";
			this->tb_out->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tb_out->Size = System::Drawing::Size(666, 152);
			this->tb_out->TabIndex = 24;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1220, 628);
			this->Controls->Add(this->tb_out);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MyForm";
			this->Text = L"Модель полета ракеты";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// объект с методами решеия сис. ду
	rk myrk;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//тест

		try
		{
			if (tb1->Text == "")
			{
				throw 1;
			}
			int c = Convert::ToInt32(tb1->Text);
			int t = myrk.cool(c);
			label1->Text = Convert::ToString(t);
		}
		catch(int i)
		{
			label1->Text = "enter number";
		}

		double *a;
		int c=0;
		myrk.foo(12, a, c);
		for (int i = 0; i < c;i++)
		this->Text += Convert::ToString(a[i])+" " ;


	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	// берем данные с контролов и сохраняем в поля объекта
	//нач. масса, кон. масса, 
	//m0 - нач. масса
	//m_fin  - кон. масса
	//alpha - расход топлива
	//sq - площадь поперечного сечения ракеты
	//c - коэфф. сопротивл.
	//f_traction -  тяга
	//dt - шаг по времени

	double m0, m_fin, alpha, sq, c, f_traction, dt;
	m0 = Convert::ToDouble(tb1->Text);
	m_fin = Convert::ToDouble(tb2->Text);
	alpha = Convert::ToDouble(tb3->Text);
	sq = Convert::ToDouble(tb4->Text);
	c = Convert::ToDouble(tb6->Text);
	f_traction = Convert::ToDouble(tb5->Text);
	dt = Convert::ToDouble(tb7->Text);
	myrk.setdata(m0, m_fin, alpha, sq, c, f_traction, dt);
	//
//Решение системы
	double* v;
	double* s;
	int n = 0;
	// Методом Эйлера - без контроля погрешности!!!
	bool hi = myrk.euler(42, 42, v, s, n);
	// сохранение результатов в поля объекта
	myrk.v = v;
	myrk.s = s;
	myrk.n = n;
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	//
	FTable ^f2 = gcnew FTable();
	f2->v = myrk.v;
	f2->s = myrk.s;
	f2->n = myrk.n;
	f2->dt = myrk.dt;
	f2->ShowDialog(); 

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	FChart1 ^c1 = gcnew FChart1();
	FChart2 ^c2 = gcnew FChart2();
	c1->v = myrk.v;
	c2->s = myrk.s;
	c2->n = myrk.n;
	c1->n = myrk.n;
	c1->dt = myrk.dt;
	c2->dt = myrk.dt;
	c1->Show();
	c2->Show();


}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	//
	for (int i = 0; i < 100;i++)
	{
		pictureBox1->Top--;
	}
}

private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	//РУНГЕ-КУТТА!
	// берем данные с контролов и сохраняем в поля объекта
	//нач. масса, кон. масса, 
	//m0 - нач. масса
	//m_fin  - кон. масса
	//alpha - расход топлива
	//sq - площадь поперечного сечения ракеты
	//c - коэфф. сопротивл.
	//f_traction -  тяга
	//dt - шаг по времени

	double m0, m_fin, alpha, sq, c, f_traction, dt;
	m0 = Convert::ToDouble(tb1->Text);
	m_fin = Convert::ToDouble(tb2->Text);
	alpha = Convert::ToDouble(tb3->Text);
	sq = Convert::ToDouble(tb4->Text);
	c = Convert::ToDouble(tb6->Text);
	f_traction = Convert::ToDouble(tb5->Text);
	dt = Convert::ToDouble(tb7->Text);
	myrk.setdata(m0, m_fin, alpha, sq, c, f_traction, dt);
	//
	//Решение системы
	double* v;
	double* s;
	int n = 0;
	// Методом Эйлера - без контроля погрешности!!!
	bool hi = myrk.rungekutta(0.01, v, s, n);
	// сохранение результатов в поля объекта
	velo_rk = v;
	num = n;
	det = dt;
	myrk.v = v;
	myrk.s = s;
	myrk.n = n;
}

public:
		double findmax(double * a, int n)
		{
			double max = 0;
			for (int i = 0; i < n; i++)
			{
				try {
					
					if (a[i] > max) max = a[i];
				}
				catch (int y) { return 0; };
			}
			return max;
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

	
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {

	//test
	// берем данные с контролов и сохраняем в поля объекта
	//нач. масса, кон. масса, 
	//m0 - нач. масса
	//m_fin  - кон. масса
	//alpha - расход топлива
	//sq - площадь поперечного сечения ракеты
	//c - коэфф. сопротивл.
	//f_traction -  тяга
	//dt - шаг по времени
	//
	double m0, m_fin, alpha, sq, c, f_traction, dt;
	m0 = Convert::ToDouble(tb1->Text);
	m_fin = Convert::ToDouble(tb2->Text);
	alpha = Convert::ToDouble(tb3->Text);
	sq = Convert::ToDouble(tb4->Text);
	c = Convert::ToDouble(tb6->Text);
	f_traction = Convert::ToDouble(tb5->Text);
	dt = Convert::ToDouble(tb7->Text);
	myrk.setdata(m0, m_fin, alpha, sq, c, f_traction, dt);
	//
	//Решение системы
	int nnn = 0;
	//double * mass = new double[10];
	//double * force = new double[10];
	//double dm = 100;
	//double df = 100;
	//mass[0] = m0;
	//force[0] = f_traction;
	//int i = 1;
	bool hi = false;
	tb_out->AppendText("start\n");
	tb_out->AppendText("m0:  " + m0.ToString() + " ftr:" + f_traction.ToString() + "\n");
	//tb_out->AppendText("----\n");
	double* v;
	double* s;
		for (int i = 1; i < 7; i++)
		{
			hi = myrk.euler_dim_less(m0, f_traction,v,s, nnn);
			//bool joke = myrk.rungekutta(0.001, v, s, yyy);
			tb_out->AppendText("m0: " + m0.ToString()+"ftr "+f_traction.ToString() + "!!!\n");
			//for (int i = 0; i < nnn; i++) {
			//	myrk.v = v;
			//	myrk.s = s;
			//}
			//myrk.n = nnn;
			delete[] v;
			delete[] s;
		}
		
	
}
};
}
