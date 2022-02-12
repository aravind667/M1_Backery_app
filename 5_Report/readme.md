# requirments

## highlevel requirements

- H1 creating login page
- H2 creating menu page
- H3 storing the data
-

## low level requirments

- H1L1 : creating login page 1. collecting the data from the user and storing in a text file 2. validating the data to get login
- inside login page: \* inside login page a few options: 1. Menu 2. Add balance 3. Check balance
- inside menu: 1. various options to be added 2. billing format and discounts to be added
- inside add menu: 1. Sender to wallet in between the accounts 2. Adding balance to wallet
- inside checkbalance: 1. showing balances 2. printing last few transations with id

- H2L2: creating menu page
  _ creating a menu page where different sources are avilable i.e staters , maincouse and etc
  _ giving options to choose

- H3L3: storing the data \* creating text file using files and pushing the data and getting it validate in login page

## swot anaylis

![SWOT](https://github.com/aravind667/M1_Backery_app/blob/main/1_Requirements/User%20friendly%20desgin%20Quick%20login%20and%20signup%20process.jpg)

## 4W's 1H

![4W_1H](https://github.com/aravind667/M1_Backery_app/blob/e9593a1b49f27d1c94e02a1d9d6f8ddd3f1d3b2e/1_Requirements/4w1h.png)

# architecture

## desgin

- Behavirual Flow charts
  ![flowchart](https://github.com/aravind667/M1_Backery_app/blob/0a86ce619e8f33639e0ea133442723affb8cdc13/2_Architecture/flow.png)
- Structural flowcharts
  ![structure](https://github.com/aravind667/M1_Backery_app/blob/d0eeacc0c4a07d05e3e90be033d8e719ef24fc2e/2_Architecture/structure%20diagram.png)

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
|  T_10   | H_10   | Logout                                             | Enter Choice      | Successfully logout                      | Successfully logout                      | PASS      |
|  T_11   | H_11   | Exit                                               | Enter choice      | Exit                                     | Exit                                     | PASS      |
