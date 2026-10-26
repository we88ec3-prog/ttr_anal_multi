
undefined4 FUN_004e29f0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  byte *pbVar3;
  
  if (param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 - 2 >> 3;
  }
  if (uVar1 != 0) {
    pbVar3 = (byte *)(param_1 + 4);
    do {
      if (((pbVar3[-2] < 10) &&
          (iVar2 = (uint)pbVar3[-2] * 0x210 + *(int *)(in_ECX + 0x6924), *(int *)(iVar2 + 0x5c) != 0
          )) && (iVar2 != 0)) {
        *(uint *)(iVar2 + 0x78) = (uint)pbVar3[-1];
        *(uint *)(iVar2 + 0x7c) = (uint)*pbVar3;
        *(uint *)(iVar2 + 0x80) = (uint)pbVar3[1];
        *(uint *)(iVar2 + 0x84) = (uint)pbVar3[2];
        *(uint *)(iVar2 + 0x88) = (uint)pbVar3[3];
        *(uint *)(iVar2 + 0x8c) = (uint)pbVar3[4];
        *(uint *)(iVar2 + 0x90) = (uint)pbVar3[5];
      }
      pbVar3 = pbVar3 + 8;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return 0;
}

