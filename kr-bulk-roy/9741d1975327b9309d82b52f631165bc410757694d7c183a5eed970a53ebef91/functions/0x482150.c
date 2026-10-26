
void FUN_00482150(void)

{
  int *in_EAX;
  
  if ((*(int *)(in_EAX[0x3e] + 0x250) != -1) && (*(int *)(in_EAX[0x3f] + 0x250) != -1)) {
    FUN_0068a1b0(in_EAX[0x3d],in_EAX[0x3f]);
    (**(code **)(*in_EAX + 0x16c))(0);
  }
  return;
}

