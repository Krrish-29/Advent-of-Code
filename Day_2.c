#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file;
    char line[100];
    int numbers[8],num_count,safe=0,increasing=0,decreasing=0,duplicate=0,outofrange=0,outofrangeindex;
    file = fopen("Day_2.txt", "r");
    while (fgets(line, sizeof(line), file) != NULL) {
        num_count = sscanf(line, "%d %d %d %d %d %d %d %d",&numbers[0], &numbers[1], &numbers[2], &numbers[3],&numbers[4], &numbers[5], &numbers[6], &numbers[7]);
        increasing=0,decreasing=0,duplicate=0,outofrange=0;
        for(int i=0;i<num_count-1;i++){
            int x=numbers[i]-numbers[i+1];
            if(x>=1&&x<=3){
                decreasing++;
            }
            else if(x<=-1&&x>=-3){
                increasing++;
            }
            else if(x==0){
                duplicate++;
            }
            else if(abs(x)>3){
                outofrange++;
                outofrange=i;
            }
        }
        if((duplicate<=1&&outofrange==0)&&(increasing==0||decreasing==0)){
            safe++;
        }
        else if((duplicate==0&&outofrange<=1)){
            if(outofrange==1&&(increasing==0||decreasing==0)){
                safe++;
            }
            // else if(outofrange==1&&(increasing>decreasing&&decreasing==1)){
            //     safe++;
            // }
            // else if(outofrange==1&&(decreasing>increasing&&increasing==1)){
            //     safe++;
            // }

        }
        else if((duplicate==0&&outofrange==0)&&decreasing==1){
            safe++;
        }
        else if((duplicate==0&&outofrange==0)&&increasing==1){
            safe++;
        }
    }
    printf("%d",safe);
    fclose(file);
    return 0;
}
/*
import numpy as np

with open("Day_2.txt") as f:
    arrs = [[int(i) for i in l.split()] for l in f]

def is_safe(d):
    return len(d[(d > 0) & (d <= 3)]) == len(d) or len(d[(d < 0) & (d >= -3)]) == len(d)

part1 = 0
part2 = 0
for a in arrs:
    if is_safe(np.diff(a)):
        part1 += 1
        part2 += 1
    else:
        for i in range(len(a)):
            if is_safe(np.diff(a[:i]+a[i+1:])):
                part2 += 1
                break
print(part1)
print(part2)*/