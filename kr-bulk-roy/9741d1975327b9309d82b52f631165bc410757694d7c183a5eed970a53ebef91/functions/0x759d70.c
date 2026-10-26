
void FUN_00759d70(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int unaff_EDI;
  undefined4 local_10;
  int local_c;
  char local_5;
  
  FUN_00848020(&local_10);
  iVar4 = local_c;
  if (local_c != *(int *)(unaff_EDI + 0x2c)) {
    iVar1 = *(int *)(local_c + 0x10);
    local_5 = *(char *)(local_c + 0x1c);
    local_10 = *(undefined4 *)(local_c + 0x18);
    iVar5 = *(int *)(local_c + 0x14) - iVar1;
    if (0 < iVar5) {
      FUN_00402400(iVar1,iVar5);
    }
    iVar5 = param_1[4];
    if (0 < iVar5) {
      puVar6 = param_1;
      if (7 < (uint)param_1[5]) {
        puVar6 = (undefined4 *)*param_1;
      }
      FUN_00448090(iVar1,puVar6,iVar5);
    }
    iVar2 = *(int *)(iVar4 + 0x14);
    iVar7 = *(int *)(iVar4 + 0x10) + param_1[4];
    *(int *)(iVar4 + 0x14) = iVar7;
    iVar7 = iVar7 - iVar2;
    if (iVar7 != 0) {
      FUN_0085e240();
      if (local_c != *(int *)(unaff_EDI + 0x2c)) {
        do {
          *(int *)(local_c + 0x10) = *(int *)(local_c + 0x10) + iVar7;
          *(int *)(local_c + 0x14) = *(int *)(local_c + 0x14) + iVar7;
          FUN_0085e240();
        } while (local_c != *(int *)(unaff_EDI + 0x2c));
      }
      puVar6 = *(undefined4 **)(unaff_EDI + 0x1c);
      for (puVar3 = (undefined4 *)*puVar6; puVar3 != puVar6; puVar3 = (undefined4 *)*puVar3) {
        if (iVar1 < (int)puVar3[2]) {
          puVar3[2] = puVar3[2] + iVar7;
        }
      }
    }
    if (local_5 != '\0') {
      FUN_007591a0(iVar1,iVar5,local_10);
    }
    FUN_007592c0(unaff_EDI);
  }
  return;
}

