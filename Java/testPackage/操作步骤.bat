@echo off
rem 初始文件：Client.java Server.java Test.java Utilities.java

rem 根据package编译.class并执行： (javac的文件不分先后顺序)
javac -d . Utilities.java Client.java Server.java
rem 打成jar包
jar -cvf mygame.jar mygame

javac Test.java
java Test