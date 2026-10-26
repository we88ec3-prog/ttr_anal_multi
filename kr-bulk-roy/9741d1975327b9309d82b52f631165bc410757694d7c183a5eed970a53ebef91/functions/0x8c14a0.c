
void FUN_008c14a0(undefined4 param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_EDX;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_ESI;
  int iVar8;
  int local_18;
  int local_14;
  int local_8;
  
  iVar6 = in_EAX >> 8;
  iVar8 = in_EDX >> 8;
  iVar4 = in_EAX - in_EDX;
  iVar5 = in_EDX + iVar8 * -0x100;
  iVar1 = in_EAX + iVar6 * -0x100;
  if (param_2 == param_3) {
    FUN_008c13f0();
    return;
  }
  iVar7 = param_3 - param_2;
  if (iVar8 != iVar6) {
    local_18 = 0x100;
    local_14 = 1;
    iVar3 = 0x100 - iVar5;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      local_18 = 0;
      local_14 = -1;
      iVar3 = iVar5;
    }
    iVar2 = (iVar3 * iVar7) / iVar4;
    local_8 = (iVar3 * iVar7) % iVar4;
    if (local_8 < 0) {
      iVar2 = iVar2 + -1;
      local_8 = local_8 + iVar4;
    }
    iVar8 = iVar8 + local_14;
    *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 0x20) + (local_18 + iVar5) * iVar2;
    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + iVar2;
    FUN_008c13f0();
    param_2 = param_2 + iVar2;
    if (iVar8 != iVar6) {
      iVar7 = ((iVar2 - param_2) + param_3) * 0x100;
      iVar5 = iVar7 / iVar4;
      iVar7 = iVar7 % iVar4;
      if (iVar7 < 0) {
        iVar5 = iVar5 + -1;
        iVar7 = iVar7 + iVar4;
      }
      local_8 = local_8 - iVar4;
      do {
        local_8 = local_8 + iVar7;
        iVar3 = iVar5;
        if (-1 < local_8) {
          local_8 = local_8 - iVar4;
          iVar3 = iVar5 + 1;
        }
        iVar8 = iVar8 + local_14;
        *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + iVar3;
        param_2 = param_2 + iVar3;
        *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 0x20) + iVar3 * 0x100;
        FUN_008c13f0();
      } while (iVar8 != iVar6);
    }
    *(int *)(unaff_ESI + 0x20) =
         *(int *)(unaff_ESI + 0x20) + ((iVar1 - local_18) + 0x100) * (param_3 - param_2);
    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + (param_3 - param_2);
    return;
  }
  *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 0x20) + (iVar1 + iVar5) * iVar7;
  *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + iVar7;
  return;
}

