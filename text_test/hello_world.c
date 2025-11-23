#include <furi.h>
#include <gui/gui.h>

static void draw_callback(Canvas* canvas, void* ctx) {
    UNUSED(ctx);
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 10, 32, "Hello, Flipper!");
}

int32_t text_test_app(void* p) {
    UNUSED(p);
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* vp = view_port_alloc();

    view_port_draw_callback_set(vp, draw_callback, NULL);
    gui_add_view_port(gui, vp, GuiLayerFullscreen);

    while(!furi_hal_buttons_is_pressed(FuriHalButtonsBack)) {
        furi_delay_ms(50);
    }

    gui_remove_view_port(gui, vp);
    view_port_free(vp);
    furi_record_close(RECORD_GUI);
    return 0;
}
