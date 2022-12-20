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
    const int one_Beat=60000/bpm;//�ķ�������ʱ�䣬�������������
    double Sharp_Minor=NORML;//����(����/����1.059)
    short fraction=1;		//x��֮һ����
    short dot=0;			//����
    int   freq=0;			//����
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
            Sleep(playtime*0.05);//������֮��ļ��
            Sharp_Minor=NORML;
            fraction=1;
            dot=0;
            freq=0;
            while(isspace(Music[i])) i++;
            i--;//������һ����continue��
            continue;
        }
        if(isdigit(Music[i]))
        {
            fraction=atoi(&Music[i]); //�õ�x
            while(isdigit(Music[i])) i++; //����ʣ������
            i--;//������һ����continue��
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
                        temp.append(1,Music[i]); 	///////////////Խ�羯��
                        freq=tone[temp];
        }
    }
    //���һ��ѭ�����˲��Ქ�����������ò�һ��
     std::cout<<"play:"<<playtime<<"ms "<<freq<<"HZ\n";
     Beep(freq*Sharp_Minor, (one_Beat*4/fraction)*(int)pow(1.5,dot));
}

#endif // TONES_H
