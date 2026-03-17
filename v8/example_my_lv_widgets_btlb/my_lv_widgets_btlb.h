#ifndef __MY_LV_WIDGETS_BTLB_H__
#define __MY_LV_WIDGETS_BTLB_H__

#include "lvgl.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    /*********************
     *      DEFINES
     *********************/

    /**********************
     *      TYPEDEFS
     **********************/

    typedef struct
    {
        lv_btn_t btn; /*Add the ancestor's type first*/
        lv_obj_t *label;
    } lv_btlb_t;

    extern const lv_obj_class_t lv_btlb_class;

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    /**
     * Create a btlb object
     * @param parent    pointer to an object, it will be the parent of the new btlb.
     * @return          pointer to the created btlb
     */
    lv_obj_t *lv_btlb_create(lv_obj_t *parent);

    void my_lv_btlb_set_label_text(lv_obj_t *obj, const char *text);
    void my_lv_btlb_set_label_color(lv_obj_t *obj, lv_color_t c);
    lv_obj_t *my_lv_btlb_get_label(lv_obj_t *obj);

    /*=====================
     * Setter functions
     *====================*/

    /*=====================
     * Getter functions
     *====================*/

    /**********************
     *      MACROS
     **********************/

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__MY_LV_WIDGETS_BTLB_H__
