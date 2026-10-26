
void FUN_00679220(void)

{
  int *in_EAX;
  
  if ((in_EAX[0x46] != 0) && (in_EAX[0x47] != 0)) {
    FUN_0068a1b0(in_EAX[0x3d],in_EAX[0x3e]);
    (**(code **)(*in_EAX + 0x16c))(0);
  }
  return;
}

