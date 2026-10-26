
void FUN_00737550(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 in_ECX;
  undefined4 *puVar8;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_14 = ExceptionList;
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092a84b;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  *param_1 = in_ECX;
  puVar2 = (undefined4 *)param_1[4];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    iVar4 = puVar3[4];
    iVar7 = FUN_00891268(0x48,uVar6);
    puVar8 = (undefined4 *)0x0;
    local_c = 0;
    if (iVar7 != 0) {
      puVar8 = (undefined4 *)FUN_00734010();
    }
    local_c = 0xffffffff;
    iVar7 = FUN_007340c0(puVar8);
    if (iVar7 < 0) {
      if (puVar8 != (undefined4 *)0x0) {
        (**(code **)*puVar8)(1);
      }
      puVar8 = (undefined4 *)0x0;
    }
    *(undefined4 **)(iVar4 + 0x30) = puVar8;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar8 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar8 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar8 + 0x15);
        puVar3 = puVar8;
        puVar8 = (undefined4 *)*puVar8;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar8 + 0x15);
          puVar3 = puVar8;
          puVar8 = (undefined4 *)*puVar8;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar5 = (undefined4 *)puVar3[1];
        puVar8 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar8 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar8 = puVar3;
        }
      }
    }
  }
  ExceptionList = local_14;
  return;
}

