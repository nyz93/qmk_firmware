#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "transactions.h"
#include "user_host.h"

typedef struct {
    uint8_t user_host_id;
} master_to_slave_t;
uint8_t current_user_host_id  = USER_HOST_MAC;
bool need_sync = false;

void raw_hid_receive(uint8_t* data, uint8_t length) {
    if (data[0] == 0x11) {
        current_user_host_id = data[1];
        need_sync = true;
    }
}

void housekeeping_task_user(void) {
    if (need_sync) {
        master_to_slave_t m2s = {current_user_host_id};
        if (transaction_rpc_send(USER_SYNC_HOST_OS, sizeof(m2s), &m2s)) {
            need_sync = false;
        }
    }
}
void user_sync_host_os_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t* m2s = (const master_to_slave_t*)in_data;
    current_user_host_id                     = m2s->user_host_id;
}
void user_init_host_sync(void) {
    transaction_register_rpc(USER_SYNC_HOST_OS, user_sync_host_os_handler);
}

uint8_t user_host_id(void) {
    return current_user_host_id;
}
