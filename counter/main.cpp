#include <phpcpp.h>
#include <time.h>

//扩展的导出类 Counter
class Counter : public Php::Base
{
private:
    int _value = 0;
public:
    Counter() = default;
    virtual ~Counter() = default;
	//类的普通成员函数
    Php::Value increment() { return ++_value; }
    Php::Value decrement() { return --_value; }
    Php::Value value() const { return _value; }
    //类的静态成员函数
    static Php::Value gettime() {return (int)time(NULL);}
};

//告诉编译器get_module是个纯C函数
extern "C" {
	//get_module是扩展的入口函数
    PHPCPP_EXPORT void *get_module() {
        static Php::Extension myExtension("counter", "1.0.0");
		
		//初始化导出类
        Php::Class<Counter> counter("Counter");
		
		//注册导出类的可访问普通函数
        counter.method<&Counter::increment> ("increment");
        counter.method<&Counter::decrement> ("decrement");
        counter.method<&Counter::value> ("value");
        
        //注册导出类的可访问静态函数
        counter.method<&Counter::gettime>("gettime");

		//注册导出类，使用右值引用方式，优化资源使用
        myExtension.add(std::move(counter));
		
		//返回扩展对象指针
        return myExtension;
    }
}