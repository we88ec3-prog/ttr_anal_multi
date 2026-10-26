
void FUN_008e94e0(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 local_628;
  undefined4 local_624;
  int local_61c;
  undefined4 *local_618;
  uint local_614;
  uint local_610;
  int local_60c;
  int local_608;
  undefined1 local_604 [16];
  int local_5f4;
  undefined4 local_5e4;
  undefined4 local_5dc;
  undefined4 local_5d8;
  byte local_5bf;
  int local_5bc;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  undefined4 local_34;
  undefined4 local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(param_1 + 4);
  local_618 = *(undefined4 **)(*(int *)(iVar1 + 0x1e8) + 0xc);
  if ((*(uint *)(iVar1 + 0x10) <= param_3) && (*(int *)(*(int *)(iVar1 + 0x80) + 0x30) == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((param_4 & 0x400) != 0) {
    param_4 = param_4 | 3;
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0xac) = 0x10000;
    *(undefined4 *)(param_1 + 0xb0) = 0x10000;
  }
  else {
    *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_2 + 0x14);
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  local_610 = param_4 & 1;
  if (local_610 == 0) {
    local_614 = CONCAT31(local_614._1_3_,1);
    if ((param_4 & 2) == 0) goto LAB_008e95a2;
  }
  local_614 = local_614 & 0xffffff00;
LAB_008e95a2:
  *(undefined4 *)(param_1 + 0x48) = 0x6f75746c;
  iVar3 = (*(code *)*local_618)
                    (local_604,iVar1,param_2,param_1,*(undefined4 *)(iVar1 + 0x1a4),
                     *(undefined4 *)(iVar1 + 0x210),local_614,(int)param_4 >> 0x10 & 0xf,
                     FUN_008e9260);
  if (iVar3 == 0) {
    local_5bf = (byte)(param_4 >> 10) & 1;
    local_b0 = *(undefined4 *)(iVar1 + 0x194);
    local_ac = *(undefined4 *)(iVar1 + 0x198);
    local_a8 = *(undefined4 *)(iVar1 + 0x19c);
    local_34 = *(undefined4 *)(iVar1 + 0x220);
    local_30 = *(undefined4 *)(iVar1 + 0x21c);
    iVar3 = FUN_008e9120();
    if (iVar3 != 0) {
      (*(code *)local_618[1])(local_604);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_18 = local_a4;
    local_14 = local_a0;
    local_10 = local_9c;
    local_c = local_98;
    local_61c = local_90;
    (*(code *)local_618[1])(local_604);
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 1 | 4;
    if ((param_4 & 0x400) == 0) {
      iVar3 = FUN_008b7c80(local_5dc);
      *(int *)(param_1 + 0x28) = iVar3 >> 0x10;
      iVar3 = FUN_008b7c80(local_5dc);
      *(int *)(param_1 + 0x38) = iVar3 >> 0x10;
      *(undefined1 *)(*(int *)(param_1 + 0x9c) + 8) = 0;
      if ((param_4 & 0x10) == 0) {
        iVar3 = FUN_008b7c80(local_5d8);
        *(int *)(param_1 + 0x34) = iVar3 >> 0x10;
        iVar3 = FUN_008b7c80(local_5d8);
        iVar3 = iVar3 >> 0x10;
      }
      else {
        iVar3 = *(int *)(iVar1 + 0x1d8) - *(int *)(iVar1 + 0x1d0) >> 0x10;
        *(int *)(param_1 + 0x34) = iVar3;
      }
      *(int *)(param_1 + 0x3c) = iVar3;
      *(undefined4 *)(param_1 + 0x48) = 0x6f75746c;
      if ((param_2 != 0) && (*(ushort *)(param_2 + 0xe) < 0x18)) {
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 0x100;
      }
      if ((((local_18 != 0x10000) || (local_c != 0x10000)) || (local_14 != 0)) || (local_10 != 0)) {
        FUN_008b9570(param_1 + 0x6c,&local_18);
      }
      if ((local_94 != 0) || (local_61c != 0)) {
        FUN_008b94d0(param_1 + 0x6c,local_94,local_61c);
      }
      local_60c = *(int *)(param_1 + 0x28);
      local_608 = 0;
      FUN_008b9510(&local_60c,&local_18);
      local_608 = *(int *)(param_1 + 0x34);
      *(int *)(param_1 + 0x28) = local_60c + local_94;
      local_60c = 0;
      FUN_008b9510(&local_60c,&local_18);
      *(int *)(param_1 + 0x34) = local_608 + local_61c;
      if (local_610 == 0) {
        iVar3 = *(int *)(param_1 + 0xac);
        iVar4 = *(int *)(param_1 + 0xb0);
        piVar6 = *(int **)(local_5f4 + 4);
        if (((char)local_614 == '\0') || (local_5bc == 0)) {
          for (iVar5 = (int)*(short *)(local_5f4 + 2); 0 < iVar5; iVar5 = iVar5 + -1) {
            lVar2 = (longlong)*piVar6 * (longlong)iVar3;
            lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
            local_618 = (undefined4 *)
                        (((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000);
            *piVar6 = (int)local_618;
            lVar2 = (longlong)piVar6[1] * (longlong)iVar4;
            lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
            local_614 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            piVar6[1] = local_614;
            piVar6 = piVar6 + 2;
          }
        }
        lVar2 = (longlong)*(int *)(param_1 + 0x28) * (longlong)iVar3;
        lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
        local_61c = *(int *)(param_1 + 0x34);
        *(uint *)(param_1 + 0x28) =
             ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
        lVar2 = (longlong)local_61c * (longlong)iVar4;
        lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
        local_610 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
        *(uint *)(param_1 + 0x34) = local_610;
      }
      FUN_008b9440(param_1 + 0x6c,&local_28);
      *(int *)(param_1 + 0x18) = local_20 - local_28;
      *(int *)(param_1 + 0x1c) = local_1c - local_24;
      *(int *)(param_1 + 0x20) = local_28;
      *(int *)(param_1 + 0x24) = local_1c;
      if ((param_4 & 0x10) != 0) {
        FUN_008b86a0((int *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x34));
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 0x9c);
      iVar4 = FUN_008b7c80(local_5e4);
      *(int *)(param_1 + 0x20) = iVar4 >> 0x10;
      iVar4 = FUN_008b7c80(local_5dc);
      *(int *)(param_1 + 0x28) = iVar4 >> 0x10;
      *(int *)(iVar3 + 0xc) = local_18;
      *(int *)(iVar3 + 0x10) = local_14;
      *(int *)(iVar3 + 0x14) = local_10;
      *(int *)(iVar3 + 0x18) = local_c;
      *(int *)(iVar3 + 0x1c) = local_94;
      *(int *)(iVar3 + 0x20) = local_61c;
      *(undefined1 *)(iVar3 + 8) = 1;
    }
    *(undefined4 *)(param_1 + 0x88) = local_628;
    *(undefined4 *)(param_1 + 0x8c) = local_624;
    if (*(int *)(*(int *)(iVar1 + 0x80) + 0x30) != 0) {
      piVar6 = *(int **)(*(int *)(iVar1 + 0x80) + 0x30);
      (**(code **)(*piVar6 + 4))(piVar6[1],&local_628);
      *(undefined4 *)(param_1 + 0x88) = 0;
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

