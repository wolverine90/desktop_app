#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/tglbtn.h>
#include <fstream>
#include "commands.h"

unsigned int mask_triple = 0xFFF00000;
unsigned int mask_quatro = 0xFFFF0000;

int COM_1 = 101;
int COM_2 = 102;
int COM_3 = 103;
int COM_4 = 104;
int COM_5 = 105;
int COM_6 = 106;
int COM_7 = 107;
int COM_8 = 108;
int COM_9 = 109;
int ID_button_receive = 111;
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
int Rec_Timer = 143;
int ID_button_custom_transmit = 146;
int ID_set_timer = 147;
int ID_log_enable = 148;
int ID_baud_921600 = 149;
int ID_toggle_launch_stop = 150;
int ID_clear_grid = 151;
int ID_error_control = 152;

const int packet = 26 * 1024;

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
	
	void on_set_timer(wxCommandEvent& event);
	
	void settings_save(wxCommandEvent& event);
	void settings_load(wxCommandEvent& event);
	void settings_load();
	void settings_default(wxCommandEvent& event);
	void settings_default();
	
	void set_port();
	
	void on_receive(wxCommandEvent& event);
	void on_custom_transmit(wxCommandEvent& event);
	
	void on_toggle_launch_stop(wxCommandEvent& event);
	void on_clear_grid(wxCommandEvent& event);
	
	void OnRecTimer(wxTimerEvent& event);
	
	void show_message(const wxString &message);
	void on_close(wxCloseEvent& event);
	
	wxStaticText *st1;
	wxStaticText *st2;
	wxTextCtrl *tc1;
	wxButton *button_receive;
	wxButton *button_custom_transmit;
	wxButton *clear_grid;
	wxToggleButton *toggle_launch_stop;
	wxCheckBox *log_enable;
	wxCheckBox *error_control;
	wxTimer* recTimer;
	wxGrid *grid;
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
	int set_timer;
	HANDLE hSerial;
	int counter;
	bool com_port_ready;
	bool program_start;
	bool id_with_error;
	int grid_rows;
	char sReceivedChar_temp[50];
	int sReceivedChar_temp_last_byte;
	
	unsigned int counter_bloader_erase_rslt;
	unsigned int counter_cpu_request_inf;
	unsigned int counter_bloader_provide_inf;
	unsigned int counter_bloader_bus_off;
	unsigned int counter_cpu_request_erase_fl;
	unsigned int counter_cpu_request_prgrm_fl;
	unsigned int counter_bloader_request_data;
	unsigned int counter_cpu_send_data;
	unsigned int counter_cpu_end_data;
	unsigned int counter_bloader_prgr_result;
	unsigned int counter_cpu_check_request;
	unsigned int counter_bloader_request_data_smpl;
	unsigned int counter_cpu_transmit_data_smpl;
	unsigned int counter_cpu_end_data_smpl;
	unsigned int counter_bloader_check_result;
	unsigned int counter_cpu_transfer_ctrl_request;
	unsigned int counter_bloader_tr_ctrl_confirm;
	unsigned int counter_cpu_request_read_fl;
	unsigned int counter_bloader_send_data_fl;
	unsigned int counter_cpu_end_data_fl;
	unsigned int counter_bloader_data_fl_err;
	
	int pos_bloader_erase_rslt;
	int pos_cpu_request_inf;
	int pos_bloader_provide_inf;
	int pos_bloader_bus_off;
	int pos_cpu_request_erase_fl;
	int pos_cpu_request_prgrm_fl;
	int pos_bloader_request_data;
	int pos_cpu_send_data;
	int pos_cpu_end_data;
	int pos_bloader_prgr_result;
	int pos_cpu_check_request;
	int pos_bloader_request_data_smpl;
	int pos_cpu_transmit_data_smpl;
	int pos_cpu_end_data_smpl;
	int pos_bloader_check_result;
	int pos_cpu_transfer_ctrl_request;
	int pos_bloader_tr_ctrl_confirm;
	int pos_cpu_request_read_fl;
	int pos_bloader_send_data_fl;
	int pos_cpu_end_data_fl;
	int pos_bloader_data_fl_err;
	
	int messages;
	
	std::ifstream inFile;
	std::ofstream outFile;
	std::ofstream log;
	std::ofstream log_error;
};

DECLARE_APP(MyApp);
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SubMenu *simple = new SubMenu(wxT("Simple"));
	simple->Show(true);
	return true;
}

SubMenu::SubMenu(const wxString& title): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1500, 920))
{
	program_start = true;
	id_with_error = false;
	counter = 0;
	set_timer = 0;
	grid_rows = 21;
	sReceivedChar_temp_last_byte = 0;
	
	messages = 0;
	counter_bloader_erase_rslt = 0;
	counter_cpu_request_inf = 0;
	counter_bloader_provide_inf = 0;
	counter_bloader_bus_off = 0;
	counter_cpu_request_erase_fl = 0;
	counter_cpu_request_prgrm_fl = 0;
	counter_bloader_request_data = 0;
	counter_cpu_send_data = 0;
	counter_cpu_end_data = 0;
	counter_bloader_prgr_result = 0;
	counter_cpu_check_request = 0;
	counter_bloader_request_data_smpl = 0;
	counter_cpu_transmit_data_smpl = 0;
	counter_cpu_end_data_smpl = 0;
	counter_bloader_check_result = 0;
	counter_cpu_transfer_ctrl_request = 0;
	counter_bloader_tr_ctrl_confirm = 0;
	counter_cpu_request_read_fl = 0;
	counter_bloader_send_data_fl = 0;
	counter_cpu_end_data_fl = 0;
	counter_bloader_data_fl_err = 0;
	
	pos_bloader_erase_rslt = -1;
	pos_cpu_request_inf = -1;
	pos_bloader_provide_inf = -1;
	pos_bloader_bus_off = -1;
	pos_cpu_request_erase_fl = -1;
	pos_cpu_request_prgrm_fl = -1;
	pos_bloader_request_data = -1;
	pos_cpu_send_data = -1;
	pos_cpu_end_data = -1;
	pos_bloader_prgr_result = -1;
	pos_cpu_check_request = -1;
	pos_bloader_request_data_smpl = -1;
	pos_cpu_transmit_data_smpl = -1;
	pos_cpu_end_data_smpl = -1;
	pos_bloader_check_result = -1;
	pos_cpu_transfer_ctrl_request = -1;
	pos_bloader_tr_ctrl_confirm = -1;
	pos_cpu_request_read_fl = -1;
	pos_bloader_send_data_fl = -1;
	pos_cpu_end_data_fl = -1;
	pos_bloader_data_fl_err = -1;

	log.open("can_log.sav");
	log_error.open("can_log_error.sav");
	
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
	settings->AppendSeparator();
	settings->Append(ID_set_timer, wxT("Set timer"));
	
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
	
	log_enable = new wxCheckBox(panel, ID_log_enable, wxT("???????????????????? ????????????"));
	log_enable->SetValue(true);
	hbox3->Add(log_enable, 0, wxRIGHT | wxLEFT | wxALIGN_BOTTOM, 10);
	error_control = new wxCheckBox(panel, ID_error_control, wxT("?????????????????? ????????????"));
	error_control->SetValue(true);
	hbox3->Add(error_control, 0, wxRIGHT | wxALIGN_BOTTOM, 10);
	button_receive = new wxButton(panel, ID_button_receive, wxT("status"));
	hbox3->Add(button_receive, 0, wxRIGHT | wxALIGN_BOTTOM, 10);
	button_custom_transmit = new wxButton(panel, ID_button_custom_transmit, wxT("mode"));
	hbox3->Add(button_custom_transmit, 0, wxRIGHT | wxALIGN_BOTTOM, 30);
	
	vbox->Add(hbox3, 0, wxALIGN_RIGHT);
	vbox->Add(-1, 10);
	
	grid = new wxGrid(panel, wxID_ANY);
	grid->CreateGrid(grid_rows, 5);
	
	wxFont col_row_label = grid->GetLabelFont();
	wxFont cell_label = grid->GetDefaultCellFont();
	col_row_label.SetPointSize(14);
	cell_label.SetPointSize(14);
	grid->SetLabelFont(col_row_label);
	grid->SetDefaultCellFont(cell_label);
	
	grid->SetColLabelValue(0, wxT("???????????????? ??????????????????"));
	grid->SetColLabelValue(1, wxT("ID (bin)"));
	grid->SetColLabelValue(2, wxT("Data (hex)"));
	grid->SetColLabelValue(3, wxT("??????????????"));
	grid->SetColLabelValue(4, wxT("????????????????"));
	
	grid->SetColSize(0, 450);
	grid->SetColSize(1, 370);
	grid->SetColSize(2, 210);
	grid->SetColSize(3, 90);
	grid->SetColSize(4, 260);
	
	grid->SetRowLabelSize(40);
	grid->AutoSizeRows();
	
	vbox->Add(grid, 0, wxALIGN_CENTER_HORIZONTAL);
	vbox->Add(-1, 10);
	
	log_enable->SetFont(cell_label);
	error_control->SetFont(cell_label);
	tc1->SetFont(cell_label);
	st1->SetFont(cell_label);
	toggle_launch_stop = new wxToggleButton(panel, ID_toggle_launch_stop, wxT("????????"), wxDefaultPosition, wxSize(150, 45));
	toggle_launch_stop->SetValue(false);
	toggle_launch_stop->SetFont(col_row_label);
	hbox4->Add(toggle_launch_stop, 0, wxRIGHT | wxLEFT | wxALIGN_BOTTOM, 10);
	clear_grid = new wxButton(panel, ID_clear_grid, wxT("????????????????"), wxDefaultPosition, wxSize(150, 45));
	clear_grid->SetFont(col_row_label);
	hbox4->Add(clear_grid, 0, wxRIGHT | wxALIGN_BOTTOM, 10);
	vbox->Add(hbox4, 0, wxALIGN_CENTER_HORIZONTAL);
	vbox->Add(-1, 10);
	
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
	
	Connect(ID_set_timer, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::on_set_timer));
	
	Connect(ID_settings_save, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::settings_save));
	Connect(ID_settings_load, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::settings_load));
	Connect(ID_settings_default, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::settings_default));

	Connect(ID_button_receive, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_receive));
	Connect(ID_button_custom_transmit, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_custom_transmit));
	
	Connect(ID_toggle_launch_stop, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_toggle_launch_stop));
	Connect(ID_clear_grid, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SubMenu::on_clear_grid));
	
	Connect(Rec_Timer, wxEVT_TIMER, wxTimerEventHandler(SubMenu::OnRecTimer));
	
	Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SubMenu::on_close));
	
	panel->SetSizer(vbox);
	SetMinSize(wxSize(1500, 900));
	Centre();
	
	recTimer = new wxTimer(this, Rec_Timer);
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

void SubMenu::on_set_timer(wxCommandEvent& WXUNUSED(event))
{
	wxString line;
	line = tc1->GetLineText(0);
	if (line == "")
		return;
	std::string temp = line.ToStdString();
	set_timer = stoi(temp);	
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
			this->show_message(wxT("???? ?????????????? ?????????????? ???????? settings.sav\n???????????????????????? ?????????????????? ???? ??????????????????"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("???? ?????????????? ?????????????? ???????? settings.sav"));
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
			this->show_message(wxT("???????????? ???????????? ?????????? settings.sav\n???????????????????????? ?????????????????? ???? ??????????????????"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("???????????? ???????????? ?????????? settings.sav"));
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
			this->show_message(wxT("???? ?????????????? ?????????????? ???????? settings.sav\n???????????????????????? ?????????????????? ???? ??????????????????"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("???? ?????????????? ?????????????? ???????? settings.sav"));
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
			this->show_message(wxT("???????????? ???????????? ?????????? settings.sav\n???????????????????????? ?????????????????? ???? ??????????????????"));
			this->settings_default();
			program_start = false;
		}
		else
			this->show_message(wxT("???????????? ???????????? ?????????? settings.sav"));
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

void SubMenu::on_receive(wxCommandEvent& WXUNUSED(event))
{
	if (com_port_ready == false)
		return;
	DWORD iSize = 0;
	char sTransmitedChar[] = "s\r";
	char sReceivedChar[packet];
	wxString line;
	while (iSize == 0)
	{
		WriteFile(hSerial, sTransmitedChar, strlen(sTransmitedChar), &iSize, 0);
		ReadFile(hSerial, sReceivedChar, packet, &iSize, 0);
	}
	
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
	
	st2->SetLabel(line);
}

void SubMenu::on_custom_transmit(wxCommandEvent& WXUNUSED(event))
{
	if (com_port_ready == false)
		return;
	DWORD iSize = 0;
	char sTransmitedChar[] = "E0000000A0\r";
	WriteFile(hSerial, sTransmitedChar, strlen(sTransmitedChar), &iSize, 0);
}

void SubMenu::on_toggle_launch_stop(wxCommandEvent& WXUNUSED(event))
{
	if (toggle_launch_stop->GetValue())
	{
		if (com_port_ready == false)
			return;
		if (set_timer == 0)
			recTimer->Start(200);
		else
			recTimer->Start(set_timer);
		DWORD iSize = 0;
		char sTransmitedChar[] = "E0000000A0\r";
		WriteFile(hSerial, sTransmitedChar, strlen(sTransmitedChar), &iSize, 0);
		toggle_launch_stop->SetLabel(wxT("????????"));
		toggle_launch_stop->SetBackgroundColour(wxColour(128, 128, 128));
	}
	else
	{
		if (com_port_ready == false)
			return;
		recTimer->Stop();
		DWORD iSize = 0;
		char sTransmitedChar[] = "E0000000F0\r";
		WriteFile(hSerial, sTransmitedChar, strlen(sTransmitedChar), &iSize, 0);
		toggle_launch_stop->SetLabel(wxT("????????"));
		toggle_launch_stop->SetBackgroundColour(wxColour());
	}
}

void SubMenu::on_clear_grid(wxCommandEvent& WXUNUSED(event))
{
	messages = 0;
	counter_bloader_erase_rslt = 0;
	counter_cpu_request_inf = 0;
	counter_bloader_provide_inf = 0;
	counter_bloader_bus_off = 0;
	counter_cpu_request_erase_fl = 0;
	counter_cpu_request_prgrm_fl = 0;
	counter_bloader_request_data = 0;
	counter_cpu_send_data = 0;
	counter_cpu_end_data = 0;
	counter_bloader_prgr_result = 0;
	counter_cpu_check_request = 0;
	counter_bloader_request_data_smpl = 0;
	counter_cpu_transmit_data_smpl = 0;
	counter_cpu_end_data_smpl = 0;
	counter_bloader_check_result = 0;
	counter_cpu_transfer_ctrl_request = 0;
	counter_bloader_tr_ctrl_confirm = 0;
	counter_cpu_request_read_fl = 0;
	counter_bloader_send_data_fl = 0;
	counter_cpu_end_data_fl = 0;
	counter_bloader_data_fl_err = 0;
	
	pos_bloader_erase_rslt = -1;
	pos_cpu_request_inf = -1;
	pos_bloader_provide_inf = -1;
	pos_bloader_bus_off = -1;
	pos_cpu_request_erase_fl = -1;
	pos_cpu_request_prgrm_fl = -1;
	pos_bloader_request_data = -1;
	pos_cpu_send_data = -1;
	pos_cpu_end_data = -1;
	pos_bloader_prgr_result = -1;
	pos_cpu_check_request = -1;
	pos_bloader_request_data_smpl = -1;
	pos_cpu_transmit_data_smpl = -1;
	pos_cpu_end_data_smpl = -1;
	pos_bloader_check_result = -1;
	pos_cpu_transfer_ctrl_request = -1;
	pos_bloader_tr_ctrl_confirm = -1;
	pos_cpu_request_read_fl = -1;
	pos_bloader_send_data_fl = -1;
	pos_cpu_end_data_fl = -1;
	pos_bloader_data_fl_err = -1;
	
	for (int i = 0; i < grid_rows; i++)
		for (int j = 0; j < 5; j++)
		{
			grid->SetCellValue(i, j, wxString(wxT("")));
			grid->SetCellBackgroundColour(i, j, wxColour(255, 255, 255));
		}
}

void SubMenu::OnRecTimer(wxTimerEvent& event)
{
	if (com_port_ready == false)
		return;
	DWORD iSize = 0;
	unsigned int ID = 0;
	int data_size = 0;
	wxString data_hex = "";
	char buf[30];
	char buf_tetr[40] = "000";
	char sReceivedChar[packet];
	wxString line = "";
	int pos_table = -1;
	char log_name[100] = "";
	unsigned int log_name_counter = 0;
	
	ReadFile(hSerial, &sReceivedChar[sReceivedChar_temp_last_byte], packet, &iSize, 0);
	
	if (sReceivedChar_temp_last_byte != 0)
	{
		for (int i = 0; i < sReceivedChar_temp_last_byte; i++)
			sReceivedChar[i] = sReceivedChar_temp[i];
		iSize += sReceivedChar_temp_last_byte;
		sReceivedChar_temp_last_byte = 0;
	}
	
	int i = 0;
	if (sReceivedChar[0] == '\r')
		i = 1;
	while (i < iSize)
	{
		if (i + 9 < iSize)
		{
			strncpy(buf, &sReceivedChar[i + 9], 1);
			buf[1] = '\0';
			sscanf(buf, "%d", &data_size);
			
			if (i + 9 + data_size * 2 < iSize)
			{
				strncpy(buf, &sReceivedChar[i + 1], 8);
				buf[8] = '\0';
				sscanf(buf, "%x", &ID);
			
				if ((ID & mask_triple) == bloader_erase_rslt_ROM || (ID & mask_triple) == bloader_erase_rslt_Flash) //?????????????????? ???????????????? ?? ??????????????. ???????????????????? ??????. ???????????????? ???????????????? (0x1E0 ?? 0x1E8) 
				{
					if ((ID & mask_quatro) == bloader_data_fl_err) //???????????? ?????????????????????? (0x1E0E)
					{
						if (pos_bloader_data_fl_err < 0)
						{
							pos_bloader_data_fl_err = messages;
							messages++;
							grid->SetCellValue(pos_bloader_data_fl_err, 0, wxT("??????????????. ???????????????????? ??????. ???????????????? ????????????????"));
						}
						counter_bloader_data_fl_err++;
						grid->SetCellValue(pos_bloader_data_fl_err, 3, wxString::Format(wxT("%d"), counter_bloader_data_fl_err));
						pos_table = pos_bloader_data_fl_err;
						strcpy(log_name, "??????????????. ???????????????????? ??????. ???????????????? ????????????????");
						log_name_counter = counter_bloader_data_fl_err;
						
						id_with_error = true;
					}
					else //?????????????????? ???????????????? (0x1E0 ?? 0x1E8)
					{
						if (pos_bloader_erase_rslt < 0)
						{
							pos_bloader_erase_rslt = messages;
							messages++;
							grid->SetCellValue(pos_bloader_erase_rslt, 0, wxT("?????????????????? ????????????????"));
						}
						counter_bloader_erase_rslt++;
						grid->SetCellValue(pos_bloader_erase_rslt, 3, wxString::Format(wxT("%d"), counter_bloader_erase_rslt));
						pos_table = pos_bloader_erase_rslt;
						strcpy(log_name, "?????????????????? ????????????????");
						log_name_counter = counter_bloader_erase_rslt;
						
						if ((ID & 0xF0000) != 0)
							id_with_error = true;
					}
				}
				if ((ID & mask_triple) == cpu_request_erase_fl_ROM || (ID & mask_triple) == cpu_request_erase_fl_Flash) //???????????? ???????????????? (0x1C0 ?? 0x1C8)
				{
					if (pos_cpu_request_erase_fl < 0)
					{
						pos_cpu_request_erase_fl = messages;
						messages++;
						grid->SetCellValue(pos_cpu_request_erase_fl, 0, wxT("???????????? ????????????????"));
					}
					counter_cpu_request_erase_fl++;
					grid->SetCellValue(pos_cpu_request_erase_fl, 3, wxString::Format(wxT("%d"), counter_cpu_request_erase_fl));
					pos_table = pos_cpu_request_erase_fl;
					strcpy(log_name, "???????????? ????????????????");
					log_name_counter = counter_cpu_request_erase_fl;
				}
				if ((ID & mask_quatro) == cpu_request_prgrm_fl_ROM || (ID & mask_quatro) == cpu_request_prgrm_fl_Flash) //???????????? ???????????????????????????????? (0x1C20 ?? 0x1CA0)
				{
					if (pos_cpu_request_prgrm_fl < 0)
					{
						pos_cpu_request_prgrm_fl = messages;
						messages++;
						grid->SetCellValue(pos_cpu_request_prgrm_fl, 0, wxT("???????????? ????????????????????????????????"));
					}
					counter_cpu_request_prgrm_fl++;
					grid->SetCellValue(pos_cpu_request_prgrm_fl, 3, wxString::Format(wxT("%d"), counter_cpu_request_prgrm_fl));
					pos_table = pos_cpu_request_prgrm_fl;
					strcpy(log_name, "???????????? ????????????????????????????????");
					log_name_counter = counter_cpu_request_prgrm_fl;
				}
				if ((ID & mask_triple) == cpu_request_inf) //???????????? ?????????? ?????????????????? ???????????????????? (0x1D0) 
				{
					if (pos_cpu_request_inf < 0)
					{
						pos_cpu_request_inf = messages;
						messages++;
						grid->SetCellValue(pos_cpu_request_inf, 0, wxT("???????????? ?????????? ?????????????????? ????????????????????"));
					}
					counter_cpu_request_inf++;
					grid->SetCellValue(pos_cpu_request_inf, 3, wxString::Format(wxT("%d"), counter_cpu_request_inf));
					pos_table = pos_cpu_request_inf;
					strcpy(log_name, "???????????? ?????????? ?????????????????? ????????????????????");
					log_name_counter = counter_cpu_request_inf;
				}
				if ((ID & mask_triple) == bloader_provide_inf) //???????????????????????????? ?????????? ?????????????????? ???????????????????? ?????? ?????????????????????????? ?????????????????? ???????? CAN (0x1F0)
				{
					if (ID == bloader_bus_off) //?????????????????????????? ?????????????????? ???????? CAN (0x1F00FFFF)
					{
						if (pos_bloader_bus_off < 0)
						{
							pos_bloader_bus_off = messages;
							messages++;
							grid->SetCellValue(pos_bloader_bus_off, 0, wxT("?????????????????????????? ?????????????????? ???????? CAN"));
						}
						counter_bloader_bus_off++;
						grid->SetCellValue(pos_bloader_bus_off, 3, wxString::Format(wxT("%d"), counter_bloader_bus_off));
						pos_table = pos_bloader_bus_off;
						strcpy(log_name, "?????????????????????????? ?????????????????? ???????? CAN");
						log_name_counter = counter_bloader_bus_off;
					}
					else //???????????????????????????? ?????????? ?????????????????? ????????????????????
					{
						if (pos_bloader_provide_inf < 0)
						{
							pos_bloader_provide_inf = messages;
							messages++;
							grid->SetCellValue(pos_bloader_provide_inf, 0, wxT("???????????????????????????? ?????????? ?????????????????? ????????????????????"));
						}
						counter_bloader_provide_inf++;
						grid->SetCellValue(pos_bloader_provide_inf, 3, wxString::Format(wxT("%d"), counter_bloader_provide_inf));
						pos_table = pos_bloader_provide_inf;
						strcpy(log_name, "???????????????????????????? ?????????? ?????????????????? ????????????????????");
						log_name_counter = counter_bloader_provide_inf;
						
						if ((ID & 0xF000) == 0)
							if ((ID & 0xFFF) != 0x555)
								id_with_error = true;
					}
				}
				if ((ID & mask_quatro) == cpu_send_data_ROM || (ID & mask_quatro) == cpu_send_data_Flash) //???????????????? ???????????? ???????????? (0x1C3F ?? 0x1CBF)
				{
					if (pos_cpu_send_data < 0)
					{
						pos_cpu_send_data = messages;
						messages++;
						grid->SetCellValue(pos_cpu_send_data, 0, wxT("???????????????? ???????????? ????????????"));
					}
					counter_cpu_send_data++;
					grid->SetCellValue(pos_cpu_send_data, 3, wxString::Format(wxT("%d"), counter_cpu_send_data));
					pos_table = pos_cpu_send_data;
					strcpy(log_name, "???????????????? ???????????? ????????????");
					log_name_counter = counter_cpu_send_data;
				}
				if ((ID & mask_quatro) == cpu_end_data_ROM || (ID & mask_quatro) == cpu_end_data_Flash) //C???????????????? ?? ???????????????? ???????????? ???????????? (0x1C2F ?? 0x1CAF)
				{
					if (pos_cpu_end_data < 0)
					{
						pos_cpu_end_data = messages;
						messages++;
						grid->SetCellValue(pos_cpu_end_data, 0, wxT("C???????????????? ?? ???????????????? ???????????? ????????????"));
					}
					counter_cpu_end_data++;
					grid->SetCellValue(pos_cpu_end_data, 3, wxString::Format(wxT("%d"), counter_cpu_end_data));
					pos_table = pos_cpu_end_data;
					strcpy(log_name, "C???????????????? ?? ???????????????? ???????????? ????????????");
					log_name_counter = counter_cpu_end_data;
				}
				if ((ID & mask_triple) == bloader_prgr_result_ROM || (ID & mask_triple) == bloader_prgr_result_Flash) //???????????? ???????????? ???????????? ?? ?????????????????? ???????????????????????????????? (0x1E2 ?? 0x1EA)
				{
					if ((ID & mask_quatro) == bloader_request_data_ROM || (ID & mask_quatro) == bloader_request_data_Flash) //???????????? ???????????? ???????????? (0x1E2F ?? 0x1EAF)
					{
						if (pos_bloader_request_data < 0)
						{
							pos_bloader_request_data = messages;
							messages++;
							grid->SetCellValue(pos_bloader_request_data, 0, wxT("???????????? ???????????? ????????????"));
						}
						counter_bloader_request_data++;
						grid->SetCellValue(pos_bloader_request_data, 3, wxString::Format(wxT("%d"), counter_bloader_request_data));
						pos_table = pos_bloader_request_data;
						strcpy(log_name, "???????????? ???????????? ????????????");
						log_name_counter = counter_bloader_request_data;
					}
					else //?????????????????? ???????????????????????????????? (0x1E2 ?? 0x1EA)
					{
						if (pos_bloader_prgr_result < 0)
						{
							pos_bloader_prgr_result = messages;
							messages++;
							grid->SetCellValue(pos_bloader_prgr_result, 0, wxT("?????????????????? ????????????????????????????????"));
						}
						counter_bloader_prgr_result++;
						grid->SetCellValue(pos_bloader_prgr_result, 3, wxString::Format(wxT("%d"), counter_bloader_prgr_result));
						pos_table = pos_bloader_prgr_result;
						strcpy(log_name, "?????????????????? ????????????????????????????????");
						log_name_counter = counter_bloader_prgr_result;
						
						if ((ID & 0xF0000) != 0)
							id_with_error = true;
					}
				}
				if ((ID & mask_quatro) == cpu_check_request_ROM || (ID & mask_quatro) == cpu_check_request_Flash) //???????????? ?????????????????? (0x1C40 ?? 0x1CC0)
				{
					if (pos_cpu_check_request < 0)
					{
						pos_cpu_check_request = messages;
						messages++;
						grid->SetCellValue(pos_cpu_check_request, 0, wxT("???????????? ??????????????????"));
					}
					counter_cpu_check_request++;
					grid->SetCellValue(pos_cpu_check_request, 3, wxString::Format(wxT("%d"), counter_cpu_check_request));
					pos_table = pos_cpu_check_request;
					strcpy(log_name, "???????????? ??????????????????");
					log_name_counter = counter_cpu_check_request;
				}
				if ((ID & mask_quatro) == cpu_transmit_data_smpl_ROM || (ID & mask_quatro) == cpu_transmit_data_smpl_Flash) //???????????????? ???????????? ???????????? ?????????????? (0x1C5F ?? 0x1CDF)
				{
					if (pos_cpu_transmit_data_smpl < 0)
					{
						pos_cpu_transmit_data_smpl = messages;
						messages++;
						grid->SetCellValue(pos_cpu_transmit_data_smpl, 0, wxT("???????????????? ???????????? ???????????? ??????????????"));
					}
					counter_cpu_transmit_data_smpl++;
					grid->SetCellValue(pos_cpu_transmit_data_smpl, 3, wxString::Format(wxT("%d"), counter_cpu_transmit_data_smpl));
					pos_table = pos_cpu_transmit_data_smpl;
					strcpy(log_name, "???????????????? ???????????? ???????????? ??????????????");
					log_name_counter = counter_cpu_transmit_data_smpl;
				}
				if ((ID & mask_quatro) == cpu_end_data_smpl_ROM || (ID & mask_quatro) == cpu_end_data_smpl_Flash) //?????????????????? ?? ???????????????? ???????????? ???????????? ?????????????? (0x1C4F ?? 0x1CCF)
				{
					if (pos_cpu_end_data_smpl < 0)
					{
						pos_cpu_end_data_smpl = messages;
						messages++;
						grid->SetCellValue(pos_cpu_end_data_smpl, 0, wxT("?????????????????? ?? ???????????????? ???????????? ???????????? ??????????????"));
					}
					counter_cpu_end_data_smpl++;
					grid->SetCellValue(pos_cpu_end_data_smpl, 3, wxString::Format(wxT("%d"), counter_cpu_end_data_smpl));
					pos_table = pos_cpu_end_data_smpl;
					strcpy(log_name, "?????????????????? ?? ???????????????? ???????????? ???????????? ??????????????");
					log_name_counter = counter_cpu_end_data_smpl;
				}
				if ((ID & mask_triple) == bloader_check_result_ROM || (ID & mask_triple) == bloader_check_result_Flash) //?????????????????? ?????????????????? ?? ???????????? ???????????? ???????????? ?????????????? (0x1E4 ?? 0x1EC)
				{
					if ((ID & mask_quatro) == bloader_request_data_smpl_ROM || (ID & mask_quatro) == bloader_request_data_smpl_Flash) //???????????? ???????????? ???????????? ?????????????? (0x1E4F ?? 0x1ECF)
					{
						if (pos_bloader_request_data_smpl < 0)
						{
							pos_bloader_request_data_smpl = messages;
							messages++;
							grid->SetCellValue(pos_bloader_request_data_smpl, 0, wxT("???????????? ???????????? ???????????? ??????????????"));
						}
						counter_bloader_request_data_smpl++;
						grid->SetCellValue(pos_bloader_request_data_smpl, 3, wxString::Format(wxT("%d"), counter_bloader_request_data_smpl));
						pos_table = pos_bloader_request_data_smpl;
						strcpy(log_name, "???????????? ???????????? ???????????? ??????????????");
						log_name_counter = counter_bloader_request_data_smpl;
					}
					else //?????????????????? ?????????????????? (0x1E4 ?? 0x1EC)
					{
						if (pos_bloader_check_result < 0)
						{
							pos_bloader_check_result = messages;
							messages++;
							grid->SetCellValue(pos_bloader_check_result, 0, wxT("?????????????????? ??????????????????"));
						}
						counter_bloader_check_result++;
						grid->SetCellValue(pos_bloader_check_result, 3, wxString::Format(wxT("%d"), counter_bloader_check_result));
						pos_table = pos_bloader_check_result;
						strcpy(log_name, "?????????????????? ??????????????????");
						log_name_counter = counter_bloader_check_result;
						
						if ((ID & 0xF0000) != 0)
							id_with_error = true;
					}
				}
				if ((ID & mask_triple) == cpu_transfer_ctrl_request) //???????????? ???????????????? ???????????????????? ???????????????? ???? (0x1C6)
				{
					if (pos_cpu_transfer_ctrl_request < 0)
					{
						pos_cpu_transfer_ctrl_request = messages;
						messages++;
						grid->SetCellValue(pos_cpu_transfer_ctrl_request, 0, wxT("???????????? ???????????????? ???????????????????? ???????????????? ????"));
					}
					counter_cpu_transfer_ctrl_request++;
					grid->SetCellValue(pos_cpu_transfer_ctrl_request, 3, wxString::Format(wxT("%d"), counter_cpu_transfer_ctrl_request));
					pos_table = pos_cpu_transfer_ctrl_request;
					strcpy(log_name, "???????????? ???????????????? ???????????????????? ???????????????? ????");
					log_name_counter = counter_cpu_transfer_ctrl_request;
				}
				if ((ID & mask_triple) == bloader_tr_ctrl_confirm) //?????????????????????????? ?????????????? ???????????????? ???????????????????? (0x1E6)
				{
					if (pos_bloader_tr_ctrl_confirm < 0)
					{
						pos_bloader_tr_ctrl_confirm = messages;
						messages++;
						grid->SetCellValue(pos_bloader_tr_ctrl_confirm, 0, wxT("?????????????????????????? ?????????????? ???????????????? ????????????????????"));
					}
					counter_bloader_tr_ctrl_confirm++;
					grid->SetCellValue(pos_bloader_tr_ctrl_confirm, 3, wxString::Format(wxT("%d"), counter_bloader_tr_ctrl_confirm));
					pos_table = pos_bloader_tr_ctrl_confirm;
					strcpy(log_name, "?????????????????????????? ?????????????? ???????????????? ????????????????????");
					log_name_counter = counter_bloader_tr_ctrl_confirm;
				}
				if ((ID & mask_quatro) == cpu_request_read_fl) //???????????? ?????????????????????? ???????????????????? (0x1CEF)
				{
					if (pos_cpu_request_read_fl < 0)
					{
						pos_cpu_request_read_fl = messages;
						messages++;
						grid->SetCellValue(pos_cpu_request_read_fl, 0, wxT("???????????? ?????????????????????? ????????????????????"));
					}
					counter_cpu_request_read_fl++;
					grid->SetCellValue(pos_cpu_request_read_fl, 3, wxString::Format(wxT("%d"), counter_cpu_request_read_fl));
					pos_table = pos_cpu_request_read_fl;
					strcpy(log_name, "???????????? ?????????????????????? ????????????????????");
					log_name_counter = counter_cpu_request_read_fl;
				}
				if ((ID & mask_quatro) == bloader_send_data_fl) //???????????????? ???????????? ???????????? (0x1EFF)
				{
					if (pos_bloader_send_data_fl < 0)
					{
						pos_bloader_send_data_fl = messages;
						messages++;
						grid->SetCellValue(pos_bloader_send_data_fl, 0, wxT("???????????????? ???????????? ????????????"));
					}
					counter_bloader_send_data_fl++;
					grid->SetCellValue(pos_bloader_send_data_fl, 3, wxString::Format(wxT("%d"), counter_bloader_send_data_fl));
					pos_table = pos_bloader_send_data_fl;
					strcpy(log_name, "???????????????? ???????????? ????????????");
					log_name_counter = counter_bloader_send_data_fl;
				}
				if ((ID & mask_quatro) == cpu_end_data_fl) //?????????????????? ?????????????????????? ???????????????????? (0x1CE0)
				{
					if (pos_cpu_end_data_fl < 0)
					{
						pos_cpu_end_data_fl = messages;
						messages++;
						grid->SetCellValue(pos_cpu_end_data_fl, 0, wxT("?????????????????? ?????????????????????? ????????????????????"));
					}
					counter_cpu_end_data_fl++;
					grid->SetCellValue(pos_cpu_end_data_fl, 3, wxString::Format(wxT("%d"), counter_cpu_end_data_fl));
					pos_table = pos_cpu_end_data_fl;
					strcpy(log_name, "?????????????????? ?????????????????????? ????????????????????");
					log_name_counter = counter_cpu_end_data_fl;
				}
				
				int j = i + 10;
				for (int n = 0; n < data_size; n++)
				{
					if (sReceivedChar[j] == '0')
						data_hex += "0";
					else
						data_hex.Append(sReceivedChar[j], 1);
					if (sReceivedChar[j + 1] == '0')
						data_hex += "0";
					else
						data_hex.Append(sReceivedChar[j + 1], 1);
					j += 2;
					i = j;
					if (n + 1 < data_size)
						data_hex += " ";
				}
				if (data_size == 0)
					i += 10;
				
				if (sReceivedChar[i] == '\r')
						i++;
			
				for (int j = 0, mask = 1; j < 29; j++)
				{
					if (ID & mask)
						buf[28 - j] = '1';
					else
						buf[28 - j] = '0';
					mask = mask << 1;
				}
				buf[29] = '\0';
	
				for (int j = 3, buf_counter = 0; j < 39; j++)
				{
					if ((j + 1) % 5 == 0)
						buf_tetr[j] = ' ';
					else
						buf_tetr[j] = buf[buf_counter++];
				}
				buf_tetr[39] = '\0';
				
				if (pos_table >= 0)
				{
					grid->SetCellValue(pos_table, 1, wxString(buf_tetr));
					grid->SetCellValue(pos_table, 2, data_hex);

					if (buf[3] == '1') //subscriber
						grid->SetCellValue(pos_table, 4, wxString(wxT("??????????????????-??????????????????")));
					else
						grid->SetCellValue(pos_table, 4, wxString(wxT("?????????????????????????????? ??????????????????")));
				}
				
				if (log_enable->GetValue())
				{
					log << counter << "\tID = " << std::hex << ID << std::dec << "\t";
					if (data_hex != "")
						log << "data = " << data_hex << "\t";
					else
						log << "no data\t\t\t\t";
					if (pos_table >= 0)
						log << log_name << "\t(" << log_name_counter << ")\n";
					else
						log << "?????????????????????? ??????????????????\n";
				}
				
				if (id_with_error == true)
				{
					if (error_control->GetValue())
					{
						grid->SetCellBackgroundColour(pos_table, 0, wxColour(255, 0, 0));
						log_error << counter << "\tID = " << std::hex << ID << std::dec << "\t";
						if (data_hex != "")
							log_error << "data = " << data_hex << "\t";
						else
							log_error << "no data\t\t\t\t";
						log_error << log_name << "\t(" << log_name_counter << ")\n";
					}
					id_with_error = false;
				}
				
				counter++;
				data_hex = "";
				pos_table = -1;
			}
			else
			{
				for (sReceivedChar_temp_last_byte = 0; i < iSize; i++, sReceivedChar_temp_last_byte++)
					sReceivedChar_temp[sReceivedChar_temp_last_byte] = sReceivedChar[i];
				i = iSize;
			}
		}
		else
		{
			for (sReceivedChar_temp_last_byte = 0; i < iSize; i++, sReceivedChar_temp_last_byte++)
				sReceivedChar_temp[sReceivedChar_temp_last_byte] = sReceivedChar[i];
			i = iSize;
		}
	}
	
	line += wxString::Format(wxT("cycle = %d, "), counter);
	line += wxString::Format(wxT("bytes readed = %d, "), iSize);
	line += wxString::Format(wxT("messages = %d"), messages);
	//st2->SetLabel(line);
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
		log.close();
		log_error.close();
		Destroy();
	}
	else
		event.Veto();
}