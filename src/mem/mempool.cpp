#include "mempool.h"

#include <stdexcept>

using namespace genalg;

mempool::mempool()
{

}

mempool::mempool(const int block_size)
{
    if (block_size < 0) { throw std::exception(); }
}

mempool::~mempool()
{

}

void* mempool::new_block()
{
    return nullptr;
}

void mempool::del_block(void* block)
{

}
