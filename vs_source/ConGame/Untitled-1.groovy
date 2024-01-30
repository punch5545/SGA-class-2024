
int main()
{
    int key = 0;
    while(1)
    {
        if(_kbhit())
        {
            while(1) { key = _getch(); }
        }

        switch(key)
        {
            case 'w':
            {
                // y좌표 위로 이동
                break;
            }
            case 'a':
            {
                // x좌표 좌로 이동
                break;
            }
            case 's':
            {
                // y좌표 아래로 이동
                break;
            }
            case 'd':
            {
                // x좌표 우로 이동
                break;
            }
            default: break;
        }


    }

}