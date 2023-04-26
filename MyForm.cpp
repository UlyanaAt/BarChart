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

    float chi = 0;

    for (int i = 1; i < 6; i++)
    {
        chi = chi + statistics[i] * statistics[i] / (numberOfTrials*prob[i-1]);
    }
    chi = chi - numberOfTrials;

    if (chi > 9.488)
    {
        form2->chi->Text = "Chi-squared test: " + chi.ToString() + " > 9.488 is true";
    }
    else
    {
        form2->chi->Text = "Chi-squared test: " + chi.ToString() + " > 9.488 is false";
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

    float Ex = 0;
    float Dx = 0;

    for (int i = 0; i < 5; i++)
    {
        Ex = Ex + prob[i] * (i + 1);
        Dx = Dx + prob[i] * (i + 1) * (i + 1);
    }
    Dx = Dx - Ex * Ex;

    float empEx = 0;
    float empDx = 0;

    for (int i = 1; i < 6; i++)
    {
        empEx = empEx + statistics[i] * i;
        empDx = empDx + statistics[i] * i*i;
    }
    empDx = empDx - empEx * empEx;
    
    float errorE = 0;
    float errorD = 0;

    errorE = abs(empEx - Ex)/abs(Ex)*100;
    errorD = abs(empDx - Dx)/abs(Dx)*100;

    form2->aver->Text = "Average: " + empEx.ToString() + " (error: " + errorE.ToString() + "%)";
    form2->varien->Text = "Variance: " + empDx.ToString() + " (error: " + errorD.ToString() + "%)";

}
