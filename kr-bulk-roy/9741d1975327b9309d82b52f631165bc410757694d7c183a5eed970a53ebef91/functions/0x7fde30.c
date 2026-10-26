
undefined4 * FUN_007fde30(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00914534;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 0;
  *param_1 = IS3D::CFieldObjectInstanceSimple::vftable;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  pcVar5 = in_EDX;
  do {
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar5 - (int)(in_EDX + 1));
  param_1[10] = param_2;
  param_1[0xc] = param_2;
  param_1[9] = 0x11;
  param_1[0xb] = param_3;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x11] = 1;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  piVar1 = param_1 + 0x1a;
  *piVar1 = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  param_1[0x20] = 0;
  param_1[0x21] = 0x3f800000;
  param_1[0x1e] = 1;
  param_1[0x1f] = param_4;
  param_1[0x22] = 0;
  param_1[0x23] = 1;
  FUN_007fe0c0(param_1);
  FUN_007fe190(param_1);
  FUN_007cbb00(param_2,piVar1,uVar4);
  param_2 = 0;
  if (param_1[0x1b] - *piVar1 >> 2 != 0) {
    do {
      iVar3 = *(int *)(*piVar1 + param_2 * 4);
      FUN_0084b1d0();
      *(undefined4 *)(iVar3 + 0xa8) = 1;
      param_2 = param_2 + 1;
    } while (param_2 < (uint)(param_1[0x1b] - *piVar1 >> 2));
  }
  if (*(int *)(param_1[0x1f] + 8) != 0) {
    param_1[9] = 0xc;
  }
  if (*(int *)(param_4 + 0x10) != 0) {
    param_1[9] = 2;
  }
  ExceptionList = local_10;
  return param_1;
}

