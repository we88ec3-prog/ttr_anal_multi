
int FUN_008f23e0(int *param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int local_8;
  
  iVar5 = param_1[3];
  iVar1 = *(short *)(iVar5 + 0x16) + 4;
  if ((iVar1 == 0) ||
     ((uint)(*(short *)(iVar5 + 0x16) + 4 +
            (int)*(short *)(iVar5 + 0x3a) + (int)*(short *)(iVar5 + 0x16)) <= *(uint *)(iVar5 + 4)))
  {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008bc9a0(iVar5,iVar1,0);
    if (local_8 != 0) {
      return local_8;
    }
  }
  sVar2 = *(short *)(iVar5 + 0x16);
  iVar1 = *(int *)(iVar5 + 0x18);
  *(int *)(iVar1 + sVar2 * 8) = param_1[0x11];
  *(int *)(iVar1 + 4 + sVar2 * 8) = param_1[0x12];
  sVar2 = *(short *)(iVar5 + 0x16);
  iVar1 = *(int *)(iVar5 + 0x18);
  *(int *)(iVar1 + 8 + sVar2 * 8) = param_1[0x13];
  *(int *)(iVar1 + 0xc + sVar2 * 8) = param_1[0x14];
  sVar2 = *(short *)(iVar5 + 0x16);
  iVar1 = *(int *)(iVar5 + 0x18);
  *(int *)(iVar1 + 0x10 + sVar2 * 8) = param_1[0x2e];
  *(int *)(iVar1 + 0x14 + sVar2 * 8) = param_1[0x2f];
  sVar2 = *(short *)(iVar5 + 0x16);
  iVar1 = *(int *)(iVar5 + 0x18);
  *(int *)(iVar1 + 0x18 + sVar2 * 8) = param_1[0x30];
  *(int *)(iVar1 + 0x1c + sVar2 * 8) = param_1[0x31];
  *(undefined1 *)((int)*(short *)(iVar5 + 0x16) + *(int *)(iVar5 + 0x1c)) = 0;
  *(undefined1 *)(*(short *)(iVar5 + 0x16) + 1 + *(int *)(iVar5 + 0x1c)) = 0;
  *(undefined1 *)(*(short *)(iVar5 + 0x16) + 2 + *(int *)(iVar5 + 0x1c)) = 0;
  *(undefined1 *)(*(short *)(iVar5 + 0x16) + 3 + *(int *)(iVar5 + 0x1c)) = 0;
  iVar1 = param_1[6];
  local_8 = FUN_008b97e0(iVar1,param_1[0x2a]);
  if (local_8 == 0) {
    uVar4 = FUN_008b9ab0(iVar1,&local_8);
    uVar6 = (uint)uVar4;
    if (local_8 == 0) {
      if (*(ushort *)(*param_1 + 0x11e) < uVar4) {
        if (param_1[7] < (int)uVar6) {
          return 0x16;
        }
        uVar3 = *(uint *)(param_1[0x28] + 0x184);
        iVar5 = FUN_008ebfc0(*(undefined4 *)(param_1[0x28] + 8));
        *(uint *)(param_1[0x28] + 0x184) = uVar3 & 0xffff;
        if (iVar5 != 0) {
          return iVar5;
        }
        local_8 = 0;
      }
      else if (uVar4 == 0) {
        return 0;
      }
      local_8 = FUN_008bab70(iVar1,*(undefined4 *)(param_1[0x28] + 0x188),uVar6);
      if (local_8 == 0) {
        *(undefined4 *)(param_1[2] + 0x88) = *(undefined4 *)(param_1[0x28] + 0x188);
        *(uint *)(param_1[2] + 0x8c) = uVar6;
        FUN_008eb180();
        uVar6 = 0;
        if ((short)param_1[0x21] != 0) {
          do {
            *(byte *)(param_1[0x25] + uVar6) = *(byte *)(param_1[0x25] + uVar6) & 0xe7;
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(ushort *)(param_1 + 0x21));
        }
        *(short *)(param_1 + 0x21) = (short)param_1[0x21] + 4;
        local_8 = FUN_008f1f40(param_1,1);
      }
    }
  }
  return local_8;
}

