#pragma once

#include <vector>

namespace genalg
{
    class mempool
    {
        private:

            using uint  = unsigned int;

        public:

            mempool();
            mempool(const int block_size);
            ~mempool();

            void* new_block();
            void   del_block(void* block);

        private:

            uint _block_size;
            void* _mem;
            void* _assigned;
    };
}
