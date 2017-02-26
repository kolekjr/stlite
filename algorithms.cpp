// The MIT License (MIT)
//
// STLite algorithms - implementation file
// Copyright (c) 2017 Jozef Kolek <jkolek@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

template <class T>
void min(T a, T b)
{
    return (a < b) ? a : b;
}

template <class T>
void max(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
static int pivot(T *arr, int lo, int hi)
{
    T pval = arr[hi];
    int i = lo-1;
    for (int j = lo; j < hi; j++)
    {
        if (arr[j] < pval)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[hi]);
    return i;
}

template <class T>
static void quick_sort_helper(T *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = pivot(arr, lo, hi);
        quick_sort_helper(arr, lo, pi-1);
        quick_sort_helper(arr, pi+1, hi);
    }
}

template <class T>
void quick_sort(T *arr, unsigned len)
{
    quick_sort_helper(arr, 0, len-1);
}

template <class T>
int binary_search(T *arr, unsigned len)
{
    // TODO: Implement
    return -1;
}
