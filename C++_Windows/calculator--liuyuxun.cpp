#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include <tuple>

int check(const std::vector<int> &a, const std::vector<int> &b)
{
	if (a.size() > b.size())
		return -1;
	if (a.size() < b.size())
		return 1;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
			return -1;
		if (a[i] < b[i])
			return 1;
	}
	return 0;
}

void print(const std::vector<int> &a, bool b, bool c)
{
	if (a.empty())
	{
		std::cout << "0";
		if (c)
			std::cout << std::endl << std::endl;
		return;
	}
	
	if (!a.empty() && a.back() == -1)
	{
		std::vector<int> temp = a;
		temp.pop_back();
		std::cout << '-';
		print(temp, b, false);
		if (c)
			std::cout << std::endl << std::endl;
		return;
	}
	
	if (b)
	{
		for (int i = a.size() - 1; i >= 0; i--)
			std::cout << a[i];
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
			std::cout << a[i];
	}
	
	if (c)
		std::cout << std::endl << std::endl;
	std::cout.flush();
}

std::vector<int> jia(const std::vector<int> &a, const std::vector<int> &b)
{
	std::vector<int> c(std::max(a.size(), b.size()) + 1, 0);
	for (int i = 0; i < std::max(a.size(), b.size()); i++)
	{
		int r = 0;
		if (i < a.size())
			r += a[i];
		if (i < b.size())
			r += b[i];
		c[i] += r;
		if (c[i] > 9)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	while (c.back() == 0 && c.size() > 1)
		c.pop_back();
	return c;
}

std::vector<int> jian(const std::vector<int> &a, const std::vector<int> &b)
{
	bool flag = 0;
	std::vector<int> aa = a, bb = b;
	int cmp = check(aa, bb);
	if (cmp == 1)
	{
		std::swap(aa, bb);
		flag = 1;
	}
	else if (cmp == 0)
	{
		return {0};
	}
	
	std::vector<int> c(aa.size() + 1, 0);
	for (int i = 0; i < aa.size(); i++)
	{
		int res = aa[i];
		if (i < bb.size())
			res -= bb[i];
		c[i] += res;
		if (c[i] < 0)
		{
			c[i + 1]--;
			c[i] += 10;
		}
	}
	while (c.back() == 0 && c.size() > 1)
		c.pop_back();
	if (flag == 1 && !(c.size() == 1 && c[0] == 0))
		c.push_back(-1);
	return c;
}

std::vector<int> cheng(const std::vector<int> &a, const std::vector<int> &b)
{
	std::vector<int> c(a.size() + b.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			c[i + j] += a[i] * b[j];
		}
	}
	for (int i = 0; i < c.size() - 1; i++)
	{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while (c.size() > 1 && c.back() == 0)
		c.pop_back();
	return c;
}

std::vector<int> quick_mi(const std::vector<int> &base, int exp)
{
	if (exp == 0)
		return {1};
	if (exp == 1)
		return base;
	
	std::vector<int> half = quick_mi(base, exp / 2);
	std::vector<int> result = cheng(half, half);
	
	if (exp % 2 == 1)
		result = cheng(result, base);
	
	return result;
}

std::tuple<std::vector<int>, std::vector<int>> chu(const std::vector<int> &a, const std::vector<int> &b)
{
	if (b.size() == 1 && b[0] == 0)
	{
		std::cout << "错误：除数不能为0！" << std::endl;
		return {{0}, {0}};
	}
	
	if (a.size() == 1 && a[0] == 0)
		return {{0}, {0}};
	
	int cmp = check(a, b);
	if (cmp == 1)
		return {{0}, a};
	if (cmp == 0)
		return {{1}, {0}};
	
	std::vector<int> q(a.size(), 0);
	std::vector<int> res(1, 0);
	
	for (int i = a.size() - 1; i >= 0; --i)
	{
		res = cheng(res, {10});
		res = jia(res, {a[i]});
		
		int l = 0, r = 9;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			std::vector<int> prod = cheng({mid}, b);
			int cmp_res = check(res, prod);
			if (cmp_res == -1 || cmp_res == 0)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		int t = r;
		q[i] = t;
		
		if (t > 0)
		{
			std::vector<int> prod = cheng({t}, b);
			res = jian(res, prod);
		}
	}
	
	while (q.size() > 1 && q.back() == 0)
		q.pop_back();
	while (res.size() > 1 && res.back() == 0)
		res.pop_back();
	
	return {q, res};
}

std::vector<int> mi_optimized(const std::vector<int> &a, const std::vector<int> &b)
{
	if (b.size() == 1 && b[0] == 0)
		return {1};
	
	if (a.size() == 1 && a[0] == 0)
		return {0};
	
	if (b.size() == 1 && b[0] == 1)
		return a;
	
	long long exp = 0;
	for (int i = b.size() - 1; i >= 0; i--)
	{
		exp = exp * 10 + b[i];
		if (exp > 1000000LL)
		{
			std::cout << "错误：指数太大，无法计算！" << std::endl;
			return {0};
		}
	}
	
	if (exp > 1000)
		std::cout << "警告：指数为 " << exp << "，计算可能需要一些时间..." << std::endl;
	
	return quick_mi(a, static_cast<int>(exp));
}

void clearScreen()
{
	system("cls");
}

void start()
{
	std::cout << "              -=-=-=-=-=-=-=               " << std::endl;
	std::cout << "                简易计算器                 " << std::endl;
	std::cout << "              -=-=-=-=-=-=-=               " << std::endl;
	std::cout << "                                  版本号7.0" << std::endl;
	std::cout << "                         作者:liuyuxun,1225" << std::endl;
	std::cout << "             暂只支持非负整数运算           " << std::endl;
	std::cout << "          输入 usage查看使用方法            " << std::endl;
	std::cout << "-------------------------------------------" << std::endl << std::endl;
}

void usage()
{
	std::cout << "                                           " << std::endl;
	std::cout << "使用方法                                   " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 格式：                                  #" << std::endl;
	std::cout << "# 数字1符号数字2                          #" << std::endl;
	std::cout << "# 例：1234+5678                           #" << std::endl;
	std::cout << "#      /  |  \\                            #" << std::endl;
	std::cout << "#  数字1 符号 数字2                       #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 支持的运算:                             #" << std::endl;
	std::cout << "# +(加法)                         -(减法) #" << std::endl;
	std::cout << "# *(乘法)                         /(除法) #" << std::endl;
	std::cout << "# ^(幂运算)                               #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 指令：                                  #" << std::endl;
	std::cout << "# exit                               退出 #" << std::endl;
	std::cout << "# log                            更新日志 #" << std::endl;
	std::cout << "# usage                          使用方法 #" << std::endl;
	std::cout << "# contact                        联系作者 #" << std::endl;
	std::cout << "# information                查看作者信息 #" << std::endl;
	std::cout << "###########################################" << std::endl << std::endl;
	
	std::cout << "按Enter键退出...";
	std::cin.ignore();
	std::cin.get();
}

void log()
{
	std::cout << "               =-=-=-=-=-=-                " << std::endl;
	std::cout << "                 更新日志                  " << std::endl;
	std::cout << "               =-=-=-=-=-=-                " << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 7.0 (精简版)                       #" << std::endl;
	std::cout << "# 更新时间：2026年7月4日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.移除内存管理系统，简化代码            #" << std::endl;
	std::cout << "# 2.重写除法算法，修复之前的所有除法错误  #" << std::endl;
	std::cout << "# 3.修正减法借位越界问题                  #" << std::endl;
	std::cout << "# 4.将指数类型改为 long long 防止溢出     #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 6.0 (改进除法版)                   #" << std::endl;
	std::cout << "# 更新时间：2026年7月4日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.将除法商和余数的保存换成了tuple       #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 5.0 (内存管理增强版)               #" << std::endl;
	std::cout << "# 更新时间：2026年2月8日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.集成完整的内存管理系统                #" << std::endl;
	std::cout << "# 2.实时监控内存分配和释放                #" << std::endl;
	std::cout << "# 3.自动检测内存泄漏                      #" << std::endl;
	std::cout << "# 4.添加内存状态查询指令                  #" << std::endl;
	std::cout << "# 5.优化幂运算算法                        #" << std::endl;
	std::cout << "# 6.增强错误处理机制                      #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 4.1 (代码规范版)                   #" << std::endl;
	std::cout << "# 更新时间：2026年2月8日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.完全重写代码结构                      #" << std::endl;
	std::cout << "# 2.符合C++社区编码规范                   #" << std::endl;
	std::cout << "# 3.优化函数参数传递方式                  #" << std::endl;
	std::cout << "# 4.修复已知的代码缺陷                    #" << std::endl;
	std::cout << "# 5.统一代码风格和格式                    #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 4.0 (功能增强版)                   #" << std::endl;
	std::cout << "# 更新时间：2026年2月6日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.添加幂运算功能(^)                     #" << std::endl;
	std::cout << "# 2.支持大整数幂计算                      #" << std::endl;
	std::cout << "# 3.优化乘法运算效率                      #" << std::endl;
	std::cout << "# 4.改进除法算法逻辑                      #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 3.0 (稳定版)                       #" << std::endl;
	std::cout << "# 更新时间：2026年2月5日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.添加完整的除法运算(/)                 #" << std::endl;
	std::cout << "# 2.支持商和余数同时显示                  #" << std::endl;
	std::cout << "# 3.实现第二代用户界面                    #" << std::endl;
	std::cout << "# 4.增加除零错误处理                      #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 2.0 (功能扩展版)                   #" << std::endl;
	std::cout << "# 更新时间：2026年2月5日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.添加乘法运算功能(*)                   #" << std::endl;
	std::cout << "# 2.实现大整数乘法算法                    #" << std::endl;
	std::cout << "# 3.优化向量存储结构                      #" << std::endl;
	std::cout << "# 4.改进数字输入方式                      #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 1.1 (界面改进版)                   #" << std::endl;
	std::cout << "# 更新时间：2026年2月4日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.更改表达式输入方式                    #" << std::endl;
	std::cout << "# 2.支持连续数字输入                      #" << std::endl;
	std::cout << "# 3.改进结果输出格式                      #" << std::endl;
	std::cout << "# 4.优化用户操作流程                      #" << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "                                           " << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# 版本 1.0 (初始发布版)                   #" << std::endl;
	std::cout << "# 更新时间：2026年2月4日                  #" << std::endl;
	std::cout << "# 更新内容：                              #" << std::endl;
	std::cout << "# 1.实现基本加法运算(+)                   #" << std::endl;
	std::cout << "# 2.实现基本减法运算(-)                   #" << std::endl;
	std::cout << "# 3.支持大整数运算                        #" << std::endl;
	std::cout << "# 4.设计第一代用户界面                    #" << std::endl;
	std::cout << "###########################################" << std::endl;
	
	std::cout << std::endl << "按Enter键继续...";
	std::cin.ignore();
	std::cin.get();
}

void contact()
{
	std::cout << "作者联系方式:                              " << std::endl;
	std::cout << "############################################" << std::endl;
	std::cout << "# liuyuxun:                                #" << std::endl;
	std::cout << "# 邮箱:lyxlele@outlook.com                 #" << std::endl;
	std::cout << "# 邮箱（备用）:2160663365@qq.com           #" << std::endl;
	std::cout << "############################################" << std::endl;
	std::cout << "# 1225:                                    #" << std::endl;
	std::cout << "# qq:3788387389                            #" << std::endl;
	std::cout << "# 邮箱:eFrisk_Dreemurr@outlook.com         #" << std::endl;
	std::cout << "# 邮箱（备用）:3788387389@qq.com           #" << std::endl;
	std::cout << "############################################" << std::endl;
	
	std::cout << "按Enter键退出...";
	std::cin.ignore();
	std::cin.get();
}

void information()
{
	std::cout << "作者信息:                              " << std::endl;
	std::cout << "############################################" << std::endl;
	std::cout << "# liuyuxun:                                #" << std::endl;
	std::cout << "# 学校:钦州师范学校附属小学                #" << std::endl;
	std::cout << "# 简介:                                    #" << std::endl;
	std::cout << "# 一个学编程的小学生                       #" << std::endl;
	std::cout << "############################################" << std::endl;
	std::cout << "# 1225:                                    #" << std::endl;
	std::cout << "# 学校:钦州市第九小学                      #" << std::endl;
	std::cout << "# 简介:                                    #" << std::endl;
	std::cout << "# liuyuxun的好友                           #" << std::endl;
	std::cout << "############################################" << std::endl;
	
	std::cout << "按Enter键退出...";
	std::cin.ignore();
	std::cin.get();
}

int main()
{
	system("title 简易计算器 v7.0");
	
	start();
	
	while (1)
	{
		char op;
		std::string s;
		std::string s1, s2;
		std::cout << "输入表达式或指令: " << std::endl;
		std::cin >> s;
		
		if (s == "exit")
		{
			std::cout << std::endl << "正在退出程序..." << std::endl;
			break;
		}
		if (s == "log")
		{
			log();
			clearScreen();
			start();
			continue;
		}
		if (s == "usage")
		{
			usage();
			clearScreen();
			start();
			continue;
		}
		if (s == "contact")
		{
			contact();
			clearScreen();
			start();
			continue;
		}
		if (s == "information")
		{
			information();
			clearScreen();
			start();
			continue;
		}
		
		int n = -1, m = -1;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (!isdigit(s[i]))
			{
				op = s[i];
				n = i;
				m = i + 1;
				break;
			}
		}
		
		if (n == -1)
		{
			std::cout << "错误：无效的表达式！" << std::endl;
			std::cout << "按Enter键继续...";
			std::cin.ignore();
			std::cin.get();
			clearScreen();
			start();
			continue;
		}
		
		s1 = s.substr(0, n);
		s2 = s.substr(m);
		
		if (s1.empty() || s2.empty())
		{
			std::cout << "错误：数字不能为空！" << std::endl;
			std::cout << "按Enter键继续...";
			std::cin.ignore();
			std::cin.get();
			clearScreen();
			start();
			continue;
		}
		
		std::vector<int> a, b;
		for (int i = s1.size() - 1; i >= 0; i--)
			a.push_back(s1[i] - '0');
		for (int i = s2.size() - 1; i >= 0; i--)
			b.push_back(s2[i] - '0');
		
		std::cout << '=';
		
		if (op == '+')
		{
			std::vector<int> c = jia(a, b);
			print(c, 1, 1);
		}
		else if (op == '-')
		{
			std::vector<int> c = jian(a, b);
			print(c, 1, 1);
		}
		else if (op == '*')
		{
			std::vector<int> c = cheng(a, b);
			print(c, 1, 1);
		}
		else if (op == '/')
		{
			auto res = chu(a, b);
			std::vector<int> c = std::get<0>(res);
			std::vector<int> d = std::get<1>(res);
			print(c, 1, 0);
			std::cout << "......";
			print(d, 1, 1);
		}
		else if (op == '^')
		{
			std::vector<int> c = mi_optimized(a, b);
			print(c, 1, 1);
		}
		else
		{
			std::cout << "错误：不支持的操作符 '" << op << "'" << std::endl;
		}
		
		std::cout << "按Enter键继续...";
		std::cin.ignore();
		std::cin.get();
		clearScreen();
		start();
	}
	
	std::cout << std::endl << "感谢使用简易计算器 v7.0！" << std::endl;
	std::cout << "按Enter键退出...";
	std::cin.ignore();
	std::cin.get();
	
	return 0;
}
