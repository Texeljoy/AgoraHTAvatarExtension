//
//  HTEffectARInterface.h
//  unityVidoCapture
//
//  Created by Eddie on 2023/2/20.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

/**
 * 视频帧格式
 *
 * 支持对BGRA、NV21、RGB、RGBA、NV12、I420格式的视频帧进行渲染
 */
typedef NS_ENUM(NSInteger, HTEARImageFormat) {
    RGB  = 0,
    RGBA = 1,
    BGR  = 2,
    BGRA = 3,
    NV12 = 4,
    NV21 = 5,
    I420 = 6,
    GRAY = 7
};

/**
 * 视频帧朝向
 */
typedef NS_ENUM(NSInteger, HTEAROrientation){
    CLOCKWISE_0 = 0,
    CLOCKWISE_90 = 90,
    CLOCKWISE_180 = 180,
    CLOCKWISE_270 = 270
};


@interface HTEffectARInterface :NSObject

#pragma mark - 单例

/**
 * 单例
 */
+ (instancetype)shareInstance;


- (void)initRuntime:(int)argc argv:(char **)argv;

-(void)copyResourceFrom:(NSString *)path;

#pragma mark - 初始化

/**
 * 初始化 - 离线授权
 *
 * @param license 离线鉴权license
 * @return 鉴权结果返回值
 */
- (int)initHTEffectAR:(NSString *)license;

#pragma mark - 渲染处理

/**
 * 设置渲染总开关
 *
 * @param renderEnable 开启为true， 关闭为false， 默认开启
 */
- (void)setRenderEnable:(BOOL)renderEnable;

/**
 * 设置图像是否存在镜像
 *
 * @param isMirror true存在， false不存在， 默认true
 */
-(void)setIsMirror:(BOOL)isMirror;

/**
 * 设置图像格式
 *
 * @param format 参考HTEARImageFormat
 */
-(void)setImageFormat:(HTEARImageFormat)format;

/**
 * 设置图像旋转角度
 *
 * @param rotation 参考HTEAROrientation
 */
-(void)setOrientation:(HTEAROrientation)orientation;

/**
 * 设置图像旋转角度
 *
 * @param maxFaces 人脸检测数目上限设置，推荐取值范围为1~5
 */
-(void)setMaxFaces:(int)maxFaces;

/**
 * 切换AR模型
 *
 * @param name 模型名称
 */
-(void)setModelName:(NSString *)name;

/**
 * 处理视频帧
 *
 * @param buffer 待渲染视频帧
 * @param width 视频帧宽度
 * @param height 视频帧高度
 */
- (void)processBuffer:(unsigned char *)buffer width:(int)width height:(int)height;

/**
 * 销毁buffer渲染资源
 */
- (void)releaseBufferRenderer;

@end


