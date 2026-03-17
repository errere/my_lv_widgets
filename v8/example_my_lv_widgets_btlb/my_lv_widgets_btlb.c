#include "my_lv_widgets_btlb.h"

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS &lv_btlb_class

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void lv_btlb_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void lv_btlb_event(const lv_obj_class_t *class_p, lv_event_t *e);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_btlb_class = {
    .base_class = &lv_btn_class,
    .width_def = LV_SIZE_CONTENT,
    .height_def = LV_SIZE_CONTENT,
    .constructor_cb = lv_btlb_constructor,
    .event_cb = lv_btlb_event,
    .editable = LV_OBJ_CLASS_EDITABLE_INHERIT,
    .group_def = LV_OBJ_CLASS_GROUP_DEF_INHERIT,
    .instance_size = sizeof(lv_btlb_t),
}; // lv_btlb_class

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t *lv_btlb_create(lv_obj_t *parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t *obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
} // lv_btlb_create


void my_lv_btlb_set_label_text(lv_obj_t *obj, const char *text)
{
    lv_label_set_text(((lv_btlb_t *)obj)->label, text);
} // my_lv_btlb_set_label_text

void my_lv_btlb_set_label_color(lv_obj_t *obj, lv_color_t c)
{
    lv_obj_set_style_text_color(((lv_btlb_t *)obj)->label, c, 0);
} // my_lv_btlb_set_label_color

lv_obj_t *my_lv_btlb_get_label(lv_obj_t *obj)
{
    return ((lv_btlb_t *)obj)->label;
} // my_lv_btlb_get_label


/**********************
 *   STATIC FUNCTIONS
 **********************/
static void lv_btlb_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    LV_UNUSED(class_p);
    lv_btlb_t *btlb = (lv_btlb_t *)obj;

    //https://forum.lvgl.io/t/how-do-i-apply-the-current-theme-to-my-custom-widget/13319/2
    // add themes need fix library
    // this problem fix in v9 with arg "theme_inheritable"
    my_default_theme_styles_t *styles = lv_theme_default_get_styles();
    lv_obj_add_style(obj, &styles->btn, 0);
    lv_obj_add_style(obj, &styles->bg_color_primary, 0);
    lv_obj_add_style(obj, &styles->transition_delayed, 0);
    lv_obj_add_style(obj, &styles->pressed, LV_STATE_PRESSED);
    lv_obj_add_style(obj, &styles->transition_normal, LV_STATE_PRESSED);
    lv_obj_add_style(obj, &styles->outline_primary, LV_STATE_FOCUS_KEY);
#if LV_THEME_DEFAULT_GROW
    lv_obj_add_style(obj, &styles->grow, LV_STATE_PRESSED);
#endif
    lv_obj_add_style(obj, &styles->bg_color_secondary, LV_STATE_CHECKED);
    lv_obj_add_style(obj, &styles->disabled, LV_STATE_DISABLED);

    btlb->label = lv_label_create(obj);
    lv_obj_center(btlb->label);

} // lv_btlb_constructor

static void lv_btlb_event(const lv_obj_class_t *class_p, lv_event_t *e)
{
    LV_UNUSED(class_p);

    lv_res_t res;

    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(MY_CLASS, e);
    if (res != LV_RES_OK)
        return;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    lv_btlb_t *self = (lv_btlb_t *)obj;

    if (code == LV_EVENT_SIZE_CHANGED || code == LV_EVENT_STYLE_CHANGED || code == LV_EVENT_LAYOUT_CHANGED)
    {
        lv_obj_t *obj = lv_event_get_target(e);
        lv_btlb_t *btlb = (lv_btlb_t *)obj;

        lv_obj_center(btlb->label);
    } // code
} // lv_btlb_event

// eof
