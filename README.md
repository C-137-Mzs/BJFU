FreeReciting高自由度单词程序开发日记
GNU 风格的版本号管理策略——主版本号 . 子版本号 . 修正版本号
1．项目初版本时，版本号可以为 0.1 或 0.1.0，也可以为 1.0 或 1.0.0，如果你为人很低调，我想你会选择那个主版本号为 0 的方式 ;
2．当项目在进行了局部修改或 bug 修正时，主版本号和子版本号都不变，修正版本号加 1;
3．当项目在原有的基础上增加了部分功能时，主版本号不变，子版本号加 1，修正版本号复位为 0，因而可以被忽略掉 ;
4．当项目在进行了重大修改或局部修正累积较多，而导致项目整体发生全局变化时，主版本号加 1;

2021.2.20 	
版本0.1.0
完成基本功能的实现
进入测试阶段

2020.2.23		
版本0.1.1
修复了无法记录短语的bug

2020.2.24		
版本0.1.2
修补了单词注释过长时排版不整齐的bug 

修复了修复1.1.0版本bug时遗留的背单词判断错误问题

修复了多次背单词时第一个单词跳过的bug

2020.2.24		
版本0.2.0
增加了背单词时按照单词错误次数降序排序的功能
增加了背单词错5次以上时的嘲讽功能
	
2020.2.25  
版本0.3.0
增加了判断单词是否重复录入的功能

