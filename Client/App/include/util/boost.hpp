#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/condition.hpp>

// cmake changes begin
// I was building this with boost 1.68.0 to satisfy a modern compiler
#if BOOST_VERSION > 103401
#include <boost/function.hpp>

namespace boost
{

	template<class T, class U> shared_ptr<T> shared_static_cast(shared_ptr<U> const & r)
	{
		return boost::static_pointer_cast<T,U>(r);
	}

	template<class T, class U> shared_ptr<T> shared_dynamic_cast(shared_ptr<U> const & r)
	{
		return boost::dynamic_pointer_cast<T,U>(r);
	}

	template<class T, class U> shared_ptr<T> shared_polymorphic_downcast(shared_ptr<U> const & r)
	{
		BOOST_ASSERT(dynamic_cast<T *>(r.get()) == r.get());
		return shared_static_cast<T>(r);
	}
}
#endif
// cmake changes end

namespace RBX
{
	boost::function0<void> background_function(const boost::function0<void>& threadfunc, const char* name);

	class worker_thread : public boost::noncopyable
	{
	public:
		enum work_result
		{
			done,
			more
		};

	private:
		struct data
		{
		public:
			boost::mutex sync;
			boost::condition wakeCondition;
			bool endRequest;
		  
		public:
			//data(const data&);
			data()
				: endRequest(false)
			{
			}
			~data()
			{
			}

		public:
			//data& operator=(const data&);
		};

	private:
		boost::shared_ptr<data> _data;
		boost::thread thread;
	
	public:
		//worker_thread(const worker_thread&);
		worker_thread(const boost::function0<enum work_result>&, const char*);
	public:
		~worker_thread();

	public:
		void wake();
		void join();
	public:
		//worker_thread& operator=(const worker_thread&);
	  
	private:
		static void threadProc(boost::shared_ptr<data>, const boost::function0<enum work_result>&);
	};
}
