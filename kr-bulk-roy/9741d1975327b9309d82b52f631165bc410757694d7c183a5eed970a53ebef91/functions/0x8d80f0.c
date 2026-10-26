
int FUN_008d80f0(uint *param_1,byte *param_2,undefined4 param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *unaff_EBX;
  byte *pbVar5;
  byte *pbVar6;
  uint local_8;
  
  pbVar5 = (byte *)*param_1;
  pbVar6 = pbVar5 + 1;
  iVar4 = 0;
  if (pbVar6 <= param_2) {
    local_8 = (uint)*pbVar5;
    if (local_8 == 0) {
      *param_1 = (uint)pbVar6;
      return iVar4;
    }
    while (pbVar5 = pbVar6, pbVar6 + 2 <= param_2) {
      pbVar1 = pbVar6 + 1;
      pbVar5 = pbVar6 + 2;
      pbVar6 = pbVar5 + *pbVar6;
      if (param_2 < pbVar6) break;
      if (unaff_EBX != (uint *)0x0) {
        uVar2 = unaff_EBX[1];
        puVar3 = unaff_EBX;
        while (uVar2 != 0) {
          if (*puVar3 == (uint)*pbVar1) {
            iVar4 = (*(code *)puVar3[1])(pbVar5,pbVar6,param_3);
            if (iVar4 != 0) goto LAB_008d815e;
            break;
          }
          uVar2 = puVar3[3];
          puVar3 = puVar3 + 2;
        }
      }
      local_8 = local_8 - 1;
      pbVar5 = pbVar6;
      if (local_8 == 0) {
LAB_008d815e:
        *param_1 = (uint)pbVar5;
        return iVar4;
      }
    }
  }
  *param_1 = (uint)pbVar5;
  return 8;
}

