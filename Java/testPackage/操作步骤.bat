@echo off
rem ��ʼ�ļ���Client.java Server.java Test.java Utilities.java

rem ����package����.class��ִ�У� (javac���ļ������Ⱥ�˳��)
javac -d . Utilities.java Client.java Server.java
rem ���jar��
jar -cvf mygame.jar mygame

javac Test.java
java Test