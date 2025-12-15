

/*********************
 *      INCLUDES
 *********************/
#include "my_lv_btlb.h"
#include "lvgl-9.4.0/src/core/lv_obj_class_private.h"
#include "lvgl-9.4.0/src/widgets/button/lv_button_private.h"

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS &my_btlb_class

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static void my_btlb_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);

const lv_obj_class_t my_btlb_class = {
    .base_class = &lv_button_class,
    .width_def = LV_SIZE_CONTENT,
    .height_def = LV_SIZE_CONTENT,
    .constructor_cb = my_btlb_constructor,
    .instance_size = sizeof(lv_my_btlb_t),
    .theme_inheritable = LV_OBJ_CLASS_THEME_INHERITABLE_TRUE // inherit theme from base class
};

static void my_btlb_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    /* 你自己的初始化 */
    lv_my_btlb_t *btlb = (lv_my_btlb_t *)obj;
    btlb->txt = lv_label_create(obj);
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t *my_btlb_create(lv_obj_t *parent)
{
    LV_LOG_INFO("begin");

    lv_obj_t *obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}


// eof
