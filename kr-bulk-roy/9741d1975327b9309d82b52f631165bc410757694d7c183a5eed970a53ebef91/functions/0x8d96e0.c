
void FUN_008d96e0(int param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint in_EAX;
  byte *pbVar1;
  byte *pbVar2;
  uint in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_c;
  
  iVar5 = 4;
  if ((in_EAX & 1) != 0) {
    iVar5 = 5;
  }
  if ((in_EAX & 2) != 0) {
    iVar5 = iVar5 + 1;
  }
  if ((in_EAX & 4) != 0) {
    iVar5 = iVar5 + 1;
  }
  local_c = 0;
  if (in_ECX != 0) {
    do {
      uVar3 = local_c + in_ECX >> 1;
      pbVar1 = (byte *)(uVar3 * iVar5 + param_1);
      if (param_2 < pbVar1 + iVar5) break;
      if ((in_EAX & 1) == 0) {
        uVar4 = (uint)*pbVar1;
        pbVar2 = pbVar1 + 1;
      }
      else {
        pbVar2 = pbVar1 + 2;
        uVar4 = (uint)CONCAT11(*pbVar1,pbVar1[1]);
      }
      if (uVar4 == param_3) {
        if ((in_EAX & 2) == 0) {
          uVar3 = (uint)*pbVar2;
          pbVar1 = pbVar2 + 1;
        }
        else {
          pbVar1 = pbVar2 + 2;
          uVar3 = (uint)CONCAT11(*pbVar2,pbVar2[1]);
        }
        *param_5 = uVar3;
        if ((in_EAX & 4) == 0) {
          *param_4 = (uint)CONCAT11(*pbVar1,pbVar1[1]);
          return;
        }
        *param_4 = (uint)CONCAT21(CONCAT11(*pbVar1,pbVar1[1]),pbVar1[2]);
        return;
      }
      uVar6 = uVar3;
      if (uVar4 < param_3) {
        uVar6 = in_ECX;
        local_c = uVar3;
      }
      in_ECX = uVar6;
    } while (local_c < uVar6);
  }
  *param_5 = 0;
  *param_4 = 0;
  return;
}

