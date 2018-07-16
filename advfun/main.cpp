#include <phpcpp.h>
#include <iostream>

//打印100以内的素数
void mm_print_pn_100()
{
	int x = 2;
	int y = 1;
	int line = 0;
	while (x <= 100){
		int z = x - y; //z随y递减1
		int a = x%z; //取余数
		if (a == 0) { //如果x被z整除
			if (z == 1) {//如果z为1（x是质数）
				Php::out << x << " ";//输出x
				line ++;//每行输出的数的数量加1
			 }
			x ++; //x加1
			y = 1;//y还原
		}
		else {//如果没有被整除
			y ++;//y加1，下一次循环中z减1
		}
		if (line == 10) {//每输出10个数                                                                                   
			Php::out << std::endl;//输出一个换行        
			line = 0;//还原line
		}
	}
	if (line != 0) //最后一行输出换行
		Php::out << std::endl;
	Php::out.flush();
}

//任意给定一个整数，打印出小于等于该整数的所有素数
void mm_print_pn_any(Php::Parameters &params){
	//检查必须输入一个参数
	if(params.size() == 0){
		Php::out << "error: need a parameter " << std::endl;
		return;
	}
	//检查参数必须是整形
	if( params[0].type() != Php::Type::Numeric){
		Php::out << "error: parameter must be numeric" << std::endl;
		return;
	}
	//检查数字必须大于1
	int number = params[0];
	if(number <= 1){
		Php::out << "error: parameter must be larger than 1" << std::endl;
		return;
	}
	//检查参数必须大于0
	int x = 2;
	int y = 1;
	int line = 0;
	while (x <= number){
		int z = x - y; //z随y递减1
		int a = x%z; //取余数
		if (a == 0) { //如果x被z整除
			if (z == 1) {//如果z为1（x是质数）
				Php::out << x << " ";//输出x
				line ++;//每行输出的数的数量加1
			 }
			x ++; //x加1
			y = 1;//y还原
		}
		else {//如果没有被整除
			y ++;//y加1，下一次循环中z减1
		}
		if (line == 10) {//每输出10个数                                                                                   
			Php::out << std::endl;//输出一个换行        
			line = 0;//还原line
		}
	}
	if (line != 0) //最后一行输出换行
		Php::out << std::endl;
	Php::out.flush();	
}

//获取1-100的和
Php::Value mm_sum_1_100(){
	int sum = 0;
	int i;
	for(i=1;i<=100;i++){
		sum += i;
	}
	return sum;
}

//获取所有参数的和
Php::Value mm_sum_all(Php::Parameters &params){
	int sum = 0;
	for (auto &param : params){
		//字符串类型可以自动转换成整形
		sum += param;
	}
	return sum;
}

//获取所有数组各元素的和
Php::Value mm_sum_array(Php::Parameters &params){
	//没有给定参数，返回0
	if(params.size() == 0){
		return 0;
	}
	//参数类型不是数组，转成整形返回
	if( params[0].type() != Php::Type::Array){
		return (int)params[0];
	}
	//数组中的元素逐个相加
	int sum = 0;
	Php::Value array = params[0];
	int size = array.size();
	int i;
	for(i=0;i<size;i++){
		sum += array.get(i);
	}
	return sum;
}

//获取30以内的所有素数
Php::Value mm_get_pn_30(){
	std::vector<int> pn;
	int x = 2;
	int y = 1;
	while (x <= 30){
		int z = x - y; //z随y递减1
		int a = x%z; //取余数
		if (a == 0) { //如果x被z整除
			if (z == 1) {//如果z为1（x是质数）
				pn.push_back(x); //放数组中去
			}
			x ++; //x加1
			y = 1;//y还原
		}
		else {//如果没有被整除
			y ++;//y加1，下一次循环中z减1
		}
	}	
	return pn;
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
        static Php::Extension extension("mymath", "1.0.0");
        
        //这里可以添加你要暴露给PHP调用的函数
		extension.add<mm_print_pn_100>("mm_print_pn_100");
		extension.add<mm_print_pn_any>("mm_print_pn_any");
		extension.add<mm_sum_1_100>("mm_sum_1_100");
		extension.add<mm_sum_all>("mm_sum_all");
		extension.add<mm_sum_array>("mm_sum_array");
		extension.add<mm_get_pn_30>("mm_get_pn_30");
		
        // 返回扩展对象指针
        return extension;
    }
}
