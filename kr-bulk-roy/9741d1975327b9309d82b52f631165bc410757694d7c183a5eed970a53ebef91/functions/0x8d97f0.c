
undefined4
FUN_008d97f0(uint *param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5,uint *param_6,
            uint *param_7,uint *param_8,uint *param_9)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_c;
  
  pbVar2 = (byte *)*param_1;
  pbVar5 = pbVar2 + 1;
  uVar8 = 0;
  if (param_2 < pbVar5) {
    return 8;
  }
  bVar1 = *pbVar2;
  uVar6 = 0;
  uVar7 = 0;
  local_c = 0;
  pbVar4 = pbVar5;
  switch(bVar1 & 3) {
  case 0:
    pbVar4 = pbVar2 + 2;
    if (param_2 < pbVar4) {
      return 8;
    }
    uVar6 = (int)(char)*pbVar5 >> 4;
    uVar7 = (int)(char)(*pbVar5 << 4) >> 4;
    break;
  case 1:
    if (param_2 < pbVar2 + 3) {
      return 8;
    }
    uVar6 = (uint)(char)*pbVar5;
    uVar7 = (uint)(char)pbVar2[2];
    pbVar4 = pbVar2 + 3;
    break;
  case 2:
    if (param_2 < pbVar2 + 5) {
      return 8;
    }
    uVar6 = (int)(short)((ushort)*pbVar5 << 8) | (uint)pbVar2[2];
    pbVar4 = pbVar2 + 5;
    uVar7 = (uint)(short)((ushort)pbVar2[3] << 8);
    goto LAB_008d98cc;
  case 3:
    if (param_2 < pbVar2 + 7) {
      return 8;
    }
    uVar6 = (uint)CONCAT21(CONCAT11(*pbVar5,pbVar2[2]),pbVar2[3]);
    pbVar4 = pbVar2 + 7;
    uVar7 = (uint)CONCAT11(pbVar2[4],pbVar2[5]) << 8;
LAB_008d98cc:
    uVar7 = uVar7 | pbVar4[-1];
  }
  switch(bVar1 >> 2 & 3) {
  case 0:
    uVar8 = 0;
    local_c = 0;
    break;
  case 1:
    if (param_2 < pbVar4 + 1) {
      return 8;
    }
    uVar8 = (int)(char)*pbVar4 >> 4 & 0xf;
    local_c = (int)(char)*pbVar4 & 0xf;
    pbVar4 = pbVar4 + 1;
    break;
  case 2:
    if (param_2 < pbVar4 + 2) {
      return 8;
    }
    local_c = (uint)pbVar4[1];
    uVar8 = (uint)*pbVar4;
    pbVar4 = pbVar4 + 2;
    break;
  case 3:
    if (param_2 < pbVar4 + 4) {
      return 8;
    }
    uVar8 = (uint)CONCAT11(*pbVar4,pbVar4[1]);
    local_c = (uint)CONCAT11(pbVar4[2],pbVar4[3]);
    pbVar4 = pbVar4 + 4;
  }
  uVar3 = 0;
  switch(bVar1 >> 4 & 3) {
  case 0:
    uVar3 = param_3;
    break;
  case 1:
    if (param_2 < pbVar4 + 1) {
      return 8;
    }
    uVar3 = (int)(char)*pbVar4 << 8;
    pbVar4 = pbVar4 + 1;
    break;
  case 2:
    pbVar5 = pbVar4 + 2;
    if (param_2 < pbVar5) {
      return 8;
    }
    uVar3 = (uint)(short)((ushort)*pbVar4 << 8);
    goto LAB_008d99cd;
  case 3:
    pbVar5 = pbVar4 + 3;
    if (param_2 < pbVar5) {
      return 8;
    }
    uVar3 = (uint)CONCAT11(*pbVar4,pbVar4[1]) << 8;
LAB_008d99cd:
    uVar3 = uVar3 | pbVar5[-1];
    pbVar4 = pbVar5;
  }
  *param_4 = uVar6;
  *param_5 = uVar7;
  *param_6 = uVar8;
  *param_7 = local_c;
  *param_8 = uVar3;
  *param_9 = (uint)(bVar1 >> 6);
  *param_1 = (uint)pbVar4;
  return 0;
}

