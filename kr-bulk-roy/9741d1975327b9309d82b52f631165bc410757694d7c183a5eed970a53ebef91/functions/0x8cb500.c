
undefined4 FUN_008cb500(uint param_1,uint param_2,int param_3)

{
  char cVar1;
  int in_EAX;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int *local_8;
  
  iVar7 = *(int *)(in_EAX + 0x84);
  local_8 = (int *)(iVar7 + (param_2 & 0xffff) * 8);
  piVar9 = (int *)(iVar7 + (param_1 & 0xffff) * 8);
  local_20 = *(int *)(in_EAX + 8);
  bVar2 = (byte)*(undefined4 *)(in_EAX + 0x18);
  local_18 = (piVar9[1] << (bVar2 & 0x1f)) - local_20;
  iVar8 = (*(int *)(iVar7 + (param_1 & 0xffff) * 8) << (bVar2 & 0x1f)) - local_20;
  iVar3 = (*local_8 << (bVar2 & 0x1f)) - local_20;
  local_20 = (local_8[1] << (bVar2 & 0x1f)) - local_20;
  iVar7 = iVar3;
  local_1c = iVar8;
  if (param_3 != 0) {
    iVar7 = local_20;
    local_20 = iVar3;
    local_1c = local_18;
    local_18 = iVar8;
  }
  pbVar4 = (byte *)(*(int *)(in_EAX + 0x88) + (param_1 & 0xffff));
  if ((*pbVar4 & 4) != 0) {
    *(byte *)(in_EAX + 0xb4) = *pbVar4 >> 5;
  }
  if ((*pbVar4 & 3) != 2) {
    if ((*pbVar4 & 3) == 0) {
      if ((*(byte *)(*(int *)(in_EAX + 0x88) + (param_2 & 0xffff)) & 3) == 1) {
        local_8 = local_8 + -2;
        local_18 = local_20;
        local_1c = iVar7;
      }
      else {
        local_1c = (local_1c + iVar7) / 2;
        local_18 = (local_20 + local_18) / 2;
      }
      piVar9 = piVar9 + -2;
      pbVar4 = pbVar4 + -1;
    }
    *(int *)(in_EAX + 0x44) = local_1c;
    *(int *)(in_EAX + 0x48) = local_18;
    do {
      if (local_8 <= piVar9) {
        cVar1 = FUN_008cb0d0(local_1c,local_18);
joined_r0x008cb80a:
        if (cVar1 != '\0') {
          return 1;
        }
        return 0;
      }
      pbVar5 = pbVar4 + 1;
      piVar11 = piVar9 + 2;
      if ((pbVar4[1] & 3) == 0) {
        bVar2 = (byte)*(undefined4 *)(in_EAX + 0x18);
        iVar7 = (*piVar11 << (bVar2 & 0x1f)) - *(int *)(in_EAX + 8);
        local_24 = (piVar9[3] << (bVar2 & 0x1f)) - *(int *)(in_EAX + 8);
        local_20 = iVar7;
        if (param_3 == 0) goto LAB_008cb720;
        while( true ) {
          iVar7 = local_24;
          local_24 = local_20;
LAB_008cb720:
          local_20 = local_24;
          local_24 = iVar7;
          if (local_8 <= piVar11) {
            cVar1 = FUN_008cb210(local_24,local_20,local_1c,local_18);
            goto joined_r0x008cb80a;
          }
          pbVar4 = pbVar5 + 1;
          piVar9 = piVar11 + 3;
          pbVar5 = pbVar5 + 1;
          piVar11 = piVar11 + 2;
          bVar2 = (byte)*(undefined4 *)(in_EAX + 0x18);
          iVar8 = (*piVar9 << (bVar2 & 0x1f)) - *(int *)(in_EAX + 8);
          iVar3 = (*piVar11 << (bVar2 & 0x1f)) - *(int *)(in_EAX + 8);
          iVar7 = iVar8;
          if (param_3 != 0) {
            iVar7 = iVar3;
            iVar3 = iVar8;
          }
          if ((*pbVar4 & 3) == 1) break;
          if ((*pbVar4 & 3) != 0) goto LAB_008cb815;
          cVar1 = FUN_008cb210(local_24,local_20,(iVar3 + local_24) / 2,(iVar7 + local_20) / 2);
          local_24 = iVar3;
          local_20 = iVar7;
          if (cVar1 != '\0') {
            return 1;
          }
        }
        cVar1 = FUN_008cb210(local_24,local_20,iVar3,iVar7);
        piVar9 = piVar11;
        pbVar4 = pbVar5;
      }
      else if ((pbVar4[1] & 3) == 1) {
        bVar2 = (byte)*(undefined4 *)(in_EAX + 0x18);
        iVar8 = (*piVar11 << (bVar2 & 0x1f)) - *(int *)(in_EAX + 8);
        iVar3 = (piVar9[3] << (bVar2 & 0x1f)) - *(int *)(in_EAX + 8);
        iVar7 = iVar8;
        if (param_3 != 0) {
          iVar7 = iVar3;
          iVar3 = iVar8;
        }
        cVar1 = FUN_008cb0d0(iVar7,iVar3);
        piVar9 = piVar11;
        pbVar4 = pbVar5;
      }
      else {
        if ((local_8 < piVar9 + 4) || ((pbVar4[2] & 3) != 2)) break;
        iVar7 = *(int *)(in_EAX + 8);
        piVar10 = piVar9 + 6;
        bVar2 = (byte)*(undefined4 *)(in_EAX + 0x18);
        local_10 = (piVar9[3] << (bVar2 & 0x1f)) - iVar7;
        iVar8 = (*piVar11 << (bVar2 & 0x1f)) - iVar7;
        local_c = (piVar9[4] << (bVar2 & 0x1f)) - iVar7;
        iVar6 = (piVar9[5] << (bVar2 & 0x1f)) - iVar7;
        iVar3 = iVar8;
        param_1 = iVar6;
        if (param_3 != 0) {
          iVar3 = local_10;
          param_1 = local_c;
          local_10 = iVar8;
          local_c = iVar6;
        }
        if (local_8 < piVar10) {
          cVar1 = FUN_008cb370(iVar3,local_10,local_c,param_1,local_1c,local_18);
          goto joined_r0x008cb80a;
        }
        iVar6 = (*piVar10 << (bVar2 & 0x1f)) - iVar7;
        iVar7 = (piVar9[7] << (bVar2 & 0x1f)) - iVar7;
        iVar8 = iVar6;
        if (param_3 != 0) {
          iVar8 = iVar7;
          iVar7 = iVar6;
        }
        cVar1 = FUN_008cb370(iVar3,local_10,local_c,param_1,iVar8,iVar7);
        piVar9 = piVar10;
        pbVar4 = pbVar4 + 3;
      }
      if (cVar1 != '\0') {
        return 1;
      }
    } while( true );
  }
LAB_008cb815:
  *(undefined4 *)(in_EAX + 0x2c) = 0x14;
  return 1;
}

