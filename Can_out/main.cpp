#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/tglbtn.h>
#include <wx/combobox.h>
#include <fstream>
//#include "commands.h"

int COM_1 = 101;
int COM_2 = 102;
int COM_3 = 103;
int COM_4 = 104;
int COM_5 = 105;
int COM_6 = 106;
int COM_7 = 107;
int COM_8 = 108;
int COM_9 = 109;
int ID_baud_9600 = 113;
int ID_baud_14400 = 114;
int ID_baud_19200 = 115;
int ID_baud_38400 = 116;
int ID_baud_57600 = 117;
int ID_baud_115200 = 118;
int ID_baud_128000 = 119;
int ID_baud_256000 = 120;
int ID_baud_custom = 121;
int ID_byte_size_5 = 122;
int ID_byte_size_6 = 123;
int ID_byte_size_7 = 124;
int ID_byte_size_8 = 125;
int ID_stopbit_1 = 126;
int ID_stopbit_1_5 = 127;
int ID_stopbit_2 = 128;
int ID_parity_no = 129;
int ID_parity_odd = 130;
int ID_parity_even = 131;
int ID_parity_mark = 132;
int ID_parity_space = 133;
int ID_read_interval = 134;
int ID_read_multiplier = 135;
int ID_read_constant = 136;
int ID_write_multiplier = 137;
int ID_write_constant = 138;
int ID_timeouts_show = 139;
int ID_settings_save = 140;
int ID_settings_load = 141;
int ID_settings_default = 142;
int ID_baud_921600 = 149;
int ID_add_to_message = 153;
int ID_add_to_queue = 154;
int ID_send = 155;
int ID_queue_clean = 156;
int ID_message_clean = 157;

const int grid_rows = 10;

const wxString standart_ID = L"Стандартное";
const wxString extended_ID = L"Расширенное";

const wxString no_data = L"Без данных";
const wxString int_1_byte = L"Целое 1 байт";
const wxString int_2_byte = L"Целое 2 байта";
const wxString int_4_byte = L"Целое 4 байта";
const wxString int_8_byte = L"Целое 8 байт";
const wxString float_4_byte = L"С плав. зпт. 4 байт";
const wxString float_8_byte = L"С плав. зпт. 8 байт";
const wxString bit_field = L"Битовое поле";

const wxString data_dec = L"dec";
const wxString data_hex = L"hex";

const wxString data_order_forward = L"От старшего к младшему";
const wxString data_order_backward = L"От младшего к старшему";

class MyApp: public wxApp
{
public:
	virtual bool OnInit();
};

class SubMenu: public wxFrame
{
public:
	SubMenu(const wxString& title);
	void OnQuit(wxCommandEvent& event);
	void set_port_1(wxCommandEvent& event);
	void set_port_2(wxCommandEvent& event);
	void set_port_3(wxCommandEvent& event);
	void set_port_4(wxCommandEvent& event);
	void set_port_5(wxCommandEvent& event);
	void set_port_6(wxCommandEvent& event);
	void set_port_7(wxCommandEvent& event);
	void set_port_8(wxCommandEvent& event);
	void set_port_9(wxCommandEvent& event);
	
	void set_baud_9600(wxCommandEvent& event);
	void set_baud_14400(wxCommandEvent& event);
	void set_baud_19200(wxCommandEvent& event);
	void set_baud_38400(wxCommandEvent& event);
	void set_baud_57600(wxCommandEvent& event);
	void set_baud_115200(wxCommandEvent& event);
	void set_baud_128000(wxCommandEvent& event);
	void set_baud_256000(wxCommandEvent& event);
	void set_baud_921600(wxCommandEvent& event);
	void set_baud_custom(wxCommandEvent& event);
	
	void set_byte_size_5(wxCommandEvent& event);
	void set_byte_size_6(wxCommandEvent& event);
	void set_byte_size_7(wxCommandEvent& event);
	void set_byte_size_8(wxCommandEvent& event);
	
	void set_stopbit_1(wxCommandEvent& event);
	void set_stopbit_1_5(wxCommandEvent& event);
	void set_stopbit_2(wxCommandEvent& event);
	
	void set_parity_no(wxCommandEvent& event);
	void set_parity_odd(wxCommandEvent& event);
	void set_parity_even(wxCommandEvent& event);
	void set_parity_mark(wxCommandEvent& event);
	void set_parity_space(wxCommandEvent& event);
	
	void set_read_interval(wxCommandEvent& event);
	void set_read_multiplier(wxCommandEvent& event);
	void set_read_constant(wxCommandEvent& event);
	void set_write_multiplier(wxCommandEvent& event);
	void set_write_constant(wxCommandEvent& event);
	void timeouts_show(wxCommandEvent& event);
	void timeouts_show();
	
	void settings_save(wxCommandEvent& event);
	void settings_load(wxCommandEvent& event);
	void settings_load();
	void settings_default(wxCommandEvent& event);
	void settings_default();
	
	void set_port();
	
	void on_add_to_message(wxCommandEvent& event);
	void on_add_to_queue(wxCommandEvent& event);
	void on_send(wxCommandEvent& event);
	void on_queue_clean(wxCommandEvent& event);
	void on_message_clean(wxCommandEvent& event);
	
	void show_message(const wxString &message);
	void on_close(wxCloseEvent& event);
	
	wxStaticText *st1;
	wxStaticText *st2;
	wxTextCtrl *tc1;
	wxButton *button_add_to_message;
	wxButton *button_add_to_queue;
	wxButton *button_send;
	wxButton *button_queue_clean;
	wxButton *button_message_clean;
	wxGrid *grid_temp;
	wxGrid *grid_queue;
	wxComboBox* combo_ID_type;
	wxComboBox* combo_data_type;
	wxComboBox* combo_data_in_format;
	wxComboBox* combo_data_order;
	wxCheckBox* chbox_bit_7;
	wxCheckBox* chbox_bit_6;
	wxCheckBox* chbox_bit_5;
	wxCheckBox* chbox_bit_4;
	wxCheckBox* chbox_bit_3;
	wxCheckBox* chbox_bit_2;
	wxCheckBox* chbox_bit_1;
	wxCheckBox* chbox_bit_0;
	wxTextCtrl *tc_ID;
	wxTextCtrl *tc_data;
	int set_port_number;
	int set_baud_rate;
	int set_byte_size;
	int set_stopbit;
	int set_parity;
	int read_interval;
	int read_multiplier;
	int read_constant;
	int write_multiplier;
	int write_constant;
	HANDLE hSerial;
	bool com_port_ready;
	bool program_start;
	//int grid_rows;
	int data_bytes_used;
	//bool ID_extended;
	//bool order_backward;
	bool ID_error;
	//bool add_to_queue_enable;
	//uint64_t data_collected;
	uint8_t data_buf[8];
	char data_temp[17];
	std::string data_string[grid_rows];
	//uint64_t data_temp;
	//uint64_t data[grid_rows];
	char ID_temp[9];
	std::string ID_string[grid_rows];
	/*unsigned int ID_temp;
	unsigned int ID[grid_rows];*/
	int messages;
	
	std::ifstream inFile;
	std::ofstream outFile;
};

DECLARE_APP(MyApp);
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SubMenu *simple = new SubMenu(wxT("Simple"));
	simple->Show(true);
	return true;
}

SubMenu::SubMenu(const wxString& title): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(910, 920))
{
	program_start = true;
	data_bytes_used = 0;
	//ID_extended = false;
	//order_backward = false;
	ID_error = true;
	//add_to_queue_enable = false;
	//ID_temp = 0;
	messages = 0;
	
	//data_collected = 0;
	for (int i = 0; i < 8; i++)
		data_buf[i] = 0;
		
	for (int i = 0; i < 16; i++)
		data_temp[i] = '0';
	data_temp[16] = '\0';
	
	for (int i = 0; i < 8; i++)
		ID_temp[i] = '0';
	ID_temp[8] = '\0';
	 
	wxMenuBar *menubar = new wxMenuBar;
	wxMenu *file = new wxMenu;
	wxMenu *settings = new wxMenu;
	wxMenu *port_number = new wxMenu;
	wxMenu *baud_rate = new wxMenu;
	wxMenu *byte_size = new wxMenu;
	wxMenu *stopbit = new wxMenu;
	wxMenu *parity = new wxMenu;
	wxMenu *timeout = new wxMenu;
	
	port_number->Append(COM_1, wxT("Com 1"));
	port_number->Append(COM_2, wxT("Com 2"));
	port_number->Append(COM_3, wxT("Com 3"));
	port_number->Append(COM_4, wxT("Com 4"));
	port_number->Append(COM_5, wxT("Com 5"));
	port_number->Append(COM_6, wxT("Com 6"));
	port_number->Append(COM_7, wxT("Com 7"));
	port_number->Append(COM_8, wxT("Com 8"));
	port_number->Append(COM_9, wxT("Com 9"));
	
	baud_rate->Append(ID_baud_9600, wxT("9600"));
	baud_rate->Append(ID_baud_14400, wxT("14400"));
	baud_rate->Append(ID_baud_19200, wxT("19200"));
	baud_rate->Append(ID_baud_38400, wxT("38400"));
	baud_rate->Append(ID_baud_57600, wxT("57600"));
	baud_rate->Append(ID_baud_115200, wxT("115200"));
	baud_rate->Append(ID_baud_128000, wxT("128000"));
	baud_rate->Append(ID_baud_256000, wxT("256000"));
	baud_rate->Append(ID_baud_921600, wxT("921600"));
	baud_rate->Append(ID_baud_custom, wxT("custom"));
	
	byte_size->Append(ID_byte_size_5, wxT("5"));
	byte_size->Append(ID_byte_size_6, wxT("6"));
	byte_size->Append(ID_byte_size_7, wxT("7"));
	byte_size->Append(ID_byte_size_8, wxT("8"));
	
	stopbit->Append(ID_stopbit_1, wxT("1"));
	stopbit->Append(ID_stopbit_1_5, wxT("1.5"));
	stopbit->Append(ID_stopbit_2, wxT("2"));
	
	parity->Append(ID_parity_no, wxT("No"));
	parity->Append(ID_parity_odd, wxT("Odd"));
	parity->Append(ID_parity_even, wxT("Even"));
	parity->Append(ID_parity_mark, wxT("Mark"));
	parity->Append(ID_parity_space, wxT("Space"));
	
	timeout->Append(ID_read_interval, wxT("Read interval"));
	timeout->Append(ID_read_multiplier, wxT("Read multiplier"));
	timeout->Append(ID_read_constant, wxT("Read constant"));
	timeout->Append(ID_write_multiplier, wxT("Write multiplier"));
	timeout->Append(ID_write_constant, wxT("Write constant"));
	timeout->AppendSeparator();
	timeout->Append(ID_timeouts_show, wxT("Show timeouts"));
	
	settings->AppendSubMenu(port_number, wxT("Port number"));
	settings->AppendSubMenu(baud_rate, wxT("Baud rate"));
	settings->AppendSubMenu(byte_size, wxT("Byte size"));
	settings->AppendSubMenu(stopbit, wxT("Stop bit"));
	settings->AppendSubMenu(parity, wxT("Parity"));
	settings->AppendSeparator();
	settings->AppendSubMenu(timeout,wxT("Timeouts"));
	
	file->Append(ID_settings_save, wxT("Save settings"));
	file->Append(ID_settings_load, wxT("Load settings"));
	file->Append(ID_settings_default, wxT("Default settings"));
	file->AppendSeparator();
	wxMenuItem *quit = new wxMenuItem(file, wxID_EXIT, wxT("&Quit\tCTRL+W"));
	file->Append(quit);
	
	menubar->Append(file, wxT("&File"));
	menubar->Append(settings, wxT("&Settings"));
	SetMenuBar(menubar);
	
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox4_1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox4_2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox4_2_1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox4_3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox5 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox6 = new wxBoxSizer(wxHORIZONTAL);
	
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	st1 = new wxStaticText(panel, wxID_ANY, wxString::Format(wxT("")), wxPoint(-1, -1));
	tc1 = new wxTextCtrl(panel, wxID_ANY);
	
	hbox1->Add(st1, 4, wxLEFT | wxRIGHT | wxEXPAND, 10);
	hbox1->Add(tc1, 1, wxRIGHT | wxALIGN_RIGHT | wxEXPAND, 10);
	vbox->Add(-1, 10);
	vbox->Add(hbox1, 0, wxEXPAND);
	vbox->Add(-1, 10);
	st2 = new wxStaticText(panel, wxID_ANY, wxT(""));
	hbox2->Add(st2, 0, wxLEFT, 10);
	vbox->Add(hbox2, 0);
	
	wxStaticText *st_ID_type = new wxStaticText(panel, wxID_ANY, wxT("Тип сообщения"));
	hbox3->Add(st_ID_type, 0, wxLEFT, 20);
	wxStaticText *st_ID = new wxStaticText(panel, wxID_ANY, wxT("ID (hex)"));
	hbox3->Add(st_ID, 0, wxLEFT, 45);
	vbox->Add(hbox3, 0);
	
	wxArrayString strings_ID_type;
	strings_ID_type.Add(standart_ID);
	strings_ID_type.Add(extended_ID);
	combo_ID_type = new wxComboBox(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150, 30), strings_ID_type, wxCB_DROPDOWN);
	combo_ID_type->SetSelection(0);
	hbox4->Add(combo_ID_type, 0, wxLEFT, 20);
	
	tc_ID = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(120, 30));
	hbox4->Add(tc_ID, 0, wxLEFT, 30);
	
	vbox->Add(hbox4, 0);
	vbox->Add(-1, 20);
	
	wxStaticText *st_data_type = new wxStaticText(panel, wxID_ANY, wxT("Тип данных"));
	hbox4_1->Add(st_data_type, 0, wxLEFT, 20);
	wxStaticText *st_data_in_format = new wxStaticText(panel, wxID_ANY, wxT("Ввод"));
	hbox4_1->Add(st_data_in_format, 0, wxLEFT, 110);
	wxStaticText *st_data = new wxStaticText(panel, wxID_ANY, wxT("Данные"));
	hbox4_1->Add(st_data, 0, wxLEFT, 60);
	wxStaticText *st_data_order = new wxStaticText(panel, wxID_ANY, wxT("Порядок байт"));
	hbox4_1->Add(st_data_order, 0, wxLEFT, 120);
	vbox->Add(hbox4_1, 0);
	//vbox->Add(-1, 20);
	
	wxArrayString strings_data_type;
	strings_data_type.Add(no_data);
	strings_data_type.Add(int_1_byte);
	strings_data_type.Add(int_2_byte);
	strings_data_type.Add(int_4_byte);
	strings_data_type.Add(int_8_byte);
	strings_data_type.Add(float_4_byte);
	strings_data_type.Add(float_8_byte);
	strings_data_type.Add(bit_field);
	combo_data_type = new wxComboBox(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(180, 30), strings_data_type, wxCB_DROPDOWN);
	combo_data_type->SetSelection(0);
	hbox4_2->Add(combo_data_type, 0, wxLEFT, 20);
	
	wxArrayString strings_data_in_format;
	strings_data_in_format.Add(data_dec);
	strings_data_in_format.Add(data_hex);
	combo_data_in_format = new wxComboBox(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(70, 30), strings_data_in_format, wxCB_DROPDOWN);
	combo_data_in_format->SetSelection(1);
	hbox4_2->Add(combo_data_in_format, 0, wxLEFT, 30);
	
	tc_data = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(160, 30));
	hbox4_2->Add(tc_data, 0, wxLEFT, 30);
	
	wxArrayString strings_data_order;
	strings_data_order.Add(data_order_forward);
	strings_data_order.Add(data_order_backward);
	combo_data_order = new wxComboBox(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(255, 30), strings_data_order, wxCB_DROPDOWN);
	combo_data_order->SetSelection(1);
	hbox4_2->Add(combo_data_order, 0, wxLEFT, 30);
	
	vbox->Add(hbox4_2, 0);
	vbox->Add(-1, 20);
	
	chbox_bit_7 = new wxCheckBox(panel, wxID_ANY, wxT("7"));
	chbox_bit_7->SetValue(false);
	hbox4_2_1->Add(chbox_bit_7, 0, wxLEFT, 20);
	chbox_bit_6 = new wxCheckBox(panel, wxID_ANY, wxT("6"));
	chbox_bit_6->SetValue(false);
	hbox4_2_1->Add(chbox_bit_6, 0, wxLEFT, 20);
	chbox_bit_5 = new wxCheckBox(panel, wxID_ANY, wxT("5"));
	chbox_bit_5->SetValue(false);
	hbox4_2_1->Add(chbox_bit_5, 0, wxLEFT, 20);
	chbox_bit_4 = new wxCheckBox(panel, wxID_ANY, wxT("4"));
	chbox_bit_4->SetValue(false);
	hbox4_2_1->Add(chbox_bit_4, 0, wxLEFT, 20);
	chbox_bit_3 = new wxCheckBox(panel, wxID_ANY, wxT("3"));
	chbox_bit_3->SetValue(false);
	hbox4_2_1->Add(chbox_bit_3, 0, wxLEFT, 20);
	chbox_bit_2 = new wxCheckBox(panel, wxID_ANY, wxT("2"));
	chbox_bit_2->SetValue(false);
	hbox4_2_1->Add(chbox_bit_2, 0, wxLEFT, 20);
	chbox_bit_1 = new wxCheckBox(panel, wxID_ANY, wxT("1"));
	chbox_bit_1->SetValue(false);
	hbox4_2_1->Add(chbox_bit_1, 0, wxLEFT, 20);
	chbox_bit_0 = new wxCheckBox(panel, wxID_ANY, wxT("0"));
	chbox_bit_0->SetValue(false);
	hbox4_2_1->Add(chbox_bit_0, 0, wxLEFT, 20);
	
	vbox->Add(hbox4_2_1, 0);
	vbox->Add(-1, 20);
	
	button_add_to_message = new wxButton(panel, ID_add_to_message, wxT("Добавить"), wxDefaultPosition, wxSize(100, 30));
	hbox4_3->Add(button_add_to_message, 0, wxLEFT, 20);
	
	vbox->Add(hbox4_3, 0);
	vbox->Add(-1, 20);
	
	grid_temp = new wxGrid(panel, wxID_ANY);
	grid_temp->CreateGrid(1, 4);
	
	wxFont col_row_label = grid_temp->GetLabelFont();
	wxFont cell_label = grid_temp->GetDefaultCellFont();
	col_row_label.SetPointSize(14);
	cell_label.SetPointSize(14);
	grid_temp->SetLabelFont(col_row_label);
	grid_temp->SetDefaultCellFont(cell_label);
	
	grid_temp->SetColLabelValue(0, wxT("Тип сообщения"));
	grid_temp->SetColLabelValue(1, wxT("ID (hex)"));
	grid_temp->SetColLabelValue(2, wxT("Данные (hex)"));
	grid_temp->SetColLabelValue(3, wxT("Порядок байт"));
	
	grid_temp->SetColSize(0, 160);
	grid_temp->SetColSize(1, 110);
	grid_temp->SetColSize(2, 300);
	grid_temp->SetColSize(3, 240);
	
	grid_temp->SetRowLabelSize(40);
	grid_temp->AutoSizeRows();
	
	vbox->Add(grid_temp, 0, wxALIGN_LEFT | wxLEFT, 20);
	vbox->Add(-1, 20);
	
	button_add_to_queue = new wxButton(panel, ID_add_to_queue, wxT("В очередь"), wxDefaultPosition, wxSize(100, 30));
	hbox5->Add(button_add_to_queue, 0, wxLEFT, 20);
	button_message_clean = new wxButton(panel, ID_message_clean, wxT("Очистка"), wxDefaultPosition, wxSize(100, 30));
	hbox5->Add(button_message_clean, 0, wxLEFT, 20);
	vbox->Add(hbox5, 0);
	vbox->Add(-1, 20);
	
	grid_queue = new wxGrid(panel, wxID_ANY);
	grid_queue->CreateGrid(grid_rows, 4);
	
	grid_queue->SetLabelFont(col_row_label);
	grid_queue->SetDefaultCellFont(cell_label);
	
	grid_queue->SetColLabelValue(0, wxT("Тип сообщения"));
	grid_queue->SetColLabelValue(1, wxT("ID (hex)"));
	grid_queue->SetColLabelValue(2, wxT("Данные (hex)"));
	grid_queue->SetColLabelValue(3, wxT("Порядок байт"));
	
	grid_queue->SetColSize(0, 160);
	grid_queue->SetColSize(1, 110);
	grid_queue->SetColSize(2, 300);
	grid_queue->SetColSize(3, 240);
	
	grid_queue->SetRowLabelSize(40);
	grid_queue->AutoSizeRows();
	
	vbox->Add(grid_queue, 0, wxALIGN_LEFT | wxLEFT, 20);
	vbox->Add(-1, 20);
	
	button_send = new wxButton(panel, ID_send, wxT("Отправить"), wxDefaultPosition, wxSize(100, 30));
	hbox6->Add(button_send, 0, wxLEFT, 20);
	button_queue_clean = new wxButton(panel, ID_queue_clean, wxT("Очистить"), wxDefaultPosition, wxSize(100, 30));
	hbox6->Add(button_queue_clean, 0, wxLEFT, 20);
	vbox->Add(hbox6, 0);
	vbox->Add(-1, 20);
	
	tc1->SetFont(cell_label);
	st1->SetFont(cell_label);
	st_ID_type->SetFont(cell_label);
	st_ID->SetFont(cell_label);
	combo_ID_type->SetFont(cell_label);
	tc_ID->SetFont(cell_label);
	combo_data_type->SetFont(cell_label);
	st_data_type->SetFont(cell_label);
	tc_data->SetFont(cell_label);
	st_data->SetFont(cell_label);
	combo_data_order->SetFont(cell_label);
	st_data_order->SetFont(cell_label);
	combo_data_in_format->SetFont(cell_label);
	st_data_in_format->SetFont(cell_label);
	button_add_to_message->SetFont(cell_label);
	button_add_to_queue->SetFont(cell_label);
	button_send->SetFont(cell_label);
	button_queue_clean->SetFont(cell_label);
	button_message_clean->SetFont(cell_label);
	chbox_bit_7->SetFont(cell_label);
	chbox_bit_6->SetFont(cell_label);
	chbox_bit_5->SetFont(cell_label);
	chbox_bit_4->SetFont(cell_label);
	chbox_bit_3->SetFont(cell_label);
	chbox_bit_2->SetFont(cell_label);
	chbox_bit_1->SetFont(cell_label);
	chbox_bit_0->SetFont(cell_label);
	/*grid_queue->SetLabelFont(col_row_label);
	grid_queue->SetDefaultCellFont(cell_label);*/
	
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::OnQuit));
	
	Connect(COM_1, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_1));
	Connect(COM_2, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_2));
	Connect(COM_3, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_3));
	Connect(COM_4, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_4));
	Connect(COM_5, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_5));
	Connect(COM_6, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_6));
	Connect(COM_7, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_7));
	Connect(COM_8, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_8));
	Connect(COM_9, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_port_9));
	
	Connect(ID_baud_9600, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_9600));
	Connect(ID_baud_14400, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_14400));
	Connect(ID_baud_19200, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_19200));
	Connect(ID_baud_38400, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_38400));
	Connect(ID_baud_57600, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_57600));
	Connect(ID_baud_115200, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_115200));
	Connect(ID_baud_128000, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_128000));
	Connect(ID_baud_256000, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_256000));
	Connect(ID_baud_921600, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_921600));
	Connect(ID_baud_custom, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_baud_custom));
	
	Connect(ID_byte_size_5, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_byte_size_5));
	Connect(ID_byte_size_6, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_byte_size_6));
	Connect(ID_byte_size_7, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_byte_size_7));
	Connect(ID_byte_size_8, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_byte_size_8));
	
	Connect(ID_stopbit_1, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_stopbit_1));
	Connect(ID_stopbit_1_5, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_stopbit_1_5));
	Connect(ID_stopbit_2, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_stopbit_2));
	
	Connect(ID_parity_no, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_parity_no));
	Connect(ID_parity_odd, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_parity_odd));
	Connect(ID_parity_even, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_parity_even));
	Connect(ID_parity_mark, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_parity_mark));
	Connect(ID_parity_space, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_parity_space));
	
	Connect(ID_read_interval, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_read_interval));
	Connect(ID_read_multiplier, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_read_multiplier));
	Connect(ID_read_constant, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_read_constant));
	Connect(ID_write_multiplier, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_write_multiplier));
	Connect(ID_write_constant, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::set_write_constant));
	Connect(ID_timeouts_show, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::timeouts_show));
	
	Connect(ID_settings_save, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::settings_save));
	Connect(ID_settings_load, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::settings_load));
	Connect(ID_settings_default, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::settings_default));
	
	Connect(ID_add_to_message, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_add_to_message));
	Connect(ID_add_to_queue, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_add_to_queue));
	Connect(ID_send, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_send));
	Connect(ID_queue_clean, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_queue_clean));
	Connect(ID_message_clean, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_message_clean));
	
	Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SubMenu::on_close));
	
	panel->SetSizer(vbox);
	SetMinSize(wxSize(910, 890));
	Centre();
	
	this->settings_load();
}

void SubMenu::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void SubMenu::set_port_1(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 1;
	this->set_port();
}

void SubMenu::set_port_2(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 2;
	this->set_port();
}

void SubMenu::set_port_3(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 3;
	this->set_port();
}

void SubMenu::set_port_4(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 4;
	this->set_port();
}

void SubMenu::set_port_5(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 5;
	this->set_port();
}

void SubMenu::set_port_6(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 6;
	this->set_port();
}

void SubMenu::set_port_7(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 7;
	this->set_port();
}

void SubMenu::set_port_8(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 8;
	this->set_port();
}

void SubMenu::set_port_9(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 9;
	this->set_port();
}

void SubMenu::set_baud_9600(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 9600;
	this->set_port();
}

void SubMenu::set_baud_14400(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 14400;
	this->set_port();
}

void SubMenu::set_baud_19200(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 19200;
	this->set_port();
}

void SubMenu::set_baud_38400(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 38400;
	this->set_port();
}

void SubMenu::set_baud_57600(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 57600;
	this->set_port();
}

void SubMenu::set_baud_115200(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 115200;
	this->set_port();
}

void SubMenu::set_baud_128000(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 128000;
	this->set_port();
}

void SubMenu::set_baud_256000(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 256000;
	this->set_port();
}

void SubMenu::set_baud_921600(wxCommandEvent& WXUNUSED(event))
{
	set_baud_rate = 921600;
	this->set_port();
}

void SubMenu::set_baud_custom(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	line = tc1->GetLineText(0);
	if (line == "")
		return;
	std::string temp = line.ToStdString();
	set_baud_rate = stoi(temp);
	this->set_port();
}

void SubMenu::set_byte_size_5(wxCommandEvent& WXUNUSED(event))
{
	set_byte_size = 5;
	this->set_port();
}

void SubMenu::set_byte_size_6(wxCommandEvent& WXUNUSED(event))
{
	set_byte_size = 6;
	this->set_port();
}

void SubMenu::set_byte_size_7(wxCommandEvent& WXUNUSED(event))
{
	set_byte_size = 7;
	this->set_port();
}

void SubMenu::set_byte_size_8(wxCommandEvent& WXUNUSED(event))
{
	set_byte_size = 8;
	this->set_port();
}

void SubMenu::set_stopbit_1(wxCommandEvent& WXUNUSED(event))
{
	set_stopbit = 0;
	this->set_port();
}

void SubMenu::set_stopbit_1_5(wxCommandEvent& WXUNUSED(event))
{
	set_stopbit = 1;
	this->set_port();
}

void SubMenu::set_stopbit_2(wxCommandEvent& WXUNUSED(event))
{
	set_stopbit = 2;
	this->set_port();
}

void SubMenu::set_parity_no(wxCommandEvent& WXUNUSED(event))
{
	set_parity = 0;
	this->set_port();
}

void SubMenu::set_parity_odd(wxCommandEvent& WXUNUSED(event))
{
	set_parity = 1;
	this->set_port();
}

void SubMenu::set_parity_even(wxCommandEvent& WXUNUSED(event))
{
	set_parity = 2;
	this->set_port();
}

void SubMenu::set_parity_mark(wxCommandEvent& WXUNUSED(event))
{
	set_parity = 3;
	this->set_port();
}

void SubMenu::set_parity_space(wxCommandEvent& WXUNUSED(event))
{
	set_parity = 4;
	this->set_port();
}

void SubMenu::set_read_interval(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	line = tc1->GetLineText(0);
	if (line == "")
		return;
	std::string temp = line.ToStdString();
	read_interval = stoi(temp);
	this->set_port();
	this->timeouts_show();
}

void SubMenu::set_read_multiplier(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	line = tc1->GetLineText(0);
	if (line == "")
		return;
	std::string temp = line.ToStdString();
	read_multiplier = stoi(temp);
	this->set_port();
	this->timeouts_show();
}

void SubMenu::set_read_constant(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	line = tc1->GetLineText(0);
	if (line == "")
		return;
	std::string temp = line.ToStdString();
	read_constant = stoi(temp);
	this->set_port();
	this->timeouts_show();
}

void SubMenu::set_write_multiplier(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	line = tc1->GetLineText(0);
	if (line == "")
		return;
	std::string temp = line.ToStdString();
	write_multiplier = stoi(temp);
	this->set_port();
	this->timeouts_show();
}

void SubMenu::set_write_constant(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	line = tc1->GetLineText(0);
	if (line == "")
		return;
	std::string temp = line.ToStdString();
	write_constant = stoi(temp);
	this->set_port();
	this->timeouts_show();
}

void SubMenu::timeouts_show(wxCommandEvent& WXUNUSED(event))
{
	wxString line = wxString::Format(wxT("Read interval: %d\n"), read_interval);
	line += wxString::Format(wxT("Read multiplier: %d\n"), read_multiplier);
	line += wxString::Format(wxT("Read constant: %d\n"), read_constant);
	line += wxString::Format(wxT("Write multiplier: %d\n"), write_multiplier);
	line += wxString::Format(wxT("Write constant: %d"), write_constant);
	st2->SetLabel(line);
}

void SubMenu::timeouts_show()
{
	wxString line = wxString::Format(wxT("Read interval: %d\n"), read_interval);
	line += wxString::Format(wxT("Read multiplier: %d\n"), read_multiplier);
	line += wxString::Format(wxT("Read constant: %d\n"), read_constant);
	line += wxString::Format(wxT("Write multiplier: %d\n"), write_multiplier);
	line += wxString::Format(wxT("Write constant: %d"), write_constant);
	st2->SetLabel(line);
}

void SubMenu::settings_save(wxCommandEvent& WXUNUSED(event))
{
	outFile.open("settings.sav");
	outFile << set_port_number << " ";
	outFile << set_baud_rate << " ";
	outFile << set_byte_size << " ";
	outFile << set_stopbit << " ";
	outFile << set_parity << " ";
	outFile << read_interval << " ";
	outFile << read_multiplier << " ";
	outFile << read_constant << " ";
	outFile << write_multiplier << " ";
	outFile << write_constant << " ";
	outFile.close();
}

void SubMenu::settings_load(wxCommandEvent& WXUNUSED(event))
{
	inFile.open("settings.sav");
    if (!inFile.is_open())
    {
        outFile.open("settings.sav");
        outFile.close();
		if (program_start == true)
		{
			this->show_message(wxT("Не удалось открыть файл settings.sav\nИспользуются настройки по умолчанию"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("Не удалось открыть файл settings.sav"));
		return;
    }
	
	int set_port_number_temp;
	int set_baud_rate_temp;
	int set_byte_size_temp;
	int set_stopbit_temp;
	int set_parity_temp;
	int read_interval_temp;
	int read_multiplier_temp;
	int read_constant_temp;
	int write_multiplier_temp;
	int write_constant_temp;
	
	inFile >> set_port_number_temp;
	inFile >> set_baud_rate_temp;
	inFile >> set_byte_size_temp;
	inFile >> set_stopbit_temp;
	inFile >> set_parity_temp;
	inFile >> read_interval_temp;
	inFile >> read_multiplier_temp;
	inFile >> read_constant_temp;
	inFile >> write_multiplier_temp;
	inFile >> write_constant_temp;
	
	if (!inFile.good())
	{
		if (program_start == true)
		{
			this->show_message(wxT("Ошибка чтения файла settings.sav\nИспользуются настройки по умолчанию"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("Ошибка чтения файла settings.sav"));
		inFile.close();
		return;
	}
	
	set_port_number = set_port_number_temp;
	set_baud_rate = set_baud_rate_temp;
	set_byte_size = set_byte_size_temp;
	set_stopbit = set_stopbit_temp;
	set_parity = set_parity_temp;
	read_interval = read_interval_temp;
	read_multiplier = read_multiplier_temp;
	read_constant = read_constant_temp;
	write_multiplier = write_multiplier_temp;
	write_constant = write_constant_temp;
	
	this->set_port();
	inFile.close();
}

void SubMenu::settings_load()
{
	inFile.open("settings.sav");
    if (!inFile.is_open())
    {
        outFile.open("settings.sav");
        outFile.close();
		if (program_start == true)
		{
			this->show_message(wxT("Не удалось открыть файл settings.sav\nИспользуются настройки по умолчанию"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("Не удалось открыть файл settings.sav"));
		return;
    }
	
	int set_port_number_temp;
	int set_baud_rate_temp;
	int set_byte_size_temp;
	int set_stopbit_temp;
	int set_parity_temp;
	int read_interval_temp;
	int read_multiplier_temp;
	int read_constant_temp;
	int write_multiplier_temp;
	int write_constant_temp;
	
	inFile >> set_port_number_temp;
	inFile >> set_baud_rate_temp;
	inFile >> set_byte_size_temp;
	inFile >> set_stopbit_temp;
	inFile >> set_parity_temp;
	inFile >> read_interval_temp;
	inFile >> read_multiplier_temp;
	inFile >> read_constant_temp;
	inFile >> write_multiplier_temp;
	inFile >> write_constant_temp;
	
	if (!inFile.good())
	{
		if (program_start == true)
		{
			this->show_message(wxT("Ошибка чтения файла settings.sav\nИспользуются настройки по умолчанию"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("Ошибка чтения файла settings.sav"));
		inFile.close();
		return;
	}
	
	set_port_number = set_port_number_temp;
	set_baud_rate = set_baud_rate_temp;
	set_byte_size = set_byte_size_temp;
	set_stopbit = set_stopbit_temp;
	set_parity = set_parity_temp;
	read_interval = read_interval_temp;
	read_multiplier = read_multiplier_temp;
	read_constant = read_constant_temp;
	write_multiplier = write_multiplier_temp;
	write_constant = write_constant_temp;
	
	this->set_port();
	inFile.close();
}

void SubMenu::settings_default(wxCommandEvent& WXUNUSED(event))
{
	set_port_number = 1;
	set_baud_rate = 115200;
	set_byte_size = 8;
	set_stopbit = 0;
	set_parity = 0;
	
	read_interval = MAXDWORD;
	read_multiplier = 0;
	read_constant = 0;
	write_multiplier = 1;
	write_constant = 1;
	
	this->set_port();
}

void SubMenu::settings_default()
{
	set_port_number = 1;
	set_baud_rate = 115200;
	set_byte_size = 8;
	set_stopbit = 0;
	set_parity = 0;
	
	read_interval = MAXDWORD;
	read_multiplier = 0;
	read_constant = 0;
	write_multiplier = 1;
	write_constant = 1;
	
	this->set_port();
}

void SubMenu::set_port()
{
	if (program_start == false)
		st2->SetLabel(wxT(""));
	com_port_ready = true;
	CloseHandle(hSerial);
	wchar_t *sPortName;
	wxString line;
	if (set_port_number == 1)
		sPortName = L"COM1";
	if (set_port_number == 2)
		sPortName = L"COM2";
	if (set_port_number == 3)
		sPortName = L"COM3";
	if (set_port_number == 4)
		sPortName = L"COM4";
	if (set_port_number == 5)
		sPortName = L"COM5";
	if (set_port_number == 6)
		sPortName = L"COM6";
	if (set_port_number == 7)
		sPortName = L"COM7";
	if (set_port_number == 8)
		sPortName = L"COM8";
	if (set_port_number == 9)
		sPortName = L"COM9";
	hSerial = ::CreateFile(sPortName,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	if(hSerial==INVALID_HANDLE_VALUE)
	{
		if(GetLastError()==ERROR_FILE_NOT_FOUND)
		{
			this->show_message(wxString::Format(wxT("COM %d serial port does not exist"), set_port_number));
			st1->SetLabel(wxString::Format(wxT("COM %d serial port does not exist"), set_port_number));
			com_port_ready = false;
			return;
		}
		this->show_message(wxString::Format(wxT("COM %d some other error occurred"), set_port_number));
		st1->SetLabel(wxString::Format(wxT("COM %d some other error occurred"), set_port_number));
		com_port_ready = false;
		return;
	}

	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		this->show_message(wxString::Format(wxT("COM %d getting state error"), set_port_number));
		st1->SetLabel(wxString::Format(wxT("COM %d getting state error"), set_port_number));
		com_port_ready = false;
		return;
	}
	dcbSerialParams.BaudRate = set_baud_rate;
	dcbSerialParams.ByteSize = set_byte_size;
	dcbSerialParams.StopBits = set_stopbit;
	dcbSerialParams.Parity = set_parity;
	if(!SetCommState(hSerial, &dcbSerialParams))
	{
		this->show_message(wxString::Format(wxT("COM %d error setting serial port state"), set_port_number));
		st1->SetLabel(wxString::Format(wxT("COM %d error setting serial port state"), set_port_number));
		com_port_ready = false;
		return;
	}
	
	COMMTIMEOUTS timeouts = { read_interval, // read interval
                              read_multiplier, // read multiplier
                             read_constant, // read constant
                              write_multiplier, // write multiplier
                              write_constant  // write constant
                            };					
	
    SetCommTimeouts(hSerial, &timeouts);
	PurgeComm(hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
	
	line = wxString::Format(wxT("COM%d, %d, %d bits"), set_port_number, set_baud_rate, set_byte_size);
	
	line += ", ";
	if (set_stopbit == 0)
		line += "1 stopbit";
	if (set_stopbit == 1)
		line += "1.5 stopbit";
	if (set_stopbit == 2)
		line += "2 stopbit";

	line += ", ";
	if (set_parity == 0)
		line += "no parity";
	if (set_parity == 1)
		line += "odd parity";
	if (set_parity == 2)
		line += "even parity";
	if (set_parity == 3)
		line += "mark parity";
	if (set_parity == 4)
		line += "space parity";

	st1->SetLabel(line);
}

void SubMenu::on_add_to_message(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	unsigned int ID = 0;
	unsigned int ID_max = 0;
	std::uint64_t data = 0;
	
	grid_temp->SetCellValue(0, 0, combo_ID_type->GetStringSelection());
	grid_temp->SetCellValue(0, 3, combo_data_order->GetStringSelection());
	if (combo_ID_type->GetStringSelection() == standart_ID)
		ID_max = 0x7FF;
	else
		ID_max = 0x1FFFFFFF;
	
	/*if (combo_data_order->GetStringSelection() == data_order_backward)
		order_backward = true;
	else
		order_backward = false;*/
	
	line = tc_ID->GetLineText(0);
	std::string temp = line.ToStdString();
	char *cstr = new char[temp.length() + 1];
	strcpy(cstr, temp.c_str());
	sscanf(cstr, "%x", &ID);
	
	if (ID > ID_max)
	{
		grid_temp->SetCellValue(0, 1, wxT("ID > ID max"));
		ID_error = true;
		return;
	}
	
	ID_error = false;
	//add_to_queue_enable = true;
	
	grid_temp->SetCellValue(0, 1, wxString::Format(wxT("%X"), ID));
	delete [] cstr;
	
	if (combo_data_type->GetStringSelection() != no_data)
	{
		line = tc_data->GetLineText(0);
		temp = line.ToStdString();
		cstr = new char[temp.length() + 1];
		strcpy(cstr, temp.c_str());
		
		if (combo_data_type->GetStringSelection() == int_1_byte || combo_data_type->GetStringSelection() == int_2_byte || combo_data_type->GetStringSelection() == int_4_byte || combo_data_type->GetStringSelection() == int_8_byte)
		{
			if (combo_data_in_format->GetStringSelection() == data_hex)
			sscanf(cstr, "%llx", &data);
			if (combo_data_in_format->GetStringSelection() == data_dec)
			sscanf(cstr, "%llu", &data);
			
			if (combo_data_type->GetStringSelection() == int_1_byte && data_bytes_used <= 7)
			{
				data_buf[data_bytes_used] = *((uint8_t *)&data);
				data_bytes_used += 1;
			}
			if (combo_data_type->GetStringSelection() == int_2_byte && data_bytes_used <= 6)
			{
				if (combo_data_order->GetStringSelection() == data_order_backward)
				{
					for (int i = data_bytes_used, k = 0; k < 2; i++, k++)
						data_buf[i] = *((uint8_t *)&data + k);
				}
				else
				{
					for (int i = data_bytes_used, k = 1; k >= 0; i++, k--)
						data_buf[i] = *((uint8_t *)&data + k);
				}
				data_bytes_used += 2;
			}
			if (combo_data_type->GetStringSelection() == int_4_byte && data_bytes_used <= 4)
			{
				if (combo_data_order->GetStringSelection() == data_order_backward)
				{
					for (int i = data_bytes_used, k = 0; k < 4; i++, k++)
						data_buf[i] = *((uint8_t *)&data + k);
				}
				else
				{
					for (int i = data_bytes_used, k = 3; k >= 0; i++, k--)
						data_buf[i] = *((uint8_t *)&data + k);
				}
				data_bytes_used += 4;
			}
			if (combo_data_type->GetStringSelection() == int_8_byte && data_bytes_used == 0)
			{
				if (combo_data_order->GetStringSelection() == data_order_backward)
				{
					for (int i = data_bytes_used, k = 0; k < 8; i++, k++)
						data_buf[i] = *((uint8_t *)&data + k);
				}
				else
				{
					for (int i = data_bytes_used, k = 7; k >= 0; i++, k--)
						data_buf[i] = *((uint8_t *)&data + k);
				}
				data_bytes_used += 8;
			}
		}
		if (combo_data_type->GetStringSelection() == float_4_byte && data_bytes_used <= 4)
		{
			sscanf(cstr, "%f", (float *)&data);
			//grid_queue->SetCellValue(9, 2, wxString::Format(wxT("%f"), *((float *)&data)));
			
			if (combo_data_order->GetStringSelection() == data_order_backward)
			{
				for (int i = data_bytes_used, k = 0; k < 4; i++, k++)
					data_buf[i] = *((uint8_t *)&data + k);
			}
			else
			{
				for (int i = data_bytes_used, k = 3; k >= 0; i++, k--)
					data_buf[i] = *((uint8_t *)&data + k);
			}
			data_bytes_used += 4;
		}
		if (combo_data_type->GetStringSelection() == float_8_byte && data_bytes_used == 0)
		{
			sscanf(cstr, "%lf", (double *)&data);
			//grid_queue->SetCellValue(9, 2, wxString::Format(wxT("%f"), *((double *)&data)));
			
			if (combo_data_order->GetStringSelection() == data_order_backward)
			{
				for (int i = data_bytes_used, k = 0; k < 8; i++, k++)
					data_buf[i] = *((uint8_t *)&data + k);
			}
			else
			{
				for (int i = data_bytes_used, k = 7; k >= 0; i++, k--)
					data_buf[i] = *((uint8_t *)&data + k);
			}
			data_bytes_used += 8;
		}
		if (combo_data_type->GetStringSelection() == bit_field && data_bytes_used <= 7)
		{
			data_buf[data_bytes_used] = 0;
			if (chbox_bit_0->GetValue() == true)
				data_buf[data_bytes_used] += 0x1;
			if (chbox_bit_1->GetValue() == true)
				data_buf[data_bytes_used] += 0x2;
			if (chbox_bit_2->GetValue() == true)
				data_buf[data_bytes_used] += 0x4;
			if (chbox_bit_3->GetValue() == true)
				data_buf[data_bytes_used] += 0x8;
			if (chbox_bit_4->GetValue() == true)
				data_buf[data_bytes_used] += 0x10;
			if (chbox_bit_5->GetValue() == true)
				data_buf[data_bytes_used] += 0x20;
			if (chbox_bit_6->GetValue() == true)
				data_buf[data_bytes_used] += 0x40;
			if (chbox_bit_7->GetValue() == true)
				data_buf[data_bytes_used] += 0x80;
			data_bytes_used += 1;
		}
		delete [] cstr;
		
		for(int i = 0, k = 0; k < 8; i += 2, k++)
		{
			if (data_buf[k] <= 0xF)
				sprintf(&data_temp[i], "0%X", data_buf[k]);
			else
				sprintf(&data_temp[i], "%X", data_buf[k]);
		}
		data_temp[data_bytes_used * 2] = '\0';
		grid_temp->SetCellValue(0, 2, wxString(data_temp));
	}
	else
	{
		data_temp[0] = '\0';
		grid_temp->SetCellValue(0, 2, no_data);
	}
	
	char ID_temp_temp[9];
	sprintf(ID_temp_temp, "%X", ID);
	int j = 0;
	int k = 0;
	if (combo_ID_type->GetStringSelection() == extended_ID)
		k = 8;
	else
		k = 3;
	for (j = 0; j < k - strlen(ID_temp_temp); j++)
		ID_temp[j] = '0';
	ID_temp[j] = '\0';
	strcat(ID_temp, ID_temp_temp);
}

void SubMenu::on_add_to_queue(wxCommandEvent& WXUNUSED(event))
{
	if (ID_error == true)
		return;
	if (messages >= grid_rows)
		return;
	
	if (strlen(ID_temp) == 8)
		grid_queue->SetCellValue(messages, 0, extended_ID);
	else if (strlen(ID_temp) == 3)
		grid_queue->SetCellValue(messages, 0, standart_ID);
	
	ID_string[messages] = std::string(ID_temp);
	data_string[messages] = std::string(data_temp);
	
	grid_queue->SetCellValue(messages, 1, wxString(ID_string[messages]));
	if (data_string[messages] != "")
		grid_queue->SetCellValue(messages, 2, wxString(data_string[messages]));
	else
		grid_queue->SetCellValue(messages, 2, no_data);
	messages++;
	data_bytes_used = 0;
}

void SubMenu::on_send(wxCommandEvent& WXUNUSED(event))
{
	wxString line = "";
	
	if (com_port_ready == false)
		return;
	DWORD iSize = 0;
	char sTransmitedChar[28];
	char sReceivedChar[100];
	for (int i = 0; i < messages; i++)
	{
		if (ID_string[i].length() == 3)
			strcpy(sTransmitedChar, "t");
		else if ((ID_string[i].length() == 8))
			strcpy(sTransmitedChar, "e");
			
		strcat(sTransmitedChar, ID_string[i].c_str());
		sprintf(&sTransmitedChar[strlen(sTransmitedChar)], "%X", data_string[i].length() / 2);
		strcat(sTransmitedChar, data_string[i].c_str());
		strcat(sTransmitedChar, "\r");
	
		WriteFile(hSerial, sTransmitedChar, strlen(sTransmitedChar), &iSize, 0);
		
		st2->SetLabel(wxString(sTransmitedChar));
		
		for (int i = 0; i < strlen(sTransmitedChar); i++)
			line += wxString::Format(wxT("%x, "), int(sTransmitedChar[i]) % 0xffffff00);
		line += "\n";
		
		wxMilliSleep(3);
	}
	st2->SetLabel(line);
	
	/*wxString line;
	while (iSize == 0)
		ReadFile(hSerial, sReceivedChar, packet, &iSize, 0);
	
	sReceivedChar[iSize] = '\0';
	line = "cycle = ";
	line += wxString::Format(wxT("%d\n"), counter++);
	line += "bytes readed = ";
	line += wxString::Format(wxT("%d\n"), iSize);
	line += wxString(sReceivedChar);
	line += "\n";
	
	for (int i = 0; i < iSize - 1; i++)
	{
		line += wxString::Format(wxT("%x, "), int(sReceivedChar[i]) % 0xffffff00);
		if ((i + 1) % 14 == 0)
			line += "\n";
	}
	line += wxString::Format(wxT("%x"), int(sReceivedChar[iSize - 1]) % 0xffffff00);
	
	st2->SetLabel(line);*/
}

void SubMenu::on_queue_clean(wxCommandEvent& WXUNUSED(event))
{
	for (int i = 0; i < messages; i++)
	{
		ID_string[i] = "";
		data_string[i] = "";
		
		for (int j = 0; j < 4; j++)
			grid_queue->SetCellValue(i, j, wxT(""));
	}
	messages = 0;
}

void SubMenu::on_message_clean(wxCommandEvent& WXUNUSED(event))
{
	data_bytes_used = 0;
	ID_error = true;
	for (int i = 0; i < 4; i++)
		grid_temp->SetCellValue(0, i, wxT(""));
	/*tc_ID->SetLabel(wxT(""));
	tc_data->SetLabel(wxT(""));*/
}

void SubMenu::show_message(const wxString &message)
{
	wxMessageDialog *dial = new wxMessageDialog(NULL, message, wxT("Message"), wxOK | wxICON_WARNING);
	dial->ShowModal();
}

void SubMenu::on_close(wxCloseEvent& event)
{
	wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Are you sure to quit?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	int ret = dial->ShowModal();
	dial->Destroy();
	
	if (ret == wxID_YES)
	{
		Destroy();
	}
	else
		event.Veto();
}