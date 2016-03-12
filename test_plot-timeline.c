#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

static void program_log (const char *format, ...)
{
        va_list args;
        char *formatted, *str;

        va_start (args, format);
        formatted = g_strdup_vprintf (format, args);
        va_end (args);

        str = g_strdup_printf ("MARK: %s: %s", g_get_prgname(), formatted);
        g_free (formatted);

        access (str, F_OK);
        g_free (str);
} 

int function1()
{
        program_log("This is function [%s]\n", __func__);
        return 0;
}

int function2()
{
        program_log("This is function [%s]\n", __func__);
        function1();
        return 0;
}

int function3()
{
        program_log("This is function [%s]\n", __func__);
        function2();
        return 0;
}

int function4()
{
        program_log("This is function [%s]\n", __func__);
        function3();
        return 0;
}

int function5()
{
        program_log("This is function [%s]\n", __func__);
        function4();
        return 0;
}

int function6()
{
        program_log("This is function [%s]\n", __func__);
        function5();
        return 0;
}

int main()
{
        program_log("main is getting called");
        program_log("calling function6");
        function6();
}
