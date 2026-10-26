
void FUN_00514d00(void)

{
  undefined1 uVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *_Str1;
  undefined4 local_8;
  
  if (in_EAX != 0) {
    piVar2 = (int *)FUN_0072e2e0(&DAT_00c067f4);
joined_r0x00514d1b:
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
      iVar3 = FUN_007300a0("REINFORCE");
      if (iVar3 == 0) {
LAB_00514d5b:
        uVar1 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00514d5b;
        uVar1 = FUN_008917b4(puVar4);
      }
      local_8 = CONCAT31(local_8._1_3_,uVar1);
      iVar3 = FUN_007300a0("MAGIC");
      if (iVar3 == 0) {
LAB_00514d87:
        uVar1 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00514d87;
        uVar1 = FUN_008917b4(puVar4);
      }
      local_8._0_2_ = CONCAT11(uVar1,(undefined1)local_8);
      iVar3 = FUN_007300a0("FAKE_MAGIC");
      if (iVar3 == 0) {
LAB_00514db3:
        uVar1 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00514db3;
        uVar1 = FUN_008917b4(puVar4);
      }
      local_8._0_3_ = CONCAT12(uVar1,(undefined2)local_8);
      iVar3 = FUN_007300a0("PERCENT");
      if (iVar3 == 0) {
LAB_00514ddf:
        uVar1 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00514ddf;
        uVar1 = FUN_008917b4(puVar4);
      }
      local_8 = CONCAT13(uVar1,(undefined3)local_8);
      if ((&local_8 < DAT_00fe3024) && (DAT_00fe3020 <= &local_8)) {
        iVar3 = (int)&local_8 - (int)DAT_00fe3020;
        if (DAT_00fe3024 == DAT_00fe3028) {
          FUN_0068c010();
        }
        if (DAT_00fe3024 != (undefined4 *)0x0) {
          *DAT_00fe3024 = DAT_00fe3020[iVar3 >> 2];
        }
      }
      else {
        if (DAT_00fe3024 == DAT_00fe3028) {
          FUN_0068c010();
        }
        if (DAT_00fe3024 != (undefined4 *)0x0) {
          *DAT_00fe3024 = local_8;
        }
      }
      DAT_00fe3024 = DAT_00fe3024 + 1;
      for (piVar2 = (int *)piVar2[0x10]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
        _Str1 = piVar2 + 8;
        if (0xf < (uint)piVar2[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar3 = __stricmp((char *)_Str1,"INFO");
        if (iVar3 == 0) goto joined_r0x00514d1b;
      }
      piVar2 = (int *)0x0;
      goto joined_r0x00514d1b;
    }
  }
  return;
}

