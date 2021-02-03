int romanToInt(char * s)
{
    int ret = 0;
    while (*s)
    {
        switch (*s++)
        {
            case 'I': ret += (*s == 'V' || *s == 'X') ? -1 : 1; break;
            case 'X': ret += (*s == 'L' || *s == 'C') ? -10 : 10; break;
            case 'C': ret += (*s == 'D' || *s == 'M') ? -100 : 100; break;
            case 'M': ret += 1000; break;
            case 'V': ret += 5; break;
            case 'L': ret += 50; break;
            case 'D': ret += 500; break;
            default: return 0;
        }
    }
    return ret;
}
