#pragma once

struct Chain {
    int _val = -1;
    Chain* _next = nullptr;

    Chain(int val): _val(val){};
};
