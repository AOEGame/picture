

#ifndef __Picture__NTJava__
#define __Picture__NTJava__

#include <string>

namespace NTJava
{
/** @breif 调用java的类静态函数
@param pkg java包名
@param method 方法名
@param sig 方法签名，因为已知道无返回值，所以可以只写参数的类型，即"(II)V"可以简写成"II", "()V"可以写为""
@param ... java方法的参数
@warning 参数的类型要和签名的类型一致，如果签名为整形，传入的参数为浮点型则会出错
*/

void callStaticVoidMethod(const char*pkg, const char *method, const char *sig, ...);
std::string callStaticStringMethod(const char *pkg, const char *method, const char *sig, ...);
int callStaticIntMethod(const char *pkg, const char *method, const char *sig, ...);
bool callStaticBoolMethod(const char *pkg, const char *method, const char *sig, ...);

}

#endif /* defined(__Picture__NTJava__) */
