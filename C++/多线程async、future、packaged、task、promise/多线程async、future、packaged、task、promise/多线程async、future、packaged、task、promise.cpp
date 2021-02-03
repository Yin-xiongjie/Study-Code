#include <iostream>
#include<thread>
#include<mutex>
#include<list>
#include<future>
#include<chrono>
#include<vector>
using namespace std;

//class A
//{
//public:
//	int mythread(int mypar)
//	{
//		cout << mypar << endl;
//		cout << "mythread start\t" << "thread_id is:" << this_thread::get_id() << endl; //打印新线程的ID号
//		chrono::milliseconds S_sleep(5000); //定义一个5S的时间变量
//		this_thread::sleep_for(S_sleep);//让线程休息5秒
//		cout << "mythread end\t" << "thread_id is:" << this_thread::get_id() << endl; //打印新线程的ID号
//		return 20;
//	}
//
//};
//int mythread(int oper)
//{
//	cout << "mythread start\t" << "thread_id is:" << this_thread::get_id() << endl; //打印新线程的ID号
//	chrono::milliseconds S_sleep(5000); //定义一个5S的时间变量
//	this_thread::sleep_for(S_sleep);//让线程休息5秒
//	cout << "mythread end\t" << "thread_id is:" << this_thread::get_id() << endl; //打印新线程的ID号
//	return 20;
//}


//vector<packaged_task<int(int)>> mytasks; //创建一个容器

int main()
{
/*
//一.std::async、std::future创建后台任务并返回值
//希望线程返回一个结果：
//std::async是个函数模板，用来启动一个异步任务，启动起来一个异步任务后，它返回一个std::future(类模板)对象；
//什么叫"启动一个异步任务"，就是自动创建一个线程并开始执行对应的线程入口函数，他返回一个std::future对象；
	//这个std::future对象里就含有线程入口函数返回的结果（线程返回的结果）；我们可以调用future对象的成员函数get()来获取；
//future提供一种异步操作结果的机制，就是说这个结果可能无法马上拿到，但线程执行完毕就能拿到结果。
//所以future里会保存一个值，这个值在将来的某个时刻能拿到
//std::launch::deferred;表示线程入口函数调用被延迟到std::future的wait()或者get()函数调用时才执行；
//因此如果不调用get(),或者wait()函数时线程不会执行；
//std::launch::deferred:延迟调用，并且没有创建新线程，是在主线程中调用的线程入口函数；

// std::launch::async:在调用async函数时就开始创建线程；
//async()函数：系统默认调用的就是std::launch::async，所以加不加参数std::launch::async效果都一样；
//std::launch::async和std::launch::deferred同时使用时是在主线程中调用的线程入口函数，并且起不到延迟调用的功能

	//下列程序是通过std::对象的get()成员函数等待线程结束并拿到结果
	A a;
	int tempar = 12;
	cout << "main thread_id is:" << this_thread::get_id() << endl;		
	//std::future<int>result = async(mythread); //采用函数创建线程
	std::future<int>result = async(launch::deferred,&A::mythread, &a, tempar);//采用类模板创建线程
	printf("一些内容操作.....\n");
	cout << result.get() <<endl;//程序会卡在这儿等待mythread线程执行完毕，再获得返回值；
	//result.wait();  //wait()只是等待线程返回，但本身不返回结果,而get()函数本身会返回结果；
*/

/**************************************************************************************************/
//二.std::packaged_task;打包任务，把任务包装起来
//是个类模板，它的模板参数是各种可调用对象，通过std::packaged_task来把各种可调用对象包装起来，方便作为线程的入口函数
//(1).法一

	//cout << "main thread_id is:" << this_thread::get_id() << endl;
	//packaged_task<int/*返回值为整形*/(int)/*参数为整形*/>mypt(mythread);  //我们把函数mythread通过packaged_task包装起来
	//thread t1(ref(mypt),1);  //创建线程，线程开始执行
	//t1.join(); //等待线程执行完毕
	//future<int> result = mypt.get_future();    //get_future()可以将返回的结果与pakaged_task的对象绑在一起；
	//cout << result.get()<<endl;
	//cout << "I Love China" << endl;

//(2).法二,用lambda函数作为线程函数入口
	//packaged_task<int/*返回值为整形*/(int)/*参数为整形*/>mypt([](int mypar) {
	//	cout << "mythread start\t" << "thread_id is:" << this_thread::get_id() << endl; //打印新线程的ID号
	//	chrono::milliseconds S_sleep(5000); //定义一个5S的时间变量
	//	this_thread::sleep_for(S_sleep);//让线程休息5秒
	//	cout << "mythread end\t" << "thread_id is:" << this_thread::get_id() << endl; //打印新线程的ID号
	//	return 20;
	//}); 
	//cout << "main thread_id is:" << this_thread::get_id() << endl;
	//thread t1(ref(mypt),1);  //创建线程，线程开始执行
	//t1.join(); //等待线程执行完毕
	//future<int> result = mypt.get_future();    //get_future()可以将返回的结果与pakaged_task的对象绑在一起；
	//cout << result.get()<<endl;
	//cout << "I Love China" << endl;

	//mytasks.push_back(move(mypt));
	////......
	//std::packaged_task<int(int)>mypt2;
	//auto iter = mytasks.begin(); //移动语义
	//mypt2 = (move(*iter));  //删除第一个元素
	//mytasks.erase(iter);
	//mypt2(12345); //直接调用
	//future<int> result = mypt2.get_future();
	//cout << result.get() << endl;

/***************************************************************************************************/
//三.std::promise,类模板
//我们能够在一个线程中给它赋值，然后我们可以在其他线程中把这个值取出来用；

	return 0;

}


