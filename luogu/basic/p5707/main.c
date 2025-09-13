#include <stdio.h>
#include <math.h>


// 10 min to sort trash
#define OFFSET 10
// timeline is 8:00 
#define TIMELINE 480


int main(){
  int s,v;
  int duration;
  // start timeline
  int timeline;


  scanf("%d %d",&s,&v);
  // 这里不能用s/v，因为s,v都是整数，是整数除法，直接舍去小数的
  duration = (int)ceil((double)s/v);
  // 总共需要的时间
  duration += OFFSET;

  timeline = TIMELINE - duration;
  // 考虑过了12点怎么办
  if(timeline < 0){
    timeline += 60*24;
  }

  int hour = timeline / 60;
  int minutes = timeline % 60 ;
  printf("%02d:%02d",hour,minutes);

}