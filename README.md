# QSoundPlayerc
(只是用QCreator开发，一点库都没用)  
能够发出哔哔声的播放器  
*本项目遵循GPLv3

## 食用方法  
1. 打开文本编辑器  
> Open a text editor   
2. 写乐谱（语法见下）  
> Write music score (see below for how)  
3. 拖到bat里面播放  
> Drag onto the batch file to play 

*当然你打开QSndPlrc直接输也可以  
> you can also directly open QSndPlrc and enter your music score there
*建议播放的时候后台随便再放点什么，不然会很卡（原理是刷新下缓存？）
> It is recommended to play something in the background when runnig this program, otherwise it will be too laggy (the principle is to refresh the cache?)
## 文件格式（语法）
```
120
4WE 8VA 8VA 4WC 4WE	8WD 16WD 16WE 8WD 8WC 8WD 8WC 4VA
4WE 8VA 8VA 4WC 4WE	8WG 16WD 16WE 8WD 8WC 8WD 8WC 8VB 8VG
4WE 8VA 8VA 4WC 4WE	8WD 16WD 16WE 8WD 8WC 8WD 8WC 8VA 8VG
4WE 8VA 8VA 4WC 4WE	8WG 8WE WG!
```
以该乐谱为例，第一行是乐曲的BPM数  
之后就是乐谱主体  
乐谱必须以!( __英文__ 叹号)结束    
    
一个音符有三部分，时值，音级和音阶  
时值用一个整数表示，表示几分之一音符  
支持VWXYZ五个音级，分别对应C3到C7的音级
使用CDEFGAB表示音阶， __小写__ b表示降调，#表示升调  
结尾可以带附点  
举例  
WC------>全(一分之一)音符中央C(即W八度的C),（1省略就默认为1）   
4YD.---->四分之一附点音符D6(即Y八度的D)   
  
注：上面的乐谱就是《最炫民族风的前奏》，release的包里面有的 

> Taking this score as an example, the first line is the BPM number of the score<br/>
And then it's the main part of the score<br/>
The score must end with "!"<br/><br/>
A note has three parts, duration, scale and scale step<br/> 
The duration is an integer. For example, 16 means it's a sixteenth note<br/>
CDEFGAB are used to represent the scale. __Lower__ b stands for falling tone, and # stands for rising one<br/> 
five scale step of VWXYZ are supported, which corresponded to the scale step from C3 to C7 respectively<br/><br/>
egs:<br/>
WC -------->whole (1th) midC note (that is, C in W scale step), (defaults to 1)<br/>
4YD. ---- -->4th dotted D6 (D of Y octave)<br/>
Note: The score above is part of _最炫民族风(The Hottest Ethnic Trend )_ , which is contained in the release<br/>
