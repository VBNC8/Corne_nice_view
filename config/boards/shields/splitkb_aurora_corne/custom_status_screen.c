#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/output_status.h>
#include <zmk/display/widgets/layer_status.h>

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);

    // Batterie Links
    lv_obj_t *bat_l = zmk_widget_battery_status_init(screen);
    lv_obj_align(bat_l, LV_ALIGN_TOP_LEFT, 0, 0);

    // Batterie Rechts (wird durch PROXY/FETCHING gefüttert)
    lv_obj_t *bat_r = zmk_widget_battery_status_init(screen);
    lv_obj_align(bat_r, LV_ALIGN_TOP_RIGHT, 0, 0);

    // Output (Bluetooth/USB) & Layer
    zmk_widget_output_status_init(screen);
    zmk_widget_layer_status_init(screen);

    return screen;
}
