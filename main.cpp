//#include <QCoreApplication>
#include <iostream>
#include "tones.h"

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    //≥ı ºªØ
    Tone tone;


    tone["VC"]=262;         //Midc
    tone["VD"]=294;
    tone["VE"]=330;
    tone["VF"]=349;
    tone["VG"]=392;
    tone["VA"]=440;
    tone["VB"]=493;

    tone["WC"]=532;
    tone["WD"]=588;
    tone["WE"]=660;
    tone["WF"]=698;
    tone["WG"]=784;
    tone["WA"]=880;
    tone["WB"]=988;

    tone["XC"]=1046;
    tone["XD"]=1175;
    tone["XE"]=1319;
    tone["XF"]=1397;
    tone["XG"]=1568;
    tone["XA"]=1760;
    tone["XB"]=1976;

    tone["YC"]=2145;
    tone["YD"]=2369;
    tone["YE"]=2615;
    tone["YF"]=2888;
    tone["YG"]=3188;
    tone["YA"]=3520;
    tone["YB"]=3886;

    tone["ZC"]=4291;
    tone["ZD"]=4738;
    tone["ZE"]=5231;
    tone["ZF"]=5775;
    tone["ZG"]=6376;
    tone["ZA"]=7040;
    tone["ZB"]=7773;
    int bpm=120;

    std::string Music;
    std::cout<<"VC=262 HZ\n"
               "VD=294 HZ\n"
               "VE=330 HZ\n"
               "VF=349 HZ\n"
               "VG=392 HZ\n"
               "VA=440 HZ\n"
               "VB=493 HZ\n"
               "\n"
               "WC=532 HZ\n"
               "WD=588 HZ\n"
               "WE=660 HZ\n"
               "WF=698 HZ\n"
               "WG=784 HZ\n"
               "WA=880 HZ\n"
               "WB=988 HZ\n"
               "\n"
               "XC=1046 HZ\n"
               "XD=1175 HZ\n"
               "XE=1319 HZ\n"
               "XF=1397 HZ\n"
               "XG=1568 HZ\n"
               "XA=1760 HZ\n"
               "XB=1976 HZ\n"
               "\n"
               "YC=2145 HZ\n"
               "YD=2369 HZ\n"
               "YE=2615 HZ\n"
               "YF=2888 HZ\n"
               "YG=3188 HZ\n"
               "YA=3520 HZ\n"
               "YB=3886 HZ\n"
               "\n"
               "ZC=4291 HZ\n"
               "ZD=4738 HZ\n"
               "ZE=5231 HZ\n"
               "ZF=5775 HZ\n"
               "ZG=6376 HZ\n"
               "ZA=7040 HZ\n"
               "ZB=7773 HZ\n"
               "\n";
    std::cout<<"bpm=";
    std::cin>>bpm;
    std::cout<<"Music here,\"!\"to stop:\n";
    char ch;
    while((ch=getchar())!='!')
    {
        Music.append(1,ch);
    }
    SoundPlay(Music,tone,bpm);

    return 0;
}
