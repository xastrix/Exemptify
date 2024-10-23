# Exemptify
A utility that allows you to add application exceptions to the windows firewall, thereby blocking outgoing traffic.
```
Usage
  Exemptify <RuleID> <PathToTheDubiousApplication> --net-off
    - Adds an exception rule for the specified application, disabling network access.
    - <RuleID> is a unique identifier for the rule you are creating.
    - <PathToTheDubiousApplication> is the file path to the application you want to exempt.

  Exemptify <RuleID> --net-on
    - Enables network access for the specified exception rule.
    - <RuleID> must correspond to an existing rule created previously.

Examples
  Exemptify test1 /path/to/app.exe --net-off
  Exemptify test1 --net-on
```
### Why may be useful
- In cases when you are paranoid and afraid for your data, which can fly to the owner of some malicious program known as “Stealer”, with the help of this utility you can reinsure yourself and add suspicious software to exceptions, so without the Internet your data can not be intercepted.
- By blocking Internet access for suspicious applications, you can minimize potential data breaches by making it harder for malware to steal sensitive information.
- If an application is compromised or acting maliciously, disabling its Internet access can limit the damage by preventing it from communicating with malicious servers.
> For users who value their security and are wary of potential threats, the ability to disable Internet access for certain applications provides reassurance that they are taking proactive steps to protect their data.
## Showcase
##### Blocking internet access for Microsoft Edge
![Showcase](https://github.com/xastrixpets/Exemptify/blob/master/media/showcase.gif)
## Installing
Clone the repository
```c
 git clone https://github.com/xastrix/Exemptify.git
```
Launch ```build-vsXX.bat``` (Where XX is the version of your VS).  
After building, run ```Exemptify.sln``` (Visual Studio Solution File) and compile project by pressing ```CTRL + Shift + B```
### Requirements
* Visual Studio
* Windows SDK
* [premake5](https://github.com/premake/premake-core/releases)
## License
Code protected by [MIT LICENSE](https://github.com/xastrix/Exemptify/blob/master/LICENSE)
