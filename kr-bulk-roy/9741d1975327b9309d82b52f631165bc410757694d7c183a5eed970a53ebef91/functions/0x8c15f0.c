
void FUN_008c15f0(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(in_EAX + 0x44) - *(int *)(in_EAX + 0x48);
  iVar6 = param_2 >> 8;
  iVar4 = param_2 + iVar6 * -0x100;
  iVar2 = param_1 - *(int *)(in_EAX + 0x40);
  iVar7 = *(int *)(in_EAX + 0x48) >> 8;
  local_c = param_2 - *(int *)(in_EAX + 0x44);
  iVar3 = iVar7;
  iVar5 = iVar6;
  if (iVar6 < iVar7) {
    iVar3 = iVar6;
    iVar5 = iVar7;
  }
  if ((iVar3 < *(int *)(in_EAX + 0x14)) && (*(int *)(in_EAX + 0x10) <= iVar5)) {
    if (iVar7 != iVar6) {
      local_10 = 1;
      local_8 = 0x100;
      if (iVar2 == 0) {
        iVar3 = (*(int *)(in_EAX + 0x40) + (*(int *)(in_EAX + 0x40) >> 8) * -0x100) * 2;
        if (local_c < 0) {
          local_8 = 0;
          local_10 = -1;
        }
        *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + (local_8 - iVar1);
        *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + (local_8 - iVar1) * iVar3;
        FUN_008c13f0();
        while (iVar7 = iVar7 + local_10, iVar7 != iVar6) {
          *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + (local_8 * 2 + -0x100) * iVar3;
          *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + local_8 * 2 + -0x100;
          FUN_008c13f0();
        }
        iVar4 = local_8 + -0x100 + iVar4;
        *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + iVar4 * iVar3;
        *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + iVar4;
        goto LAB_008c1832;
      }
      local_10 = 1;
      iVar3 = 0x100 - iVar1;
      if (local_c < 0) {
        local_c = -local_c;
        local_8 = 0;
        local_10 = -1;
        iVar3 = iVar1;
      }
      local_14 = (iVar3 * iVar2) % local_c;
      if (local_14 < 0) {
        local_14 = local_14 + local_c;
      }
      FUN_008c14a0(iVar7,iVar1,local_8);
      iVar7 = iVar7 + local_10;
      FUN_008c13f0();
      if (iVar7 != iVar6) {
        local_24 = (iVar2 * 0x100) % local_c;
        if (local_24 < 0) {
          local_24 = local_24 + local_c;
        }
        local_14 = local_14 - local_c;
        do {
          local_14 = local_14 + local_24;
          if (-1 < local_14) {
            local_14 = local_14 - local_c;
          }
          FUN_008c14a0(iVar7,0x100 - local_8,local_8);
          iVar7 = iVar7 + local_10;
          FUN_008c13f0();
        } while (iVar7 != iVar6);
      }
      iVar1 = 0x100 - local_8;
    }
    FUN_008c14a0(iVar7,iVar1,iVar4);
  }
LAB_008c1832:
  *(int *)(in_EAX + 0x40) = param_1;
  *(int *)(in_EAX + 0x44) = param_2;
  *(int *)(in_EAX + 0x48) = iVar6 * 0x100;
  return;
}

