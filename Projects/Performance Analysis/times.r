#install ggpolt package
#install.packages(c("ggplot2"), repos = "http://cran.utstat.utoronto.ca/")

#load library
library("ggplot2")

#store csv into data frame
timeData = read.csv("\\times.csv")

#add column of adjusted time
timeData$Adjusted.Time <- (timeData$UUT.Time - timeData$Overhead.Time)

#adjusted time calculation
print(aggregate(Adjusted.Time ~ DLL.Name, data=timeData, FUN=mean))

#plot Data
ggplot(timeData, aes(x=Adjusted.Time)) + geom_density(aes(group=DLL.Name, colour=DLL.Name)) + ggtitle("Compiler Times") 