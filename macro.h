/*
    https://github.com/sl-sl-sl-sl-sl/Macro.git
 
 补充
 http://nshipster.com/__attribute__/
 https://blog.twitter.com/2014/attribute-directives-in-objective-c
 http://blog.sunnyxx.com/2014/09/15/objc-attribute-cleanup/
 */


















// 在方法后面添加, 什么此方法不可使用
UNAVAILABLE_ATTRIBUTE
__attribute__ ((unavailable("<#DESCRIPTION#>")))
NS_CLASS_AVAILABLE_IOS(9_0)
__attribute__ (availability())

// 子类继承此类需要调用super
NS_REQUIRES_SUPER
__attribute__((objc_requires_super))

// 在@interface前面添加, 声明此类不可继承
objc_subclassing_restricted


/*
    @(...) 语法糖
     typedef struct __attribute__((objc_boxable)) {
     CGFloat x, y, width, height;
     } XXRect;
 
    XXRect rect2 = {1, 2, 3, 4};
    NSValue *value2 = @(rect2);
 */
__attribute__((objc_boxable))


/*
 用于 @interface 或 @protocol，将类或协议的名字在编译时指定成另一个：
 __attribute__((objc_runtime_name("SarkGay")))
 @interface Sark : NSObject
 @end
 
 NSLog(@"%@", NSStringFromClass([Sark class])); // "SarkGay"
 */
__attribute__((objc_runtime_name("<#OtherClassName#>")))






/*
    constructor 构造器 在+load之后 main之前加载
    destructor 在main之后加载
 */
__attribute__((constructor))
static void beforeMain(void) {
    NSLog(@"beforeMain");
}
__attribute__((destructor))
static void afterMain(void) {
    NSLog(@"afterMain");
}

__attribute__((constructor(101))) // 越小优先级越高

/*
    若干个函数名相同, 参数不同, 根据参数选择函数, 只能用于C函数
 */
__attribute__((overloadable)) void logAnything(id obj) {
    NSLog(@"%@", obj);
}
__attribute__((overloadable)) void logAnything(int number) {
    NSLog(@"%@", @(number));
}
__attribute__((overloadable)) void logAnything(CGRect rect) {
    NSLog(@"%@", NSStringFromCGRect(rect));
}


















