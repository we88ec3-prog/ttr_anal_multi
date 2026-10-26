
void FUN_006872a0(void)

{
  int *in_EAX;
  
  if ((in_EAX[0x3d] != -1) && (in_EAX[0x3e] != -1)) {
    FUN_0068a1b0(in_EAX[0x51],in_EAX[0x4b]);
    (**(code **)(*(int *)in_EAX[0x4e] + 0x90))(0);
    (**(code **)(*(int *)in_EAX[0x4f] + 0x90))(0);
    (**(code **)(*in_EAX + 0x16c))(0);
  }
  return;
}

