
void FUN_00845670(void)

{
  uint in_EAX;
  
  if (DAT_00f7af98 < in_EAX) {
    DAT_00f7af98 = in_EAX;
    if (DAT_00f7afa0 != 0) {
      FUN_00891d3d(DAT_00f7afa0);
    }
    DAT_00f7afa0 = 0;
    if (DAT_00f7af98 != 0) {
      DAT_00f7afa0 = FUN_0087dc3d(DAT_00f7af98);
    }
  }
  DAT_00f7af9c = 0;
  return;
}

