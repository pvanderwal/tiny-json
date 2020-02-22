/* To use enter the jsonPath expression on the command line. 
e.g.  ./example .ENERGY.Yesterday
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../tiny-jsonPath.h"

/* Parser a json string. */

int
main(int argc, char *argv[])
{
    int val;
    char str[] = "{\n"
                    "\t\"Time\":\"2020-02-20T19:39:43\", \n"
                    "\t\"ENERGY\":{\n"
                        "\t\t\"TotalStartTime\":\"2020-02-18T23:46:55\", \n"
                        "\t\t\"Total\":1.765, \n"
                        "\t\t\"Yesterday\":0.969, \n"
                        "\t\t\"Today\":0.797, \n"
                        "\t\t\"Period\":0, \n"
                        "\t\t\"Power\":0, \n"
                        "\t\t\"ApparentPower\":0, \n"
                        "\t\t\"ReactivePower\":0, \n"
                        "\t\t\"Factor\":0.00, \n"
                        "\t\t\"Voltage\":115, \n"
                        "\t\t\"Current\":0.000 \n"
                    "\t} \n"
                "}";

    double result = realPath(str, argv[1]);

    if (NAN == result){
        printf("path %s : Error not found or not a real number", argv[1]);
    } else {
        val = 1 > result ? result*1000.0 : result;
        printf("\n\nSearching\n %s \nUsing jsonPath expression: %s.\n\nThe result as an Integer ( *1000 if less than 1) = %d\n and as a floating point value = (%f)\n\n", str, argv[1], val, result);

    }

    return EXIT_SUCCESS;
}
