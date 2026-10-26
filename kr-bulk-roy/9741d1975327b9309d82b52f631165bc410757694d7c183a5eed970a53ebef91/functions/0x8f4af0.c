
void FUN_008f4af0(int param_1)

{
  int iVar1;
  uint in_EAX;
  int iVar2;
  uint in_ECX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EBX;
  int *piVar7;
  int *local_8;
  
  iVar1 = *(int *)(unaff_EBX + 0x1c);
  iVar5 = *(int *)(param_1 + 0x1c);
  iVar3 = *(int *)(unaff_EBX + 0x18) - iVar1;
  iVar4 = *(int *)(param_1 + 0x18) - iVar5;
  if (in_EAX <= in_ECX) {
    if (iVar1 == iVar5) {
      piVar7 = (int *)(in_EAX + 0x18);
      iVar5 = (in_ECX - in_EAX) / 0x28 + 1;
      do {
        iVar6 = iVar4;
        if (piVar7[1] <= iVar1) {
          iVar6 = iVar3;
        }
        *piVar7 = piVar7[1] + iVar6;
        piVar7 = piVar7 + 10;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      return;
    }
    local_8 = (int *)(in_EAX + 0x18);
    if (iVar1 < iVar5) {
      iVar6 = (in_ECX - in_EAX) / 0x28 + 1;
      do {
        iVar2 = local_8[1];
        if (iVar1 < iVar2) {
          if (iVar2 < iVar5) {
            iVar2 = FUN_008b7dc0(iVar2 - iVar1,*(int *)(param_1 + 0x18) - *(int *)(unaff_EBX + 0x18)
                                 ,iVar5 - iVar1);
            iVar2 = iVar2 + *(int *)(unaff_EBX + 0x18);
          }
          else {
            iVar2 = iVar2 + iVar4;
          }
        }
        else {
          iVar2 = iVar2 + iVar3;
        }
        *local_8 = iVar2;
        local_8 = local_8 + 10;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      return;
    }
    iVar6 = (in_ECX - in_EAX) / 0x28 + 1;
    do {
      iVar2 = local_8[1];
      if (iVar5 < iVar2) {
        if (iVar2 < iVar1) {
          iVar2 = FUN_008b7dc0(iVar2 - iVar1,*(int *)(param_1 + 0x18) - *(int *)(unaff_EBX + 0x18),
                               iVar5 - iVar1);
          iVar2 = iVar2 + *(int *)(unaff_EBX + 0x18);
        }
        else {
          iVar2 = iVar2 + iVar3;
        }
      }
      else {
        iVar2 = iVar2 + iVar4;
      }
      *local_8 = iVar2;
      local_8 = local_8 + 10;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return;
}

