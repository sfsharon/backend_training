
/*
    From https://www.hackerrank.com/challenges/attribute-parser/problem

    We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:

</tag-name>

For example:

<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
The attributes are referenced as:

tag1~value  
tag1.tag2~name
You are given the source code in HRML format consisting of  lines. You have to answer  queries. Each query asks you to print the value of the attribute specified. Print "Not Found!" if there isn't any such attribute.

Input Format

The first line consists of two space separated integers,  and .  specifies the number of lines in the HRML source program.  specifies the number of queries.

The following  lines consist of either an opening tag with zero or more attributes or a closing tag.There is a space after the tag-name, attribute-name, '=' and value.There is no space after the last value. If there are no attributes there is no space after tag name.

 queries follow. Each query consists of string that references an attribute in the source program.More formally, each query is of the form ~ where  and  are valid tags in the input.

Constraints

Each line in the source program contains, at max, 200 characters.
Every reference to the attributes in the  queries contains at max 200 characters.
All tag names are unique and the HRML source program is logically correct.
A tag can have no attributes as well.
Output Format

Print the value of the attribute for each query. Print "Not Found!" without quotes if there is no such attribute in the source program.

Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
Sample Output

Name1
Not Found!
HelloWorld

*/
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <sstream>

using namespace std;

void tokenizeLine (const string& inStr,    /* Input */
                   vector<string>& tokens /* Output */) 
{
    /*
        Tokenize a single line according to white space, ' '
        Based on code from : https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
    */
    stringstream inStream(inStr);
    string tempStr;

    while (getline(inStr, tempStr, ' ' ))
    {
        tokens.push_back(tempStr);
    }    
}

int main() {
/*
 8/9/2020, 0200 AM
 TODO - The idea is to parse the HRML lines to an STL map.
        Each line (which is not a closing tag, e.g. "</tag5>") will be added to the map.
        The key will be the accumulated tag name, meaning that if "tag5" parents in the 
        tree hierarchy are atg1 and tag2, then the key in the map will be "tag1.tag2.tag5".
        Each time that a closing tag name is encountered, its value will be erased from the 
        name key aggregation. 
        The values can be (empty) list of attributes, that are an STL pair of
        name string and name value.
        The query will just do a search on the key, and then a search on the list of pair strings. 
*/    

    int HRML_lines = 0;
    int query_lines = 0;
    cin >> HRML_lines >> query_lines;
    cout << "Got " << HRML_lines << " HRML Lines, and " << query_lines << " Queries\n";

    vector<string> vecOfStrs(HRML_lines + query_lines);    

    // Input lines into a vector of strings
    string str;
    for (int i = 0; i < (HRML_lines + query_lines) ; i++)
    {
        getline(cin, str);
        if (str.size() > 0) 
        {
            vecOfStrs[i] = str;
        }
    }

    // Tokenize each line
    for (vector<string>::iterator it = vecOfStrs.begin(); 
         it != vecOfStrs.end(); 
         ++it) 
         {
             vector<str> myTokens;
             tokenizeLine(*it, myTokens);
         }
         


    return 0;
}