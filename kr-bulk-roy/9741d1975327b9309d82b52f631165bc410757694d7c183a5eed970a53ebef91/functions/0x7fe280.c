
void FUN_007fe280(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  undefined1 local_70 [44];
  undefined1 local_44 [48];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092b7ce;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff68);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar5 = DAT_00fb76e8;
  local_c = 0xffffffff;
  if (DAT_00fb76e8 != 0) {
    if (*(int *)(*(int *)(in_ECX + 0x7c) + 0xc) == 0) {
      pfVar4 = (float *)(**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(local_44);
      fVar2 = *(float *)(in_ECX + 0x34) - *pfVar4;
      fVar1 = *(float *)(in_ECX + 0x38) - pfVar4[1];
      fVar3 = *(float *)(in_ECX + 0x3c) - pfVar4[2];
      fVar2 = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1;
      if ((fVar2 <= *(float *)(iVar5 + 0x30) * *(float *)(iVar5 + 0x30)) &&
         (fVar1 = *(float *)(*(int *)(in_ECX + 0x7c) + 0x18), fVar2 <= fVar1 * fVar1))
      goto LAB_007fe488;
    }
    else {
      (**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(local_70);
      fVar6 = (float10)FUN_008ff870();
      if ((float)fVar6 <=
          *(float *)(*(int *)(*(int *)(*(int *)(DAT_00fba838 + 0x54) + 0xc +
                                      *(int *)(*(int *)(DAT_00fba838 + 0x54) + 4) * 4) + 0xc) + 4) +
          *(float *)(in_ECX + 0x40)) {
        if (*(float *)(*(int *)(in_ECX + 0x7c) + 0x18) + *(float *)(in_ECX + 0x40) < (float)fVar6) {
          *(undefined4 *)(in_ECX + 4) = 1;
          ExceptionList = local_14;
          return;
        }
        goto LAB_007fe488;
      }
    }
    *(undefined4 *)(in_ECX + 4) = 1;
    ExceptionList = local_14;
    return;
  }
LAB_007fe488:
  if (DAT_00fb76e4 == 0) {
    iVar5 = 1;
  }
  else {
    iVar5 = FUN_00838860(*(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x38),
                         *(undefined4 *)(in_ECX + 0x3c),*(undefined4 *)(in_ECX + 0x40));
  }
  *(uint *)(in_ECX + 4) = (uint)(iVar5 == 0);
  ExceptionList = local_14;
  return;
}

