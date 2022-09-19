#include <bits/stdc++.h>
using namespace std;

int main()
{
     unordered_map<string, int> m; // unordered map , random values at random locations or print randomly
     // map<string, int> m; //ordered map  based on rbt , prints ordered value acc to keys

     pair<string, int> p = {"ayush", 10};
     m.insert(p);
     cout << m.at("ayush") << endl;
     cout << m["ayush"] << endl
          << endl;

     pair<string, int> p2 = make_pair("negi", 2);
     m.insert(p2);
     cout << m.at("negi") << endl;
     cout << m["negi"] << endl
          << endl;

     m["hello"] = 3;
     cout << m["hello"] << endl;

     m.insert({"kumar", 2});
     cout << m["kumar"] << endl;
     //     cout << m["bye"] << endl; // will make a new entity "bye" and key will be 0 by default if it doesnot exist.
     //     cout << m.at("bye") << endl
     // << endl;

     // cout << m.at("nokey") << endl; // error , no key found.

     cout << "size : " << m.size() << endl; // size

     // count gives 0 or 1 ie if the element is present.
     cout << "count : ayush " << m.count("ayush") << endl;
     cout << "count: " << m.count("hsdsa") << endl;

     //     erase
         cout << m.erase("negi") << endl; // returns 1 if element is present and deleted and 0 if element is not present.
         cout << "size : " << m.size() << endl
              << endl;

         auto it = m.find("ayush");
         cout << (*it).first << " " << (*it).second << endl;
     //     // print all elements :
         for (auto it = m.begin(); it != m.end(); it++)
         {
             cout << it->first << " " << it->second << endl;
         }
     //      string str = "23444";
     //     int c =stoi(str);
     // cout<<c;
     //  if(m.find("sui")==m.end())
     //  {
     //     char ch='a'+3;
     //     cout<<ch;
     //  }
     //         m.clear()//clears all values
     return 0;
}