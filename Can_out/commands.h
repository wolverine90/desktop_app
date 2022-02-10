#ifndef __COMMANDS_H__
#define __COMMANDS_H__

/*-----Маски Идентификатора----*/
#define subscriber        0xFDFFFFFF
#define common_mark       0xFEFFFFFF
#define action            0xFF1FFFFF
#define action_mark       0xFFEFFFFF
#define action_result     0xFFF0FFFF
#define common_inf        0xFFFF0000


/*-----Общая Служебная Информация-----*/

#define cpu_request_inf           0x1D000000    // запрос общей служебной информации      //data = 0
#define cpu_request_m             0xFFFF0FFF

#define bloader_provide_inf       0x1F000000    // предоставление общей служебной информации    //data = 0
#define bloader_provide_inf_m     0xFFFF0000

#define bloader_bus_off           0x1F00FFFF    // фиксированное состояние шины CAN       //data = 0


/*-----Действия с Flash-----*/

// СТИРАНИЕ ROM             //if EEPROM do cpu_command & action then command | 0x00800000
#define cpu_request_erase_fl_ROM      0x1C000000    // запрос стирания_ROM                        //data = 0
#define cpu_request_erase_fl_Flash    0x1C800000    // запрос стирания_Flash

#define bloader_erase_rslt_ROM          0x1E000000    // результат стирания                     //data = 0 if error data = 8
#define bloader_erase_rslt_Flash        0x1E800000    // результат стирания                     //data = 0 if error data = 8
#define bloader_erase_rslt_m      0xFFF0FFFF 
#define bloader_ers_rslt_d_m_err  0xFFFFFFFFFFFF0000


//ПРОГРАММИРОВАНИЕ ROM      //if EEPROM do cpu_command & action then command | 0x00A00000
#define cpu_request_prgrm_fl_ROM	0x1C200000    // запрос программирования ROM               //data = 8
#define cpu_request_prgrm_fl_Flash	0x1CA00000	  // запрос программирования Flash
#define cpu_prgrm_data_size       0xFFFFFFFFFFFF0001

#define bloader_request_data_ROM      0x1E2F0000    // запрос пакета данных_ROM                   //data = 0
#define bloader_request_data_Flash    0x1EAF0000    // запрос пакета данных_Flash
#define bloader_request_data_m    0xFFFF0000

#define cpu_send_data_ROM             0x1C3F0000    // передача пакета данных_ROM    //multiple   //data = 8 
#define cpu_send_data_Flash           0x1CBF0000    // передача пакета данных_Flash
#define cpu_send_data_m           0xFFFFFF00

#define cpu_end_data_ROM              0x1C2F0000    // сообщение о передаче пакета данных_ROM     //data = 0
#define cpu_end_data_Flash            0x1CAF0000    // сообщение о передаче пакета данных_Flash
#define cpu_end_data_m            0xFFFF0000

#define bloader_prgr_result_ROM       0x1E200000    // результат программирования_ROM             //data = 0 if error data = 8
#define bloader_prgr_result_Flash     0x1EA00000    // результат программирования_Flash
#define bloader_prgr_resul_m      0xFFF0FFFF
#define bloader_prgr_m_data_err   0xFFFFFFFFFFFF0000        


//СРАВНЕНИЕ ROM             //if EEPROM do cpu_command & action then command | 0x00C00000
#define cpu_check_request_ROM         0x1C400000    // запрос сравнения_ROM                       //data = 8
#define cpu_check_request_Flash       0x1CC00000    // запрос сравнения_Flash
#define cpu_check_data_smpl       0xFFFFFFFFFFFF0001

#define bloader_request_data_smpl_ROM   0x1E4F0000    // запрос пакета данных образца_ROM           //data = 0
#define bloader_request_data_smpl_Flash 0x1ECF0000    // запрос пакета данных образца_Flash
#define bloader_rqst_data_smpl_m  0xFFFF0000

#define cpu_transmit_data_smpl_ROM      0x1C5F0000    // передача пакета данных образца_ROM //multiple    //data = 8
#define cpu_transmit_data_smpl_Flash    0x1CDF0000    // передача пакета данных образца_Flash
#define cpu_transmit_data_smpl_m  0xFFFFFFC0

#define cpu_end_data_smpl_ROM         0x1C4F0000    // сообщение о передаче пакета данных образца_ROM   //data = 0
#define cpu_end_data_smpl_Flash       0x1CCF0000    // сообщение о передаче пакета данных образца_Flash
#define cpu_end_data_smpl_m       0xFFFF0000

#define bloader_check_result_ROM      0x1E400000    // результат сравнения_ROM                    //data = 0 if error data = 8
#define bloader_check_result_Flash    0x1EC00000    // результат сравнения_Flash
#define bloader_check_data_err    0xFFFFFFFFFFFF0000


//ПЕРЕДАЧА УПРАВЛЕНИЯ ШТАТНОМУ ПО
#define cpu_transfer_ctrl_request 0x1C600000    // запрос передачи управления штатному ПО //data = 01
#define bloader_tr_ctrl_confirm   0x1E600000    // подтверждение запроса передачи управления //data = 0


//ВЫЧИТЫВАНИЕ ИНФОРМАЦИИ EEPROM
#define cpu_request_read_fl       0x1CEF0000    // запрос вычитывания                        //data = 0
#define cpu_request_read_fl_m     0xFFFF0000

#define bloader_send_data_fl      0x1EFF0000    // передача пакета данных    //multiple   //data = 8 
#define bloader_send_data_fl_     0xFFFF0000

#define cpu_end_data_fl           0x1CE00000    // окончание вычитывания информации       //data = 0

#define bloader_data_fl_err       0x1E0E0000    // ошибка вычитывания/сбой последовательности пакетов //data = 0

#endif
