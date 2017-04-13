//
//  SGPageTitleView.h
//  SGPageViewExample
//
//  Created by apple on 17/4/10.
//  Copyright © 2017年 Sorgle. All rights reserved.
//

#import <UIKit/UIKit.h>
@class SGPageTitleView;

typedef enum : NSUInteger {
    SGIndicatorTypeDefault, /// 指示器默认长度与按钮宽度相等
    SGIndicatorTypeEqual, /// 指示器宽度等于按钮文字宽度
} SGIndicatorType;

@protocol SGPageTitleViewDelegate <NSObject>
/// pageTitleViewDelegate
- (void)SGPageTitleView:(SGPageTitleView *)SGPageTitleView selectedIndex:(NSInteger)selectedIndex;

@end

@interface SGPageTitleView : UIView
/**
 *  对象方法创建 SGPageTitleView
 *
 *  @param frame     frame
 *  @param titleNames     标题数组
 */
- (instancetype)initWithFrame:(CGRect)frame titleNames:(NSArray *)titleNames;
/**
 *  类方法创建 SGPageTitleView
 *
 *  @param frame     frame
 *  @param titleNames     标题数组
 */
+ (instancetype)pageTitleViewWithFrame:(CGRect)frame titleNames:(NSArray *)titleNames;

/** pageTitleViewDelegate */
@property (nonatomic, weak) id<SGPageTitleViewDelegate> pageTitleViewDelegate;

/** 选中的按钮下标, 如果这个属性和 indicatorStyle 属性同时存在，则此属性在前 */
@property (nonatomic, assign) NSInteger selectedIndex;
/** 指示器样式 */
@property (nonatomic, assign) SGIndicatorType indicatorStyle;
/** 是否让标题有渐变效果，默认为 YES */
@property (nonatomic, assign) BOOL isTitleGradientEffect;
/** 是否让指示器滚动，默认为跟随内容的滚动而滚动 */
@property (nonatomic, assign) BOOL isIndicatorScroll;
/** 是否显示指示器，默认为 YES */
@property (nonatomic, assign) BOOL isShowIndicator;
/** 是否需要弹性效果，默认为 YES */
@property (nonatomic, assign) BOOL isNeedBounces;

/** 给外界提供的方法，获取 SGContentView 的 progress／originalIndex／targetIndex, 必须实现 */
- (void)setSegmentedControlWithProgress:(CGFloat)progress originalIndex:(NSInteger)originalIndex targetIndex:(NSInteger)targetIndex;

@end
