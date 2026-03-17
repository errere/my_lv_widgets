/*
a label in button
*/

/*********************
 *      INCLUDES
 *********************/
#include "my_lv_btlb.h"

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS &my_btlb_class

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_btlb_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void my_btlb_event_cb(const lv_obj_class_t *class_p, lv_event_t *e);
/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t my_btlb_class = {
    .base_class = &lv_button_class,
    .width_def = LV_SIZE_CONTENT,
    .height_def = LV_SIZE_CONTENT,
    .constructor_cb = my_btlb_constructor,
    .event_cb = my_btlb_event_cb,
    .instance_size = sizeof(lv_my_btlb_t),
    .theme_inheritable = LV_OBJ_CLASS_THEME_INHERITABLE_TRUE // inherit theme from base class
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t *my_lv_btlb_create(lv_obj_t *parent)
{
    LV_LOG_INFO("begin");

    lv_obj_t *obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);

    return obj;
} // my_lv_btlb_create

void my_lv_btlb_set_label_text(lv_obj_t *obj, const char *text)
{
    lv_label_set_text(((lv_my_btlb_t *)obj)->txt, text);
} // my_lv_btlb_set_label_text

void my_lv_btlb_set_label_color(lv_obj_t *obj, lv_color_t c)
{
    lv_obj_set_style_text_color(((lv_my_btlb_t *)obj)->txt, c, 0);
} // my_lv_btlb_set_label_color

lv_obj_t *my_lv_btlb_get_label(lv_obj_t *obj)
{
    return ((lv_my_btlb_t *)obj)->txt;
} // my_lv_btlb_get_label

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void my_btlb_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    /* 你自己的初始化 */
    lv_my_btlb_t *btlb = (lv_my_btlb_t *)obj;
    btlb->txt = lv_label_create(obj);
    lv_obj_center(btlb->txt);
} // my_btlb_constructor

static void my_btlb_event_cb(const lv_obj_class_t *class_p, lv_event_t *e)
{

    /*Call the ancestor's event handler*/
    lv_event_code_t code = lv_event_get_code(e);
    lv_result_t res = lv_obj_event_base(MY_CLASS, e);
    if (res != LV_RESULT_OK)
    {
        return;
    } //! LV_RESULT_OK

    if (code == LV_EVENT_SIZE_CHANGED || code == LV_EVENT_STYLE_CHANGED || code == LV_EVENT_LAYOUT_CHANGED)
    {
        lv_obj_t *obj = lv_event_get_target(e);
        lv_my_btlb_t *btlb = (lv_my_btlb_t *)obj;

        lv_obj_center(btlb->txt);
    } // code

} // my_btlb_event_cb

// eof
