
int FUN_00872500(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int *in_ECX;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  int *local_8;
  
  local_8 = (int *)*in_ECX;
  uVar6 = in_ECX[1] - (int)local_8 >> 2;
  uVar7 = 0;
  if (uVar6 != 0) {
    if (uVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid vector<T> subscript");
    }
    do {
      iVar2 = *local_8;
      pbVar5 = (byte *)(iVar2 + 8);
      pbVar3 = param_1;
      if (0xf < *(uint *)(iVar2 + 0x1c)) {
        pbVar5 = *(byte **)pbVar5;
      }
      do {
        bVar1 = *pbVar3;
        bVar8 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_00872553:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_00872558;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar8 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_00872553;
        pbVar5 = pbVar5 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00872558:
      if (iVar4 == 0) {
        return iVar2;
      }
      local_8 = local_8 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar6);
  }
  return 0;
}

