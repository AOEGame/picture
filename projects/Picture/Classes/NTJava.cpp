#include "NTJava.h"

#include <cstring>
#include <vector>
#include <jni.h>
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

using cocos2d::JniMethodInfo;
using cocos2d::JniHelper;

namespace NTJava
{

static const char *addReturnSig(const char *sig, const char *ret)
{
	const int n = 2048;
	static char buffer[n];
	if (sig[0] == '(') {
		return sig;
	}
	int r = snprintf(buffer, n, "(%s)%s", sig, ret);
	CCAssert(r < n, "buffer is too short");
	return buffer;
}

static std::vector<int> countArgs(const char *sig)
{
	std::vector<int> v(1, 0);
	const char *p = sig + 1;
	while (*p != ')') {
		if (*p == 'L') {
			CCAssert(!strncmp("Ljava/lang/String;", p, 18), "only support string object");
			p += 17;
			v.push_back(v[0]);
		}
		p++;
		v[0]++;
	}
	return v;
}

static jvalue *generateArgs(JniMethodInfo &minfo, const char *sig, va_list args)
{
	std::vector<int> v = countArgs(sig);
	if (!v[0]) {
		return NULL;
	}
	jvalue *jargs = new jvalue[v[0]];
	const char *p = sig + 1;
	int i = 0;
	while (*p != ')') {
		switch (*p) {
		case 'Z':
			jargs[i].z = (jboolean)va_arg(args, int);
			break;
		case 'B':
			jargs[i].b = (jchar)va_arg(args, int);
			break;
		case 'C':
			jargs[i].c = (jchar)va_arg(args, int);
			break;
		case 'S':
			jargs[i].s = (jshort)va_arg(args, int);
			break;
		case 'I':
			jargs[i].i = (jint)va_arg(args, int);
			break;
		case 'J':
			jargs[i].j = (jlong)va_arg(args, long);
			break;
		case 'F':
			jargs[i].f = (jfloat)va_arg(args, double);
			break;
		case 'D':
			jargs[i].d = (jdouble)va_arg(args, double);
			break;
		case 'L': {
			CCAssert(!strncmp("Ljava/lang/String;", p, 18), "only support string object");
			p += 17;
			const char *str = va_arg(args, char *);
			/*
			按文档NewStringUTF传入的字符串应该是modified UTF-8，C++中使用的是标准的UTF-8，需要转换
			不过两者的区别在于\x00和基本多文种平面之外字符，应该不会用到这些，所以不转换应该也可以
			2dx引擎中类似的调用也没有转换
			https://zh.wikipedia.org/wiki/UTF-8#.E8.AE.8A.E7.A8.AEUTF-8
			*/
			jargs[i].l = minfo.env->NewStringUTF(str);
			break;
		}
		default:
			char buf[128];
			snprintf(buf, 128, "unsupport type %s", p);
			CCAssert(false, buf);
		}
		i++;
		p++;
	}
	return jargs;
}

static void releaseJString(JniMethodInfo &minfo, const char *sig, const jvalue *jargs)
{
	std::vector<int> v = countArgs(sig);
	if (v.size() > 1) {
		for (int i = 1; i < v.size(); i++) {
			minfo.env->DeleteLocalRef(jargs[v[i]].l);
		}
	}
}

void callStaticVoidMethod(const char *pkg, const char *method, const char *sig, ...)
{
	JniMethodInfo minfo;
	const char *fullsig = addReturnSig(sig, "V");
	JniHelper::getStaticMethodInfo(minfo, pkg, method, fullsig);

	va_list args;
	va_start(args, sig);
	jvalue *jargs = generateArgs(minfo, fullsig, args);
	va_end(args);

	minfo.env->CallStaticVoidMethodA(minfo.classID, minfo.methodID, jargs);
	releaseJString(minfo, fullsig, jargs);
	delete []jargs;
	minfo.env->DeleteLocalRef(minfo.classID);
}

std::string callStaticStringMethod(const char *pkg, const char *method, const char *sig, ...)
{
	JniMethodInfo minfo;
	const char *fullsig = addReturnSig(sig, "Ljava/lang/String;");
	JniHelper::getStaticMethodInfo(minfo, pkg, method, fullsig);

	va_list args;
	va_start(args, sig);
	jvalue *jargs = generateArgs(minfo, fullsig, args);
	va_end(args);

	jstring ret = (jstring)minfo.env->CallStaticObjectMethodA(minfo.classID, minfo.methodID, jargs);
	std::string str = JniHelper::jstring2string(ret);
	releaseJString(minfo, fullsig, jargs);
	delete []jargs;
	minfo.env->DeleteLocalRef(minfo.classID);
	minfo.env->DeleteLocalRef(ret);
	return str;
}

int callStaticIntMethod(const char *pkg, const char *method, const char *sig, ...)
{
	JniMethodInfo minfo;
	const char *fullsig = addReturnSig(sig, "I");
	JniHelper::getStaticMethodInfo(minfo, pkg, method, fullsig);

	va_list args;
	va_start(args, sig);
	jvalue *jargs = generateArgs(minfo, fullsig, args);
	va_end(args);

	jint ret = minfo.env->CallStaticIntMethodA(minfo.classID, minfo.methodID, jargs);
	releaseJString(minfo, fullsig, jargs);
	delete []jargs;
	minfo.env->DeleteLocalRef(minfo.classID);
	return (int)ret;
}

bool callStaticBoolMethod(const char *pkg, const char *method, const char *sig, ...)
{
	JniMethodInfo minfo;
	const char *fullsig = addReturnSig(sig, "Z");
	JniHelper::getStaticMethodInfo(minfo, pkg, method, fullsig);

	va_list args;
	va_start(args, sig);
	jvalue *jargs = generateArgs(minfo, fullsig, args);
	va_end(args);

	jboolean ret = minfo.env->CallStaticBooleanMethodA(minfo.classID, minfo.methodID, jargs);
	releaseJString(minfo, fullsig, jargs);
	delete []jargs;
	minfo.env->DeleteLocalRef(minfo.classID);
	return (bool)ret;
}
}
