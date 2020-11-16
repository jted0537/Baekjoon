#include <iostream>
#include <string>

using namespace std;
bool broken[11] = {
    false,
};
bool checker(int n);
int length(int n);
int main()
{
    int ornum;
    int n;
    int buf;
    cin >> ornum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        broken[buf] = true;
    }
    int ab = abs(ornum - 100);
    if (ab != 0)
    {
        for (int i = 0; i < 1000001; i++)
        {
            if (checker(i))
            {
                int alp = length(i);
                int d = abs(ornum - i);
                if (d + alp < ab)
                    ab = d + alp;
            }
        }
    }
    cout << ab;
}
bool checker(int n)
{
    if (n == 0)
    {
        if (broken[0])
            return false;
        else
        {
            return true;
        }
    }
    while (n > 0)
    {
        int i = n % 10;
        n /= 10;
        if (broken[i])
            return false;
    }
    return true;
}
int length(int n) {
	int len = 0;
	if (n == 0) return 1;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}


