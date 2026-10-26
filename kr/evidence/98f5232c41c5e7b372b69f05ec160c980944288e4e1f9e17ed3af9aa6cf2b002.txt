
void FUN_0082cbc0(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907128;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *unaff_EDI = 1;
  unaff_EDI[1] = *(undefined4 *)(param_1 + 4);
  unaff_EDI[2] = *(undefined4 *)(param_1 + 8);
  unaff_EDI[3] = *(undefined4 *)(param_1 + 0xc);
  unaff_EDI[4] = *(undefined4 *)(param_1 + 0x10);
  unaff_EDI[7] = 0;
  unaff_EDI[8] = 0;
  if ((param_2 != (int *)0x0) && (cVar2 = FUN_0047c250(uVar3), cVar2 != '\0')) {
    FUN_007a31c0(param_1,param_2);
  }
  unaff_EDI[5] = (float)(int)unaff_EDI[1] / (float)unaff_EDI[3];
  unaff_EDI[6] = (float)(int)unaff_EDI[2] / (float)unaff_EDI[4];
  unaff_EDI[9] = 0;
  unaff_EDI[10] = 0;
  unaff_EDI[0xb] = 0;
  unaff_EDI[0xc] = 0;
  unaff_EDI[0xd] = 0;
  unaff_EDI[0xe] = 0;
  unaff_EDI[0xf] = 0;
  unaff_EDI[0x10] = 0;
  unaff_EDI[0x11] = 0;
  unaff_EDI[0x12] = 0;
  unaff_EDI[0x13] = 0;
  unaff_EDI[0x14] = 0;
  unaff_EDI[0x15] = 0;
  unaff_EDI[0x16] = 0;
  unaff_EDI[0x17] = 0;
  unaff_EDI[0x18] = 0;
  unaff_EDI[0x19] = 0;
  unaff_EDI[0x1a] = 0;
  unaff_EDI[0x1b] = 0;
  unaff_EDI[0x1c] = 0;
  unaff_EDI[0x1d] = 0;
  unaff_EDI[0x1e] = 0;
  unaff_EDI[0x1f] = 0;
  unaff_EDI[0x20] = 0;
  unaff_EDI[0x21] = 0;
  unaff_EDI[0x22] = 0;
  unaff_EDI[0x23] = 0;
  unaff_EDI[0x24] = 0;
  unaff_EDI[0x25] = 0;
  unaff_EDI[0x26] = 0;
  unaff_EDI[0x27] = 0;
  unaff_EDI[0x28] = 0;
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    LOCK();
    iVar1 = param_2[1] + -1;
    param_2[1] = iVar1;
    UNLOCK();
    if (iVar1 == 0) {
      (**(code **)*param_2)();
      LOCK();
      iVar1 = param_2[2] + -1;
      param_2[2] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)(*param_2 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

