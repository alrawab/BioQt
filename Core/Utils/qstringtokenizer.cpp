#include "qstringtokenizer.h"

namespace BioQt {


int find_first_not_of(const QString &str,const QString & delm,int pos=0)
{

    int index=-1;
    for(int i=pos;i<str.size();++i)
    {
        if( !delm.contains( str.at(i)))
             return i;

    }

    return index;

}

int find_first_of(const QString &str,const QString & delm,int pos=0)
{

    int index=-1;
    for(int i=pos;i<str.size();++i)
    {
        if( delm.contains( str.at(i)))
             return i;

    }

    return index;

}



QStringTokenizer::QStringTokenizer(const QString& s, const QString& delimiters, bool solid, bool allowEmptyTokens):
    tokens_(),
    splits_(),
    currentPosition_(0)
{
    if (!solid)
    {
        size_t index = (find_first_not_of(s,delimiters));
        while( index != -1)
        {
           size_t newIndex = find_first_of(s,delimiters, index);
            if (newIndex != -1)
            {
                tokens_.push_back(s.mid(index, newIndex - index));
                if (!allowEmptyTokens) index =find_first_not_of(s,delimiters, newIndex);
                else                   index = newIndex + 1;
                splits_.push_back(s.mid(newIndex, index - newIndex));
            }
            else
            {
                tokens_.push_back(s.mid(index));
                index = newIndex;
            }
        }
    }
    else
    {
        size_t index = 0;
        while (index != -1)
        {
            size_t newIndex = s.indexOf(delimiters,index);
            if (newIndex != -1)
            {
                tokens_.push_back(s.mid(index, newIndex - index));
                if (!allowEmptyTokens)
                {
                    index = newIndex + delimiters.size();
                    while (index != -1 && s.mid(index, delimiters.size()) == delimiters)
                        index += delimiters.size();
                }
                else index = newIndex + delimiters.size();
                splits_.push_back(s.mid(newIndex, index - newIndex));
            }
            else
            {
                tokens_.push_back(s.mid(index));
                index = newIndex;
            }
        }
    }
}



const QString& QStringTokenizer::nextToken() throw (BioQtException)
{
    if (!hasMoreToken()) throw BioQtException("No more token in tokenizer.");
        return tokens_[currentPosition_++];

}



void QStringTokenizer::removeEmptyTokens()
{
  for (unsigned int i = tokens_.size(); i > currentPosition_; i--)
  {
    if (tokens_[i-1] == "") tokens_.erase(tokens_.begin() + i - 1);
  }
}


QString QStringTokenizer::unparseRemainingTokens() const
{
  QString s;
  for (unsigned int i = currentPosition_; i < tokens_.size() - 1; ++i) {
    s += tokens_[i] + splits_[i];
  }
  if (numberOfRemainingTokens() > 0)
    s += tokens_.back();
  return s;
}

unsigned int QStringTokenizer::countTokens()
{
    return getTokens().size();
}





} // namespace BioQt
