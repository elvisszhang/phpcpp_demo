#include <phpcpp.h>
#include <iostream>

//这是PHP里面可以调用的接口函数
void say_hello()
{
	//输出一段欢迎文字
	Php::out << "hello world from my first extension" << std::endl;
}

/**
 *  告诉编译器get_module是个纯C函数
 */
extern "C" {
    
    /**
     *  本函数在PHP进程一打开就会被访问，并返回一个描述扩展信息的PHP结构指针
     */
    PHPCPP_EXPORT void *get_module() 
    {
        // 必须是static类型，因为扩展对象需要在PHP进程内常驻内存
        static Php::Extension extension("helloworld", "1.0.0");
        
        //这里可以添加你要暴露给PHP调用的函数
		extension.add<say_hello>("say_hello");
		
        // 返回扩展对象指针
        return extension;
    }
}
