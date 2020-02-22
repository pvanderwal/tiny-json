# tiny-json

[![Build Status](https://travis-ci.org/rafagafe/tiny-json.svg?branch=master)](https://travis-ci.org/rafagafe/tiny-json) [![GitHub contributors](https://img.shields.io/github/contributors/rafagafe/tiny-json.svg)](https://github.com/rafagafe/tiny-json/graphs/contributors) [![Donate using PayPal](https://img.shields.io/badge/donate-PayPal-orange.svg)](https://paypal.me/rafagafe)


see https://github.com/rafagafe/tiny-json for original version of tiny-json

tiny-jsonPath
Extends tiny-json to add simple jsonPath search expressions (see https://www.npmjs.com/package/jsonpath)"
Currently only supports the '.' "Child member operator", i.e. $.parent.child

# API
To seach json_string for a particular field using jsonPath

```C
char json_string[] = "{\n"
                    "\"Time\":\"2020-02-20T19:39:43\", \n"
                    "\"ENERGY\":{\n"
                        "\"TotalStartTime\":\"2020-02-18T23:46:55\", \n"
                        "\"Total\":1.765, \n"
                        "\"Yesterday\":0.969, \n"
                        "\"Today\":0.797, \n"
                        "\"Power\":80, \n"
                        "\"Voltage\":115, \n"
                        "\"Current\":0.000 \n"
                    "} \n"
                "}";
char jsonPath = "$.ENERGY.Power"
json_t const* target = jsonPath( json_string, jsonPath) 
```
the variable 'target' will contain json_t field with a value of "80"

to return the 'real' value as a double type variable use the realPath() function
```C
double val = realPath( json_string, jsonPath);
```
val = 80.00000

to return a string representing the value you can use stringPath()
```C
char* val = stringPath( json_string, jsonPath);
```
val = "80"
