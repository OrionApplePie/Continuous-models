#pragma once

namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FChart2
	/// </summary>
	public ref class FChart2 : public System::Windows::Forms::Form
	{
	public:
		double * v;
		double * s;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	public:
		int n;
		double dt;
		//
		FChart2(void)
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
		~FChart2()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Red;
			series1->LabelBorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			series1->Legend = L"Legend1";
			series1->LegendText = L"Высота";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(884, 562);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// FChart2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 562);
			this->Controls->Add(this->chart1);
			this->Name = L"FChart2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ВЫСОТА";
			this->Load += gcnew System::EventHandler(this, &FChart2::FChart2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FChart2_Load(System::Object^  sender, System::EventArgs^  e) {

		//this->chart2->Series["Series1"]->Points->Clear();
		this->chart1->Series["Series1"]->Points->Clear();


		for (int i = 0; i < n; i++)
		{
			this->chart1->Series["Series1"]->Points->AddXY(i*dt, s[i]);
			//this->chart2->Series["Series1"]->Points->AddXY(i*0.1, s[i]);
		}

	}
	};
}
