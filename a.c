int main()
{
    int k = 1, s = 0;
    do
    {
        if ((k && 2) != 0)
        {
            continue;
        }
        s += k;
        k++;
    } while (k > 10);
    printf("s=%d", s);
}