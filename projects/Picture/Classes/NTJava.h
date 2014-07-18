

#ifndef __Picture__NTJava__
#define __Picture__NTJava__

#include <string>

namespace NTJava
{
/** @breif ����java���ྲ̬����
@param pkg java����
@param method ������
@param sig ����ǩ������Ϊ��֪���޷���ֵ�����Կ���ֻд���������ͣ���"(II)V"���Լ�д��"II", "()V"����дΪ""
@param ... java�����Ĳ���
@warning ����������Ҫ��ǩ��������һ�£����ǩ��Ϊ���Σ�����Ĳ���Ϊ������������
*/

void callStaticVoidMethod(const char*pkg, const char *method, const char *sig, ...);
std::string callStaticStringMethod(const char *pkg, const char *method, const char *sig, ...);
int callStaticIntMethod(const char *pkg, const char *method, const char *sig, ...);
bool callStaticBoolMethod(const char *pkg, const char *method, const char *sig, ...);

}

#endif /* defined(__Picture__NTJava__) */
