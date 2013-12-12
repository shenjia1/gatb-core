//! [snippet1]
// We include what we need for the test
#include <gatb/gatb_core.hpp>
#include <iostream>

/********************************************************************************/
/*                    Bank with exception management                            */
/********************************************************************************/
int main (int argc, char* argv[])
{
    // We define a try/catch block in case some method fails (bad filename for instance)
    try
    {
        // We declare a Bank instance defined by a list of filenames
        Bank b (argc-1, argv+1);

        // We create an iterator over this bank.
        Bank::Iterator it (b);

        // We loop over sequences.
        for (it.first(); !it.isDone(); it.next())
        {
            // We dump the data size and the comment
            std::cout << "[" << it->getDataSize() << "] " << it->getComment()  << std::endl;

            // We dump the data
            std::cout << it->getDataBuffer() << std::endl;
        }
    }
    catch (gatb::core::system::Exception& e)
    {
        std::cerr << "EXCEPTION: " << e.getMessage() << std::endl;
    }
}
//! [snippet1]