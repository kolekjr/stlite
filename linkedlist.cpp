// The MIT License (MIT)
//
// High-performance generic linked list - implementation file
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
LinkedList<T>::LinkedList(T *arr, unsigned len)
{
    for (unsigned i = 0; i < len; i++)
        push_back(arr[i]);
}

// Copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList &other)
{
    if (&other != this && other._lst)
    {
        // Pointer to the first element
        Element<T> *p = other._lst->next;
        while (p != other._lst)
        {
            push_back(p->value);
            p = p->next;
        }

        push_back(p->value);
    }
}

// Move constructor
template <class T>
LinkedList<T>::LinkedList(LinkedList &&other)
{
    if (&other != this)
        _lst = other._lst;
}

// Copy assignment operator
template <class T>
void LinkedList<T>::operator=(const LinkedList &other)
{
    if (&other != this && other._lst)
    {
        clear();

        // Pointer to the first element
        Element<T> *p = other._lst->next;
        while (p != other._lst)
        {
            push_back(p->value);
            p = p->next;
        }

        push_back(p->value);
    }
}

// Move assignment operator
template <class T>
void LinkedList<T>::operator=(LinkedList &&other)
{
    if (&other != this)
    {
        clear();
        _lst = other._lst;
    }
}

// Append element to end of the list
template <class T>
void LinkedList<T>::push_back(T value)
{
    Element<T> *e = new Element<T>(value);

    if (!_lst)
    {
        e->next = e;
    }
    else
    {
        e->next = _lst->next;
        _lst->next = e;
    }

    _lst = e;
    _sz++;
}

// Append elements of other to end of the list
template <class T>
void LinkedList<T>::append(const LinkedList &other)
{
    if (other._lst)
    {
        // Pointer to the first element
        Element<T> *p = other._lst->next;
        while (p != other._lst)
        {
            push_back(p->value);
            p = p->next;
        }

        push_back(p->value);
    }
}

// Insert element at beginning of the list
template <class T>
void LinkedList<T>::push_front(T value)
{
    Element<T> *e = new Element<T>(value);

    if (!_lst)
    {
        e->next = e;
        _lst = e;
    }
    else
    {
        e->next = _lst->next;
        _lst->next = e;
    }

    _sz++;
}

// Remove element with the value from the list.
// Return true if element has been removed, false otherwise.
template <class T>
bool LinkedList<T>::remove(T value)
{
    if (!_lst)
        return false;

    if (_lst->next == _lst)
    {
        if (_lst->value == value)
        {
            delete _lst;
            _sz--;
            return true;
        }

        return false;
    }

    // Pointer to the last element
    Element<T> *p = _lst;

    while (p->next->value != value &&  p->next != _lst)
        p = p->next;

    if (p->next->value == value)
    {
        if (p->next == _lst)
            _lst = p;

        Element<T> *old = p->next;
        p->next = p->next->next;
        delete old;
        _sz--;

        return true;
    }

    return false;
}

// Remove element at the position "pos" in the list.
// Return true if element has been removed, false otherwise.
template <class T>
bool LinkedList<T>::remove_pos(unsigned pos)
{
    if (!_lst)
        return false;

    // TODO: Implement

    return false;
}

// Two possible cases:
//   - The list contains a single element, we remove it and set _lst to nullptr
//     and _sz to 0.
//   - The list has more than one element. Removing a first element from the
//     list is efficient and easy, just remove _lst->next which points to the
//     first element of the list.
template <class T>
bool LinkedList<T>::pop_front()
{
    if (!_lst)
        return false;

    if (_lst->next == _lst)
    {
        delete _lst;
        _lst = nullptr;
        _sz = 0;
    }
    else
    {
        Element<T> *old = _lst->next;
        _lst->next = _lst->next->next;
        delete old;
        _sz--;
    }

    return false;
}

template <class T>
bool LinkedList<T>::pop_back()
{
    if (!_lst)
        return false;

    if (_lst->next == _lst)
    {
        // The list contains a single element

        delete _lst;
        _lst = nullptr;
        _sz = 0;
    }
    else
    {
        // We need to traverse entire list to get "next" pointer that points to
        // the _lst.

        Element<T> *p = _lst->next;
        while (p->next != _lst)
            p = p->next;
        p->next = _lst->next;
        delete _lst;
        _lst = p;
        _sz--;
    }

    return true;
}

template <class T>
T LinkedList<T>::get(unsigned pos)
{
    if (_lst)
    {
        unsigned n = 0;

        // Pointer to the first element
        Element<T> *p = _lst->next;
        while (n != pos && p != _lst)
        {
            p = p->next;
            n++;
        }

        if ((n == pos) || (p == _lst && n+1 == pos))
            return p->value;
    }
}

template <class T>
void LinkedList<T>::clear()
{
    if (!_lst)
        return;

    Element<T> *p = _lst;

    while (p->next != _lst)
    {
        Element<T> *old = _lst->next;
        _lst->next = _lst->next->next;
        delete old;
    }

    delete _lst;
    _lst = nullptr;
    _sz = 0;
}

template <class T>
void LinkedList<T>::reverse()
{
    // TODO: Implement
}