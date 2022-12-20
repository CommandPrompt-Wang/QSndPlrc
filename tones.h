#ifndef TONES_H
#define TONES_H

#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <windows.h>
#include <cmath>

typedef std::map<std::string,DWORD> Tone;
#define SHARP 1.059
#define MINOR (1/1.059)
#define NORML 1


void SoundPlay(std::string Music,  Tone tone, const int bpm)
{
    const int one_Beat=60000/bpm;//四分音符的时间，所以下面乘了四
    double Sharp_Minor=NORML;//升降(乘以/除以1.059)
    short fraction=1;		//x分之一音符
    short dot=0;			//附点
    int   freq=0;			//音高
    int playtime=(one_Beat*4/fraction)*(int)pow(1.5,dot);
    while(isspace(Music[0]))
    {
        Music=(Music.substr(1,Music.length()-1));
    }
    for(unsigned int i=0;i<Music.length();i++)
    {
        if(isspace(Music[i]))
        {
            playtime=(one_Beat*4/fraction)*(int)pow(1.5,dot);
            std::cout<<"play:"<<playtime<<"ms "<<freq<<"HZ\n";
            Beep(freq*Sharp_Minor, playtime*0.95);
            Sleep(playtime*0.05);//音与音之间的间距
            Sharp_Minor=NORML;
            fraction=1;
            dot=0;
            freq=0;
            while(isspace(Music[i])) i++;
            i--;//多整了一个（continue）
            continue;
        }
        if(isdigit(Music[i]))
        {
            fraction=atoi(&Music[i]); //得到x
            while(isdigit(Music[i])) i++; //跳过剩余数字
            i--;//多整了一个（continue）
            continue;
        }
        switch(Music[i]){
            case '#':	Sharp_Minor=SHARP;
                        break;
            case 'b':	Sharp_Minor=MINOR;
                        break;
            case '.':	dot++;
                        break;
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':	std::string temp;
                        temp.append(1,Music[i]);
                        i++;
                        temp.append(1,Music[i]); 	///////////////越界警告
                        freq=tone[temp];
        }
    }
    //最后一个循环完了不会播放声音，还得补一句
     std::cout<<"play:"<<playtime<<"ms "<<freq<<"HZ\n";
     Beep(freq*Sharp_Minor, (one_Beat*4/fraction)*(int)pow(1.5,dot));
}

#endif // TONES_H
