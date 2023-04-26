#pragma once

namespace BarChart {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	public: System::Windows::Forms::Label^ chi;
	public:

	public: System::Windows::Forms::Label^ varien;

	public: System::Windows::Forms::Label^ aver;


	public:
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->chi = (gcnew System::Windows::Forms::Label());
			this->varien = (gcnew System::Windows::Forms::Label());
			this->aver = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->IsValueShownAsLabel = true;
			series2->LabelFormat = L"{0:0.000}";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(597, 510);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chi);
			this->groupBox1->Controls->Add(this->varien);
			this->groupBox1->Controls->Add(this->aver);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 13.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 528);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(597, 159);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Measurements";
			// 
			// chi
			// 
			this->chi->AutoSize = true;
			this->chi->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chi->Location = System::Drawing::Point(6, 109);
			this->chi->Name = L"chi";
			this->chi->Size = System::Drawing::Size(115, 21);
			this->chi->TabIndex = 6;
			this->chi->Text = L"Chi-squared:";
			// 
			// varien
			// 
			this->varien->AutoSize = true;
			this->varien->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->varien->Location = System::Drawing::Point(6, 60);
			this->varien->Name = L"varien";
			this->varien->Size = System::Drawing::Size(94, 21);
			this->varien->TabIndex = 5;
			this->varien->Text = L"Variance: ";
			// 
			// aver
			// 
			this->aver->AutoSize = true;
			this->aver->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->aver->Location = System::Drawing::Point(6, 28);
			this->aver->Name = L"aver";
			this->aver->Size = System::Drawing::Size(89, 21);
			this->aver->TabIndex = 4;
			this->aver->Text = L"Average: ";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 691);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

};
}
