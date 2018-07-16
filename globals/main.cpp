#include <phpcpp.h>
#include <iostream>

//打印$_SERVER全局变量
void dump_server_vars()
{
	Php::out << "PHP_SELF: " << Php::SERVER["PHP_SELF"] << "<BR>";
	Php::out << "REMOTE_ADDR: " << Php::SERVER["REMOTE_ADDR"] << "<BR>";
	Php::out << "SERVER_NAME: " << Php::SERVER["SERVER_NAME"] << "<BR>";
	Php::out << "HTTP_REFERER: " << Php::SERVER["HTTP_REFERER"] << "<BR>";
}

//打印$_GET全局变量
void dump_get_vars()
{
	Php::out << "PHP_SELF: " << Php::SERVER["PHP_SELF"] << "<BR>";
	Php::out << "REMOTE_ADDR: " << Php::SERVER["REMOTE_ADDR"] << "<BR>";
	Php::out << "SERVER_NAME: " << Php::SERVER["SERVER_NAME"] << "<BR>";
	Php::out << "HTTP_REFERER: " << Php::SERVER["HTTP_REFERER"] << "<BR>";
}

//打印$_POST全局变量
void dump_post_vars()
{
	Php::out << "PHP_SELF: " << Php::SERVER["PHP_SELF"] << "<BR>";
	Php::out << "REMOTE_ADDR: " << Php::SERVER["REMOTE_ADDR"] << "<BR>";
	Php::out << "SERVER_NAME: " << Php::SERVER["SERVER_NAME"] << "<BR>";
	Php::out << "HTTP_REFERER: " << Php::SERVER["HTTP_REFERER"] << "<BR>";
}

//打印$_REQUEST全局变量
void dump_request_vars()
{
	Php::out << "PHP_SELF: " << Php::SERVER["PHP_SELF"] << "<BR>";
	Php::out << "REMOTE_ADDR: " << Php::SERVER["REMOTE_ADDR"] << "<BR>";
	Php::out << "SERVER_NAME: " << Php::SERVER["SERVER_NAME"] << "<BR>";
	Php::out << "HTTP_REFERER: " << Php::SERVER["HTTP_REFERER"] << "<BR>";
}

//打印$_FILES全局变量
void dump_files_vars()
{
	Php::out << "PHP_SELF: " << Php::SERVER["PHP_SELF"] << "<BR>";
	Php::out << "REMOTE_ADDR: " << Php::SERVER["REMOTE_ADDR"] << "<BR>";
	Php::out << "SERVER_NAME: " << Php::SERVER["SERVER_NAME"] << "<BR>";
	Php::out << "HTTP_REFERER: " << Php::SERVER["HTTP_REFERER"] << "<BR>";
}

//打印$_GLOBALS全局变量
void dump_globals_vars()
{
	Php::out << "PHP_SELF: " << Php::SERVER["PHP_SELF"] << "<BR>";
	Php::out << "REMOTE_ADDR: " << Php::SERVER["REMOTE_ADDR"] << "<BR>";
	Php::out << "SERVER_NAME: " << Php::SERVER["SERVER_NAME"] << "<BR>";
	Php::out << "HTTP_REFERER: " << Php::SERVER["HTTP_REFERER"] << "<BR>";
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
        static Php::Extension extension("myglobals", "1.0.0");
        
        //这里可以添加你要暴露给PHP调用的函数
		extension.add<dump_server_vars>("dump_server_vars");
		
        // 返回扩展对象指针
        return extension;
    }
}
