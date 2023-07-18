#include "mystring.h"
#include <string.h>

mystring* crt_mystring(const char* const str, size_t _size, size_t size_of_char){
    mystring* block = (mystring*)malloc(sizeof(mystring));

    block->m_str = (char*)malloc(size_of_char * sizeof(char) * _size + 1);
    int num_of_char = _size * size_of_char + 1;
    for(int i = 0; i < num_of_char; i++){
        block->m_str[i] = str[i];
    }

    block->m_size = _size;
    block->m_size_of_char = size_of_char;
    block->m_length = _size;
    block->m_capacity = _size;
    
    block->append_char = append_char;
    block->append_chars = append_chars;
    block->append_str = append_str;
    block->assign = assign;
    block->at = at;
    block->capacity = capacity;
    block->clear = clear;
    block->compare = compare;
    block->copy = copy;
    block->data = data;
    block->empty = empty;
    block->end = end;
    block->erase = erase;
    block->find = find;
    block->front = front;
    block->insert = insert;
    block->length = length;
    block->max_size = max_size;
    block->pop_back = pop_back;
    block->push_back = push_back;
    block->rbegin = rbegin;
    block->rend = rend;
    block->replace = replace;
    block->resize = resize;
    block->reserve = reserve;
    block->rfind = rfind;
    block->shrink_to_fit = shrink_to_fit;
    block->size = size;
    block->substr = substr;
    block->swap = swap;
}

bool isvalid(mystring* block){
    if(block){
        if(block->m_str){
            return true;
        }
    }
    return false;
}

void del_mystring(mystring* block){
    if(block){
        if(block->m_str){
            free(block->m_str);
        }
        free(block);
    }
}

void append_char(mystring* block, const char c){
    if(isvalid(block)){
        if(block->m_capacity ^ block->m_size){
            block->m_str = realloc(block->m_str, 2 * block->m_size);
            block->m_capacity = 2 * block->m_size;
        }
        block->m_str[block->m_length] = c;
        block->m_str[block->m_length + 1] = '\0';
        block->m_size++;
        block->m_length++;
    }
}

void append_chars(mystring* block, const char c, size_t size){
    if(isvalid(block)){
        if(block->m_capacity < block->m_size + size){
            block->m_str = realloc(block->m_str, 2 * (block->m_size + size));
            block->m_capacity = 2 * (block->m_size + size);
        }
        
        memset(block->m_str + block->m_size, c, size);
        
        block->m_str[block->m_length + size] = '\0';
        block->m_size += size;
        block->m_length += size;
    }
}

void append_str(mystring* block, const char* const str, size_t size){
    if(isvalid(block)){
        if(block->m_capacity < block->m_size + size){
            block->m_str = realloc(block->m_str, 2 * (block->m_size + size));
            block->m_capacity = 2 * (block->m_size + size);
        }

        memmove(block->m_str + block->m_size, str, size);
        
        block->m_str[block->m_length + size] = '\0';
        block->m_size += size;
        block->m_length += size;
    }
}

void assign(mystring* block, const char* const str, size_t size){
    if(isvalid(block)){
        if(block->m_capacity < block->m_size + size){
            block->m_str = realloc(block->m_str, 2 * size);
            block->m_capacity = 2 * size;
        }
        memmove(block->m_str, str, size);
        block->m_str[size] = '\0';
        block->m_size = size;
        block->m_length = size;
    }
}

char* const at(mystring* block, size_t pos){
    if(isvalid(block)){
        return block->m_str + pos;
    }
}

char* const back(mystring* block){
    if(isvalid(block)){
        return block->m_str + block->m_size - 1;
    }
}

char* const begin(mystring* block){
    if(isvalid(block)){
        return block->m_str;
    }
}

size_t capacity(mystring* block){
    if(isvalid(block)){
        return block->m_capacity;
    }
}

void clear(mystring* block){
    if(isvalid(block)){
        free(block->m_str);
        block->m_str = NULL;
        block->m_size = 0;
        block->m_length = 0;
        block->m_capacity = 0;
        block->m_size_of_char = 0;
    }
}

int compare(mystring* block, const char* const str, size_t size){
    if(isvalid(block)){
        return memcmp(block->m_str, str, size < block->m_size ? size : block->m_size);
    }
}

size_t copy(mystring* _Dst, mystring* _Src){
    if(_Dst && _Src){
        if(_Dst->m_capacity < _Src->m_size){
            _Dst->m_str = realloc(_Dst->m_str, _Src->m_size * 2);
            memmove(_Dst->m_str, _Src->m_str, _Src->m_size);
            _Dst->m_capacity = _Src->m_size * 2;
            _Dst->m_size = _Src->m_size;
            _Dst->m_length = _Src->m_size;
        }
    }
}

const char* data(mystring* block){
    if(isvalid(block)){
        return block->m_str;
    }
    return NULL;
}

bool empty(mystring* block){
    if(isvalid(block) && block->m_size){
        return 0;
    }
    return 1;
}

char* const end(mystring* block){
    if(isvalid(block)){
        return block->m_str + block->m_size;
    }
    return NULL;
}

void erase(mystring* block, size_t index, size_t size){
    if(isvalid(block)){
        char* temp = malloc(sizeof(char) * (block->m_size - size));
        memmove(temp, block->m_str, sizeof(char) * index);
        memmove(temp + index, block->m_str + index + size, block->m_size - index - size + 1);
        free(block->m_str);
        block->m_str = temp;
        block->m_size -= size;
        block->m_length = block->m_size;
        block->m_capacity = block->m_size - size;
    }    
}

void my_next(int* next,int n,const char* p)
{
	int j = 0,k=-1;
	next[0] = -1;
	while(j<n)
	{
		if (k == -1 || p[j] == p[k])
		{
			next[j + 1] = k + 1;
			j++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}

int kmp(const char* str1, const char* str2)
{
	int i = 0, j = 0;
	int len = (int)strlen(str2);
	int* next = (int*)malloc(len * sizeof(int));
	assert(next);
	my_next(next,len-1,str2);
	while (str2[j])
	{
		if(j==-1||str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
		if (str1[i] == '\0')
		{
			free(next);
			next = NULL;
			return -1;
		}
	}
	free(next);
	next = NULL;
	return i - strlen(str2);
}

char* const find(mystring* block, const char* const str, size_t size, size_t offset){
    if(isvalid(block)){
        if(offset > block->m_size && block->m_size - offset< size){
            return NULL;
        }
        if(size > 20){
            int rev = kmp(block->m_str + offset, str);
            if(rev == -1){
                return NULL;
            }
            return block->m_str + offset + rev;
        }
        else{
            int flag = 1;
            for(int i = 0; i < block->m_size - offset; i++){                
                for(int j = 0; j < strlen(str); j++){
                    if((block->m_str + offset)[i] == str[j]){
                        continue;
                    }
                    else{
                        flag = 0;                        
                        break;
                    }
                }
                if(flag){
                    return block->m_str + offset + i;
                }
            }
            return NULL;
        }
    }
    return NULL;
}

char* const front(mystring* block){
    if(isvalid(block)){
        return block->m_str;
    }
    return NULL;
}

size_t insert(mystring* block, const char* const str, size_t size, size_t offset){
    if(isvalid(block)){
        char* temp = malloc(sizeof(char) * (block->m_size + size + 1));
        memset(temp, 0, (block->m_size + size + 1));
        memmove(temp, block->m_str, offset);
        memmove(temp + offset, str, size);
        memmove(temp + offset + size, block->m_str + offset, block->m_size - offset);
        block->m_size += size;
        block->m_length += block->m_length;
        block->m_capacity  = block->m_size;
        return size;
    }
    return 0;
}

size_t length(mystring* block){
    if(isvalid(block)){
        return block->m_length;
    }
    return -1;
}

size_t max_size(mystring* block){
    if(isvalid(block)){
        return block->m_capacity;
    }
}

const char pop_back(mystring* block){
    if(isvalid(block)){
        char rev = block->m_str[block->m_size];
        block->m_str[block->m_size] = 0;
        block->m_size--;
        block->m_length--;
        return rev;
    }
    return 0;
}

int push_back(mystring* block, char c){
    if(isvalid(block)){
        if(block->m_size + 1 > block->m_capacity){
            block->m_str = realloc(block->m_str, 2 * block->m_size);
            block->m_capacity = 2 * block->m_size;
        }
        block->m_str[block->m_size] = c;
        block->m_str[block->m_size + 1] = 0;
        block->m_size++;
        return 0;
    }
    return -1;
}

char* const rbegin(mystring* block){
    if(isvalid(block)){
        return block->m_str + block->m_size;
    }
    return NULL;
}

char* const rend(mystring* block){
    if(isvalid(block)){
        return block->m_str;
    }
    return NULL;
}

void replace(mystring* block, const char* const str, size_t size, size_t offset){
    if(isvalid(block)){
        if(offset + size > block->m_capacity){
            block->m_str = realloc(block->m_str, block->m_size + size + 1);
            block->m_capacity = block->m_size + size;
        }
        memmove(block->m_str + offset, str, size);
        if(offset + size > block->m_size){
            block->m_size = offset + size;
            block->m_length = offset + size;
        }
    }
}

void reserve(mystring* block, size_t size);

void resize(mystring* block, size_t size);

char* const rfind(mystring* block, const char* const str, size_t size, size_t offset);

void shrink_to_fit(mystring* block);

size_t size(mystring* block);

char* const substr(mystring* block, size_t offset, size_t size);

void swap(mystring* block);