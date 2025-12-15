#ifndef __MY_LV_BTLB_H__
#define __MY_LV_BTLB_H__

#ifdef __cplusplus
extern "C"
{
#endif

    /*********************
     *      INCLUDES
     *********************/
#include "lvgl.h"
#include "lvgl-9.4.0/src/core/lv_obj_private.h"
#include "lvgl-9.4.0/src/widgets/button/lv_button_private.h"

/*Testing of dependencies*/
#if LV_USE_LABEL == 0
#error "lv_label is required. Enable it in lv_conf.h (LV_USE_LABEL  1) "
#endif

    /*********************
     *      DEFINES
     *********************/

    /**********************
     *      TYPEDEFS
     **********************/

    typedef struct
    {
        lv_button_t obj; /**< Add the ancestor's type first */
        // lv_obj_t *btn;
        lv_obj_t *txt;

    } lv_my_btlb_t;

    extern const lv_obj_class_t my_btlb_class;

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    lv_obj_t *my_btlb_create(lv_obj_t *parent);

    /**********************
     *      MACROS
     **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif