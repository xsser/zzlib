#include <stdlib.h> 
#include <stdio.h>
#include "../getopt.h"

/*
   int main()
   {
   printf("helloworld:[%s]\n", getenv ("path"));
   printf("你好，中国\n");
   return 0;
   }
 */
    int
main (argc, argv)
    int argc;
    char **argv;
{
    int c;
    int digit_optind = 0;
    while (1)
    {
        int this_option_optind = optind ? optind : 1;

        c = getopt (argc, argv, "abc:d:01234567:89");
        if (c == EOF)
        {
            break;
        }

        switch (c)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (digit_optind != 0 && digit_optind != this_option_optind)
                {
                    printf ("digits occur in two different argv-elements.\n");
                }
                digit_optind = this_option_optind;
                printf ("option %c value '%s'\n", c, optarg);
                break;

            case 'a':
                printf ("option a\n");
                break;

            case 'b':
                printf ("option b\n");
                break;

            case 'c':
                printf ("option c with value '%s'\n", optarg);
                break;

            case 'd':
                printf ("option d with value '%s'\n", optarg);
                break;

			case 'e':
			  printf ("option e with value '%s'\n", optarg);
			  break;

            case '?':
                break;

            default:
                printf ("?? getopt returned character code 0%o ??\n", c);
        }
    }

    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
        {
            printf ("%s ", argv[optind++]);
        }
        printf ("\n");
    }

    exit (0);
}


