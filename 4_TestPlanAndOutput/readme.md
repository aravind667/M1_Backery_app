# Test plan

| Test ID | HLT ID | Description                                        | Exp IN            | Exp OUT                                  | Actual Out                               | PASS/FAIL |
| :-----: | ------ | -------------------------------------------------- | ----------------- | ---------------------------------------- | ---------------------------------------- | --------- |
|  T_01   | H_01   | Provide required details for login to your account | password          | Successfully logined In                  | Successfully logined In                  | PASS      |
|  T_02   | H_02   | When wrong password is entered                     | Password          | Entered Password is wrong                | Exit                                     | PASS      |
|  T_03   | H_03   | Display the details of avilable menu               | Enter choice      | Display list                             | Display list                             | PASS      |
|  T_04   | H_04   | Order a food from the menu                         | enter choice      | ThankYou for Booking Ticket              | ThankYou for ordering                    | PASS      |
|  T_05   | H_05   | Bill of the items purchased                        | enter choice      | food category, no of persons,no of items | food category, no of persons,no of items | PASS      |
|  T_06   | H_06   | Adding extra                                       | order number      | Your order is placed and bill            | Your order is placed and bill            | PASS      |
|  T_07   | H_07   | Add balance to the wallet                          | Enter choice      | Please enter the amount                  | Please enter the amount                  | PASS      |
|  T_08   | H_08   | person to person                                   | enter wallet name | amount transfered                        | amount transfered                        | PASS      |
|  T_09   | H_09   | check balance                                      | Enter choice      | Trancation_id, person_name,amount        | Trancation_id, person_name,amount        | PASS      |

| T_10 | H_10 | Logout | Enter Choice | Successfully logout | Successfully logout | PASS |
| T_11 | H_11 | Exit | Enter choice | Exit | Exit | PASS |
