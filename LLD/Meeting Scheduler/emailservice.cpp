#include <aws/core/Aws.h>
#include <aws/email/SESClient.h>

class EmailService
{
public:
    void sendEmail(vector<Attendee> attendees)
    {
        Aws::SES::SESClient ses;
        se_req.SetDestination(destination);
        se_req.SetMessage(message);
    }
}