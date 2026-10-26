
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00867210(void)

{
  short sVar1;
  int *in_EAX;
  int iVar2;
  short *local_8;
  
  if (in_EAX != (int *)0x0) {
    if (DAT_00fba944 != (int *)0x0) {
      (**(code **)(*DAT_00fba944 + 8))(DAT_00fba944);
      DAT_00fba944 = (int *)0x0;
    }
    _DAT_00fba948 = 10000;
    (**(code **)(*in_EAX + 0x6c))();
    local_8 = (short *)0x0;
    (**(code **)(*DAT_00fba944 + 0x2c))(DAT_00fba944,0,0,&local_8,0);
    iVar2 = 0;
    do {
      sVar1 = (short)iVar2 * 4;
      *local_8 = sVar1;
      local_8[1] = sVar1 + 2;
      local_8[2] = sVar1 + 1;
      local_8[3] = sVar1 + 3;
      local_8[4] = sVar1 + 1;
      local_8[5] = sVar1 + 2;
      local_8 = local_8 + 6;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 10000);
    (**(code **)(*DAT_00fba944 + 0x30))(DAT_00fba944);
  }
  return;
}

