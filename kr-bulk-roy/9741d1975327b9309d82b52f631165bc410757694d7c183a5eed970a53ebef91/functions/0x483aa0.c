
void FUN_00483aa0(void)

{
  int *in_EAX;
  
  if (*(int *)(in_EAX[0x3e] + 0x250) != -1) {
    FUN_0068a1b0(in_EAX[0x3d],in_EAX[0x3e]);
    (**(code **)(*(int *)in_EAX[0x42] + 0x90))(0);
    (**(code **)(*in_EAX + 0x16c))(0);
  }
  return;
}

