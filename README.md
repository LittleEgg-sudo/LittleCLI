## LittleCLI

A simple CLI project that has a command history, an easy function to register commands, and outputs everything to a log file. 
Personally i'm using this project for my auth backend as a local control panel because I personally hate working with websites. In the future I'll maybe add in a scrolling feature since right now it only display's the last 20ish command responses/logs but everything gets logged to a file so I don't see the need for it right now.
To use the command history, it's just like any other cli you just use your arrow keys to cycle through your history.

This is only for windows. I'm sure it's fairly easy to port to linux but I havent tried to. Only reason it won' work on linux is the fact that I use windows functions for getting console size and console cursor position.


Registering commands is very simple either with a lambda funciton or just another function present.


    void testprint(std::vector<std::string> params) {
        if(params.size() != 1) {
            console::add_log("not correct command usage!");
            return;
        }
      console::add_log("working! param1: " + params[0]);
        
    }
    
    command::register_command("testprint", testprint);
    command::register_command("exit", [](std::vector<std::string> params){ exit(1); });


I'd love any suggestions/recommendations for new features to add!
This also was made in just over an hour so if you find any bugs please lmk.

![enter image description here](https://i.imgur.com/XbUaqbB.png)

