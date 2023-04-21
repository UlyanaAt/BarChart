#include "MyForm.h"
using namespace BarChart;
using namespace System::Windows::Forms;
#include <ctime>
#include <iostream>
#include <math.h>    
#include "Suplimental.h"

// Application entry point
[STAThreadAttribute]
void main(array<String^>^ args) {
    srand(time(0));
    // Initial Application Parameters:
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    BarChart::MyForm form;
    Application::Run(% form);
}

System::Void BarChart::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyForm1^ form2 = gcnew MyForm1();
    form2->Show();

    float prob[5] = { 0 };
    prob[0] = (float)numeric1->Value;
    prob[1] = (float)numeric2->Value;
    prob[2] = (float)numeric3->Value;
    prob[3] = (float)numeric4->Value;
    prob[4] = 1 - prob[0] - prob[1] - prob[2] - prob[3];

    

    int numberOfTrials = (int)numericUpDown1->Value;
    float statistics[6] = {0};

    for (int j = 0; j < numberOfTrials; j++)
    {
        int i = 0;
        int k = 0;
        float RandNumb = Suplimental::RandZeroToOne();
        while (RandNumb > 0)
        {
            RandNumb = RandNumb - prob[i];
            k++;
            i++;
        }

        statistics[k]++;
    }

    for (int i = 1; i < 6; i++)
    {
		statistics[i] = statistics[i] / numberOfTrials;
	}

    form2->chart1->Series["Series1"]->Points->Clear();

    for (int i = 1; i < 6; i++)
    {
        form2->chart1->Series["Series1"]->Points->AddXY(i, statistics[i]);
	}
     
}
