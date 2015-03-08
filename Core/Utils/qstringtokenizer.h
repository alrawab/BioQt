#ifndef QSTRINGTOKENIZER_H
#define QSTRINGTOKENIZER_H

#include <BioQt_global.h>
#include <QtCore>
#include <Utils/Exceptions/BioQtException.h>
#include <deque>


namespace BioQt {
/**
 * @brief The QStringTokenizer class Qt port for Java StringTokenizer
 */
class BIOQTSHARED_EXPORT QStringTokenizer
{
public:
    QStringTokenizer(const QString& s, const QString& delimiters = " \t\n\f\r", bool solid = false, bool allowEmptyTokens = false);
    virtual ~QStringTokenizer() {}

public:
    QStringTokenizer(): tokens_(), splits_(), currentPosition_(0) {}

public:

    /**
         * @brief Get the next available token.
         * If no token is availbale, throw an Exception.
         *
         * @return The next token if there is one.
         */
    const QString& nextToken() throw (BioQtException);

    /**
         * @brief Tell if some tokens are still available.
         * @return True if some tokens are still available.
         */
    bool hasMoreToken() const {
        return currentPosition_ < tokens_.size();
    }

    /**
             * @brief Tell how many tokens are available.
             *
             * @return the number of tokens available.
             */
    unsigned int numberOfRemainingTokens() const { return tokens_.size() - currentPosition_; }

    /**
             * @brief Get a particular token.
             *
             * Do not move the iterator.
             *
             * @param pos The index of the token.
             * @return the token at position 'pos'.
             */
    const QString& getToken(unsigned int pos) const { return tokens_[pos]; }

    /**
             * @brief Retrieve all tokens.
             *
             * @return A reference toward the vector of tokens.
             */
    const std::deque<QString>& getTokens() const { return tokens_; }

    /**
         * @brief remove all empty token from the current position.
         */
    void removeEmptyTokens();
    /**
         * @return The remaining tokens as if the original corresponding string was not parsed.
         */
    QString unparseRemainingTokens() const;

     unsigned int countTokens();


protected:
    /** @brief Where the tokens are stored. */
    std::deque<QString>tokens_;
    std::deque<QString>splits_;
    /** @brief the current position in the token list. */
    unsigned int currentPosition_;


};

} // namespace BioQt

#endif // BIOQT_QSTRINGTOKENIZER_H
