#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define crt_mystring(str, size) crt_mystring(str, size, 1ULL)

struct mystring{
    struct mystring* this;
    char* m_str;

    size_t m_size_of_char;
    size_t m_size;
    size_t m_length;
    size_t m_capacity;

    void (*append_char)(struct mystring* block, const char c);

    void (*append_chars)(struct mystring* block, const char c, size_t size);

    void (*append_str)(struct mystring* block, const char* const str, size_t size);

    void (*assign)(struct mystring* block, const char* const str, size_t size);

    char* const (*at)(struct mystring* block, size_t pos);

    char* const (*back)(struct mystring* block);

    char* const (*begin)(struct mystring* block);

    size_t (*capacity)(struct mystring* block);

    void (*clear)(struct mystring* block);

    int (*compare)(struct mystring* block, const char* const str);

    size_t (*copy)(struct mystring* block, char* const str, size_t size, size_t offset);

    const char* (*data)(struct mystring* block);

    bool (*empty)(struct mystring* block);

    char* const (*end)(struct mystring* block);

    void (*erase)(struct mystring* block, size_t index);

    char* const (*find)(struct mystring* block, const char* const str, size_t size, size_t offset);

    char* const (*front)(struct mystring* block);

    size_t (*insert)(struct mystring* block, const char* const str, size_t size, size_t offset);

    size_t (*length)(struct mystring* block);

    size_t (*max_size)(struct mystring* block);

    const char (*pop_back)(struct mystring* block);

    const char (*push_back)(struct mystring* block);

    char* const (*rbegin)(struct mystring* block);

    char* const (*rend)(struct mystring* block);

    void (*replace)(struct mystring* block, const char* const str, size_t size, size_t offset);

    void (*reserve)(struct mystring* block, size_t size);

    void (*resize)(struct mystring* block, size_t size);

    char* const (*rfind)(struct mystring* block, const char* const str, size_t size, size_t offset);

    void (*shrink_to_fit)(struct mystring* block);

    size_t (*size)(struct mystring* block);

    char* const (*substr)(struct mystring* block, size_t offset, size_t size);

    void (*swap)(struct mystring* block);
};

typedef struct mystring mystring;


mystring* crt_mystring(const char* const str, size_t size, size_t size_of_char);

void del_mystring(struct mystring* block);

void append_char(struct mystring* block, const char c);

void append_chars(struct mystring* block, const char c, size_t size);

void append_str(struct mystring* block, const char* const str, size_t size);

void assign(struct mystring* block, const char* const str, size_t size);

char* const at(struct mystring* block, size_t pos);

char* const back(struct mystring* block);

char* const begin(struct mystring* block);

size_t capacity(struct mystring* block);

void clear(struct mystring* block);

int compare(struct mystring* block, const char* const str, size_t size);

size_t copy(struct mystring* block, struct mystring* str);

const char* data(struct mystring* block);

bool empty(struct mystring* block);

char* const end(struct mystring* block);

void erase(struct mystring* block, size_t index, size_t size);

char* const find(struct mystring* block, const char* const str, size_t size, size_t offset);

char* const front(struct mystring* block);

size_t insert(struct mystring* block, const char* const str, size_t size, size_t offset);

size_t length(struct mystring* block);

size_t max_size(struct mystring* block);

const char pop_back(struct mystring* block);

const char push_back(struct mystring* block, char c);

char* const rbegin(struct mystring* block);

char* const rend(struct mystring* block);

void replace(struct mystring* block, const char* const str, size_t size, size_t offset);

void reserve(struct mystring* block, size_t size);

void resize(struct mystring* block, size_t size);

char* const rfind(struct mystring* block, const char* const str, size_t size, size_t offset);

void shrink_to_fit(struct mystring* block);

size_t size(struct mystring* block);

char* const substr(struct mystring* block, size_t offset, size_t size);

void swap(struct mystring* block);