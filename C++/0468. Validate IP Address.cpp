class Solution {
public:
    string validIPAddress(string queryIP) {
        regex ipv4("((25[0-5]|2[0-4]\\d|[1]\\d\\d?|[0-9])\.){3}(25[0-5]|2[0-4]\\d|[1]\\d\\d?|[0-9])");
        if (regex_match(queryIP, ipv4)) {
            return "IPv4";
        }
        regex ipv6("([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}");
        if (regex_match(queryIP, ipv6)) {
            return "IPv6";
        }
        return "Neither";
    }
};