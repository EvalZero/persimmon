/*
 * File      : pm_switch_button.h
 * COPYRIGHT (C) 2012-2017, Shanghai Real-Thread Technology Co., Ltd
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-11-05     realthread   the first version
 */

#pragma once

#include <vector>
#include <pm_widget.h>
#include <pm_image.h>
#include "sigslot.h"
#include <pm_timer.h>

namespace Persimmon
{

class SwitchButton : public Widget
{
public:
    SwitchButton(const Rect& rect);
    virtual ~SwitchButton();

    void setSwitchBackImage(Image *norImg, Image *selImg)
    {
        if (norBackImage)
            delete norBackImage;

        if (selBackImage)
            delete selBackImage;

        norBackImage = norImg;
        selBackImage = selImg;
    }

    void setSwitchSliderImage(Image *norImg, Image *selImg)
    {
        if (norSliderImage)
            delete norSliderImage;

        if (selSliderImage)
            delete selSliderImage;

        norSliderImage = norImg;
        selSliderImage = selImg;
    }

    void selectEnable(bool sel = true)
    {
        select = sel;
    }

    Signal<bool> clicked;

    virtual bool handleGestureEvent(struct rtgui_event_gesture *, const struct rtgui_gesture *);    //触摸手势事件处理函数
    
    virtual void render(struct rtgui_dc* dc, const Point &dcPoint = Point(),
                        const Rect &srcRect = Rect(),
                        RenderFlag flags = DrawNormal);

private:
    void onAnimation(void);

    Image *norBackImage, *selBackImage;
    Image *norSliderImage, *selSliderImage;
    int index;
    bool select, animation;
    Timer *animationTimer;
};

}
