
int FUN_008d8460(byte *param_1,byte *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int local_8;
  
  local_8 = 0;
  if (param_3[0x13] != 0) {
    return 0;
  }
  if (param_1 + 1 <= param_2) {
    uVar5 = *param_1 & 0xf;
    iVar4 = (*param_1 >> 4) + uVar5;
    if (param_1 + 1 + iVar4 * 2 <= param_2) {
      puVar3 = (uint *)FUN_008bc7d0(*param_3,4,0,iVar4,0,&local_8);
      if (local_8 != 0) {
        return local_8;
      }
      param_3[0x13] = puVar3;
      param_3[0x10] = puVar3 + uVar5;
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        pbVar1 = param_1 + 1;
        pbVar2 = param_1 + 2;
        param_1 = param_1 + 2;
        *puVar3 = (int)(short)((ushort)*pbVar1 << 8) | (uint)*pbVar2;
        puVar3 = puVar3 + 1;
      }
      return 0;
    }
  }
  return 8;
}

