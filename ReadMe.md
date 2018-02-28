## KSHInterpreter USAGE



### CAT
用于观看某个文件的内容

     cat filename 

+	filename	要显示的的文件的路径

### CLEAR
清除屏幕

    clear
### CMP
用于比较两个文件是否有差异。当相互比较的两个文件完全一样时，则该指令不会显示任何信息。若发现有所差异，预设会标示出第一个不同之处的字符和列数编号。

    cmp filename1 filename2

+	filename1     要比较的第一个文件
  +filename2     要比较的第二个文件     

### CP
主要用于复制文件或目录。

    cp filename1 filename2

+	filename1 被复制的文件路径
  +filename2 filename复制到的文件路径

### DATE
显示当前系统时间

    date

### ECHO
用于字符串的输出

    echo “Hello world”

### FIND
指定目录下查找文件。任何位于参数之前的字符串都将被视为欲查找的目录名。如果使用该命令时，不设置任何参数，则find命令将在当前目录下查找子目录与文件。并且将查找到的子目录和文件全部进行显示。

    find filename1

+	filename1 查找的文件名

### SORT
对文件内容进行排序

    sort filename

+	filename	指定被排序的文件路径

### IFCONFIG
用于配置和显示Linux内核中网络接口的网络参数。用ifconfig命令配置的网卡信息，在网卡重启后机器重启后，配置就不存在。要想将上述的配置信息永远的存的电脑里，那就要修改网卡的配置文件了。

    ifconfig

### LS
用来显示目标列表，在Linux中是使用率较高的命令。ls命令的输出信息可以进行彩色加亮显示，以分区不同类型的文件。

    ls

### MKDIR
创建目录。该命令创建由[dirname](http://man.linuxde.net/dirname)命名的目录。如果在目录名的前面没有加任何路径名，则在当前目录下创建由dirname指定的目录；如果给出了一个已经存在的路径，将会在该目录下创建一个指定的目录。在创建目录时，应保证新建的目录与它所在目录下的文件没有重名。 

    mkdir dirname
### more

分页显示大文本文件的命令

    more filename1

+	filename1 	大文本文件路径名

### MV
对文件或目录重新命名，或者将文件从一个目录移到另一个目录中。

    mv filename1 filename2

+	filename1 被重命名的文件
  +filename2 重命名的文件名


### PS
显示瞬间行程 (process) 的动态 

    ps
### PWD

查看”当前工作目录“的完整路径

    pwd
### MESG

用于设置当前终端的写权限，即是否让其他用户向本终端发信息

```
mesg(参数)
```

y/n：y表示运行向当前终端写信息，n表示禁止向当前终端写信息。

### RM

可以删除一个目录中的一个或多个文件或目录，也可以将某个目录及其下属的所有文件及其子目录均删除掉。对于链接文件，只是删除整个链接文件，而原有文件保持不变。

    rm filename1

+	filename1 删除的文件路径名

### TREE
以树形显示文件夹结构

    tree
### TAC

把文件内容反过来显示，文件内容的最后一行先显示，第一行最后显示。

    tac filename1

+	filename1    显示的文件路径名

### WHO

用于显示谁登录了系统

```
who
```

### 

