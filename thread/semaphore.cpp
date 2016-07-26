#include <mutex>
#include <condition_variable>

class semaphore {
public:
  semaphore() : count_() {}

  void notify()
  {
    std::unique_lock<std::mutex> l(m_);
    ++count_;
    c_.notify_one();
  }
  
  void wait()
  {
    std::unique_lock<std::mutex> l(m_);
    while (!count_) {
      c_.wait(l);
    }
    --count_;
  }

private:
  unsigned long count_;
  std::mutex m_;
  std::condition_variable c_;
};

int main()
{

}
