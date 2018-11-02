#ifndef COMMON_CONCURRENT_QUEUE_H
#define COMMON_CONCURRENT_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

namespace common
{
namespace tools
{
/// A thread safe queue that supports both synchronous pop and async_pop.
/// It's not allowed to use pop and async_pop together choose one.
template <class T>
class ConcurrentQueue {
public:
	/// \brief Pushes element into the queue
	/// \param element The element to insert.
	void Push(const T& element)
	{
		this->queueMutex.lock();
		if (this->handler)
		{
			auto handlerCopy = this->handler;
			this->handler = nullptr;
			this->queueMutex.unlock();
			handlerCopy(element);
		}
		else
		{
			this->queue.push(element);
			this->notifier.notify_one();
			this->queueMutex.unlock();
		}
	}

	/// \brief Remove the oldest element from the queue. Blocks if no element is available.
	/// \return The removed element.
	T Pop()
	{
		std::unique_lock<std::mutex> l(this->queueMutex);
		while (this->queue.empty())
		{
			notifier.wait(l);
		}

		T element = this->queue.front();
		this->queue.pop();
		return element;
	}

	/// \brief Asynchronously pop an element from the queue.
	/// \param handler The function that will be called when the element is popped.
	void AsyncPop(std::function<void(T)> handler)
	{
		this->queueMutex.lock();
		if (!this->queue.empty())
		{
			T element = this->queue.front();
			this->queue.pop();
			this->queueMutex.unlock();
			handler(element);
		}
		else
		{
			this->handler = handler;
			this->queueMutex.unlock();
		}
	}

	/// \brief Check whether the queue is empty.
	/// \return True if empty, False if not empty.
	bool Empty() const
	{
		std::lock_guard<std::mutex> lock(this->queueMutex);
		return this->queue.empty();
	}

	/// \brief Return how many elements are currently in the queue
	/// \return The amount of elements int the queue.
	std::size_t Size() const
	{
		std::lock_guard<std::mutex> lock(this->queueMutex);
		return this->queue.size();
	}

private:
	/// \brief contains an async handler to be called when an element is pushed to the queue.
	std::function<void(T)> handler;
	/// \brief Underlying non concurrent queue that holds the elements.
	std::queue<T> queue;
	/// \brief Lock used for synchronisation.
	mutable std::mutex queueMutex;
	/// \brief notifier that allows efficient notifying of a waiting pop.
	std::condition_variable notifier;
};

}
}



#endif //COMMON_CONCURRENT_QUEUE_H
