
void FUN_00680d00(void)

{
  int *in_EAX;
  
  if (((in_EAX[0x3e] != -1) && (in_EAX[0x3f] != -1)) && (in_EAX[0x40] != -1)) {
    FUN_0068a1b0(in_EAX[0x3d],in_EAX[0x41]);
    (**(code **)(*(int *)in_EAX[0x48] + 0x90))(0);
    (**(code **)(*in_EAX + 0x16c))(0);
  }
  return;
}

