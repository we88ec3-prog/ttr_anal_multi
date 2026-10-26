
/* WARNING: Removing unreachable block (ram,0x007a2bae) */

void FUN_007a2b50(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar8 = true;
  iVar6 = (int)param_3;
  if (*(char *)((int)puVar5[1] + 0x31) == '\0') {
    uVar1 = *(uint *)((int)param_3 + 0x1c);
    puVar7 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar7;
      uVar2 = puVar5[7];
      uVar4 = uVar1;
      if (uVar2 <= uVar1) {
        uVar4 = uVar2;
      }
      uVar4 = FUN_00407e70(uVar4);
      if (uVar4 == 0) {
        if (uVar1 < uVar2) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(uVar1 != uVar2);
        }
      }
      bVar8 = (int)uVar4 < 0;
      if (bVar8) {
        puVar7 = (undefined4 *)*puVar5;
      }
      else {
        puVar7 = (undefined4 *)puVar5[2];
      }
      iVar6 = (int)param_3;
    } while (*(char *)((int)puVar7 + 0x31) == '\0');
  }
  param_3 = puVar5;
  if (bVar8) {
    if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar8 = true;
      goto LAB_007a2c1d;
    }
    FUN_00536ea0();
  }
  puVar5 = param_3;
  cVar3 = FUN_0049ae30();
  if (cVar3 == '\0') {
    FUN_0079d840(iVar6 + 0xc);
    FUN_0089120c(iVar6);
    *param_2 = puVar5;
    *(undefined1 *)(param_2 + 1) = 0;
    return;
  }
LAB_007a2c1d:
  puVar5 = (undefined4 *)FUN_007a3050(&param_3,bVar8,iVar6);
  *param_2 = *puVar5;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

