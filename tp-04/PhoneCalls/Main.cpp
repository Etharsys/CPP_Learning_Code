#include "Person.h"
#include "Phone.h"
#include "HomePhone.h"
#include "MobilePhone.h"

int main()
{
    Person paul { "Paul", 3 };
    Phone  phone { paul };
    //phone.ring();

    //HomePhone close_phone { paul, 3 };
    //close_phone.ring();					// Hi! Paul on the phone.

    //HomePhone far_phone { paul, -10 };
    //far_phone.ring();					// This is the voicemail of Paul. Please leave a message.

    //const Phone& normal_phone = far_phone;
    //normal_phone.ring();				// This is the voicemail of Paul. Please leave a message.

    MobilePhone mobile_phone { paul };

    //const Phone& normal_phone = mobile_phone;
    //normal_phone.ring();				// Hi! Paul on the phone.

    HomePhone far_phone { paul, -10 };

    const Phone normal_phone = far_phone;
    normal_phone.ring();

    return 0;
}
