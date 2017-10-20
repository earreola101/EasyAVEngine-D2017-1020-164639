#pragma once
#include <windows.h>
#include <TChar.h>
#pragma comment(lib, "Ole32.lib")
#include "EasyVideo.h"


namespace EasyVideoCLRForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	HRESULT hr;
	EasyVideo::IEVCamera2 *pCamera;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form

	{
	public:

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			HRESULT hr;
			//hr=::CoInitialize(0); 
			//TRACE(_T("\n0x%X"),hr); 
			if(FAILED(hr))
			{

			}
			
			hr=CoCreateInstance(CLSID_EasyVideo,NULL,CLSCTX_INPROC_SERVER,EasyVideo::IID_IEVCamera2,reinterpret_cast<void**> (&pCamera));
			if(pCamera==NULL) 
			{
				return ;
			} 
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			
			
				 hr=pCamera->PreviewStop();

				 // disable bayer mode
				 EasyVideo::IEVBayer *pEVB;
				 pCamera->QueryInterface( EasyVideo::IID_IEVBayer,reinterpret_cast<void**> (&pEVB));
				 bool bEnableBayer;
				 int BBP,BMode;
				 pEVB->GetBayer(bEnableBayer,BBP,BMode);// get device bayer mode
				 pEVB->SetBayer(false,BBP,BMode);// enable bayer mode.
				 pEVB->Release();

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button5;

	

	private: 

	private: System::ComponentModel::IContainer^  components;
	protected: 

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(422, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start Preview";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(10, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(407, 375);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(422, 343);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 42);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Stop Preview";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::PreviewColor_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(422, 300);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(128, 36);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Save BMP in Application Folder";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::SaveVideoFrame_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(422, 60);
			this->button4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(128, 37);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Start Preview Bayer";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::PreviewBayer_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(425, 105);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(422, 149);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(126, 33);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Capture Pin Page";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(559, 396);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"EasyVideo Bayer CLR WFA Ver 1.00";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 hr=pCamera->PreviewWindowSet((HWND)pictureBox1->Handle.ToInt32() );
				 hr=pCamera->PreviewStart(); 
			 }
	private: System::Void PreviewColor_Click(System::Object^  sender, System::EventArgs^  e) {
				 hr=pCamera->PreviewStop();

				 // disable bayer mode
				 EasyVideo::IEVBayer *pEVB;
				 pCamera->QueryInterface( EasyVideo::IID_IEVBayer,reinterpret_cast<void**> (&pEVB));
				 bool bEnableBayer;
				 int BBP,BMode;
				 pEVB->GetBayer(bEnableBayer,BBP,BMode);// get device bayer mode
				 pEVB->SetBayer(false,BBP,BMode);// enable bayer mode.
				 pEVB->Release();

			 }
	private: System::Void SaveVideoFrame_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(pCamera->IsPreviewing())
					 hr=pCamera->VideoFrameSave(EasyVideo::FrameBeforeRender,_T(""));
			 }
	private: System::Void PreviewBayer_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(pCamera==NULL)	return ;

				 EasyVideo::IEVBayer *pEVB;
				 pCamera->QueryInterface( EasyVideo::IID_IEVBayer,reinterpret_cast<void**> (&pEVB));
				 bool bEnableBayer;
				 int BBP,BMode;
				 pEVB->GetBayer(bEnableBayer,BBP,BMode);// get device bayer mode
				 pEVB->SetBayer(true,BBP,BMode);// enable bayer mode.
				 pEVB->Release();

				 //hr=pCamera->FormatSet(EasyVideo::MEDIASUBTYPE_YUY2,2592,1944);
				 hr=pCamera->PreviewWindowSet((HWND)pictureBox1->Handle.ToInt32() );
				 hr=pCamera->PreviewStart();
				 /*
				 Sleep(5000);// wait for the device's FW ready and stable

				 if(pCamera->IsPreviewing())
				 hr=pCamera->VideoFrameSave(EasyVideo::FrameBeforeRender,_T(""));
				 hr=pCamera->PreviewStop();
				 */


			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				// if(pCamera->IsPreviewing())
				 {
				 double fs;
				  if (pCamera!=NULL)
				 pCamera->FrameRateGet(fs);
				 System::String ^str;
				 
				 this->label1->Text=str->Format ("Frame Rate={0:F2} F/Sec", fs);

				 this->label1->Update();  
				// this->label1->Refresh();  
				 }
				

			 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

    
			 pCamera->OpenPropertyPage(0,NULL);

		 }
};
}

