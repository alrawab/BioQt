//====
// Array2D.hpp
// - defines a two-dimensional array template
// Notes
// - this package is provided as with no warranty.
// - the author is not responsible for any damage caused
//   either directly or indirectly by using this package.
// - anybody is free to do whatever he/she wants with this
//   package as long as this header section is preserved.
// Created on 2003-03-07 by
// - Roger Zhang (rogerz@cs.dal.ca)
// Modifications
// - Roger Zhang on 2004-10-27
//   - added swapRows and swapColumns
// -
// Last compiled under Linux with gcc-3
//====

#ifndef _RZ_ARRAY_2D_
#define _RZ_ARRAY_2D_

#include <algorithm>
#include <cassert>

namespace RZ
{
    template<typename T> class Array2D
    {
        T **data_;
        int width_, height_;

        void clear();

    public:

        //====
        // constructors and destructor

        Array2D(int h, int w) : height_(h), width_(w)
        {
            assert(h > 0 && w > 0);

            for (data_ = new T*[h]; h-- > 0; data_[h] = new T[w]);
        }

        Array2D(int h, int w, const T &e /* init */) : height_(h), width_(w)
        {
            assert(h > 0 && w > 0);

            for (data_ = new T*[h]; h-- > 0; std::fill_n(data_[h], w, e)) {
                data_[h] = new T[w];
            }
        }

        Array2D(const Array2D<T> &g) : height_(0), width_(0), data_(NULL)
        {
            operator =(g);
        }

        ~Array2D() { clear(); }

        //====
        // accessors and mutators

        int height() const { return height_; }

        int width() const { return width_; }

        int capacity() const { return height_ * width_; }

        void swapRows(int i, int j)
        {
            assert(i >= 0 && i < height_ && j >= 0 && j < height_);

            std::swap(data_[i], data_[j]);
        }

        void swapColumns(int i, int j)
        {
            assert(i >= 0 && i < width_ && j >= 0 && j < width_);

            for (int k = 0; k < height_; k++) {
                std::swap(data_[k][i], data_[k][j]);
            }
        }

        //====
        // operator overloads

        T *operator [](int r)
        {
            assert(r >= 0 && r < height_);

            return data_[r];
        }

        const T *operator [](int r) const
        {
            assert(r >= 0 && r < height_);

            return data_[r];
        }

        Array2D<T> &operator =(const Array2D<T> &g);

        bool operator ==(const Array2D<T> &g) const;

        bool operator !=(const Array2D<T> &g) const
        {
            return !operator ==(g);
        }

    }; // class Array2D

    template<typename T>
    Array2D<T> &Array2D<T>::operator =(const Array2D<T> &g)
    {
        bool sizeChanged = width_ != g.width_ || height_ != g.height_;

        if (sizeChanged) {
            clear();
            data_ = new T*[height_ = g.height_];
            width_ = g.width_;
        }

        for (register int i = 0; i < height_; i++) {
            if (!sizeChanged || (data_[i] = new T[width_])) {
                std::copy(g.data_[i], g.data_[i] + width_, data_[i]);
            }
        }

        return *this;
    }

    template<typename T>
    bool Array2D<T>::operator ==(const Array2D<T> &g) const
    {
        if (height_ != g.height_ || width_ != g.width_) {
            return false;
        }

        for (register int i = 0; i < height_; i++) {
            if (!std::equal(data_[i], data_[i] + width_, g.data_[i])) {
                return false;
            }
        }

        return true;
    }

    template<typename T> void Array2D<T>::clear()
    {
        if (data_) {
            while (height_-- > 0) {
                delete [] data_[height_];
            }
            delete [] data_;
        }
    }

} // namespace RZ

#endif // _RZ_ARRAY_2D_
