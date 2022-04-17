#ifndef ERRORS_HPP
#define ERRORS_HPP

//------------------------------------------------------------
//					ERROR MESSEGES DECLARATION
//------------------------------------------------------------

#include <iostream>

#include "domain/dom_flags.hpp"
#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_path.hpp"

#ifdef BILL_WINDOWS
#include <windows.h>
#endif // !BILL_WINDOWS

namespace dom
{
    class ErrorMessages
    {
    public:
        ErrorMessages();

        template<typename... Args>
        static void startLogBlock(Args... args)
        {
            for(sint_8 i = 0; i < mLogBlockCount; ++i) (*mLogStream) << '\t';
            ++mLogBlockCount;

            (void)std::initializer_list<bool>
            {
                static_cast<bool>((*mLogStream) << args << ' ')...
            };

            (*mLogStream) << '\n';
        }

        template<typename... Args>
        static void endLogBlock(Args... args)
        {
            for(sint_8 i = 0; i < mLogBlockCount; ++i) (*mLogStream) << '\t';
            --mLogBlockCount;

            (void)std::initializer_list<bool>
            {
                static_cast<bool>((*mLogStream) << args << ' ')...
            };
            
            (*mLogStream) << '\n';
        }

        template<typename... Args>
        static void writeLog(Args... args)
        {
            for(sint_8 i = 0; i < mLogBlockCount; ++i) (*mLogStream) << '\t';

            (void)std::initializer_list<bool>
            {
                static_cast<bool>((*mLogStream) << args << ' ')...
            };

            (*mLogStream) << '\n';
        }

        template<typename... Args>
        static void writeError(Args... args)
        {
            #ifdef ERRORS_TO_LOG_OUTPU
                for(sint_8 i = 0; i < mLogBlockCount; ++i) (*mLogStream) << '\t';
            #endif

            (*mErrorStream) << "ERROR" << ' ';

            (void)std::initializer_list<bool>
            {
                static_cast<bool>((*mErrorStream) << args << ' ')...
            };

            (*mErrorStream) << '\n';
        }

        static void writeLogEndl();

        #ifdef BILL_WINDOWS
        /*
        \brief Gets error of WinAPI.
        \return String with error messege.
        */
        str_val GetLastErrorAsString();
        #endif // !BILL_WINDOWS

    private:
        static ErrorMessages mGreatCrutch;

        static std::ostream* mLogStream;
        static std::ostream* mErrorStream;

        static sint_8 mLogBlockCount;
    };
}


#ifdef _DBG_
    #define START_LOG_BLOCK     dom::ErrorMessages::startLogBlock
    #define END_LOG_BLOCK       dom::ErrorMessages::endLogBlock
    #define WRITE_LOG           dom::ErrorMessages::writeLog
    #define WRITE_LOG_ENDL      dom::ErrorMessages::writeLogEndl 
    #define WRITE_ERROR         dom::ErrorMessages::writeError
#else
    #define START_LOG_BLOCK
    #define END_LOG_BLOCK
    #define WRITE_LOG     
    #define WRITE_LOG_ENDL 
    #define WRITE_ERROR    
#endif // DEBUG

#endif // !ERRORS_HPP