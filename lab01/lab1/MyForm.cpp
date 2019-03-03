#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	lab1::MyForm form;
	//lab1::Table table;
	Application::Run(%form);

}