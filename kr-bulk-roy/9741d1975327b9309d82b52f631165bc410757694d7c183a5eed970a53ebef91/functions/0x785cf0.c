
void FUN_00785cf0(void)

{
  undefined4 *in_EAX;
  
  in_EAX[3] = 1;
  in_EAX[4] = 1;
  in_EAX[2] = gbORT::vftable;
  *in_EAX = gbHybridTrack<gbQuat>::vftable;
  *(undefined1 *)(in_EAX + 5) = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[1] = 4;
  return;
}

