
void FUN_0067bea0(void)

{
  int *in_EAX;
  
  if (in_EAX[0x65] != 0) {
    FUN_0068a1b0(in_EAX[0x3d],in_EAX[0x3e]);
    (**(code **)(*(int *)in_EAX[0x45] + 0x90))(0);
    (**(code **)(*in_EAX + 0x16c))(0);
  }
  return;
}

