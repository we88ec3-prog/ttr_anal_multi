
/* WARNING: Type propagation algorithm not settling */

void FUN_007feb70(void)

{
  int *piVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  uint uVar6;
  int iVar7;
  void *local_14 [3];
  int local_8;
  
  local_8 = 0xffffffff;
  local_14[2] = &LAB_009320e3;
  local_14[1] = ExceptionList;
  ExceptionList = local_14 + 1;
  FUN_008380b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  uVar6 = 0;
  local_8 = 0;
  if (in_ECX[1] == 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    uVar2 = in_ECX[0x13] - in_ECX[0x12] >> 2;
    if (uVar2 != 0) {
      do {
        pvVar3 = (void *)(**(code **)(*(int *)in_ECX[0xc] + 0x30))
                                   (*(undefined4 *)(in_ECX[0x12] + uVar6 * 4));
        local_14[0] = pvVar3;
        if ((local_14 < DAT_00fb7778) && (DAT_00fb7774 <= local_14)) {
          iVar7 = (int)local_14 - (int)DAT_00fb7774;
          if (DAT_00fb7778 == DAT_00fb777c) {
            FUN_0079bf10();
          }
          if (DAT_00fb7778 != (void **)0x0) {
            *DAT_00fb7778 = DAT_00fb7774[iVar7 >> 2];
          }
        }
        else {
          if (DAT_00fb7778 == DAT_00fb777c) {
            FUN_0079bf10();
          }
          if (DAT_00fb7778 != (void **)0x0) {
            *DAT_00fb7778 = pvVar3;
          }
        }
        DAT_00fb7778 = DAT_00fb7778 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar2);
    }
    iVar5 = DAT_00fb7740;
    iVar4 = (**(code **)(*in_ECX + 4))();
    iVar7 = *(int *)(iVar4 * 0x2004 + 0x2000 + iVar5);
    iVar5 = iVar4 * 0x2004 + iVar5;
    if (iVar7 < 0x800) {
      *(int **)(iVar5 + iVar7 * 4) = in_ECX;
      piVar1 = (int *)(iVar5 + 0x2000);
      *piVar1 = *piVar1 + 1;
    }
    iVar7 = DAT_00fb7740;
    if ((*(float *)(in_ECX[0xc] + 0x70) < *(float *)(DAT_00fba838 + 0xd8)) &&
       (*(int *)(DAT_00fb7740 + 0x16028) < 0x800)) {
      *(int **)(DAT_00fb7740 + 0x14028 + *(int *)(DAT_00fb7740 + 0x16028) * 4) = in_ECX;
      *(int *)(iVar7 + 0x16028) = *(int *)(iVar7 + 0x16028) + 1;
    }
    if ((in_ECX[0x22] != 0) && (in_ECX[0xb] != in_ECX[0xc])) {
      FUN_00802f70(in_ECX[0x22]);
    }
  }
  FUN_00837fd0();
  PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  ExceptionList = local_14[1];
  return;
}

