#include <memory> 
#include <iostream>
class list { 
  public: 
    list() : next() { } 
    list(std::unique_ptr<list>& n) : next(std::move(n)) { } 
 
  private: 
    std::unique_ptr<list> next; 
}; 
  
void kaboom() { 
  auto node = std::make_unique<list>(); 
  for (auto i = 0; i < 10000000; i++) { 
    node = std::make_unique<list>(node); 
  } 
} 
  
int main() { 
  kaboom(); 
} 