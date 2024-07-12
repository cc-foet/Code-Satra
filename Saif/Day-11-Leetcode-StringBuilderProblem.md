[Defanging and IP Address](https://leetcode.com/problems/defanging-an-ip-address/)

```java
        public class solution {
                public static void main(String[] args )
                {
                        String IP = "1.1.1.1";
                        System.out.println(defangIPAddress(IP));


                }
                public static String defangIPAddress (String address) {
                        StringBuilder result = new StringBuilder();
                        for(char c : address.toCharArray()) { // using For each loop to iterate over the string
                                        if(c == '.') { // Checking if the current character is '.' or not if true
                                                result.append("[.]");  // if current char is dot then appending "[.]" to the result string

                                        }
                                        else {
                                                result.append(c); // Else appending the character to the result
                                        }

                        }
                        return result.toString(); // Converting the result from stringBuilder to string
                }
        }

```