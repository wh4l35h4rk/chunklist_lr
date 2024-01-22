#include <iostream>
#include <list>
#include <algorithm>

namespace fefu_laboratory_two {

    template <typename Type>
    class ChunkList {
    private: 
        struct Chunk {
            std::list<Type> data;

            bool operator==(const Chunk &e) {
                return data == e.data;
            }
        };

        std::list<Chunk> chunkList;
        size_t N;

        void ifEmpty(Chunk &e){
            if (e.data.empty()){
                chunkList.erase(std::remove(chunkList.begin(), chunkList.end(), e), chunkList.end());
            }
        }

    public:
        ChunkList(size_t chunkSize) {
            N = chunkSize;
        }

        void begin(){ return chunkList.begin(); }
        void end(){ return chunkList.end(); }

        void insert (Type value){
            for (Chunk &e : chunkList) {
                if (e.data.size() < N) {
                    e.data.push_back(value);
                    return;
                }
            }
            Chunk newChunk {};
            newChunk.data.push_back(value);
            chunkList.push_back(newChunk);
        }

        void erase (unsigned long long int pos){
            int sizeAllChunks = 0;
            for (Chunk &e : chunkList) {
                for (auto it = e.data.begin(); it != e.data.end(); it++) {
                    auto curIt = std::distance(e.data.begin(), it);
                    if (pos == sizeAllChunks + curIt) {
                        e.data.erase(it);
                        ifEmpty(e);
                        return;
                    }       
                }
                sizeAllChunks += e.data.size();
            }
        }

        void pop_head(){
            chunkList.front().data.pop_front();
            ifEmpty(chunkList.front());
        }

        void pop_back(){
            chunkList.back().data.pop_back();
            ifEmpty(chunkList.back());
        }

        void output(){
            for (Chunk chunk : chunkList) {
                std::list<Type> list = chunk.data;
                for (Type const &e : list) {
                    std::cout << e << ' ';
                }
                std::cout << std::endl;
            }
        }
    };
}