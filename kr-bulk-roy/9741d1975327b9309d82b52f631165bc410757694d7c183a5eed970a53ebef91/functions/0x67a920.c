
void FUN_0067a920(void)

{
  int *in_EAX;
  
  if ((in_EAX[0x44] != -1) && (in_EAX[0x45] != -1)) {
    FUN_0068a1b0(in_EAX[0x47],in_EAX[0x3d]);
    (**(code **)(*(int *)in_EAX[0x43] + 0x90))(0);
    (**(code **)(*in_EAX + 0x16c))(0);
  }
  return;
}

