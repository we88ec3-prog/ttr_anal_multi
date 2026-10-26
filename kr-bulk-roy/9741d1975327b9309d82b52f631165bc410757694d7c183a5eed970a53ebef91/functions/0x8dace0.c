
void FUN_008dace0(int param_1,int param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int local_30;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(param_1 + 4);
  puVar1 = (undefined4 *)(param_1 + 0x6c);
  if (param_3 != 0) {
    param_3 = param_3 - 1;
  }
  if ((((iVar2 != 0) && (param_3 < *(uint *)(iVar2 + 0x198))) &&
      (((param_4 & 9) != 0 || (iVar4 = FUN_008d9ac0(param_2), iVar4 != 0)))) &&
     ((param_4 & 0x4000) == 0)) {
    iVar7 = param_3 * 0x10 + *(int *)(iVar2 + 0x1a0);
    *(undefined4 *)(param_1 + 0x48) = 0x6f75746c;
    *puVar1 = 0;
    iVar4 = FUN_008da9b0(*(undefined4 *)(iVar2 + 0x68),*(undefined4 *)(iVar2 + 0xbc),
                         *(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 8));
    if (iVar4 == 0) {
      iVar4 = *(int *)(param_1 + 0xbc);
      *puVar1 = *(undefined4 *)(iVar4 + 0x14);
      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(iVar4 + 0x18);
      *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar4 + 0x1c);
      *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(iVar4 + 0x20);
      uVar5 = *(uint *)(iVar4 + 0x24);
      *(uint *)(param_1 + 0x7c) = uVar5;
      uVar5 = uVar5 & 0xfffffffe;
      *(uint *)(param_1 + 0x7c) = uVar5 | 4;
      if ((param_2 != 0) && (*(ushort *)(param_2 + 0xe) < 0x18)) {
        *(uint *)(param_1 + 0x7c) = uVar5 | 0x104;
      }
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      uVar6 = *(undefined4 *)(iVar7 + 4);
      if (*(int *)(iVar2 + 0x130) != *(int *)(iVar2 + 300)) {
        uVar6 = FUN_008b7dc0(uVar6,*(int *)(iVar2 + 300),*(int *)(iVar2 + 0x130));
      }
      if ((*(byte *)(iVar2 + 0x144) & 1) == 0) {
        *(undefined4 *)(param_1 + 0x28) = uVar6;
      }
      else {
        *(undefined4 *)(param_1 + 0x34) = uVar6;
      }
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
      if ((~(byte)param_4 & 1) != 0) {
        iVar2 = *(int *)(param_2 + 0x10);
        iVar4 = *(int *)(param_2 + 0x14);
        piVar8 = *(int **)(param_1 + 0x70);
        local_30 = 0;
        if (0 < *(short *)(param_1 + 0x6e)) {
          do {
            lVar3 = (longlong)*piVar8 * (longlong)iVar2;
            lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
            *piVar8 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
            lVar3 = (longlong)piVar8[1] * (longlong)iVar4;
            lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
            piVar8[1] = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
            local_30 = local_30 + 1;
            piVar8 = piVar8 + 2;
          } while (local_30 < *(short *)(param_1 + 0x6e));
        }
        lVar3 = (longlong)*(int *)(param_1 + 0x28) * (longlong)iVar2;
        lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
        *(uint *)(param_1 + 0x28) =
             ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
        lVar3 = (longlong)*(int *)(param_1 + 0x34) * (longlong)iVar4;
        lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
        *(uint *)(param_1 + 0x34) =
             ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
      }
      FUN_008b9440(puVar1,&local_18);
      *(int *)(param_1 + 0x18) = local_10 - local_18;
      *(int *)(param_1 + 0x1c) = local_c - local_14;
      *(int *)(param_1 + 0x20) = local_18;
      *(int *)(param_1 + 0x24) = local_c - (local_c - local_14);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

